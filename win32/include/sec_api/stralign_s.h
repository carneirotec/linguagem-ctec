/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido __STRALIGN_H_S_
#defina __STRALIGN_H_S_

#inclua <stralign.h>

#se definido(MINGW_HAS_SECURE_API)

#se_definido __cplusplus
externo "C" {
#fim_se

#se !definido(I_X86_) && definido(_WSTRING_S_DEFINED)
#se definido(__cplusplus) && definido(_WConst_Return)
  estático __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,size_t DestinationSize,PCUWSTR Source) {
    se(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination)) retorne (wcscpy_s((PWSTR)Destination,DestinationSize,(PCWSTR)Source)==0 ? Destination : NULL);
    retorne uaw_wcscpy((PCUWSTR)String,Character);
  }
#fim_se
#fim_se

#se_definido __cplusplus
}
#fim_se
#fim_se
#fim_se
