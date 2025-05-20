/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#inclua <_mingw.h>

#inclua <io.h>

#se_não_definido _INC_FCNTL
#defina _INC_FCNTL

#defina _O_RDONLY 0x0000
#defina _O_WRONLY 0x0001
#defina _O_RDWR 0x0002
#defina _O_APPEND 0x0008
#defina _O_CREAT 0x0100
#defina _O_TRUNC 0x0200
#defina _O_EXCL 0x0400
#defina _O_TEXT 0x4000
#defina _O_BINARY 0x8000
#defina _O_WTEXT 0x10000
#defina _O_U16TEXT 0x20000
#defina _O_U8TEXT 0x40000
#defina _O_ACCMODE (_O_RDONLY|_O_WRONLY|_O_RDWR)

#defina _O_RAW _O_BINARY
#defina _O_NOINHERIT 0x0080
#defina _O_TEMPORARY 0x0040
#defina _O_SHORT_LIVED 0x1000

#defina _O_SEQUENTIAL 0x0020
#defina _O_RANDOM 0x0010

#se !definido(NO_OLDNAMES) || definido(_POSIX)
#defina O_RDONLY _O_RDONLY
#defina O_WRONLY _O_WRONLY
#defina O_RDWR _O_RDWR
#defina O_APPEND _O_APPEND
#defina O_CREAT _O_CREAT
#defina O_TRUNC _O_TRUNC
#defina O_EXCL _O_EXCL
#defina O_TEXT _O_TEXT
#defina O_BINARY _O_BINARY
#defina O_RAW _O_BINARY
#defina O_TEMPORARY _O_TEMPORARY
#defina O_NOINHERIT _O_NOINHERIT
#defina O_SEQUENTIAL _O_SEQUENTIAL
#defina O_RANDOM _O_RANDOM
#defina O_ACCMODE _O_ACCMODE
#fim_se
#fim_se
