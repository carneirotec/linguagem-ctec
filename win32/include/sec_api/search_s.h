/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_SEARCH_S
#defina _INC_SEARCH_S

#inclua <search.h>

#se definido(MINGW_HAS_SECURE_API)

#se_definido __cplusplus
externo "C" {
#fim_se

  _CRTIMP vazio *__cdecl _lfind_s(constante vazio *_Key,constante vazio *_Base,sem_sinal inteiro *_NumOfElements,size_t _SizeOfElements,inteiro (__cdecl *_PtFuncCompare)(vazio *,constante vazio *,constante vazio *),vazio *_Context);
  _CRTIMP vazio *__cdecl _lsearch_s(constante vazio *_Key,vazio *_Base,sem_sinal inteiro *_NumOfElements,size_t _SizeOfElements,inteiro (__cdecl *_PtFuncCompare)(vazio *,constante vazio *,constante vazio *),vazio *_Context);

#se_definido __cplusplus
}
#fim_se

#fim_se
#fim_se
