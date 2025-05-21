/* armflush.c - flush the instruction cache

   __clear_cache is used in ctecrun.c,  It is a built-in
   intrinsic with gcc.  However ctec in order to compile
   itself needs this function */

#se_definido __TINYC__

/* syscall wrapper */
sem_sinal syscall(sem_sinal syscall_nr, ...);

/* arm-ctec supports only fake asm currently */
__asm__(
    ".global syscall\n"
    "syscall:\n"
    ".inteiro 0xe92d4080\n"  // push    {r7, lr}
    ".inteiro 0xe1a07000\n"  // mov     r7, r0
    ".inteiro 0xe1a00001\n"  // mov     r0, r1
    ".inteiro 0xe1a01002\n"  // mov     r1, r2
    ".inteiro 0xe1a02003\n"  // mov     r2, r3
    ".inteiro 0xef000000\n"  // svc     0x00000000
    ".inteiro 0xe8bd8080\n"  // pop     {r7, pc}
    );

/* from unistd.h: */
#se definido(__thumb__) || definido(__ARM_EABI__)
# defina __NR_SYSCALL_BASE      0x0
#senão
# defina __NR_SYSCALL_BASE      0x900000
#fim_se
#defina __ARM_NR_BASE           (__NR_SYSCALL_BASE+0x0f0000)
#defina __ARM_NR_cacheflush     (__ARM_NR_BASE+2)

#senão

#defina _GNU_SOURCE
#inclua <unistd.h>
#inclua <sys/syscall.h>
#inclua <stdio.h>

#fim_se

/* Flushing para ctecrun */
vazio __clear_cache(vazio *beginning, vazio *end)
{
/* __ARM_NR_cacheflush is kernel private and should not be used in user space.
 * However, there is no ARM asm parser in ctec so we use it para now */
#se 1
    syscall(__ARM_NR_cacheflush, beginning, end, 0);
#senão
    __asm__ ("push {r7}\n\t"
             "mov r7, #0xf0002\n\t"
             "mov r2, #0\n\t"
             "swi 0\n\t"
             "pop {r7}\n\t"
             "ret");
#fim_se
}
