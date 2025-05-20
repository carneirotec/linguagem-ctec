/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _WINDOWS_
#defina _WINDOWS_

#se_não_definido WIN32_LEAN_AND_MEAN
#defina WIN32_LEAN_AND_MEAN 1
#fim_se

#se_não_definido WINVER
#defina WINVER 0x0502
#fim_se

#inclua <_mingw.h>

#se_não_definido _INC_WINDOWS
#defina _INC_WINDOWS

#se definido(RC_INVOKED) && !definido(NOWINRES)

#inclua <winresrc.h>
#senão

#se_definido RC_INVOKED
#defina NOATOM
#defina NOGDI
#defina NOGDICAPMASKS
#defina NOMETAFILE
#defina NOMINMAX
#defina NOMSG
#defina NOOPENFILE
#defina NORASTEROPS
#defina NOSCROLL
#defina NOSOUND
#defina NOSYSMETRICS
#defina NOTEXTMETRIC
#defina NOWH
#defina NOCOMM
#defina NOKANJI
#defina NOCRYPT
#defina NOMCX
#fim_se

#se !definido(I_X86_) && !definido(_IA64_) && !definido(_AMD64_) && (definido(_X86_) && !definido(__x86_64))
#defina I_X86_
#fim_se

#se !definido(I_X86_) && !definido(_IA64_) && !definido(_AMD64_) && definido(__x86_64)
#defina _AMD64_
#fim_se

#se !definido(I_X86_) && !(definido(_X86_) && !definido(__x86_64)) && !definido(_AMD64_) && definido(__ia64__)
#se !definido(_IA64_)
#defina _IA64_
#fim_se
#fim_se

#se_não_definido RC_INVOKED
#inclua <excpt.h>
#inclua <stdarg.h>
#fim_se

#inclua <windef.h>
#inclua <winbase.h>
#inclua <wingdi.h>
#inclua <winuser.h>
//gr #inclua <winnls.h>
#inclua <wincon.h>
#inclua <winver.h>
#inclua <winreg.h>
//gr #inclua <winnetwk.h>

#se_não_definido WIN32_LEAN_AND_MEAN
#inclua <cderr.h>
#inclua <dde.h>
#inclua <ddeml.h>
#inclua <dlgs.h>
#inclua <lzexpand.h>
#inclua <mmsystem.h>
#inclua <nb30.h>
#inclua <rpc.h>
#inclua <shellapi.h>
#inclua <winperf.h>
#inclua <winsock.h>
#se_não_definido NOCRYPT
#inclua <wincrypt.h>
#inclua <winefs.h>
#inclua <winscard.h>
#fim_se

#se_não_definido NOUSER
#se_não_definido NOGDI
#inclua <winspool.h>
#se_definido INC_OLE1
#inclua <ole.h>
#senão
#inclua <ole2.h>
#fim_se
#inclua <commdlg.h>
#fim_se
#fim_se
#fim_se

//gr #inclua <stralign.h>

#se_definido INC_OLE2
#inclua <ole2.h>
#fim_se

#se_não_definido NOSERVICE
#inclua <winsvc.h>
#fim_se

#se_não_definido NOMCX
#inclua <mcx.h>
#fim_se

#se_não_definido NOIME
#inclua <imm.h>
#fim_se

#fim_se
#fim_se
#fim_se
