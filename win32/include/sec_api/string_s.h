/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_STRING_S
#defina _INC_STRING_S

#inclua <string.h>

#se definido(MINGW_HAS_SECURE_API)

#se_definido __cplusplus
externo "C" {
#fim_se

  _CRTIMP errno_t __cdecl _strset_s(caractere *_Dst,size_t _DstSize,inteiro _Value);
  _CRTIMP errno_t __cdecl _strerror_s(caractere *_Buf,size_t _SizeInBytes,constante caractere *_ErrMsg);
  _CRTIMP errno_t __cdecl _strlwr_s(caractere *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strlwr_s_l(caractere *_Str,size_t _Size,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strnset_s(caractere *_Str,size_t _Size,inteiro _Val,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _strupr_s(caractere *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _strupr_s_l(caractere *_Str,size_t _Size,_locale_t _Locale);
#se_não_definido _WSTRING_S_DEFINED
#defina _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,constante wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,size_t _SizeInWords,inteiro _ErrNum);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *_Buffer,size_t _SizeInWords,constante wchar_t *_ErrMsg);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,size_t _DstSizeInWords,wchar_t _Val,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,size_t _SizeInWords,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,size_t _SizeInWords);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,size_t _SizeInWords,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
#fim_se

#se_definido __cplusplus
}
#fim_se
#fim_se
#fim_se
