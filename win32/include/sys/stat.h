/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_STAT
#defina _INC_STAT

#se_não_definido _WIN32
#erro Only Win32 target is supported!
#fim_se

#inclua <_mingw.h>
#inclua <io.h>

#diretiva pack(push,_CRT_PACKING)

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _CRTIMP
#defina _CRTIMP __declspec(importe_dll)
#fim_se

#inclua <sys/types.h>

#se_não_definido __TINYC__ /* gr */
#se_definido _USE_32BIT_TIME_T
#se_definido _WIN64
#não_definido _USE_32BIT_TIME_T
#fim_se
#senão
#se _INTEGRAL_MAX_BITS < 64
#defina _USE_32BIT_TIME_T
#fim_se
#fim_se
#fim_se

#se_não_definido _TIME32_T_DEFINED
  defina_tipo longo __time32_t;
#defina _TIME32_T_DEFINED
#fim_se

#se_não_definido _TIME64_T_DEFINED
#se _INTEGRAL_MAX_BITS >= 64
  defina_tipo __int64 __time64_t;
#fim_se
#defina _TIME64_T_DEFINED
#fim_se

#se_não_definido _TIME_T_DEFINED
#se_definido _USE_32BIT_TIME_T
  defina_tipo __time32_t time_t;
#senão
  defina_tipo __time64_t time_t;
#fim_se
#defina _TIME_T_DEFINED
#fim_se

#se_não_definido _WCHAR_T_DEFINED
  defina_tipo sem_sinal curto wchar_t;
#defina _WCHAR_T_DEFINED
#fim_se

#se_não_definido _STAT_DEFINED

#se_definido _USE_32BIT_TIME_T
#se_não_definido _WIN64
#defina _fstat32 _fstat
#defina _stat32 _stat
#defina _wstat32 _wstat
#senão
#defina _fstat _fstat32
#defina _stat _stat32
#defina _wstat _wstat32
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

#defina _STAT_DEFINED
#fim_se

#defina _S_IFMT 0xF000
#defina _S_IFDIR 0x4000
#defina _S_IFCHR 0x2000
#defina _S_IFIFO 0x1000
#defina _S_IFREG 0x8000
#defina _S_IREAD 0x0100
#defina _S_IWRITE 0x0080
#defina _S_IEXEC 0x0040

  _CRTIMP inteiro __cdecl _fstat32(inteiro _FileDes,estrutura _stat32 *_Stat);
  _CRTIMP inteiro __cdecl _stat32(constante caractere *_Name,estrutura _stat32 *_Stat);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP inteiro __cdecl _fstat64(inteiro _FileDes,estrutura _stat64 *_Stat);
  _CRTIMP inteiro __cdecl _fstat32i64(inteiro _FileDes,estrutura _stat32i64 *_Stat);
  inteiro __cdecl _fstat64i32(inteiro _FileDes,estrutura _stat64i32 *_Stat);
  __CRT_INLINE inteiro __cdecl _fstat64i32(inteiro _FileDes,estrutura _stat64i32 *_Stat)
  {
    estrutura _stat64 st;
    inteiro ret=_fstat64(_FileDes,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_mode=st.st_mode;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_size=(_off_t) st.st_size;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    retorne ret;
  }
  _CRTIMP inteiro __cdecl _stat64(constante caractere *_Name,estrutura _stat64 *_Stat);
  _CRTIMP inteiro __cdecl _stat32i64(constante caractere *_Name,estrutura _stat32i64 *_Stat);
  inteiro __cdecl _stat64i32(constante caractere *_Name,estrutura _stat64i32 *_Stat);
  __CRT_INLINE inteiro __cdecl _stat64i32(constante caractere *_Name,estrutura _stat64i32 *_Stat)
  {
    estrutura _stat64 st;
    inteiro ret=_stat64(_Name,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_mode=st.st_mode;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_size=(_off_t) st.st_size;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    retorne ret;
  }
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

#se_não_definido	NO_OLDNAMES
#defina	_S_IFBLK	0x3000	/* Block: Is this ever set under w32? */

#defina S_IFMT _S_IFMT
#defina S_IFDIR _S_IFDIR
#defina S_IFCHR _S_IFCHR
#defina S_IFREG _S_IFREG
#defina S_IREAD _S_IREAD
#defina S_IWRITE _S_IWRITE
#defina S_IEXEC _S_IEXEC
#defina	S_IFIFO		_S_IFIFO
#defina	S_IFBLK		_S_IFBLK

#defina	_S_IRWXU	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#defina	_S_IXUSR	_S_IEXEC
#defina	_S_IWUSR	_S_IWRITE

#defina	S_IRWXU		_S_IRWXU
#defina	S_IXUSR		_S_IXUSR
#defina	S_IWUSR		_S_IWUSR
#defina	S_IRUSR		_S_IRUSR
#defina	_S_IRUSR	_S_IREAD

#defina	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#defina	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#defina	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#defina	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#defina	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

#fim_se

#se !definido (RC_INVOKED) && !definido (NO_OLDNAMES)
inteiro __cdecl stat(constante caractere *_Filename,estrutura stat *_Stat);
inteiro __cdecl fstat(inteiro _Desc,estrutura stat *_Stat);
inteiro __cdecl wstat(constante wchar_t *_Filename,estrutura stat *_Stat);
#se_definido _USE_32BIT_TIME_T
__CRT_INLINE inteiro __cdecl fstat(inteiro _Desc,estrutura stat *_Stat) {
  retorne _fstat32(_Desc,(estrutura _stat32 *)_Stat);
}
__CRT_INLINE inteiro __cdecl stat(constante caractere *_Filename,estrutura stat *_Stat) {
  retorne _stat32(_Filename,(estrutura _stat32 *)_Stat);
}
#senão
__CRT_INLINE inteiro __cdecl fstat(inteiro _Desc,estrutura stat *_Stat) {
  retorne _fstat64i32(_Desc,(estrutura _stat64i32 *)_Stat);
}
__CRT_INLINE inteiro __cdecl stat(constante caractere *_Filename,estrutura stat *_Stat) {
  retorne _stat64i32(_Filename,(estrutura _stat64i32 *)_Stat);
}
#fim_se
#fim_se

#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)
#fim_se
