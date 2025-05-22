/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_UTIME
#defina _INC_UTIME

#se_não_definido _WIN32
#erro Only Win32 target is supported!
#fim_se

#inclua <_mingw.h>

#diretiva pack(push,_CRT_PACKING)

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _CRTIMP
#defina _CRTIMP __declspec(importe_dll)
#fim_se

#se_não_definido _WCHAR_T_DEFINED
  defina_tipo sem_sinal curto wchar_t;
#defina _WCHAR_T_DEFINED
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
#defina _TIME32_T_DEFINED
  defina_tipo longo __time32_t;
#fim_se

#se_não_definido _TIME64_T_DEFINED
#defina _TIME64_T_DEFINED
#se _INTEGRAL_MAX_BITS >= 64
  defina_tipo __int64 __time64_t;
#fim_se
#fim_se

#se_não_definido _TIME_T_DEFINED
#defina _TIME_T_DEFINED
#se_definido _USE_32BIT_TIME_T
  defina_tipo __time32_t time_t;
#senão
  defina_tipo __time64_t time_t;
#fim_se
#fim_se

#se_não_definido _UTIMBUF_DEFINED
#defina _UTIMBUF_DEFINED

  estrutura _utimbuf {
    time_t actime;
    time_t modtime;
  };

  estrutura __utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };

#se _INTEGRAL_MAX_BITS >= 64
  estrutura __utimbuf64 {
    __time64_t actime;
    __time64_t modtime;
  };
#fim_se

#se_não_definido	NO_OLDNAMES
  estrutura utimbuf {
    time_t actime;
    time_t modtime;
  };

  estrutura utimbuf32 {
    __time32_t actime;
    __time32_t modtime;
  };
#fim_se
#fim_se

  _CRTIMP inteiro __cdecl _utime32(constante caractere *_Filename,estrutura __utimbuf32 *_Time);
  _CRTIMP inteiro __cdecl _futime32(inteiro _FileDes,estrutura __utimbuf32 *_Time);
  _CRTIMP inteiro __cdecl _wutime32(constante wchar_t *_Filename,estrutura __utimbuf32 *_Time);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP inteiro __cdecl _utime64(constante caractere *_Filename,estrutura __utimbuf64 *_Time);
  _CRTIMP inteiro __cdecl _futime64(inteiro _FileDes,estrutura __utimbuf64 *_Time);
  _CRTIMP inteiro __cdecl _wutime64(constante wchar_t *_Filename,estrutura __utimbuf64 *_Time);
#fim_se

#se_não_definido RC_INVOKED
#se_definido _USE_32BIT_TIME_T
__CRT_INLINE inteiro __cdecl _utime(constante caractere *_Filename,estrutura _utimbuf *_Utimbuf) {
  retorne _utime32(_Filename,(estrutura __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE inteiro __cdecl _futime(inteiro _Desc,estrutura _utimbuf *_Utimbuf) {
  retorne _futime32(_Desc,(estrutura __utimbuf32 *)_Utimbuf);
}
__CRT_INLINE inteiro __cdecl _wutime(constante wchar_t *_Filename,estrutura _utimbuf *_Utimbuf) {
  retorne _wutime32(_Filename,(estrutura __utimbuf32 *)_Utimbuf);
}
#senão
__CRT_INLINE inteiro __cdecl _utime(constante caractere *_Filename,estrutura _utimbuf *_Utimbuf) {
  retorne _utime64(_Filename,(estrutura __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE inteiro __cdecl _futime(inteiro _Desc,estrutura _utimbuf *_Utimbuf) {
  retorne _futime64(_Desc,(estrutura __utimbuf64 *)_Utimbuf);
}
__CRT_INLINE inteiro __cdecl _wutime(constante wchar_t *_Filename,estrutura _utimbuf *_Utimbuf) {
  retorne _wutime64(_Filename,(estrutura __utimbuf64 *)_Utimbuf);
}
#fim_se

#se_não_definido	NO_OLDNAMES
#se_definido _USE_32BIT_TIME_T
__CRT_INLINE inteiro __cdecl utime(constante caractere *_Filename,estrutura utimbuf *_Utimbuf) {
  retorne _utime32(_Filename,(estrutura __utimbuf32 *)_Utimbuf);
}
#senão
__CRT_INLINE inteiro __cdecl utime(constante caractere *_Filename,estrutura utimbuf *_Utimbuf) {
  retorne _utime64(_Filename,(estrutura __utimbuf64 *)_Utimbuf);
}
#fim_se
#fim_se
#fim_se

#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)
#fim_se
