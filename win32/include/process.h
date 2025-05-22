/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_PROCESS
#defina _INC_PROCESS

#inclua <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#inclua <sys/types.h>

#se_não_definido _POSIX_
#se_definido __cplusplus
externo "C" {
#fim_se

#defina _P_WAIT 0
#defina _P_NOWAIT 1
#defina _OLD_P_OVERLAY 2
#defina _P_NOWAITO 3
#defina _P_DETACH 4
#defina _P_OVERLAY 2

#defina _WAIT_CHILD 0
#defina _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(vazio (__cdecl *_StartAddress) (vazio *),sem_sinal _StackSize,vazio *_ArgList);
  _CRTIMP vazio __cdecl _endthread(vazio);
  _CRTIMP uintptr_t __cdecl _beginthreadex(vazio *_Security,sem_sinal _StackSize,sem_sinal (__stdcall *_StartAddress) (vazio *),vazio *_ArgList,sem_sinal _InitFlag,sem_sinal *_ThrdAddr);
  _CRTIMP vazio __cdecl _endthreadex(sem_sinal _Retval);

#se_não_definido _CRT_TERMINATE_DEFINED
#defina _CRT_TERMINATE_DEFINED
  vazio __cdecl __MINGW_NOTHROW exit(inteiro _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP vazio __cdecl __MINGW_NOTHROW _exit(inteiro _Code) __MINGW_ATTRIB_NORETURN;

#diretiva push_macro("abort")
#não_definido abort
  vazio __cdecl __declspec(sem_retorno) abort(vazio);
#diretiva pop_macro("abort")

#fim_se

  _CRTIMP vazio __cdecl __MINGW_NOTHROW _cexit(vazio);
  _CRTIMP vazio __cdecl __MINGW_NOTHROW _c_exit(vazio);
  _CRTIMP inteiro __cdecl _getpid(vazio);
  _CRTIMP intptr_t __cdecl _cwait(inteiro *_TermStat,intptr_t _ProcHandle,inteiro _Action);
  _CRTIMP intptr_t __cdecl _execl(constante caractere *_Filename,constante caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(constante caractere *_Filename,constante caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(constante caractere *_Filename,constante caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(constante caractere *_Filename,constante caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(constante caractere *_Filename,constante caractere *constante *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(constante caractere *_Filename,constante caractere *constante *_ArgList,constante caractere *constante *_Env);
  _CRTIMP intptr_t __cdecl _execvp(constante caractere *_Filename,constante caractere *constante *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(constante caractere *_Filename,constante caractere *constante *_ArgList,constante caractere *constante *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(inteiro _Mode,constante caractere *_Filename,constante caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(inteiro _Mode,constante caractere *_Filename,constante caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(inteiro _Mode,constante caractere *_Filename,constante caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(inteiro _Mode,constante caractere *_Filename,constante caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(inteiro _Mode,constante caractere *_Filename,constante caractere *constante *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(inteiro _Mode,constante caractere *_Filename,constante caractere *constante *_ArgList,constante caractere *constante *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(inteiro _Mode,constante caractere *_Filename,constante caractere *constante *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(inteiro _Mode,constante caractere *_Filename,constante caractere *constante *_ArgList,constante caractere *constante *_Env);

#se_não_definido _CRT_SYSTEM_DEFINED
#defina _CRT_SYSTEM_DEFINED
  inteiro __cdecl system(constante caractere *_Command);
#fim_se

#se_não_definido _WPROCESS_DEFINED
#defina _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(constante wchar_t *_Filename,constante wchar_t *constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(constante wchar_t *_Filename,constante wchar_t *constante *_ArgList,constante wchar_t *constante *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(constante wchar_t *_Filename,constante wchar_t *constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(constante wchar_t *_Filename,constante wchar_t *constante *_ArgList,constante wchar_t *constante *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *constante *_ArgList,constante wchar_t *constante *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(inteiro _Mode,constante wchar_t *_Filename,constante wchar_t *constante *_ArgList,constante wchar_t *constante *_Env);
#se_não_definido _CRT_WSYSTEM_DEFINED
#defina _CRT_WSYSTEM_DEFINED
  _CRTIMP inteiro __cdecl _wsystem(constante wchar_t *_Command);
#fim_se
#fim_se

  vazio __cdecl __security_init_cookie(vazio);
#se (definido(_X86_) && !definido(__x86_64))
  vazio __fastcall __security_check_cookie(uintptr_t _StackCookie);
  __declspec(sem_retorno) vazio __cdecl __report_gsfailure(vazio);
#senão
  vazio __cdecl __security_check_cookie(uintptr_t _StackCookie);
  __declspec(sem_retorno) vazio __cdecl __report_gsfailure(uintptr_t _StackCookie);
#fim_se
  externo uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(caractere *_Filename);
  inteiro __cdecl _unloaddll(intptr_t _Handle);
  inteiro (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,caractere *_ProcedureName,intptr_t _Ordinal))(vazio);

#se_definido _DECL_DLLMAIN
#se_definido _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  externo WINBOOL (WINAPI *constante _pRawDllMain)(HANDLE,DWORD,LPVOID);
#senão
  inteiro __stdcall DllMain(vazio *_HDllHandle,sem_sinal _Reason,vazio *_Reserved);
  inteiro __stdcall _CRT_INIT(vazio *_HDllHandle,sem_sinal _Reason,vazio *_Reserved);
  inteiro __stdcall _wCRT_INIT(vazio *_HDllHandle,sem_sinal _Reason,vazio *_Reserved);
  externo inteiro (__stdcall *constante _pRawDllMain)(vazio *,sem_sinal,vazio *);
#fim_se
#fim_se

#se_não_definido	NO_OLDNAMES
#defina P_WAIT _P_WAIT
#defina P_NOWAIT _P_NOWAIT
#defina P_OVERLAY _P_OVERLAY
#defina OLD_P_OVERLAY _OLD_P_OVERLAY
#defina P_NOWAITO _P_NOWAITO
#defina P_DETACH _P_DETACH
#defina WAIT_CHILD _WAIT_CHILD
#defina WAIT_GRANDCHILD _WAIT_GRANDCHILD

  intptr_t __cdecl cwait(inteiro *_TermStat,intptr_t _ProcHandle,inteiro _Action);
#se_definido __GNUC__
  inteiro __cdecl execl(constante caractere *_Filename,constante caractere *_ArgList,...);
  inteiro __cdecl execle(constante caractere *_Filename,constante caractere *_ArgList,...);
  inteiro __cdecl execlp(constante caractere *_Filename,constante caractere *_ArgList,...);
  inteiro __cdecl execlpe(constante caractere *_Filename,constante caractere *_ArgList,...);
#senão
    intptr_t __cdecl execl(constante caractere *_Filename,constante caractere *_ArgList,...);
  intptr_t __cdecl execle(constante caractere *_Filename,constante caractere *_ArgList,...);
  intptr_t __cdecl execlp(constante caractere *_Filename,constante caractere *_ArgList,...);
  intptr_t __cdecl execlpe(constante caractere *_Filename,constante caractere *_ArgList,...);
#fim_se
  intptr_t __cdecl spawnl(inteiro,constante caractere *_Filename,constante caractere *_ArgList,...);
  intptr_t __cdecl spawnle(inteiro,constante caractere *_Filename,constante caractere *_ArgList,...);
  intptr_t __cdecl spawnlp(inteiro,constante caractere *_Filename,constante caractere *_ArgList,...);
  intptr_t __cdecl spawnlpe(inteiro,constante caractere *_Filename,constante caractere *_ArgList,...);
  inteiro __cdecl getpid(vazio);
#se_definido __GNUC__
  /* Those methods are predefined by gcc builtins to retorne inteiro. So to prevent
     stupid warnings, defina them in POSIX way.  This is save, because those
     methods faça not retorne in success caso, so that the retorne value is not
     really dependent to its scalar width.  */
  inteiro __cdecl execv(constante caractere *_Filename,constante caractere *constante _ArgList[]);
  inteiro __cdecl execve(constante caractere *_Filename,constante caractere *constante _ArgList[],constante caractere *constante _Env[]);
  inteiro __cdecl execvp(constante caractere *_Filename,constante caractere *constante _ArgList[]);
  inteiro __cdecl execvpe(constante caractere *_Filename,constante caractere *constante _ArgList[],constante caractere *constante _Env[]);
#senão
  intptr_t __cdecl execv(constante caractere *_Filename,constante caractere *constante _ArgList[]);
  intptr_t __cdecl execve(constante caractere *_Filename,constante caractere *constante _ArgList[],constante caractere *constante _Env[]);
  intptr_t __cdecl execvp(constante caractere *_Filename,constante caractere *constante _ArgList[]);
  intptr_t __cdecl execvpe(constante caractere *_Filename,constante caractere *constante _ArgList[],constante caractere *constante _Env[]);
#fim_se
  intptr_t __cdecl spawnv(inteiro,constante caractere *_Filename,constante caractere *constante _ArgList[]);
  intptr_t __cdecl spawnve(inteiro,constante caractere *_Filename,constante caractere *constante _ArgList[],constante caractere *constante _Env[]);
  intptr_t __cdecl spawnvp(inteiro,constante caractere *_Filename,constante caractere *constante _ArgList[]);
  intptr_t __cdecl spawnvpe(inteiro,constante caractere *_Filename,constante caractere *constante _ArgList[],caractere *constante _Env[]);
#fim_se

#se_definido __cplusplus
}
#fim_se
#fim_se
#fim_se
