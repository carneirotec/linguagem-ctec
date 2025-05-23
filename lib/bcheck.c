/*
 *  Tiny C Memory and bounds checker
 * 
 *  Copyright (c) 2002 Fabrice Bellard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License para more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; se not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#inclua <stdlib.h>
#inclua <stdio.h>
#inclua <stdarg.h>
#inclua <string.h>

#se !definido(__FreeBSD__) \
 && !definido(__FreeBSD_kernel__) \
 && !definido(__DragonFly__) \
 && !definido(__OpenBSD__) \
 && !definido(__NetBSD__)
#inclua <malloc.h>
#fim_se

#se !definido(_WIN32)
#inclua <unistd.h>
#fim_se

/* #defina BOUND_DEBUG */

#se_definido BOUND_DEBUG
 #defina dprintf(a...) fprintf(a)
#senão
 #defina dprintf(a...)
#fim_se

/* defina so that bound array is estático (faster, but use memory se
   bound checking not used) */
/* #defina BOUND_STATIC */

/* use malloc hooks. Currently the code cannot be reliable se no hooks */
#defina CONFIG_CTEC_MALLOC_HOOKS
#defina HAVE_MEMALIGN

#se definido(__FreeBSD__) \
 || definido(__FreeBSD_kernel__) \
 || definido(__DragonFly__) \
 || definido(__OpenBSD__) \
 || definido(__NetBSD__) \
 || definido(__dietlibc__) \
 || definido(_WIN32)
//#aviso Bound checking does not support malloc (etc.) in this environment.
#não_definido CONFIG_CTEC_MALLOC_HOOKS
#não_definido HAVE_MEMALIGN
#fim_se

#defina BOUND_T1_BITS 13
#defina BOUND_T2_BITS 11
#defina BOUND_T3_BITS (sizeof(size_t)*8 - BOUND_T1_BITS - BOUND_T2_BITS)
#defina BOUND_E_BITS  (sizeof(size_t))

#defina BOUND_T1_SIZE ((size_t)1 << BOUND_T1_BITS)
#defina BOUND_T2_SIZE ((size_t)1 << BOUND_T2_BITS)
#defina BOUND_T3_SIZE ((size_t)1 << BOUND_T3_BITS)

#defina BOUND_T23_BITS (BOUND_T2_BITS + BOUND_T3_BITS)
#defina BOUND_T23_SIZE ((size_t)1 << BOUND_T23_BITS)


/* this pointer is generated when bound check is incorrect */
#defina INVALID_POINTER ((vazio *)(-2))
/* size of an empty region */
#defina EMPTY_SIZE  ((size_t)(-1))
/* size of an invalid region */
#defina INVALID_SIZE      0

defina_tipo estrutura BoundEntry {
    size_t start;
    size_t size;
    estrutura BoundEntry *next;
    size_t is_invalid; /* true se pointers outside region are invalid */
} BoundEntry;

/* external interface */
vazio __bound_init(vazio);
vazio __bound_new_region(vazio *p, size_t size);
inteiro __bound_delete_region(vazio *p);

#se_definido __attribute__
  /* an __attribute__ macro is definido in the system headers */
  #não_definido __attribute__ 
#fim_se
#defina FASTCALL __attribute__((regparm(3)))

vazio *__bound_malloc(size_t size, constante vazio *caller);
vazio *__bound_memalign(size_t size, size_t align, constante vazio *caller);
vazio __bound_free(vazio *ptr, constante vazio *caller);
vazio *__bound_realloc(vazio *ptr, size_t size, constante vazio *caller);
estático vazio *libc_malloc(size_t size);
estático vazio libc_free(vazio *ptr);
estático vazio install_malloc_hooks(vazio);
estático vazio restore_malloc_hooks(vazio);

#se_definido CONFIG_CTEC_MALLOC_HOOKS
estático vazio *saved_malloc_hook;
estático vazio *saved_free_hook;
estático vazio *saved_realloc_hook;
estático vazio *saved_memalign_hook;
#fim_se

/* CTEC definitions */
externo caractere __bounds_start; /* start of estático bounds table */
/* erro message, just para CTEC */
constante caractere *__bound_error_msg;

/* runtime erro output */
externo vazio rt_error(size_t pc, constante caractere *fmt, ...);

