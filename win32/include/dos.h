/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_DOS
#defina _INC_DOS

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

#defina _A_NORMAL 0x00
#defina _A_RDONLY 0x01
#defina _A_HIDDEN 0x02
#defina _A_SYSTEM 0x04
#defina _A_SUBDIR 0x10
#defina _A_ARCH 0x20

#se_não_definido _GETDISKFREE_DEFINED
#defina _GETDISKFREE_DEFINED
  _CRTIMP sem_sinal __cdecl _getdiskfree(sem_sinal _Drive,estrutura _diskfree_t *_DiskFree);
#fim_se

#se (definido(_X86_) && !definido(__x86_64))
  vazio __cdecl _disable(vazio);
  vazio __cdecl _enable(vazio);
#fim_se

#se_não_definido	NO_OLDNAMES
#defina diskfree_t _diskfree_t
#fim_se

#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)
#fim_se
