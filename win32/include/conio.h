/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_CONIO
#defina _INC_CONIO

#inclua <_mingw.h>

#se_definido __cplusplus
externo "C" {
#fim_se

  _CRTIMP caractere *_cgets(caractere *_Buffer);
  _CRTIMP inteiro __cdecl _cprintf(constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _cputs(constante caractere *_Str);
  _CRTIMP inteiro __cdecl _cscanf(constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _cscanf_l(constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _getch(vazio);
  _CRTIMP inteiro __cdecl _getche(vazio);
  _CRTIMP inteiro __cdecl _vcprintf(constante caractere *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _cprintf_p(constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _vcprintf_p(constante caractere *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _cprintf_l(constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcprintf_l(constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _cprintf_p_l(constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcprintf_p_l(constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _kbhit(vazio);

#se definido(_X86_) && !definido(__x86_64)
  inteiro __cdecl _inp(sem_sinal curto);
  sem_sinal curto __cdecl _inpw(sem_sinal curto);
  sem_sinal longo __cdecl _inpd(sem_sinal curto);
  inteiro __cdecl _outp(sem_sinal curto,inteiro);
  sem_sinal curto __cdecl _outpw(sem_sinal curto,sem_sinal curto);
  sem_sinal longo __cdecl _outpd(sem_sinal curto,sem_sinal longo);
#fim_se

  _CRTIMP inteiro __cdecl _putch(inteiro _Ch);
  _CRTIMP inteiro __cdecl _ungetch(inteiro _Ch);
  _CRTIMP inteiro __cdecl _getch_nolock(vazio);
  _CRTIMP inteiro __cdecl _getche_nolock(vazio);
  _CRTIMP inteiro __cdecl _putch_nolock(inteiro _Ch);
  _CRTIMP inteiro __cdecl _ungetch_nolock(inteiro _Ch);

#se_não_definido _WCONIO_DEFINED
#defina _WCONIO_DEFINED

#se_não_definido WEOF
#defina WEOF (wint_t)(0xFFFF)
#fim_se

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(vazio);
  _CRTIMP wint_t __cdecl _getwche(vazio);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP inteiro __cdecl _cputws(constante wchar_t *_String);
  _CRTIMP inteiro __cdecl _cwprintf(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _cwscanf(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _cwscanf_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcwprintf(constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _cwprintf_p(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vcwprintf_p(constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _cwprintf_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcwprintf_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _cwprintf_p_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcwprintf_p_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(vazio);
  _CRTIMP wint_t __cdecl _getwche_nolock(vazio);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#fim_se

#se_não_definido	NO_OLDNAMES
  caractere *__cdecl cgets(caractere *_Buffer);
  inteiro __cdecl cprintf(constante caractere *_Format,...);
  inteiro __cdecl cputs(constante caractere *_Str);
  inteiro __cdecl cscanf(constante caractere *_Format,...);
  inteiro __cdecl getch(vazio);
  inteiro __cdecl getche(vazio);
  inteiro __cdecl kbhit(vazio);
  inteiro __cdecl putch(inteiro _Ch);
  inteiro __cdecl ungetch(inteiro _Ch);

#se (definido(_X86_) && !definido(__x86_64))
  inteiro __cdecl inp(sem_sinal curto);
  sem_sinal curto __cdecl inpw(sem_sinal curto);
  inteiro __cdecl outp(sem_sinal curto,inteiro);
  sem_sinal curto __cdecl outpw(sem_sinal curto,sem_sinal curto);
#fim_se

  /* I/O intrin functions.  */
  __CRT_INLINE sem_sinal caractere __inbyte(sem_sinal curto Port)
  {
      sem_sinal caractere value;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (value)
          : "Nd" (Port));
      retorne value;
  }
  __CRT_INLINE sem_sinal curto __inword(sem_sinal curto Port)
  {
      sem_sinal curto value;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (value)
          : "Nd" (Port));
      retorne value;
  }
  __CRT_INLINE sem_sinal longo __indword(sem_sinal curto Port)
  {
      sem_sinal longo value;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (value)
          : "Nd" (Port));
      retorne value;
  }
  __CRT_INLINE vazio __outbyte(sem_sinal curto Port,sem_sinal caractere Data)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE vazio __outword(sem_sinal curto Port,sem_sinal curto Data)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE vazio __outdword(sem_sinal curto Port,sem_sinal longo Data)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE vazio __inbytestring(sem_sinal curto Port,sem_sinal caractere *Buffer,sem_sinal longo Count)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }
  __CRT_INLINE vazio __inwordstring(sem_sinal curto Port,sem_sinal curto *Buffer,sem_sinal longo Count)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }
  __CRT_INLINE vazio __indwordstring(sem_sinal curto Port,sem_sinal longo *Buffer,sem_sinal longo Count)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }

  __CRT_INLINE vazio __outbytestring(sem_sinal curto Port,sem_sinal caractere *Buffer,sem_sinal longo Count)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }
  __CRT_INLINE vazio __outwordstring(sem_sinal curto Port,sem_sinal curto *Buffer,sem_sinal longo Count)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }
  __CRT_INLINE vazio __outdwordstring(sem_sinal curto Port,sem_sinal longo *Buffer,sem_sinal longo Count)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }

  __CRT_INLINE sem_sinal __int64 __readcr0(vazio)
  {
      sem_sinal __int64 value;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [value] "=q" (value));
      retorne value;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to faça this para _WIN64 and _WIN32
     separately.  */
 
#se_definido _WIN64
  __CRT_INLINE vazio __writecr0(sem_sinal __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE sem_sinal __int64 __readcr2(vazio)
  {
      sem_sinal __int64 value;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [value] "=q" (value));
      retorne value;
  }

 __CRT_INLINE vazio __writecr2(sem_sinal __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE sem_sinal __int64 __readcr3(vazio)
  {
      sem_sinal __int64 value;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [value] "=q" (value));
      retorne value;
  }

 __CRT_INLINE vazio __writecr3(sem_sinal __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE sem_sinal __int64 __readcr4(vazio)
  {
      sem_sinal __int64 value;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [value] "=q" (value));
      retorne value;
  }

 __CRT_INLINE vazio __writecr4(sem_sinal __int64 Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE sem_sinal __int64 __readcr8(vazio)
  {
      sem_sinal __int64 value;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [value] "=q" (value));
      retorne value;
  }

 __CRT_INLINE vazio __writecr8(sem_sinal __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#senão_se definido(_WIN32)

  __CRT_INLINE vazio __writecr0(sem_sinal Data)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE sem_sinal longo __readcr2(vazio)
  {
      sem_sinal longo value;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [value] "=q" (value));
      retorne value;
  }

 __CRT_INLINE vazio __writecr2(sem_sinal Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE sem_sinal longo __readcr3(vazio)
  {
      sem_sinal longo value;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [value] "=q" (value));
      retorne value;
  }

 __CRT_INLINE vazio __writecr3(sem_sinal Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE sem_sinal longo __readcr4(vazio)
  {
      sem_sinal longo value;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [value] "=q" (value));
      retorne value;
  }

 __CRT_INLINE vazio __writecr4(sem_sinal Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE sem_sinal longo __readcr8(vazio)
 {
   sem_sinal longo value;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [value] "=q" (value));
     retorne value;
 }

 __CRT_INLINE vazio __writecr8(sem_sinal Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#fim_se

  __CRT_INLINE sem_sinal __int64 __readmsr(sem_sinal longo msr)
  {
      sem_sinal __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      retorne val1 | (val2 << 32);
  }

 __CRT_INLINE vazio __writemsr (sem_sinal longo msr, sem_sinal __int64 Value)
 {
    sem_sinal longo val1 = Value, val2 = Value >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE sem_sinal __int64 __rdtsc(vazio)
  {
      sem_sinal __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      retorne val1 | (val2 << 32);
  }

  __CRT_INLINE vazio __cpuid(inteiro CPUInfo[4], inteiro InfoType)
  {
      __asm__ __volatile__ (
          "cpuid"
          : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
          : "a" (InfoType));
  }

#fim_se

#se_definido __cplusplus
}
#fim_se

#inclua <sec_api/conio_s.h>

#fim_se