#se_definido BOUND_STATIC
estático BoundEntry *__bound_t1[BOUND_T1_SIZE]; /* page table */
#senão
estático BoundEntry **__bound_t1; /* page table */
#fim_se
estático BoundEntry *__bound_empty_t2;   /* empty page, para unused pages */
estático BoundEntry *__bound_invalid_t2; /* invalid page, para invalid pointers */

estático BoundEntry *__bound_find_region(BoundEntry *e1, vazio *p)
{
    size_t addr, tmp;
    BoundEntry *e;

    e = e1;
    enquanto (e != NULL) {
        addr = (size_t)p;
        addr -= e->start;
        se (addr <= e->size) {
            /* put region at the head */
            tmp = e1->start;
            e1->start = e->start;
            e->start = tmp;
            tmp = e1->size;
            e1->size = e->size;
            e->size = tmp;
            retorne e1;
        }
        e = e->next;
    }
    /* no entry found: retorne empty entry or invalid entry */
    se (e1->is_invalid)
        retorne __bound_invalid_t2;
    senão
        retorne __bound_empty_t2;
}

/* print a bound erro message */
estático vazio bound_error(constante caractere *fmt, ...)
{
    __bound_error_msg = fmt;
    fprintf(stderr,"%s %s: %s\n", __FILE__, __FUNCTION__, fmt);
    *(vazio **)0 = 0; /* force a runtime erro */
}

estático vazio bound_alloc_error(vazio)
{
    bound_error("not enough memory para bound checking code");
}

/* retorne '(p + offset)' para pointer arithmetic (a pointer can reach
   the end of a region in this caso */
vazio * FASTCALL __bound_ptr_add(vazio *p, size_t offset)
{
    size_t addr = (size_t)p;
    BoundEntry *e;

    dprintf(stderr, "%s %s: %p %x\n",
        __FILE__, __FUNCTION__, p, (sem_sinal)offset);

    __bound_init();

    e = __bound_t1[addr >> (BOUND_T2_BITS + BOUND_T3_BITS)];
    e = (BoundEntry *)((caractere *)e + 
                       ((addr >> (BOUND_T3_BITS - BOUND_E_BITS)) & 
                        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS)));
    addr -= e->start;
    se (addr > e->size) {
        e = __bound_find_region(e, p);
        addr = (size_t)p - e->start;
    }
    addr += offset;
    se (addr >= e->size) {
	fprintf(stderr,"%s %s: %p is outside of the region\n",
            __FILE__, __FUNCTION__, p + offset);
        retorne INVALID_POINTER; /* retorne an invalid pointer */
    }
    retorne p + offset;
}

/* retorne '(p + offset)' para pointer indirection (the resulting must
   be strictly inside the region */
#defina BOUND_PTR_INDIR(dsize)                                          \
vazio * FASTCALL __bound_ptr_indir ## dsize (vazio *p, size_t offset)     \
{                                                                       \
    size_t addr = (size_t)p;                                            \
    BoundEntry *e;                                                      \
                                                                        \
    dprintf(stderr, "%s %s: %p %x start\n",                             \
        __FILE__, __FUNCTION__, p, (sem_sinal)offset);	                \
									\
    __bound_init();							\
    e = __bound_t1[addr >> (BOUND_T2_BITS + BOUND_T3_BITS)];            \
    e = (BoundEntry *)((caractere *)e +                                      \
                       ((addr >> (BOUND_T3_BITS - BOUND_E_BITS)) &      \
                        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS)));        \
    addr -= e->start;                                                   \
    se (addr > e->size) {                                               \
        e = __bound_find_region(e, p);                                  \
        addr = (size_t)p - e->start;                                    \
    }                                                                   \
    addr += offset + dsize;                                             \
    se (addr > e->size) {                                               \
	fprintf(stderr,"%s %s: %p is outside of the region\n",          \
            __FILE__, __FUNCTION__, p + offset);                        \
        retorne INVALID_POINTER; /* retorne an invalid pointer */         \
    }									\
    dprintf(stderr, "%s %s: retorne p+offset = %p\n",                    \
        __FILE__, __FUNCTION__, p + offset);                            \
    retorne p + offset;                                                  \
}

BOUND_PTR_INDIR(1)
BOUND_PTR_INDIR(2)
BOUND_PTR_INDIR(4)
BOUND_PTR_INDIR(8)
BOUND_PTR_INDIR(12)
BOUND_PTR_INDIR(16)

#se definido(__GNUC__) && (__GNUC__ >= 6)
/*
 * At least gcc 6.2 complains when __builtin_frame_address is used with
 * nonzero argument.
 */
