/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_LOCALE
#defina _INC_LOCALE

#inclua <_mingw.h>

#diretiva pack(push,_CRT_PACKING)

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido NULL
#se_definido __cplusplus
#defina NULL 0
#senão
#defina NULL ((vazio *)0)
#fim_se
#fim_se

#defina LC_ALL 0
#defina LC_COLLATE 1
#defina LC_CTYPE 2
#defina LC_MONETARY 3
#defina LC_NUMERIC 4
#defina LC_TIME 5

#defina LC_MIN LC_ALL
#defina LC_MAX LC_TIME

#se_não_definido _LCONV_DEFINED
#defina _LCONV_DEFINED
  estrutura lconv {
    caractere *decimal_point;
    caractere *thousands_sep;
    caractere *grouping;
    caractere *int_curr_symbol;
    caractere *currency_symbol;
    caractere *mon_decimal_point;
    caractere *mon_thousands_sep;
    caractere *mon_grouping;
    caractere *positive_sign;
    caractere *negative_sign;
    caractere int_frac_digits;
    caractere frac_digits;
    caractere p_cs_precedes;
    caractere p_sep_by_space;
    caractere n_cs_precedes;
    caractere n_sep_by_space;
    caractere p_sign_posn;
    caractere n_sign_posn;
  };
#fim_se

#se_não_definido _CONFIG_LOCALE_SWT
#defina _CONFIG_LOCALE_SWT

#defina _ENABLE_PER_THREAD_LOCALE 0x1
#defina _DISABLE_PER_THREAD_LOCALE 0x2
#defina _ENABLE_PER_THREAD_LOCALE_GLOBAL 0x10
#defina _DISABLE_PER_THREAD_LOCALE_GLOBAL 0x20
#defina _ENABLE_PER_THREAD_LOCALE_NEW 0x100
#defina _DISABLE_PER_THREAD_LOCALE_NEW 0x200

#fim_se

  inteiro __cdecl _configthreadlocale(inteiro _Flag);
  caractere *__cdecl setlocale(inteiro _Category,constante caractere *_Locale);
  _CRTIMP estrutura lconv *__cdecl localeconv(vazio);
  _locale_t __cdecl _get_current_locale(vazio);
  _locale_t __cdecl _create_locale(inteiro _Category,constante caractere *_Locale);
  vazio __cdecl _free_locale(_locale_t _Locale);
  _locale_t __cdecl __get_current_locale(vazio);
  _locale_t __cdecl __create_locale(inteiro _Category,constante caractere *_Locale);
  vazio __cdecl __free_locale(_locale_t _Locale);

#se_não_definido _WLOCALE_DEFINED
#defina _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(inteiro _Category,constante wchar_t *_Locale);
#fim_se

#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)
#fim_se
