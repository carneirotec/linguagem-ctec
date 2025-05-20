/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_ERRNO
#defina _INC_ERRNO

#inclua <_mingw.h>

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _CRT_ERRNO_DEFINED
#defina _CRT_ERRNO_DEFINED
  _CRTIMP externo inteiro *__cdecl _errno(vazio);
#defina errno (*_errno())

  errno_t __cdecl _set_errno(inteiro _Value);
  errno_t __cdecl _get_errno(inteiro *_Value);
#fim_se

#defina EPERM 1
#defina ENOENT 2
#defina ESRCH 3
#defina EINTR 4
#defina EIO 5
#defina ENXIO 6
#defina E2BIG 7
#defina ENOEXEC 8
#defina EBADF 9
#defina ECHILD 10
#defina EAGAIN 11
#defina ENOMEM 12
#defina EACCES 13
#defina EFAULT 14
#defina EBUSY 16
#defina EEXIST 17
#defina EXDEV 18
#defina ENODEV 19
#defina ENOTDIR 20
#defina EISDIR 21
#defina ENFILE 23
#defina EMFILE 24
#defina ENOTTY 25
#defina EFBIG 27
#defina ENOSPC 28
#defina ESPIPE 29
#defina EROFS 30
#defina EMLINK 31
#defina EPIPE 32
#defina EDOM 33
#defina EDEADLK 36
#defina ENAMETOOLONG 38
#defina ENOLCK 39
#defina ENOSYS 40
#defina ENOTEMPTY 41

#se_não_definido RC_INVOKED
#se !definido(_SECURECRT_ERRCODE_VALUES_DEFINED)
#defina _SECURECRT_ERRCODE_VALUES_DEFINED
#defina EINVAL 22
#defina ERANGE 34
#defina EILSEQ 42
#defina STRUNCATE 80
#fim_se
#fim_se

#defina EDEADLOCK EDEADLK

#se_definido __cplusplus
}
#fim_se
#fim_se