#diretiva GCC diagnostic push
#diretiva GCC diagnostic ignored "-Wframe-address"
#fim_se

/* retorne the frame pointer of the caller */
#defina GET_CALLER_FP(fp)\
{\
    fp = (size_t)__builtin_frame_address(1);\
}

/* called when entering a function to add all the local regions */
vazio FASTCALL __bound_local_new(vazio *p1) 
{
    size_t addr, size, fp, *p = p1;

    dprintf(stderr, "%s, %s start p1=%p\n", __FILE__, __FUNCTION__, p);
    GET_CALLER_FP(fp);
    para(;;) {
        addr = p[0];
        se (addr == 0)
            pare;
        addr += fp;
        size = p[1];
        p += 2;
        __bound_new_region((vazio *)addr, size);
    }
    dprintf(stderr, "%s, %s end\n", __FILE__, __FUNCTION__);
}

/* called when leaving a function to delete all the local regions */
vazio FASTCALL __bound_local_delete(vazio *p1) 
{
    size_t addr, fp, *p = p1;
    GET_CALLER_FP(fp);
    para(;;) {
        addr = p[0];
        se (addr == 0)
            pare;
        addr += fp;
        p += 2;
        __bound_delete_region((vazio *)addr);
    }
}

#se definido(__GNUC__) && (__GNUC__ >= 6)
#diretiva GCC diagnostic pop
#fim_se

estático BoundEntry *__bound_new_page(vazio)
{
    BoundEntry *page;
    size_t i;

    page = libc_malloc(sizeof(BoundEntry) * BOUND_T2_SIZE);
    se (!page)
        bound_alloc_error();
    para(i=0;i<BOUND_T2_SIZE;i++) {
        /* put empty entries */
        page[i].start = 0;
        page[i].size = EMPTY_SIZE;
        page[i].next = NULL;
        page[i].is_invalid = 0;
    }
    retorne page;
}

/* currently we use malloc(). Should use bound_new_page() */
estático BoundEntry *bound_new_entry(vazio)
{
    BoundEntry *e;
    e = libc_malloc(sizeof(BoundEntry));
    retorne e;
}

estático vazio bound_free_entry(BoundEntry *e)
{
    libc_free(e);
}

estático BoundEntry *get_page(size_t index)
{
    BoundEntry *page;
    page = __bound_t1[index];
    se (!page || page == __bound_empty_t2 || page == __bound_invalid_t2) {
        /* create a new page se necessary */
        page = __bound_new_page();
        __bound_t1[index] = page;
    }
    retorne page;
}

/* mark a region as being invalid (can only be used during init) */
estático vazio mark_invalid(size_t addr, size_t size)
{
    size_t start, end;
    BoundEntry *page;
    size_t t1_start, t1_end, i, j, t2_start, t2_end;

    start = addr;
    end = addr + size;

    t2_start = (start + BOUND_T3_SIZE - 1) >> BOUND_T3_BITS;
    se (end != 0)
        t2_end = end >> BOUND_T3_BITS;
    senão
        t2_end = 1 << (BOUND_T1_BITS + BOUND_T2_BITS);

#se 0
    dprintf(stderr, "mark_invalid: start = %x %x\n", t2_start, t2_end);
#fim_se
    
    /* first we handle full pages */
    t1_start = (t2_start + BOUND_T2_SIZE - 1) >> BOUND_T2_BITS;
    t1_end = t2_end >> BOUND_T2_BITS;

    i = t2_start & (BOUND_T2_SIZE - 1);
    j = t2_end & (BOUND_T2_SIZE - 1);
    
    se (t1_start == t1_end) {
        page = get_page(t2_start >> BOUND_T2_BITS);
        para(; i < j; i++) {
            page[i].size = INVALID_SIZE;
            page[i].is_invalid = 1;
        }
    } senão {
        se (i > 0) {
            page = get_page(t2_start >> BOUND_T2_BITS);
            para(; i < BOUND_T2_SIZE; i++) {
                page[i].size = INVALID_SIZE;
                page[i].is_invalid = 1;
            }
        }
        para(i = t1_start; i < t1_end; i++) {
            __bound_t1[i] = __bound_invalid_t2;
        }
        se (j != 0) {
            page = get_page(t1_end);
            para(i = 0; i < j; i++) {
                page[i].size = INVALID_SIZE;
                page[i].is_invalid = 1;
            }
        }
    }
}

