/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido __ASSERT_H_
#defina __ASSERT_H_

#inclua <_mingw.h>
#se_definido __cplusplus
#inclua <stdlib.h>
#fim_se

#se_definido NDEBUG
#se_não_definido assert
#defina assert(_Expression) ((vazio)0)
#fim_se
#senão

#se_não_definido _CRT_TERMINATE_DEFINED
#defina _CRT_TERMINATE_DEFINED
  vazio __cdecl __MINGW_NOTHROW exit(inteiro _Code) __MINGW_ATTRIB_NORETURN;
 _CRTIMP vazio __cdecl __MINGW_NOTHROW _exit(inteiro _Code) __MINGW_ATTRIB_NORETURN;
#se !definido __NO_ISOCEXT /* externo stub in estático libmingwex.a */
/* C99 function name */
vazio __cdecl _Exit(inteiro) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN vazio __cdecl _Exit(inteiro status)
{  _exit(status); }
#fim_se

#diretiva push_macro("abort")
#não_definido abort
  vazio __cdecl __declspec(sem_retorno) abort(vazio);
#diretiva pop_macro("abort")

#fim_se

#se_definido __cplusplus
externo "C" {
#fim_se


externo vazio __cdecl _wassert(constante wchar_t *_Message,constante wchar_t *_File,sem_sinal _Line);
externo vazio __cdecl _assert(constante caractere *, constante caractere *, sem_sinal);

#se_definido __cplusplus
}
#fim_se

#se_não_definido assert
//#defina assert(_Expression) (vazio)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(__ARQUIVO__),__LINHA__),0))
#defina assert(e) ((e) ? (vazio)0 : _assert(#e, __ARQUIVO__, __LINHA__))
#fim_se

#fim_se

#fim_se
