/*
 *  CTEC - Tiny C Compiler
 *
 *  Copyright (c) 2001-2004 Fabrice Bellard
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

#inclua "ctec.h"

/********************************************************/
/* global variables */

/* use GNU C extensions */
ST_DATA inteiro gnu_ext = 1;

/* use TinyCC extensions */
ST_DATA inteiro ctec_ext = 1;

/* XXX: get rid of this ASAP */
ST_DATA estrutura CTECState *ctec_state;

estático inteiro nb_states;

/********************************************************/

#se ONE_SOURCE
#inclua "ctecpp.c"
#inclua "ctecgen.c"
#inclua "ctecelf.c"
#inclua "ctecrun.c"
#se_definido CTEC_TARGET_I386
#inclua "i386-gen.c"
#inclua "i386-link.c"
#inclua "i386-asm.c"
#fim_se
#se_definido CTEC_TARGET_ARM
#inclua "arm-gen.c"
#inclua "arm-link.c"
#inclua "arm-asm.c"
#fim_se
#se_definido CTEC_TARGET_ARM64
#inclua "arm64-gen.c"
#inclua "arm64-link.c"
#fim_se
#se_definido CTEC_TARGET_C67
#inclua "c67-gen.c"
#inclua "c67-link.c"
#inclua "cteccoff.c"
#fim_se
#se_definido CTEC_TARGET_X86_64
#inclua "x86_64-gen.c"
#inclua "x86_64-link.c"
#inclua "i386-asm.c"
#fim_se
#se_definido CONFIG_CTEC_ASM
#inclua "ctecasm.c"
#fim_se
#se_definido CTEC_TARGET_PE
#inclua "ctecpe.c"
#fim_se
#fim_se /* ONE_SOURCE */

/********************************************************/
#se_não_definido CONFIG_CTEC_ASM
ST_FUNC vazio asm_instr(vazio)
{
    ctec_error("em_linha asm() not supported");
}
ST_FUNC vazio asm_global_instr(vazio)
{
    ctec_error("em_linha asm() not supported");
}
#fim_se

/********************************************************/
#se_definido _WIN32
ST_FUNC caractere *normalize_slashes(caractere *path)
{
    caractere *p;
    para (p = path; *p; ++p)
        se (*p == '\\')
            *p = '/';
    retorne path;
}

estático HMODULE ctec_module;

/* on win32, we suppose the lib and includes are at the location of 'ctec.exe' */
estático vazio ctec_set_lib_path_w32(CTECState *s)
{
    caractere path[1024], *p;
    GetModuleFileNameA(ctec_module, path, sizeof path);
    p = ctec_basename(normalize_slashes(strlwr(path)));
    se (p > path)
        --p;
    *p = 0;
    ctec_set_lib_path(s, path);
}

#se_definido CTEC_TARGET_PE
estático vazio ctec_add_systemdir(CTECState *s)
{
    caractere buf[1000];
    GetSystemDirectory(buf, sizeof buf);
    ctec_add_library_path(s, normalize_slashes(buf));
}
#fim_se

#se_definido LIBCTEC_AS_DLL
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    se (DLL_PROCESS_ATTACH == dwReason)
        ctec_module = hDll;
    retorne TRUE;
}
#fim_se
#fim_se

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC caractere *pstrcpy(caractere *buf, inteiro buf_size, constante caractere *s)
{
    caractere *q, *q_end;
    inteiro c;

    se (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        enquanto (q < q_end) {
            c = *s++;
            se (c == '\0')
                pare;
            *q++ = c;
        }
        *q = '\0';
    }
    retorne buf;
}

/* strcat and truncate. */
ST_FUNC caractere *pstrcat(caractere *buf, inteiro buf_size, constante caractere *s)
{
    inteiro len;
    len = strlen(buf);
    se (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    retorne buf;
}

ST_FUNC caractere *pstrncpy(caractere *out, constante caractere *in, size_t num)
{
    memcpy(out, in, num);
    out[num] = '\0';
    retorne out;
}

/* extract the basename of a file */
PUB_FUNC caractere *ctec_basename(constante caractere *name)
{
    caractere *p = strchr(name, 0);
    enquanto (p > name && !IS_DIRSEP(p[-1]))
        --p;
    retorne p;
}

/* extract extension part of a file
 *
 * (se no extension, retorne pointer to end-of-string)
 */
PUB_FUNC caractere *ctec_fileextension (constante caractere *name)
{
    caractere *b = ctec_basename(name);
    caractere *e = strrchr(b, '.');
    retorne e ? e : strchr(b, 0);
}

/********************************************************/
/* memory management */

#não_definido free
#não_definido malloc
#não_definido realloc

#se_não_definido MEM_DEBUG

PUB_FUNC vazio ctec_free(vazio *ptr)
{
    free(ptr);
}

PUB_FUNC vazio *ctec_malloc(sem_sinal longo size)
{
    vazio *ptr;
    ptr = malloc(size);
    se (!ptr && size)
        ctec_error("memory full (malloc)");
    retorne ptr;
}

PUB_FUNC vazio *ctec_mallocz(sem_sinal longo size)
{
    vazio *ptr;
    ptr = ctec_malloc(size);
    memset(ptr, 0, size);
    retorne ptr;
}

PUB_FUNC vazio *ctec_realloc(vazio *ptr, sem_sinal longo size)
{
    vazio *ptr1;
    ptr1 = realloc(ptr, size);
    se (!ptr1 && size)
        ctec_error("memory full (realloc)");
    retorne ptr1;
}

PUB_FUNC caractere *ctec_strdup(constante caractere *str)
{
    caractere *ptr;
    ptr = ctec_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    retorne ptr;
}

PUB_FUNC vazio ctec_memcheck(vazio)
{
}

#senão

#defina MEM_DEBUG_MAGIC1 0xFEEDDEB1
#defina MEM_DEBUG_MAGIC2 0xFEEDDEB2
#defina MEM_DEBUG_MAGIC3 0xFEEDDEB3
#defina MEM_DEBUG_FILE_LEN 40
#defina MEM_DEBUG_CHECK3(header) \
    ((mem_debug_header_t*)((caractere*)header + header->size))->magic3
#defina MEM_USER_PTR(header) \
    ((caractere *)header + offsetof(mem_debug_header_t, magic3))
#defina MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((caractere*)ptr - offsetof(mem_debug_header_t, magic3))

estrutura mem_debug_header {
    sem_sinal magic1;
    sem_sinal size;
    estrutura mem_debug_header *prev;
    estrutura mem_debug_header *next;
    inteiro line_num;
    caractere file_name[MEM_DEBUG_FILE_LEN + 1];
    sem_sinal magic2;
    ALIGNED(16) sem_sinal magic3;
};

defina_tipo estrutura mem_debug_header mem_debug_header_t;

estático mem_debug_header_t *mem_debug_chain;
estático sem_sinal mem_cur_size;
estático sem_sinal mem_max_size;

estático mem_debug_header_t *malloc_check(vazio *ptr, constante caractere *msg)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    se (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        MEM_DEBUG_CHECK3(header) != MEM_DEBUG_MAGIC3 ||
        header->size == (sem_sinal)-1) {
        fprintf(stderr, "%s check failed\n", msg);
        se (header->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                header->file_name, header->line_num);
        exit(1);
    }
    retorne header;
}

