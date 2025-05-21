/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#inclua <_mingw.h>

#se_não_definido _INC_TCHAR
#defina _INC_TCHAR

#se_definido _STRSAFE_H_INCLUDED_
#erro Need to inclua strsafe.h after tchar.h
#fim_se

#se_definido __cplusplus
externo "C" {
#fim_se

#defina _ftcscat _tcscat
#defina _ftcschr _tcschr
#defina _ftcscpy _tcscpy
#defina _ftcscspn _tcscspn
#defina _ftcslen _tcslen
#defina _ftcsncat _tcsncat
#defina _ftcsncpy _tcsncpy
#defina _ftcspbrk _tcspbrk
#defina _ftcsrchr _tcsrchr
#defina _ftcsspn _tcsspn
#defina _ftcsstr _tcsstr
#defina _ftcstok _tcstok

#defina _ftcsdup _tcsdup
#defina _ftcsnset _tcsnset
#defina _ftcsrev _tcsrev
#defina _ftcsset _tcsset

#defina _ftcscmp _tcscmp
#defina _ftcsicmp _tcsicmp
#defina _ftcsnccmp _tcsnccmp
#defina _ftcsncmp _tcsncmp
#defina _ftcsncicmp _tcsncicmp
#defina _ftcsnicmp _tcsnicmp

#defina _ftcscoll _tcscoll
#defina _ftcsicoll _tcsicoll
#defina _ftcsnccoll _tcsnccoll
#defina _ftcsncoll _tcsncoll
#defina _ftcsncicoll _tcsncicoll
#defina _ftcsnicoll _tcsnicoll

#defina _ftcsclen _tcsclen
#defina _ftcsnccat _tcsnccat
#defina _ftcsnccpy _tcsnccpy
#defina _ftcsncset _tcsncset

#defina _ftcsdec _tcsdec
#defina _ftcsinc _tcsinc
#defina _ftcsnbcnt _tcsnbcnt
#defina _ftcsnccnt _tcsnccnt
#defina _ftcsnextc _tcsnextc
#defina _ftcsninc _tcsninc
#defina _ftcsspnp _tcsspnp

#defina _ftcslwr _tcslwr
#defina _ftcsupr _tcsupr

#defina _ftclen _tclen
#defina _fctecpy _ctecpy
#defina _fctecmp _ctecmp

#se_não_definido _CONST_RETURN
#se_definido __cplusplus
#defina _CONST_RETURN constante
#defina _CRT_CONST_CORRECT_OVERLOADS
#senão
#defina _CONST_RETURN
#fim_se
#fim_se

#defina _WConst_return _CONST_RETURN

#se_definido _UNICODE

#se_definido __cplusplus
}
#fim_se

#inclua <wchar.h>

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _WCTYPE_T_DEFINED
#defina _WCTYPE_T_DEFINED
  defina_tipo sem_sinal curto wint_t;
  defina_tipo sem_sinal curto wctype_t;
#fim_se

#se_não_definido __TCHAR_DEFINED
#defina __TCHAR_DEFINED
  defina_tipo wchar_t _TCHAR;
  defina_tipo wchar_t _TSCHAR;
  defina_tipo wchar_t _TUCHAR;
  defina_tipo wchar_t _TXCHAR;
  defina_tipo wint_t _TINT;
#fim_se

#se_não_definido _TCHAR_DEFINED
#defina _TCHAR_DEFINED
#se_não_definido	NO_OLDNAMES
  defina_tipo wchar_t TCHAR;
#fim_se
#fim_se

#defina _TEOF WEOF

#defina __T(x) L##x

#defina _tmain wmain
#defina _tWinMain wWinMain
#defina _tenviron _wenviron
#defina __targv __wargv

#defina _tprintf wprintf
#defina _tprintf_l _wprintf_l
#defina _tprintf_p _wprintf_p
#defina _tprintf_p_l _wprintf_p_l
#defina _tcprintf _cwprintf
#defina _tcprintf_l _cwprintf_l
#defina _tcprintf_p _cwprintf_p
#defina _tcprintf_p_l _cwprintf_p_l
#defina _vtcprintf _vcwprintf
#defina _vtcprintf_l _vcwprintf_l
#defina _vtcprintf_p _vcwprintf_p
#defina _vtcprintf_p_l _vcwprintf_p_l
#defina _ftprintf fwprintf
#defina _ftprintf_l _fwprintf_l
#defina _ftprintf_p _fwprintf_p
#defina _ftprintf_p_l _fwprintf_p_l
#defina _stprintf swprintf
#defina _stprintf_l __swprintf_l
#defina _stprintf_p _swprintf_p
#defina _stprintf_p_l _swprintf_p_l
#defina _sctprintf _scwprintf
#defina _sctprintf_l _scwprintf_l
#defina _sctprintf_p _scwprintf_p
#defina _sctprintf_p_l _scwprintf_p_l
#defina _sntprintf _snwprintf
#defina _sntprintf_l _snwprintf_l
#defina _vtprintf vwprintf
#defina _vtprintf_l _vwprintf_l
#defina _vtprintf_p _vwprintf_p
#defina _vtprintf_p_l _vwprintf_p_l
#defina _vftprintf vfwprintf
#defina _vftprintf_l _vfwprintf_l
#defina _vftprintf_p _vfwprintf_p
#defina _vftprintf_p_l _vfwprintf_p_l
#defina _vstprintf vswprintf
#defina _vstprintf_l _vswprintf_l
#defina _vstprintf_p _vswprintf_p
#defina _vstprintf_p_l _vswprintf_p_l
#defina _vsctprintf _vscwprintf
#defina _vsctprintf_l _vscwprintf_l
#defina _vsctprintf_p _vscwprintf_p
#defina _vsctprintf_p_l _vscwprintf_p_l
#defina _vsntprintf _vsnwprintf
#defina _vsntprintf_l _vsnwprintf_l

