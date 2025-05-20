/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#se_não_definido _INC_CONIO_S
#defina _INC_CONIO_S

#inclua <conio.h>

#se definido(MINGW_HAS_SECURE_API)

#se_definido __cplusplus
externo "C" {
#fim_se

  _CRTIMP errno_t __cdecl _cgets_s(caractere *_Buffer,size_t _Size,size_t *_SizeRead);
  _CRTIMP inteiro __cdecl _cprintf_s(constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _cscanf_s(constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _cscanf_s_l(constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcprintf_s(constante caractere *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _cprintf_s_l(constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcprintf_s_l(constante caractere *_Format,_locale_t _Locale,va_list _ArgList);

#se_não_definido _WCONIO_DEFINED_S
#defina _WCONIO_DEFINED_S
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer,size_t _SizeInWords,size_t *_SizeRead);
  _CRTIMP inteiro __cdecl _cwprintf_s(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _cwscanf_s(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _cwscanf_s_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcwprintf_s(constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _cwprintf_s_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcwprintf_s_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#fim_se

#se_definido __cplusplus
}
#fim_se

#fim_se
#fim_se
