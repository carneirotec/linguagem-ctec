/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_MEMORY
#defina _INC_MEMORY

#inclua <_mingw.h>

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _CONST_RETURN
#defina _CONST_RETURN
#fim_se

#defina _WConst_return _CONST_RETURN

#se_não_definido _CRT_MEMORY_DEFINED
#defina _CRT_MEMORY_DEFINED
  _CRTIMP vazio *__cdecl _memccpy(vazio *_Dst,constante vazio *_Src,inteiro _Val,size_t _MaxCount);
  _CONST_RETURN vazio *__cdecl memchr(constante vazio *_Buf ,inteiro _Val,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _memicmp(constante vazio *_Buf1,constante vazio *_Buf2,size_t _Size);
  _CRTIMP inteiro __cdecl _memicmp_l(constante vazio *_Buf1,constante vazio *_Buf2,size_t _Size,_locale_t _Locale);
  inteiro __cdecl memcmp(constante vazio *_Buf1,constante vazio *_Buf2,size_t _Size);
  vazio *__cdecl memcpy(vazio *_Dst,constante vazio *_Src,size_t _Size);
  vazio *__cdecl memset(vazio *_Dst,inteiro _Val,size_t _Size);

#se_não_definido	NO_OLDNAMES
  vazio *__cdecl memccpy(vazio *_Dst,constante vazio *_Src,inteiro _Val,size_t _Size);
  inteiro __cdecl memicmp(constante vazio *_Buf1,constante vazio *_Buf2,size_t _Size);
#fim_se
#fim_se

#se_definido __cplusplus
}
#fim_se
#fim_se