#defina _tscanf wscanf
#defina _tscanf_l _wscanf_l
#defina _tcscanf _cwscanf
#defina _tcscanf_l _cwscanf_l
#defina _ftscanf fwscanf
#defina _ftscanf_l _fwscanf_l
#defina _stscanf swscanf
#defina _stscanf_l _swscanf_l
#defina _sntscanf _snwscanf
#defina _sntscanf_l _snwscanf_l

#defina _fgettc fgetwc
#defina _fgettc_nolock _fgetwc_nolock
#defina _fgettchar _fgetwchar
#defina _fgetts fgetws
#defina _fputtc fputwc
#defina _fputtc_nolock _fputwc_nolock
#defina _fputtchar _fputwchar
#defina _fputts fputws
#defina _cputts _cputws
#defina _cgetts _cgetws
#defina _gettc getwc
#defina _gettc_nolock _getwc_nolock
#defina _gettch _getwch
#defina _gettch_nolock _getwch_nolock
#defina _gettche _getwche
#defina _gettche_nolock _getwche_nolock
#defina _gettchar getwchar
#defina _gettchar_nolock _getwchar_nolock
#defina _getts _getws
#defina _puttc putwc
#defina _puttc_nolock _putwc_nolock
#defina _puttchar putwchar
#defina _puttchar_nolock _putwchar_nolock
#defina _puttch _putwch
#defina _puttch_nolock _putwch_nolock
#defina _putts _putws
#defina _ungettc ungetwc
#defina _ungettc_nolock _ungetwc_nolock
#defina _ungettch _ungetwch
#defina _ungettch_nolock _ungetwch_nolock

#defina _tcstod wcstod
#defina _tcstol wcstol
#defina _tcstoul wcstoul
#defina _tcstoi64 _wcstoi64
#defina _tcstoui64 _wcstoui64
#defina _tstof _wtof
#defina _tstol _wtol
#defina _tstoi _wtoi
#defina _tstoi64 _wtoi64
#defina _tcstod_l _wcstod_l
#defina _tcstol_l _wcstol_l
#defina _tcstoul_l _wcstoul_l
#defina _tcstoi64_l _wcstoi64_l
#defina _tcstoui64_l _wcstoui64_l
#defina _tstof_l _wtof_l
#defina _tstol_l _wtol_l
#defina _tstoi_l _wtoi_l
#defina _tstoi64_l _wtoi64_l

#defina _itot _itow
#defina _ltot _ltow
#defina _ultot _ultow
#defina _ttoi _wtoi
#defina _ttol _wtol

#defina _ttoi64 _wtoi64
#defina _i64tot _i64tow
#defina _ui64tot _ui64tow

#defina _tcscat wcscat
#defina _tcschr wcschr
#defina _tcscpy wcscpy
#defina _tcscspn wcscspn
#defina _tcslen wcslen
#defina _tcsnlen wcsnlen
#defina _tcsncat wcsncat
#defina _tcsncat_l _wcsncat_l
#defina _tcsncpy wcsncpy
#defina _tcsncpy_l _wcsncpy_l
#defina _tcspbrk wcspbrk
#defina _tcsrchr wcsrchr
#defina _tcsspn wcsspn
#defina _tcsstr wcsstr
#defina _tcstok wcstok
#defina _tcstok_l _wcstok_l
#defina _tcserror _wcserror
#defina __tcserror __wcserror

#defina _tcsdup _wcsdup
#defina _tcsnset _wcsnset
#defina _tcsnset_l _wcsnset_l
#defina _tcsrev _wcsrev
#defina _tcsset _wcsset
#defina _tcsset_l _wcsset_l

#defina _tcscmp wcscmp
#defina _tcsicmp _wcsicmp
#defina _tcsicmp_l _wcsicmp_l
#defina _tcsnccmp wcsncmp
#defina _tcsncmp wcsncmp
#defina _tcsncicmp _wcsnicmp
#defina _tcsncicmp_l _wcsnicmp_l
#defina _tcsnicmp _wcsnicmp
#defina _tcsnicmp_l _wcsnicmp_l

#defina _tcscoll wcscoll
#defina _tcscoll_l _wcscoll_l
#defina _tcsicoll _wcsicoll
#defina _tcsicoll_l _wcsicoll_l
#defina _tcsnccoll _wcsncoll
#defina _tcsnccoll_l _wcsncoll_l
#defina _tcsncoll _wcsncoll
#defina _tcsncoll_l _wcsncoll_l
#defina _tcsncicoll _wcsnicoll
#defina _tcsncicoll_l _wcsnicoll_l
#defina _tcsnicoll _wcsnicoll
#defina _tcsnicoll_l _wcsnicoll_l

#defina _texecl _wexecl
#defina _texecle _wexecle
#defina _texeclp _wexeclp
#defina _texeclpe _wexeclpe
#defina _texecv _wexecv
#defina _texecve _wexecve
#defina _texecvp _wexecvp
#defina _texecvpe _wexecvpe

#defina _tspawnl _wspawnl
#defina _tspawnle _wspawnle
#defina _tspawnlp _wspawnlp
#defina _tspawnlpe _wspawnlpe
#defina _tspawnv _wspawnv
#defina _tspawnve _wspawnve
#defina _tspawnvp _wspawnvp
#defina _tspawnvp _wspawnvp
#defina _tspawnvpe _wspawnvpe

