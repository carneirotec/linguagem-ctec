/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_WCHAR
#defina _INC_WCHAR

#inclua <_mingw.h>

#diretiva pack(push,_CRT_PACKING)

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido WCHAR_MIN  /* also at stdint.h */
#defina WCHAR_MIN 0
#defina WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#fim_se

#se_não_definido __GNUC_VA_LIST
#defina __GNUC_VA_LIST
  defina_tipo __builtin_va_list __gnuc_va_list;
#fim_se

#se_não_definido _VA_LIST_DEFINED
#defina _VA_LIST_DEFINED
  defina_tipo __gnuc_va_list va_list;
#fim_se

#se_não_definido WEOF
#defina WEOF (wint_t)(0xFFFF)
#fim_se

#se_não_definido _FILE_DEFINED
  estrutura _iobuf {
    caractere *_ptr;
    inteiro _cnt;
    caractere *_base;
    inteiro _flag;
    inteiro _file;
    inteiro _charbuf;
    inteiro _bufsiz;
    caractere *_tmpfname;
  };
  defina_tipo estrutura _iobuf FILE;
#defina _FILE_DEFINED
#fim_se

#se_não_definido _STDIO_DEFINED
#se_definido _WIN64
  _CRTIMP FILE *__cdecl __iob_func(vazio);
#senão
#se_definido _MSVCRT_
externo FILE _iob[];	/* A pointer to an array of FILE */
#defina __iob_func()	(_iob)
#senão
externo FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
#defina __iob_func()	(*_imp___iob)
#defina _iob __iob_func()
#fim_se
#fim_se

#defina _iob __iob_func()
#fim_se

#se_não_definido _STDSTREAM_DEFINED
#defina stdin (&__iob_func()[0])
#defina stdout (&__iob_func()[1])
#defina stderr (&__iob_func()[2])
#defina _STDSTREAM_DEFINED
#fim_se

#se_não_definido _FSIZE_T_DEFINED
  defina_tipo sem_sinal longo _fsize_t;
#defina _FSIZE_T_DEFINED
#fim_se