vazio __bound_init(vazio)
{
    size_t i;
    BoundEntry *page;
    size_t start, size;
    size_t *p;

    estático inteiro inited;
    se (inited)
	retorne;

    inited = 1;

    dprintf(stderr, "%s, %s() start\n", __FILE__, __FUNCTION__);

    /* save malloc hooks and install bound check hooks */
    install_malloc_hooks();

#se_não_definido BOUND_STATIC
    __bound_t1 = libc_malloc(BOUND_T1_SIZE * sizeof(BoundEntry *));
    se (!__bound_t1)
        bound_alloc_error();
#fim_se
    __bound_empty_t2 = __bound_new_page();
    para(i=0;i<BOUND_T1_SIZE;i++) {
        __bound_t1[i] = __bound_empty_t2;
    }

    page = __bound_new_page();
    para(i=0;i<BOUND_T2_SIZE;i++) {
        /* put invalid entries */
        page[i].start = 0;
        page[i].size = INVALID_SIZE;
        page[i].next = NULL;
        page[i].is_invalid = 1;
    }
    __bound_invalid_t2 = page;

    /* invalid pointer zone */
    start = (size_t)INVALID_POINTER & ~(BOUND_T23_SIZE - 1);
    size = BOUND_T23_SIZE;
    mark_invalid(start, size);

#se definido(CONFIG_CTEC_MALLOC_HOOKS)
    /* malloc zone is also marked invalid. can only use that with
     * hooks because all libs should use the same malloc. The solution
     * would be to build a new malloc para ctec.
     *
     * usually heap (= malloc zone) comes right after bss, i.e. after _end, but
     * not always - either se we are running from under `ctec -b -run`, or se
     * address space randomization is turned on(a), heap start will be separated
     * from bss end.
     *
     * So sbrk(0) will be a good approximation para start_brk:
     *
     *   - se we are a separately compiled program, __bound_init() runs early,
     *     and sbrk(0) should be equal or very near to start_brk(b) (in caso other
     *     constructors malloc something), or
     *
     *   - se we are running from under `ctec -b -run`, sbrk(0) will retorne
     *     start of heap portion which is under this program control, and not
     *     mark as invalid earlier allocated memory.
     *
     *
     * (a) /proc/sys/kernel/randomize_va_space = 2, on Linux;
     *     usually turned on by padrão.
     *
     * (b) on Linux >= v3.3, the alternative is to read
     *     start_brk from /proc/self/stat
     */
    start = (size_t)sbrk(0);
    size = 128 * 0x100000;
    mark_invalid(start, size);
#fim_se

    /* add all estático bound check values */
    p = (size_t *)&__bounds_start;
    enquanto (p[0] != 0) {
        __bound_new_region((vazio *)p[0], p[1]);
        p += 2;
    }

    dprintf(stderr, "%s, %s() end\n\n", __FILE__, __FUNCTION__);
}

vazio __bound_main_arg(vazio **p)
{
    vazio *start = p;
    enquanto (*p++);

    dprintf(stderr, "%s, %s calling __bound_new_region(%p %x)\n",
            __FILE__, __FUNCTION__, start, (sem_sinal)((vazio *)p - start));

    __bound_new_region(start, (vazio *) p - start);
}

vazio __bound_exit(vazio)
{
    dprintf(stderr, "%s, %s()\n", __FILE__, __FUNCTION__);
    restore_malloc_hooks();
}

estático em_linha vazio add_region(BoundEntry *e, 
                              size_t start, size_t size)
{
    BoundEntry *e1;
    se (e->start == 0) {
        /* no region : add it */
        e->start = start;
        e->size = size;
    } senão {
        /* already regions in the list: add it at the head */
        e1 = bound_new_entry();
        e1->start = e->start;
        e1->size = e->size;
        e1->next = e->next;
        e->start = start;
        e->size = size;
        e->next = e1;
    }
}