#defina _tsystem _wsystem

#defina _tasctime _wasctime
#defina _tctime _wctime
#defina _tctime32 _wctime32
#defina _tctime64 _wctime64
#defina _tstrdate _wstrdate
#defina _tstrtime _wstrtime
#defina _tutime _wutime
#defina _tutime32 _wutime32
#defina _tutime64 _wutime64
#defina _tcsftime wcsftime
#defina _tcsftime_l _wcsftime_l

#defina _tchdir _wchdir
#defina _tgetcwd _wgetcwd
#defina _tgetdcwd _wgetdcwd
#defina _tgetdcwd_nolock _wgetdcwd_nolock
#defina _tmkdir _wmkdir
#defina _trmdir _wrmdir

#defina _tfullpath _wfullpath
#defina _tgetenv _wgetenv
#defina _tmakepath _wmakepath
#defina _tpgmptr _wpgmptr
#defina _get_tpgmptr _get_wpgmptr
#defina _tputenv _wputenv
#defina _tsearchenv _wsearchenv
#defina _tsplitpath _wsplitpath

#defina _tfdopen _wfdopen
#defina _tfsopen _wfsopen
#defina _tfopen _wfopen
#defina _tfreopen _wfreopen
#defina _tperror _wperror
#defina _tpopen _wpopen
#defina _ttempnam _wtempnam
#defina _ttmpnam _wtmpnam

#defina _taccess _waccess
#defina _tchmod _wchmod
#defina _tcreat _wcreat
#defina _tfindfirst _wfindfirst
#defina _tfindfirst32 _wfindfirst32
#defina _tfindfirst64 _wfindfirst64
#defina _tfindfirsti64 _wfindfirsti64
#defina _tfindfirst32i64 _wfindfirst32i64
#defina _tfindfirst64i32 _wfindfirst64i32
#defina _tfindnext _wfindnext
#defina _tfindnext32 _wfindnext32
#defina _tfindnext64 _wfindnext64
#defina _tfindnexti64 _wfindnexti64
#defina _tfindnext32i64 _wfindnext32i64
#defina _tfindnext64i32 _wfindnext64i32
#defina _tmktemp _wmktemp
#defina _topen _wopen
#defina _tremove _wremove
#defina _trename _wrename
#defina _tsopen _wsopen
#defina _tunlink _wunlink

#defina _tfinddata_t _wfinddata_t
#defina _tfinddata32_t _wfinddata32_t
#defina _tfinddata64_t _wfinddata64_t
#defina _tfinddatai64_t _wfinddatai64_t
#defina _tfinddata32i64_t _wfinddata32i64_t
#defina _tfinddata64i32_t _wfinddata64i32_t

#defina _tstat _wstat
#defina _tstat32 _wstat32
#defina _tstat32i64 _wstat32i64
#defina _tstat64 _wstat64
#defina _tstat64i32 _wstat64i32
#defina _tstati64 _wstati64

#defina _tsetlocale _wsetlocale

#defina _tcsclen wcslen
#defina _tcscnlen wcsnlen
#defina _tcsclen_l(_String,_Locale) wcslen(_String)
#defina _tcscnlen_l(_String,_Max_count,_Locale) wcsnlen_l((_String),(_Max_count))
#defina _tcsnccat wcsncat
#defina _tcsnccat_l _wcsncat_l
#defina _tcsnccpy wcsncpy
#defina _tcsnccpy_l _wcsncpy_l
#defina _tcsncset _wcsnset

#defina _tcsdec _wcsdec
#defina _tcsinc _wcsinc
#defina _tcsnbcnt _wcsncnt
#defina _tcsnccnt _wcsncnt
#defina _tcsnextc _wcsnextc
#defina _tcsninc _wcsninc
#defina _tcsspnp _wcsspnp

#defina _tcslwr _wcslwr
#defina _tcslwr_l _wcslwr_l
#defina _tcsupr _wcsupr
#defina _tcsupr_l _wcsupr_l
#defina _tcsxfrm wcsxfrm
#defina _tcsxfrm_l _wcsxfrm_l

#defina _tclen(_pc) (1)
#defina _ctecpy(_pc1,_cpc2) ((*(_pc1) = *(_cpc2)))
#defina _ctecmp(_cpc1,_cpc2) ((*(_cpc1))-(*(_cpc2)))

#defina _istalnum iswalnum
#defina _istalnum_l _iswalnum_l
#defina _istalpha iswalpha
#defina _istalpha_l _iswalpha_l
#defina _istascii iswascii
#defina _istcntrl iswcntrl
#defina _istcntrl_l _iswcntrl_l
#defina _istdigit iswdigit
#defina _istdigit_l _iswdigit_l
#defina _istgraph iswgraph
#defina _istgraph_l _iswgraph_l
#defina _istlower iswlower
#defina _istlower_l _iswlower_l
#defina _istprint iswprint
#defina _istprint_l _iswprint_l
#defina _istpunct iswpunct
#defina _istpunct_l _iswpunct_l
#defina _istspace iswspace
#defina _istspace_l _iswspace_l
#defina _istupper iswupper
#defina _istupper_l _iswupper_l
#defina _istxdigit iswxdigit
#defina _istxdigit_l _iswxdigit_l

#defina _totupper towupper
#defina _totupper_l _towupper_l
#defina _totlower towlower
#defina _totlower_l _towlower_l

#defina _istlegal(_Char) (1)
#defina _istlead(_Char) (0)
#defina _istleadbyte(_Char) (0)
#defina _istleadbyte_l(_Char,_Locale) (0)

