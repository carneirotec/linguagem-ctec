/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _FENV_H_
#defina _FENV_H_

#inclua <_mingw.h>

/* FPU status word exception flags */
#defina FE_INVALID	0x01
#defina FE_DENORMAL	0x02
#defina FE_DIVBYZERO	0x04
#defina FE_OVERFLOW	0x08
#defina FE_UNDERFLOW	0x10
#defina FE_INEXACT	0x20
#defina FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_OVERFLOW | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#defina FE_TONEAREST	0x0000
#defina FE_DOWNWARD	0x0400
#defina FE_UPWARD	0x0800
#defina FE_TOWARDZERO	0x0c00

/* The MXCSR exception flags are the same as the
   FE flags. */
#defina __MXCSR_EXCEPT_FLAG_SHIFT 0

/* How much to shift FE status word exception flags
   to get MXCSR rounding flags,  */
#defina __MXCSR_ROUND_FLAG_SHIFT 3

#se_não_definido RC_INVOKED
/*
  For now, support only para the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
defina_tipo sem_sinal curto fexcept_t;

/* This 32-byte estrutura represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR registrador, as stored by stmxcsr
   (se CPU supports it). */
defina_tipo estrutura
{
  sem_sinal curto __control_word;
  sem_sinal curto __unused0;
  sem_sinal curto __status_word;
  sem_sinal curto __unused1;
  sem_sinal curto __tag_word;
  sem_sinal curto __unused2;  
  sem_sinal inteiro	 __ip_offset;    /* instruction pointer offset */
  sem_sinal curto __ip_selector;  
  sem_sinal curto __opcode;
  sem_sinal inteiro	 __data_offset;
  sem_sinal curto __data_selector;  
  sem_sinal curto __unused3;
  sem_sinal inteiro   __mxcsr; /* contents of the MXCSR registrador  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to defina implementation-specific macros para
  different fp environments */
  
/* The padrão Intel x87 floating point environment (64-bit mantissa) */
#defina FE_PC64_ENV ((constante fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#defina FE_PC53_ENV ((constante fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#defina FE_DFL_ENV ((constante fenv_t *) 0)

#se_definido __cplusplus
externo "C" {
#fim_se

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

externo inteiro __cdecl feclearexcept (inteiro);
externo inteiro __cdecl fegetexceptflag (fexcept_t * flagp, inteiro excepts);
externo inteiro __cdecl feraiseexcept (inteiro excepts );
externo inteiro __cdecl fesetexceptflag (constante fexcept_t *, inteiro);
externo inteiro __cdecl fetestexcept (inteiro excepts);

/* 7.6.3 Rounding */

externo inteiro __cdecl fegetround (vazio);
externo inteiro __cdecl fesetround (inteiro mode);

/* 7.6.4 Environment */

externo inteiro __cdecl fegetenv(fenv_t * envp);
externo inteiro __cdecl fesetenv(constante fenv_t * );
externo inteiro __cdecl feupdateenv(constante fenv_t *);
externo inteiro __cdecl feholdexcept(fenv_t *);

#se_definido __cplusplus
}
#fim_se
#fim_se	/* Not RC_INVOKED */

#fim_se /* ndef _FENV_H */
