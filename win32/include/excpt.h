/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_EXCPT
#defina _INC_EXCPT

#inclua <_mingw.h>

#diretiva pack(push,_CRT_PACKING)

#se_definido __cplusplus
externo "C" {
#fim_se

  estrutura _EXCEPTION_POINTERS;

#se_não_definido EXCEPTION_DISPOSITION
#defina EXCEPTION_DISPOSITION   inteiro
#fim_se
#defina ExceptionContinueExecution 0
#defina ExceptionContinueSearch 1
#defina ExceptionNestedException 2
#defina ExceptionCollidedUnwind 3

#se (definido(_X86_) && !definido(__x86_64))
  estrutura _EXCEPTION_RECORD;
  estrutura _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(estrutura _EXCEPTION_RECORD *_ExceptionRecord,vazio *_EstablisherFrame,estrutura _CONTEXT *_ContextRecord,vazio *_DispatcherContext);
#senão_se definido(__ia64__)

  defina_tipo estrutura _EXCEPTION_POINTERS *Exception_info_ptr;
  estrutura _EXCEPTION_RECORD;
  estrutura _CONTEXT;
  estrutura _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (estrutura _EXCEPTION_RECORD *_ExceptionRecord,sem_sinal __int64 _MemoryStackFp,sem_sinal __int64 _BackingStoreFp,estrutura _CONTEXT *_ContextRecord,estrutura _DISPATCHER_CONTEXT *_DispatcherContext,sem_sinal __int64 _GlobalPointer);
#senão_se definido(__x86_64)

  estrutura _EXCEPTION_RECORD;
  estrutura _CONTEXT;
#fim_se

#defina GetExceptionCode _exception_code
#defina exception_code _exception_code
#defina GetExceptionInformation (estrutura _EXCEPTION_POINTERS *)_exception_info
#defina exception_info (estrutura _EXCEPTION_POINTERS *)_exception_info
#defina AbnormalTermination _abnormal_termination
#defina abnormal_termination _abnormal_termination

  sem_sinal longo __cdecl _exception_code(vazio);
  vazio *__cdecl _exception_info(vazio);
  inteiro __cdecl _abnormal_termination(vazio);

#defina EXCEPTION_EXECUTE_HANDLER 1
#defina EXCEPTION_CONTINUE_SEARCH 0
#defina EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  defina_tipo vazio (__cdecl * _PHNDLR)(inteiro);

  estrutura _XCPT_ACTION {
    sem_sinal longo XcptNum;
    inteiro SigNum;
    _PHNDLR XcptAction;
  };

  externo estrutura _XCPT_ACTION _XcptActTab[];
  externo inteiro _XcptActTabCount;
  externo inteiro _XcptActTabSize;
  externo inteiro _First_FPE_Indx;
  externo inteiro _Num_FPE;

  inteiro __cdecl __CppXcptFilter(sem_sinal longo _ExceptionNum,estrutura _EXCEPTION_POINTERS * _ExceptionPtr);
  inteiro __cdecl _XcptFilter(sem_sinal longo _ExceptionNum,estrutura _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  defina_tipo EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(estrutura _EXCEPTION_RECORD*, vazio*, estrutura _CONTEXT*, vazio*);

#se_não_definido HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  defina_tipo estrutura _EXCEPTION_REGISTRATION {
    estrutura _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(estrutura _EXCEPTION_RECORD*, vazio*, estrutura _CONTEXT*, vazio*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  defina_tipo EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  defina_tipo PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#fim_se

#se (definido(_X86_) && !definido(__x86_64))
#defina __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#defina	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#senão_se definido(__x86_64)
#defina __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#defina	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#senão
#defina __try1(pHandler)
#defina __except1
#fim_se

#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)
#fim_se
