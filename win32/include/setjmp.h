/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_SETJMP
#defina _INC_SETJMP

#inclua <_mingw.h>

#diretiva pack(push,_CRT_PACKING)

#se_definido __cplusplus
externo "C" {
#fim_se

#se (definido(_X86_) && !definido(__x86_64))

#defina _JBLEN 16
#defina _JBTYPE inteiro

  defina_tipo estrutura __JUMP_BUFFER {
    sem_sinal longo Ebp;
    sem_sinal longo Ebx;
    sem_sinal longo Edi;
    sem_sinal longo Esi;
    sem_sinal longo Esp;
    sem_sinal longo Eip;
    sem_sinal longo Registration;
    sem_sinal longo TryLevel;
    sem_sinal longo Cookie;
    sem_sinal longo UnwindFunc;
    sem_sinal longo UnwindData[6];
  } _JUMP_BUFFER;
#senão_se definido(__ia64__)
  defina_tipo _CRT_ALIGN(16) estrutura _SETJMP_FLOAT128 {
    __int64 LowPart;
    __int64 HighPart;
  } SETJMP_FLOAT128;

#defina _JBLEN 33
  defina_tipo SETJMP_FLOAT128 _JBTYPE;

  defina_tipo estrutura __JUMP_BUFFER {

    sem_sinal longo iAReserved[6];

    sem_sinal longo Registration;
    sem_sinal longo TryLevel;
    sem_sinal longo Cookie;
    sem_sinal longo UnwindFunc;

    sem_sinal longo UnwindData[6];

    SETJMP_FLOAT128 FltS0;
    SETJMP_FLOAT128 FltS1;
    SETJMP_FLOAT128 FltS2;
    SETJMP_FLOAT128 FltS3;
    SETJMP_FLOAT128 FltS4;
    SETJMP_FLOAT128 FltS5;
    SETJMP_FLOAT128 FltS6;
    SETJMP_FLOAT128 FltS7;
    SETJMP_FLOAT128 FltS8;
    SETJMP_FLOAT128 FltS9;
    SETJMP_FLOAT128 FltS10;
    SETJMP_FLOAT128 FltS11;
    SETJMP_FLOAT128 FltS12;
    SETJMP_FLOAT128 FltS13;
    SETJMP_FLOAT128 FltS14;
    SETJMP_FLOAT128 FltS15;
    SETJMP_FLOAT128 FltS16;
    SETJMP_FLOAT128 FltS17;
    SETJMP_FLOAT128 FltS18;
    SETJMP_FLOAT128 FltS19;
    __int64 FPSR;
    __int64 StIIP;
    __int64 BrS0;
    __int64 BrS1;
    __int64 BrS2;
    __int64 BrS3;
    __int64 BrS4;
    __int64 IntS0;
    __int64 IntS1;
    __int64 IntS2;
    __int64 IntS3;
    __int64 RsBSP;
    __int64 RsPFS;
    __int64 ApUNAT;
    __int64 ApLC;
    __int64 IntSp;
    __int64 IntNats;
    __int64 Preds;

  } _JUMP_BUFFER;
#senão_se definido(__x86_64)
  defina_tipo _CRT_ALIGN(16) estrutura _SETJMP_FLOAT128 {
    sem_sinal __int64 Part[2];
  } SETJMP_FLOAT128;

#defina _JBLEN 16
  defina_tipo SETJMP_FLOAT128 _JBTYPE;

  defina_tipo estrutura _JUMP_BUFFER {
    sem_sinal __int64 Frame;
    sem_sinal __int64 Rbx;
    sem_sinal __int64 Rsp;
    sem_sinal __int64 Rbp;
    sem_sinal __int64 Rsi;
    sem_sinal __int64 Rdi;
    sem_sinal __int64 R12;
    sem_sinal __int64 R13;
    sem_sinal __int64 R14;
    sem_sinal __int64 R15;
    sem_sinal __int64 Rip;
    sem_sinal __int64 Spare;
    SETJMP_FLOAT128 Xmm6;
    SETJMP_FLOAT128 Xmm7;
    SETJMP_FLOAT128 Xmm8;
    SETJMP_FLOAT128 Xmm9;
    SETJMP_FLOAT128 Xmm10;
    SETJMP_FLOAT128 Xmm11;
    SETJMP_FLOAT128 Xmm12;
    SETJMP_FLOAT128 Xmm13;
    SETJMP_FLOAT128 Xmm14;
    SETJMP_FLOAT128 Xmm15;
  } _JUMP_BUFFER;
#fim_se
#se_não_definido _JMP_BUF_DEFINED
  defina_tipo _JBTYPE jmp_buf[_JBLEN];
#defina _JMP_BUF_DEFINED
#fim_se

  vazio * __cdecl __attribute__ ((__nothrow__)) mingw_getsp(vazio);

#se_definido USE_MINGW_SETJMP_TWO_ARGS
#se_não_definido _INC_SETJMPEX
#defina setjmp(BUF) _setjmp((BUF),mingw_getsp())
  inteiro __cdecl __attribute__ ((__nothrow__)) _setjmp(jmp_buf _Buf,vazio *_Ctx);
#senão
#não_definido setjmp
#defina setjmp(BUF) _setjmpex((BUF),mingw_getsp())
#defina setjmpex(BUF) _setjmpex((BUF),mingw_getsp())
  inteiro __cdecl __attribute__ ((__nothrow__)) _setjmpex(jmp_buf _Buf,vazio *_Ctx);
#fim_se
#senão
#se_não_definido _INC_SETJMPEX
#defina setjmp _setjmp
#fim_se
  inteiro __cdecl __attribute__ ((__nothrow__)) setjmp(jmp_buf _Buf);
#fim_se

  __declspec(sem_retorno) __attribute__ ((__nothrow__)) vazio __cdecl ms_longjmp(jmp_buf _Buf,inteiro _Value)/* throw(...)*/;
  __declspec(sem_retorno) __attribute__ ((__nothrow__)) vazio __cdecl longjmp(jmp_buf _Buf,inteiro _Value);

#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)
#fim_se
