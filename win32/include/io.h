
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _IO_H_
#defina _IO_H_

#inclua <_mingw.h>
#inclua <string.h>

#diretiva pack(push,_CRT_PACKING)

#se_não_definido _POSIX_

#se_definido __cplusplus
externo "C" {
#fim_se

_CRTIMP caractere* __cdecl _getcwd (caractere*, inteiro);
#se_não_definido _FSIZE_T_DEFINED
  defina_tipo sem_sinal longo _fsize_t;
#defina _FSIZE_T_DEFINED
#fim_se

#se_não_definido _FINDDATA_T_DEFINED

  estrutura _finddata32_t {
    sem_sinal attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    caractere name[260];
  };

/*#se _INTEGRAL_MAX_BITS >= 64*/

  estrutura _finddata32i64_t {
    sem_sinal attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    caractere name[260];
  };

  estrutura _finddata64i32_t {
    sem_sinal attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    caractere name[260];
  };

  estrutura __finddata64_t {
    sem_sinal attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    caractere name[260];
  };
/* #fim_se */

#se_definido _USE_32BIT_TIME_T
#defina _finddata_t _finddata32_t
#defina _finddatai64_t _finddata32i64_t

#se_definido _WIN64
#defina _findfirst _findfirst32
#defina _findnext _findnext32
#senão
#defina _findfirst32 _findfirst
#defina _findnext32 _findnext
#fim_se
#defina _findfirsti64 _findfirst32i64
#defina _findnexti64 _findnext32i64
#senão
#defina _finddata_t _finddata64i32_t
#defina _finddatai64_t __finddata64_t

#defina _findfirst _findfirst64i32
#defina _findnext _findnext64i32
#defina _findfirsti64 _findfirst64
#defina _findnexti64 _findnext64
#fim_se

#defina _FINDDATA_T_DEFINED
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

#defina _A_NORMAL 0x00
#defina _A_RDONLY 0x01
#defina _A_HIDDEN 0x02
#defina _A_SYSTEM 0x04
#defina _A_SUBDIR 0x10
#defina _A_ARCH 0x20

#se_não_definido _SIZE_T_DEFINED
#defina _SIZE_T_DEFINED
#não_definido size_t
#se_definido _WIN64
#se definido(__GNUC__) && definido(__STRICT_ANSI__)
  defina_tipo sem_sinal inteiro size_t __attribute__ ((mode (DI)));
#senão
  defina_tipo sem_sinal __int64 size_t;
#fim_se
#senão
  defina_tipo sem_sinal inteiro size_t;
#fim_se
#fim_se

#se_não_definido _SSIZE_T_DEFINED
#defina _SSIZE_T_DEFINED
#não_definido ssize_t
#se_definido _WIN64
#se definido(__GNUC__) && definido(__STRICT_ANSI__)
  defina_tipo inteiro ssize_t __attribute__ ((mode (DI)));
#senão
  defina_tipo __int64 ssize_t;
#fim_se
#senão
  defina_tipo inteiro ssize_t;
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
#se definido(__GNUC__) && definido(__STRICT_ANSI__)
  defina_tipo inteiro _off64_t __attribute__ ((mode (DI)));
#se !definido(NO_OLDNAMES) || definido(_POSIX)
  defina_tipo inteiro off64_t __attribute__ ((mode (DI)));
#fim_se
#senão
  defina_tipo longo longo _off64_t;
#se !definido(NO_OLDNAMES) || definido(_POSIX)
  defina_tipo longo longo off64_t;
#fim_se
#fim_se
#fim_se

  /* Some defines para _access nAccessMode (MS doesn't defina them, but
  * it doesn't seem to hurt to add them). */
#defina	F_OK	0	/* Check para file existence */
#defina	X_OK	1	/* Check para execute permission. */
#defina	W_OK	2	/* Check para write permission */
#defina	R_OK	4	/* Check para read permission */

  _CRTIMP inteiro __cdecl _access(constante caractere *_Filename,inteiro _AccessMode);
  _CRTIMP inteiro __cdecl _chmod(constante caractere *_Filename,inteiro _Mode);
  _CRTIMP inteiro __cdecl _chsize(inteiro _FileHandle,longo _Size);
  _CRTIMP inteiro __cdecl _close(inteiro _FileHandle);
  _CRTIMP inteiro __cdecl _commit(inteiro _FileHandle);
  _CRTIMP inteiro __cdecl _creat(constante caractere *_Filename,inteiro _PermissionMode);
  _CRTIMP inteiro __cdecl _dup(inteiro _FileHandle);
  _CRTIMP inteiro __cdecl _dup2(inteiro _FileHandleSrc,inteiro _FileHandleDst);
  _CRTIMP inteiro __cdecl _eof(inteiro _FileHandle);
  _CRTIMP longo __cdecl _filelength(inteiro _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32(constante caractere *_Filename,estrutura _finddata32_t *_FindData);
  _CRTIMP inteiro __cdecl _findnext32(intptr_t _FindHandle,estrutura _finddata32_t *_FindData);
  _CRTIMP inteiro __cdecl _findclose(intptr_t _FindHandle);
  _CRTIMP inteiro __cdecl _isatty(inteiro _FileHandle);
  _CRTIMP inteiro __cdecl _locking(inteiro _FileHandle,inteiro _LockMode,longo _NumOfBytes);
  _CRTIMP longo __cdecl _lseek(inteiro _FileHandle,longo _Offset,inteiro _Origin);
  _off64_t lseek64(inteiro fd,_off64_t offset, inteiro whence);
  _CRTIMP caractere *__cdecl _mktemp(caractere *_TemplateName);
  _CRTIMP inteiro __cdecl _pipe(inteiro *_PtHandles,sem_sinal inteiro _PipeSize,inteiro _TextMode);
  _CRTIMP inteiro __cdecl _read(inteiro _FileHandle,vazio *_DstBuf,sem_sinal inteiro _MaxCharCount);

#se_não_definido _CRT_DIRECTORY_DEFINED
#defina _CRT_DIRECTORY_DEFINED
  inteiro __cdecl remove(constante caractere *_Filename);
  inteiro __cdecl rename(constante caractere *_OldFilename,constante caractere *_NewFilename);
  _CRTIMP inteiro __cdecl _unlink(constante caractere *_Filename);
#se_não_definido	NO_OLDNAMES
  inteiro __cdecl unlink(constante caractere *_Filename);
#fim_se
#fim_se

  _CRTIMP inteiro __cdecl _setmode(inteiro _FileHandle,inteiro _Mode);
  _CRTIMP longo __cdecl _tell(inteiro _FileHandle);
  _CRTIMP inteiro __cdecl _umask(inteiro _Mode);
  _CRTIMP inteiro __cdecl _write(inteiro _FileHandle,constante vazio *_Buf,sem_sinal inteiro _MaxCharCount);

#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 __cdecl _filelengthi64(inteiro _FileHandle);
  _CRTIMP intptr_t __cdecl _findfirst32i64(constante caractere *_Filename,estrutura _finddata32i64_t *_FindData);
  _CRTIMP intptr_t __cdecl _findfirst64(constante caractere *_Filename,estrutura __finddata64_t *_FindData);
#se_definido __cplusplus
#inclua <string.h>
#fim_se
  intptr_t __cdecl _findfirst64i32(constante caractere *_Filename,estrutura _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t __cdecl _findfirst64i32(constante caractere *_Filename,estrutura _finddata64i32_t *_FindData)
  {
    estrutura __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    retorne ret;
  }
  _CRTIMP inteiro __cdecl _findnext32i64(intptr_t _FindHandle,estrutura _finddata32i64_t *_FindData);
  _CRTIMP inteiro __cdecl _findnext64(intptr_t _FindHandle,estrutura __finddata64_t *_FindData);
  inteiro __cdecl _findnext64i32(intptr_t _FindHandle,estrutura _finddata64i32_t *_FindData);
  __CRT_INLINE inteiro __cdecl _findnext64i32(intptr_t _FindHandle,estrutura _finddata64i32_t *_FindData)
  {
    estrutura __finddata64_t fd;
    inteiro ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    retorne ret;
  }
  __int64 __cdecl _lseeki64(inteiro _FileHandle,__int64 _Offset,inteiro _Origin);
  __int64 __cdecl _telli64(inteiro _FileHandle);
#fim_se
#se_não_definido NO_OLDNAMES

#se_não_definido _UWIN
  inteiro __cdecl chdir (constante caractere *);
  caractere *__cdecl getcwd (caractere *, inteiro);
  inteiro __cdecl mkdir (constante caractere *);
  caractere *__cdecl mktemp(caractere *);
  inteiro __cdecl rmdir (constante caractere*);
  inteiro __cdecl chmod (constante caractere *, inteiro);
#fim_se /* _UWIN */

#fim_se /* Not NO_OLDNAMES */

  _CRTIMP errno_t __cdecl _sopen_s(inteiro *_FileHandle,constante caractere *_Filename,inteiro _OpenFlag,inteiro _ShareFlag,inteiro _PermissionMode);

#se_não_definido __cplusplus
  _CRTIMP inteiro __cdecl _open(constante caractere *_Filename,inteiro _OpenFlag,...);
  _CRTIMP inteiro __cdecl _sopen(constante caractere *_Filename,inteiro _OpenFlag,inteiro _ShareFlag,...);
#senão
  externo "C++" _CRTIMP inteiro __cdecl _open(constante caractere *_Filename,inteiro _Openflag,inteiro _PermissionMode = 0);
  externo "C++" _CRTIMP inteiro __cdecl _sopen(constante caractere *_Filename,inteiro _Openflag,inteiro _ShareFlag,inteiro _PermissionMode = 0);
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

  inteiro __cdecl __lock_fhandle(inteiro _Filehandle);
  vazio __cdecl _unlock_fhandle(inteiro _Filehandle);
  _CRTIMP intptr_t __cdecl _get_osfhandle(inteiro _FileHandle);
  _CRTIMP inteiro __cdecl _open_osfhandle(intptr_t _OSFileHandle,inteiro _Flags);

#se_não_definido	NO_OLDNAMES
  inteiro __cdecl access(constante caractere *_Filename,inteiro _AccessMode);
  inteiro __cdecl chmod(constante caractere *_Filename,inteiro _AccessMode);
  inteiro __cdecl chsize(inteiro _FileHandle,longo _Size);
  inteiro __cdecl close(inteiro _FileHandle);
  inteiro __cdecl creat(constante caractere *_Filename,inteiro _PermissionMode);
  inteiro __cdecl dup(inteiro _FileHandle);
  inteiro __cdecl dup2(inteiro _FileHandleSrc,inteiro _FileHandleDst);
  inteiro __cdecl eof(inteiro _FileHandle);
  longo __cdecl filelength(inteiro _FileHandle);
  inteiro __cdecl isatty(inteiro _FileHandle);
  inteiro __cdecl locking(inteiro _FileHandle,inteiro _LockMode,longo _NumOfBytes);
  longo __cdecl lseek(inteiro _FileHandle,longo _Offset,inteiro _Origin);
  caractere *__cdecl mktemp(caractere *_TemplateName);
  inteiro __cdecl open(constante caractere *_Filename,inteiro _OpenFlag,...);
  inteiro __cdecl read(inteiro _FileHandle,vazio *_DstBuf,sem_sinal inteiro _MaxCharCount);
  inteiro __cdecl setmode(inteiro _FileHandle,inteiro _Mode);
  inteiro __cdecl sopen(constante caractere *_Filename,inteiro _OpenFlag,inteiro _ShareFlag,...);
  longo __cdecl tell(inteiro _FileHandle);
  inteiro __cdecl umask(inteiro _Mode);
  inteiro __cdecl write(inteiro _Filehandle,constante vazio *_Buf,sem_sinal inteiro _MaxCharCount);
#fim_se

#se_definido __cplusplus
}
#fim_se
#fim_se

#se_definido __cplusplus
externo "C" {
#fim_se

/* Misc stuff */
caractere *getlogin(vazio);
#se_definido __USE_MINGW_ALARM
sem_sinal inteiro alarm(sem_sinal inteiro seconds);
#fim_se

#se_definido __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, enquanto the version
    shipped with Vista, returns an erro code.  This will restore the
    old behaviour  */
estático em_linha inteiro __mingw_access (constante caractere *__fname, inteiro __mode) {
  retorne  _access (__fname, __mode & ~X_OK);
}

#defina access(__f,__m)  __mingw_access (__f, __m)
#fim_se


#se_definido __cplusplus
}
#fim_se


#diretiva pack(pop)

#inclua <sec_api/io_s.h>

#fim_se /* End _IO_H_ */

