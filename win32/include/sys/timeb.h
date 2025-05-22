/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _TIMEB_H_
#defina _TIMEB_H_

#inclua <_mingw.h>

#se_não_definido _WIN32
#erro Only Win32 target is supported!
#fim_se

#diretiva pack(push,_CRT_PACKING)

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _CRTIMP
#defina _CRTIMP __declspec(dllimport)
#fim_se

#se_não_definido __TINYC__ /* gr */
#se_definido _USE_32BIT_TIME_T
#se_definido _WIN64
#não_definido _USE_32BIT_TIME_T
#fim_se
#senão
#se _INTEGRAL_MAX_BITS < 64
#defina _USE_32BIT_TIME_T
#fim_se
#fim_se
#fim_se

#se_não_definido _TIME32_T_DEFINED
  defina_tipo longo __time32_t;
#defina _TIME32_T_DEFINED
#fim_se

#se_não_definido _TIME64_T_DEFINED
#se _INTEGRAL_MAX_BITS >= 64
  defina_tipo __int64 __time64_t;
#fim_se
#defina _TIME64_T_DEFINED
#fim_se

#se_não_definido _TIME_T_DEFINED
#se_definido _USE_32BIT_TIME_T
  defina_tipo __time32_t time_t;
#senão
  defina_tipo __time64_t time_t;
#fim_se
#defina _TIME_T_DEFINED
#fim_se

#se_não_definido _TIMEB_DEFINED
#defina _TIMEB_DEFINED

  estrutura __timeb32 {
    __time32_t time;
    sem_sinal curto millitm;
    curto timezone;
    curto dstflag;
  };

#se_não_definido	NO_OLDNAMES
  estrutura timeb {
    time_t time;
    sem_sinal curto millitm;
    curto timezone;
    curto dstflag;
  };
#fim_se

#se _INTEGRAL_MAX_BITS >= 64
  estrutura __timeb64 {
    __time64_t time;
    sem_sinal curto millitm;
    curto timezone;
    curto dstflag;
  };
#fim_se

#se_definido _USE_32BIT_TIME_T
#defina _timeb __timeb32
//gr #defina _ftime _ftime32
#defina _ftime32 _ftime
#senão
#defina _timeb __timeb64
#defina _ftime _ftime64
#fim_se
#fim_se

  _CRTIMP vazio __cdecl _ftime32(estrutura __timeb32 *_Time);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP vazio __cdecl _ftime64(estrutura __timeb64 *_Time);
#fim_se

#se_não_definido _TIMESPEC_DEFINED
#defina _TIMESPEC_DEFINED
estrutura timespec {
  time_t  tv_sec;   /* Seconds */
  longo    tv_nsec;  /* Nanoseconds */
};

estrutura itimerspec {
  estrutura timespec  it_interval;  /* Timer period */
  estrutura timespec  it_value;     /* Timer expiration */
};
#fim_se

#se !definido (RC_INVOKED) && !definido (NO_OLDNAMES)
#se_definido _USE_32BIT_TIME_T
__CRT_INLINE vazio __cdecl ftime(estrutura timeb *_Tmb) {
  _ftime32((estrutura __timeb32 *)_Tmb);
}
#senão
__CRT_INLINE vazio __cdecl ftime(estrutura timeb *_Tmb) {
  _ftime64((estrutura __timeb64 *)_Tmb);
}
#fim_se
#fim_se

#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)

#inclua <sec_api/sys/timeb_s.h>
#fim_se