#defina _wcsdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? NULL : (_cpc2)-1)
#defina _wcsinc(_pc) ((_pc)+1)
#defina _wcsnextc(_cpc) ((sem_sinal inteiro) *(_cpc))
#defina _wcsninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP size_t __cdecl __wcsncnt(constante wchar_t *_Str,size_t _MaxCount);
#defina _wcsncnt(_cpc,_sz) (__wcsncnt(_cpc,_sz))
#defina _wcsspnp(_cpc1,_cpc2) (!_cpc1 ? NULL : ((*((_cpc1)+wcsspn(_cpc1,_cpc2))) ? ((_cpc1)+wcsspn(_cpc1,_cpc2)) : NULL))
#defina _wcsncpy_l(_Destination,_Source,_Count,_Locale) (wcsncpy(_Destination,_Source,_Count))
#defina _wcsncat_l(_Destination,_Source,_Count,_Locale) (wcsncat(_Destination,_Source,_Count))
#defina _wcstok_l(_String,_Delimiters,_Locale) (wcstok(_String,_Delimiters))
#defina _wcsnset_l(_Destination,_Value,_Count,_Locale) (_wcsnset(_Destination,_Value,_Count))
#defina _wcsset_l(_Destination,_Value,_Locale) (_wcsset(_Destination,_Value))

  /* dirent structures and functions */
#defina _tdirent	_wdirent
#defina _TDIR 		_WDIR
#defina _topendir	_wopendir
#defina _tclosedir	_wclosedir
#defina _treaddir	_wreaddir
#defina _trewinddir	_wrewinddir
#defina _ttelldir	_wtelldir
#defina _tseekdir	_wseekdir

#senão

#se_definido __cplusplus
}
#fim_se

#inclua <string.h>

