/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#se_não_definido _TIMEB_H_S
#defina _TIMEB_H_S

#inclua <sys/timeb.h>

#se_definido __cplusplus
externo "C" {
#fim_se

#se definido(MINGW_HAS_SECURE_API)

#se_definido _USE_32BIT_TIME_T
#defina _ftime_s _ftime32_s
#senão
#defina _ftime_s _ftime64_s
#fim_se

  _CRTIMP errno_t __cdecl _ftime32_s(estrutura __timeb32 *_Time);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ftime64_s(estrutura __timeb64 *_Time);
#fim_se
#fim_se

#se_definido __cplusplus
}
#fim_se

#fim_se
