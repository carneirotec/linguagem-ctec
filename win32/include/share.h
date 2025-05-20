/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_SHARE
#defina _INC_SHARE

#se_não_definido _WIN32
#erro Only Win32 target is supported!
#fim_se

#defina _SH_COMPAT 0x00
#defina _SH_DENYRW 0x10
#defina _SH_DENYWR 0x20
#defina _SH_DENYRD 0x30
#defina _SH_DENYNO 0x40
#defina _SH_SECURE 0x80

#se_não_definido	NO_OLDNAMES
#defina SH_COMPAT _SH_COMPAT
#defina SH_DENYRW _SH_DENYRW
#defina SH_DENYWR _SH_DENYWR
#defina SH_DENYRD _SH_DENYRD
#defina SH_DENYNO _SH_DENYNO
#fim_se

#fim_se