/* create a new region. It should not already exist in the region list */
vazio __bound_new_region(vazio *p, size_t size)
{
    size_t start, end;
    BoundEntry *page, *e, *e2;
    size_t t1_start, t1_end, i, t2_start, t2_end;

    dprintf(stderr, "%s, %s(%p, %x) start\n",
        __FILE__, __FUNCTION__, p, (sem_sinal)size);

    __bound_init();

    start = (size_t)p;
    end = start + size;
    t1_start = start >> (BOUND_T2_BITS + BOUND_T3_BITS);
    t1_end = end >> (BOUND_T2_BITS + BOUND_T3_BITS);

    /* start */
    page = get_page(t1_start);
    t2_start = (start >> (BOUND_T3_BITS - BOUND_E_BITS)) & 
        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS);
    t2_end = (end >> (BOUND_T3_BITS - BOUND_E_BITS)) & 
        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS);


    e = (BoundEntry *)((caractere *)page + t2_start);
    add_region(e, start, size);

    se (t1_end == t1_start) {
        /* same ending page */
        e2 = (BoundEntry *)((caractere *)page + t2_end);
        se (e2 > e) {
            e++;
            para(;e<e2;e++) {
                e->start = start;
                e->size = size;
            }
            add_region(e, start, size);
        }
    } senão {
        /* mark until end of page */
        e2 = page + BOUND_T2_SIZE;
        e++;
        para(;e<e2;e++) {
            e->start = start;
            e->size = size;
        }
        /* mark intermediate pages, se any */
        para(i=t1_start+1;i<t1_end;i++) {
            page = get_page(i);
            e2 = page + BOUND_T2_SIZE;
            para(e=page;e<e2;e++) {
                e->start = start;
                e->size = size;
            }
        }
        /* last page */
        page = get_page(t1_end);
        e2 = (BoundEntry *)((caractere *)page + t2_end);
        para(e=page;e<e2;e++) {
            e->start = start;
            e->size = size;
        }
        add_region(e, start, size);
    }

    dprintf(stderr, "%s, %s end\n", __FILE__, __FUNCTION__);
}

/* delete a region */
estático em_linha vazio delete_region(BoundEntry *e, vazio *p, size_t empty_size)
{
    size_t addr;
    BoundEntry *e1;

    addr = (size_t)p;
    addr -= e->start;
    se (addr <= e->size) {
        /* region found is first one */
        e1 = e->next;
        se (e1 == NULL) {
            /* no more region: mark it empty */
            e->start = 0;
            e->size = empty_size;
        } senão {
            /* copy next region in head */
            e->start = e1->start;
            e->size = e1->size;
            e->next = e1->next;
            bound_free_entry(e1);
        }
    } senão {
        /* find the matching region */
        para(;;) {
            e1 = e;
            e = e->next;
            /* region not found: faça nothing */
            se (e == NULL)
                pare;
            addr = (size_t)p - e->start;
            se (addr <= e->size) {
                /* found: remove entry */
                e1->next = e->next;
                bound_free_entry(e);
                pare;
            }
        }
    }
}

/* WARNING: 'p' must be the starting point of the region. */
/* retorne non zero se erro */
inteiro __bound_delete_region(vazio *p)
{
    size_t start, end, addr, size, empty_size;
    BoundEntry *page, *e, *e2;
    size_t t1_start, t1_end, t2_start, t2_end, i;

    dprintf(stderr, "%s %s() start\n", __FILE__, __FUNCTION__);

    __bound_init();

    start = (size_t)p;
    t1_start = start >> (BOUND_T2_BITS + BOUND_T3_BITS);
    t2_start = (start >> (BOUND_T3_BITS - BOUND_E_BITS)) & 
        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS);
    
    /* find region size */
    page = __bound_t1[t1_start];
    e = (BoundEntry *)((caractere *)page + t2_start);
    addr = start - e->start;
    se (addr > e->size)
        e = __bound_find_region(e, p);
    /* test se invalid region */
    se (e->size == EMPTY_SIZE || (size_t)p != e->start) 
        retorne -1;
    /* compute the size we put in invalid regions */
    se (e->is_invalid)
        empty_size = INVALID_SIZE;
    senão
        empty_size = EMPTY_SIZE;
    size = e->size;
    end = start + size;

    /* now we can free each entry */
    t1_end = end >> (BOUND_T2_BITS + BOUND_T3_BITS);
    t2_end = (end >> (BOUND_T3_BITS - BOUND_E_BITS)) & 
        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS);

    delete_region(e, p, empty_size);
    se (t1_end == t1_start) {
        /* same ending page */
        e2 = (BoundEntry *)((caractere *)page + t2_end);
        se (e2 > e) {
            e++;
            para(;e<e2;e++) {
                e->start = 0;
                e->size = empty_size;
            }
            delete_region(e, p, empty_size);
        }
    } senão {
        /* mark until end of page */
        e2 = page + BOUND_T2_SIZE;
        e++;
        para(;e<e2;e++) {
            e->start = 0;
            e->size = empty_size;
        }
        /* mark intermediate pages, se any */
        /* XXX: should free them */
        para(i=t1_start+1;i<t1_end;i++) {
            page = get_page(i);
            e2 = page + BOUND_T2_SIZE;
            para(e=page;e<e2;e++) {
                e->start = 0;
                e->size = empty_size;
            }
        }
        /* last page */
        page = get_page(t1_end);
        e2 = (BoundEntry *)((caractere *)page + t2_end);
        para(e=page;e<e2;e++) {
            e->start = 0;
            e->size = empty_size;
        }
        delete_region(e, p, empty_size);
    }

    dprintf(stderr, "%s %s() end\n", __FILE__, __FUNCTION__);

    retorne 0;
}