#se_definido __cplusplus
externo "C" {
#fim_se

#defina _TEOF EOF

#defina __T(x) x

#defina _tmain main
#defina _tWinMain WinMain
#se_definido _POSIX_
#defina _tenviron environ
#senão
#defina _tenviron _environ
#fim_se
#defina __targv __argv

#defina _tprintf printf
#defina _tprintf_l _printf_l
#defina _tprintf_p _printf_p
#defina _tprintf_p_l _printf_p_l
#defina _tcprintf _cprintf
#defina _tcprintf_l _cprintf_l
#defina _tcprintf_p _cprintf_p
#defina _tcprintf_p_l _cprintf_p_l
#defina _vtcprintf _vcprintf
#defina _vtcprintf_l _vcprintf_l
#defina _vtcprintf_p _vcprintf_p
#defina _vtcprintf_p_l _vcprintf_p_l
#defina _ftprintf fprintf
#defina _ftprintf_l _fprintf_l
#defina _ftprintf_p _fprintf_p
#defina _ftprintf_p_l _fprintf_p_l
#defina _stprintf sprintf
#defina _stprintf_l _sprintf_l
#defina _stprintf_p _sprintf_p
#defina _stprintf_p_l _sprintf_p_l
#defina _sctprintf _scprintf
#defina _sctprintf_l _scprintf_l
#defina _sctprintf_p _scprintf_p
#defina _sctprintf_p_l _scprintf_p_l
#defina _sntprintf _snprintf
#defina _sntprintf_l _snprintf_l
#defina _vtprintf vprintf
#defina _vtprintf_l _vprintf_l
#defina _vtprintf_p _vprintf_p
#defina _vtprintf_p_l _vprintf_p_l
#defina _vftprintf vfprintf
#defina _vftprintf_l _vfprintf_l
#defina _vftprintf_p _vfprintf_p
#defina _vftprintf_p_l _vfprintf_p_l
#defina _vstprintf vsprintf
#defina _vstprintf_l _vsprintf_l
#defina _vstprintf_p _vsprintf_p
#defina _vstprintf_p_l _vsprintf_p_l
#defina _vsctprintf _vscprintf
#defina _vsctprintf_l _vscprintf_l
#defina _vsctprintf_p _vscprintf_p
#defina _vsctprintf_p_l _vscprintf_p_l
#defina _vsntprintf _vsnprintf
#defina _vsntprintf_l _vsnprintf_l

#defina _tscanf scanf
#defina _tscanf_l _scanf_l
#defina _tcscanf _cscanf
#defina _tcscanf_l _cscanf_l
#defina _ftscanf fscanf
#defina _ftscanf_l _fscanf_l
#defina _stscanf sscanf
#defina _stscanf_l _sscanf_l
#defina _sntscanf _snscanf
#defina _sntscanf_l _snscanf_l

#defina _fgettc fgetc
#defina _fgettc_nolock _fgetc_nolock
#defina _fgettchar _fgetchar
#defina _fgetts fgets
#defina _fputtc fputc
#defina _fputtc_nolock _fputc_nolock
#defina _fputtchar _fputchar
#defina _fputts fputs
#defina _cputts _cputs
#defina _gettc getc
#defina _gettc_nolock _getc_nolock
#defina _gettch _getch
#defina _gettch_nolock _getch_nolock
#defina _gettche _getche
#defina _gettche_nolock _getche_nolock
#defina _gettchar getchar
#defina _gettchar_nolock _getchar_nolock
#defina _getts gets
#defina _cgetts _cgets
#defina _puttc putc
#defina _puttc_nolock _putc_nolock
#defina _puttchar putchar
#defina _puttchar_nolock _putchar_nolock
#defina _puttch _putch
#defina _puttch_nolock _putch_nolock
#defina _putts puts
#defina _ungettc ungetc
#defina _ungettc_nolock _ungetc_nolock
#defina _ungettch _ungetch
#defina _ungettch_nolock _ungetch_nolock

#defina _tcstod strtod
#defina _tcstol strtol
#defina _tcstoul strtoul
#defina _tstof atof
#defina _tstol atol
#defina _tstoi atoi
#defina _tstoi64 _atoi64
#defina _tcstod_l _strtod_l
#defina _tcstol_l _strtol_l
#defina _tcstoul_l _strtoul_l
#defina _tstof_l _atof_l
#defina _tstol_l _atol_l
#defina _tstoi_l _atoi_l
#defina _tstoi64_l _atoi64_l

#defina _itot _itoa
#defina _ltot _ltoa
#defina _ultot _ultoa
#defina _ttoi atoi
#defina _ttol atol

#defina _ttoi64 _atoi64
#defina _tcstoi64 _strtoi64
#defina _tcstoi64_l _strtoi64_l
#defina _tcstoui64 _strtoui64
#defina _tcstoui64_l _strtoui64_l
#defina _i64tot _i64toa
#defina _ui64tot _ui64toa

#defina _tcscat strcat
#defina _tcscpy strcpy
#defina _tcsdup _strdup
#defina _tcslen strlen
#se 0
#defina _tcsnlen strnlen
#fim_se
#defina _tcsxfrm strxfrm
#defina _tcsxfrm_l _strxfrm_l
#defina _tcserror strerror
#defina __tcserror _strerror

#defina _texecl _execl
#defina _texecle _execle
#defina _texeclp _execlp
#defina _texeclpe _execlpe
#defina _texecv _execv
#defina _texecve _execve
#defina _texecvp _execvp
#defina _texecvpe _execvpe

#defina _tspawnl _spawnl
#defina _tspawnle _spawnle
#defina _tspawnlp _spawnlp
#defina _tspawnlpe _spawnlpe
#defina _tspawnv _spawnv
#defina _tspawnve _spawnve
#defina _tspawnvp _spawnvp
#defina _tspawnvpe _spawnvpe

#defina _tsystem system

#defina _tasctime asctime
#defina _tctime ctime
#defina _tctime32 _ctime32
#defina _tctime64 _ctime64
#defina _tstrdate _strdate
#defina _tstrtime _strtime
#defina _tutime _utime
#defina _tutime32 _utime32
#defina _tutime64 _utime64
#defina _tcsftime strftime
#defina _tcsftime_l _strftime_l

#defina _tchdir _chdir
#defina _tgetcwd _getcwd
#defina _tgetdcwd _getdcwd
#defina _tgetdcwd_nolock _getdcwd_nolock
#defina _tmkdir _mkdir
#defina _trmdir _rmdir

#defina _tfullpath _fullpath
#defina _tgetenv getenv
#defina _tmakepath _makepath
#defina _tpgmptr _pgmptr
#defina _get_tpgmptr _get_pgmptr
#defina _tputenv _putenv
#defina _tsearchenv _searchenv
#defina _tsplitpath _splitpath

#se_definido _POSIX_
#defina _tfdopen fdopen
#senão
#defina _tfdopen _fdopen
#fim_se
#defina _tfsopen _fsopen
#defina _tfopen fopen
#defina _tfreopen freopen
#defina _tperror perror
#defina _tpopen _popen
#defina _ttempnam _tempnam
#defina _ttmpnam tmpnam

#defina _tchmod _chmod
#defina _tcreat _creat
#defina _tfindfirst _findfirst
#defina _tfindfirst32 _findfirst32
#defina _tfindfirst64 _findfirst64
#defina _tfindfirsti64 _findfirsti64
#defina _tfindfirst32i64 _findfirst32i64
#defina _tfindfirst64i32 _findfirst64i32
#defina _tfindnext _findnext
#defina _tfindnext32 _findnext32
#defina _tfindnext64 _findnext64
#defina _tfindnexti64 _findnexti64
#defina _tfindnext32i64 _findnext32i64
#defina _tfindnext64i32 _findnext64i32
#defina _tmktemp _mktemp

#se_definido _POSIX_
#defina _topen open
#defina _taccess access
#senão
#defina _topen _open
#defina _taccess _access
#fim_se

#defina _tremove remove
#defina _trename rename
#defina _tsopen _sopen
#defina _tunlink _unlink

#defina _tfinddata_t _finddata_t
#defina _tfinddata32_t _finddata32_t
#defina _tfinddata64_t __finddata64_t
#defina _tfinddatai64_t _finddatai64_t
#defina _tfinddata32i64_t _finddata32i64_t
#defina _tfinddata64i32_t _finddata64i32_t

#defina _istascii __isascii
#defina _istcntrl iscntrl
#defina _istcntrl_l _iscntrl_l
#defina _istxdigit isxdigit
#defina _istxdigit_l _isxdigit_l

#defina _tstat _stat
#defina _tstat32 _stat32
#defina _tstat32i64 _stat32i64
#defina _tstat64 _stat64
#defina _tstat64i32 _stat64i32
#defina _tstati64 _stati64

#defina _tsetlocale setlocale

#se_definido _MBCS

#se_definido __cplusplus
}
#fim_se

#inclua <mbstring.h>

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido __TCHAR_DEFINED
  defina_tipo caractere _TCHAR;
  defina_tipo sinalizado caractere _TSCHAR;
  defina_tipo sem_sinal caractere _TUCHAR;
  defina_tipo sem_sinal caractere _TXCHAR;
  defina_tipo sem_sinal inteiro _TINT;
#defina __TCHAR_DEFINED
#fim_se

#se_não_definido _TCHAR_DEFINED
#se_não_definido	NO_OLDNAMES
  defina_tipo caractere TCHAR;
#fim_se
#defina _TCHAR_DEFINED
#fim_se

