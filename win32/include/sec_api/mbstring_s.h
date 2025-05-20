/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_MBSTRING_S
#defina _INC_MBSTRING_S

#inclua <mbstring.h>

#se definido(MINGW_HAS_SECURE_API)

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _MBSTRING_S_DEFINED
#defina _MBSTRING_S_DEFINED
  _CRTIMP errno_t __cdecl _mbscat_s(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,constante sem_sinal caractere *_Src);
  _CRTIMP errno_t __cdecl _mbscat_s_l(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,constante sem_sinal caractere *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbscpy_s(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,constante sem_sinal caractere *_Src);
  _CRTIMP errno_t __cdecl _mbscpy_s_l(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,constante sem_sinal caractere *_Src,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbslwr_s(sem_sinal caractere *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbslwr_s_l(sem_sinal caractere *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcat_s(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,constante sem_sinal caractere *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnbcat_s_l(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,constante sem_sinal caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,constante sem_sinal caractere *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,constante sem_sinal caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnbset_s(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,sem_sinal inteiro _Ch,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnbset_s_l(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,sem_sinal inteiro _Ch,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncat_s(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,constante sem_sinal caractere *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsncat_s_l(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,constante sem_sinal caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsncpy_s(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,constante sem_sinal caractere *_Src,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsncpy_s_l(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,constante sem_sinal caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsnset_s(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,sem_sinal inteiro _Val,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbsnset_s_l(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,sem_sinal inteiro _Val,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsset_s(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,sem_sinal inteiro _Val);
  _CRTIMP errno_t __cdecl _mbsset_s_l(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,sem_sinal inteiro _Val,_locale_t _Locale);
  _CRTIMP sem_sinal caractere *__cdecl _mbstok_s(sem_sinal caractere *_Str,constante sem_sinal caractere *_Delim,sem_sinal caractere **_Context);
  _CRTIMP sem_sinal caractere *__cdecl _mbstok_s_l(sem_sinal caractere *_Str,constante sem_sinal caractere *_Delim,sem_sinal caractere **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbsupr_s(sem_sinal caractere *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _mbsupr_s_l(sem_sinal caractere *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _mbccpy_s(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,inteiro *_PCopied,constante sem_sinal caractere *_Src);
  _CRTIMP errno_t __cdecl _mbccpy_s_l(sem_sinal caractere *_Dst,size_t _DstSizeInBytes,inteiro *_PCopied,constante sem_sinal caractere *_Src,_locale_t _Locale);
#fim_se

#se_definido __cplusplus
}
#fim_se

#fim_se
#fim_se