/* retorne the size of the region starting at p, or EMPTY_SIZE se non
   existent region. */
estático size_t get_region_size(vazio *p)
{
    size_t addr = (size_t)p;
    BoundEntry *e;

    e = __bound_t1[addr >> (BOUND_T2_BITS + BOUND_T3_BITS)];
    e = (BoundEntry *)((caractere *)e + 
                       ((addr >> (BOUND_T3_BITS - BOUND_E_BITS)) & 
                        ((BOUND_T2_SIZE - 1) << BOUND_E_BITS)));
    addr -= e->start;
    se (addr > e->size)
        e = __bound_find_region(e, p);
    se (e->start != (size_t)p)
        retorne EMPTY_SIZE;
    retorne e->size;
}

/* patched memory functions */

/* force compiler to perform stores coded up to this point */
#defina barrier()   __asm__ __volatile__ ("": : : "memory")

estático vazio install_malloc_hooks(vazio)
{
#se_definido CONFIG_CTEC_MALLOC_HOOKS
    saved_malloc_hook = __malloc_hook;
    saved_free_hook = __free_hook;
    saved_realloc_hook = __realloc_hook;
    saved_memalign_hook = __memalign_hook;
    __malloc_hook = __bound_malloc;
    __free_hook = __bound_free;
    __realloc_hook = __bound_realloc;
    __memalign_hook = __bound_memalign;

    barrier();
#fim_se
}

estático vazio restore_malloc_hooks(vazio)
{
#se_definido CONFIG_CTEC_MALLOC_HOOKS
    __malloc_hook = saved_malloc_hook;
    __free_hook = saved_free_hook;
    __realloc_hook = saved_realloc_hook;
    __memalign_hook = saved_memalign_hook;

    barrier();
#fim_se
}

estático vazio *libc_malloc(size_t size)
{
    vazio *ptr;
    restore_malloc_hooks();
    ptr = malloc(size);
    install_malloc_hooks();
    retorne ptr;
}

estático vazio libc_free(vazio *ptr)
{
    restore_malloc_hooks();
    free(ptr);
    install_malloc_hooks();
}

/* XXX: we should use a malloc which ensure that it is unlikely that
   two malloc'ed data have the same address se 'free' are made in
   between. */
vazio *__bound_malloc(size_t size, constante vazio *caller)
{
    vazio *ptr;
    
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = libc_malloc(size + 1);
    
    se (!ptr)
        retorne NULL;

    dprintf(stderr, "%s, %s calling __bound_new_region(%p, %x)\n",
           __FILE__, __FUNCTION__, ptr, (sem_sinal)size);

    __bound_new_region(ptr, size);
    retorne ptr;
}

vazio *__bound_memalign(size_t size, size_t align, constante vazio *caller)
{
    vazio *ptr;

    restore_malloc_hooks();

#se_não_definido HAVE_MEMALIGN
    se (align > 4) {
        /* XXX: handle it ? */
        ptr = NULL;
    } senão {
        /* we suppose that malloc aligns to at least four bytes */
        ptr = malloc(size + 1);
    }
#senão
    /* we allocate one more byte to ensure the regions will be
       separated by at least one byte. With the glibc malloc, it may
       be in fact not necessary */
    ptr = memalign(size + 1, align);
#fim_se
    
    install_malloc_hooks();
    
    se (!ptr)
        retorne NULL;

    dprintf(stderr, "%s, %s calling __bound_new_region(%p, %x)\n",
           __FILE__, __FUNCTION__, ptr, (sem_sinal)size);

    __bound_new_region(ptr, size);
    retorne ptr;
}

