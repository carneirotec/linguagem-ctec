/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_CTYPE
#defina _INC_CTYPE

#inclua <_mingw.h>

#se_definido __cplusplus
externo "C" {
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
#defina __pctype_func()	(_pctype)
#senão
#defina __pctype_func()	(*_imp___pctype)
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
#se_definido _MSVCRT_
#defina __pwctype_func() (_pwctype)
#se_não_definido _pwctype
  externo sem_sinal curto *_pwctype;
#fim_se
#senão
#defina __pwctype_func() (*_imp___pwctype)
#se_não_definido _pwctype
  externo sem_sinal curto **_imp___pwctype;
#defina _pwctype (*_imp___pwctype)
#fim_se
#fim_se
#fim_se
#fim_se

  /* CRT stuff */
#se 1
  externo constante sem_sinal caractere __newclmap[];
  externo constante sem_sinal caractere __newcumap[];
  externo pthreadlocinfo __ptlocinfo;
  externo pthreadmbcinfo __ptmbcinfo;
  externo inteiro __globallocalestatus;
  externo inteiro __locale_changed;
  externo estrutura threadlocaleinfostruct __initiallocinfo;
  externo _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo __cdecl __updatetlocinfo(vazio);
  pthreadmbcinfo __cdecl __updatetmbcinfo(vazio);
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

#se_não_definido _CTYPE_DEFINED
#defina _CTYPE_DEFINED

  _CRTIMP inteiro __cdecl _isctype(inteiro _C,inteiro _Type);
  _CRTIMP inteiro __cdecl _isctype_l(inteiro _C,inteiro _Type,_locale_t _Locale);
  _CRTIMP inteiro __cdecl isalpha(inteiro _C);
  _CRTIMP inteiro __cdecl _isalpha_l(inteiro _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl isupper(inteiro _C);
  _CRTIMP inteiro __cdecl _isupper_l(inteiro _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl islower(inteiro _C);
  _CRTIMP inteiro __cdecl _islower_l(inteiro _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl isdigit(inteiro _C);
  _CRTIMP inteiro __cdecl _isdigit_l(inteiro _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl isxdigit(inteiro _C);
  _CRTIMP inteiro __cdecl _isxdigit_l(inteiro _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl isspace(inteiro _C);
  _CRTIMP inteiro __cdecl _isspace_l(inteiro _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl ispunct(inteiro _C);
  _CRTIMP inteiro __cdecl _ispunct_l(inteiro _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl isalnum(inteiro _C);
  _CRTIMP inteiro __cdecl _isalnum_l(inteiro _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl isprint(inteiro _C);
  _CRTIMP inteiro __cdecl _isprint_l(inteiro _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl isgraph(inteiro _C);
  _CRTIMP inteiro __cdecl _isgraph_l(inteiro _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl iscntrl(inteiro _C);
  _CRTIMP inteiro __cdecl _iscntrl_l(inteiro _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl toupper(inteiro _C);
  _CRTIMP inteiro __cdecl tolower(inteiro _C);
  _CRTIMP inteiro __cdecl _tolower(inteiro _C);
  _CRTIMP inteiro __cdecl _tolower_l(inteiro _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _toupper(inteiro _C);
  _CRTIMP inteiro __cdecl _toupper_l(inteiro _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl __isascii(inteiro _C);
  _CRTIMP inteiro __cdecl __toascii(inteiro _C);
  _CRTIMP inteiro __cdecl __iscsymf(inteiro _C);
  _CRTIMP inteiro __cdecl __iscsym(inteiro _C);

#se (definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !definido (NO_OLDNAMES)
inteiro __cdecl isblank(inteiro _C);
#fim_se
#fim_se

#se_não_definido _WCTYPE_DEFINED
#defina _WCTYPE_DEFINED

  inteiro __cdecl iswalpha(wint_t _C);
  _CRTIMP inteiro __cdecl _iswalpha_l(wint_t _C,_locale_t _Locale);
  inteiro __cdecl iswupper(wint_t _C);
  _CRTIMP inteiro __cdecl _iswupper_l(wint_t _C,_locale_t _Locale);
  inteiro __cdecl iswlower(wint_t _C);
  _CRTIMP inteiro __cdecl _iswlower_l(wint_t _C,_locale_t _Locale);
  inteiro __cdecl iswdigit(wint_t _C);
  _CRTIMP inteiro __cdecl _iswdigit_l(wint_t _C,_locale_t _Locale);
  inteiro __cdecl iswxdigit(wint_t _C);
  _CRTIMP inteiro __cdecl _iswxdigit_l(wint_t _C,_locale_t _Locale);
  inteiro __cdecl iswspace(wint_t _C);
  _CRTIMP inteiro __cdecl _iswspace_l(wint_t _C,_locale_t _Locale);
  inteiro __cdecl iswpunct(wint_t _C);
  _CRTIMP inteiro __cdecl _iswpunct_l(wint_t _C,_locale_t _Locale);
  inteiro __cdecl iswalnum(wint_t _C);
  _CRTIMP inteiro __cdecl _iswalnum_l(wint_t _C,_locale_t _Locale);
  inteiro __cdecl iswprint(wint_t _C);
  _CRTIMP inteiro __cdecl _iswprint_l(wint_t _C,_locale_t _Locale);
  inteiro __cdecl iswgraph(wint_t _C);
  _CRTIMP inteiro __cdecl _iswgraph_l(wint_t _C,_locale_t _Locale);
  inteiro __cdecl iswcntrl(wint_t _C);
  _CRTIMP inteiro __cdecl _iswcntrl_l(wint_t _C,_locale_t _Locale);
  inteiro __cdecl iswascii(wint_t _C);
  inteiro __cdecl isleadbyte(inteiro _C);
  _CRTIMP inteiro __cdecl _isleadbyte_l(inteiro _C,_locale_t _Locale);
  wint_t __cdecl towupper(wint_t _C);
  _CRTIMP wint_t __cdecl _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t __cdecl towlower(wint_t _C);
  _CRTIMP wint_t __cdecl _towlower_l(wint_t _C,_locale_t _Locale);
  inteiro __cdecl iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP inteiro __cdecl _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP inteiro __cdecl __iswcsymf(wint_t _C);
  _CRTIMP inteiro __cdecl _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP inteiro __cdecl __iswcsym(wint_t _C);
  _CRTIMP inteiro __cdecl _iswcsym_l(wint_t _C,_locale_t _Locale);
  inteiro __cdecl is_wctype(wint_t _C,wctype_t _Type);

#se (definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !definido (NO_OLDNAMES)
inteiro __cdecl iswblank(wint_t _C);
#fim_se
#fim_se

#se_não_definido _CTYPE_DISABLE_MACROS

#se_não_definido MB_CUR_MAX
#defina MB_CUR_MAX ___mb_cur_max_func()
#se_não_definido __mb_cur_max
#se_definido _MSVCRT_
  externo inteiro __mb_cur_max;
#senão
#defina __mb_cur_max	(*_imp____mb_cur_max)
  externo inteiro *_imp____mb_cur_max;
#fim_se
#fim_se
#se_definido _MSVCRT_
#defina ___mb_cur_max_func() (__mb_cur_max)
#senão
#defina ___mb_cur_max_func() (*_imp____mb_cur_max)
#fim_se
#fim_se

#defina __chvalidchk(a,b) (__PCTYPE_FUNC[(a)] & (b))
#defina _chvalidchk_l(_Char,_Flag,_Locale) (!_Locale ? __chvalidchk(_Char,_Flag) : ((_locale_t)_Locale)->locinfo->pctype[_Char] & (_Flag))
#defina _ischartype_l(_Char,_Flag,_Locale) (((_Locale)!=NULL && (((_locale_t)(_Locale))->locinfo->mb_cur_max) > 1) ? _isctype_l(_Char,(_Flag),_Locale) : _chvalidchk_l(_Char,_Flag,_Locale))
#defina _isalpha_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA,_Locale)
#defina _isupper_l(_Char,_Locale) _ischartype_l(_Char,_UPPER,_Locale)
#defina _islower_l(_Char,_Locale) _ischartype_l(_Char,_LOWER,_Locale)
#defina _isdigit_l(_Char,_Locale) _ischartype_l(_Char,_DIGIT,_Locale)
#defina _isxdigit_l(_Char,_Locale) _ischartype_l(_Char,_HEX,_Locale)
#defina _isspace_l(_Char,_Locale) _ischartype_l(_Char,_SPACE,_Locale)
#defina _ispunct_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT,_Locale)
#defina _isalnum_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA|_DIGIT,_Locale)
#defina _isprint_l(_Char,_Locale) _ischartype_l(_Char,_BLANK|_PUNCT|_ALPHA|_DIGIT,_Locale)
#defina _isgraph_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT|_ALPHA|_DIGIT,_Locale)
#defina _iscntrl_l(_Char,_Locale) _ischartype_l(_Char,_CONTROL,_Locale)
#defina _tolower(_Char) ((_Char)-'A'+'a')
#defina _toupper(_Char) ((_Char)-'a'+'A')
#defina __isascii(_Char) ((sem_sinal)(_Char) < 0x80)
#defina __toascii(_Char) ((_Char) & 0x7f)

#se_não_definido _WCTYPE_INLINE_DEFINED
#defina _WCTYPE_INLINE_DEFINED

#não_definido _CRT_WCTYPE_NOINLINE
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
#defina _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#defina _iswupper_l(_c,_p) (_iswctype_l(_c,_UPPER,_p))
#defina _iswlower_l(_c,_p) (_iswctype_l(_c,_LOWER,_p))
#defina _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#defina _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#defina _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#defina _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#defina _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#defina _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#defina _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#defina _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#fim_se
#fim_se

#defina __iscsymf(_c) (isalpha(_c) || ((_c)=='_'))
#defina __iscsym(_c) (isalnum(_c) || ((_c)=='_'))
#defina __iswcsymf(_c) (iswalpha(_c) || ((_c)=='_'))
#defina __iswcsym(_c) (iswalnum(_c) || ((_c)=='_'))
#defina _iscsymf_l(_c,_p) (_isalpha_l(_c,_p) || ((_c)=='_'))
#defina _iscsym_l(_c,_p) (_isalnum_l(_c,_p) || ((_c)=='_'))
#defina _iswcsymf_l(_c,_p) (_iswalpha_l(_c,_p) || ((_c)=='_'))
#defina _iswcsym_l(_c,_p) (_iswalnum_l(_c,_p) || ((_c)=='_'))
#fim_se

#se_não_definido	NO_OLDNAMES
#se_não_definido _CTYPE_DEFINED
  inteiro __cdecl isascii(inteiro _C);
  inteiro __cdecl toascii(inteiro _C);
  inteiro __cdecl iscsymf(inteiro _C);
  inteiro __cdecl iscsym(inteiro _C);
#senão
#defina isascii __isascii
#defina toascii __toascii
#defina iscsymf __iscsymf
#defina iscsym __iscsym
#fim_se
#fim_se

#se_definido __cplusplus
}
#fim_se
#fim_se
