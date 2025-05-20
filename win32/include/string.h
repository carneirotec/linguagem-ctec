/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_STRING
#defina _INC_STRING

#inclua <_mingw.h>

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _NLSCMP_DEFINED
#defina _NLSCMP_DEFINED
#defina _NLSCMPERROR 2147483647
#fim_se

#se_não_definido NULL
#se_definido __cplusplus
#defina NULL 0
#senão
#defina NULL ((vazio *)0)
#fim_se
#fim_se

#defina _WConst_return _CONST_RETURN

#se_não_definido _CRT_MEMORY_DEFINED
#defina _CRT_MEMORY_DEFINED
  _CRTIMP vazio *__cdecl _memccpy(vazio *_Dst,constante vazio *_Src,inteiro _Val,size_t _MaxCount);
  _CONST_RETURN vazio *__cdecl memchr(constante vazio *_Buf ,inteiro _Val,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _memicmp(constante vazio *_Buf1,constante vazio *_Buf2,size_t _Size);
  _CRTIMP inteiro __cdecl _memicmp_l(constante vazio *_Buf1,constante vazio *_Buf2,size_t _Size,_locale_t _Locale);
  inteiro __cdecl memcmp(constante vazio *_Buf1,constante vazio *_Buf2,size_t _Size);
  vazio *__cdecl memcpy(vazio *_Dst,constante vazio *_Src,size_t _Size);
  vazio *__cdecl memset(vazio *_Dst,inteiro _Val,size_t _Size);
#se_não_definido	NO_OLDNAMES
  vazio *__cdecl memccpy(vazio *_Dst,constante vazio *_Src,inteiro _Val,size_t _Size);
  inteiro __cdecl memicmp(constante vazio *_Buf1,constante vazio *_Buf2,size_t _Size);
#fim_se
#fim_se
  caractere *__cdecl _strset(caractere *_Str,inteiro _Val);
  caractere *__cdecl strcpy(caractere *_Dest,constante caractere *_Source);
  caractere *__cdecl strcat(caractere *_Dest,constante caractere *_Source);
  inteiro __cdecl strcmp(constante caractere *_Str1,constante caractere *_Str2);
  size_t __cdecl strlen(constante caractere *_Str);
#se 0
  size_t __cdecl strnlen(constante caractere *_Str,size_t _MaxCount);
#fim_se
  vazio *__cdecl memmove(vazio *_Dst,constante vazio *_Src,size_t _Size);
  _CRTIMP caractere *__cdecl _strdup(constante caractere *_Src);
  _CONST_RETURN caractere *__cdecl strchr(constante caractere *_Str,inteiro _Val);
  _CRTIMP inteiro __cdecl _stricmp(constante caractere *_Str1,constante caractere *_Str2);
  _CRTIMP inteiro __cdecl _strcmpi(constante caractere *_Str1,constante caractere *_Str2);
  _CRTIMP inteiro __cdecl _stricmp_l(constante caractere *_Str1,constante caractere *_Str2,_locale_t _Locale);
  inteiro __cdecl strcoll(constante caractere *_Str1,constante caractere *_Str2);
  _CRTIMP inteiro __cdecl _strcoll_l(constante caractere *_Str1,constante caractere *_Str2,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _stricoll(constante caractere *_Str1,constante caractere *_Str2);
  _CRTIMP inteiro __cdecl _stricoll_l(constante caractere *_Str1,constante caractere *_Str2,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _strncoll (constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _strncoll_l(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _strnicoll (constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _strnicoll_l(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  size_t __cdecl strcspn(constante caractere *_Str,constante caractere *_Control);
  _CRTIMP caractere *__cdecl _strerror(constante caractere *_ErrMsg);
  caractere *__cdecl strerror(inteiro);
  _CRTIMP caractere *__cdecl _strlwr(caractere *_String);
  caractere *strlwr_l(caractere *_String,_locale_t _Locale);
  caractere *__cdecl strncat(caractere *_Dest,constante caractere *_Source,size_t _Count);
  inteiro __cdecl strncmp(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _strnicmp(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _strnicmp_l(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  caractere *strncpy(caractere *_Dest,constante caractere *_Source,size_t _Count);
  _CRTIMP caractere *__cdecl _strnset(caractere *_Str,inteiro _Val,size_t _MaxCount);
  _CONST_RETURN caractere *__cdecl strpbrk(constante caractere *_Str,constante caractere *_Control);
  _CONST_RETURN caractere *__cdecl strrchr(constante caractere *_Str,inteiro _Ch);
  _CRTIMP caractere *__cdecl _strrev(caractere *_Str);
  size_t __cdecl strspn(constante caractere *_Str,constante caractere *_Control);
  _CONST_RETURN caractere *__cdecl strstr(constante caractere *_Str,constante caractere *_SubStr);
  caractere *__cdecl strtok(caractere *_Str,constante caractere *_Delim);
  _CRTIMP caractere *__cdecl _strupr(caractere *_String);
  _CRTIMP caractere *_strupr_l(caractere *_String,_locale_t _Locale);
  size_t __cdecl strxfrm(caractere *_Dst,constante caractere *_Src,size_t _MaxCount);
  _CRTIMP size_t __cdecl _strxfrm_l(caractere *_Dst,constante caractere *_Src,size_t _MaxCount,_locale_t _Locale);

#se_não_definido	NO_OLDNAMES
  caractere *__cdecl strdup(constante caractere *_Src);
  inteiro __cdecl strcmpi(constante caractere *_Str1,constante caractere *_Str2);
  inteiro __cdecl stricmp(constante caractere *_Str1,constante caractere *_Str2);
  caractere *__cdecl strlwr(caractere *_Str);
  inteiro __cdecl strnicmp(constante caractere *_Str1,constante caractere *_Str,size_t _MaxCount);
  __CRT_INLINE inteiro __cdecl strncasecmp (constante caractere *__sz1, constante caractere *__sz2, size_t __sizeMaxCompare) { retorne _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE inteiro __cdecl strcasecmp (constante caractere *__sz1, constante caractere *__sz2) { retorne _stricmp (__sz1, __sz2); }
  caractere *__cdecl strnset(caractere *_Str,inteiro _Val,size_t _MaxCount);
  caractere *__cdecl strrev(caractere *_Str);
  caractere *__cdecl strset(caractere *_Str,inteiro _Val);
  caractere *__cdecl strupr(caractere *_Str);
#fim_se

#se_não_definido _WSTRING_DEFINED
#defina _WSTRING_DEFINED

  _CRTIMP wchar_t *__cdecl _wcsdup(constante wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t *_Dest,constante wchar_t *_Source);
  _CONST_RETURN wchar_t *__cdecl wcschr(constante wchar_t *_Str,wchar_t _Ch);
  inteiro __cdecl wcscmp(constante wchar_t *_Str1,constante wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t *_Dest,constante wchar_t *_Source);
  size_t __cdecl wcscspn(constante wchar_t *_Str,constante wchar_t *_Control);
  size_t __cdecl wcslen(constante wchar_t *_Str);
  size_t __cdecl wcsnlen(constante wchar_t *_Src,size_t _MaxCount);
  wchar_t *wcsncat(wchar_t *_Dest,constante wchar_t *_Source,size_t _Count);
  inteiro __cdecl wcsncmp(constante wchar_t *_Str1,constante wchar_t *_Str2,size_t _MaxCount);
  wchar_t *wcsncpy(wchar_t *_Dest,constante wchar_t *_Source,size_t _Count);
  _CONST_RETURN wchar_t *__cdecl wcspbrk(constante wchar_t *_Str,constante wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsrchr(constante wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(constante wchar_t *_Str,constante wchar_t *_Control);
  _CONST_RETURN wchar_t *__cdecl wcsstr(constante wchar_t *_Str,constante wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t *_Str,constante wchar_t *_Delim);
  _CRTIMP wchar_t *__cdecl _wcserror(inteiro _ErrNum);
  _CRTIMP wchar_t *__cdecl __wcserror(constante wchar_t *_Str);
  _CRTIMP inteiro __cdecl _wcsicmp(constante wchar_t *_Str1,constante wchar_t *_Str2);
  _CRTIMP inteiro __cdecl _wcsicmp_l(constante wchar_t *_Str1,constante wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _wcsnicmp(constante wchar_t *_Str1,constante wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _wcsnicmp_l(constante wchar_t *_Str1,constante wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  _CRTIMP wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *__cdecl _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t __cdecl wcsxfrm(wchar_t *_Dst,constante wchar_t *_Src,size_t _MaxCount);
  _CRTIMP size_t __cdecl _wcsxfrm_l(wchar_t *_Dst,constante wchar_t *_Src,size_t _MaxCount,_locale_t _Locale);
  inteiro __cdecl wcscoll(constante wchar_t *_Str1,constante wchar_t *_Str2);
  _CRTIMP inteiro __cdecl _wcscoll_l(constante wchar_t *_Str1,constante wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _wcsicoll(constante wchar_t *_Str1,constante wchar_t *_Str2);
  _CRTIMP inteiro __cdecl _wcsicoll_l(constante wchar_t *_Str1,constante wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _wcsncoll(constante wchar_t *_Str1,constante wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _wcsncoll_l(constante wchar_t *_Str1,constante wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _wcsnicoll(constante wchar_t *_Str1,constante wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _wcsnicoll_l(constante wchar_t *_Str1,constante wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);

#se_não_definido	NO_OLDNAMES
  wchar_t *__cdecl wcsdup(constante wchar_t *_Str);
#defina wcswcs wcsstr
  inteiro __cdecl wcsicmp(constante wchar_t *_Str1,constante wchar_t *_Str2);
  inteiro __cdecl wcsnicmp(constante wchar_t *_Str1,constante wchar_t *_Str2,size_t _MaxCount);
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  wchar_t *__cdecl wcsrev(wchar_t *_Str);
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *__cdecl wcslwr(wchar_t *_Str);
  wchar_t *__cdecl wcsupr(wchar_t *_Str);
  inteiro __cdecl wcsicoll(constante wchar_t *_Str1,constante wchar_t *_Str2);
#fim_se
#fim_se

#se_definido __cplusplus
}
#fim_se

#inclua <sec_api/string_s.h>
#fim_se