vazio __bound_free(vazio *ptr, constante vazio *caller)
{
    se (ptr == NULL)
        retorne;
    se (__bound_delete_region(ptr) != 0)
        bound_error("freeing invalid region");

    libc_free(ptr);
}

vazio *__bound_realloc(vazio *ptr, size_t size, constante vazio *caller)
{
    vazio *ptr1;
    size_t old_size;

    se (size == 0) {
        __bound_free(ptr, caller);
        retorne NULL;
    } senão {
        ptr1 = __bound_malloc(size, caller);
        se (ptr == NULL || ptr1 == NULL)
            retorne ptr1;
        old_size = get_region_size(ptr);
        se (old_size == EMPTY_SIZE)
            bound_error("realloc'ing invalid pointer");
        memcpy(ptr1, ptr, old_size);
        __bound_free(ptr, caller);
        retorne ptr1;
    }
}

#se_não_definido CONFIG_CTEC_MALLOC_HOOKS
vazio *__bound_calloc(size_t nmemb, size_t size)
{
    vazio *ptr;
    size = size * nmemb;
    ptr = __bound_malloc(size, NULL);
    se (!ptr)
        retorne NULL;
    memset(ptr, 0, size);
    retorne ptr;
}
#fim_se

#se 0
estático vazio bound_dump(vazio)
{
    BoundEntry *page, *e;
    size_t i, j;

    fprintf(stderr, "region dump:\n");
    para(i=0;i<BOUND_T1_SIZE;i++) {
        page = __bound_t1[i];
        para(j=0;j<BOUND_T2_SIZE;j++) {
            e = page + j;
            /* faça not print invalid or empty entries */
            se (e->size != EMPTY_SIZE && e->start != 0) {
                fprintf(stderr, "%08x:", 
                       (i << (BOUND_T2_BITS + BOUND_T3_BITS)) + 
                       (j << BOUND_T3_BITS));
                faça {
                    fprintf(stderr, " %08lx:%08lx", e->start, e->start + e->size);
                    e = e->next;
                } enquanto (e != NULL);
                fprintf(stderr, "\n");
            }
        }
    }
}
#fim_se

/* some useful checked functions */

/* check that (p ... p + size - 1) lies inside 'p' region, se any */
estático vazio __bound_check(constante vazio *p, size_t size)
{
    se (size == 0)
        retorne;
    p = __bound_ptr_add((vazio *)p, size - 1);
    se (p == INVALID_POINTER)
        bound_error("invalid pointer");
}

vazio *__bound_memcpy(vazio *dst, constante vazio *src, size_t size)
{
    vazio* p;

    dprintf(stderr, "%s %s: start, dst=%p src=%p size=%x\n",
            __FILE__, __FUNCTION__, dst, src, (sem_sinal)size);

    __bound_check(dst, size);
    __bound_check(src, size);
    /* check also region overlap */
    se (src >= dst && src < dst + size)
        bound_error("overlapping regions in memcpy()");

    p = memcpy(dst, src, size);

    dprintf(stderr, "%s %s: end, p=%p\n", __FILE__, __FUNCTION__, p);
    retorne p;
}

vazio *__bound_memmove(vazio *dst, constante vazio *src, size_t size)
{
    __bound_check(dst, size);
    __bound_check(src, size);
    retorne memmove(dst, src, size);
}

vazio *__bound_memset(vazio *dst, inteiro c, size_t size)
{
    __bound_check(dst, size);
    retorne memset(dst, c, size);
}

/* XXX: could be optimized */
inteiro __bound_strlen(constante caractere *s)
{
    constante caractere *p;
    size_t len;

    len = 0;
    para(;;) {
        p = __bound_ptr_indir1((caractere *)s, len);
        se (p == INVALID_POINTER)
            bound_error("bad pointer in strlen()");
        se (*p == '\0')
            pare;
        len++;
    }
    retorne len;
}

caractere *__bound_strcpy(caractere *dst, constante caractere *src)
{
    size_t len;
    vazio *p;

    dprintf(stderr, "%s %s: strcpy start, dst=%p src=%p\n",
            __FILE__, __FUNCTION__, dst, src);
    len = __bound_strlen(src);
    p = __bound_memcpy(dst, src, len + 1);
    dprintf(stderr, "%s %s: strcpy end, p = %p\n",
            __FILE__, __FUNCTION__, p);
    retorne p;
}
