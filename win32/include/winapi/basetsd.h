/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _BASETSD_H_
#defina _BASETSD_H_

#se (definido(__x86_64) || definido(__ia64__)) && !definido(RC_INVOKED)
defina_tipo sem_sinal __int64 POINTER_64_INT;
#senão
defina_tipo sem_sinal longo POINTER_64_INT;
#fim_se

#defina POINTER_32
#defina POINTER_64
#defina FIRMWARE_PTR

#se_definido __cplusplus
externo "C" {
#fim_se

  defina_tipo sinalizado caractere INT8,*PINT8;
  defina_tipo sinalizado curto INT16,*PINT16;
  defina_tipo sinalizado inteiro INT32,*PINT32;
  defina_tipo sinalizado __int64 INT64,*PINT64;
  defina_tipo sem_sinal caractere UINT8,*PUINT8;
  defina_tipo sem_sinal curto UINT16,*PUINT16;
  defina_tipo sem_sinal inteiro UINT32,*PUINT32;
  defina_tipo sem_sinal __int64 UINT64,*PUINT64;
  defina_tipo sinalizado inteiro LONG32,*PLONG32;
  defina_tipo sem_sinal inteiro ULONG32,*PULONG32;
  defina_tipo sem_sinal inteiro DWORD32,*PDWORD32;

#se_não_definido _W64
#defina _W64
#fim_se

#se_definido _WIN64
  defina_tipo __int64 INT_PTR,*PINT_PTR;
  defina_tipo sem_sinal __int64 UINT_PTR,*PUINT_PTR;
  defina_tipo __int64 LONG_PTR,*PLONG_PTR;
  defina_tipo sem_sinal __int64 ULONG_PTR,*PULONG_PTR;
#defina __int3264 __int64
#senão
  defina_tipo inteiro INT_PTR,*PINT_PTR;
  defina_tipo sem_sinal inteiro UINT_PTR,*PUINT_PTR;
  defina_tipo longo LONG_PTR,*PLONG_PTR;
  defina_tipo sem_sinal longo ULONG_PTR,*PULONG_PTR;
#defina __int3264 __int32
#fim_se

#se_definido _WIN64
#defina ADDRESS_TAG_BIT 0x40000000000ULL
  defina_tipo __int64 SHANDLE_PTR;
  defina_tipo sem_sinal __int64 HANDLE_PTR;
  defina_tipo sem_sinal inteiro UHALF_PTR,*PUHALF_PTR;
  defina_tipo inteiro HALF_PTR,*PHALF_PTR;

  estático __inline sem_sinal longo HandleToULong(constante vazio *h) { retorne((sem_sinal longo) (ULONG_PTR) h); }
  estático __inline longo HandleToLong(constante vazio *h) { retorne((longo) (LONG_PTR) h); }
  estático __inline vazio *ULongToHandle(constante sem_sinal longo h) { retorne((vazio *) (UINT_PTR) h); }
  estático __inline vazio *LongToHandle(constante longo h) { retorne((vazio *) (INT_PTR) h); }
  estático __inline sem_sinal longo PtrToUlong(constante vazio *p) { retorne((sem_sinal longo) (ULONG_PTR) p); }
  estático __inline sem_sinal inteiro PtrToUint(constante vazio *p) { retorne((sem_sinal inteiro) (UINT_PTR) p); }
  estático __inline sem_sinal curto PtrToUshort(constante vazio *p) { retorne((sem_sinal curto) (sem_sinal longo) (ULONG_PTR) p); }
  estático __inline longo PtrToLong(constante vazio *p) { retorne((longo) (LONG_PTR) p); }
  estático __inline inteiro PtrToInt(constante vazio *p) { retorne((inteiro) (INT_PTR) p); }
  estático __inline curto PtrToShort(constante vazio *p) { retorne((curto) (longo) (LONG_PTR) p); }
  estático __inline vazio *IntToPtr(constante inteiro i) { retorne((vazio *)(INT_PTR)i); }
  estático __inline vazio *UIntToPtr(constante sem_sinal inteiro ui) { retorne((vazio *)(UINT_PTR)ui); }
  estático __inline vazio *LongToPtr(constante longo l) { retorne((vazio *)(LONG_PTR)l); }
  estático __inline vazio *ULongToPtr(constante sem_sinal longo ul) { retorne((vazio *)(ULONG_PTR)ul); }

#defina PtrToPtr64(p) ((vazio *) p)
#defina Ptr64ToPtr(p) ((vazio *) p)
#defina HandleToHandle64(h) (PtrToPtr64(h))
#defina Handle64ToHandle(h) (Ptr64ToPtr(h))

  estático __inline vazio *Ptr32ToPtr(constante vazio *p) { retorne (vazio *)p; }
  estático __inline vazio *Handle32ToHandle(constante vazio *h) { retorne((vazio *) h); }
  estático __inline vazio *PtrToPtr32(constante vazio *p) { retorne((vazio *) (ULONG_PTR) p); }

#defina HandleToHandle32(h) (PtrToPtr32(h))
#senão

#defina ADDRESS_TAG_BIT 0x80000000UL

  defina_tipo sem_sinal curto UHALF_PTR,*PUHALF_PTR;
  defina_tipo curto HALF_PTR,*PHALF_PTR;
  defina_tipo longo SHANDLE_PTR;
  defina_tipo sem_sinal longo HANDLE_PTR;

#defina HandleToULong(h) ((ULONG)(ULONG_PTR)(h))
#defina HandleToLong(h) ((LONG)(LONG_PTR) (h))
#defina ULongToHandle(ul) ((HANDLE)(ULONG_PTR) (ul))
#defina LongToHandle(h) ((HANDLE)(LONG_PTR) (h))
#defina PtrToUlong(p) ((ULONG)(ULONG_PTR) (p))
#defina PtrToLong(p) ((LONG)(LONG_PTR) (p))
#defina PtrToUint(p) ((UINT)(UINT_PTR) (p))
#defina PtrToInt(p) ((INT)(INT_PTR) (p))
#defina PtrToUshort(p) ((sem_sinal curto)(ULONG_PTR)(p))
#defina PtrToShort(p) ((curto)(LONG_PTR)(p))
#defina IntToPtr(i) ((VOID *)(INT_PTR)((inteiro)i))
#defina UIntToPtr(ui) ((VOID *)(UINT_PTR)((sem_sinal inteiro)ui))
#defina LongToPtr(l) ((VOID *)(LONG_PTR)((longo)l))
#defina ULongToPtr(ul) ((VOID *)(ULONG_PTR)((sem_sinal longo)ul))

  estático __inline vazio *PtrToPtr64(constante vazio *p) { retorne((vazio *) (ULONG_PTR)p); }
  estático __inline vazio *Ptr64ToPtr(constante vazio *p) { retorne((vazio *) (ULONG_PTR) p); }
  estático __inline vazio *HandleToHandle64(constante vazio *h) { retorne((vazio *) h); }
  estático __inline vazio *Handle64ToHandle(constante vazio *h) { retorne((vazio *) (ULONG_PTR) h); }

#defina Ptr32ToPtr(p) ((vazio *) p)
#defina Handle32ToHandle(h) (Ptr32ToPtr(h))
#defina PtrToPtr32(p) ((vazio *) p)
#defina HandleToHandle32(h) (PtrToPtr32(h))
#fim_se

#defina HandleToUlong(h) HandleToULong(h)
#defina UlongToHandle(ul) ULongToHandle(ul)
#defina UlongToPtr(ul) ULongToPtr(ul)
#defina UintToPtr(ui) UIntToPtr(ui)

#defina MAXUINT_PTR (~((UINT_PTR)0))
#defina MAXINT_PTR ((INT_PTR)(MAXUINT_PTR >> 1))
#defina MININT_PTR (~MAXINT_PTR)

#defina MAXULONG_PTR (~((ULONG_PTR)0))
#defina MAXLONG_PTR ((LONG_PTR)(MAXULONG_PTR >> 1))
#defina MINLONG_PTR (~MAXLONG_PTR)

#defina MAXUHALF_PTR ((UHALF_PTR)~0)
#defina MAXHALF_PTR ((HALF_PTR)(MAXUHALF_PTR >> 1))
#defina MINHALF_PTR (~MAXHALF_PTR)

  defina_tipo ULONG_PTR SIZE_T,*PSIZE_T;
  defina_tipo LONG_PTR SSIZE_T,*PSSIZE_T;
  defina_tipo ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  defina_tipo __int64 LONG64,*PLONG64;
  defina_tipo sem_sinal __int64 ULONG64,*PULONG64;
  defina_tipo sem_sinal __int64 DWORD64,*PDWORD64;
  defina_tipo ULONG_PTR KAFFINITY;
  defina_tipo KAFFINITY *PKAFFINITY;

#se_definido __cplusplus
}
#fim_se
#fim_se