PUB_FUNC vazio *ctec_malloc_debug(sem_sinal longo size, constante caractere *file, inteiro linha)
{
    inteiro ofs;
    mem_debug_header_t *header;

    header = malloc(sizeof(mem_debug_header_t) + size);
    se (!header)
        ctec_error("memory full (malloc)");

    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->size = size;
    MEM_DEBUG_CHECK3(header) = MEM_DEBUG_MAGIC3;
    header->line_num = linha;
    ofs = strlen(file) - MEM_DEBUG_FILE_LEN;
    strncpy(header->file_name, file + (ofs > 0 ? ofs : 0), MEM_DEBUG_FILE_LEN);
    header->file_name[MEM_DEBUG_FILE_LEN] = 0;

    header->next = mem_debug_chain;
    header->prev = NULL;
    se (header->next)
        header->next->prev = header;
    mem_debug_chain = header;

    mem_cur_size += size;
    se (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;

    retorne MEM_USER_PTR(header);
}

PUB_FUNC vazio ctec_free_debug(vazio *ptr)
{
    mem_debug_header_t *header;
    se (!ptr)
        retorne;
    header = malloc_check(ptr, "ctec_free");
    mem_cur_size -= header->size;
    header->size = (sem_sinal)-1;
    se (header->next)
        header->next->prev = header->prev;
    se (header->prev)
        header->prev->next = header->next;
    se (header == mem_debug_chain)
        mem_debug_chain = header->next;
    free(header);
}

PUB_FUNC vazio *ctec_mallocz_debug(sem_sinal longo size, constante caractere *file, inteiro linha)
{
    vazio *ptr;
    ptr = ctec_malloc_debug(size,file,linha);
    memset(ptr, 0, size);
    retorne ptr;
}

PUB_FUNC vazio *ctec_realloc_debug(vazio *ptr, sem_sinal longo size, constante caractere *file, inteiro linha)
{
    mem_debug_header_t *header;
    inteiro mem_debug_chain_update = 0;
    se (!ptr)
        retorne ctec_malloc_debug(size, file, linha);
    header = malloc_check(ptr, "ctec_realloc");
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = realloc(header, sizeof(mem_debug_header_t) + size);
    se (!header)
        ctec_error("memory full (realloc)");
    header->size = size;
    MEM_DEBUG_CHECK3(header) = MEM_DEBUG_MAGIC3;
    se (header->next)
        header->next->prev = header;
    se (header->prev)
        header->prev->next = header;
    se (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    se (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    retorne MEM_USER_PTR(header);
}

PUB_FUNC caractere *ctec_strdup_debug(constante caractere *str, constante caractere *file, inteiro linha)
{
    caractere *ptr;
    ptr = ctec_malloc_debug(strlen(str) + 1, file, linha);
    strcpy(ptr, str);
    retorne ptr;
}

PUB_FUNC vazio ctec_memcheck(vazio)
{
    se (mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        enquanto (header) {
            fprintf(stderr, "%s:%u: erro: %u bytes leaked\n",
                header->file_name, header->line_num, header->size);
            header = header->next;
        }
#se MEM_DEBUG-0 == 2
        exit(2);
#fim_se
    }
}
#fim_se /* MEM_DEBUG */

#defina free(p) use_ctec_free(p)
#defina malloc(s) use_ctec_malloc(s)
#defina realloc(p, s) use_ctec_realloc(p, s)

/********************************************************/
/* dynarrays */

ST_FUNC vazio dynarray_add(vazio *ptab, inteiro *nb_ptr, vazio *data)
{
    inteiro nb, nb_alloc;
    vazio **pp;

    nb = *nb_ptr;
    pp = *(vazio ***)ptab;
    /* every power of two we duplo array size */
    se ((nb & (nb - 1)) == 0) {
        se (!nb)
            nb_alloc = 1;
        senão
            nb_alloc = nb * 2;
        pp = ctec_realloc(pp, nb_alloc * sizeof(vazio *));
        *(vazio***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC vazio dynarray_reset(vazio *pp, inteiro *n)
{
    vazio **p;
    para (p = *(vazio***)pp; *n; ++p, --*n)
        se (*p)
            ctec_free(*p);
    ctec_free(*(vazio**)pp);
    *(vazio**)pp = NULL;
}

estático vazio ctec_split_path(CTECState *s, vazio *p_ary, inteiro *p_nb_ary, constante caractere *in)
{
    constante caractere *p;
    faça {
        inteiro c;
        CString str;

        cstr_new(&str);
        para (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            se (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                se (c == 'B')
                    cstr_cat(&str, s->ctec_lib_path, -1);
            } senão {
                cstr_ccat(&str, c);
            }
        }
        se (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, ctec_strdup(str.data));
        }
        cstr_free(&str);
        in = p+1;
    } enquanto (*p);
}

/********************************************************/

estático vazio strcat_vprintf(caractere *buf, inteiro buf_size, constante caractere *fmt, va_list ap)
{
    inteiro len;
    len = strlen(buf);
    vsnprintf(buf + len, buf_size - len, fmt, ap);
}

estático vazio strcat_printf(caractere *buf, inteiro buf_size, constante caractere *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    strcat_vprintf(buf, buf_size, fmt, ap);
    va_end(ap);
}

estático vazio error1(CTECState *s1, inteiro is_warning, constante caractere *fmt, va_list ap)
{
    caractere buf[2048];
    BufferedFile **pf, *f;

    buf[0] = '\0';
    /* use upper file se em_linha ":asm:" or token ":paste:" */
    para (f = file; f && f->filename[0] == ':'; f = f->prev)
     ;
    se (f) {
        para(pf = s1->include_stack; pf < s1->include_stack_ptr; pf++)
            strcat_printf(buf, sizeof(buf), "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->line_num);
        se (s1->error_set_jmp_enabled) {
            strcat_printf(buf, sizeof(buf), "%s:%d: ",
                f->filename, f->line_num - !!(tok_flags & TOK_FLAG_BOL));
        } senão {
            strcat_printf(buf, sizeof(buf), "%s: ",
                f->filename);
        }
    } senão {
        strcat_printf(buf, sizeof(buf), "ctec: ");
    }
    se (is_warning)
        strcat_printf(buf, sizeof(buf), "aviso: ");
    senão
        strcat_printf(buf, sizeof(buf), "erro: ");
    strcat_vprintf(buf, sizeof(buf), fmt, ap);

    se (!s1->error_func) {
        /* padrão caso: stderr */
        se (s1->output_type == CTEC_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            /* print a newline during ctec -E */
            printf("\n"), fflush(stdout);
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", buf);
        fflush(stderr); /* print erro/aviso now (win32) */
    } senão {
        s1->error_func(s1->error_opaque, buf);
    }
    se (!is_warning || s1->warn_error)
        s1->nb_errors++;
}

LIBCTECAPI vazio ctec_set_error_func(CTECState *s, vazio *error_opaque,
                        vazio (*error_func)(vazio *opaque, constante caractere *msg))
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* erro without aborting current compilation */
PUB_FUNC vazio ctec_error_noabort(constante caractere *fmt, ...)
{
    CTECState *s1 = ctec_state;
    va_list ap;

    va_start(ap, fmt);
    error1(s1, 0, fmt, ap);
    va_end(ap);
}

PUB_FUNC vazio ctec_error(constante caractere *fmt, ...)
{
    CTECState *s1 = ctec_state;
    va_list ap;

    va_start(ap, fmt);
    error1(s1, 0, fmt, ap);
    va_end(ap);
    /* better than nothing: in some cases, we accept to handle errors */
    se (s1->error_set_jmp_enabled) {
        longjmp(s1->error_jmp_buf, 1);
    } senão {
        /* XXX: eliminate this someday */
        exit(1);
    }
}

PUB_FUNC vazio ctec_warning(constante caractere *fmt, ...)
{
    CTECState *s1 = ctec_state;
    va_list ap;

    se (s1->warn_none)
        retorne;

    va_start(ap, fmt);
    error1(s1, 1, fmt, ap);
    va_end(ap);
}

/********************************************************/
/* I/O layer */

ST_FUNC vazio ctec_open_bf(CTECState *s1, constante caractere *filename, inteiro initlen)
{
    BufferedFile *bf;
    inteiro buflen = initlen ? initlen : IO_BUF_SIZE;

    bf = ctec_mallocz(sizeof(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, sizeof(bf->filename), filename);
    bf->true_filename = bf->filename;
    bf->line_num = 1;
    bf->ifdef_stack_ptr = s1->ifdef_stack_ptr;
    bf->fd = -1;
    bf->prev = file;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC vazio ctec_close(vazio)
{
    BufferedFile *bf = file;
    se (bf->fd > 0) {
        close(bf->fd);
        total_lines += bf->line_num;
    }
    se (bf->true_filename != bf->filename)
        ctec_free(bf->true_filename);
    file = bf->prev;
    ctec_free(bf);
}

ST_FUNC inteiro ctec_open(CTECState *s1, constante caractere *filename)
{
    inteiro fd;
    se (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    senão
        fd = open(filename, O_RDONLY | O_BINARY);
    se ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        printf("%s %*s%s\n", fd < 0 ? "nf":"->",
               (inteiro)(s1->include_stack_ptr - s1->include_stack), "", filename);
    se (fd < 0)
        retorne -1;
    ctec_open_bf(s1, filename, 0);
#se_definido _WIN32
    normalize_slashes(file->filename);
#fim_se
    file->fd = fd;
    retorne fd;
}

/* compile the file opened in 'file'. Return non zero se errors. */
estático inteiro ctec_compile(CTECState *s1)
{
    Sym *define_start;
    inteiro filetype, is_asm;

    define_start = define_stack;
    filetype = s1->filetype;
    is_asm = filetype == AFF_TYPE_ASM || filetype == AFF_TYPE_ASMPP;
    ctecelf_begin_file(s1);

    se (setjmp(s1->error_jmp_buf) == 0) {
        s1->nb_errors = 0;
        s1->error_set_jmp_enabled = 1;

        preprocess_start(s1, is_asm);
        se (s1->output_type == CTEC_OUTPUT_PREPROCESS) {
            ctec_preprocess(s1);
        } senão se (is_asm) {
#se_definido CONFIG_CTEC_ASM
            ctec_assemble(s1, filetype == AFF_TYPE_ASMPP);
#senão
            ctec_error_noabort("asm not supported");
#fim_se
        } senão {
            ctecgen_compile(s1);
        }
    }
    s1->error_set_jmp_enabled = 0;

    preprocess_end(s1);
    free_inline_functions(s1);
    /* reset defina stack, but keep -D and built-ins */
    free_defines(define_start);
    sym_pop(&global_stack, NULL, 0);
    sym_pop(&local_stack, NULL, 0);
    ctecelf_end_file(s1);
    retorne s1->nb_errors != 0 ? -1 : 0;
}

LIBCTECAPI inteiro ctec_compile_string(CTECState *s, constante caractere *str)
{
    inteiro len, ret;

    len = strlen(str);
    ctec_open_bf(s, "<string>", len);
    memcpy(file->buffer, str, len);
    ret = ctec_compile(s);
    ctec_close();
    retorne ret;
}

/* defina a preprocessor symbol. A value can also be provided with the '=' operator */
LIBCTECAPI vazio ctec_define_symbol(CTECState *s1, constante caractere *sym, constante caractere *value)
{
    inteiro len1, len2;
    /* padrão value */
    se (!value)
        value = "1";
    len1 = strlen(sym);
    len2 = strlen(value);

    /* init file structure */
    ctec_open_bf(s1, "<defina>", len1 + len2 + 1);
    memcpy(file->buffer, sym, len1);
    file->buffer[len1] = ' ';
    memcpy(file->buffer + len1 + 1, value, len2);

    /* parse with defina parser */
    next_nomacro();
    parse_define();
    ctec_close();
}

/* undefine a preprocessor symbol */
LIBCTECAPI vazio ctec_undefine_symbol(CTECState *s1, constante caractere *sym)
{
    TokenSym *ts;
    Sym *s;
    ts = tok_alloc(sym, strlen(sym));
    s = define_find(ts->tok);
    /* undefine symbol by putting an invalid name */
    se (s)
        define_undef(s);
}

/* cleanup all estático data used during compilation */
estático vazio ctec_cleanup(vazio)
{
    se (NULL == ctec_state)
        retorne;
    enquanto (file)
        ctec_close();
    ctecpp_delete(ctec_state);
    ctec_state = NULL;
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    /* reset symbol stack */
    sym_free_first = NULL;
}

LIBCTECAPI CTECState *ctec_new(vazio)
{
    CTECState *s;

    ctec_cleanup();

    s = ctec_mallocz(sizeof(CTECState));
    se (!s)
        retorne NULL;
    ctec_state = s;
    ++nb_states;

    s->alacarte_link = 1;
    s->nocommon = 1;
    s->warn_implicit_function_declaration = 1;
    s->ms_extensions = 1;

#se_definido CHAR_IS_UNSIGNED
    s->char_is_unsigned = 1;
#fim_se
#se_definido CTEC_TARGET_I386
    s->seg_size = 32;
#fim_se
    /* enable this se you want symbols with leading underscore on windows: */
#se 0 /* def CTEC_TARGET_PE */
    s->leading_underscore = 1;
#fim_se
#se_definido _WIN32
    ctec_set_lib_path_w32(s);
#senão
    ctec_set_lib_path(s, CONFIG_CTECDIR);
#fim_se
    ctecelf_new(s);
    ctecpp_new(s);

    /* we add dummy defines para some special macros to speed up tests
       and to have working definido() */
    define_push(TOK___LINE__, MACRO_OBJ, NULL, NULL);
    define_push(TOK___FILE__, MACRO_OBJ, NULL, NULL);
    define_push(TOK___DATE__, MACRO_OBJ, NULL, NULL);
    define_push(TOK___TIME__, MACRO_OBJ, NULL, NULL);
    define_push(TOK___COUNTER__, MACRO_OBJ, NULL, NULL);
    {
        /* defina __TINYC__ 92X  */
        caractere buffer[32]; inteiro a,b,c;
        sscanf(CTEC_VERSION, "%d.%d.%d", &a, &b, &c);
        sprintf(buffer, "%d", a*10000 + b*100 + c);
        ctec_define_symbol(s, "__TINYC__", buffer);
    }

    /* standard defines */
    ctec_define_symbol(s, "__STDC__", NULL);
    ctec_define_symbol(s, "__STDC_VERSION__", "199901L");
    ctec_define_symbol(s, "__STDC_HOSTED__", NULL);

    /* target defines */
#se definido(CTEC_TARGET_I386)
    ctec_define_symbol(s, "__i386__", NULL);
    ctec_define_symbol(s, "__i386", NULL);
    ctec_define_symbol(s, "i386", NULL);
#senão_se definido(CTEC_TARGET_X86_64)
    ctec_define_symbol(s, "__x86_64__", NULL);
#senão_se definido(CTEC_TARGET_ARM)
    ctec_define_symbol(s, "__ARM_ARCH_4__", NULL);
    ctec_define_symbol(s, "__arm_elf__", NULL);
    ctec_define_symbol(s, "__arm_elf", NULL);
    ctec_define_symbol(s, "arm_elf", NULL);
    ctec_define_symbol(s, "__arm__", NULL);
    ctec_define_symbol(s, "__arm", NULL);
    ctec_define_symbol(s, "arm", NULL);
    ctec_define_symbol(s, "__APCS_32__", NULL);
    ctec_define_symbol(s, "__ARMEL__", NULL);
#se definido(CTEC_ARM_EABI)
    ctec_define_symbol(s, "__ARM_EABI__", NULL);
#fim_se
#se definido(CTEC_ARM_HARDFLOAT)
    s->float_abi = ARM_HARD_FLOAT;
    ctec_define_symbol(s, "__ARM_PCS_VFP", NULL);
#senão
    s->float_abi = ARM_SOFTFP_FLOAT;
#fim_se
#senão_se definido(CTEC_TARGET_ARM64)
    ctec_define_symbol(s, "__aarch64__", NULL);
#senão_se definido CTEC_TARGET_C67
    ctec_define_symbol(s, "__C67__", NULL);
#fim_se

#se_definido CTEC_TARGET_PE
    ctec_define_symbol(s, "_WIN32", NULL);
# se_definido CTEC_TARGET_X86_64
    ctec_define_symbol(s, "_WIN64", NULL);
# fim_se
#senão
    ctec_define_symbol(s, "__unix__", NULL);
    ctec_define_symbol(s, "__unix", NULL);
    ctec_define_symbol(s, "unix", NULL);
# se definido(__linux__)
    ctec_define_symbol(s, "__linux__", NULL);
    ctec_define_symbol(s, "__linux", NULL);
# fim_se
# se definido(__FreeBSD__)
    ctec_define_symbol(s, "__FreeBSD__", "__FreeBSD__");
    /* No 'Thread Storage Local' on FreeBSD with ctec */
    ctec_define_symbol(s, "__NO_TLS", NULL);
# fim_se
# se definido(__FreeBSD_kernel__)
    ctec_define_symbol(s, "__FreeBSD_kernel__", NULL);
# fim_se
# se definido(__NetBSD__)
    ctec_define_symbol(s, "__NetBSD__", "__NetBSD__");
# fim_se
# se definido(__OpenBSD__)
    ctec_define_symbol(s, "__OpenBSD__", "__OpenBSD__");
# fim_se
#fim_se

    /* TinyCC & gcc defines */
#se PTR_SIZE == 4
    /* 32bit systems. */
    ctec_define_symbol(s, "__SIZE_TYPE__", "sem_sinal inteiro");
    ctec_define_symbol(s, "__PTRDIFF_TYPE__", "inteiro");
    ctec_define_symbol(s, "__ILP32__", NULL);
#senão_se LONG_SIZE == 4
    /* 64bit Windows. */
    ctec_define_symbol(s, "__SIZE_TYPE__", "sem_sinal longo longo");
    ctec_define_symbol(s, "__PTRDIFF_TYPE__", "longo longo");
    ctec_define_symbol(s, "__LLP64__", NULL);
#senão
    /* Other 64bit systems. */
    ctec_define_symbol(s, "__SIZE_TYPE__", "sem_sinal longo");
    ctec_define_symbol(s, "__PTRDIFF_TYPE__", "longo");
    ctec_define_symbol(s, "__LP64__", NULL);
#fim_se

#se_definido CTEC_TARGET_PE
    ctec_define_symbol(s, "__WCHAR_TYPE__", "sem_sinal curto");
    ctec_define_symbol(s, "__WINT_TYPE__", "sem_sinal curto");
#senão
    ctec_define_symbol(s, "__WCHAR_TYPE__", "inteiro");
    /* wint_t is sem_sinal inteiro by padrão, but (sinalizado) inteiro on BSDs
       and sem_sinal curto on windows.  Other OSes might have still
       other conventions, sigh.  */
# se definido(__FreeBSD__) || definido (__FreeBSD_kernel__) \
  || definido(__NetBSD__) || definido(__OpenBSD__)
    ctec_define_symbol(s, "__WINT_TYPE__", "inteiro");
#  se_definido __FreeBSD__
    /* defina __GNUC__ to have some useful stuff from sys/cdefs.h
       that are unconditionally used in FreeBSDs other system headers :/ */
    ctec_define_symbol(s, "__GNUC__", "2");
    ctec_define_symbol(s, "__GNUC_MINOR__", "7");
    ctec_define_symbol(s, "__builtin_alloca", "alloca");
#  fim_se
# senão
    ctec_define_symbol(s, "__WINT_TYPE__", "sem_sinal inteiro");
    /* glibc defines */
    ctec_define_symbol(s, "__REDIRECT(name, proto, alias)",
        "name proto __asm__ (#alias)");
    ctec_define_symbol(s, "__REDIRECT_NTH(name, proto, alias)",
        "name proto __asm__ (#alias) __THROW");
# fim_se
# se definido(CTEC_MUSL)
    ctec_define_symbol(s, "__DEFINED_va_list", "");
    ctec_define_symbol(s, "__DEFINED___isoc_va_list", "");
    ctec_define_symbol(s, "__isoc_va_list", "vazio *");
# fim_se /* CTEC_MUSL */
    /* Some GCC builtins that are simple to express as macros.  */
    ctec_define_symbol(s, "__builtin_extract_return_addr(x)", "x");
#fim_se /* ndef CTEC_TARGET_PE */
    retorne s;
}

LIBCTECAPI vazio ctec_delete(CTECState *s1)
{
    ctec_cleanup();

    /* free sections */
    ctecelf_delete(s1);

    /* free library paths */
    dynarray_reset(&s1->library_paths, &s1->nb_library_paths);
    dynarray_reset(&s1->crt_paths, &s1->nb_crt_paths);

    /* free inclua paths */
    dynarray_reset(&s1->cached_includes, &s1->nb_cached_includes);
    dynarray_reset(&s1->include_paths, &s1->nb_include_paths);
    dynarray_reset(&s1->sysinclude_paths, &s1->nb_sysinclude_paths);
    dynarray_reset(&s1->cmd_include_files, &s1->nb_cmd_include_files);

    ctec_free(s1->ctec_lib_path);
    ctec_free(s1->soname);
    ctec_free(s1->rpath);
    ctec_free(s1->init_symbol);
    ctec_free(s1->fini_symbol);
    ctec_free(s1->outfile);
    ctec_free(s1->deps_outfile);
    dynarray_reset(&s1->files, &s1->nb_files);
    dynarray_reset(&s1->target_deps, &s1->nb_target_deps);
    dynarray_reset(&s1->pragma_libs, &s1->nb_pragma_libs);
    dynarray_reset(&s1->argv, &s1->argc);

#se_definido CTEC_IS_NATIVE
    /* free runtime memory */
    ctec_run_free(s1);
#fim_se

    ctec_free(s1);
    se (0 == --nb_states)
        ctec_memcheck();
}

LIBCTECAPI inteiro ctec_set_output_type(CTECState *s, inteiro output_type)
{
    s->output_type = output_type;

    /* always elf para objects */
    se (output_type == CTEC_OUTPUT_OBJ)
        s->output_format = CTEC_OUTPUT_FORMAT_ELF;

    se (s->char_is_unsigned)
        ctec_define_symbol(s, "__CHAR_UNSIGNED__", NULL);

    se (!s->nostdinc) {
        /* padrão inclua paths */
        /* -isystem paths have already been handled */
        ctec_add_sysinclude_path(s, CONFIG_CTEC_SYSINCLUDEPATHS);
    }

#se_definido CONFIG_CTEC_BCHECK
    se (s->do_bounds_check) {
        /* se bound checking, then add corresponding sections */
        ctecelf_bounds_new(s);
        /* defina symbol */
        ctec_define_symbol(s, "__BOUNDS_CHECKING_ON", NULL);
    }
#fim_se
    se (s->do_debug) {
        /* add debug sections */
        ctecelf_stab_new(s);
    }

    ctec_add_library_path(s, CONFIG_CTEC_LIBPATHS);

#se_definido CTEC_TARGET_PE
# se_definido _WIN32
    se (!s->nostdlib && output_type != CTEC_OUTPUT_OBJ)
        ctec_add_systemdir(s);
# fim_se
#senão
    /* paths para crt objects */
    ctec_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_CTEC_CRTPREFIX);
    /* add libc crt1/crti objects */
    se ((output_type == CTEC_OUTPUT_EXE || output_type == CTEC_OUTPUT_DLL) &&
        !s->nostdlib) {
        se (output_type != CTEC_OUTPUT_DLL)
            ctec_add_crt(s, "crt1.o");
        ctec_add_crt(s, "crti.o");
    }
#fim_se
    retorne 0;
}

LIBCTECAPI inteiro ctec_add_include_path(CTECState *s, constante caractere *pathname)
{
    ctec_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    retorne 0;
}

LIBCTECAPI inteiro ctec_add_sysinclude_path(CTECState *s, constante caractere *pathname)
{
    ctec_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    retorne 0;
}

ST_FUNC inteiro ctec_add_file_internal(CTECState *s1, constante caractere *filename, inteiro flags)
{
    inteiro ret;

    /* open the file */
    ret = ctec_open(s1, filename);
    se (ret < 0) {
        se (flags & AFF_PRINT_ERROR)
            ctec_error_noabort("file '%s' not found", filename);
        retorne ret;
    }

    /* update target deps */
    dynarray_add(&s1->target_deps, &s1->nb_target_deps,
            ctec_strdup(filename));

    se (flags & AFF_TYPE_BIN) {
        ElfW(Ehdr) ehdr;
        inteiro fd, obj_type;

        fd = file->fd;
        obj_type = ctec_object_type(fd, &ehdr);
        lseek(fd, 0, SEEK_SET);

#se_definido CTEC_TARGET_MACHO
        se (0 == obj_type && 0 == strcmp(ctec_fileextension(filename), ".dylib"))
            obj_type = AFF_BINTYPE_DYN;
#fim_se

        troque (obj_type) {
        caso AFF_BINTYPE_REL:
            ret = ctec_load_object_file(s1, fd, 0);
            pare;
#se_não_definido CTEC_TARGET_PE
        caso AFF_BINTYPE_DYN:
            se (s1->output_type == CTEC_OUTPUT_MEMORY) {
                ret = 0;
#se_definido CTEC_IS_NATIVE
                se (NULL == dlopen(filename, RTLD_GLOBAL | RTLD_LAZY))
                    ret = -1;
#fim_se
            } senão {
                ret = ctec_load_dll(s1, fd, filename,
                                   (flags & AFF_REFERENCED_DLL) != 0);
            }
            pare;
#fim_se
        caso AFF_BINTYPE_AR:
            ret = ctec_load_archive(s1, fd);
            pare;
#se_definido CTEC_TARGET_COFF
        caso AFF_BINTYPE_C67:
            ret = ctec_load_coff(s1, fd);
            pare;
#fim_se
        padrão:
#se_definido CTEC_TARGET_PE
            ret = pe_load_file(s1, filename, fd);
#senão
            /* as GNU ld, consider it is an ld script se not recognized */
            ret = ctec_load_ldscript(s1);
#fim_se
            se (ret < 0)
                ctec_error_noabort("unrecognized file type");
            pare;
        }
    } senão {
        ret = ctec_compile(s1);
    }
    ctec_close();
    retorne ret;
}

LIBCTECAPI inteiro ctec_add_file(CTECState *s, constante caractere *filename)
{
    inteiro filetype = s->filetype;
    inteiro flags = AFF_PRINT_ERROR;
    se (filetype == 0) {
        /* use a file extension to detect a filetype */
        constante caractere *ext = ctec_fileextension(filename);
        se (ext[0]) {
            ext++;
            se (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            senão se (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            senão se (!PATHCMP(ext, "c") || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            senão
                flags |= AFF_TYPE_BIN;
        } senão {
            filetype = AFF_TYPE_C;
        }
        s->filetype = filetype;
    }
    retorne ctec_add_file_internal(s, filename, flags);
}

LIBCTECAPI inteiro ctec_add_library_path(CTECState *s, constante caractere *pathname)
{
    ctec_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    retorne 0;
}

estático inteiro ctec_add_library_internal(CTECState *s, constante caractere *fmt,
    constante caractere *filename, inteiro flags, caractere **paths, inteiro nb_paths)
{
    caractere buf[1024];
    inteiro i;

    para(i = 0; i < nb_paths; i++) {
        snprintf(buf, sizeof(buf), fmt, paths[i], filename);
        se (ctec_add_file_internal(s, buf, flags | AFF_TYPE_BIN) == 0)
            retorne 0;
    }
    retorne -1;
}

/* find and load a dll. Return non zero se not found */
/* XXX: add '-rpath' option support ? */
ST_FUNC inteiro ctec_add_dll(CTECState *s, constante caractere *filename, inteiro flags)
{
    retorne ctec_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

ST_FUNC inteiro ctec_add_crt(CTECState *s, constante caractere *filename)
{
    se (-1 == ctec_add_library_internal(s, "%s/%s",
        filename, 0, s->crt_paths, s->nb_crt_paths))
        ctec_error_noabort("file '%s' not found", filename);
    retorne 0;
}

/* the library name is the same as the argument of the '-l' option */
LIBCTECAPI inteiro ctec_add_library(CTECState *s, constante caractere *libraryname)
{
#se definido CTEC_TARGET_PE
    constante caractere *libs[] = { "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll", "%s/lib%s.a", NULL };
    constante caractere **pp = s->static_link ? libs + 4 : libs;
#senão_se definido CTEC_TARGET_MACHO
    constante caractere *libs[] = { "%s/lib%s.dylib", "%s/lib%s.a", NULL };
    constante caractere **pp = s->static_link ? libs + 1 : libs;
#senão
    constante caractere *libs[] = { "%s/lib%s.so", "%s/lib%s.a", NULL };
    constante caractere **pp = s->static_link ? libs + 1 : libs;
#fim_se
    enquanto (*pp) {
        se (0 == ctec_add_library_internal(s, *pp,
            libraryname, 0, s->library_paths, s->nb_library_paths))
            retorne 0;
        ++pp;
    }
    retorne -1;
}

PUB_FUNC inteiro ctec_add_library_err(CTECState *s, constante caractere *libname)
{
    inteiro ret = ctec_add_library(s, libname);
    se (ret < 0)
        ctec_error_noabort("library '%s' not found", libname);
    retorne ret;
}

/* handle #diretiva comment(lib,) */
ST_FUNC vazio ctec_add_pragma_libs(CTECState *s1)
{
    inteiro i;
    para (i = 0; i < s1->nb_pragma_libs; i++)
        ctec_add_library_err(s1, s1->pragma_libs[i]);
}

LIBCTECAPI inteiro ctec_add_symbol(CTECState *s, constante caractere *name, constante vazio *val)
{
#se_definido CTEC_TARGET_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as se it were in a DLL. */
    pe_putimport(s, 0, name, (uintptr_t)val);
#senão
    set_elf_sym(symtab_section, (uintptr_t)val, 0,
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0,
        SHN_ABS, name);
#fim_se
    retorne 0;
}

LIBCTECAPI vazio ctec_set_lib_path(CTECState *s, constante caractere *path)
{
    ctec_free(s->ctec_lib_path);
    s->ctec_lib_path = ctec_strdup(path);
}

#defina WD_ALL    0x0001 /* aviso is activated when using -Wall */
#defina FD_INVERT 0x0002 /* invert value before storing */

defina_tipo estrutura FlagDef {
    uint16_t offset;
    uint16_t flags;
    constante caractere *name;
} FlagDef;

estático inteiro no_flag(constante caractere **pp)
{
    constante caractere *p = *pp;
    se (*p != 'n' || *++p != 'o' || *++p != '-')
        retorne 0;
    *pp = p + 1;
    retorne 1;
}

ST_FUNC inteiro set_flag(CTECState *s, constante FlagDef *flags, constante caractere *name)
{
    inteiro value, ret;
    constante FlagDef *p;
    constante caractere *r;

    value = 1;
    r = name;
    se (no_flag(&r))
        value = 0;

    para (ret = -1, p = flags; p->name; ++p) {
        se (ret) {
            se (strcmp(r, p->name))
                continue;
        } senão {
            se (0 == (p->flags & WD_ALL))
                continue;
        }
        se (p->offset) {
            *(inteiro*)((caractere *)s + p->offset) =
                p->flags & FD_INVERT ? !value : value;
            se (ret)
                retorne 0;
        } senão {
            ret = 0;
        }
    }
    retorne ret;
}

estático inteiro strstart(constante caractere *val, constante caractere **str)
{
    constante caractere *p, *q;
    p = *str;
    q = val;
    enquanto (*q) {
        se (*p != *q)
            retorne 0;
        p++;
        q++;
    }
    *str = p;
    retorne 1;
}

/* Like strstart, but automatically takes into account that ld options can
 *
 * - start with duplo or single dash (e.g. '--soname' or '-soname')
 * - arguments can be given as separate or after '=' (e.g. '-Wl,-soname,x.so'
 *   or '-Wl,-soname=x.so')
 *
 * you provide `val` always in 'option[=]' form (no leading -)
 */
estático inteiro link_option(constante caractere *str, constante caractere *val, constante caractere **ptr)
{
    constante caractere *p, *q;
    inteiro ret;

    /* there should be 1 or 2 dashes */
    se (*str++ != '-')
        retorne 0;
    se (*str == '-')
        str++;

    /* then str & val should match (potentially up to '=') */
    p = str;
    q = val;

    ret = 1;
    se (q[0] == '?') {
        ++q;
        se (no_flag(&p))
            ret = -1;
    }

    enquanto (*q != '\0' && *q != '=') {
        se (*p != *q)
            retorne 0;
        p++;
        q++;
    }

    /* '=' near eos means ',' or '=' is ok */
    se (*q == '=') {
        se (*p == 0)
            *ptr = p;
        se (*p != ',' && *p != '=')
            retorne 0;
        p++;
    } senão se (*p) {
        retorne 0;
    }
    *ptr = p;
    retorne ret;
}

estático constante caractere *skip_linker_arg(constante caractere **str)
{
    constante caractere *s1 = *str;
    constante caractere *s2 = strchr(s1, ',');
    *str = s2 ? s2++ : (s2 = s1 + strlen(s1));
    retorne s2;
}

estático vazio copy_linker_arg(caractere **pp, constante caractere *s, inteiro sep)
{
    constante caractere *q = s;
    caractere *p = *pp;
    inteiro l = 0;
    se (p && sep)
        p[l = strlen(p)] = sep, ++l;
    skip_linker_arg(&q);
    pstrncpy(l + (*pp = ctec_realloc(p, q - s + l + 1)), s, q - s);
}

/* set linker options */
estático inteiro ctec_set_linker(CTECState *s, constante caractere *option)
{
    enquanto (*option) {

        constante caractere *p = NULL;
        caractere *end = NULL;
        inteiro ignoring = 0;
        inteiro ret;

        se (link_option(option, "Bsymbolic", &p)) {
            s->symbolic = 1;
        } senão se (link_option(option, "nostdlib", &p)) {
            s->nostdlib = 1;
        } senão se (link_option(option, "fini=", &p)) {
            copy_linker_arg(&s->fini_symbol, p, 0);
            ignoring = 1;
        } senão se (link_option(option, "image-base=", &p)
                || link_option(option, "Ttext=", &p)) {
            s->text_addr = strtoull(p, &end, 16);
            s->has_text_addr = 1;
        } senão se (link_option(option, "init=", &p)) {
            copy_linker_arg(&s->init_symbol, p, 0);
            ignoring = 1;
        } senão se (link_option(option, "oformat=", &p)) {
#se definido(CTEC_TARGET_PE)
            se (strstart("pe-", &p)) {
#senão_se PTR_SIZE == 8
            se (strstart("elf64-", &p)) {
#senão
            se (strstart("elf32-", &p)) {
#fim_se
                s->output_format = CTEC_OUTPUT_FORMAT_ELF;
            } senão se (!strcmp(p, "binary")) {
                s->output_format = CTEC_OUTPUT_FORMAT_BINARY;
#se_definido CTEC_TARGET_COFF
            } senão se (!strcmp(p, "coff")) {
                s->output_format = CTEC_OUTPUT_FORMAT_COFF;
#fim_se
            } senão
                ir_para err;

        } senão se (link_option(option, "as-needed", &p)) {
            ignoring = 1;
        } senão se (link_option(option, "O", &p)) {
            ignoring = 1;
        } senão se (link_option(option, "export-all-symbols", &p)) {
            s->rdynamic = 1;
        } senão se (link_option(option, "rpath=", &p)) {
            copy_linker_arg(&s->rpath, p, ':');
        } senão se (link_option(option, "enable-new-dtags", &p)) {
            s->enable_new_dtags = 1;
        } senão se (link_option(option, "section-alignment=", &p)) {
            s->section_align = strtoul(p, &end, 16);
        } senão se (link_option(option, "soname=", &p)) {
            copy_linker_arg(&s->soname, p, 0);
#se_definido CTEC_TARGET_PE
        } senão se (link_option(option, "large-address-aware", &p)) {
            s->pe_characteristics |= 0x20;
        } senão se (link_option(option, "file-alignment=", &p)) {
            s->pe_file_align = strtoul(p, &end, 16);
        } senão se (link_option(option, "stack=", &p)) {
            s->pe_stack_size = strtoul(p, &end, 10);
        } senão se (link_option(option, "subsystem=", &p)) {
#se definido(CTEC_TARGET_I386) || definido(CTEC_TARGET_X86_64)
            se (!strcmp(p, "native")) {
                s->pe_subsystem = 1;
            } senão se (!strcmp(p, "console")) {
                s->pe_subsystem = 3;
            } senão se (!strcmp(p, "gui") || !strcmp(p, "windows")) {
                s->pe_subsystem = 2;
            } senão se (!strcmp(p, "posix")) {
                s->pe_subsystem = 7;
            } senão se (!strcmp(p, "efiapp")) {
                s->pe_subsystem = 10;
            } senão se (!strcmp(p, "efiboot")) {
                s->pe_subsystem = 11;
            } senão se (!strcmp(p, "efiruntime")) {
                s->pe_subsystem = 12;
            } senão se (!strcmp(p, "efirom")) {
                s->pe_subsystem = 13;
#senão_se definido(CTEC_TARGET_ARM)
            se (!strcmp(p, "wince")) {
                s->pe_subsystem = 9;
#fim_se
            } senão
                ir_para err;
#fim_se
        } senão se (ret = link_option(option, "?whole-archive", &p), ret) {
            s->alacarte_link = ret < 0;
        } senão se (p) {
            retorne 0;
        } senão {
    err:
            ctec_error("unsupported linker option '%s'", option);
        }

        se (ignoring && s->warn_unsupported)
            ctec_warning("unsupported linker option '%s'", option);

        option = skip_linker_arg(&p);
    }
    retorne 1;
}

defina_tipo estrutura CTECOption {
    constante caractere *name;
    uint16_t index;
    uint16_t flags;
} CTECOption;

enumeração {
    CTEC_OPTION_HELP,
    CTEC_OPTION_HELP2,
    CTEC_OPTION_v,
    CTEC_OPTION_I,
    CTEC_OPTION_D,
    CTEC_OPTION_U,
    CTEC_OPTION_P,
    CTEC_OPTION_L,
    CTEC_OPTION_B,
    CTEC_OPTION_l,
    CTEC_OPTION_bench,
    CTEC_OPTION_bt,
    CTEC_OPTION_b,
    CTEC_OPTION_g,
    CTEC_OPTION_c,
    CTEC_OPTION_dumpversion,
    CTEC_OPTION_d,
    CTEC_OPTION_static,
    CTEC_OPTION_std,
    CTEC_OPTION_shared,
    CTEC_OPTION_soname,
    CTEC_OPTION_o,
    CTEC_OPTION_r,
    CTEC_OPTION_s,
    CTEC_OPTION_traditional,
    CTEC_OPTION_Wl,
    CTEC_OPTION_Wp,
    CTEC_OPTION_W,
    CTEC_OPTION_O,
    CTEC_OPTION_mfloat_abi,
    CTEC_OPTION_m,
    CTEC_OPTION_f,
    CTEC_OPTION_isystem,
    CTEC_OPTION_iwithprefix,
    CTEC_OPTION_include,
    CTEC_OPTION_nostdinc,
    CTEC_OPTION_nostdlib,
    CTEC_OPTION_print_search_dirs,
    CTEC_OPTION_rdynamic,
    CTEC_OPTION_param,
    CTEC_OPTION_pedantic,
    CTEC_OPTION_pthread,
    CTEC_OPTION_run,
    CTEC_OPTION_w,
    CTEC_OPTION_pipe,
    CTEC_OPTION_E,
    CTEC_OPTION_MD,
    CTEC_OPTION_MF,
    CTEC_OPTION_x,
    CTEC_OPTION_ar,
    CTEC_OPTION_impdef
};

#defina CTEC_OPTION_HAS_ARG 0x0001
#defina CTEC_OPTION_NOSEP   0x0002 /* cannot have space before option and arg */

estático constante CTECOption ctec_options[] = {
    { "h", CTEC_OPTION_HELP, 0 },
    { "-help", CTEC_OPTION_HELP, 0 },
    { "?", CTEC_OPTION_HELP, 0 },
    { "hh", CTEC_OPTION_HELP2, 0 },
    { "v", CTEC_OPTION_v, CTEC_OPTION_HAS_ARG | CTEC_OPTION_NOSEP },
    { "I", CTEC_OPTION_I, CTEC_OPTION_HAS_ARG },
    { "D", CTEC_OPTION_D, CTEC_OPTION_HAS_ARG },
    { "U", CTEC_OPTION_U, CTEC_OPTION_HAS_ARG },
    { "P", CTEC_OPTION_P, CTEC_OPTION_HAS_ARG | CTEC_OPTION_NOSEP },
    { "L", CTEC_OPTION_L, CTEC_OPTION_HAS_ARG },
    { "B", CTEC_OPTION_B, CTEC_OPTION_HAS_ARG },
    { "l", CTEC_OPTION_l, CTEC_OPTION_HAS_ARG | CTEC_OPTION_NOSEP },
    { "bench", CTEC_OPTION_bench, 0 },
#se_definido CONFIG_CTEC_BACKTRACE
    { "bt", CTEC_OPTION_bt, CTEC_OPTION_HAS_ARG },
#fim_se
#se_definido CONFIG_CTEC_BCHECK
    { "b", CTEC_OPTION_b, 0 },
#fim_se
    { "g", CTEC_OPTION_g, CTEC_OPTION_HAS_ARG | CTEC_OPTION_NOSEP },
    { "c", CTEC_OPTION_c, 0 },
    { "dumpversion", CTEC_OPTION_dumpversion, 0},
    { "d", CTEC_OPTION_d, CTEC_OPTION_HAS_ARG | CTEC_OPTION_NOSEP },
    { "estático", CTEC_OPTION_static, 0 },
    { "std", CTEC_OPTION_std, CTEC_OPTION_HAS_ARG | CTEC_OPTION_NOSEP },
    { "shared", CTEC_OPTION_shared, 0 },
    { "soname", CTEC_OPTION_soname, CTEC_OPTION_HAS_ARG },
    { "o", CTEC_OPTION_o, CTEC_OPTION_HAS_ARG },
    { "-param", CTEC_OPTION_param, CTEC_OPTION_HAS_ARG },
    { "pedantic", CTEC_OPTION_pedantic, 0},
    { "pthread", CTEC_OPTION_pthread, 0},
    { "run", CTEC_OPTION_run, CTEC_OPTION_HAS_ARG | CTEC_OPTION_NOSEP },
    { "rdynamic", CTEC_OPTION_rdynamic, 0 },
    { "r", CTEC_OPTION_r, 0 },
    { "s", CTEC_OPTION_s, 0 },
    { "traditional", CTEC_OPTION_traditional, 0 },
    { "Wl,", CTEC_OPTION_Wl, CTEC_OPTION_HAS_ARG | CTEC_OPTION_NOSEP },
    { "Wp,", CTEC_OPTION_Wp, CTEC_OPTION_HAS_ARG | CTEC_OPTION_NOSEP },
    { "W", CTEC_OPTION_W, CTEC_OPTION_HAS_ARG | CTEC_OPTION_NOSEP },
    { "O", CTEC_OPTION_O, CTEC_OPTION_HAS_ARG | CTEC_OPTION_NOSEP },
#se_definido CTEC_TARGET_ARM
    { "mfloat-abi", CTEC_OPTION_mfloat_abi, CTEC_OPTION_HAS_ARG },
#fim_se
    { "m", CTEC_OPTION_m, CTEC_OPTION_HAS_ARG | CTEC_OPTION_NOSEP },
    { "f", CTEC_OPTION_f, CTEC_OPTION_HAS_ARG | CTEC_OPTION_NOSEP },
    { "isystem", CTEC_OPTION_isystem, CTEC_OPTION_HAS_ARG },
    { "inclua", CTEC_OPTION_include, CTEC_OPTION_HAS_ARG },
    { "nostdinc", CTEC_OPTION_nostdinc, 0 },
    { "nostdlib", CTEC_OPTION_nostdlib, 0 },
    { "print-search-dirs", CTEC_OPTION_print_search_dirs, 0 },
    { "w", CTEC_OPTION_w, 0 },
    { "pipe", CTEC_OPTION_pipe, 0},
    { "E", CTEC_OPTION_E, 0},
    { "MD", CTEC_OPTION_MD, 0},
    { "MF", CTEC_OPTION_MF, CTEC_OPTION_HAS_ARG },
    { "x", CTEC_OPTION_x, CTEC_OPTION_HAS_ARG },
    { "ar", CTEC_OPTION_ar, 0},
#se_definido CTEC_TARGET_PE
    { "impdef", CTEC_OPTION_impdef, 0},
#fim_se
    { NULL, 0, 0 },
};

estático constante FlagDef options_W[] = {
    { 0, 0, "all" },
    { offsetof(CTECState, warn_unsupported), 0, "unsupported" },
    { offsetof(CTECState, warn_write_strings), 0, "write-strings" },
    { offsetof(CTECState, warn_error), 0, "erro" },
    { offsetof(CTECState, warn_gcc_compat), 0, "gcc-compat" },
    { offsetof(CTECState, warn_implicit_function_declaration), WD_ALL,
      "implicit-function-declaration" },
    { 0, 0, NULL }
};

estático constante FlagDef options_f[] = {
    { offsetof(CTECState, char_is_unsigned), 0, "sem_sinal-caractere" },
    { offsetof(CTECState, char_is_unsigned), FD_INVERT, "sinalizado-caractere" },
    { offsetof(CTECState, nocommon), FD_INVERT, "common" },
    { offsetof(CTECState, leading_underscore), 0, "leading-underscore" },
    { offsetof(CTECState, ms_extensions), 0, "ms-extensions" },
    { offsetof(CTECState, dollars_in_identifiers), 0, "dollars-in-identifiers" },
    { 0, 0, NULL }
};

estático constante FlagDef options_m[] = {
    { offsetof(CTECState, ms_bitfields), 0, "ms-bitfields" },
#se_definido CTEC_TARGET_X86_64
    { offsetof(CTECState, nosse), FD_INVERT, "sse" },
#fim_se
    { 0, 0, NULL }
};

estático vazio parse_option_D(CTECState *s1, constante caractere *optarg)
{
    caractere *sym = ctec_strdup(optarg);
    caractere *value = strchr(sym, '=');
    se (value)
        *value++ = '\0';
    ctec_define_symbol(s1, sym, value);
    ctec_free(sym);
}

estático vazio args_parser_add_file(CTECState *s, constante caractere* filename, inteiro filetype)
{
    estrutura filespec *f = ctec_malloc(sizeof *f + strlen(filename));
    f->type = filetype;
    f->alacarte = s->alacarte_link;
    strcpy(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
}

estático inteiro args_parser_make_argv(constante caractere *r, inteiro *argc, caractere ***argv)
{
    inteiro ret = 0, q, c;
    CString str;
    para(;;) {
        enquanto (c = (sem_sinal caractere)*r, c && c <= ' ')
	    ++r;
        se (c == 0)
            pare;
        q = 0;
        cstr_new(&str);
        enquanto (c = (sem_sinal caractere)*r, c) {
            ++r;
            se (c == '\\' && (*r == '"' || *r == '\\')) {
                c = *r++;
            } senão se (c == '"') {
                q = !q;
                continue;
            } senão se (q == 0 && c <= ' ') {
                pare;
            }
            cstr_ccat(&str, c);
        }
        cstr_ccat(&str, 0);
        //printf("<%s>\n", str.data), fflush(stdout);
        dynarray_add(argv, argc, ctec_strdup(str.data));
        cstr_free(&str);
        ++ret;
    }
    retorne ret;
}

/* read list file */
estático vazio args_parser_listfile(CTECState *s,
    constante caractere *filename, inteiro optind, inteiro *pargc, caractere ***pargv)
{
    inteiro fd, i;
    size_t len;
    caractere *p;
    inteiro argc = 0;
    caractere **argv = NULL;

    fd = open(filename, O_RDONLY | O_BINARY);
    se (fd < 0)
        ctec_error("listfile '%s' not found", filename);

    len = lseek(fd, 0, SEEK_END);
    p = ctec_malloc(len + 1), p[len] = 0;
    lseek(fd, 0, SEEK_SET), read(fd, p, len), close(fd);

    para (i = 0; i < *pargc; ++i)
        se (i == optind)
            args_parser_make_argv(p, &argc, &argv);
        senão
            dynarray_add(&argv, &argc, ctec_strdup((*pargv)[i]));

    ctec_free(p);
    dynarray_reset(&s->argv, &s->argc);
    *pargc = s->argc = argc, *pargv = s->argv = argv;
}

PUB_FUNC inteiro ctec_parse_args(CTECState *s, inteiro *pargc, caractere ***pargv, inteiro optind)
{
    constante CTECOption *popt;
    constante caractere *optarg, *r;
    constante caractere *run = NULL;
    inteiro last_o = -1;
    inteiro x;
    CString linker_arg; /* collect -Wl options */
    inteiro tool = 0, arg_start = 0, noaction = optind;
    caractere **argv = *pargv;
    inteiro argc = *pargc;

    cstr_new(&linker_arg);

    enquanto (optind < argc) {
        r = argv[optind];
        se (r[0] == '@' && r[1] != '\0') {
            args_parser_listfile(s, r + 1, optind, &argc, &argv);
	    continue;
        }
        optind++;
        se (tool) {
            se (r[0] == '-' && r[1] == 'v' && r[2] == 0)
                ++s->verbose;
            continue;
        }
reparse:
        se (r[0] != '-' || r[1] == '\0') {
            se (r[0] != '@') /* allow "ctec file(s) -run @ args ..." */
                args_parser_add_file(s, r, s->filetype);
            se (run) {
                ctec_set_options(s, run);
                arg_start = optind - 1;
                pare;
            }
            continue;
        }

        /* find option in table */
        para(popt = ctec_options; ; ++popt) {
            constante caractere *p1 = popt->name;
            constante caractere *r1 = r + 1;
            se (p1 == NULL)
                ctec_error("invalid option -- '%s'", r);
            se (!strstart(p1, &r1))
                continue;
            optarg = r1;
            se (popt->flags & CTEC_OPTION_HAS_ARG) {
                se (*r1 == '\0' && !(popt->flags & CTEC_OPTION_NOSEP)) {
                    se (optind >= argc)
                arg_err:
                        ctec_error("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } senão se (*r1 != '\0')
                continue;
            pare;
        }

        troque(popt->index) {
        caso CTEC_OPTION_HELP:
            retorne OPT_HELP;
        caso CTEC_OPTION_HELP2:
            retorne OPT_HELP2;
        caso CTEC_OPTION_I:
            ctec_add_include_path(s, optarg);
            pare;
        caso CTEC_OPTION_D:
            parse_option_D(s, optarg);
            pare;
        caso CTEC_OPTION_U:
            ctec_undefine_symbol(s, optarg);
            pare;
        caso CTEC_OPTION_L:
            ctec_add_library_path(s, optarg);
            pare;
        caso CTEC_OPTION_B:
            /* set ctec utilities path (mainly para ctec development) */
            ctec_set_lib_path(s, optarg);
            pare;
        caso CTEC_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB);
            s->nb_libraries++;
            pare;
        caso CTEC_OPTION_pthread:
            parse_option_D(s, "_REENTRANT");
            s->option_pthread = 1;
            pare;
        caso CTEC_OPTION_bench:
            s->do_bench = 1;
            pare;
#se_definido CONFIG_CTEC_BACKTRACE
        caso CTEC_OPTION_bt:
            ctec_set_num_callers(atoi(optarg));
            pare;
#fim_se
#se_definido CONFIG_CTEC_BCHECK
        caso CTEC_OPTION_b:
            s->do_bounds_check = 1;
            s->do_debug = 1;
            pare;
#fim_se
        caso CTEC_OPTION_g:
            s->do_debug = 1;
            pare;
        caso CTEC_OPTION_c:
            x = CTEC_OUTPUT_OBJ;
        set_output_type:
            se (s->output_type)
                ctec_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            pare;
        caso CTEC_OPTION_d:
            se (*optarg == 'D')
                s->dflag = 3;
            senão se (*optarg == 'M')
                s->dflag = 7;
            senão se (*optarg == 't')
                s->dflag = 16;
            senão se (isnum(*optarg))
                g_debug = atoi(optarg);
            senão
                ir_para unsupported_option;
            pare;
        caso CTEC_OPTION_static:
            s->static_link = 1;
            pare;
        caso CTEC_OPTION_std:
    	    /* silently ignore, a current purpose:
    	       allow to use a ctec as a reference compiler para "make test" */
            pare;
        caso CTEC_OPTION_shared:
            x = CTEC_OUTPUT_DLL;
            ir_para set_output_type;
        caso CTEC_OPTION_soname:
            s->soname = ctec_strdup(optarg);
            pare;
        caso CTEC_OPTION_o:
            se (s->outfile) {
                ctec_warning("multiple -o option");
                ctec_free(s->outfile);
            }
            s->outfile = ctec_strdup(optarg);
            pare;
        caso CTEC_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = CTEC_OUTPUT_OBJ;
            ir_para set_output_type;
        caso CTEC_OPTION_isystem:
            ctec_add_sysinclude_path(s, optarg);
            pare;
	caso CTEC_OPTION_include:
	    dynarray_add(&s->cmd_include_files,
			 &s->nb_cmd_include_files, ctec_strdup(optarg));
	    pare;
        caso CTEC_OPTION_nostdinc:
            s->nostdinc = 1;
            pare;
        caso CTEC_OPTION_nostdlib:
            s->nostdlib = 1;
            pare;
        caso CTEC_OPTION_run:
#se_não_definido CTEC_IS_NATIVE
            ctec_error("-run is not available in a cross compiler");
#fim_se
            run = optarg;
            x = CTEC_OUTPUT_MEMORY;
            ir_para set_output_type;
        caso CTEC_OPTION_v:
            faça ++s->verbose; enquanto (*optarg++ == 'v');
            ++noaction;
            pare;
        caso CTEC_OPTION_f:
            se (set_flag(s, options_f, optarg) < 0)
                ir_para unsupported_option;
            pare;
#se_definido CTEC_TARGET_ARM
        caso CTEC_OPTION_mfloat_abi:
            /* ctec doesn't support soft real yet */
            se (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
                ctec_undefine_symbol(s, "__ARM_PCS_VFP");
            } senão se (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            senão
                ctec_error("unsupported real abi '%s'", optarg);
            pare;
#fim_se
        caso CTEC_OPTION_m:
            se (set_flag(s, options_m, optarg) < 0) {
                se (x = atoi(optarg), x != 32 && x != 64)
                    ir_para unsupported_option;
                se (PTR_SIZE != x/8)
                    retorne x;
                ++noaction;
            }
            pare;
        caso CTEC_OPTION_W:
            se (set_flag(s, options_W, optarg) < 0)
                ir_para unsupported_option;
            pare;
        caso CTEC_OPTION_w:
            s->warn_none = 1;
            pare;
        caso CTEC_OPTION_rdynamic:
            s->rdynamic = 1;
            pare;
        caso CTEC_OPTION_Wl:
            se (linker_arg.size)
                --linker_arg.size, cstr_ccat(&linker_arg, ',');
            cstr_cat(&linker_arg, optarg, 0);
            se (ctec_set_linker(s, linker_arg.data))
                cstr_free(&linker_arg);
            pare;
	caso CTEC_OPTION_Wp:
	    r = optarg;
	    ir_para reparse;
        caso CTEC_OPTION_E:
            x = CTEC_OUTPUT_PREPROCESS;
            ir_para set_output_type;
        caso CTEC_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            pare;
        caso CTEC_OPTION_MD:
            s->gen_deps = 1;
            pare;
        caso CTEC_OPTION_MF:
            s->deps_outfile = ctec_strdup(optarg);
            pare;
        caso CTEC_OPTION_dumpversion:
            printf ("%s\n", CTEC_VERSION);
            exit(0);
            pare;
        caso CTEC_OPTION_x:
            se (*optarg == 'c')
                s->filetype = AFF_TYPE_C;
            senão se (*optarg == 'a')
                s->filetype = AFF_TYPE_ASMPP;
            senão se (*optarg == 'n')
                s->filetype = AFF_TYPE_NONE;
            senão
                ctec_warning("unsupported language '%s'", optarg);
            pare;
        caso CTEC_OPTION_O:
            last_o = atoi(optarg);
            pare;
        caso CTEC_OPTION_print_search_dirs:
            x = OPT_PRINT_DIRS;
            ir_para extra_action;
        caso CTEC_OPTION_impdef:
            x = OPT_IMPDEF;
            ir_para extra_action;
        caso CTEC_OPTION_ar:
            x = OPT_AR;
        extra_action:
            arg_start = optind - 1;
            se (arg_start != noaction)
                ctec_error("cannot parse %s here", r);
            tool = x;
            pare;
        caso CTEC_OPTION_traditional:
        caso CTEC_OPTION_pedantic:
        caso CTEC_OPTION_pipe:
        caso CTEC_OPTION_s:
            /* ignored */
            pare;
        padrão:
unsupported_option:
            se (s->warn_unsupported)
                ctec_warning("unsupported option '%s'", r);
            pare;
        }
    }
    se (last_o > 0)
        ctec_define_symbol(s, "__OPTIMIZE__", NULL);
    se (linker_arg.size) {
        r = linker_arg.data;
        ir_para arg_err;
    }
    *pargc = argc - arg_start;
    *pargv = argv + arg_start;
    se (tool)
        retorne tool;
    se (optind != noaction)
        retorne 0;
    se (s->verbose == 2)
        retorne OPT_PRINT_DIRS;
    se (s->verbose)
        retorne OPT_V;
    retorne OPT_HELP;
}

LIBCTECAPI vazio ctec_set_options(CTECState *s, constante caractere *r)
{
    caractere **argv = NULL;
    inteiro argc = 0;
    args_parser_make_argv(r, &argc, &argv);
    ctec_parse_args(s, &argc, &argv, 0);
    dynarray_reset(&argv, &argc);
}

PUB_FUNC vazio ctec_print_stats(CTECState *s, sem_sinal total_time)
{
    se (total_time < 1)
        total_time = 1;
    se (total_bytes < 1)
        total_bytes = 1;
    fprintf(stderr, "* %d idents, %d lines, %d bytes\n"
                    "* %0.3f s, %u lines/s, %0.1f MB/s\n",
           tok_ident - TOK_IDENT, total_lines, total_bytes,
           (duplo)total_time/1000,
           (sem_sinal)total_lines*1000/total_time,
           (duplo)total_bytes/1000/total_time);
#se_definido MEM_DEBUG
    fprintf(stderr, "* %d bytes memory used\n", mem_max_size);
#fim_se
}
