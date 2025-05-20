/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_IO_S
#defina _INC_IO_S

#inclua <io.h>

#se definido(MINGW_HAS_SECURE_API)

#se_definido __cplusplus
externo "C" {
#fim_se

  _CRTIMP errno_t __cdecl _access_s(constante caractere *_Filename,inteiro _AccessMode);
  _CRTIMP errno_t __cdecl _chsize_s(inteiro _FileHandle,__int64 _Size);
  _CRTIMP errno_t __cdecl _mktemp_s(caractere *_TemplateName,size_t _Size);
  _CRTIMP errno_t __cdecl _umask_s(inteiro _NewMode,inteiro *_OldMode);

#se_não_definido _WIO_S_DEFINED
#defina _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(constante wchar_t *_Filename,inteiro _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t _SizeInWords);
#fim_se

#se_definido __cplusplus
}
#fim_se

#fim_se
#fim_se
