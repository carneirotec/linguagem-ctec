/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_WCTYPE
#defina _INC_WCTYPE

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

#se_não_definido _WCTYPE_T_DEFINED
  defina_tipo sem_sinal curto wint_t;
  defina_tipo sem_sinal curto wctype_t;
#defina _WCTYPE_T_DEFINED
#fim_se

#se_não_definido WEOF
#defina WEOF (wint_t)(0xFFFF)
#fim_se

#se_não_definido _CRT_CTYPEDATA_DEFINED
#defina _CRT_CTYPEDATA_DEFINED
#se_não_definido _CTYPE_DISABLE_MACROS

#se_não_definido __PCTYPE_FUNC
#defina __PCTYPE_FUNC __pctype_func()
#se_definido _MSVCRT_
#defina __pctype_func() (_pctype)
#senão
#defina __pctype_func() (*_imp___pctype)
#fim_se
#fim_se

#se_não_definido _pctype
#se_definido _MSVCRT_
  externo sem_sinal curto *_pctype;
#senão
  externo sem_sinal curto **_imp___pctype;
#defina _pctype (*_imp___pctype)
#fim_se
#fim_se

#fim_se
#fim_se

#se_não_definido _CRT_WCTYPEDATA_DEFINED
#defina _CRT_WCTYPEDATA_DEFINED
#se_não_definido _CTYPE_DISABLE_MACROS
#se_não_definido _wctype
#se_definido _MSVCRT_
  externo sem_sinal curto *_wctype;
#senão
  externo sem_sinal curto **_imp___wctype;
#defina _wctype (*_imp___wctype)
#fim_se
#fim_se

#se_não_definido _pwctype
#se_definido _MSVCRT_
  externo sem_sinal curto *_pwctype;
#senão
  externo sem_sinal curto **_imp___pwctype;
#defina _pwctype (*_imp___pwctype)
#defina __pwctype_func() (*_imp___pwctype)
#fim_se
#fim_se
#fim_se
#fim_se

#defina _UPPER 0x1
#defina _LOWER 0x2
#defina _DIGIT 0x4
#defina _SPACE 0x8

#defina _PUNCT 0x10
#defina _CONTROL 0x20
#defina _BLANK 0x40
#defina _HEX 0x80

#defina _LEADBYTE 0x8000
#defina _ALPHA (0x0100|_UPPER|_LOWER)

#se_não_definido _WCTYPE_DEFINED
#defina _WCTYPE_DEFINED

  inteiro __cdecl iswalpha(wint_t);
  inteiro __cdecl iswupper(wint_t);
  inteiro __cdecl iswlower(wint_t);
  inteiro __cdecl iswdigit(wint_t);
  inteiro __cdecl iswxdigit(wint_t);
  inteiro __cdecl iswspace(wint_t);
  inteiro __cdecl iswpunct(wint_t);
  inteiro __cdecl iswalnum(wint_t);
  inteiro __cdecl iswprint(wint_t);
  inteiro __cdecl iswgraph(wint_t);
  inteiro __cdecl iswcntrl(wint_t);
  inteiro __cdecl iswascii(wint_t);
  inteiro __cdecl isleadbyte(inteiro);
  wint_t __cdecl towupper(wint_t);
  wint_t __cdecl towlower(wint_t);
  inteiro __cdecl iswctype(wint_t,wctype_t);
  _CRTIMP inteiro __cdecl __iswcsymf(wint_t);
  _CRTIMP inteiro __cdecl __iswcsym(wint_t);
  inteiro __cdecl is_wctype(wint_t,wctype_t);
#se (definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !definido (NO_OLDNAMES)
inteiro __cdecl isblank(inteiro _C);
#fim_se
#fim_se

#se_não_definido _WCTYPE_INLINE_DEFINED
#defina _WCTYPE_INLINE_DEFINED
#se_não_definido __cplusplus
#defina iswalpha(_c) (iswctype(_c,_ALPHA))
#defina iswupper(_c) (iswctype(_c,_UPPER))
#defina iswlower(_c) (iswctype(_c,_LOWER))
#defina iswdigit(_c) (iswctype(_c,_DIGIT))
#defina iswxdigit(_c) (iswctype(_c,_HEX))
#defina iswspace(_c) (iswctype(_c,_SPACE))
#defina iswpunct(_c) (iswctype(_c,_PUNCT))
#defina iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#defina iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#defina iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#defina iswcntrl(_c) (iswctype(_c,_CONTROL))
#defina iswascii(_c) ((sem_sinal)(_c) < 0x80)
#defina isleadbyte(c) (__pctype_func()[(sem_sinal caractere)(c)] & _LEADBYTE)
#senão
  __CRT_INLINE inteiro __cdecl iswalpha(wint_t _C) {retorne (iswctype(_C,_ALPHA)); }
  __CRT_INLINE inteiro __cdecl iswupper(wint_t _C) {retorne (iswctype(_C,_UPPER)); }
  __CRT_INLINE inteiro __cdecl iswlower(wint_t _C) {retorne (iswctype(_C,_LOWER)); }
  __CRT_INLINE inteiro __cdecl iswdigit(wint_t _C) {retorne (iswctype(_C,_DIGIT)); }
  __CRT_INLINE inteiro __cdecl iswxdigit(wint_t _C) {retorne (iswctype(_C,_HEX)); }
  __CRT_INLINE inteiro __cdecl iswspace(wint_t _C) {retorne (iswctype(_C,_SPACE)); }
  __CRT_INLINE inteiro __cdecl iswpunct(wint_t _C) {retorne (iswctype(_C,_PUNCT)); }
  __CRT_INLINE inteiro __cdecl iswalnum(wint_t _C) {retorne (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE inteiro __cdecl iswprint(wint_t _C) {retorne (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE inteiro __cdecl iswgraph(wint_t _C) {retorne (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE inteiro __cdecl iswcntrl(wint_t _C) {retorne (iswctype(_C,_CONTROL)); }
  __CRT_INLINE inteiro __cdecl iswascii(wint_t _C) {retorne ((sem_sinal)(_C) < 0x80); }
  __CRT_INLINE inteiro __cdecl isleadbyte(inteiro _C) {retorne (__pctype_func()[(sem_sinal caractere)(_C)] & _LEADBYTE); }
#fim_se
#fim_se

  defina_tipo wchar_t wctrans_t;
  wint_t __cdecl towctrans(wint_t,wctrans_t);
  wctrans_t __cdecl wctrans(constante caractere *);
  wctype_t __cdecl wctype(constante caractere *);

#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)
#fim_se
