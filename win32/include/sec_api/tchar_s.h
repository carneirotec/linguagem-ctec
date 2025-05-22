/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_TCHAR_S
#defina _INC_TCHAR_S

#inclua <tchar.h>

#se definido(MINGW_HAS_SECURE_API)

#se_definido __cplusplus
externo "C" {
#fim_se

#se_definido _UNICODE

#defina _tprintf_s wprintf_s
#defina _tprintf_s_l _wprintf_s_l
#defina _tcprintf_s _cwprintf_s
#defina _tcprintf_s_l _cwprintf_s_l
#defina _vtcprintf_s _vcwprintf_s
#defina _vtcprintf_s_l _vcwprintf_s_l
#defina _ftprintf_s fwprintf_s
#defina _ftprintf_s_l _fwprintf_s_l
#defina _stprintf_s swprintf_s
#defina _stprintf_s_l _swprintf_s_l
#defina _sntprintf_s _snwprintf_s
#defina _sntprintf_s_l _snwprintf_s_l
#defina _vtprintf_s vwprintf_s
#defina _vtprintf_s_l _vwprintf_s_l
#defina _vftprintf_s vfwprintf_s
#defina _vftprintf_s_l _vfwprintf_s_l
#defina _vstprintf_s vswprintf_s
#defina _vstprintf_s_l _vswprintf_s_l
#defina _vsntprintf_s _vsnwprintf_s
#defina _vsntprintf_s_l _vsnwprintf_s_l

#defina _tscanf_s wscanf_s
#defina _tscanf_s_l _wscanf_s_l
#defina _tcscanf_s _cwscanf_s
#defina _tcscanf_s_l _cwscanf_s_l
#defina _ftscanf_s fwscanf_s
#defina _ftscanf_s_l _fwscanf_s_l
#defina _stscanf_s swscanf_s
#defina _stscanf_s_l _swscanf_s_l
#defina _sntscanf_s _snwscanf_s
#defina _sntscanf_s_l _snwscanf_s_l

#defina _cgetts_s _cgetws_s
#defina _getts_s _getws_s

#defina _itot_s _itow_s
#defina _ltot_s _ltow_s
#defina _ultot_s _ultow_s
#defina _i64tot_s _i64tow_s
#defina _ui64tot_s _ui64tow_s

#defina _tcscat_s wcscat_s
#defina _tcscpy_s wcscpy_s
#defina _tcsncat_s wcsncat_s
#defina _tcsncat_s_l _wcsncat_s_l
#defina _tcsncpy_s wcsncpy_s
#defina _tcsncpy_s_l _wcsncpy_s_l
#defina _tcstok_s wcstok_s
#defina _tcstok_s_l _wcstok_s_l
#defina _tcserror_s _wcserror_s
#defina __tcserror_s __wcserror_s

#defina _tcsnset_s _wcsnset_s
#defina _tcsnset_s_l _wcsnset_s_l
#defina _tcsset_s _wcsset_s
#defina _tcsset_s_l _wcsset_s_l

#defina _tasctime_s _wasctime_s
#defina _tctime_s _wctime_s
#defina _tctime32_s _wctime32_s
#defina _tctime64_s _wctime64_s
#defina _tstrdate_s _wstrdate_s
#defina _tstrtime_s _wstrtime_s

#defina _tgetenv_s _wgetenv_s
#defina _tdupenv_s _wdupenv_s
#defina _tmakepath_s _wmakepath_s
#defina _tputenv_s _wputenv_s
#defina _tsearchenv_s _wsearchenv_s
#defina _tsplitpath_s _wsplitpath_s

#defina _tfopen_s _wfopen_s
#defina _tfreopen_s _wfreopen_s
#defina _ttmpnam_s _wtmpnam_s
#defina _taccess_s _waccess_s
#defina _tmktemp_s _wmktemp_s

#defina _tcsnccat_s wcsncat_s
#defina _tcsnccat_s_l _wcsncat_s_l
#defina _tcsnccpy_s wcsncpy_s
#defina _tcsnccpy_s_l _wcsncpy_s_l

#defina _tcslwr_s _wcslwr_s
#defina _tcslwr_s_l _wcslwr_s_l
#defina _tcsupr_s _wcsupr_s
#defina _tcsupr_s_l _wcsupr_s_l

#defina _wcstok_s_l(_String,_Delimiters,_Current_position,_Locale) (wcstok_s(_String,_Delimiters,_Current_position))
#defina _wcsnset_s_l(_Destination,_Destination_size_chars,_Value,_Count,_Locale) (_wcsnset_s(_Destination,_Destination_size_chars,_Value,_Count))
#defina _wcsset_s_l(_Destination,_Destination_size_chars,_Value,_Locale) (_wcsset_s(_Destination,_Destination_size_chars,_Value))

#senão

#defina _tprintf_s printf_s
#defina _tprintf_s_l _printf_s_l
#defina _tcprintf_s _cprintf_s
#defina _tcprintf_s_l _cprintf_s_l
#defina _vtcprintf_s _vcprintf_s
#defina _vtcprintf_s_l _vcprintf_s_l
#defina _ftprintf_s fprintf_s
#defina _ftprintf_s_l _fprintf_s_l
#defina _stprintf_s sprintf_s
#defina _stprintf_s_l _sprintf_s_l
#defina _sntprintf_s _snprintf_s
#defina _sntprintf_s_l _snprintf_s_l
#defina _vtprintf_s vprintf_s
#defina _vtprintf_s_l _vprintf_s_l
#defina _vftprintf_s vfprintf_s
#defina _vftprintf_s_l _vfprintf_s_l
#defina _vstprintf_s vsprintf_s
#defina _vstprintf_s_l _vsprintf_s_l
#defina _vsntprintf_s _vsnprintf_s
#defina _vsntprintf_s_l _vsnprintf_s_l
#defina _tscanf_s scanf_s
#defina _tscanf_s_l _scanf_s_l
#defina _tcscanf_s _cscanf_s
#defina _tcscanf_s_l _cscanf_s_l
#defina _ftscanf_s fscanf_s
#defina _ftscanf_s_l _fscanf_s_l
#defina _stscanf_s sscanf_s
#defina _stscanf_s_l _sscanf_s_l
#defina _sntscanf_s _snscanf_s
#defina _sntscanf_s_l _snscanf_s_l

#defina _getts_s gets_s
#defina _cgetts_s _cgets_s
#defina _itot_s _itoa_s
#defina _ltot_s _ltoa_s
#defina _ultot_s _ultoa_s
#defina _i64tot_s _i64toa_s
#defina _ui64tot_s _ui64toa_s

#defina _tcscat_s strcat_s
#defina _tcscpy_s strcpy_s
#defina _tcserror_s strerror_s
#defina __tcserror_s _strerror_s

#defina _tasctime_s asctime_s
#defina _tctime_s ctime_s
#defina _tctime32_s _ctime32_s
#defina _tctime64_s _ctime64_s
#defina _tstrdate_s _strdate_s
#defina _tstrtime_s _strtime_s

#defina _tgetenv_s getenv_s
#defina _tdupenv_s _dupenv_s
#defina _tmakepath_s _makepath_s
#defina _tputenv_s _putenv_s
#defina _tsearchenv_s _searchenv_s
#defina _tsplitpath_s _splitpath_s

#defina _tfopen_s fopen_s
#defina _tfreopen_s freopen_s
#defina _ttmpnam_s tmpnam_s
#defina _tmktemp_s _mktemp_s

#se_não_definido _POSIX_
#defina _taccess_s _access_s
#fim_se

#defina _tsopen_s _sopen_s

#se_definido _MBCS

#se_definido _MB_MAP_DIRECT

#defina _tcsncat_s _mbsnbcat_s
#defina _tcsncat_s_l _mbsnbcat_s_l
#defina _tcsncpy_s _mbsnbcpy_s
#defina _tcsncpy_s_l _mbsnbcpy_s_l
#defina _tcstok_s _mbstok_s
#defina _tcstok_s_l _mbstok_s_l

#defina _tcsnset_s _mbsnbset_s
#defina _tcsnset_s_l _mbsnbset_s_l
#defina _tcsset_s _mbsset_s
#defina _tcsset_s_l _mbsset_s_l

#defina _tcsnccat_s _mbsncat_s
#defina _tcsnccat_s_l _mbsncat_s_l
#defina _tcsnccpy_s _mbsncpy_s
#defina _tcsnccpy_s_l _mbsncpy_s_l
#defina _tcsncset_s _mbsnset_s
#defina _tcsncset_s_l _mbsnset_s_l

#defina _tcslwr_s _mbslwr_s
#defina _tcslwr_s_l _mbslwr_s_l
#defina _tcsupr_s _mbsupr_s
#defina _tcsupr_s_l _mbsupr_s_l

#defina _ctecpy_s _mbccpy_s
#defina _ctecpy_s_l _mbccpy_s_l
#senão

  _CRTIMP caractere *__cdecl _tcsncat_s(caractere *_Dst,size_t _DstSizeInChars,constante caractere *_Src,size_t _MaxCount);
  _CRTIMP caractere *__cdecl _tcsncat_s_l(caractere *_Dst,size_t _DstSizeInChars,constante caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP caractere *__cdecl _tcsncpy_s(caractere *_Dst,size_t _DstSizeInChars,constante caractere *_Src,size_t _MaxCount);
  _CRTIMP caractere *__cdecl _tcsncpy_s_l(caractere *_Dst,size_t _DstSizeInChars,constante caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP caractere *__cdecl _tcstok_s(caractere *_Str,constante caractere *_Delim,caractere **_Context);
  _CRTIMP caractere *__cdecl _tcstok_s_l(caractere *_Str,constante caractere *_Delim,caractere **_Context,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _tcsset_s(caractere *_Str,size_t _SizeInChars,sem_sinal inteiro _Val);
  _CRTIMP errno_t __cdecl _tcsset_s_l(caractere *_Str,size_t _SizeInChars,sem_sinal inteiro,_locale_t _Locale);
  _CRTIMP caractere *__cdecl _tcsnccat_s(caractere *_Dst,size_t _DstSizeInChars,constante caractere *_Src,size_t _MaxCount);
  _CRTIMP caractere *__cdecl _tcsnccat_s_l(caractere *_Dst,size_t _DstSizeInChars,constante caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP caractere *__cdecl _tcsnccpy_s(caractere *_Dst,size_t _DstSizeInChars,constante caractere *_Src,size_t _MaxCount);
  _CRTIMP caractere *__cdecl _tcsnccpy_s_l(caractere *_Dst,size_t _DstSizeInChars,constante caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP caractere *__cdecl _tcslwr_s(caractere *_Str,size_t _SizeInChars);
  _CRTIMP caractere *__cdecl _tcslwr_s_l(caractere *_Str,size_t _SizeInChars,_locale_t _Locale);
  _CRTIMP caractere *__cdecl _tcsupr_s(caractere *_Str,size_t _SizeInChars);
  _CRTIMP caractere *__cdecl _tcsupr_s_l(caractere *_Str,size_t _SizeInChars,_locale_t _Locale);

#fim_se

#senão

#defina _tcsncat_s strncat_s
#defina _tcsncat_s_l _strncat_s_l
#defina _tcsncpy_s strncpy_s
#defina _tcsncpy_s_l _strncpy_s_l
#defina _tcstok_s strtok_s
#defina _tcstok_s_l _strtok_s_l

#defina _tcsnset_s _strnset_s
#defina _tcsnset_s_l _strnset_s_l
#defina _tcsset_s _strset_s
#defina _tcsset_s _strset_s
#defina _tcsset_s_l _strset_s_l

#defina _tcsnccat_s strncat_s
#defina _tcsnccat_s_l _strncat_s_l
#defina _tcsnccpy_s strncpy_s
#defina _tcsnccpy_s_l _strncpy_s_l

#defina _tcslwr_s _strlwr_s
#defina _tcslwr_s_l _strlwr_s_l
#defina _tcsupr_s _strupr_s
#defina _tcsupr_s_l _strupr_s_l

#defina _strnset_s_l(_Destination,_Destination_size_chars,_Value,_Count,_Locale) (_strnset_s(_Destination,_Destination_size_chars,_Value,_Count))
#defina _strset_s_l(_Destination,_Destination_size_chars,_Value,_Locale) (_strset_s(_Destination,_Destination_size_chars,_Value))
#fim_se
#fim_se

#se_definido __cplusplus
}
#fim_se
#fim_se
#fim_se
