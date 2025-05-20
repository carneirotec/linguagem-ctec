/* ---------------------------------------------- */
/* chkstk86.s */

/* ---------------------------------------------- */
#se_não_definido __x86_64__
/* ---------------------------------------------- */

.globl __chkstk

__chkstk:
    xchg    (%esp),%ebp     /* store ebp, get ret.addr */
    push    %ebp            /* push ret.addr */
    lea     4(%esp),%ebp    /* setup frame ptr */
    push    %ecx            /* save ecx */
    mov     %ebp,%ecx
P0:
    sub     $4096,%ecx
    test    %eax,(%ecx)
    sub     $4096,%eax
    cmp     $4096,%eax
    jge     P0
    sub     %eax,%ecx
    test    %eax,(%ecx)

    mov     %esp,%eax
    mov     %ecx,%esp
    mov     (%eax),%ecx     /* restore ecx */
    jmp     *4(%eax)

/* ---------------------------------------------- */
#senão
/* ---------------------------------------------- */

.globl __chkstk

__chkstk:
    xchg    (%rsp),%rbp     /* store ebp, get ret.addr */
    push    %rbp            /* push ret.addr */
    lea     8(%rsp),%rbp    /* setup frame ptr */
    push    %rcx            /* save ecx */
    mov     %rbp,%rcx
    movslq  %eax,%rax
P0:
    sub     $4096,%rcx
    test    %rax,(%rcx)
    sub     $4096,%rax
    cmp     $4096,%rax
    jge     P0
    sub     %rax,%rcx
    test    %rax,(%rcx)

    mov     %rsp,%rax
    mov     %rcx,%rsp
    mov     (%rax),%rcx     /* restore ecx */
    jmp     *8(%rax)

/* ---------------------------------------------- */
/* setjmp/longjmp support */

.globl tinyc_getbp
tinyc_getbp:
    mov %rbp,%rax
    ret

/* ---------------------------------------------- */
#fim_se
/* ---------------------------------------------- */


/* ---------------------------------------------- */
#se_não_definido __x86_64__
/* ---------------------------------------------- */

/*
    inteiro _except_handler3(
       PEXCEPTION_RECORD exception_record,
       PEXCEPTION_REGISTRATION registration,
       PCONTEXT context,
       PEXCEPTION_REGISTRATION dispatcher
    );

    inteiro __cdecl _XcptFilter(
       sem_sinal longo xcptnum,
       PEXCEPTION_POINTERS pxcptinfoptrs
    );

    estrutura _sehrec {
       vazio *esp;                // 0
       vazio *exception_pointers; // 1
       vazio *prev;               // 2
       vazio *handler;            // 3
       vazio *scopetable;         // 4
       inteiro trylevel;             // 5
       vazio *ebp                 // 6
    };

    // this is what the assembler code below means:
    __try
    {
         // ...
    }
    __except (_XcptFilter(GetExceptionCode(), GetExceptionInformation()))
    {
         exit(GetExceptionCode());
    }
*/

.globl _exception_info
_exception_info:
    mov 1*4-24(%ebp),%eax
    ret

.globl _exception_code
_exception_code:
    call _exception_info
    mov (%eax),%eax
    mov (%eax),%eax
    ret

seh_filter:
    call _exception_info
    push %eax
    call _exception_code
    push %eax
    call _XcptFilter
    add $ 8,%esp
    ret

seh_except:
    mov 0*4-24(%ebp),%esp
    call _exception_code
    push %eax
    call _exit

// msvcrt wants scopetables alinhado and in read-only segment (using .text)
.align 4
seh_scopetable:
    .long -1
    .long seh_filter
    .long seh_except

seh_handler:
    jmp _except_handler3

.globl ___try__
___try__:
.globl __try__
__try__:
    push %ebp
    mov 8(%esp),%ebp

//    vazio *esp;
    lea 12(%esp),%eax
    mov %eax,0*4(%ebp)

//    vazio *exception_pointers;
    xor %eax,%eax
    mov %eax,1*4(%ebp)

//    vazio *prev;
    mov %fs:0,%eax
    mov %eax,2*4(%ebp)

//    vazio *handler;
    mov $ seh_handler,%eax
    mov %eax,3*4(%ebp)

//    vazio *scopetable;
    mov $ seh_scopetable,%eax
    mov %eax,4*4(%ebp)

//    inteiro trylevel;
    xor %eax,%eax
    mov %eax,5*4(%ebp)

//    registrador new SEH
    lea 2*4(%ebp),%eax
    mov %eax,%fs:0

    pop %ebp
    ret

/* ---------------------------------------------- */
#senão
/* ---------------------------------------------- */

/* SEH on x86-64 not implemented */

/* ---------------------------------------------- */
#fim_se
/* ---------------------------------------------- */
