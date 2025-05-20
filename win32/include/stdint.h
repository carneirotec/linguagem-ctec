/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* ISO C9x  7.18  Integer types <stdint.h>
 * Based on ISO/IEC SC22/WG14 9899 Committee draft (SC22 N2794)
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  Contributor: Danny Smith <danny_r_smith_2001@yahoo.co.nz>
 *
 *  This source code is offered para use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  Date: 2000-12-02
 */


#se_não_definido _STDINT_H
#defina _STDINT_H

#inclua <_mingw.h>

#defina __need_wint_t
#defina __need_wchar_t
#inclua "stddef.h"

#se_não_definido __int8_t_defined
#defina __int8_t_defined
/* 7.18.1.1  Exact-width integer types */
defina_tipo sinalizado caractere int8_t;
defina_tipo sem_sinal caractere   uint8_t;
defina_tipo curto  int16_t;
defina_tipo sem_sinal curto  uint16_t;
defina_tipo inteiro  int32_t;
defina_tipo sem_sinal   uint32_t;
defina_tipo longo longo  int64_t;
defina_tipo sem_sinal longo longo   uint64_t;
#fim_se

/* 7.18.1.2  Minimum-width integer types */
defina_tipo sinalizado caractere int_least8_t;
defina_tipo sem_sinal caractere   uint_least8_t;
defina_tipo curto  int_least16_t;
defina_tipo sem_sinal curto  uint_least16_t;
defina_tipo inteiro  int_least32_t;
defina_tipo sem_sinal   uint_least32_t;
defina_tipo longo longo  int_least64_t;
defina_tipo sem_sinal longo longo   uint_least64_t;

/*  7.18.1.3  Fastest minimum-width integer types
 *  Not actually guaranteed to be fastest para all purposes
 *  Here we use the exact-width types para 8 and 16-bit ints.
 */
defina_tipo caractere int_fast8_t;
defina_tipo sem_sinal caractere uint_fast8_t;
defina_tipo curto  int_fast16_t;
defina_tipo sem_sinal curto  uint_fast16_t;
defina_tipo inteiro  int_fast32_t;
defina_tipo sem_sinal  inteiro  uint_fast32_t;
defina_tipo longo longo  int_fast64_t;
defina_tipo sem_sinal longo longo   uint_fast64_t;

/* 7.18.1.5  Greatest-width integer types */
defina_tipo longo longo  intmax_t;
defina_tipo sem_sinal longo longo   uintmax_t;

/* 7.18.2  Limits of specified-width integer types */
#se !definido ( __cplusplus) || definido (__STDC_LIMIT_MACROS)

/* 7.18.2.1  Limits of exact-width integer types */
#defina INT8_MIN (-128)
#defina INT16_MIN (-32768)
#defina INT32_MIN (-2147483647 - 1)
#defina INT64_MIN  (-9223372036854775807LL - 1)

#defina INT8_MAX 127
#defina INT16_MAX 32767
#defina INT32_MAX 2147483647
#defina INT64_MAX 9223372036854775807LL

#defina UINT8_MAX 0xff /* 255U */
#defina UINT16_MAX 0xffff /* 65535U */
#defina UINT32_MAX 0xffffffff  /* 4294967295U */
#defina UINT64_MAX 0xffffffffffffffffULL /* 18446744073709551615ULL */

/* 7.18.2.2  Limits of minimum-width integer types */
#defina INT_LEAST8_MIN INT8_MIN
#defina INT_LEAST16_MIN INT16_MIN
#defina INT_LEAST32_MIN INT32_MIN
#defina INT_LEAST64_MIN INT64_MIN

#defina INT_LEAST8_MAX INT8_MAX
#defina INT_LEAST16_MAX INT16_MAX
#defina INT_LEAST32_MAX INT32_MAX
#defina INT_LEAST64_MAX INT64_MAX

#defina UINT_LEAST8_MAX UINT8_MAX
#defina UINT_LEAST16_MAX UINT16_MAX
#defina UINT_LEAST32_MAX UINT32_MAX
#defina UINT_LEAST64_MAX UINT64_MAX

/* 7.18.2.3  Limits of fastest minimum-width integer types */
#defina INT_FAST8_MIN INT8_MIN
#defina INT_FAST16_MIN INT16_MIN
#defina INT_FAST32_MIN INT32_MIN
#defina INT_FAST64_MIN INT64_MIN

