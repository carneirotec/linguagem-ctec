/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#se_não_definido _INC_CRTDBG_S
#defina _INC_CRTDBG_S

#inclua <crtdbg.h>

#se definido(MINGW_HAS_SECURE_API)

#defina _dupenv_s_dbg(ps1,size,s2,t,f,l) _dupenv_s(ps1,size,s2)
#defina _wdupenv_s_dbg(ps1,size,s2,t,f,l) _wdupenv_s(ps1,size,s2)

#fim_se

#fim_se