#se_definido _MB_MAP_DIRECT

#defina _tcschr _mbschr
#defina _tcscspn _mbscspn
#defina _tcsncat _mbsnbcat
#defina _tcsncat_l _mbsnbcat_l
#defina _tcsncpy _mbsnbcpy
#defina _tcsncpy_l _mbsnbcpy_l
#defina _tcspbrk _mbspbrk
#defina _tcsrchr _mbsrchr
#defina _tcsspn _mbsspn
#defina _tcsstr _mbsstr
#defina _tcstok _mbstok
#defina _tcstok_l _mbstok_l

#defina _tcsnset _mbsnbset
#defina _tcsnset_l _mbsnbset_l
#defina _tcsrev _mbsrev
#defina _tcsset _mbsset
#defina _tcsset_l _mbsset_l

#defina _tcscmp _mbscmp
#defina _tcsicmp _mbsicmp
#defina _tcsicmp_l _mbsicmp_l
#defina _tcsnccmp _mbsncmp
#defina _tcsncmp _mbsnbcmp
#defina _tcsncicmp _mbsnicmp
#defina _tcsncicmp_l _mbsnicmp_l
#defina _tcsnicmp _mbsnbicmp
#defina _tcsnicmp_l _mbsnbicmp_l

#defina _tcscoll _mbscoll
#defina _tcscoll_l _mbscoll_l
#defina _tcsicoll _mbsicoll
#defina _tcsicoll_l _mbsicoll_l
#defina _tcsnccoll _mbsncoll
#defina _tcsnccoll_l _mbsncoll_l
#defina _tcsncoll _mbsnbcoll
#defina _tcsncoll_l _mbsnbcoll_l
#defina _tcsncicoll _mbsnicoll
#defina _tcsncicoll_l _mbsnicoll_l
#defina _tcsnicoll _mbsnbicoll
#defina _tcsnicoll_l _mbsnbicoll_l

#defina _tcsclen _mbslen
#defina _tcscnlen _mbsnlen
#defina _tcsclen_l _mbslen_l
#defina _tcscnlen_l _mbsnlen_l
#defina _tcsnccat _mbsncat
#defina _tcsnccat_l _mbsncat_l
#defina _tcsnccpy _mbsncpy
#defina _tcsnccpy_l _mbsncpy_l
#defina _tcsncset _mbsnset
#defina _tcsncset_l _mbsnset_l

#defina _tcsdec _mbsdec
#defina _tcsinc _mbsinc
#defina _tcsnbcnt _mbsnbcnt
#defina _tcsnccnt _mbsnccnt
#defina _tcsnextc _mbsnextc
#defina _tcsninc _mbsninc
#defina _tcsspnp _mbsspnp

#defina _tcslwr _mbslwr
#defina _tcslwr_l _mbslwr_l
#defina _tcsupr _mbsupr
#defina _tcsupr_l _mbsupr_l

