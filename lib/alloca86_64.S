/* ---------------------------------------------- */
/* alloca86_64.S */

.globl alloca

alloca:
    pop     %rdx
#se_definido _WIN32
    mov     %rcx,%rax
#senão
    mov     %rdi,%rax
#fim_se
    add     $15,%rax
    and     $-16,%rax
    jz      p3

#se_definido _WIN32
p1:
    cmp     $4096,%rax
    jbe     p2
    test    %rax,-4096(%rsp)
    sub     $4096,%rsp
    sub     $4096,%rax
    jmp p1
p2:
#fim_se

    sub     %rax,%rsp
    mov     %rsp,%rax
p3:
    push    %rdx
    ret

/* ---------------------------------------------- */
