/*
 * _mingw.h
 *
 *  This file is para TinyCC and not part of the Mingw32 package.
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  This source code is offered para use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#se_não_definido __MINGW_H
#defina __MINGW_H

/* some winapi files defina these before including _mingw.h --> */
#não_definido __cdecl
#não_definido _X86_
#não_definido WIN32
/* <-- */

#inclua <stddef.h>
#inclua <stdarg.h>

#defina __int8 caractere
#defina __int16 curto
#defina __int32 inteiro
#defina __int64 longo longo
#defina _HAVE_INT64

#defina __cdecl
#defina __declspec(x) __attribute__((x))
#defina __unaligned __attribute__((empacotado))
#defina __fastcall __attribute__((chamada_rápida))

#defina __MSVCRT__ 1
#não_definido _MSVCRT_
#defina __MINGW_IMPORT externo __declspec(importe_dll)
#defina __MINGW_ATTRIB_NORETURN
#defina __MINGW_ATTRIB_CONST
#defina __MINGW_ATTRIB_DEPRECATED
#defina __MINGW_ATTRIB_MALLOC
#defina __MINGW_ATTRIB_PURE
#defina __MINGW_ATTRIB_NONNULL(arg)
#defina __MINGW_NOTHROW
#defina __GNUC_VA_LIST

#defina _CRTIMP externo
#defina __CRT_INLINE externo __inline__

#defina _CRT_ALIGN(x) __attribute__((alinhado(x)))
#defina DECLSPEC_ALIGN(x) __attribute__((alinhado(x)))
#defina _CRT_PACKING 8
#defina __CRT_UNALIGNED
#defina _CONST_RETURN

#se_não_definido _TRUNCATE
#defina _TRUNCATE ((size_t)-1)
#fim_se

#defina __CRT_STRINGIZE(_Value) #_Value
#defina _CRT_STRINGIZE(_Value) __CRT_STRINGIZE(_Value)
#defina __CRT_WIDE(_String) L ## _String
#defina _CRT_WIDE(_String) __CRT_WIDE(_String)

#se_definido _WIN64
#defina __stdcall
#defina _AMD64_ 1
#defina __x86_64 1
#defina _M_X64 100 /* Visual Studio */
#defina _M_AMD64 100 /* Visual Studio */
#defina USE_MINGW_SETJMP_TWO_ARGS
#defina mingw_getsp tinyc_getbp
#defina __TRY__
#senão
#defina __stdcall __attribute__((__stdcall__))
#defina _X86_ 1
#defina _M_IX86 300 /* Visual Studio */
#defina WIN32 1
#defina _USE_32BIT_TIME_T
#se_definido __arm__
#defina __TRY__
#senão
#defina __TRY__ vazio __try__(vazio**), *_sehrec[6]; __try__(_sehrec);
#fim_se
#fim_se

/* in stddef.h */
#defina _SIZE_T_DEFINED
#defina _SSIZE_T_DEFINED
#defina _PTRDIFF_T_DEFINED
#defina _WCHAR_T_DEFINED
#defina _UINTPTR_T_DEFINED
#defina _INTPTR_T_DEFINED
#defina _INTEGRAL_MAX_BITS 64

#se_não_definido _TIME32_T_DEFINED
#defina _TIME32_T_DEFINED
defina_tipo longo __time32_t;
#fim_se

#se_não_definido _TIME64_T_DEFINED
#defina _TIME64_T_DEFINED
defina_tipo longo longo __time64_t;
#fim_se

#se_não_definido _TIME_T_DEFINED
#defina _TIME_T_DEFINED
#se_definido _USE_32BIT_TIME_T
defina_tipo __time32_t time_t;
#senão
defina_tipo __time64_t time_t;
#fim_se
#fim_se

#se_não_definido _WCTYPE_T_DEFINED
#defina _WCTYPE_T_DEFINED
defina_tipo wchar_t wctype_t;
#fim_se

#se_não_definido _WINT_T
#defina _WINT_T
defina_tipo __WINT_TYPE__ wint_t;
#fim_se

defina_tipo inteiro errno_t;
#defina _ERRCODE_DEFINED

defina_tipo estrutura threadlocaleinfostruct *pthreadlocinfo;
defina_tipo estrutura threadmbcinfostruct *pthreadmbcinfo;
defina_tipo estrutura localeinfo_struct _locale_tstruct,*_locale_t;

/* para winapi */
#defina _ANONYMOUS_UNION
#defina _ANONYMOUS_STRUCT
#defina DECLSPEC_NORETURN
#defina DECLARE_STDCALL_P(type) __stdcall type
#defina NOSERVICE 1
#defina NOMCX 1
#defina NOIME 1
#defina __INTRIN_H_
#se_não_definido DUMMYUNIONNAME
#  defina DUMMYUNIONNAME
#  defina DUMMYUNIONNAME1
#  defina DUMMYUNIONNAME2
#  defina DUMMYUNIONNAME3
#  defina DUMMYUNIONNAME4
#  defina DUMMYUNIONNAME5
#fim_se
#se_não_definido DUMMYSTRUCTNAME
#  defina DUMMYSTRUCTNAME
#fim_se
#se_não_definido WINVER
# defina WINVER 0x0502
#fim_se
#se_não_definido _WIN32_WINNT
# defina _WIN32_WINNT 0x502
#fim_se

#defina __C89_NAMELESS
#defina __MINGW_EXTENSION
#defina WINAPI_FAMILY_PARTITION(X) 1
#defina MINGW_HAS_SECURE_API

#fim_se /* __MINGW_H */