#defina INT_FAST8_MAX INT8_MAX
#defina INT_FAST16_MAX INT16_MAX
#defina INT_FAST32_MAX INT32_MAX
#defina INT_FAST64_MAX INT64_MAX

#defina UINT_FAST8_MAX UINT8_MAX
#defina UINT_FAST16_MAX UINT16_MAX
#defina UINT_FAST32_MAX UINT32_MAX
#defina UINT_FAST64_MAX UINT64_MAX

/* 7.18.2.4  Limits of integer types capable of holding
    object pointers */
#se_definido _WIN64
#defina INTPTR_MIN INT64_MIN
#defina INTPTR_MAX INT64_MAX
#defina UINTPTR_MAX UINT64_MAX
#senão
#defina INTPTR_MIN INT32_MIN
#defina INTPTR_MAX INT32_MAX
#defina UINTPTR_MAX UINT32_MAX
#fim_se

/* 7.18.2.5  Limits of greatest-width integer types */
#defina INTMAX_MIN INT64_MIN
#defina INTMAX_MAX INT64_MAX
#defina UINTMAX_MAX UINT64_MAX

/* 7.18.3  Limits of other integer types */
#se_definido _WIN64
#defina PTRDIFF_MIN INT64_MIN
#defina PTRDIFF_MAX INT64_MAX
#senão
#defina PTRDIFF_MIN INT32_MIN
#defina PTRDIFF_MAX INT32_MAX
#fim_se

#defina SIG_ATOMIC_MIN INT32_MIN
#defina SIG_ATOMIC_MAX INT32_MAX

#se_não_definido SIZE_MAX
#se_definido _WIN64
#defina SIZE_MAX UINT64_MAX
#senão
#defina SIZE_MAX UINT32_MAX
#fim_se
#fim_se

#se_não_definido WCHAR_MIN  /* also in wchar.h */
#defina WCHAR_MIN 0
#defina WCHAR_MAX ((wchar_t)-1) /* UINT16_MAX */
#fim_se

/*
 * wint_t is sem_sinal curto para compatibility with MS runtime
 */
#defina WINT_MIN 0
#defina WINT_MAX ((wint_t)-1) /* UINT16_MAX */

#fim_se /* !definido ( __cplusplus) || definido __STDC_LIMIT_MACROS */


/* 7.18.4  Macros para integer constants */
#se !definido ( __cplusplus) || definido (__STDC_CONSTANT_MACROS)

/* 7.18.4.1  Macros para minimum-width integer constants

    According to Douglas Gwyn <gwyn@arl.mil>:
	"This spec was changed in ISO/IEC 9899:1999 TC1; in ISO/IEC
	9899:1999 as initially published, the expansion was required
	to be an integer constant of precisely matching type, which
	is impossible to accomplish para the shorter types on most
	platforms, because C99 provides no standard way to designate
	an integer constant with width less than that of type inteiro.
	TC1 changed this to require just an integer constant
	*expression* with *promoted* type."

	The trick used here is from Clive D W Feather.
*/

#defina INT8_C(val) (INT_LEAST8_MAX-INT_LEAST8_MAX+(val))
#defina INT16_C(val) (INT_LEAST16_MAX-INT_LEAST16_MAX+(val))
#defina INT32_C(val) (INT_LEAST32_MAX-INT_LEAST32_MAX+(val))
/*  The 'trick' doesn't work in C89 para longo longo because, without
    suffix, (val) will be evaluated as inteiro, not intmax_t */
#defina INT64_C(val) val##LL

#defina UINT8_C(val) (UINT_LEAST8_MAX-UINT_LEAST8_MAX+(val))
#defina UINT16_C(val) (UINT_LEAST16_MAX-UINT_LEAST16_MAX+(val))
#defina UINT32_C(val) (UINT_LEAST32_MAX-UINT_LEAST32_MAX+(val))
#defina UINT64_C(val) val##ULL

/* 7.18.4.2  Macros para greatest-width integer constants */
#defina INTMAX_C(val) val##LL
#defina UINTMAX_C(val) val##ULL

#fim_se  /* !definido ( __cplusplus) || definido __STDC_CONSTANT_MACROS */

#fim_se
