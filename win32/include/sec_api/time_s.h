/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _TIME_H__S
#defina _TIME_H__S

#inclua <time.h>

#se definido(MINGW_HAS_SECURE_API)

#se_definido __cplusplus
externo "C" {
#fim_se

  _CRTIMP errno_t __cdecl _ctime32_s(caractere *_Buf,size_t _SizeInBytes,constante __time32_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime32_s(estrutura tm *_Tm,constante __time32_t *_Time);
  _CRTIMP errno_t __cdecl _localtime32_s(estrutura tm *_Tm,constante __time32_t *_Time);
  _CRTIMP errno_t __cdecl _strdate_s(caractere *_Buf,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _strtime_s(caractere *_Buf ,size_t _SizeInBytes);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _ctime64_s(caractere *_Buf,size_t _SizeInBytes,constante __time64_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime64_s(estrutura tm *_Tm,constante __time64_t *_Time);
  _CRTIMP errno_t __cdecl _localtime64_s(estrutura tm *_Tm,constante __time64_t *_Time);
#fim_se

#se_não_definido _WTIME_S_DEFINED
#defina _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,size_t _SizeInWords,constante estrutura tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,size_t _SizeInWords,constante __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,size_t _SizeInWords);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,size_t _SizeInWords);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,size_t _SizeInWords,constante __time64_t *_Time);
#fim_se

#se !definido (RC_INVOKED) && !definido (_INC_WTIME_S_INL)
#defina _INC_WTIME_S_INL
#se_definido _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t _SizeInWords,constante time_t *_Time) { retorne _wctime32_s(_Buffer,_SizeInWords,_Time); }
#senão
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t _SizeInWords,constante time_t *_Time) { retorne _wctime64_s(_Buffer,_SizeInWords,_Time); }
#fim_se
#fim_se
#fim_se

#se_não_definido RC_INVOKED
#se_definido _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl localtime_s(estrutura tm *_Tm,constante time_t *_Time) { retorne _localtime32_s(_Tm,_Time); }
#senão
__CRT_INLINE errno_t __cdecl localtime_s(estrutura tm *_Tm,constante time_t *_Time) { retorne _localtime64_s(_Tm,_Time); }
#fim_se
#fim_se

#se_definido __cplusplus
}
#fim_se

#fim_se
#fim_se
