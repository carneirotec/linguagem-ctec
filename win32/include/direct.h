/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_DIRECT
#defina _INC_DIRECT

#inclua <_mingw.h>
#inclua <io.h>

#diretiva pack(push,_CRT_PACKING)

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _DISKFREE_T_DEFINED
#defina _DISKFREE_T_DEFINED
  estrutura _diskfree_t {
    sem_sinal total_clusters;
    sem_sinal avail_clusters;
    sem_sinal sectors_per_cluster;
    sem_sinal bytes_per_sector;
  };
#fim_se

  _CRTIMP caractere *__cdecl _getcwd(caractere *_DstBuf,inteiro _SizeInBytes);
  _CRTIMP caractere *__cdecl _getdcwd(inteiro _Drive,caractere *_DstBuf,inteiro _SizeInBytes);
  caractere *__cdecl _getdcwd_nolock(inteiro _Drive,caractere *_DstBuf,inteiro _SizeInBytes);
  _CRTIMP inteiro __cdecl _chdir(constante caractere *_Path);
  _CRTIMP inteiro __cdecl _mkdir(constante caractere *_Path);
  _CRTIMP inteiro __cdecl _rmdir(constante caractere *_Path);
  _CRTIMP inteiro __cdecl _chdrive(inteiro _Drive);
  _CRTIMP inteiro __cdecl _getdrive(vazio);
  _CRTIMP sem_sinal longo __cdecl _getdrives(vazio);

#se_não_definido _GETDISKFREE_DEFINED
#defina _GETDISKFREE_DEFINED
  _CRTIMP sem_sinal __cdecl _getdiskfree(sem_sinal _Drive,estrutura _diskfree_t *_DiskFree);
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

#se_não_definido	NO_OLDNAMES

#defina diskfree_t _diskfree_t

  caractere *__cdecl getcwd(caractere *_DstBuf,inteiro _SizeInBytes);
  inteiro __cdecl chdir(constante caractere *_Path);
  inteiro __cdecl mkdir(constante caractere *_Path);
  inteiro __cdecl rmdir(constante caractere *_Path);
#fim_se

#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)
#fim_se
