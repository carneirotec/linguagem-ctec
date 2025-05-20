/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_LOCKING
#defina _INC_LOCKING

#se_não_definido _WIN32
#erro Only Win32 target is supported!
#fim_se

/* All the headers inclua this file. */
#inclua <_mingw.h>

#defina _LK_UNLCK 0
#defina _LK_LOCK 1
#defina _LK_NBLCK 2
#defina _LK_RLCK 3
#defina _LK_NBRLCK 4

#se_não_definido	NO_OLDNAMES
#defina LK_UNLCK _LK_UNLCK
#defina LK_LOCK _LK_LOCK
#defina LK_NBLCK _LK_NBLCK
#defina LK_RLCK _LK_RLCK
#defina LK_NBRLCK _LK_NBRLCK
#fim_se

#fim_se