#defina _tclen _mbclen
#defina _ctecpy _mbccpy
#defina _ctecpy_l _mbccpy_l
#senão

  _CRTIMP _CONST_RETURN caractere *__cdecl _tcschr(constante caractere *_Str,sem_sinal inteiro _Val);
  _CRTIMP size_t __cdecl _tcscspn(constante caractere *_Str,constante caractere *_Control);
  _CRTIMP caractere *__cdecl _tcsncat(caractere *_Dst,constante caractere *_Src,size_t _MaxCount);
  _CRTIMP caractere *__cdecl _tcsncat_l(caractere *_Dst,constante caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP caractere *__cdecl _tcsncpy(caractere *_Dst,constante caractere *_Src,size_t _MaxCount);
  _CRTIMP caractere *__cdecl _tcsncpy_l(caractere *_Dst,constante caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP _CONST_RETURN caractere *__cdecl _tcspbrk(constante caractere *_Str,constante caractere *_Control);
  _CRTIMP _CONST_RETURN caractere *__cdecl _tcsrchr(constante caractere *_Str,sem_sinal inteiro _Ch);
  _CRTIMP size_t __cdecl _tcsspn(constante caractere *_Str,constante caractere *_Control);
  _CRTIMP _CONST_RETURN caractere *__cdecl _tcsstr(constante caractere *_Str,constante caractere *_Substr);
  _CRTIMP caractere *__cdecl _tcstok(caractere *_Str,constante caractere *_Delim);
  _CRTIMP caractere *__cdecl _tcstok_l(caractere *_Str,constante caractere *_Delim,_locale_t _Locale);
  _CRTIMP caractere *__cdecl _tcsnset(caractere *_Str,sem_sinal inteiro _Val,size_t _MaxCount);
  _CRTIMP caractere *__cdecl _tcsrev(caractere *_Str);
  _CRTIMP caractere *__cdecl _tcsset(caractere *_Str,sem_sinal inteiro _Val);
  _CRTIMP caractere *__cdecl _tcsset_l(caractere *_Str,sem_sinal inteiro _Val,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _tcscmp(constante caractere *_Str1,constante caractere *_Str);
  _CRTIMP inteiro __cdecl _tcsicmp(constante caractere *_Str1,constante caractere *_Str2);
  _CRTIMP inteiro __cdecl _tcsicmp_l(constante caractere *_Str1,constante caractere *_Str2,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _tcsnccmp(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _tcsncmp(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _tcsncicmp(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _tcsncicmp_l(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _tcsnicmp(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _tcsnicmp_l(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _tcscoll(constante caractere *_Str1,constante caractere *_Str2);
  _CRTIMP inteiro __cdecl _tcscoll_l(constante caractere *_Str1,constante caractere *_Str2,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _tcsicoll(constante caractere *_Str1,constante caractere *_Str2);
  _CRTIMP inteiro __cdecl _tcsicoll_l(constante caractere *_Str1,constante caractere *_Str2,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _tcsnccoll(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _tcsnccoll_l(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _tcsncoll(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _tcsncoll_l(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _tcsncicoll(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _tcsncicoll_l(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _tcsnicoll(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _tcsnicoll_l(constante caractere *_Str1,constante caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP size_t __cdecl _tcsclen(constante caractere *_Str);
  _CRTIMP size_t __cdecl _tcscnlen(constante caractere *_Str,size_t _MaxCount);
  _CRTIMP size_t __cdecl _tcsclen_l(constante caractere *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _tcscnlen_l(constante caractere *_Str,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP caractere *__cdecl _tcsnccat(caractere *_Dst,constante caractere *_Src,size_t _MaxCount);
  _CRTIMP caractere *__cdecl _tcsnccat_l(caractere *_Dst,constante caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP caractere *__cdecl _tcsnccpy(caractere *_Dst,constante caractere *_Src,size_t _MaxCount);
  _CRTIMP caractere *__cdecl _tcsnccpy_l(caractere *_Dst,constante caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP caractere *__cdecl _tcsncset(caractere *_Str,sem_sinal inteiro _Val,size_t _MaxCount);
  _CRTIMP caractere *__cdecl _tcsdec(constante caractere *_Start,constante caractere *_Pos);
  _CRTIMP caractere *__cdecl _tcsinc(constante caractere *_Ptr);
  _CRTIMP size_t __cdecl _tcsnbcnt(constante caractere *_Str,size_t _MaxCount);
  _CRTIMP size_t __cdecl _tcsnccnt(constante caractere *_Str,size_t _MaxCount);
  _CRTIMP sem_sinal inteiro __cdecl _tcsnextc (constante caractere *_Str);
  _CRTIMP caractere *__cdecl _tcsninc(constante caractere *_Ptr,size_t _Count);
  _CRTIMP caractere *__cdecl _tcsspnp(constante caractere *_Str1,constante caractere *_Str2);
  _CRTIMP caractere *__cdecl _tcslwr(caractere *_Str);
  _CRTIMP caractere *__cdecl _tcslwr_l(caractere *_Str,_locale_t _Locale);
  _CRTIMP caractere *__cdecl _tcsupr(caractere *_Str);
  _CRTIMP caractere *__cdecl _tcsupr_l(caractere *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _tclen(constante caractere *_Str);
  _CRTIMP vazio __cdecl _ctecpy(caractere *_DstCh,constante caractere *_SrcCh);

#se_definido __cplusplus
#se_não_definido _CPP_TCHAR_INLINES_DEFINED
#defina _CPP_TCHAR_INLINES_DEFINED
  externo "C++" {
    externo em_linha caractere *__cdecl _tcschr(caractere *_S,sem_sinal inteiro _C) { retorne ((caractere *)_tcschr((constante caractere *)_S,_C)); }
    externo em_linha caractere *__cdecl _tcspbrk(caractere *_S,constante caractere *_P) { retorne ((caractere *)_tcspbrk((constante caractere *)_S,_P)); }
    externo em_linha caractere *__cdecl _tcsrchr(caractere *_S,sem_sinal inteiro _C) { retorne ((caractere *)_tcsrchr((constante caractere *)_S,_C)); }
    externo em_linha caractere *__cdecl _tcsstr(caractere *_S,constante caractere *_P) { retorne ((caractere *)_tcsstr((constante caractere *)_S,_P)); }
  }
#fim_se
#fim_se
#fim_se

#defina _ctecmp(_cp1,_cp2) _tcsnccmp(_cp1,_cp2,1)

#defina _istalnum _ismbcalnum
#defina _istalnum_l _ismbcalnum_l
#defina _istalpha _ismbcalpha
#defina _istalpha_l _ismbcalpha_l
#defina _istdigit _ismbcdigit
#defina _istdigit_l _ismbcdigit_l
#defina _istgraph _ismbcgraph
#defina _istgraph_l _ismbcgraph_l
#defina _istlegal _ismbclegal
#defina _istlegal_l _ismbclegal_l
#defina _istlower _ismbclower
#defina _istlower_l _ismbclower_l
#defina _istprint _ismbcprint
#defina _istprint_l _ismbcprint_l
#defina _istpunct _ismbcpunct
#defina _istpunct_l _ismbcpunct_l
#defina _istspace _ismbcspace
#defina _istspace_l _ismbcspace_l
#defina _istupper _ismbcupper
#defina _istupper_l _ismbcupper_l

#defina _totupper _mbctoupper
#defina _totupper_l _mbctoupper_l
#defina _totlower _mbctolower
#defina _totlower_l _mbctolower_l

#defina _istlead _ismbblead
#defina _istleadbyte isleadbyte
#defina _istleadbyte_l _isleadbyte_l
#senão

#se_não_definido __TCHAR_DEFINED
#defina __TCHAR_DEFINED
  defina_tipo caractere _TCHAR;
  defina_tipo sinalizado caractere _TSCHAR;
  defina_tipo sem_sinal caractere _TUCHAR;
  defina_tipo caractere _TXCHAR;
  defina_tipo inteiro _TINT;
#fim_se

#se_não_definido _TCHAR_DEFINED
#defina _TCHAR_DEFINED
#se_não_definido	NO_OLDNAMES
  defina_tipo caractere TCHAR;
#fim_se
#fim_se

#defina _tcschr strchr
#defina _tcscspn strcspn
#defina _tcsncat strncat
#defina _tcsncat_l _strncat_l
#defina _tcsncpy strncpy
#defina _tcsncpy_l _strncpy_l
#defina _tcspbrk strpbrk
#defina _tcsrchr strrchr
#defina _tcsspn strspn
#defina _tcsstr strstr
#defina _tcstok strtok
#defina _tcstok_l _strtok_l

#defina _tcsnset _strnset
#defina _tcsnset_l _strnset_l
#defina _tcsrev _strrev
#defina _tcsset _strset

#defina _tcscmp strcmp
#defina _tcsicmp _stricmp
#defina _tcsicmp_l _stricmp_l
#defina _tcsnccmp strncmp
#defina _tcsncmp strncmp
#defina _tcsncicmp _strnicmp
#defina _tcsncicmp_l _strnicmp_l
#defina _tcsnicmp _strnicmp
#defina _tcsnicmp_l _strnicmp_l

#defina _tcscoll strcoll
#defina _tcscoll_l _strcoll_l
#defina _tcsicoll _stricoll
#defina _tcsicoll_l _stricoll_l
#defina _tcsnccoll _strncoll
#defina _tcsnccoll_l _strncoll_l
#defina _tcsncoll _strncoll
#defina _tcsncoll_l _strncoll_l
#defina _tcsncicoll _strnicoll
#defina _tcsncicoll_l _strnicoll_l
#defina _tcsnicoll _strnicoll
#defina _tcsnicoll_l _strnicoll_l

#defina _tcsclen strlen
#defina _tcscnlen strnlen
#defina _tcsclen_l(_String,_Locale) strlen(_String)
#defina _tcscnlen_l(_String,_Max_count,_Locale) strnlen_l((_String),(_Max_count))
#defina _tcsnccat strncat
#defina _tcsnccat_l _strncat_l
#defina _tcsnccpy strncpy
#defina _tcsnccpy_l _strncpy_l
#defina _tcsncset _strnset

#defina _tcsdec _strdec
#defina _tcsinc _strinc
#defina _tcsnbcnt _strncnt
#defina _tcsnccnt _strncnt
#defina _tcsnextc _strnextc
#defina _tcsninc _strninc
#defina _tcsspnp _strspnp

#defina _tcslwr _strlwr
#defina _tcslwr_l _strlwr_l
#defina _tcsupr _strupr
#defina _tcsupr_l _strupr_l
#defina _tcsxfrm strxfrm
#defina _tcsxfrm_l _strxfrm_l

#defina _istlead(_Char) (0)
#defina _istleadbyte(_Char) (0)
#defina _istleadbyte_l(_Char,_Locale) (0)

#defina _tclen(_pc) (1)
#defina _ctecpy(_pc1,_cpc2) (*(_pc1) = *(_cpc2))
#defina _ctecmp(_cpc1,_cpc2) (((sem_sinal caractere)*(_cpc1))-((sem_sinal caractere)*(_cpc2)))

  /* dirent structures and functions */
#defina _tdirent	dirent
#defina _TDIR 		DIR
#defina _topendir	opendir
#defina _tclosedir	closedir
#defina _treaddir	readdir
#defina _trewinddir	rewinddir
#defina _ttelldir	telldir
#defina _tseekdir	seekdir

#defina _istalnum isalnum
#defina _istalnum_l _isalnum_l
#defina _istalpha isalpha
#defina _istalpha_l _isalpha_l
#defina _istdigit isdigit
#defina _istdigit_l _isdigit_l
#defina _istgraph isgraph
#defina _istgraph_l _isgraph_l
#defina _istlower islower
#defina _istlower_l _islower_l
#defina _istprint isprint
#defina _istprint_l _isprint_l
#defina _istpunct ispunct
#defina _istpunct_l _ispunct_l
#defina _istspace isspace
#defina _istspace_l _isspace_l
#defina _istupper isupper
#defina _istupper_l _isupper_l

#defina _totupper toupper
#defina _totupper_l _toupper_l
#defina _totlower tolower
#defina _totlower_l _tolower_l

#defina _istlegal(_c) (1)

#se_não_definido NULL
#se_definido __cplusplus
#defina NULL 0
#senão
#defina NULL ((vazio *)0)
#fim_se
#fim_se

#defina _strdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? NULL : (_cpc2)-1)
#defina _strinc(_pc) ((_pc)+1)
#defina _strnextc(_cpc) ((sem_sinal inteiro) *(constante sem_sinal caractere *)(_cpc))
#defina _strninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP size_t __cdecl __strncnt(constante caractere *_Str,size_t _Cnt);
#defina _strncnt(_cpc,_sz) (__strncnt(_cpc,_sz))
#defina _strspnp(_cpc1,_cpc2) (!_cpc1 ? NULL : ((*((_cpc1)+strspn(_cpc1,_cpc2))) ? ((_cpc1)+strspn(_cpc1,_cpc2)) : NULL))

#defina _strncpy_l(_Destination,_Source,_Count,_Locale) (strncpy(_Destination,_Source,_Count))
#defina _strncat_l(_Destination,_Source,_Count,_Locale) (strncat(_Destination,_Source,_Count))
#defina _strtok_l(_String,_Delimiters,_Locale) (strtok(_String,_Delimiters))
#defina _strnset_l(_Destination,_Value,_Count,_Locale) (_strnset(_Destination,_Value,_Count))
#defina _strset_l(_Destination,_Value,_Locale) (_strset(_Destination,_Value))
#fim_se
#fim_se

#defina _T(x) __T(x)
#defina _TEXT(x) __T(x)

#se_definido __cplusplus
}
#fim_se

#inclua <sec_api/tchar_s.h>
#fim_se