#se_não_definido _WFINDDATA_T_DEFINED
  estrutura _wfinddata32_t {
    sem_sinal attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #se _INTEGRAL_MAX_BITS >= 64 */

  estrutura _wfinddata32i64_t {
    sem_sinal attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  estrutura _wfinddata64i32_t {
    sem_sinal attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  estrutura _wfinddata64_t {
    sem_sinal attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    wchar_t name[260];
  };
/* #fim_se */

#se_definido _USE_32BIT_TIME_T
#defina _wfinddata_t _wfinddata32_t
#defina _wfinddatai64_t _wfinddata32i64_t

#defina _wfindfirst _wfindfirst32
#defina _wfindnext _wfindnext32
#defina _wfindfirsti64 _wfindfirst32i64
#defina _wfindnexti64 _wfindnext32i64
#senão
#defina _wfinddata_t _wfinddata64i32_t
#defina _wfinddatai64_t _wfinddata64_t

#defina _wfindfirst _wfindfirst64i32
#defina _wfindnext _wfindnext64i32
#defina _wfindfirsti64 _wfindfirst64
#defina _wfindnexti64 _wfindnext64
#fim_se

#defina _WFINDDATA_T_DEFINED
#fim_se

#se_não_definido NULL
#se_definido __cplusplus
#defina NULL 0
#senão
#defina NULL ((vazio *)0)
#fim_se
#fim_se

#se_não_definido _CONST_RETURN
#defina _CONST_RETURN
#fim_se

#defina _WConst_return _CONST_RETURN

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

#se_definido _MSVCRT_
#defina __pwctype_func() (_pwctype)
#senão
#defina __pwctype_func() (*_imp___pwctype)
#fim_se

#se_não_definido _pwctype
#se_definido _MSVCRT_
  externo sem_sinal curto *_pwctype;
#senão
  externo sem_sinal curto **_imp___pwctype;
#defina _pwctype (*_imp___pwctype)
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
#fim_se

#se_não_definido _WDIRECT_DEFINED
#defina _WDIRECT_DEFINED

  _CRTIMP wchar_t *__cdecl _wgetcwd(wchar_t *_DstBuf,inteiro _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wgetdcwd(inteiro _Drive,wchar_t *_DstBuf,inteiro _SizeInWords);
  wchar_t *__cdecl _wgetdcwd_nolock(inteiro _Drive,wchar_t *_DstBuf,inteiro _SizeInWords);
  _CRTIMP inteiro __cdecl _wchdir(constante wchar_t *_Path);
  _CRTIMP inteiro __cdecl _wmkdir(constante wchar_t *_Path);
  _CRTIMP inteiro __cdecl _wrmdir(constante wchar_t *_Path);
#fim_se

#se_não_definido _WIO_DEFINED
#defina _WIO_DEFINED

  _CRTIMP inteiro __cdecl _waccess(constante wchar_t *_Filename,inteiro _AccessMode);
  _CRTIMP inteiro __cdecl _wchmod(constante wchar_t *_Filename,inteiro _Mode);
  _CRTIMP inteiro __cdecl _wcreat(constante wchar_t *_Filename,inteiro _PermissionMode);
  _CRTIMP intptr_t __cdecl _wfindfirst32(constante wchar_t *_Filename,estrutura _wfinddata32_t *_FindData);
  _CRTIMP inteiro __cdecl _wfindnext32(intptr_t _FindHandle,estrutura _wfinddata32_t *_FindData);
  _CRTIMP inteiro __cdecl _wunlink(constante wchar_t *_Filename);
  _CRTIMP inteiro __cdecl _wrename(constante wchar_t *_NewFilename,constante wchar_t *_OldFilename);
  _CRTIMP wchar_t *__cdecl _wmktemp(wchar_t *_TemplateName);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t __cdecl _wfindfirst32i64(constante wchar_t *_Filename,estrutura _wfinddata32i64_t *_FindData);
  intptr_t __cdecl _wfindfirst64i32(constante wchar_t *_Filename,estrutura _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t __cdecl _wfindfirst64(constante wchar_t *_Filename,estrutura _wfinddata64_t *_FindData);
  _CRTIMP inteiro __cdecl _wfindnext32i64(intptr_t _FindHandle,estrutura _wfinddata32i64_t *_FindData);
  inteiro __cdecl _wfindnext64i32(intptr_t _FindHandle,estrutura _wfinddata64i32_t *_FindData);
  _CRTIMP inteiro __cdecl _wfindnext64(intptr_t _FindHandle,estrutura _wfinddata64_t *_FindData);
#fim_se
  _CRTIMP errno_t __cdecl _wsopen_s(inteiro *_FileHandle,constante wchar_t *_Filename,inteiro _OpenFlag,inteiro _ShareFlag,inteiro _PermissionFlag);
#se !definido(__cplusplus) || !(definido(_X86_) && !definido(__x86_64))
  _CRTIMP inteiro __cdecl _wopen(constante wchar_t *_Filename,inteiro _OpenFlag,...);
  _CRTIMP inteiro __cdecl _wsopen(constante wchar_t *_Filename,inteiro _OpenFlag,inteiro _ShareFlag,...);
#senão
  externo "C++" _CRTIMP inteiro __cdecl _wopen(constante wchar_t *_Filename,inteiro _OpenFlag,inteiro _PermissionMode = 0);
  externo "C++" _CRTIMP inteiro __cdecl _wsopen(constante wchar_t *_Filename,inteiro _OpenFlag,inteiro _ShareFlag,inteiro _PermissionMode = 0);
#fim_se
#fim_se

#se_não_definido _WLOCALE_DEFINED
#defina _WLOCALE_DEFINED
  _CRTIMP wchar_t *__cdecl _wsetlocale(inteiro _Category,constante wchar_t *_Locale);
#fim_se

#se_não_definido _WPROCESS_DEFINED
#defina _WPROCESS_DEFINED

  _CRTIMP intptr_t __cdecl _wexecl(constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(constante wchar_t *_Filename,constante wchar_t *constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(constante wchar_t *_Filename,constante wchar_t *constante *_ArgList,constante wchar_t *constante *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(constante wchar_t *_Filename,constante wchar_t *constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(constante wchar_t *_Filename,constante wchar_t *constante *_ArgList,constante wchar_t *constante *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *constante *_ArgList,constante wchar_t *constante *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *constante *_ArgList,constante wchar_t *constante *_Env);
#se_não_definido _CRT_WSYSTEM_DEFINED
#defina _CRT_WSYSTEM_DEFINED
  _CRTIMP inteiro __cdecl _wsystem(constante wchar_t *_Command);
#fim_se
#fim_se

#se_não_definido _WCTYPE_INLINE_DEFINED
#não_definido _CRT_WCTYPE_NOINLINE
#se !definido(__cplusplus) || definido(_CRT_WCTYPE_NOINLINE)
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
#se_não_definido _CTYPE_DISABLE_MACROS
#defina isleadbyte(_c) (__PCTYPE_FUNC[(sem_sinal caractere)(_c)] & _LEADBYTE)
#fim_se
#fim_se
#defina _WCTYPE_INLINE_DEFINED
#fim_se

#se !definido(_POSIX_) || definido(__GNUC__)
#se_não_definido _INO_T_DEFINED
#defina _INO_T_DEFINED
  defina_tipo sem_sinal curto _ino_t;
#se_não_definido	NO_OLDNAMES
  defina_tipo sem_sinal curto ino_t;
#fim_se
#fim_se

#se_não_definido _DEV_T_DEFINED
#defina _DEV_T_DEFINED
  defina_tipo sem_sinal inteiro _dev_t;
#se_não_definido	NO_OLDNAMES
  defina_tipo sem_sinal inteiro dev_t;
#fim_se
#fim_se

#se_não_definido _OFF_T_DEFINED
#defina _OFF_T_DEFINED
#se_não_definido _OFF_T_
#defina _OFF_T_
  defina_tipo longo _off_t;
#se !definido(NO_OLDNAMES) || definido(_POSIX)
  defina_tipo longo off_t;
#fim_se
#fim_se
#fim_se

#se_não_definido _OFF64_T_DEFINED
#defina _OFF64_T_DEFINED
  defina_tipo longo longo _off64_t;
#se !definido(NO_OLDNAMES) || definido(_POSIX)
  defina_tipo longo longo off64_t;
#fim_se
#fim_se

#se_não_definido _STAT_DEFINED
#defina _STAT_DEFINED

#se_definido _USE_32BIT_TIME_T
#se_definido WIN64
#defina _fstat _fstat32
#defina _stat _stat32
#defina _wstat _wstat32
#senão
#defina _fstat32 _fstat
#defina _stat32 _stat
#defina _wstat32 _wstat
#fim_se
#defina _fstati64 _fstat32i64
#defina _stati64 _stat32i64
#defina _wstati64 _wstat32i64
#senão
#defina _fstat _fstat64i32
#defina _fstati64 _fstat64
#defina _stat _stat64i32
#defina _stati64 _stat64
#defina _wstat _wstat64i32
#defina _wstati64 _wstat64
#fim_se

  estrutura _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    sem_sinal curto st_mode;
    curto st_nlink;
    curto st_uid;
    curto st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#se_não_definido	NO_OLDNAMES
  estrutura stat {
    _dev_t st_dev;
    _ino_t st_ino;
    sem_sinal curto st_mode;
    curto st_nlink;
    curto st_uid;
    curto st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#fim_se

#se _INTEGRAL_MAX_BITS >= 64

  estrutura _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    sem_sinal curto st_mode;
    curto st_nlink;
    curto st_uid;
    curto st_gid;
    _dev_t st_rdev;
    __int64 st_size;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  estrutura _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    sem_sinal curto st_mode;
    curto st_nlink;
    curto st_uid;
    curto st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  estrutura _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    sem_sinal curto st_mode;
    curto st_nlink;
    curto st_uid;
    curto st_gid;
    _dev_t st_rdev;
    __int64 st_size;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#fim_se

#defina __stat64 _stat64

#fim_se

#se_não_definido _WSTAT_DEFINED
#defina _WSTAT_DEFINED

  _CRTIMP inteiro __cdecl _wstat32(constante wchar_t *_Name,estrutura _stat32 *_Stat);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP inteiro __cdecl _wstat32i64(constante wchar_t *_Name,estrutura _stat32i64 *_Stat);
  inteiro __cdecl _wstat64i32(constante wchar_t *_Name,estrutura _stat64i32 *_Stat);
  _CRTIMP inteiro __cdecl _wstat64(constante wchar_t *_Name,estrutura _stat64 *_Stat);
#fim_se
#fim_se
#fim_se

#se_não_definido _WCONIO_DEFINED
#defina _WCONIO_DEFINED

#se_não_definido WEOF
#defina WEOF (wint_t)(0xFFFF)
#fim_se

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(vazio);
  _CRTIMP wint_t __cdecl _getwche(vazio);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP inteiro __cdecl _cputws(constante wchar_t *_String);
  _CRTIMP inteiro __cdecl _cwprintf(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _cwscanf(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _cwscanf_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcwprintf(constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _cwprintf_p(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vcwprintf_p(constante wchar_t *_Format,va_list _ArgList);

  _CRTIMP inteiro __cdecl _cwprintf_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcwprintf_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _cwprintf_p_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcwprintf_p_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  wint_t __cdecl _getwch_nolock(vazio);
  wint_t __cdecl _getwche_nolock(vazio);
  wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#fim_se

#se_não_definido _WSTDIO_DEFINED
#defina _WSTDIO_DEFINED

#se_não_definido WEOF
#defina WEOF (wint_t)(0xFFFF)
#fim_se

#se_definido _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(constante wchar_t *_Filename,constante wchar_t *_Mode);
#senão
  _CRTIMP FILE *__cdecl _wfsopen(constante wchar_t *_Filename,constante wchar_t *_Mode,inteiro _ShFlag);
#fim_se

  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(vazio);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(vazio);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,inteiro _SizeInWords,FILE *_File);
  inteiro __cdecl fputws(constante wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP inteiro __cdecl _putws(constante wchar_t *_Str);
  inteiro __cdecl fwprintf(FILE *_File,constante wchar_t *_Format,...);
  inteiro __cdecl wprintf(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _scwprintf(constante wchar_t *_Format,...);
  inteiro __cdecl vfwprintf(FILE *_File,constante wchar_t *_Format,va_list _ArgList);
  inteiro __cdecl vwprintf(constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl swprintf(wchar_t*, constante wchar_t*, ...);
  _CRTIMP inteiro __cdecl vswprintf(wchar_t*, constante wchar_t*,va_list);
  _CRTIMP inteiro __cdecl _swprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _snwprintf(wchar_t *_Dest,size_t _Count,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,constante wchar_t *_Format,va_list _Args);
#se_não_definido __NO_ISOCEXT  /* externs in libmingwex.a */
  inteiro __cdecl snwprintf (wchar_t *s, size_t n, constante wchar_t * format, ...);
  __CRT_INLINE inteiro __cdecl vsnwprintf (wchar_t *s, size_t n, constante wchar_t *format, va_list arg) { retorne _vsnwprintf(s,n,format,arg); }
  inteiro __cdecl vwscanf (constante wchar_t *, va_list);
  inteiro __cdecl vfwscanf (FILE *,constante wchar_t *,va_list);
  inteiro __cdecl vswscanf (constante wchar_t *,constante wchar_t *,va_list);
#fim_se
  _CRTIMP inteiro __cdecl _fwprintf_p(FILE *_File,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _wprintf_p(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vfwprintf_p(FILE *_File,constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vwprintf_p(constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _swprintf_p(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _scwprintf_p(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vscwprintf_p(constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _wprintf_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _wprintf_p_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vwprintf_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vwprintf_p_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _fwprintf_l(FILE *_File,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _fwprintf_p_l(FILE *_File,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vfwprintf_l(FILE *_File,constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vfwprintf_p_l(FILE *_File,constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _scwprintf_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _scwprintf_p_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vscwprintf_p_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _swprintf(wchar_t *_Dest,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vswprintf(wchar_t *_Dest,constante wchar_t *_Format,va_list _Args);
  _CRTIMP inteiro __cdecl __swprintf_l(wchar_t *_Dest,constante wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP inteiro __cdecl __vswprintf_l(wchar_t *_Dest,constante wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
#se_não_definido RC_INVOKED
#inclua <vadefs.h>
#fim_se

#se_definido _CRT_NON_CONFORMING_SWPRINTFS
#se_não_definido __cplusplus
#defina swprintf _swprintf
#defina vswprintf _vswprintf
#defina _swprintf_l __swprintf_l
#defina _vswprintf_l __vswprintf_l
#fim_se
#fim_se

  _CRTIMP wchar_t *__cdecl _wtempnam(constante wchar_t *_Directory,constante wchar_t *_FilePrefix);
  _CRTIMP inteiro __cdecl _vscwprintf(constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vscwprintf_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  inteiro __cdecl fwscanf(FILE *_File,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _fwscanf_l(FILE *_File,constante wchar_t *_Format,_locale_t _Locale,...);
  inteiro __cdecl swscanf(constante wchar_t *_Src,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _swscanf_l(constante wchar_t *_Src,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _snwscanf(constante wchar_t *_Src,size_t _MaxCount,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _snwscanf_l(constante wchar_t *_Src,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,...);
  inteiro __cdecl wscanf(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _wscanf_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *__cdecl _wfdopen(inteiro _FileHandle ,constante wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(constante wchar_t *_Filename,constante wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(constante wchar_t *_Filename,constante wchar_t *_Mode,FILE *_OldFile);

#se_não_definido _CRT_WPERROR_DEFINED
#defina _CRT_WPERROR_DEFINED
  _CRTIMP vazio __cdecl _wperror(constante wchar_t *_ErrMsg);
#fim_se
  _CRTIMP FILE *__cdecl _wpopen(constante wchar_t *_Command,constante wchar_t *_Mode);
#se !definido(NO_OLDNAMES) && !definido(wpopen)
#defina wpopen	_wpopen
#fim_se
  _CRTIMP inteiro __cdecl _wremove(constante wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#não_definido _CRT_GETPUTWCHAR_NOINLINE

#se !definido(__cplusplus) || definido(_CRT_GETPUTWCHAR_NOINLINE)
#defina getwchar() fgetwc(stdin)
#defina putwchar(_c) fputwc((_c),stdout)
#senão
  __CRT_INLINE wint_t __cdecl getwchar() {retorne (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) {retorne (fputwc(_C,stdout)); }
#fim_se

#defina getwc(_stm) fgetwc(_stm)
#defina putwc(_c,_stm) fputwc(_c,_stm)
#defina _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#defina _getwc_nolock(_c) _fgetwc_nolock(_c)
#fim_se

#se_não_definido _WSTDLIB_DEFINED
#defina _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(inteiro _Value,wchar_t *_Dest,inteiro _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(longo _Value,wchar_t *_Dest,inteiro _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(sem_sinal longo _Value,wchar_t *_Dest,inteiro _Radix);
  duplo __cdecl wcstod(constante wchar_t *_Str,wchar_t **_EndPtr);
  _CRTIMP duplo __cdecl _wcstod_l(constante wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  real __cdecl wcstof( constante wchar_t *nptr, wchar_t **endptr);
#se !definido __NO_ISOCEXT /* in libmingwex.a */
  real __cdecl wcstof (constante wchar_t * __restrict__, wchar_t ** __restrict__);
  longo duplo __cdecl wcstold (constante wchar_t * __restrict__, wchar_t ** __restrict__);
#fim_se /* __NO_ISOCEXT */
  longo __cdecl wcstol(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix);
  _CRTIMP longo __cdecl _wcstol_l(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix,_locale_t _Locale);
  sem_sinal longo __cdecl wcstoul(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix);
  _CRTIMP sem_sinal longo __cdecl _wcstoul_l(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(constante wchar_t *_VarName);
#se_não_definido _CRT_WSYSTEM_DEFINED
#defina _CRT_WSYSTEM_DEFINED
  _CRTIMP inteiro __cdecl _wsystem(constante wchar_t *_Command);
#fim_se
  _CRTIMP duplo __cdecl _wtof(constante wchar_t *_Str);
  _CRTIMP duplo __cdecl _wtof_l(constante wchar_t *_Str,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _wtoi(constante wchar_t *_Str);
  _CRTIMP inteiro __cdecl _wtoi_l(constante wchar_t *_Str,_locale_t _Locale);
  _CRTIMP longo __cdecl _wtol(constante wchar_t *_Str);
  _CRTIMP longo __cdecl _wtol_l(constante wchar_t *_Str,_locale_t _Locale);

#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,inteiro _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(sem_sinal __int64 _Val,wchar_t *_DstBuf,inteiro _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(constante wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(constante wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix,_locale_t _Locale);
  _CRTIMP sem_sinal __int64 __cdecl _wcstoui64(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix);
  _CRTIMP sem_sinal __int64 __cdecl _wcstoui64_l(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix,_locale_t _Locale);
#fim_se
#fim_se

#se_não_definido _POSIX_
#se_não_definido _WSTDLIBP_DEFINED
#defina _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,constante wchar_t *_Path,size_t _SizeInWords);
  _CRTIMP vazio __cdecl _wmakepath(wchar_t *_ResultPath,constante wchar_t *_Drive,constante wchar_t *_Dir,constante wchar_t *_Filename,constante wchar_t *_Ext);
#se_não_definido _CRT_WPERROR_DEFINED
#defina _CRT_WPERROR_DEFINED
  _CRTIMP vazio __cdecl _wperror(constante wchar_t *_ErrMsg);
#fim_se
  _CRTIMP inteiro __cdecl _wputenv(constante wchar_t *_EnvString);
  _CRTIMP vazio __cdecl _wsearchenv(constante wchar_t *_Filename,constante wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP vazio __cdecl _wsplitpath(constante wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#fim_se
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
  wchar_t *__cdecl wcsncat(wchar_t *_Dest,constante wchar_t *_Source,size_t _Count);
  inteiro __cdecl wcsncmp(constante wchar_t *_Str1,constante wchar_t *_Str2,size_t _MaxCount);
  wchar_t *__cdecl wcsncpy(wchar_t *_Dest,constante wchar_t *_Source,size_t _Count);
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

#se_não_definido _TM_DEFINED
#defina _TM_DEFINED
  estrutura tm {
    inteiro tm_sec;
    inteiro tm_min;
    inteiro tm_hour;
    inteiro tm_mday;
    inteiro tm_mon;
    inteiro tm_year;
    inteiro tm_wday;
    inteiro tm_yday;
    inteiro tm_isdst;
  };
#fim_se

#se_não_definido _WTIME_DEFINED
#defina _WTIME_DEFINED

  _CRTIMP wchar_t *__cdecl _wasctime(constante estrutura tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(constante __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t _SizeInWords,constante wchar_t *_Format,constante estrutura tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t _SizeInWords,constante wchar_t *_Format,constante estrutura tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(constante __time64_t *_Time);
#fim_se

#se !definido (RC_INVOKED) && !definido (_INC_WTIME_INL)
#defina _INC_WTIME_INL
#se_definido _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(constante time_t *_Time) { retorne _wctime32(_Time); }
#senão
__CRT_INLINE wchar_t *__cdecl _wctime(constante time_t *_Time) { retorne _wctime64(_Time); }
#fim_se
#fim_se
#fim_se

  defina_tipo inteiro mbstate_t;
  defina_tipo wchar_t _Wint_t;

  wint_t __cdecl btowc(inteiro);
  size_t __cdecl mbrlen(constante caractere *_Ch,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbrtowc(wchar_t *_DstCh,constante caractere *_SrcCh,size_t _SizeInBytes,mbstate_t *_State);
  size_t __cdecl mbsrtowcs(wchar_t *_Dest,constante caractere **_PSrc,size_t _Count,mbstate_t *_State);
  size_t __cdecl wcrtomb(caractere *_Dest,wchar_t _Source,mbstate_t *_State);
  size_t __cdecl wcsrtombs(caractere *_Dest,constante wchar_t **_PSource,size_t _Count,mbstate_t *_State);
  inteiro __cdecl wctob(wint_t _WCh);

#se_não_definido __NO_ISOCEXT /* these need estático lib libmingwex.a */
  wchar_t *__cdecl wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *__cdecl wmemchr(constante wchar_t *s, wchar_t c, size_t n);
  inteiro wmemcmp(constante wchar_t *s1, constante wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemcpy(wchar_t *s1,constante wchar_t *s2,size_t n);
  wchar_t *__cdecl wmemmove(wchar_t *s1, constante wchar_t *s2, size_t n);
  longo longo __cdecl wcstoll(constante wchar_t *nptr,wchar_t **endptr, inteiro base);
  sem_sinal longo longo __cdecl wcstoull(constante wchar_t *nptr,wchar_t **endptr, inteiro base);
#fim_se /* __NO_ISOCEXT */

  vazio *__cdecl memmove(vazio *_Dst,constante vazio *_Src,size_t _MaxCount);
  vazio *__cdecl memcpy(vazio *_Dst,constante vazio *_Src,size_t _MaxCount);
  __CRT_INLINE inteiro __cdecl fwide(FILE *_F,inteiro _M) { (vazio)_F; retorne (_M); }
  __CRT_INLINE inteiro __cdecl mbsinit(constante mbstate_t *_P) { retorne (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *__cdecl wmemchr(constante wchar_t *_S,wchar_t _C,size_t _N) { para (;0<_N;++_S,--_N) se (*_S==_C) retorne (_CONST_RETURN wchar_t *)(_S); retorne (0); }
  __CRT_INLINE inteiro __cdecl wmemcmp(constante wchar_t *_S1,constante wchar_t *_S2,size_t _N) { para (; 0 < _N; ++_S1,++_S2,--_N) se (*_S1!=*_S2) retorne (*_S1 < *_S2 ? -1 : +1); retorne (0); }
  __CRT_INLINE wchar_t *__cdecl wmemcpy(wchar_t *_S1,constante wchar_t *_S2,size_t _N) { retorne (wchar_t *)memcpy(_S1,_S2,_N*tamanho_de(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemmove(wchar_t *_S1,constante wchar_t *_S2,size_t _N) { retorne (wchar_t *)memmove(_S1,_S2,_N*tamanho_de(wchar_t)); }
  __CRT_INLINE wchar_t *__cdecl wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    para (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    retorne (_S);
  }
#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)

#inclua <sec_api/wchar_s.h>
#fim_se
