/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _WINNT_
#defina _WINNT_

#se_definido __cplusplus
externo "C" {
#fim_se

#inclua <ctype.h>
#defina ANYSIZE_ARRAY 1

//gr #inclua <specstrings.h>

#defina RESTRICTED_POINTER

#se_não_definido __CRT_UNALIGNED
#defina __CRT_UNALIGNED
#fim_se

#se definido(__ia64__) || definido(__x86_64)
#defina UNALIGNED __CRT_UNALIGNED
#se_definido _WIN64
#defina UNALIGNED64 __CRT_UNALIGNED
#senão
#defina UNALIGNED64
#fim_se
#senão
#defina UNALIGNED
#defina UNALIGNED64
#fim_se

#se !definido(I_X86_) && !definido(_IA64_) && !definido(_AMD64_) && (definido(_X86_) && !definido(__x86_64))
#defina I_X86_
#fim_se

#se !definido(I_X86_) && !definido(_IA64_) && !definido(_AMD64_) && definido(__x86_64)
#defina _AMD64_
#fim_se

#se !definido(I_X86_) && !(definido(_X86_) && !definido(__x86_64)) && !definido(_AMD64_) && definido(__ia64__)
#se !definido(_IA64_)
#defina _IA64_
#fim_se
#fim_se


#se_definido _WIN64
#defina MAX_NATURAL_ALIGNMENT sizeof(ULONGLONG)
#defina MEMORY_ALLOCATION_ALIGNMENT 16
#senão
#defina MAX_NATURAL_ALIGNMENT sizeof(DWORD)
#defina MEMORY_ALLOCATION_ALIGNMENT 8
#fim_se

#se_definido __cplusplus
#defina TYPE_ALIGNMENT(t) __alignof__ (t)
#senão
#defina TYPE_ALIGNMENT(t) FIELD_OFFSET(estrutura { caractere x; t test; },test)
#fim_se

#se_definido _WIN64
#se_definido _AMD64_
#defina PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#senão_se definido(_IA64_)
#defina PROBE_ALIGNMENT(_s) (TYPE_ALIGNMENT(_s) > TYPE_ALIGNMENT(DWORD) ? TYPE_ALIGNMENT(_s) : TYPE_ALIGNMENT(DWORD))
#senão
#erro No Target Architecture
#fim_se
#defina PROBE_ALIGNMENT32(_s) TYPE_ALIGNMENT(DWORD)
#senão
#defina PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#fim_se

#defina C_ASSERT(e) defina_tipo caractere __C_ASSERT__[(e)?1:-1]

#inclua <basetsd.h>

#se definido(_X86_) || definido(__ia64__) || definido(__x86_64)
#defina DECLSPEC_IMPORT __declspec(dllimport)
#senão
#defina DECLSPEC_IMPORT
#fim_se

#se_não_definido DECLSPEC_NORETURN
#defina DECLSPEC_NORETURN __declspec(noreturn)
#fim_se

#se_não_definido DECLSPEC_ALIGN
#defina DECLSPEC_ALIGN(x) __attribute__ ((aligned(x)))
#fim_se

#se_não_definido SYSTEM_CACHE_ALIGNMENT_SIZE
#se definido(_AMD64_) || definido(I_X86_)
#defina SYSTEM_CACHE_ALIGNMENT_SIZE 64
#senão
#defina SYSTEM_CACHE_ALIGNMENT_SIZE 128
#fim_se
#fim_se

#se_não_definido DECLSPEC_CACHEALIGN
#defina DECLSPEC_CACHEALIGN DECLSPEC_ALIGN(SYSTEM_CACHE_ALIGNMENT_SIZE)
#fim_se

#se_não_definido DECLSPEC_UUID
#defina DECLSPEC_UUID(x)
#fim_se

#se_não_definido DECLSPEC_NOVTABLE
#defina DECLSPEC_NOVTABLE
#fim_se

#se_não_definido DECLSPEC_SELECTANY
#defina DECLSPEC_SELECTANY __declspec(selectany)
#fim_se

#se_não_definido NOP_FUNCTION
#defina NOP_FUNCTION (vazio)0
#fim_se

#se_não_definido DECLSPEC_NOINLINE
#defina DECLSPEC_NOINLINE
#fim_se

#se_não_definido FORCEINLINE
#defina FORCEINLINE estático __inline__
#fim_se

#se_não_definido DECLSPEC_DEPRECATED
#defina DECLSPEC_DEPRECATED __declspec(deprecated)
#defina DEPRECATE_SUPPORTED
#fim_se

#defina DECLSPEC_DEPRECATED_DDK
#defina PRAGMA_DEPRECATED_DDK 0

  defina_tipo vazio *PVOID;
  defina_tipo vazio *PVOID64;

#defina NTAPI __stdcall
#defina NTSYSAPI DECLSPEC_IMPORT
#defina NTSYSCALLAPI DECLSPEC_IMPORT

#se_não_definido VOID
#defina VOID vazio
  defina_tipo caractere CHAR;
  defina_tipo curto SHORT;
  defina_tipo longo LONG;
#fim_se

  defina_tipo wchar_t WCHAR;
  defina_tipo WCHAR *PWCHAR,*LPWCH,*PWCH;
  defina_tipo CONST WCHAR *LPCWCH,*PCWCH;
  defina_tipo WCHAR *NWPSTR,*LPWSTR,*PWSTR;
  defina_tipo PWSTR *PZPWSTR;
  defina_tipo CONST PWSTR *PCZPWSTR;
  defina_tipo WCHAR UNALIGNED *LPUWSTR,*PUWSTR;
  defina_tipo CONST WCHAR *LPCWSTR,*PCWSTR;
  defina_tipo PCWSTR *PZPCWSTR;
  defina_tipo CONST WCHAR UNALIGNED *LPCUWSTR,*PCUWSTR;
  defina_tipo CHAR *PCHAR,*LPCH,*PCH;
  defina_tipo CONST CHAR *LPCCH,*PCCH;
  defina_tipo CHAR *NPSTR,*LPSTR,*PSTR;
  defina_tipo PSTR *PZPSTR;
  defina_tipo CONST PSTR *PCZPSTR;
  defina_tipo CONST CHAR *LPCSTR,*PCSTR;
  defina_tipo PCSTR *PZPCSTR;

#se_definido UNICODE
#se_não_definido _TCHAR_DEFINED
#defina _TCHAR_DEFINED
  defina_tipo WCHAR TCHAR,*PTCHAR;
  defina_tipo WCHAR TBYTE ,*PTBYTE;
#fim_se

  defina_tipo LPWSTR LPTCH,PTCH;
  defina_tipo LPWSTR PTSTR,LPTSTR;
  defina_tipo LPCWSTR PCTSTR,LPCTSTR;
  defina_tipo LPUWSTR PUTSTR,LPUTSTR;
  defina_tipo LPCUWSTR PCUTSTR,LPCUTSTR;
  defina_tipo LPWSTR LP;
#defina __TEXT(quote) L##quote
#senão
#se_não_definido _TCHAR_DEFINED
#defina _TCHAR_DEFINED
  defina_tipo caractere TCHAR,*PTCHAR;
  defina_tipo sem_sinal caractere TBYTE ,*PTBYTE;
#fim_se

  defina_tipo LPSTR LPTCH,PTCH;
  defina_tipo LPSTR PTSTR,LPTSTR,PUTSTR,LPUTSTR;
  defina_tipo LPCSTR PCTSTR,LPCTSTR,PCUTSTR,LPCUTSTR;
#defina __TEXT(quote) quote
#fim_se

#defina TEXT(quote) __TEXT(quote)

  defina_tipo SHORT *PSHORT;
  defina_tipo LONG *PLONG;

  defina_tipo vazio *HANDLE;
#defina DECLARE_HANDLE(name) estrutura name##__ { inteiro unused; }; defina_tipo estrutura name##__ *name
  defina_tipo HANDLE *PHANDLE;

  defina_tipo BYTE FCHAR;
  defina_tipo WORD FSHORT;
  defina_tipo DWORD FLONG;

#se_não_definido _HRESULT_DEFINED
#defina _HRESULT_DEFINED
  defina_tipo LONG HRESULT;
#fim_se

#se_definido __cplusplus
#defina EXTERN_C externo "C"
#senão
#defina EXTERN_C externo
#fim_se

#defina STDMETHODCALLTYPE WINAPI
#defina STDMETHODVCALLTYPE __cdecl
#defina STDAPICALLTYPE WINAPI
#defina STDAPIVCALLTYPE __cdecl
#defina STDAPI EXTERN_C HRESULT WINAPI
#defina STDAPI_(type) EXTERN_C type WINAPI
#defina STDMETHODIMP HRESULT WINAPI
#defina STDMETHODIMP_(type) type WINAPI
#defina STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#defina STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE
#defina STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#defina STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

  defina_tipo caractere CCHAR;
#se_não_definido _LCID_DEFINED
#defina _LCID_DEFINED
defina_tipo DWORD LCID;
#fim_se
  defina_tipo PDWORD PLCID;
#se_não_definido _LANGID_DEFINED
#defina _LANGID_DEFINED
  defina_tipo WORD LANGID;
#fim_se
#defina APPLICATION_ERROR_MASK 0x20000000
#defina ERROR_SEVERITY_SUCCESS 0x00000000
#defina ERROR_SEVERITY_INFORMATIONAL 0x40000000
#defina ERROR_SEVERITY_WARNING 0x80000000
#defina ERROR_SEVERITY_ERROR 0xC0000000

#se_definido __ia64__
  __declspec(align(16))
#fim_se
    defina_tipo estrutura _FLOAT128 {
      __int64 LowPart;
      __int64 HighPart;
  } FLOAT128;

  defina_tipo FLOAT128 *PFLOAT128;

#defina _ULONGLONG_
#se((!(definido(_X86_) && !definido(__x86_64)) || (definido(_INTEGRAL_MAX_BITS) && _INTEGRAL_MAX_BITS >= 64)))
  defina_tipo __int64 LONGLONG;
  defina_tipo sem_sinal __int64 ULONGLONG;

#defina MAXLONGLONG (0x7fffffffffffffff)
#senão

  defina_tipo duplo LONGLONG;
  defina_tipo duplo ULONGLONG;
#fim_se

  defina_tipo LONGLONG *PLONGLONG;
  defina_tipo ULONGLONG *PULONGLONG;

  defina_tipo LONGLONG USN;

  defina_tipo união _LARGE_INTEGER {
    estrutura {
      DWORD LowPart;
      LONG HighPart;
    };
    estrutura {
      DWORD LowPart;
      LONG HighPart;
    } u;
    LONGLONG QuadPart;
  } LARGE_INTEGER;

  defina_tipo LARGE_INTEGER *PLARGE_INTEGER;

  defina_tipo união _ULARGE_INTEGER {
    estrutura {
      DWORD LowPart;
      DWORD HighPart;
    };
    estrutura {
      DWORD LowPart;
      DWORD HighPart;
    } u;
    ULONGLONG QuadPart;
  } ULARGE_INTEGER;

  defina_tipo ULARGE_INTEGER *PULARGE_INTEGER;

  defina_tipo estrutura _LUID {
    DWORD LowPart;
    LONG HighPart;
  } LUID,*PLUID;

#defina _DWORDLONG_
  defina_tipo ULONGLONG DWORDLONG;
  defina_tipo DWORDLONG *PDWORDLONG;

#se_definido RC_INVOKED
#defina Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#defina UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#defina Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#senão_se (definido(_X86_) && !definido(__x86_64))
#defina Int32x32To64(a,b) (LONGLONG)((LONGLONG)(LONG)(a) *(LONG)(b))
#defina UInt32x32To64(a,b) (ULONGLONG)((ULONGLONG)(DWORD)(a) *(DWORD)(b))
#defina Int64ShrlMod32(a,b) ((DWORDLONG)(a)>>(b))
#senão_se definido(__ia64__) || definido(__x86_64)
#defina Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#defina UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#defina Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#senão
#erro Must defina a target architecture.
#fim_se

#defina Int64ShraMod32(a,b) ((LONGLONG)(a) >> (b))
#defina Int64ShllMod32(a,b) ((ULONGLONG)(a) << (b))

#se_definido __cplusplus
  externo "C" {
#fim_se

#se_definido __x86_64

#defina RotateLeft8 _rotl8
#defina RotateLeft16 _rotl16
#defina RotateRight8 _rotr8
#defina RotateRight16 _rotr16

    sem_sinal caractere __cdecl _rotl8(sem_sinal caractere Value,sem_sinal caractere Shift);
    sem_sinal curto __cdecl _rotl16(sem_sinal curto Value,sem_sinal caractere Shift);
    sem_sinal caractere __cdecl _rotr8(sem_sinal caractere Value,sem_sinal caractere Shift);
    sem_sinal curto __cdecl _rotr16(sem_sinal curto Value,sem_sinal caractere Shift);
#fim_se

#defina RotateLeft32 _rotl
#defina RotateLeft64 _rotl64
#defina RotateRight32 _rotr
#defina RotateRight64 _rotr64

    sem_sinal inteiro __cdecl _rotl(sem_sinal inteiro Value,inteiro Shift);
    sem_sinal __int64 __cdecl _rotl64(sem_sinal __int64 Value,inteiro Shift);
    sem_sinal inteiro __cdecl _rotr(sem_sinal inteiro Value,inteiro Shift);
    sem_sinal __int64 __cdecl _rotr64(sem_sinal __int64 Value,inteiro Shift);
#se_definido __cplusplus
  }
#fim_se

#defina ANSI_NULL ((CHAR)0)
#defina UNICODE_NULL ((WCHAR)0)
#defina UNICODE_STRING_MAX_BYTES ((WORD) 65534)
#defina UNICODE_STRING_MAX_CHARS (32767)

#se_não_definido _BOOLEAN_
#defina _BOOLEAN_
  defina_tipo BYTE BOOLEAN;
#fim_se
  defina_tipo BOOLEAN *PBOOLEAN;

  defina_tipo estrutura _LIST_ENTRY {
    estrutura _LIST_ENTRY *Flink;
    estrutura _LIST_ENTRY *Blink;
  } LIST_ENTRY,*PLIST_ENTRY,*RESTRICTED_POINTER PRLIST_ENTRY;

  defina_tipo estrutura _SINGLE_LIST_ENTRY {
    estrutura _SINGLE_LIST_ENTRY *Next;
  } SINGLE_LIST_ENTRY,*PSINGLE_LIST_ENTRY;

  defina_tipo estrutura LIST_ENTRY32 {
    DWORD Flink;
    DWORD Blink;
  } LIST_ENTRY32;
  defina_tipo LIST_ENTRY32 *PLIST_ENTRY32;

  defina_tipo estrutura LIST_ENTRY64 {
    ULONGLONG Flink;
    ULONGLONG Blink;
  } LIST_ENTRY64;
  defina_tipo LIST_ENTRY64 *PLIST_ENTRY64;

#inclua <guiddef.h>

#se_não_definido __OBJECTID_DEFINED
#defina __OBJECTID_DEFINED
  defina_tipo estrutura _OBJECTID {
    GUID Lineage;
    DWORD Uniquifier;
  } OBJECTID;
#fim_se

#defina MINCHAR 0x80
#defina MAXCHAR 0x7f
#defina MINSHORT 0x8000
#defina MAXSHORT 0x7fff
#defina MINLONG 0x80000000
#defina MAXLONG 0x7fffffff
#defina MAXBYTE 0xff
#defina MAXWORD 0xffff
#defina MAXDWORD 0xffffffff

#defina FIELD_OFFSET(type,field) ((LONG)(LONG_PTR)&(((type *)0)->field))
#defina RTL_FIELD_SIZE(type,field) (sizeof(((type *)0)->field))
#defina RTL_SIZEOF_THROUGH_FIELD(type,field) (FIELD_OFFSET(type,field) + RTL_FIELD_SIZE(type,field))
#defina RTL_CONTAINS_FIELD(Struct,Size,Field) ((((PCHAR)(&(Struct)->Field)) + sizeof((Struct)->Field)) <= (((PCHAR)(Struct))+(Size)))
#defina RTL_NUMBER_OF_V1(A) (sizeof(A)/sizeof((A)[0]))
#defina RTL_NUMBER_OF_V2(A) RTL_NUMBER_OF_V1(A)

#se_definido ENABLE_RTL_NUMBER_OF_V2
#defina RTL_NUMBER_OF(A) RTL_NUMBER_OF_V2(A)
#senão
#defina RTL_NUMBER_OF(A) RTL_NUMBER_OF_V1(A)
#fim_se

#defina ARRAYSIZE(A) RTL_NUMBER_OF_V2(A)
#defina _ARRAYSIZE(A) RTL_NUMBER_OF_V1(A)

#defina RTL_FIELD_TYPE(type,field) (((type*)0)->field)
#defina RTL_NUMBER_OF_FIELD(type,field) (RTL_NUMBER_OF(RTL_FIELD_TYPE(type,field)))
#defina RTL_PADDING_BETWEEN_FIELDS(T,F1,F2) ((FIELD_OFFSET(T,F2) > FIELD_OFFSET(T,F1)) ? (FIELD_OFFSET(T,F2) - FIELD_OFFSET(T,F1) - RTL_FIELD_SIZE(T,F1)) : (FIELD_OFFSET(T,F1) - FIELD_OFFSET(T,F2) - RTL_FIELD_SIZE(T,F2)))

#se_definido __cplusplus
#defina RTL_CONST_CAST(type) const_cast<type>
#senão
#defina RTL_CONST_CAST(type) (type)
#fim_se

#defina RTL_BITS_OF(sizeOfArg) (sizeof(sizeOfArg) *8)
#defina RTL_BITS_OF_FIELD(type,field) (RTL_BITS_OF(RTL_FIELD_TYPE(type,field)))
#defina CONTAINING_RECORD(address,type,field) ((type *)((PCHAR)(address) - (ULONG_PTR)(&((type *)0)->field)))

#defina VER_SERVER_NT 0x80000000
#defina VER_WORKSTATION_NT 0x40000000
#defina VER_SUITE_SMALLBUSINESS 0x00000001
#defina VER_SUITE_ENTERPRISE 0x00000002
#defina VER_SUITE_BACKOFFICE 0x00000004
#defina VER_SUITE_COMMUNICATIONS 0x00000008
#defina VER_SUITE_TERMINAL 0x00000010
#defina VER_SUITE_SMALLBUSINESS_RESTRICTED 0x00000020
#defina VER_SUITE_EMBEDDEDNT 0x00000040
#defina VER_SUITE_DATACENTER 0x00000080
#defina VER_SUITE_SINGLEUSERTS 0x00000100
#defina VER_SUITE_PERSONAL 0x00000200
#defina VER_SUITE_BLADE 0x00000400
#defina VER_SUITE_EMBEDDED_RESTRICTED 0x00000800
#defina VER_SUITE_SECURITY_APPLIANCE 0x00001000
#defina VER_SUITE_STORAGE_SERVER 0x00002000
#defina VER_SUITE_COMPUTE_SERVER 0x00004000

#defina PRODUCT_UNDEFINED                       0x0

#defina PRODUCT_ULTIMATE                        0x1
#defina PRODUCT_HOME_BASIC                      0x2
#defina PRODUCT_HOME_PREMIUM                    0x3
#defina PRODUCT_ENTERPRISE                      0x4
#defina PRODUCT_HOME_BASIC_N                    0x5
#defina PRODUCT_BUSINESS                        0x6
#defina PRODUCT_STANDARD_SERVER                 0x7
#defina PRODUCT_DATACENTER_SERVER               0x8
#defina PRODUCT_SMALLBUSINESS_SERVER            0x9
#defina PRODUCT_ENTERPRISE_SERVER               0xa
#defina PRODUCT_STARTER                         0xb
#defina PRODUCT_DATACENTER_SERVER_CORE          0xc
#defina PRODUCT_STANDARD_SERVER_CORE            0xd
#defina PRODUCT_ENTERPRISE_SERVER_CORE          0xe
#defina PRODUCT_ENTERPRISE_SERVER_IA64          0xf
#defina PRODUCT_BUSINESS_N                      0x10
#defina PRODUCT_WEB_SERVER                      0x11
#defina PRODUCT_CLUSTER_SERVER                  0x12
#defina PRODUCT_HOME_SERVER                     0x13
#defina PRODUCT_STORAGE_EXPRESS_SERVER          0x14
#defina PRODUCT_STORAGE_STANDARD_SERVER         0x15
#defina PRODUCT_STORAGE_WORKGROUP_SERVER        0x16
#defina PRODUCT_STORAGE_ENTERPRISE_SERVER       0x17
#defina PRODUCT_SERVER_FOR_SMALLBUSINESS        0x18
#defina PRODUCT_SMALLBUSINESS_SERVER_PREMIUM    0x19

#defina PRODUCT_UNLICENSED                      0xabcdabcd

#defina LANG_NEUTRAL 0x00
#defina LANG_INVARIANT 0x7f

#defina LANG_AFRIKAANS 0x36
#defina LANG_ALBANIAN 0x1c
#defina LANG_ALSATIAN 0x84
#defina LANG_AMHARIC 0x5e
#defina LANG_ARABIC 0x01
#defina LANG_ARMENIAN 0x2b
#defina LANG_ASSAMESE 0x4d
#defina LANG_AZERI 0x2c
#defina LANG_BASHKIR 0x6d
#defina LANG_BASQUE 0x2d
#defina LANG_BELARUSIAN 0x23
#defina LANG_BENGALI 0x45
#defina LANG_BRETON 0x7e
#defina LANG_BOSNIAN 0x1a
#defina LANG_BOSNIAN_NEUTRAL 0x781a
#defina LANG_BULGARIAN 0x02
#defina LANG_CATALAN 0x03
#defina LANG_CHINESE 0x04
#defina LANG_CHINESE_SIMPLIFIED 0x04
#defina LANG_CHINESE_TRADITIONAL 0x7c04
#defina LANG_CORSICAN 0x83
#defina LANG_CROATIAN 0x1a
#defina LANG_CZECH 0x05
#defina LANG_DANISH 0x06
#defina LANG_DARI 0x8c
#defina LANG_DIVEHI 0x65
#defina LANG_DUTCH 0x13
#defina LANG_ENGLISH 0x09
#defina LANG_ESTONIAN 0x25
#defina LANG_FAEROESE 0x38
#defina LANG_FARSI 0x29
#defina LANG_FILIPINO 0x64
#defina LANG_FINNISH 0x0b
#defina LANG_FRENCH 0x0c
#defina LANG_FRISIAN 0x62
#defina LANG_GALICIAN 0x56
#defina LANG_GEORGIAN 0x37
#defina LANG_GERMAN 0x07
#defina LANG_GREEK 0x08
#defina LANG_GREENLANDIC 0x6f
#defina LANG_GUJARATI 0x47
#defina LANG_HAUSA 0x68
#defina LANG_HEBREW 0x0d
#defina LANG_HINDI 0x39
#defina LANG_HUNGARIAN 0x0e
#defina LANG_ICELANDIC 0x0f
#defina LANG_IGBO 0x70
#defina LANG_INDONESIAN 0x21
#defina LANG_INUKTITUT 0x5d
#defina LANG_IRISH 0x3c
#defina LANG_ITALIAN 0x10
#defina LANG_JAPANESE 0x11
#defina LANG_KANNADA 0x4b
#defina LANG_KASHMIRI 0x60
#defina LANG_KAZAK 0x3f
#defina LANG_KHMER 0x53
#defina LANG_KICHE 0x86
#defina LANG_KINYARWANDA 0x87
#defina LANG_KONKANI 0x57
#defina LANG_KOREAN 0x12
#defina LANG_KYRGYZ 0x40
#defina LANG_LAO 0x54
#defina LANG_LATVIAN 0x26
#defina LANG_LITHUANIAN 0x27
#defina LANG_LOWER_SORBIAN 0x2e
#defina LANG_LUXEMBOURGISH 0x6e
#defina LANG_MACEDONIAN 0x2f
#defina LANG_MALAY 0x3e
#defina LANG_MALAYALAM 0x4c
#defina LANG_MALTESE 0x3a
#defina LANG_MANIPURI 0x58
#defina LANG_MAORI 0x81
#defina LANG_MAPUDUNGUN 0x7a
#defina LANG_MARATHI 0x4e
#defina LANG_MOHAWK 0x7c
#defina LANG_MONGOLIAN 0x50
#defina LANG_NEPALI 0x61
#defina LANG_NORWEGIAN 0x14
#defina LANG_OCCITAN 0x82
#defina LANG_ORIYA 0x48
#defina LANG_PASHTO 0x63
#defina LANG_PERSIAN 0x29
#defina LANG_POLISH 0x15
#defina LANG_PORTUGUESE 0x16
#defina LANG_PUNJABI 0x46
#defina LANG_QUECHUA 0x6b
#defina LANG_ROMANIAN 0x18
#defina LANG_RUSSIAN 0x19
#defina LANG_SAMI 0x3b
#defina LANG_ROMANSH 0x17
#defina LANG_SANSKRIT 0x4f
#defina LANG_SERBIAN 0x1a
#defina LANG_SERBIAN_NEUTRAL 0x7c1a
#defina LANG_SINDHI 0x59
#defina LANG_SINHALESE 0x5b
#defina LANG_SLOVAK 0x1b
#defina LANG_SLOVENIAN 0x24
#defina LANG_SOTHO 0x6c
#defina LANG_SPANISH 0x0a
#defina LANG_SWAHILI 0x41
#defina LANG_SWEDISH 0x1d
#defina LANG_SYRIAC 0x5a
#defina LANG_TAJIK 0x28
#defina LANG_TAMAZIGHT 0x5f
#defina LANG_TAMIL 0x49
#defina LANG_TATAR 0x44
#defina LANG_TELUGU 0x4a
#defina LANG_THAI 0x1e
#defina LANG_TIBETAN 0x51
#defina LANG_TIGRIGNA 0x73
#defina LANG_TSWANA 0x32
#defina LANG_TURKISH 0x1f
#defina LANG_TURKMEN 0x42
#defina LANG_UIGHUR 0x80
#defina LANG_UKRAINIAN 0x22
#defina LANG_UPPER_SORBIAN 0x2e
#defina LANG_URDU 0x20
#defina LANG_UZBEK 0x43
#defina LANG_VIETNAMESE 0x2a
#defina LANG_WELSH 0x52
#defina LANG_WOLOF 0x88
#defina LANG_XHOSA 0x34
#defina LANG_YAKUT 0x85
#defina LANG_YI 0x78
#defina LANG_YORUBA 0x6a
#defina LANG_ZULU 0x35

#defina SUBLANG_NEUTRAL 0x0
#defina SUBLANG_DEFAULT 0x1
#defina SUBLANG_SYS_DEFAULT 0x2
#defina SUBLANG_CUSTOM_DEFAULT 0x3
#defina SUBLANG_CUSTOM_UNSPECIFIED 0x4
#defina SUBLANG_UI_CUSTOM_DEFAULT 0x5

#defina SUBLANG_ARABIC_SAUDI_ARABIA 0x01
#defina SUBLANG_ARABIC_IRAQ 0x02
#defina SUBLANG_ARABIC_EGYPT 0x03
#defina SUBLANG_ARABIC_LIBYA 0x04
#defina SUBLANG_ARABIC_ALGERIA 0x05
#defina SUBLANG_ARABIC_MOROCCO 0x06
#defina SUBLANG_ARABIC_TUNISIA 0x07
#defina SUBLANG_ARABIC_OMAN 0x08
#defina SUBLANG_ARABIC_YEMEN 0x09
#defina SUBLANG_ARABIC_SYRIA 0x0a
#defina SUBLANG_ARABIC_JORDAN 0x0b
#defina SUBLANG_ARABIC_LEBANON 0x0c
#defina SUBLANG_ARABIC_KUWAIT 0x0d
#defina SUBLANG_ARABIC_UAE 0x0e
#defina SUBLANG_ARABIC_BAHRAIN 0x0f
#defina SUBLANG_ARABIC_QATAR 0x10
#defina SUBLANG_AZERI_LATIN 0x01
#defina SUBLANG_AZERI_CYRILLIC 0x02
#defina SUBLANG_CHINESE_TRADITIONAL 0x01
#defina SUBLANG_CHINESE_SIMPLIFIED 0x02
#defina SUBLANG_CHINESE_HONGKONG 0x03
#defina SUBLANG_CHINESE_SINGAPORE 0x04
#defina SUBLANG_CHINESE_MACAU 0x05
#defina SUBLANG_DUTCH 0x01
#defina SUBLANG_DUTCH_BELGIAN 0x02
#defina SUBLANG_ENGLISH_US 0x01
#defina SUBLANG_ENGLISH_UK 0x02
#defina SUBLANG_ENGLISH_AUS 0x03
#defina SUBLANG_ENGLISH_CAN 0x04
#defina SUBLANG_ENGLISH_NZ 0x05
#defina SUBLANG_ENGLISH_EIRE 0x06
#defina SUBLANG_ENGLISH_SOUTH_AFRICA 0x07
#defina SUBLANG_ENGLISH_JAMAICA 0x08
#defina SUBLANG_ENGLISH_CARIBBEAN 0x09
#defina SUBLANG_ENGLISH_BELIZE 0x0a
#defina SUBLANG_ENGLISH_TRINIDAD 0x0b
#defina SUBLANG_ENGLISH_ZIMBABWE 0x0c
#defina SUBLANG_ENGLISH_PHILIPPINES 0x0d
#defina SUBLANG_FRENCH 0x01
#defina SUBLANG_FRENCH_BELGIAN 0x02
#defina SUBLANG_FRENCH_CANADIAN 0x03
#defina SUBLANG_FRENCH_SWISS 0x04
#defina SUBLANG_FRENCH_LUXEMBOURG 0x05
#defina SUBLANG_FRENCH_MONACO 0x06
#defina SUBLANG_GERMAN 0x01
#defina SUBLANG_GERMAN_SWISS 0x02
#defina SUBLANG_GERMAN_AUSTRIAN 0x03
#defina SUBLANG_GERMAN_LUXEMBOURG 0x04
#defina SUBLANG_GERMAN_LIECHTENSTEIN 0x05
#defina SUBLANG_ITALIAN 0x01
#defina SUBLANG_ITALIAN_SWISS 0x02
#defina SUBLANG_KASHMIRI_SASIA 0x02
#defina SUBLANG_KASHMIRI_INDIA 0x02
#defina SUBLANG_KOREAN 0x01
#defina SUBLANG_LITHUANIAN 0x01
#defina SUBLANG_MALAY_MALAYSIA 0x01
#defina SUBLANG_MALAY_BRUNEI_DARUSSALAM 0x02
#defina SUBLANG_NEPALI_INDIA 0x02
#defina SUBLANG_NORWEGIAN_BOKMAL 0x01
#defina SUBLANG_NORWEGIAN_NYNORSK 0x02
#defina SUBLANG_PORTUGUESE 0x02
#defina SUBLANG_PORTUGUESE_BRAZILIAN 0x01
#defina SUBLANG_SERBIAN_LATIN 0x02
#defina SUBLANG_SERBIAN_CYRILLIC 0x03
#defina SUBLANG_SPANISH 0x01
#defina SUBLANG_SPANISH_MEXICAN 0x02
#defina SUBLANG_SPANISH_MODERN 0x03
#defina SUBLANG_SPANISH_GUATEMALA 0x04
#defina SUBLANG_SPANISH_COSTA_RICA 0x05
#defina SUBLANG_SPANISH_PANAMA 0x06
#defina SUBLANG_SPANISH_DOMINICAN_REPUBLIC 0x07
#defina SUBLANG_SPANISH_VENEZUELA 0x08
#defina SUBLANG_SPANISH_COLOMBIA 0x09
#defina SUBLANG_SPANISH_PERU 0x0a
#defina SUBLANG_SPANISH_ARGENTINA 0x0b
#defina SUBLANG_SPANISH_ECUADOR 0x0c
#defina SUBLANG_SPANISH_CHILE 0x0d
#defina SUBLANG_SPANISH_URUGUAY 0x0e
#defina SUBLANG_SPANISH_PARAGUAY 0x0f
#defina SUBLANG_SPANISH_BOLIVIA 0x10
#defina SUBLANG_SPANISH_EL_SALVADOR 0x11
#defina SUBLANG_SPANISH_HONDURAS 0x12
#defina SUBLANG_SPANISH_NICARAGUA 0x13
#defina SUBLANG_SPANISH_PUERTO_RICO 0x14
#defina SUBLANG_SWEDISH 0x01
#defina SUBLANG_SWEDISH_FINLAND 0x02
#defina SUBLANG_URDU_PAKISTAN 0x01
#defina SUBLANG_URDU_INDIA 0x02
#defina SUBLANG_UZBEK_LATIN 0x01
#defina SUBLANG_UZBEK_CYRILLIC 0x02

#defina SORT_DEFAULT 0x0
#defina SORT_INVARIANT_MATH 0x1

#defina SORT_JAPANESE_XJIS 0x0
#defina SORT_JAPANESE_UNICODE 0x1
#defina SORT_JAPANESE_RADICALSTROKE 0x4

#defina SORT_CHINESE_BIG5 0x0
#defina SORT_CHINESE_PRCP 0x0
#defina SORT_CHINESE_UNICODE 0x1
#defina SORT_CHINESE_PRC 0x2
#defina SORT_CHINESE_BOPOMOFO 0x3

#defina SORT_KOREAN_KSC 0x0
#defina SORT_KOREAN_UNICODE 0x1

#defina SORT_GERMAN_PHONE_BOOK 0x1

#defina SORT_HUNGARIAN_DEFAULT 0x0
#defina SORT_HUNGARIAN_TECHNICAL 0x1

#defina SORT_GEORGIAN_TRADITIONAL 0x0
#defina SORT_GEORGIAN_MODERN 0x1

#defina MAKELANGID(p,s) ((((WORD)(s)) << 10) | (WORD)(p))
#defina PRIMARYLANGID(lgid) ((WORD)(lgid) & 0x3ff)
#defina SUBLANGID(lgid) ((WORD)(lgid) >> 10)

#defina NLS_VALID_LOCALE_MASK 0x000fffff

#defina MAKELCID(lgid,srtid) ((DWORD)((((DWORD)((WORD)(srtid))) << 16) | ((DWORD)((WORD)(lgid)))))
#defina MAKESORTLCID(lgid,srtid,ver) ((DWORD)((MAKELCID(lgid,srtid)) | (((DWORD)((WORD)(ver))) << 20)))
#defina LANGIDFROMLCID(lcid) ((WORD)(lcid))
#defina SORTIDFROMLCID(lcid) ((WORD)((((DWORD)(lcid)) >> 16) & 0xf))
#defina SORTVERSIONFROMLCID(lcid) ((WORD)((((DWORD)(lcid)) >> 20) & 0xf))

#defina LOCALE_NAME_MAX_LENGTH 85
#defina LANG_SYSTEM_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_SYS_DEFAULT))
#defina LANG_USER_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT))

#defina LOCALE_SYSTEM_DEFAULT (MAKELCID(LANG_SYSTEM_DEFAULT,SORT_DEFAULT))
#defina LOCALE_USER_DEFAULT (MAKELCID(LANG_USER_DEFAULT,SORT_DEFAULT))

#defina LOCALE_NEUTRAL (MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),SORT_DEFAULT))

#defina LOCALE_CUSTOM_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_DEFAULT), SORT_DEFAULT))
#defina LOCALE_CUSTOM_UNSPECIFIED (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_UNSPECIFIED), SORT_DEFAULT))
#defina LOCALE_CUSTOM_UI_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_UI_CUSTOM_DEFAULT), SORT_DEFAULT))

#defina LOCALE_INVARIANT (MAKELCID(MAKELANGID(LANG_INVARIANT,SUBLANG_NEUTRAL),SORT_DEFAULT))

#defina UNREFERENCED_PARAMETER(P) (P)
#defina DBG_UNREFERENCED_PARAMETER(P) (P)
#defina DBG_UNREFERENCED_LOCAL_VARIABLE(V) (V)

#defina DEFAULT_UNREACHABLE

#se_não_definido WIN32_NO_STATUS
#defina STATUS_WAIT_0 ((DWORD)0x00000000L)
#defina STATUS_ABANDONED_WAIT_0 ((DWORD)0x00000080L)
#defina STATUS_USER_APC ((DWORD)0x000000C0L)
#defina STATUS_TIMEOUT ((DWORD)0x00000102L)
#defina STATUS_PENDING ((DWORD)0x00000103L)
#defina DBG_EXCEPTION_HANDLED ((DWORD)0x00010001L)
#defina DBG_CONTINUE ((DWORD)0x00010002L)
#defina STATUS_SEGMENT_NOTIFICATION ((DWORD)0x40000005L)
#defina DBG_TERMINATE_THREAD ((DWORD)0x40010003L)
#defina DBG_TERMINATE_PROCESS ((DWORD)0x40010004L)
#defina DBG_CONTROL_C ((DWORD)0x40010005L)
#defina DBG_CONTROL_BREAK ((DWORD)0x40010008L)
#defina DBG_COMMAND_EXCEPTION ((DWORD)0x40010009L)
#defina STATUS_GUARD_PAGE_VIOLATION ((DWORD)0x80000001L)
#defina STATUS_DATATYPE_MISALIGNMENT ((DWORD)0x80000002L)
#defina STATUS_BREAKPOINT ((DWORD)0x80000003L)
#defina STATUS_SINGLE_STEP ((DWORD)0x80000004L)
#defina DBG_EXCEPTION_NOT_HANDLED ((DWORD)0x80010001L)
#defina STATUS_ACCESS_VIOLATION ((DWORD)0xC0000005L)
#defina STATUS_IN_PAGE_ERROR ((DWORD)0xC0000006L)
#defina STATUS_INVALID_HANDLE ((DWORD)0xC0000008L)
#defina STATUS_NO_MEMORY ((DWORD)0xC0000017L)
#defina STATUS_ILLEGAL_INSTRUCTION ((DWORD)0xC000001DL)
#defina STATUS_NONCONTINUABLE_EXCEPTION ((DWORD)0xC0000025L)
#defina STATUS_INVALID_DISPOSITION ((DWORD)0xC0000026L)
#defina STATUS_ARRAY_BOUNDS_EXCEEDED ((DWORD)0xC000008CL)
#defina STATUS_FLOAT_DENORMAL_OPERAND ((DWORD)0xC000008DL)
#defina STATUS_FLOAT_DIVIDE_BY_ZERO ((DWORD)0xC000008EL)
#defina STATUS_FLOAT_INEXACT_RESULT ((DWORD)0xC000008FL)
#defina STATUS_FLOAT_INVALID_OPERATION ((DWORD)0xC0000090L)
#defina STATUS_FLOAT_OVERFLOW ((DWORD)0xC0000091L)
#defina STATUS_FLOAT_STACK_CHECK ((DWORD)0xC0000092L)
#defina STATUS_FLOAT_UNDERFLOW ((DWORD)0xC0000093L)
#defina STATUS_INTEGER_DIVIDE_BY_ZERO ((DWORD)0xC0000094L)
#defina STATUS_INTEGER_OVERFLOW ((DWORD)0xC0000095L)
#defina STATUS_PRIVILEGED_INSTRUCTION ((DWORD)0xC0000096L)
#defina STATUS_STACK_OVERFLOW ((DWORD)0xC00000FDL)
#defina STATUS_CONTROL_C_EXIT ((DWORD)0xC000013AL)
#defina STATUS_FLOAT_MULTIPLE_FAULTS ((DWORD)0xC00002B4L)
#defina STATUS_FLOAT_MULTIPLE_TRAPS ((DWORD)0xC00002B5L)
#defina STATUS_REG_NAT_CONSUMPTION ((DWORD)0xC00002C9L)
#defina STATUS_SXS_EARLY_DEACTIVATION ((DWORD)0xC015000FL)
#defina STATUS_SXS_INVALID_DEACTIVATION ((DWORD)0xC0150010L)
#fim_se

#defina MAXIMUM_WAIT_OBJECTS 64
#defina MAXIMUM_SUSPEND_COUNT MAXCHAR

  defina_tipo ULONG_PTR KSPIN_LOCK;
  defina_tipo KSPIN_LOCK *PKSPIN_LOCK;

#se_definido _AMD64_

#se definido(__x86_64) && !definido(RC_INVOKED)

#se_definido __cplusplus
  externo "C" {
#fim_se

#defina BitTest _bittest
#defina BitTestAndComplement _bittestandcomplement
#defina BitTestAndSet _bittestandset
#defina BitTestAndReset _bittestandreset
#defina InterlockedBitTestAndSet _interlockedbittestandset
#defina InterlockedBitTestAndReset _interlockedbittestandreset
#defina BitTest64 _bittest64
#defina BitTestAndComplement64 _bittestandcomplement64
#defina BitTestAndSet64 _bittestandset64
#defina BitTestAndReset64 _bittestandreset64
#defina InterlockedBitTestAndSet64 _interlockedbittestandset64
#defina InterlockedBitTestAndReset64 _interlockedbittestandreset64

    __CRT_INLINE BOOLEAN _bittest(LONG constante *Base,LONG Offset) {
      inteiro old = 0;
      __asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo *) Base))
	:"Ir" (Offset));
      retorne (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement(LONG *Base,LONG Offset) {
      inteiro old = 0;
      __asm__ __volatile__("btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo *) Base))
	:"Ir" (Offset));
      retorne (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN InterlockedBitTestAndComplement(LONG *Base,LONG Bit) {
      inteiro old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo *) Base))
	:"Ir" (Bit));
      retorne (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset(LONG *Base,LONG Offset) {
      inteiro old = 0;
      __asm__ __volatile__("btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo *) Base))
	:"Ir" (Offset));
      retorne (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset(LONG *Base,LONG Offset) {
      inteiro old = 0;
      __asm__ __volatile__("btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo *) Base))
	:"Ir" (Offset));
      retorne (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset(LONG *Base,LONG Offset) {
      inteiro old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo *) Base))
	:"Ir" (Offset));
      retorne (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset(LONG *Base,LONG Offset) {
      inteiro old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo *) Base))
	:"Ir" (Offset));
      retorne (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittest64(LONG64 constante *Base,LONG64 Offset) {
      inteiro old = 0;
      __asm__ __volatile__("btq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo longo *) Base))
	:"Ir" (Offset));
      retorne (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement64(LONG64 *Base,LONG64 Offset) {
      inteiro old = 0;
      __asm__ __volatile__("btcq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo longo *) Base))
	:"Ir" (Offset));
      retorne (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset64(LONG64 *Base,LONG64 Offset) {
      inteiro old = 0;
      __asm__ __volatile__("btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo longo *) Base))
	:"Ir" (Offset));
      retorne (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset64(LONG64 *Base,LONG64 Offset) {
      inteiro old = 0;
      __asm__ __volatile__("btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo longo *) Base))
	:"Ir" (Offset));
      retorne (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset64(LONG64 *Base,LONG64 Offset) {
      inteiro old = 0;
      __asm__ __volatile__("lock ; btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo longo *) Base))
	:"Ir" (Offset));
      retorne (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset64(LONG64 *Base,LONG64 Offset) {
      inteiro old = 0;
      __asm__ __volatile__("lock ; btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo longo *) Base))
	:"Ir" (Offset));
      retorne (BOOLEAN) (old!=0);
    }
#defina BitScanForward _BitScanForward
#defina BitScanReverse _BitScanReverse
#defina BitScanForward64 _BitScanForward64
#defina BitScanReverse64 _BitScanReverse64

    __CRT_INLINE BOOLEAN _BitScanForward(DWORD *Index,DWORD Mask) {
      __asm__ __volatile__("bsfl %1,%0" : "=r" (Mask),"=m" ((*(volátil longo *)Index)));
      retorne Mask!=0;
    }
    __CRT_INLINE BOOLEAN _BitScanReverse(DWORD *Index,DWORD Mask) {
      __asm__ __volatile__("bsrl %1,%0" : "=r" (Mask),"=m" ((*(volátil longo *)Index)));
      retorne Mask!=0;
    }
    __CRT_INLINE BOOLEAN _BitScanForward64(DWORD *Index,DWORD64 Mask) {
      __asm__ __volatile__("bsfq %1,%0" : "=r" (Mask),"=m" ((*(volátil longo longo *)Index)));
      retorne Mask!=0;
    }
    __CRT_INLINE BOOLEAN _BitScanReverse64(DWORD *Index,DWORD64 Mask) {
      __asm__ __volatile__("bsrq %1,%0" : "=r" (Mask),"=m" ((*(volátil longo longo *)Index)));
      retorne Mask!=0;
    }

#defina InterlockedIncrement16 _InterlockedIncrement16
#defina InterlockedDecrement16 _InterlockedDecrement16
#defina InterlockedCompareExchange16 _InterlockedCompareExchange16

#defina InterlockedAnd _InterlockedAnd
#defina InterlockedOr _InterlockedOr
#defina InterlockedXor _InterlockedXor
#defina InterlockedIncrement _InterlockedIncrement
#defina InterlockedIncrementAcquire InterlockedIncrement
#defina InterlockedIncrementRelease InterlockedIncrement
#defina InterlockedDecrement _InterlockedDecrement
#defina InterlockedDecrementAcquire InterlockedDecrement
#defina InterlockedDecrementRelease InterlockedDecrement
#defina InterlockedAdd _InterlockedAdd
#defina InterlockedExchange _InterlockedExchange
#defina InterlockedExchangeAdd _InterlockedExchangeAdd
#defina InterlockedCompareExchange _InterlockedCompareExchange
#defina InterlockedCompareExchangeAcquire InterlockedCompareExchange
#defina InterlockedCompareExchangeRelease InterlockedCompareExchange

#defina InterlockedAnd64 _InterlockedAnd64
#defina InterlockedAndAffinity InterlockedAnd64
#defina InterlockedOr64 _InterlockedOr64
#defina InterlockedOrAffinity InterlockedOr64
#defina InterlockedXor64 _InterlockedXor64
#defina InterlockedIncrement64 _InterlockedIncrement64
#defina InterlockedDecrement64 _InterlockedDecrement64
#defina InterlockedAdd64 _InterlockedAdd64
#defina InterlockedExchange64 _InterlockedExchange64
#defina InterlockedExchangeAcquire64 InterlockedExchange64
#defina InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#defina InterlockedCompareExchange64 _InterlockedCompareExchange64
#defina InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#defina InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

#defina InterlockedExchangePointer _InterlockedExchangePointer
#defina InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#defina InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer
#defina InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer

#defina InterlockedExchangeAddSizeT(a,b) InterlockedExchangeAdd64((LONG64 *)a,b)
#defina InterlockedIncrementSizeT(a) InterlockedIncrement64((LONG64 *)a)
#defina InterlockedDecrementSizeT(a) InterlockedDecrement64((LONG64 *)a)

    __CRT_INLINE SHORT InterlockedIncrement16(SHORT volátil *Addend) {
      sem_sinal caractere c;
      sem_sinal caractere s;
      __asm__ __volatile__(
	"lock ; addw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      retorne (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedDecrement16(SHORT volátil *Addend) {
      sem_sinal caractere c;
      sem_sinal caractere s;
      __asm__ __volatile__(
	"lock ; subw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      retorne (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedCompareExchange16(SHORT volátil *Destination,SHORT ExChange,SHORT Comperand) {
      SHORT prev;
      __asm__ __volatile__("lock ; cmpxchgw %w1,%2"
	:"=a"(prev)
	:"q"(ExChange), "m"(*Destination), "0"(Comperand)
	: "memory");
      retorne prev;
    }
    __CRT_INLINE LONG InterlockedAnd(LONG volátil *Destination,LONG Value) {
      __asm__ __volatile__("lock ; andl %0,%1"
	: :"r"(Value),"m"(*Destination)
	: "memory");
      retorne *Destination;
    }
    __CRT_INLINE LONG InterlockedOr(LONG volátil *Destination,LONG Value) {
      __asm__ __volatile__("lock ; orl %0,%1"
	: : "r"(Value),"m"(*Destination) : "memory");
      retorne *Destination;
    }
    __CRT_INLINE LONG InterlockedXor(LONG volátil *Destination,LONG Value) {
      __asm__ __volatile__("lock ; xorl %0,%1"
	: : "r"(Value),"m"(*Destination) : "memory");
      retorne *Destination;
    }
    //		$$$$
    __CRT_INLINE LONG64 InterlockedAnd64(LONG64 volátil *Destination,LONG64 Value) {
      __asm__ __volatile__("lock ; andq %0,%1"
	: : "r"(Value),"m"(*Destination) : "memory");
      retorne *Destination;
    }
    __CRT_INLINE LONG64 InterlockedOr64(LONG64 volátil *Destination,LONG64 Value) {
      __asm__ __volatile__("lock ; orq %0,%1"
	: : "r"(Value),"m"(*Destination) : "memory");
      retorne *Destination;
    }
    __CRT_INLINE LONG64 InterlockedXor64(LONG64 volátil *Destination,LONG64 Value) {
      __asm__ __volatile__("lock ; xorq %0,%1"
	: : "r"(Value),"m"(*Destination) : "memory");
      retorne *Destination;
    }
    __CRT_INLINE LONG InterlockedIncrement(LONG volátil *Addend) {
      sem_sinal caractere c;
      sem_sinal caractere s;
      __asm__ __volatile__(
	"lock ; addl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      retorne (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedDecrement(LONG volátil *Addend) {
      sem_sinal caractere c;
      sem_sinal caractere s;
      __asm__ __volatile__(
	"lock ; subl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      retorne (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedExchange(LONG volátil *Target,LONG Value) {
      __asm__ __volatile("lock ; xchgl %0,%1"
	: "=r"(Value)
	: "m"(*Target),"0"(Value)
	: "memory");
      retorne Value;
    }
    LONG InterlockedExchangeAdd(LONG volátil *Addend,LONG Value);

#se_não_definido _X86AMD64_
    __CRT_INLINE LONG InterlockedAdd(LONG volátil *Addend,LONG Value) { retorne InterlockedExchangeAdd(Addend,Value) + Value; }
#fim_se
    __CRT_INLINE LONG InterlockedCompareExchange(LONG volátil *Destination,LONG ExChange,LONG Comperand) {
      LONG prev;
      __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      retorne prev;
    }
    __CRT_INLINE LONG64 InterlockedIncrement64(LONG64 volátil *Addend) {
      sem_sinal caractere c;
      sem_sinal caractere s;
      __asm__ __volatile__(
	"lock ; addq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      retorne (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedDecrement64(LONG64 volátil *Addend) {
      sem_sinal caractere c;
      sem_sinal caractere s;
      __asm__ __volatile__(
	"lock ; subq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      retorne (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedExchange64(LONG64 volátil *Target,LONG64 Value) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(Value)
	: "m"(*Target),"0"(Value)
	: "memory");
      retorne Value;
    }
    LONG64 InterlockedExchangeAdd64(LONG64 volátil *Addend,LONG64 Value);

#se_não_definido _X86AMD64_
    __CRT_INLINE LONG64 InterlockedAdd64(LONG64 volátil *Addend,LONG64 Value) { retorne InterlockedExchangeAdd64(Addend,Value) + Value; }
#fim_se

    __CRT_INLINE LONG64 InterlockedCompareExchange64(LONG64 volátil *Destination,LONG64 ExChange,LONG64 Comperand) {
      LONG64 prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      retorne prev;
    }
    __CRT_INLINE PVOID InterlockedCompareExchangePointer(PVOID volátil *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      retorne prev;
    }
    __CRT_INLINE PVOID InterlockedExchangePointer(PVOID volátil *Target,PVOID Value) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(Value)
	: "m"(*Target),"0"(Value)
	: "memory");
      retorne Value;
    }

#defina CacheLineFlush(Address) _mm_clflush(Address)

    VOID _ReadWriteBarrier(VOID);

#defina FastFence __faststorefence
#defina LoadFence _mm_lfence
#defina MemoryFence _mm_mfence
#defina StoreFence _mm_sfence

    VOID __faststorefence(VOID);
    VOID _m_prefetchw(volátil CONST VOID *Source);

//!__TINYC__: #inclua <intrin.h>

#defina YieldProcessor _mm_pause
#defina MemoryBarrier __faststorefence
#defina PreFetchCacheLine(l,a) _mm_prefetch((CHAR CONST *) a,l)
#defina PrefetchForWrite(p) _m_prefetchw(p)
#defina ReadForWriteAccess(p) (_m_prefetchw(p),*(p))

#defina PF_TEMPORAL_LEVEL_1 _MM_HINT_T0
#defina PF_TEMPORAL_LEVEL_2 _MM_HINT_T1
#defina PF_TEMPORAL_LEVEL_3 _MM_HINT_T2
#defina PF_NON_TEMPORAL_LEVEL_ALL _MM_HINT_NTA

#defina ReadMxCsr _mm_getcsr
#defina WriteMxCsr _mm_setcsr

    VOID __int2c(VOID);

#defina DbgRaiseAssertionFailure() __int2c()
#defina GetCallersEflags() __getcallerseflags()

    sem_sinal __int32 __getcallerseflags(VOID);

#defina GetSegmentLimit __segmentlimit

    DWORD __segmentlimit(DWORD Selector);

#defina ReadTimeStampCounter() __rdtsc()

    DWORD64 __rdtsc(VOID);
    VOID __movsb(PBYTE Destination,BYTE constante *Source,SIZE_T Count);
    VOID __movsw(PWORD Destination,WORD constante *Source,SIZE_T Count);
    VOID __movsd(PDWORD Destination,DWORD constante *Source,SIZE_T Count);
    VOID __movsq(PDWORD64 Destination,DWORD64 constante *Source,SIZE_T Count);
    VOID __stosb(PBYTE Destination,BYTE Value,SIZE_T Count);
    VOID __stosw(PWORD Destination,WORD Value,SIZE_T Count);
    VOID __stosd(PDWORD Destination,DWORD Value,SIZE_T Count);
    VOID __stosq(PDWORD64 Destination,DWORD64 Value,SIZE_T Count);

#defina MultiplyHigh __mulh
#defina UnsignedMultiplyHigh __umulh

    LONGLONG MultiplyHigh(LONGLONG Multiplier,LONGLONG Multiplicand);
    ULONGLONG UnsignedMultiplyHigh(ULONGLONG Multiplier,ULONGLONG Multiplicand);

#defina ShiftLeft128 __shiftleft128
#defina ShiftRight128 __shiftright128

    DWORD64 ShiftLeft128(DWORD64 LowPart,DWORD64 HighPart,BYTE Shift);
    DWORD64 ShiftRight128(DWORD64 LowPart,DWORD64 HighPart,BYTE Shift);

#defina Multiply128 _mul128

    LONG64 Multiply128(LONG64 Multiplier,LONG64 Multiplicand,LONG64 *HighProduct);

#defina UnsignedMultiply128 _umul128

    DWORD64 UnsignedMultiply128(DWORD64 Multiplier,DWORD64 Multiplicand,DWORD64 *HighProduct);

    __CRT_INLINE LONG64 MultiplyExtract128(LONG64 Multiplier,LONG64 Multiplicand,BYTE Shift) {
      LONG64 extractedProduct;
      LONG64 highProduct;
      LONG64 lowProduct;
      lowProduct = Multiply128(Multiplier,Multiplicand,&highProduct);
      extractedProduct = (LONG64)ShiftRight128((LONG64)lowProduct,(LONG64)highProduct,Shift);
      retorne extractedProduct;
    }

    __CRT_INLINE DWORD64 UnsignedMultiplyExtract128(DWORD64 Multiplier,DWORD64 Multiplicand,BYTE Shift) {
      DWORD64 extractedProduct;
      DWORD64 highProduct;
      DWORD64 lowProduct;
      lowProduct = UnsignedMultiply128(Multiplier,Multiplicand,&highProduct);
      extractedProduct = ShiftRight128(lowProduct,highProduct,Shift);
      retorne extractedProduct;
    }

    __CRT_INLINE BYTE __readgsbyte(DWORD Offset) {
      BYTE ret;
      __asm__ volátil ("movb	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(volátil longo *) (DWORD64) Offset)));
      retorne ret;
    }
    __CRT_INLINE WORD __readgsword(DWORD Offset) {
      WORD ret;
      __asm__ volátil ("movw	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(volátil longo *) (DWORD64) Offset)));
      retorne ret;
    }
    __CRT_INLINE DWORD __readgsdword(DWORD Offset) {
      DWORD ret;
      __asm__ volátil ("movl	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(volátil longo *) (DWORD64) Offset)));
      retorne ret;
    }
    __CRT_INLINE DWORD64 __readgsqword(DWORD Offset) {
      vazio *ret;
      __asm__ volátil ("movq	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(volátil longo *) (DWORD64) Offset)));
      retorne (DWORD64) ret;
    }
    __CRT_INLINE VOID __writegsbyte(DWORD Offset,BYTE Data) {
      __asm__ volátil ("movb	%0,%%gs:%1"
	: "=r" (Data) ,"=m" ((*(volátil longo *) (DWORD64) Offset)));
    }
    __CRT_INLINE VOID __writegsword(DWORD Offset,WORD Data) {
      __asm__ volátil ("movw	%0,%%gs:%1"
	: "=r" (Data) ,"=m" ((*(volátil longo *) (DWORD64) Offset)));
    }
    __CRT_INLINE VOID __writegsdword(DWORD Offset,DWORD Data) {
      __asm__ volátil ("movl	%0,%%gs:%1"
	: "=r" (Data) ,"=m" ((*(volátil longo *) (DWORD64) Offset)));
    }
    __CRT_INLINE VOID __writegsqword(DWORD Offset,DWORD64 Data) {
      __asm__ volátil ("movq	%0,%%gs:%1"
	: "=r" (Data) ,"=m" ((*(volátil longo *) (DWORD64) Offset)));
    }

#se_definido __cplusplus
  }
#fim_se
#fim_se

#defina EXCEPTION_READ_FAULT 0
#defina EXCEPTION_WRITE_FAULT 1
#defina EXCEPTION_EXECUTE_FAULT 8

#se !definido(RC_INVOKED)

#defina CONTEXT_AMD64 0x100000

#defina CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#defina CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#defina CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#defina CONTEXT_FLOATING_POINT (CONTEXT_AMD64 | 0x8L)
#defina CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x10L)

#defina CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT)
#defina CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_POINT | CONTEXT_DEBUG_REGISTERS)

#defina CONTEXT_EXCEPTION_ACTIVE 0x8000000
#defina CONTEXT_SERVICE_ACTIVE 0x10000000
#defina CONTEXT_EXCEPTION_REQUEST 0x40000000
#defina CONTEXT_EXCEPTION_REPORTING 0x80000000
#fim_se

#defina INITIAL_MXCSR 0x1f80
#defina INITIAL_FPCSR 0x027f

  defina_tipo DECLSPEC_ALIGN(16) estrutura _M128A {
    ULONGLONG Low;
    LONGLONG High;
  } M128A,*PM128A;

  defina_tipo estrutura _XMM_SAVE_AREA32 {
    WORD ControlWord;
    WORD StatusWord;
    BYTE TagWord;
    BYTE Reserved1;
    WORD ErrorOpcode;
    DWORD ErrorOffset;
    WORD ErrorSelector;
    WORD Reserved2;
    DWORD DataOffset;
    WORD DataSelector;
    WORD Reserved3;
    DWORD MxCsr;
    DWORD MxCsr_Mask;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    BYTE Reserved4[96];
  } XMM_SAVE_AREA32,*PXMM_SAVE_AREA32;

#defina LEGACY_SAVE_AREA_LENGTH sizeof(XMM_SAVE_AREA32)

  defina_tipo DECLSPEC_ALIGN(16) estrutura _CONTEXT {
    DWORD64 P1Home;
    DWORD64 P2Home;
    DWORD64 P3Home;
    DWORD64 P4Home;
    DWORD64 P5Home;
    DWORD64 P6Home;
    DWORD ContextFlags;
    DWORD MxCsr;
    WORD SegCs;
    WORD SegDs;
    WORD SegEs;
    WORD SegFs;
    WORD SegGs;
    WORD SegSs;
    DWORD EFlags;
    DWORD64 Dr0;
    DWORD64 Dr1;
    DWORD64 Dr2;
    DWORD64 Dr3;
    DWORD64 Dr6;
    DWORD64 Dr7;
    DWORD64 Rax;
    DWORD64 Rcx;
    DWORD64 Rdx;
    DWORD64 Rbx;
    DWORD64 Rsp;
    DWORD64 Rbp;
    DWORD64 Rsi;
    DWORD64 Rdi;
    DWORD64 R8;
    DWORD64 R9;
    DWORD64 R10;
    DWORD64 R11;
    DWORD64 R12;
    DWORD64 R13;
    DWORD64 R14;
    DWORD64 R15;
    DWORD64 Rip;
    união {
      XMM_SAVE_AREA32 FltSave;
      XMM_SAVE_AREA32 FloatSave;
      estrutura {
	M128A Header[2];
	M128A Legacy[8];
	M128A Xmm0;
	M128A Xmm1;
	M128A Xmm2;
	M128A Xmm3;
	M128A Xmm4;
	M128A Xmm5;
	M128A Xmm6;
	M128A Xmm7;
	M128A Xmm8;
	M128A Xmm9;
	M128A Xmm10;
	M128A Xmm11;
	M128A Xmm12;
	M128A Xmm13;
	M128A Xmm14;
	M128A Xmm15;
      };
    };
    M128A VectorRegister[26];
    DWORD64 VectorControl;
    DWORD64 DebugControl;
    DWORD64 LastBranchToRip;
    DWORD64 LastBranchFromRip;
    DWORD64 LastExceptionToRip;
    DWORD64 LastExceptionFromRip;
  } CONTEXT,*PCONTEXT;

#defina RUNTIME_FUNCTION_INDIRECT 0x1

  defina_tipo estrutura _RUNTIME_FUNCTION {
    DWORD BeginAddress;
    DWORD EndAddress;
    DWORD UnwindData;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  defina_tipo PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  defina_tipo DWORD (*POUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK)(HANDLE Process,PVOID TableAddress,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#defina OUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"

  NTSYSAPI VOID __cdecl RtlRestoreContext (PCONTEXT ContextRecord,estrutura _EXCEPTION_RECORD *ExceptionRecord);
  NTSYSAPI BOOLEAN __cdecl RtlAddFunctionTable(PRUNTIME_FUNCTION FunctionTable,DWORD EntryCount,DWORD64 BaseAddress);
  NTSYSAPI BOOLEAN __cdecl RtlInstallFunctionTableCallback(DWORD64 TableIdentifier,DWORD64 BaseAddress,DWORD Length,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR OutOfProcessCallbackDll);
  NTSYSAPI BOOLEAN __cdecl RtlDeleteFunctionTable(PRUNTIME_FUNCTION FunctionTable);
#fim_se

#se_definido I_X86_
#se(definido(_X86_) && !definido(__x86_64)) && !definido(RC_INVOKED)
#se_definido __cplusplus
  externo "C" {
#fim_se

    __CRT_INLINE BOOLEAN InterlockedBitTestAndSet(LONG *Base,LONG Bit) {
      inteiro old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo *) Base))
	:"Ir" (Bit));
      retorne (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN InterlockedBitTestAndReset(LONG *Base,LONG Bit) {
      inteiro old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo *) Base))
	:"Ir" (Bit));
      retorne (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN InterlockedBitTestAndComplement(LONG *Base,LONG Bit) {
      inteiro old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(volátil longo *) Base))
	:"Ir" (Bit));
      retorne (BOOLEAN) (old!=0);
    }

#se_definido _PREFIX_
    BYTE __readfsbyte(DWORD Offset);
    WORD __readfsword(DWORD Offset);
    DWORD __readfsdword(DWORD Offset);
    VOID __writefsbyte(DWORD Offset,BYTE Data);
    VOID __writefsword(DWORD Offset,WORD Data);
    VOID __writefsdword(DWORD Offset,DWORD Data);
#fim_se

#se_definido __cplusplus
  }
#fim_se
#fim_se

#se(definido(_X86_) && !definido(__x86_64))
  __CRT_INLINE VOID MemoryBarrier(VOID) {
    LONG Barrier;
    __asm__ __volatile__("xchgl %eax,%0 "
      :"=r" (Barrier));
  }
#defina YieldProcessor() __asm__ __volatile__("rep nop ");

#defina PreFetchCacheLine(l,a)
#defina ReadForWriteAccess(p) (*(p))

#defina PF_TEMPORAL_LEVEL_1
#defina PF_NON_TEMPORAL_LEVEL_ALL

  __CRT_INLINE VOID DbgRaiseAssertionFailure(vazio) {
    __asm__ __volatile__("inteiro 0x2c ");
  }
  PVOID GetCurrentFiber(vazio);
  __CRT_INLINE PVOID GetCurrentFiber(vazio)
  {
    vazio *ret;
    __asm__ volátil ("movl	%%fs:0x10,%0"
	: "=r" (ret));
    retorne ret;
  }
  PVOID GetFiberData(vazio);
  __CRT_INLINE PVOID GetFiberData(vazio)
  {
    vazio *ret;
    __asm__ volátil ("movl	%%fs:0x10,%0\n"
	"movl	(%0),%0"
	: "=r" (ret));
    retorne ret;
  }
#fim_se

#defina EXCEPTION_READ_FAULT 0
#defina EXCEPTION_WRITE_FAULT 1
#defina EXCEPTION_EXECUTE_FAULT 8

#defina SIZE_OF_80387_REGISTERS 80

#se !definido(RC_INVOKED)

#defina CONTEXT_i386 0x00010000
#defina CONTEXT_i486 0x00010000

#defina CONTEXT_CONTROL (CONTEXT_i386 | 0x00000001L)
#defina CONTEXT_INTEGER (CONTEXT_i386 | 0x00000002L)
#defina CONTEXT_SEGMENTS (CONTEXT_i386 | 0x00000004L)
#defina CONTEXT_FLOATING_POINT (CONTEXT_i386 | 0x00000008L)
#defina CONTEXT_DEBUG_REGISTERS (CONTEXT_i386 | 0x00000010L)
#defina CONTEXT_EXTENDED_REGISTERS (CONTEXT_i386 | 0x00000020L)

#defina CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS)

#defina CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_POINT | CONTEXT_DEBUG_REGISTERS | CONTEXT_EXTENDED_REGISTERS)
#fim_se

#defina MAXIMUM_SUPPORTED_EXTENSION 512

    defina_tipo estrutura _FLOATING_SAVE_AREA {
      DWORD ControlWord;
      DWORD StatusWord;
      DWORD TagWord;
      DWORD ErrorOffset;
      DWORD ErrorSelector;
      DWORD DataOffset;
      DWORD DataSelector;
      BYTE RegisterArea[SIZE_OF_80387_REGISTERS];
      DWORD Cr0NpxState;
    } FLOATING_SAVE_AREA;

    defina_tipo FLOATING_SAVE_AREA *PFLOATING_SAVE_AREA;

    defina_tipo estrutura _CONTEXT {
      DWORD ContextFlags;
      DWORD Dr0;
      DWORD Dr1;
      DWORD Dr2;
      DWORD Dr3;
      DWORD Dr6;
      DWORD Dr7;
      FLOATING_SAVE_AREA FloatSave;
      DWORD SegGs;
      DWORD SegFs;
      DWORD SegEs;
      DWORD SegDs;

      DWORD Edi;
      DWORD Esi;
      DWORD Ebx;
      DWORD Edx;
      DWORD Ecx;
      DWORD Eax;
      DWORD Ebp;
      DWORD Eip;
      DWORD SegCs;
      DWORD EFlags;
      DWORD Esp;
      DWORD SegSs;
      BYTE ExtendedRegisters[MAXIMUM_SUPPORTED_EXTENSION];
    } CONTEXT;

    defina_tipo CONTEXT *PCONTEXT;
#fim_se

#se_não_definido _LDT_ENTRY_DEFINED
#defina _LDT_ENTRY_DEFINED

    defina_tipo estrutura _LDT_ENTRY {
      WORD LimitLow;
      WORD BaseLow;
      união {
	estrutura {
	  BYTE BaseMid;
	  BYTE Flags1;
	  BYTE Flags2;
	  BYTE BaseHi;
	} Bytes;
	estrutura {
	  DWORD BaseMid : 8;
	  DWORD Type : 5;
	  DWORD Dpl : 2;
	  DWORD Pres : 1;
	  DWORD LimitHi : 4;
	  DWORD Sys : 1;
	  DWORD Reserved_0 : 1;
	  DWORD Default_Big : 1;
	  DWORD Granularity : 1;
	  DWORD BaseHi : 8;
	} Bits;
      } HighWord;
    } LDT_ENTRY,*PLDT_ENTRY;
#fim_se

#se definido(__ia64__) && !definido(RC_INVOKED)

#se_definido __cplusplus
    externo "C" {
#fim_se

      BOOLEAN BitScanForward64(DWORD *Index,DWORD64 Mask);
      BOOLEAN BitScanReverse64(DWORD *Index,DWORD64 Mask);

#se_definido __cplusplus
    }
#fim_se
#fim_se

#se !definido(GENUTIL) && !definido(_GENIA64_) && definido(_IA64_)

    vazio *_cdecl _rdteb(vazio);
#se_definido __ia64__

#defina NtCurrentTeb() ((estrutura _TEB *)_rdteb())
#defina GetCurrentFiber() (((PNT_TIB)NtCurrentTeb())->FiberData)
#defina GetFiberData() (*(PVOID *)(GetCurrentFiber()))

#se_definido __cplusplus
    externo "C" {
#fim_se

      vazio __break(inteiro);
      vazio __yield(vazio);
      vazio __mf(vazio);
      vazio __lfetch(inteiro Level,VOID CONST *Address);
      vazio __lfetchfault(inteiro Level,VOID CONST *Address);
      vazio __lfetch_excl(inteiro Level,VOID CONST *Address);
      vazio __lfetchfault_excl(inteiro Level,VOID CONST *Address);

#defina MD_LFHINT_NONE 0x00
#defina MD_LFHINT_NT1 0x01
#defina MD_LFHINT_NT2 0x02
#defina MD_LFHINT_NTA 0x03

#se_definido __cplusplus
    }
#fim_se

#defina YieldProcessor __yield
#defina MemoryBarrier __mf
#defina PreFetchCacheLine __lfetch
#defina ReadForWriteAccess(p) (*(p))
#defina DbgRaiseAssertionFailure() __break(ASSERT_BREAKPOINT)

#defina PF_TEMPORAL_LEVEL_1 MD_LFHINT_NONE
#defina PF_NON_TEMPORAL_LEVEL_ALL MD_LFHINT_NTA

#defina UnsignedMultiplyHigh __UMULH

    ULONGLONG UnsignedMultiplyHigh(ULONGLONG Multiplier,ULONGLONG Multiplicand);
#senão
    estrutura _TEB *NtCurrentTeb(vazio);
#fim_se
#fim_se

#se_definido _IA64_

#defina EXCEPTION_READ_FAULT 0
#defina EXCEPTION_WRITE_FAULT 1
#defina EXCEPTION_EXECUTE_FAULT 2

#se !definido(RC_INVOKED)

#defina CONTEXT_IA64 0x00080000

#defina CONTEXT_CONTROL (CONTEXT_IA64 | 0x00000001L)
#defina CONTEXT_LOWER_FLOATING_POINT (CONTEXT_IA64 | 0x00000002L)
#defina CONTEXT_HIGHER_FLOATING_POINT (CONTEXT_IA64 | 0x00000004L)
#defina CONTEXT_INTEGER (CONTEXT_IA64 | 0x00000008L)
#defina CONTEXT_DEBUG (CONTEXT_IA64 | 0x00000010L)
#defina CONTEXT_IA32_CONTROL (CONTEXT_IA64 | 0x00000020L)

#defina CONTEXT_FLOATING_POINT (CONTEXT_LOWER_FLOATING_POINT | CONTEXT_HIGHER_FLOATING_POINT)
#defina CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#defina CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_DEBUG | CONTEXT_IA32_CONTROL)

#defina CONTEXT_EXCEPTION_ACTIVE 0x8000000
#defina CONTEXT_SERVICE_ACTIVE 0x10000000
#defina CONTEXT_EXCEPTION_REQUEST 0x40000000
#defina CONTEXT_EXCEPTION_REPORTING 0x80000000
#fim_se

    defina_tipo estrutura _CONTEXT {
      DWORD ContextFlags;
      DWORD Fill1[3];
      ULONGLONG DbI0;
      ULONGLONG DbI1;
      ULONGLONG DbI2;
      ULONGLONG DbI3;
      ULONGLONG DbI4;
      ULONGLONG DbI5;
      ULONGLONG DbI6;
      ULONGLONG DbI7;
      ULONGLONG DbD0;
      ULONGLONG DbD1;
      ULONGLONG DbD2;
      ULONGLONG DbD3;
      ULONGLONG DbD4;
      ULONGLONG DbD5;
      ULONGLONG DbD6;
      ULONGLONG DbD7;
      FLOAT128 FltS0;
      FLOAT128 FltS1;
      FLOAT128 FltS2;
      FLOAT128 FltS3;
      FLOAT128 FltT0;
      FLOAT128 FltT1;
      FLOAT128 FltT2;
      FLOAT128 FltT3;
      FLOAT128 FltT4;
      FLOAT128 FltT5;
      FLOAT128 FltT6;
      FLOAT128 FltT7;
      FLOAT128 FltT8;
      FLOAT128 FltT9;
      FLOAT128 FltS4;
      FLOAT128 FltS5;
      FLOAT128 FltS6;
      FLOAT128 FltS7;
      FLOAT128 FltS8;
      FLOAT128 FltS9;
      FLOAT128 FltS10;
      FLOAT128 FltS11;
      FLOAT128 FltS12;
      FLOAT128 FltS13;
      FLOAT128 FltS14;
      FLOAT128 FltS15;
      FLOAT128 FltS16;
      FLOAT128 FltS17;
      FLOAT128 FltS18;
      FLOAT128 FltS19;
      FLOAT128 FltF32;
      FLOAT128 FltF33;
      FLOAT128 FltF34;
      FLOAT128 FltF35;
      FLOAT128 FltF36;
      FLOAT128 FltF37;
      FLOAT128 FltF38;
      FLOAT128 FltF39;
      FLOAT128 FltF40;
      FLOAT128 FltF41;
      FLOAT128 FltF42;
      FLOAT128 FltF43;
      FLOAT128 FltF44;
      FLOAT128 FltF45;
      FLOAT128 FltF46;
      FLOAT128 FltF47;
      FLOAT128 FltF48;
      FLOAT128 FltF49;
      FLOAT128 FltF50;
      FLOAT128 FltF51;
      FLOAT128 FltF52;
      FLOAT128 FltF53;
      FLOAT128 FltF54;
      FLOAT128 FltF55;
      FLOAT128 FltF56;
      FLOAT128 FltF57;
      FLOAT128 FltF58;
      FLOAT128 FltF59;
      FLOAT128 FltF60;
      FLOAT128 FltF61;
      FLOAT128 FltF62;
      FLOAT128 FltF63;
      FLOAT128 FltF64;
      FLOAT128 FltF65;
      FLOAT128 FltF66;
      FLOAT128 FltF67;
      FLOAT128 FltF68;
      FLOAT128 FltF69;
      FLOAT128 FltF70;
      FLOAT128 FltF71;
      FLOAT128 FltF72;
      FLOAT128 FltF73;
      FLOAT128 FltF74;
      FLOAT128 FltF75;
      FLOAT128 FltF76;
      FLOAT128 FltF77;
      FLOAT128 FltF78;
      FLOAT128 FltF79;
      FLOAT128 FltF80;
      FLOAT128 FltF81;
      FLOAT128 FltF82;
      FLOAT128 FltF83;
      FLOAT128 FltF84;
      FLOAT128 FltF85;
      FLOAT128 FltF86;
      FLOAT128 FltF87;
      FLOAT128 FltF88;
      FLOAT128 FltF89;
      FLOAT128 FltF90;
      FLOAT128 FltF91;
      FLOAT128 FltF92;
      FLOAT128 FltF93;
      FLOAT128 FltF94;
      FLOAT128 FltF95;
      FLOAT128 FltF96;
      FLOAT128 FltF97;
      FLOAT128 FltF98;
      FLOAT128 FltF99;
      FLOAT128 FltF100;
      FLOAT128 FltF101;
      FLOAT128 FltF102;
      FLOAT128 FltF103;
      FLOAT128 FltF104;
      FLOAT128 FltF105;
      FLOAT128 FltF106;
      FLOAT128 FltF107;
      FLOAT128 FltF108;
      FLOAT128 FltF109;
      FLOAT128 FltF110;
      FLOAT128 FltF111;
      FLOAT128 FltF112;
      FLOAT128 FltF113;
      FLOAT128 FltF114;
      FLOAT128 FltF115;
      FLOAT128 FltF116;
      FLOAT128 FltF117;
      FLOAT128 FltF118;
      FLOAT128 FltF119;
      FLOAT128 FltF120;
      FLOAT128 FltF121;
      FLOAT128 FltF122;
      FLOAT128 FltF123;
      FLOAT128 FltF124;
      FLOAT128 FltF125;
      FLOAT128 FltF126;
      FLOAT128 FltF127;
      ULONGLONG StFPSR;
      ULONGLONG IntGp;
      ULONGLONG IntT0;
      ULONGLONG IntT1;
      ULONGLONG IntS0;
      ULONGLONG IntS1;
      ULONGLONG IntS2;
      ULONGLONG IntS3;
      ULONGLONG IntV0;
      ULONGLONG IntT2;
      ULONGLONG IntT3;
      ULONGLONG IntT4;
      ULONGLONG IntSp;
      ULONGLONG IntTeb;
      ULONGLONG IntT5;
      ULONGLONG IntT6;
      ULONGLONG IntT7;
      ULONGLONG IntT8;
      ULONGLONG IntT9;
      ULONGLONG IntT10;
      ULONGLONG IntT11;
      ULONGLONG IntT12;
      ULONGLONG IntT13;
      ULONGLONG IntT14;
      ULONGLONG IntT15;
      ULONGLONG IntT16;
      ULONGLONG IntT17;
      ULONGLONG IntT18;
      ULONGLONG IntT19;
      ULONGLONG IntT20;
      ULONGLONG IntT21;
      ULONGLONG IntT22;
      ULONGLONG IntNats;
      ULONGLONG Preds;
      ULONGLONG BrRp;
      ULONGLONG BrS0;
      ULONGLONG BrS1;
      ULONGLONG BrS2;
      ULONGLONG BrS3;
      ULONGLONG BrS4;
      ULONGLONG BrT0;
      ULONGLONG BrT1;
      ULONGLONG ApUNAT;
      ULONGLONG ApLC;
      ULONGLONG ApEC;
      ULONGLONG ApCCV;
      ULONGLONG ApDCR;
      ULONGLONG RsPFS;
      ULONGLONG RsBSP;
      ULONGLONG RsBSPSTORE;
      ULONGLONG RsRSC;
      ULONGLONG RsRNAT;
      ULONGLONG StIPSR;
      ULONGLONG StIIP;
      ULONGLONG StIFS;
      ULONGLONG StFCR;
      ULONGLONG Eflag;
      ULONGLONG SegCSD;
      ULONGLONG SegSSD;
      ULONGLONG Cflag;
      ULONGLONG StFSR;
      ULONGLONG StFIR;
      ULONGLONG StFDR;
      ULONGLONG UNUSEDPACK;
    } CONTEXT,*PCONTEXT;

    defina_tipo estrutura _PLABEL_DESCRIPTOR {
      ULONGLONG EntryPoint;
      ULONGLONG GlobalPointer;
    } PLABEL_DESCRIPTOR,*PPLABEL_DESCRIPTOR;

    defina_tipo estrutura _RUNTIME_FUNCTION {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD UnwindInfoAddress;
    } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

    defina_tipo PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
    defina_tipo DWORD (*POUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK)(HANDLE Process,PVOID TableAddress,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#defina OUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"

    BOOLEAN RtlAddFunctionTable(PRUNTIME_FUNCTION FunctionTable,DWORD EntryCount,ULONGLONG BaseAddress,ULONGLONG TargetGp);
    BOOLEAN RtlInstallFunctionTableCallback(DWORD64 TableIdentifier,DWORD64 BaseAddress,DWORD Length,DWORD64 TargetGp,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR OutOfProcessCallbackDll);
    BOOLEAN RtlDeleteFunctionTable(PRUNTIME_FUNCTION FunctionTable);
    VOID RtlRestoreContext (PCONTEXT ContextRecord,estrutura _EXCEPTION_RECORD *ExceptionRecord);
    VOID __jump_unwind(ULONGLONG TargetMsFrame,ULONGLONG TargetBsFrame,ULONGLONG TargetPc);
#fim_se

#defina EXCEPTION_NONCONTINUABLE 0x1
#defina EXCEPTION_MAXIMUM_PARAMETERS 15

    defina_tipo estrutura _EXCEPTION_RECORD {
      DWORD ExceptionCode;
      DWORD ExceptionFlags;
      estrutura _EXCEPTION_RECORD *ExceptionRecord;
      PVOID ExceptionAddress;
      DWORD NumberParameters;
      ULONG_PTR ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
    } EXCEPTION_RECORD;

    defina_tipo EXCEPTION_RECORD *PEXCEPTION_RECORD;

    defina_tipo estrutura _EXCEPTION_RECORD32 {
      DWORD ExceptionCode;
      DWORD ExceptionFlags;
      DWORD ExceptionRecord;
      DWORD ExceptionAddress;
      DWORD NumberParameters;
      DWORD ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
    } EXCEPTION_RECORD32,*PEXCEPTION_RECORD32;

    defina_tipo estrutura _EXCEPTION_RECORD64 {
      DWORD ExceptionCode;
      DWORD ExceptionFlags;
      DWORD64 ExceptionRecord;
      DWORD64 ExceptionAddress;
      DWORD NumberParameters;
      DWORD __unusedAlignment;
      DWORD64 ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
    } EXCEPTION_RECORD64,*PEXCEPTION_RECORD64;

    defina_tipo estrutura _EXCEPTION_POINTERS {
      PEXCEPTION_RECORD ExceptionRecord;
      PCONTEXT ContextRecord;
    } EXCEPTION_POINTERS,*PEXCEPTION_POINTERS;

#se_definido __x86_64

    defina_tipo EXCEPTION_DISPOSITION NTAPI EXCEPTION_ROUTINE (estrutura _EXCEPTION_RECORD *ExceptionRecord, PVOID EstablisherFrame, estrutura _CONTEXT *ContextRecord, PVOID DispatcherContext);
#se_não_definido __PEXCEPTION_ROUTINE_DEFINED
#defina __PEXCEPTION_ROUTINE_DEFINED
    defina_tipo EXCEPTION_ROUTINE *PEXCEPTION_ROUTINE;
#fim_se

    /* http://msdn.microsoft.com/en-us/library/ms680597(VS.85).aspx */

#defina UNWIND_HISTORY_TABLE_SIZE 12

  defina_tipo estrutura _UNWIND_HISTORY_TABLE_ENTRY {
    ULONG64 ImageBase;
    PRUNTIME_FUNCTION FunctionEntry;
  } UNWIND_HISTORY_TABLE_ENTRY, *PUNWIND_HISTORY_TABLE_ENTRY;

#defina UNWIND_HISTORY_TABLE_NONE    0
#defina UNWIND_HISTORY_TABLE_GLOBAL  1
#defina UNWIND_HISTORY_TABLE_LOCAL   2

  defina_tipo estrutura _UNWIND_HISTORY_TABLE {
    ULONG Count;
    UCHAR Search;
    ULONG64 LowAddress;
    ULONG64 HighAddress;
    UNWIND_HISTORY_TABLE_ENTRY Entry[UNWIND_HISTORY_TABLE_SIZE];
  } UNWIND_HISTORY_TABLE, *PUNWIND_HISTORY_TABLE;

  /* http://msdn.microsoft.com/en-us/library/b6sf5kbd(VS.80).aspx */

  estrutura _DISPATCHER_CONTEXT;
  defina_tipo estrutura _DISPATCHER_CONTEXT DISPATCHER_CONTEXT;
  defina_tipo estrutura _DISPATCHER_CONTEXT *PDISPATCHER_CONTEXT;

  estrutura _DISPATCHER_CONTEXT {
    ULONG64 ControlPc;
    ULONG64 ImageBase;
    PRUNTIME_FUNCTION FunctionEntry;
    ULONG64 EstablisherFrame;
    ULONG64 TargetIp;
    PCONTEXT ContextRecord;
    PEXCEPTION_ROUTINE LanguageHandler;
    PVOID HandlerData;
    /* http://www.nynaeve.net/?p=99 */
    PUNWIND_HISTORY_TABLE HistoryTable;
    ULONG ScopeIndex;
    ULONG Fill0;
  };

  /* http://msdn.microsoft.com/en-us/library/ms680617(VS.85).aspx */

  defina_tipo estrutura _KNONVOLATILE_CONTEXT_POINTERS
  {
    PM128A FloatingContext[16];
    PULONG64 IntegerContext[16];
  } KNONVOLATILE_CONTEXT_POINTERS, *PKNONVOLATILE_CONTEXT_POINTERS;
#fim_se /* definido(__x86_64) */

    defina_tipo PVOID PACCESS_TOKEN;
    defina_tipo PVOID PSECURITY_DESCRIPTOR;
    defina_tipo PVOID PSID;

    defina_tipo DWORD ACCESS_MASK;
    defina_tipo ACCESS_MASK *PACCESS_MASK;

#defina DELETE (0x00010000L)
#defina READ_CONTROL (0x00020000L)
#defina WRITE_DAC (0x00040000L)
#defina WRITE_OWNER (0x00080000L)
#defina SYNCHRONIZE (0x00100000L)

#defina STANDARD_RIGHTS_REQUIRED (0x000F0000L)
#defina STANDARD_RIGHTS_READ (READ_CONTROL)
#defina STANDARD_RIGHTS_WRITE (READ_CONTROL)
#defina STANDARD_RIGHTS_EXECUTE (READ_CONTROL)
#defina STANDARD_RIGHTS_ALL (0x001F0000L)

#defina SPECIFIC_RIGHTS_ALL (0x0000FFFFL)

#defina ACCESS_SYSTEM_SECURITY (0x01000000L)

#defina MAXIMUM_ALLOWED (0x02000000L)

#defina GENERIC_READ (0x80000000L)
#defina GENERIC_WRITE (0x40000000L)
#defina GENERIC_EXECUTE (0x20000000L)
#defina GENERIC_ALL (0x10000000L)

    defina_tipo estrutura _GENERIC_MAPPING {
      ACCESS_MASK GenericRead;
      ACCESS_MASK GenericWrite;
      ACCESS_MASK GenericExecute;
      ACCESS_MASK GenericAll;
    } GENERIC_MAPPING;
    defina_tipo GENERIC_MAPPING *PGENERIC_MAPPING;

#inclua <pshpack4.h>

    defina_tipo estrutura _LUID_AND_ATTRIBUTES {
      LUID Luid;
      DWORD Attributes;
    } LUID_AND_ATTRIBUTES,*PLUID_AND_ATTRIBUTES;
    defina_tipo LUID_AND_ATTRIBUTES LUID_AND_ATTRIBUTES_ARRAY[ANYSIZE_ARRAY];
    defina_tipo LUID_AND_ATTRIBUTES_ARRAY *PLUID_AND_ATTRIBUTES_ARRAY;

#inclua <poppack.h>

#se_não_definido SID_IDENTIFIER_AUTHORITY_DEFINED
#defina SID_IDENTIFIER_AUTHORITY_DEFINED
    defina_tipo estrutura _SID_IDENTIFIER_AUTHORITY {
      BYTE Value[6];
    } SID_IDENTIFIER_AUTHORITY,*PSID_IDENTIFIER_AUTHORITY;
#fim_se

#se_não_definido SID_DEFINED
#defina SID_DEFINED
    defina_tipo estrutura _SID {
      BYTE Revision;
      BYTE SubAuthorityCount;
      SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
      DWORD SubAuthority[ANYSIZE_ARRAY];
    } SID,*PISID;
#fim_se

#defina SID_REVISION (1)
#defina SID_MAX_SUB_AUTHORITIES (15)
#defina SID_RECOMMENDED_SUB_AUTHORITIES (1)

#defina SECURITY_MAX_SID_SIZE (sizeof(SID) - sizeof(DWORD) + (SID_MAX_SUB_AUTHORITIES *sizeof(DWORD)))

    defina_tipo enumeração _SID_NAME_USE {
      SidTypeUser = 1,SidTypeGroup,SidTypeDomain,SidTypeAlias,SidTypeWellKnownGroup,SidTypeDeletedAccount,SidTypeInvalid,SidTypeUnknown,SidTypeComputer
    } SID_NAME_USE,*PSID_NAME_USE;

    defina_tipo estrutura _SID_AND_ATTRIBUTES {
      PSID Sid;
      DWORD Attributes;
    } SID_AND_ATTRIBUTES,*PSID_AND_ATTRIBUTES;

    defina_tipo SID_AND_ATTRIBUTES SID_AND_ATTRIBUTES_ARRAY[ANYSIZE_ARRAY];
    defina_tipo SID_AND_ATTRIBUTES_ARRAY *PSID_AND_ATTRIBUTES_ARRAY;

#defina SECURITY_NULL_SID_AUTHORITY {0,0,0,0,0,0}
#defina SECURITY_WORLD_SID_AUTHORITY {0,0,0,0,0,1}
#defina SECURITY_LOCAL_SID_AUTHORITY {0,0,0,0,0,2}
#defina SECURITY_CREATOR_SID_AUTHORITY {0,0,0,0,0,3}
#defina SECURITY_NON_UNIQUE_AUTHORITY {0,0,0,0,0,4}
#defina SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

#defina SECURITY_NULL_RID (0x00000000L)
#defina SECURITY_WORLD_RID (0x00000000L)
#defina SECURITY_LOCAL_RID (0x00000000L)

#defina SECURITY_CREATOR_OWNER_RID (0x00000000L)
#defina SECURITY_CREATOR_GROUP_RID (0x00000001L)

#defina SECURITY_CREATOR_OWNER_SERVER_RID (0x00000002L)
#defina SECURITY_CREATOR_GROUP_SERVER_RID (0x00000003L)

#defina SECURITY_NT_AUTHORITY {0,0,0,0,0,5}

#defina SECURITY_DIALUP_RID (0x00000001L)
#defina SECURITY_NETWORK_RID (0x00000002L)
#defina SECURITY_BATCH_RID (0x00000003L)
#defina SECURITY_INTERACTIVE_RID (0x00000004L)
#defina SECURITY_LOGON_IDS_RID (0x00000005L)
#defina SECURITY_LOGON_IDS_RID_COUNT (3L)
#defina SECURITY_SERVICE_RID (0x00000006L)
#defina SECURITY_ANONYMOUS_LOGON_RID (0x00000007L)
#defina SECURITY_PROXY_RID (0x00000008L)
#defina SECURITY_ENTERPRISE_CONTROLLERS_RID (0x00000009L)
#defina SECURITY_SERVER_LOGON_RID SECURITY_ENTERPRISE_CONTROLLERS_RID
#defina SECURITY_PRINCIPAL_SELF_RID (0x0000000AL)
#defina SECURITY_AUTHENTICATED_USER_RID (0x0000000BL)
#defina SECURITY_RESTRICTED_CODE_RID (0x0000000CL)
#defina SECURITY_TERMINAL_SERVER_RID (0x0000000DL)
#defina SECURITY_REMOTE_LOGON_RID (0x0000000EL)
#defina SECURITY_THIS_ORGANIZATION_RID (0x0000000FL)
#defina SECURITY_IUSER_RID (0x00000011L)

#defina SECURITY_LOCAL_SYSTEM_RID (0x00000012L)
#defina SECURITY_LOCAL_SERVICE_RID (0x00000013L)
#defina SECURITY_NETWORK_SERVICE_RID (0x00000014L)

#defina SECURITY_NT_NON_UNIQUE (0x00000015L)
#defina SECURITY_NT_NON_UNIQUE_SUB_AUTH_COUNT (3L)

#defina SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID (0x00000016L)

#defina SECURITY_BUILTIN_DOMAIN_RID (0x00000020L)
#defina SECURITY_WRITE_RESTRICTED_CODE_RID (0x00000021L)

#defina SECURITY_PACKAGE_BASE_RID (0x00000040L)
#defina SECURITY_PACKAGE_RID_COUNT (2L)
#defina SECURITY_PACKAGE_NTLM_RID (0x0000000AL)
#defina SECURITY_PACKAGE_SCHANNEL_RID (0x0000000EL)
#defina SECURITY_PACKAGE_DIGEST_RID (0x00000015L)

#defina SECURITY_SERVICE_ID_BASE_RID (0x00000050L)
#defina SECURITY_SERVICE_ID_RID_COUNT (6L)

#defina SECURITY_RESERVED_ID_BASE_RID (0x00000051L)

#defina SECURITY_MAX_ALWAYS_FILTERED (0x000003E7L)
#defina SECURITY_MIN_NEVER_FILTERED (0x000003E8L)

#defina SECURITY_OTHER_ORGANIZATION_RID (0x000003E8L)

#defina FOREST_USER_RID_MAX (0x000001F3L)

#defina DOMAIN_USER_RID_ADMIN (0x000001F4L)
#defina DOMAIN_USER_RID_GUEST (0x000001F5L)
#defina DOMAIN_USER_RID_KRBTGT (0x000001F6L)

#defina DOMAIN_USER_RID_MAX (0x000003E7L)

#defina DOMAIN_GROUP_RID_ADMINS (0x00000200L)
#defina DOMAIN_GROUP_RID_USERS (0x00000201L)
#defina DOMAIN_GROUP_RID_GUESTS (0x00000202L)
#defina DOMAIN_GROUP_RID_COMPUTERS (0x00000203L)
#defina DOMAIN_GROUP_RID_CONTROLLERS (0x00000204L)
#defina DOMAIN_GROUP_RID_CERT_ADMINS (0x00000205L)
#defina DOMAIN_GROUP_RID_SCHEMA_ADMINS (0x00000206L)
#defina DOMAIN_GROUP_RID_ENTERPRISE_ADMINS (0x00000207L)
#defina DOMAIN_GROUP_RID_POLICY_ADMINS (0x00000208L)
#defina DOMAIN_GROUP_RID_READONLY_CONTROLLERS (0x00000209L)

#defina DOMAIN_ALIAS_RID_ADMINS (0x00000220L)
#defina DOMAIN_ALIAS_RID_USERS (0x00000221L)
#defina DOMAIN_ALIAS_RID_GUESTS (0x00000222L)
#defina DOMAIN_ALIAS_RID_POWER_USERS (0x00000223L)

#defina DOMAIN_ALIAS_RID_ACCOUNT_OPS (0x00000224L)
#defina DOMAIN_ALIAS_RID_SYSTEM_OPS (0x00000225L)
#defina DOMAIN_ALIAS_RID_PRINT_OPS (0x00000226L)
#defina DOMAIN_ALIAS_RID_BACKUP_OPS (0x00000227L)

#defina DOMAIN_ALIAS_RID_REPLICATOR (0x00000228L)
#defina DOMAIN_ALIAS_RID_RAS_SERVERS (0x00000229L)
#defina DOMAIN_ALIAS_RID_PREW2KCOMPACCESS (0x0000022AL)
#defina DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS (0x0000022BL)
#defina DOMAIN_ALIAS_RID_NETWORK_CONFIGURATION_OPS (0x0000022CL)
#defina DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS (0x0000022DL)

#defina DOMAIN_ALIAS_RID_MONITORING_USERS (0x0000022EL)
#defina DOMAIN_ALIAS_RID_LOGGING_USERS (0x0000022FL)
#defina DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS (0x00000230L)
#defina DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS (0x00000231L)
#defina DOMAIN_ALIAS_RID_DCOM_USERS (0x00000232L)

#defina DOMAIN_ALIAS_RID_IUSERS (0x00000238L)
#defina DOMAIN_ALIAS_RID_CRYPTO_OPERATORS (0x00000239L)
#defina DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_GROUP (0x0000023BL)
#defina DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_GROUP (0x0000023CL)
#defina DOMAIN_ALIAS_RID_EVENT_LOG_READERS_GROUP (0x0000023DL)

#defina SECURITY_MANDATORY_LABEL_AUTHORITY {0,0,0,0,0,16}
#defina SECURITY_MANDATORY_UNTRUSTED_RID (0x00000000L)
#defina SECURITY_MANDATORY_LOW_RID (0x00001000L)
#defina SECURITY_MANDATORY_MEDIUM_RID (0x00002000L)
#defina SECURITY_MANDATORY_HIGH_RID (0x00003000L)
#defina SECURITY_MANDATORY_SYSTEM_RID (0x00004000L)
#defina SECURITY_MANDATORY_PROTECTED_PROCESS_RID (0x00005000L)

#defina SECURITY_MANDATORY_MAXIMUM_USER_RID SECURITY_MANDATORY_SYSTEM_RID

#defina MANDATORY_LEVEL_TO_MANDATORY_RID(IL) (IL * 0x1000)

    defina_tipo enumeração {
      WinNullSid = 0,WinWorldSid = 1,WinLocalSid = 2,WinCreatorOwnerSid = 3,WinCreatorGroupSid = 4,WinCreatorOwnerServerSid = 5,WinCreatorGroupServerSid = 6,WinNtAuthoritySid = 7,WinDialupSid = 8,WinNetworkSid = 9,WinBatchSid = 10,WinInteractiveSid = 11,WinServiceSid = 12,WinAnonymousSid = 13,WinProxySid = 14,WinEnterpriseControllersSid = 15,WinSelfSid = 16,WinAuthenticatedUserSid = 17,WinRestrictedCodeSid = 18,WinTerminalServerSid = 19,WinRemoteLogonIdSid = 20,WinLogonIdsSid = 21,WinLocalSystemSid = 22,WinLocalServiceSid = 23,WinNetworkServiceSid = 24,WinBuiltinDomainSid = 25,WinBuiltinAdministratorsSid = 26,WinBuiltinUsersSid = 27,WinBuiltinGuestsSid = 28,WinBuiltinPowerUsersSid = 29,WinBuiltinAccountOperatorsSid = 30,WinBuiltinSystemOperatorsSid = 31,WinBuiltinPrintOperatorsSid = 32,WinBuiltinBackupOperatorsSid = 33,WinBuiltinReplicatorSid = 34,WinBuiltinPreWindows2000CompatibleAccessSid = 35,WinBuiltinRemoteDesktopUsersSid = 36,WinBuiltinNetworkConfigurationOperatorsSid = 37,WinAccountAdministratorSid = 38,WinAccountGuestSid = 39,WinAccountKrbtgtSid = 40,WinAccountDomainAdminsSid = 41,WinAccountDomainUsersSid = 42,WinAccountDomainGuestsSid = 43,WinAccountComputersSid = 44,WinAccountControllersSid = 45,WinAccountCertAdminsSid = 46,WinAccountSchemaAdminsSid = 47,WinAccountEnterpriseAdminsSid = 48,WinAccountPolicyAdminsSid = 49,WinAccountRasAndIasServersSid = 50,WinNTLMAuthenticationSid = 51,WinDigestAuthenticationSid = 52,WinSChannelAuthenticationSid = 53,WinThisOrganizationSid = 54,WinOtherOrganizationSid = 55,WinBuiltinIncomingForestTrustBuildersSid = 56,WinBuiltinPerfMonitoringUsersSid = 57,WinBuiltinPerfLoggingUsersSid = 58,WinBuiltinAuthorizationAccessSid = 59,WinBuiltinTerminalServerLicenseServersSid = 60,WinBuiltinDCOMUsersSid = 61
    } WELL_KNOWN_SID_TYPE;

#defina SYSTEM_LUID { 0x3E7,0x0 }
#defina ANONYMOUS_LOGON_LUID { 0x3e6,0x0 }
#defina LOCALSERVICE_LUID { 0x3e5,0x0 }
#defina NETWORKSERVICE_LUID { 0x3e4,0x0 }
#defina IUSER_LUID { 0x3e3, 0x0 }

#defina SE_GROUP_MANDATORY (0x00000001L)
#defina SE_GROUP_ENABLED_BY_DEFAULT (0x00000002L)
#defina SE_GROUP_ENABLED (0x00000004L)
#defina SE_GROUP_OWNER (0x00000008L)
#defina SE_GROUP_USE_FOR_DENY_ONLY (0x00000010L)
#defina SE_GROUP_INTEGRITY (0x00000020L)
#defina SE_GROUP_INTEGRITY_ENABLED (0x00000040L)
#defina SE_GROUP_LOGON_ID (0xC0000000L)
#defina SE_GROUP_RESOURCE (0x20000000L)

#defina ACL_REVISION (2)
#defina ACL_REVISION_DS (4)

#defina ACL_REVISION1 (1)
#defina MIN_ACL_REVISION ACL_REVISION2
#defina ACL_REVISION2 (2)
#defina ACL_REVISION3 (3)
#defina ACL_REVISION4 (4)
#defina MAX_ACL_REVISION ACL_REVISION4

    defina_tipo estrutura _ACL {
      BYTE AclRevision;
      BYTE Sbz1;
      WORD AclSize;
      WORD AceCount;
      WORD Sbz2;
    } ACL;
    defina_tipo ACL *PACL;

    defina_tipo estrutura _ACE_HEADER {
      BYTE AceType;
      BYTE AceFlags;
      WORD AceSize;
    } ACE_HEADER;
    defina_tipo ACE_HEADER *PACE_HEADER;

#defina ACCESS_MIN_MS_ACE_TYPE (0x0)
#defina ACCESS_ALLOWED_ACE_TYPE (0x0)
#defina ACCESS_DENIED_ACE_TYPE (0x1)
#defina SYSTEM_AUDIT_ACE_TYPE (0x2)
#defina SYSTEM_ALARM_ACE_TYPE (0x3)
#defina ACCESS_MAX_MS_V2_ACE_TYPE (0x3)

#defina ACCESS_ALLOWED_COMPOUND_ACE_TYPE (0x4)
#defina ACCESS_MAX_MS_V3_ACE_TYPE (0x4)

#defina ACCESS_MIN_MS_OBJECT_ACE_TYPE (0x5)
#defina ACCESS_ALLOWED_OBJECT_ACE_TYPE (0x5)
#defina ACCESS_DENIED_OBJECT_ACE_TYPE (0x6)
#defina SYSTEM_AUDIT_OBJECT_ACE_TYPE (0x7)
#defina SYSTEM_ALARM_OBJECT_ACE_TYPE (0x8)
#defina ACCESS_MAX_MS_OBJECT_ACE_TYPE (0x8)

#defina ACCESS_MAX_MS_V4_ACE_TYPE (0x8)
#defina ACCESS_MAX_MS_ACE_TYPE (0x8)

#defina ACCESS_ALLOWED_CALLBACK_ACE_TYPE (0x9)
#defina ACCESS_DENIED_CALLBACK_ACE_TYPE (0xA)
#defina ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE (0xB)
#defina ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE (0xC)
#defina SYSTEM_AUDIT_CALLBACK_ACE_TYPE (0xD)
#defina SYSTEM_ALARM_CALLBACK_ACE_TYPE (0xE)
#defina SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE (0xF)
#defina SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE (0x10)

#defina SYSTEM_MANDATORY_LABEL_ACE_TYPE (0x11)
#defina ACCESS_MAX_MS_V5_ACE_TYPE (0x11)

#defina OBJECT_INHERIT_ACE (0x1)
#defina CONTAINER_INHERIT_ACE (0x2)
#defina NO_PROPAGATE_INHERIT_ACE (0x4)
#defina INHERIT_ONLY_ACE (0x8)
#defina INHERITED_ACE (0x10)
#defina VALID_INHERIT_FLAGS (0x1F)

#defina SUCCESSFUL_ACCESS_ACE_FLAG (0x40)
#defina FAILED_ACCESS_ACE_FLAG (0x80)

    defina_tipo estrutura _ACCESS_ALLOWED_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;
    } ACCESS_ALLOWED_ACE;

    defina_tipo ACCESS_ALLOWED_ACE *PACCESS_ALLOWED_ACE;

    defina_tipo estrutura _ACCESS_DENIED_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;
    } ACCESS_DENIED_ACE;
    defina_tipo ACCESS_DENIED_ACE *PACCESS_DENIED_ACE;

    defina_tipo estrutura _SYSTEM_AUDIT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;
    } SYSTEM_AUDIT_ACE;
    defina_tipo SYSTEM_AUDIT_ACE *PSYSTEM_AUDIT_ACE;

    defina_tipo estrutura _SYSTEM_ALARM_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;
    } SYSTEM_ALARM_ACE;
    defina_tipo SYSTEM_ALARM_ACE *PSYSTEM_ALARM_ACE;

    defina_tipo estrutura _ACCESS_ALLOWED_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;
    } ACCESS_ALLOWED_OBJECT_ACE,*PACCESS_ALLOWED_OBJECT_ACE;

    defina_tipo estrutura _ACCESS_DENIED_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;
    } ACCESS_DENIED_OBJECT_ACE,*PACCESS_DENIED_OBJECT_ACE;

    defina_tipo estrutura _SYSTEM_AUDIT_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;
    } SYSTEM_AUDIT_OBJECT_ACE,*PSYSTEM_AUDIT_OBJECT_ACE;

    defina_tipo estrutura _SYSTEM_ALARM_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;
    } SYSTEM_ALARM_OBJECT_ACE,*PSYSTEM_ALARM_OBJECT_ACE;

    defina_tipo estrutura _ACCESS_ALLOWED_CALLBACK_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;

    } ACCESS_ALLOWED_CALLBACK_ACE,*PACCESS_ALLOWED_CALLBACK_ACE;

    defina_tipo estrutura _ACCESS_DENIED_CALLBACK_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;

    } ACCESS_DENIED_CALLBACK_ACE,*PACCESS_DENIED_CALLBACK_ACE;

    defina_tipo estrutura _SYSTEM_AUDIT_CALLBACK_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;

    } SYSTEM_AUDIT_CALLBACK_ACE,*PSYSTEM_AUDIT_CALLBACK_ACE;

    defina_tipo estrutura _SYSTEM_ALARM_CALLBACK_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;

    } SYSTEM_ALARM_CALLBACK_ACE,*PSYSTEM_ALARM_CALLBACK_ACE;

    defina_tipo estrutura _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;

    } ACCESS_ALLOWED_CALLBACK_OBJECT_ACE,*PACCESS_ALLOWED_CALLBACK_OBJECT_ACE;

    defina_tipo estrutura _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;

    } ACCESS_DENIED_CALLBACK_OBJECT_ACE,*PACCESS_DENIED_CALLBACK_OBJECT_ACE;

    defina_tipo estrutura _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;

    } SYSTEM_AUDIT_CALLBACK_OBJECT_ACE,*PSYSTEM_AUDIT_CALLBACK_OBJECT_ACE;

    defina_tipo estrutura _SYSTEM_ALARM_CALLBACK_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;

    } SYSTEM_ALARM_CALLBACK_OBJECT_ACE,*PSYSTEM_ALARM_CALLBACK_OBJECT_ACE;

#defina ACE_OBJECT_TYPE_PRESENT 0x1
#defina ACE_INHERITED_OBJECT_TYPE_PRESENT 0x2

    defina_tipo enumeração _ACL_INFORMATION_CLASS {
      AclRevisionInformation = 1,AclSizeInformation
    } ACL_INFORMATION_CLASS;

    defina_tipo estrutura _ACL_REVISION_INFORMATION {
      DWORD AclRevision;
    } ACL_REVISION_INFORMATION;
    defina_tipo ACL_REVISION_INFORMATION *PACL_REVISION_INFORMATION;

    defina_tipo estrutura _ACL_SIZE_INFORMATION {
      DWORD AceCount;
      DWORD AclBytesInUse;
      DWORD AclBytesFree;
    } ACL_SIZE_INFORMATION;
    defina_tipo ACL_SIZE_INFORMATION *PACL_SIZE_INFORMATION;

#defina SECURITY_DESCRIPTOR_REVISION (1)
#defina SECURITY_DESCRIPTOR_REVISION1 (1)

#defina SECURITY_DESCRIPTOR_MIN_LENGTH (sizeof(SECURITY_DESCRIPTOR))

    defina_tipo WORD SECURITY_DESCRIPTOR_CONTROL,*PSECURITY_DESCRIPTOR_CONTROL;

#defina SE_OWNER_DEFAULTED (0x0001)
#defina SE_GROUP_DEFAULTED (0x0002)
#defina SE_DACL_PRESENT (0x0004)
#defina SE_DACL_DEFAULTED (0x0008)
#defina SE_SACL_PRESENT (0x0010)
#defina SE_SACL_DEFAULTED (0x0020)
#defina SE_DACL_AUTO_INHERIT_REQ (0x0100)
#defina SE_SACL_AUTO_INHERIT_REQ (0x0200)
#defina SE_DACL_AUTO_INHERITED (0x0400)
#defina SE_SACL_AUTO_INHERITED (0x0800)
#defina SE_DACL_PROTECTED (0x1000)
#defina SE_SACL_PROTECTED (0x2000)
#defina SE_RM_CONTROL_VALID (0x4000)
#defina SE_SELF_RELATIVE (0x8000)

    defina_tipo estrutura _SECURITY_DESCRIPTOR_RELATIVE {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      DWORD Owner;
      DWORD Group;
      DWORD Sacl;
      DWORD Dacl;
    } SECURITY_DESCRIPTOR_RELATIVE,*PISECURITY_DESCRIPTOR_RELATIVE;

    defina_tipo estrutura _SECURITY_DESCRIPTOR {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      PSID Owner;
      PSID Group;
      PACL Sacl;
      PACL Dacl;

    } SECURITY_DESCRIPTOR,*PISECURITY_DESCRIPTOR;

    defina_tipo estrutura _OBJECT_TYPE_LIST {
      WORD Level;
      WORD Sbz;
      GUID *ObjectType;
    } OBJECT_TYPE_LIST,*POBJECT_TYPE_LIST;

#defina ACCESS_OBJECT_GUID 0
#defina ACCESS_PROPERTY_SET_GUID 1
#defina ACCESS_PROPERTY_GUID 2

#defina ACCESS_MAX_LEVEL 4

    defina_tipo enumeração _AUDIT_EVENT_TYPE {
      AuditEventObjectAccess,AuditEventDirectoryServiceAccess
    } AUDIT_EVENT_TYPE,*PAUDIT_EVENT_TYPE;

#defina AUDIT_ALLOW_NO_PRIVILEGE 0x1

#defina ACCESS_DS_SOURCE_A "DS"
#defina ACCESS_DS_SOURCE_W L"DS"
#defina ACCESS_DS_OBJECT_TYPE_NAME_A "Directory Service Object"
#defina ACCESS_DS_OBJECT_TYPE_NAME_W L"Directory Service Object"

#defina SE_PRIVILEGE_ENABLED_BY_DEFAULT (0x00000001L)
#defina SE_PRIVILEGE_ENABLED (0x00000002L)
#defina SE_PRIVILEGE_REMOVED (0X00000004L)
#defina SE_PRIVILEGE_USED_FOR_ACCESS (0x80000000L)

#defina PRIVILEGE_SET_ALL_NECESSARY (1)

    defina_tipo estrutura _PRIVILEGE_SET {
      DWORD PrivilegeCount;
      DWORD Control;
      LUID_AND_ATTRIBUTES Privilege[ANYSIZE_ARRAY];
    } PRIVILEGE_SET,*PPRIVILEGE_SET;

#defina SE_CREATE_TOKEN_NAME TEXT("SeCreateTokenPrivilege")
#defina SE_ASSIGNPRIMARYTOKEN_NAME TEXT("SeAssignPrimaryTokenPrivilege")
#defina SE_LOCK_MEMORY_NAME TEXT("SeLockMemoryPrivilege")
#defina SE_INCREASE_QUOTA_NAME TEXT("SeIncreaseQuotaPrivilege")
#defina SE_UNSOLICITED_INPUT_NAME TEXT("SeUnsolicitedInputPrivilege")
#defina SE_MACHINE_ACCOUNT_NAME TEXT("SeMachineAccountPrivilege")
#defina SE_TCB_NAME TEXT("SeTcbPrivilege")
#defina SE_SECURITY_NAME TEXT("SeSecurityPrivilege")
#defina SE_TAKE_OWNERSHIP_NAME TEXT("SeTakeOwnershipPrivilege")
#defina SE_LOAD_DRIVER_NAME TEXT("SeLoadDriverPrivilege")
#defina SE_SYSTEM_PROFILE_NAME TEXT("SeSystemProfilePrivilege")
#defina SE_SYSTEMTIME_NAME TEXT("SeSystemtimePrivilege")
#defina SE_PROF_SINGLE_PROCESS_NAME TEXT("SeProfileSingleProcessPrivilege")
#defina SE_INC_BASE_PRIORITY_NAME TEXT("SeIncreaseBasePriorityPrivilege")
#defina SE_CREATE_PAGEFILE_NAME TEXT("SeCreatePagefilePrivilege")
#defina SE_CREATE_PERMANENT_NAME TEXT("SeCreatePermanentPrivilege")
#defina SE_BACKUP_NAME TEXT("SeBackupPrivilege")
#defina SE_RESTORE_NAME TEXT("SeRestorePrivilege")
#defina SE_SHUTDOWN_NAME TEXT("SeShutdownPrivilege")
#defina SE_DEBUG_NAME TEXT("SeDebugPrivilege")
#defina SE_AUDIT_NAME TEXT("SeAuditPrivilege")
#defina SE_SYSTEM_ENVIRONMENT_NAME TEXT("SeSystemEnvironmentPrivilege")
#defina SE_CHANGE_NOTIFY_NAME TEXT("SeChangeNotifyPrivilege")
#defina SE_REMOTE_SHUTDOWN_NAME TEXT("SeRemoteShutdownPrivilege")
#defina SE_UNDOCK_NAME TEXT("SeUndockPrivilege")
#defina SE_SYNC_AGENT_NAME TEXT("SeSyncAgentPrivilege")
#defina SE_ENABLE_DELEGATION_NAME TEXT("SeEnableDelegationPrivilege")
#defina SE_MANAGE_VOLUME_NAME TEXT("SeManageVolumePrivilege")
#defina SE_IMPERSONATE_NAME TEXT("SeImpersonatePrivilege")
#defina SE_CREATE_GLOBAL_NAME TEXT("SeCreateGlobalPrivilege")

    defina_tipo enumeração _SECURITY_IMPERSONATION_LEVEL {
      SecurityAnonymous,SecurityIdentification,SecurityImpersonation,SecurityDelegation
    } SECURITY_IMPERSONATION_LEVEL,*PSECURITY_IMPERSONATION_LEVEL;

#defina SECURITY_MAX_IMPERSONATION_LEVEL SecurityDelegation
#defina SECURITY_MIN_IMPERSONATION_LEVEL SecurityAnonymous
#defina DEFAULT_IMPERSONATION_LEVEL SecurityImpersonation
#defina VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))

#defina TOKEN_ASSIGN_PRIMARY (0x0001)
#defina TOKEN_DUPLICATE (0x0002)
#defina TOKEN_IMPERSONATE (0x0004)
#defina TOKEN_QUERY (0x0008)
#defina TOKEN_QUERY_SOURCE (0x0010)
#defina TOKEN_ADJUST_PRIVILEGES (0x0020)
#defina TOKEN_ADJUST_GROUPS (0x0040)
#defina TOKEN_ADJUST_DEFAULT (0x0080)
#defina TOKEN_ADJUST_SESSIONID (0x0100)

#defina TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED | TOKEN_ASSIGN_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_SOURCE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)
#defina TOKEN_ALL_ACCESS (TOKEN_ALL_ACCESS_P | TOKEN_ADJUST_SESSIONID)
#defina TOKEN_READ (STANDARD_RIGHTS_READ | TOKEN_QUERY)

#defina TOKEN_WRITE (STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)

#defina TOKEN_EXECUTE (STANDARD_RIGHTS_EXECUTE)

    defina_tipo enumeração _TOKEN_TYPE {
      TokenPrimary = 1,TokenImpersonation
    } TOKEN_TYPE;
    defina_tipo TOKEN_TYPE *PTOKEN_TYPE;

    defina_tipo enumeração _TOKEN_INFORMATION_CLASS {
      TokenUser = 1,TokenGroups,TokenPrivileges,TokenOwner,TokenPrimaryGroup,TokenDefaultDacl,TokenSource,TokenType,TokenImpersonationLevel,
      TokenStatistics,TokenRestrictedSids,TokenSessionId,TokenGroupsAndPrivileges,TokenSessionReference,TokenSandBoxInert,TokenAuditPolicy,
      TokenOrigin,MaxTokenInfoClass
    } TOKEN_INFORMATION_CLASS,*PTOKEN_INFORMATION_CLASS;

    defina_tipo estrutura _TOKEN_USER {
      SID_AND_ATTRIBUTES User;
    } TOKEN_USER,*PTOKEN_USER;

    defina_tipo estrutura _TOKEN_GROUPS {
      DWORD GroupCount;
      SID_AND_ATTRIBUTES Groups[ANYSIZE_ARRAY];
    } TOKEN_GROUPS,*PTOKEN_GROUPS;

    defina_tipo estrutura _TOKEN_PRIVILEGES {
      DWORD PrivilegeCount;
      LUID_AND_ATTRIBUTES Privileges[ANYSIZE_ARRAY];
    } TOKEN_PRIVILEGES,*PTOKEN_PRIVILEGES;

    defina_tipo estrutura _TOKEN_OWNER {
      PSID Owner;
    } TOKEN_OWNER,*PTOKEN_OWNER;

    defina_tipo estrutura _TOKEN_PRIMARY_GROUP {
      PSID PrimaryGroup;
    } TOKEN_PRIMARY_GROUP,*PTOKEN_PRIMARY_GROUP;

    defina_tipo estrutura _TOKEN_DEFAULT_DACL {
      PACL DefaultDacl;
    } TOKEN_DEFAULT_DACL,*PTOKEN_DEFAULT_DACL;

    defina_tipo estrutura _TOKEN_GROUPS_AND_PRIVILEGES {
      DWORD SidCount;
      DWORD SidLength;
      PSID_AND_ATTRIBUTES Sids;
      DWORD RestrictedSidCount;
      DWORD RestrictedSidLength;
      PSID_AND_ATTRIBUTES RestrictedSids;
      DWORD PrivilegeCount;
      DWORD PrivilegeLength;
      PLUID_AND_ATTRIBUTES Privileges;
      LUID AuthenticationId;
    } TOKEN_GROUPS_AND_PRIVILEGES,*PTOKEN_GROUPS_AND_PRIVILEGES;

#defina TOKEN_AUDIT_SUCCESS_INCLUDE 0x1
#defina TOKEN_AUDIT_SUCCESS_EXCLUDE 0x2
#defina TOKEN_AUDIT_FAILURE_INCLUDE 0x4
#defina TOKEN_AUDIT_FAILURE_EXCLUDE 0x8

#defina VALID_AUDIT_POLICY_BITS (TOKEN_AUDIT_SUCCESS_INCLUDE | TOKEN_AUDIT_SUCCESS_EXCLUDE | TOKEN_AUDIT_FAILURE_INCLUDE | TOKEN_AUDIT_FAILURE_EXCLUDE)
#defina VALID_TOKEN_AUDIT_POLICY_ELEMENT(P) ((((P).PolicyMask & ~VALID_AUDIT_POLICY_BITS)==0) && ((P).Category <= AuditEventMaxType))

    defina_tipo estrutura _TOKEN_AUDIT_POLICY_ELEMENT {
      DWORD Category;
      DWORD PolicyMask;
    } TOKEN_AUDIT_POLICY_ELEMENT,*PTOKEN_AUDIT_POLICY_ELEMENT;

    defina_tipo estrutura _TOKEN_AUDIT_POLICY {
      DWORD PolicyCount;
      TOKEN_AUDIT_POLICY_ELEMENT Policy[ANYSIZE_ARRAY];
    } TOKEN_AUDIT_POLICY,*PTOKEN_AUDIT_POLICY;

#defina PER_USER_AUDITING_POLICY_SIZE(p) (sizeof(TOKEN_AUDIT_POLICY) + (((p)->PolicyCount > ANYSIZE_ARRAY) ? (sizeof(TOKEN_AUDIT_POLICY_ELEMENT) *((p)->PolicyCount - ANYSIZE_ARRAY)) : 0))
#defina PER_USER_AUDITING_POLICY_SIZE_BY_COUNT(C) (sizeof(TOKEN_AUDIT_POLICY) + (((C) > ANYSIZE_ARRAY) ? (sizeof(TOKEN_AUDIT_POLICY_ELEMENT) *((C) - ANYSIZE_ARRAY)) : 0))

#defina TOKEN_SOURCE_LENGTH 8

    defina_tipo estrutura _TOKEN_SOURCE {
      CHAR SourceName[TOKEN_SOURCE_LENGTH];
      LUID SourceIdentifier;
    } TOKEN_SOURCE,*PTOKEN_SOURCE;

    defina_tipo estrutura _TOKEN_STATISTICS {
      LUID TokenId;
      LUID AuthenticationId;
      LARGE_INTEGER ExpirationTime;
      TOKEN_TYPE TokenType;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      DWORD DynamicCharged;
      DWORD DynamicAvailable;
      DWORD GroupCount;
      DWORD PrivilegeCount;
      LUID ModifiedId;
    } TOKEN_STATISTICS,*PTOKEN_STATISTICS;

    defina_tipo estrutura _TOKEN_CONTROL {
      LUID TokenId;
      LUID AuthenticationId;
      LUID ModifiedId;
      TOKEN_SOURCE TokenSource;
    } TOKEN_CONTROL,*PTOKEN_CONTROL;

    defina_tipo estrutura _TOKEN_ORIGIN {
      LUID OriginatingLogonSession;
    } TOKEN_ORIGIN,*PTOKEN_ORIGIN;

#defina SECURITY_DYNAMIC_TRACKING (TRUE)
#defina SECURITY_STATIC_TRACKING (FALSE)

    defina_tipo BOOLEAN SECURITY_CONTEXT_TRACKING_MODE,*PSECURITY_CONTEXT_TRACKING_MODE;

    defina_tipo estrutura _SECURITY_QUALITY_OF_SERVICE {
      DWORD Length;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      SECURITY_CONTEXT_TRACKING_MODE ContextTrackingMode;
      BOOLEAN EffectiveOnly;
    } SECURITY_QUALITY_OF_SERVICE,*PSECURITY_QUALITY_OF_SERVICE;

    defina_tipo estrutura _SE_IMPERSONATION_STATE {
      PACCESS_TOKEN Token;
      BOOLEAN CopyOnOpen;
      BOOLEAN EffectiveOnly;
      SECURITY_IMPERSONATION_LEVEL Level;
    } SE_IMPERSONATION_STATE,*PSE_IMPERSONATION_STATE;

#defina DISABLE_MAX_PRIVILEGE 0x1
#defina SANDBOX_INERT 0x2

    defina_tipo DWORD SECURITY_INFORMATION,*PSECURITY_INFORMATION;

#defina OWNER_SECURITY_INFORMATION (0x00000001L)
#defina GROUP_SECURITY_INFORMATION (0x00000002L)
#defina DACL_SECURITY_INFORMATION (0x00000004L)
#defina SACL_SECURITY_INFORMATION (0x00000008L)

#defina PROTECTED_DACL_SECURITY_INFORMATION (0x80000000L)
#defina PROTECTED_SACL_SECURITY_INFORMATION (0x40000000L)
#defina UNPROTECTED_DACL_SECURITY_INFORMATION (0x20000000L)
#defina UNPROTECTED_SACL_SECURITY_INFORMATION (0x10000000L)

#defina PROCESS_TERMINATE (0x0001)
#defina PROCESS_CREATE_THREAD (0x0002)
#defina PROCESS_SET_SESSIONID (0x0004)
#defina PROCESS_VM_OPERATION (0x0008)
#defina PROCESS_VM_READ (0x0010)
#defina PROCESS_VM_WRITE (0x0020)
#defina PROCESS_DUP_HANDLE (0x0040)
#defina PROCESS_CREATE_PROCESS (0x0080)
#defina PROCESS_SET_QUOTA (0x0100)
#defina PROCESS_SET_INFORMATION (0x0200)
#defina PROCESS_QUERY_INFORMATION (0x0400)
#defina PROCESS_SUSPEND_RESUME (0x0800)
#defina PROCESS_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFF)

#se_definido _WIN64
#defina MAXIMUM_PROCESSORS 64
#senão
#defina MAXIMUM_PROCESSORS 32
#fim_se

#defina THREAD_TERMINATE (0x0001)
#defina THREAD_SUSPEND_RESUME (0x0002)
#defina THREAD_GET_CONTEXT (0x0008)
#defina THREAD_SET_CONTEXT (0x0010)
#defina THREAD_SET_INFORMATION (0x0020)
#defina THREAD_QUERY_INFORMATION (0x0040)
#defina THREAD_SET_THREAD_TOKEN (0x0080)
#defina THREAD_IMPERSONATE (0x0100)
#defina THREAD_DIRECT_IMPERSONATION (0x0200)

#defina THREAD_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x3FF)

#defina JOB_OBJECT_ASSIGN_PROCESS (0x0001)
#defina JOB_OBJECT_SET_ATTRIBUTES (0x0002)
#defina JOB_OBJECT_QUERY (0x0004)
#defina JOB_OBJECT_TERMINATE (0x0008)
#defina JOB_OBJECT_SET_SECURITY_ATTRIBUTES (0x0010)
#defina JOB_OBJECT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1F)

    defina_tipo estrutura _JOB_SET_ARRAY {
      HANDLE JobHandle;
      DWORD MemberLevel;
      DWORD Flags;
    } JOB_SET_ARRAY,*PJOB_SET_ARRAY;

#defina FLS_MAXIMUM_AVAILABLE 128
#defina TLS_MINIMUM_AVAILABLE 64

#se_não_definido _NT_TIB_DEFINED
#defina _NT_TIB_DEFINED
    defina_tipo estrutura _NT_TIB {
      estrutura _EXCEPTION_REGISTRATION_RECORD *ExceptionList;
      PVOID StackBase;
      PVOID StackLimit;
      PVOID SubSystemTib;
      união {
	PVOID FiberData;
	DWORD Version;
      };
      PVOID ArbitraryUserPointer;
      estrutura _NT_TIB *Self;
    } NT_TIB;
    defina_tipo NT_TIB *PNT_TIB;
#fim_se

    defina_tipo estrutura _NT_TIB32 {
      DWORD ExceptionList;
      DWORD StackBase;
      DWORD StackLimit;
      DWORD SubSystemTib;
      união {
	DWORD FiberData;
	DWORD Version;
      };
      DWORD ArbitraryUserPointer;
      DWORD Self;
    } NT_TIB32,*PNT_TIB32;

    defina_tipo estrutura _NT_TIB64 {
      DWORD64 ExceptionList;
      DWORD64 StackBase;
      DWORD64 StackLimit;
      DWORD64 SubSystemTib;
      união {
	DWORD64 FiberData;
	DWORD Version;
      };
      DWORD64 ArbitraryUserPointer;
      DWORD64 Self;
    } NT_TIB64,*PNT_TIB64;

#se !definido(I_X86_) && !definido(_IA64_) && !definido(_AMD64_)
#defina WX86
#fim_se

#defina THREAD_BASE_PRIORITY_LOWRT 15
#defina THREAD_BASE_PRIORITY_MAX 2
#defina THREAD_BASE_PRIORITY_MIN (-2)
#defina THREAD_BASE_PRIORITY_IDLE (-15)

    defina_tipo estrutura _QUOTA_LIMITS {
      SIZE_T PagedPoolLimit;
      SIZE_T NonPagedPoolLimit;
      SIZE_T MinimumWorkingSetSize;
      SIZE_T MaximumWorkingSetSize;
      SIZE_T PagefileLimit;
      LARGE_INTEGER TimeLimit;
    } QUOTA_LIMITS,*PQUOTA_LIMITS;

#defina QUOTA_LIMITS_HARDWS_MIN_ENABLE 0x00000001
#defina QUOTA_LIMITS_HARDWS_MIN_DISABLE 0x00000002
#defina QUOTA_LIMITS_HARDWS_MAX_ENABLE 0x00000004
#defina QUOTA_LIMITS_HARDWS_MAX_DISABLE 0x00000008

    defina_tipo estrutura _QUOTA_LIMITS_EX {
      SIZE_T PagedPoolLimit;
      SIZE_T NonPagedPoolLimit;
      SIZE_T MinimumWorkingSetSize;
      SIZE_T MaximumWorkingSetSize;
      SIZE_T PagefileLimit;
      LARGE_INTEGER TimeLimit;
      SIZE_T Reserved1;
      SIZE_T Reserved2;
      SIZE_T Reserved3;
      SIZE_T Reserved4;
      DWORD Flags;
      DWORD Reserved5;
    } QUOTA_LIMITS_EX,*PQUOTA_LIMITS_EX;

    defina_tipo estrutura _IO_COUNTERS {
      ULONGLONG ReadOperationCount;
      ULONGLONG WriteOperationCount;
      ULONGLONG OtherOperationCount;
      ULONGLONG ReadTransferCount;
      ULONGLONG WriteTransferCount;
      ULONGLONG OtherTransferCount;
    } IO_COUNTERS;
    defina_tipo IO_COUNTERS *PIO_COUNTERS;

    defina_tipo estrutura _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
      LARGE_INTEGER TotalUserTime;
      LARGE_INTEGER TotalKernelTime;
      LARGE_INTEGER ThisPeriodTotalUserTime;
      LARGE_INTEGER ThisPeriodTotalKernelTime;
      DWORD TotalPageFaultCount;
      DWORD TotalProcesses;
      DWORD ActiveProcesses;
      DWORD TotalTerminatedProcesses;
    } JOBOBJECT_BASIC_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;

    defina_tipo estrutura _JOBOBJECT_BASIC_LIMIT_INFORMATION {
      LARGE_INTEGER PerProcessUserTimeLimit;
      LARGE_INTEGER PerJobUserTimeLimit;
      DWORD LimitFlags;
      SIZE_T MinimumWorkingSetSize;
      SIZE_T MaximumWorkingSetSize;
      DWORD ActiveProcessLimit;
      ULONG_PTR Affinity;
      DWORD PriorityClass;
      DWORD SchedulingClass;
    } JOBOBJECT_BASIC_LIMIT_INFORMATION,*PJOBOBJECT_BASIC_LIMIT_INFORMATION;

    defina_tipo estrutura _JOBOBJECT_EXTENDED_LIMIT_INFORMATION {
      JOBOBJECT_BASIC_LIMIT_INFORMATION BasicLimitInformation;
      IO_COUNTERS IoInfo;
      SIZE_T ProcessMemoryLimit;
      SIZE_T JobMemoryLimit;
      SIZE_T PeakProcessMemoryUsed;
      SIZE_T PeakJobMemoryUsed;
    } JOBOBJECT_EXTENDED_LIMIT_INFORMATION,*PJOBOBJECT_EXTENDED_LIMIT_INFORMATION;

    defina_tipo estrutura _JOBOBJECT_BASIC_PROCESS_ID_LIST {
      DWORD NumberOfAssignedProcesses;
      DWORD NumberOfProcessIdsInList;
      ULONG_PTR ProcessIdList[1];
    } JOBOBJECT_BASIC_PROCESS_ID_LIST,*PJOBOBJECT_BASIC_PROCESS_ID_LIST;

    defina_tipo estrutura _JOBOBJECT_BASIC_UI_RESTRICTIONS {
      DWORD UIRestrictionsClass;
    } JOBOBJECT_BASIC_UI_RESTRICTIONS,*PJOBOBJECT_BASIC_UI_RESTRICTIONS;

    defina_tipo estrutura _JOBOBJECT_SECURITY_LIMIT_INFORMATION {
      DWORD SecurityLimitFlags;
      HANDLE JobToken;
      PTOKEN_GROUPS SidsToDisable;
      PTOKEN_PRIVILEGES PrivilegesToDelete;
      PTOKEN_GROUPS RestrictedSids;
    } JOBOBJECT_SECURITY_LIMIT_INFORMATION,*PJOBOBJECT_SECURITY_LIMIT_INFORMATION;

    defina_tipo estrutura _JOBOBJECT_END_OF_JOB_TIME_INFORMATION {
      DWORD EndOfJobTimeAction;
    } JOBOBJECT_END_OF_JOB_TIME_INFORMATION,*PJOBOBJECT_END_OF_JOB_TIME_INFORMATION;

    defina_tipo estrutura _JOBOBJECT_ASSOCIATE_COMPLETION_PORT {
      PVOID CompletionKey;
      HANDLE CompletionPort;
    } JOBOBJECT_ASSOCIATE_COMPLETION_PORT,*PJOBOBJECT_ASSOCIATE_COMPLETION_PORT;

    defina_tipo estrutura _JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION {
      JOBOBJECT_BASIC_ACCOUNTING_INFORMATION BasicInfo;
      IO_COUNTERS IoInfo;
    } JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION;

    defina_tipo estrutura _JOBOBJECT_JOBSET_INFORMATION {
      DWORD MemberLevel;
    } JOBOBJECT_JOBSET_INFORMATION,*PJOBOBJECT_JOBSET_INFORMATION;

#defina JOB_OBJECT_TERMINATE_AT_END_OF_JOB 0
#defina JOB_OBJECT_POST_AT_END_OF_JOB 1

#defina JOB_OBJECT_MSG_END_OF_JOB_TIME 1
#defina JOB_OBJECT_MSG_END_OF_PROCESS_TIME 2
#defina JOB_OBJECT_MSG_ACTIVE_PROCESS_LIMIT 3
#defina JOB_OBJECT_MSG_ACTIVE_PROCESS_ZERO 4
#defina JOB_OBJECT_MSG_NEW_PROCESS 6
#defina JOB_OBJECT_MSG_EXIT_PROCESS 7
#defina JOB_OBJECT_MSG_ABNORMAL_EXIT_PROCESS 8
#defina JOB_OBJECT_MSG_PROCESS_MEMORY_LIMIT 9
#defina JOB_OBJECT_MSG_JOB_MEMORY_LIMIT 10

#defina JOB_OBJECT_LIMIT_WORKINGSET 0x00000001
#defina JOB_OBJECT_LIMIT_PROCESS_TIME 0x00000002
#defina JOB_OBJECT_LIMIT_JOB_TIME 0x00000004
#defina JOB_OBJECT_LIMIT_ACTIVE_PROCESS 0x00000008
#defina JOB_OBJECT_LIMIT_AFFINITY 0x00000010
#defina JOB_OBJECT_LIMIT_PRIORITY_CLASS 0x00000020
#defina JOB_OBJECT_LIMIT_PRESERVE_JOB_TIME 0x00000040
#defina JOB_OBJECT_LIMIT_SCHEDULING_CLASS 0x00000080

#defina JOB_OBJECT_LIMIT_PROCESS_MEMORY 0x00000100
#defina JOB_OBJECT_LIMIT_JOB_MEMORY 0x00000200
#defina JOB_OBJECT_LIMIT_DIE_ON_UNHANDLED_EXCEPTION 0x00000400
#defina JOB_OBJECT_LIMIT_BREAKAWAY_OK 0x00000800
#defina JOB_OBJECT_LIMIT_SILENT_BREAKAWAY_OK 0x00001000
#defina JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE 0x00002000

#defina JOB_OBJECT_LIMIT_RESERVED2 0x00004000
#defina JOB_OBJECT_LIMIT_RESERVED3 0x00008000
#defina JOB_OBJECT_LIMIT_RESERVED4 0x00010000
#defina JOB_OBJECT_LIMIT_RESERVED5 0x00020000
#defina JOB_OBJECT_LIMIT_RESERVED6 0x00040000

#defina JOB_OBJECT_LIMIT_VALID_FLAGS 0x0007ffff

#defina JOB_OBJECT_BASIC_LIMIT_VALID_FLAGS 0x000000ff
#defina JOB_OBJECT_EXTENDED_LIMIT_VALID_FLAGS 0x00003fff
#defina JOB_OBJECT_RESERVED_LIMIT_VALID_FLAGS 0x0007ffff

#defina JOB_OBJECT_UILIMIT_NONE 0x00000000

#defina JOB_OBJECT_UILIMIT_HANDLES 0x00000001
#defina JOB_OBJECT_UILIMIT_READCLIPBOARD 0x00000002
#defina JOB_OBJECT_UILIMIT_WRITECLIPBOARD 0x00000004
#defina JOB_OBJECT_UILIMIT_SYSTEMPARAMETERS 0x00000008
#defina JOB_OBJECT_UILIMIT_DISPLAYSETTINGS 0x00000010
#defina JOB_OBJECT_UILIMIT_GLOBALATOMS 0x00000020
#defina JOB_OBJECT_UILIMIT_DESKTOP 0x00000040
#defina JOB_OBJECT_UILIMIT_EXITWINDOWS 0x00000080

#defina JOB_OBJECT_UILIMIT_ALL 0x000000FF

#defina JOB_OBJECT_UI_VALID_FLAGS 0x000000FF

#defina JOB_OBJECT_SECURITY_NO_ADMIN 0x00000001
#defina JOB_OBJECT_SECURITY_RESTRICTED_TOKEN 0x00000002
#defina JOB_OBJECT_SECURITY_ONLY_TOKEN 0x00000004
#defina JOB_OBJECT_SECURITY_FILTER_TOKENS 0x00000008

#defina JOB_OBJECT_SECURITY_VALID_FLAGS 0x0000000f

    defina_tipo enumeração _JOBOBJECTINFOCLASS {
      JobObjectBasicAccountingInformation = 1,JobObjectBasicLimitInformation,JobObjectBasicProcessIdList,JobObjectBasicUIRestrictions,
      JobObjectSecurityLimitInformation,JobObjectEndOfJobTimeInformation,JobObjectAssociateCompletionPortInformation,
      JobObjectBasicAndIoAccountingInformation,JobObjectExtendedLimitInformation,JobObjectJobSetInformation,MaxJobObjectInfoClass
    } JOBOBJECTINFOCLASS;

#defina EVENT_MODIFY_STATE 0x0002
#defina EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#defina MUTANT_QUERY_STATE 0x0001

#defina MUTANT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| MUTANT_QUERY_STATE)
#defina SEMAPHORE_MODIFY_STATE 0x0002
#defina SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#defina TIMER_QUERY_STATE 0x0001
#defina TIMER_MODIFY_STATE 0x0002

#defina TIMER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| TIMER_QUERY_STATE|TIMER_MODIFY_STATE)

#defina TIME_ZONE_ID_UNKNOWN 0
#defina TIME_ZONE_ID_STANDARD 1
#defina TIME_ZONE_ID_DAYLIGHT 2

    defina_tipo enumeração _LOGICAL_PROCESSOR_RELATIONSHIP {
      RelationProcessorCore,RelationNumaNode,RelationCache
    } LOGICAL_PROCESSOR_RELATIONSHIP;

#defina LTP_PC_SMT 0x1

    defina_tipo enumeração _PROCESSOR_CACHE_TYPE {
      CacheUnified,CacheInstruction,CacheData,CacheTrace
    } PROCESSOR_CACHE_TYPE;

#defina CACHE_FULLY_ASSOCIATIVE 0xFF

    defina_tipo estrutura _CACHE_DESCRIPTOR {
      BYTE Level;
      BYTE Associativity;
      WORD LineSize;
      DWORD Size;
      PROCESSOR_CACHE_TYPE Type;
    } CACHE_DESCRIPTOR,*PCACHE_DESCRIPTOR;

    defina_tipo estrutura _SYSTEM_LOGICAL_PROCESSOR_INFORMATION {
      ULONG_PTR ProcessorMask;
      LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
      união {
	estrutura {
	  BYTE Flags;
	} ProcessorCore;
	estrutura {
	  DWORD NodeNumber;
	} NumaNode;
	CACHE_DESCRIPTOR Cache;
	ULONGLONG Reserved[2];
      };
    } SYSTEM_LOGICAL_PROCESSOR_INFORMATION,*PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;

#defina PROCESSOR_INTEL_386 386
#defina PROCESSOR_INTEL_486 486
#defina PROCESSOR_INTEL_PENTIUM 586
#defina PROCESSOR_INTEL_IA64 2200
#defina PROCESSOR_AMD_X8664 8664
#defina PROCESSOR_MIPS_R4000 4000
#defina PROCESSOR_ALPHA_21064 21064
#defina PROCESSOR_PPC_601 601
#defina PROCESSOR_PPC_603 603
#defina PROCESSOR_PPC_604 604
#defina PROCESSOR_PPC_620 620
#defina PROCESSOR_HITACHI_SH3 10003
#defina PROCESSOR_HITACHI_SH3E 10004
#defina PROCESSOR_HITACHI_SH4 10005
#defina PROCESSOR_MOTOROLA_821 821
#defina PROCESSOR_SHx_SH3 103
#defina PROCESSOR_SHx_SH4 104
#defina PROCESSOR_STRONGARM 2577
#defina PROCESSOR_ARM720 1824
#defina PROCESSOR_ARM820 2080
#defina PROCESSOR_ARM920 2336
#defina PROCESSOR_ARM_7TDMI 70001
#defina PROCESSOR_OPTIL 0x494f

#defina PROCESSOR_ARCHITECTURE_INTEL 0
#defina PROCESSOR_ARCHITECTURE_MIPS 1
#defina PROCESSOR_ARCHITECTURE_ALPHA 2
#defina PROCESSOR_ARCHITECTURE_PPC 3
#defina PROCESSOR_ARCHITECTURE_SHX 4
#defina PROCESSOR_ARCHITECTURE_ARM 5
#defina PROCESSOR_ARCHITECTURE_IA64 6
#defina PROCESSOR_ARCHITECTURE_ALPHA64 7
#defina PROCESSOR_ARCHITECTURE_MSIL 8
#defina PROCESSOR_ARCHITECTURE_AMD64 9
#defina PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 10

#defina PROCESSOR_ARCHITECTURE_UNKNOWN 0xFFFF

#defina PF_FLOATING_POINT_PRECISION_ERRATA 0
#defina PF_FLOATING_POINT_EMULATED 1
#defina PF_COMPARE_EXCHANGE_DOUBLE 2
#defina PF_MMX_INSTRUCTIONS_AVAILABLE 3
#defina PF_PPC_MOVEMEM_64BIT_OK 4
#defina PF_ALPHA_BYTE_INSTRUCTIONS 5
#defina PF_XMMI_INSTRUCTIONS_AVAILABLE 6
#defina PF_3DNOW_INSTRUCTIONS_AVAILABLE 7
#defina PF_RDTSC_INSTRUCTION_AVAILABLE 8
#defina PF_PAE_ENABLED 9
#defina PF_XMMI64_INSTRUCTIONS_AVAILABLE 10
#defina PF_SSE_DAZ_MODE_AVAILABLE 11
#defina PF_NX_ENABLED 12

    defina_tipo estrutura _MEMORY_BASIC_INFORMATION {
      PVOID BaseAddress;
      PVOID AllocationBase;
      DWORD AllocationProtect;
      SIZE_T RegionSize;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } MEMORY_BASIC_INFORMATION,*PMEMORY_BASIC_INFORMATION;

    defina_tipo estrutura _MEMORY_BASIC_INFORMATION32 {
      DWORD BaseAddress;
      DWORD AllocationBase;
      DWORD AllocationProtect;
      DWORD RegionSize;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } MEMORY_BASIC_INFORMATION32,*PMEMORY_BASIC_INFORMATION32;

    defina_tipo DECLSPEC_ALIGN(16) estrutura _MEMORY_BASIC_INFORMATION64 {
      ULONGLONG BaseAddress;
      ULONGLONG AllocationBase;
      DWORD AllocationProtect;
      DWORD __alignment1;
      ULONGLONG RegionSize;
      DWORD State;
      DWORD Protect;
      DWORD Type;
      DWORD __alignment2;
    } MEMORY_BASIC_INFORMATION64,*PMEMORY_BASIC_INFORMATION64;

#defina SECTION_QUERY 0x0001
#defina SECTION_MAP_WRITE 0x0002
#defina SECTION_MAP_READ 0x0004
#defina SECTION_MAP_EXECUTE 0x0008
#defina SECTION_EXTEND_SIZE 0x0010
#defina SECTION_MAP_EXECUTE_EXPLICIT 0x0020

#defina SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY| SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_SIZE)
#defina PAGE_NOACCESS 0x01
#defina PAGE_READONLY 0x02
#defina PAGE_READWRITE 0x04
#defina PAGE_WRITECOPY 0x08
#defina PAGE_EXECUTE 0x10
#defina PAGE_EXECUTE_READ 0x20
#defina PAGE_EXECUTE_READWRITE 0x40
#defina PAGE_EXECUTE_WRITECOPY 0x80
#defina PAGE_GUARD 0x100
#defina PAGE_NOCACHE 0x200
#defina PAGE_WRITECOMBINE 0x400
#defina MEM_COMMIT 0x1000
#defina MEM_RESERVE 0x2000
#defina MEM_DECOMMIT 0x4000
#defina MEM_RELEASE 0x8000
#defina MEM_FREE 0x10000
#defina MEM_PRIVATE 0x20000
#defina MEM_MAPPED 0x40000
#defina MEM_RESET 0x80000
#defina MEM_TOP_DOWN 0x100000
#defina MEM_WRITE_WATCH 0x200000
#defina MEM_PHYSICAL 0x400000
#defina MEM_LARGE_PAGES 0x20000000
#defina MEM_4MB_PAGES 0x80000000
#defina SEC_FILE 0x800000
#defina SEC_IMAGE 0x1000000
#defina SEC_RESERVE 0x4000000
#defina SEC_COMMIT 0x8000000
#defina SEC_NOCACHE 0x10000000
#defina SEC_LARGE_PAGES 0x80000000
#defina MEM_IMAGE SEC_IMAGE
#defina WRITE_WATCH_FLAG_RESET 0x01

#defina FILE_READ_DATA (0x0001)
#defina FILE_LIST_DIRECTORY (0x0001)

#defina FILE_WRITE_DATA (0x0002)
#defina FILE_ADD_FILE (0x0002)

#defina FILE_APPEND_DATA (0x0004)
#defina FILE_ADD_SUBDIRECTORY (0x0004)
#defina FILE_CREATE_PIPE_INSTANCE (0x0004)

#defina FILE_READ_EA (0x0008)

#defina FILE_WRITE_EA (0x0010)

#defina FILE_EXECUTE (0x0020)
#defina FILE_TRAVERSE (0x0020)

#defina FILE_DELETE_CHILD (0x0040)

#defina FILE_READ_ATTRIBUTES (0x0080)

#defina FILE_WRITE_ATTRIBUTES (0x0100)

#defina FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#defina FILE_GENERIC_READ (STANDARD_RIGHTS_READ | FILE_READ_DATA | FILE_READ_ATTRIBUTES | FILE_READ_EA | SYNCHRONIZE)
#defina FILE_GENERIC_WRITE (STANDARD_RIGHTS_WRITE | FILE_WRITE_DATA | FILE_WRITE_ATTRIBUTES | FILE_WRITE_EA | FILE_APPEND_DATA | SYNCHRONIZE)
#defina FILE_GENERIC_EXECUTE (STANDARD_RIGHTS_EXECUTE | FILE_READ_ATTRIBUTES | FILE_EXECUTE | SYNCHRONIZE)

#defina FILE_SHARE_READ 0x00000001
#defina FILE_SHARE_WRITE 0x00000002
#defina FILE_SHARE_DELETE 0x00000004
#defina FILE_ATTRIBUTE_READONLY 0x00000001
#defina FILE_ATTRIBUTE_HIDDEN 0x00000002
#defina FILE_ATTRIBUTE_SYSTEM 0x00000004
#defina FILE_ATTRIBUTE_DIRECTORY 0x00000010
#defina FILE_ATTRIBUTE_ARCHIVE 0x00000020
#defina FILE_ATTRIBUTE_DEVICE 0x00000040
#defina FILE_ATTRIBUTE_NORMAL 0x00000080
#defina FILE_ATTRIBUTE_TEMPORARY 0x00000100
#defina FILE_ATTRIBUTE_SPARSE_FILE 0x00000200
#defina FILE_ATTRIBUTE_REPARSE_POINT 0x00000400
#defina FILE_ATTRIBUTE_COMPRESSED 0x00000800
#defina FILE_ATTRIBUTE_OFFLINE 0x00001000
#defina FILE_ATTRIBUTE_NOT_CONTENT_INDEXED 0x00002000
#defina FILE_ATTRIBUTE_ENCRYPTED 0x00004000
#defina FILE_NOTIFY_CHANGE_FILE_NAME 0x00000001
#defina FILE_NOTIFY_CHANGE_DIR_NAME 0x00000002
#defina FILE_NOTIFY_CHANGE_ATTRIBUTES 0x00000004
#defina FILE_NOTIFY_CHANGE_SIZE 0x00000008
#defina FILE_NOTIFY_CHANGE_LAST_WRITE 0x00000010
#defina FILE_NOTIFY_CHANGE_LAST_ACCESS 0x00000020
#defina FILE_NOTIFY_CHANGE_CREATION 0x00000040
#defina FILE_NOTIFY_CHANGE_SECURITY 0x00000100
#defina FILE_ACTION_ADDED 0x00000001
#defina FILE_ACTION_REMOVED 0x00000002
#defina FILE_ACTION_MODIFIED 0x00000003
#defina FILE_ACTION_RENAMED_OLD_NAME 0x00000004
#defina FILE_ACTION_RENAMED_NEW_NAME 0x00000005
#defina MAILSLOT_NO_MESSAGE ((DWORD)-1)
#defina MAILSLOT_WAIT_FOREVER ((DWORD)-1)
#defina FILE_CASE_SENSITIVE_SEARCH 0x00000001
#defina FILE_CASE_PRESERVED_NAMES 0x00000002
#defina FILE_UNICODE_ON_DISK 0x00000004
#defina FILE_PERSISTENT_ACLS 0x00000008
#defina FILE_FILE_COMPRESSION 0x00000010
#defina FILE_VOLUME_QUOTAS 0x00000020
#defina FILE_SUPPORTS_SPARSE_FILES 0x00000040
#defina FILE_SUPPORTS_REPARSE_POINTS 0x00000080
#defina FILE_SUPPORTS_REMOTE_STORAGE 0x00000100
#defina FILE_VOLUME_IS_COMPRESSED 0x00008000
#defina FILE_SUPPORTS_OBJECT_IDS 0x00010000
#defina FILE_SUPPORTS_ENCRYPTION 0x00020000
#defina FILE_NAMED_STREAMS 0x00040000
#defina FILE_READ_ONLY_VOLUME 0x00080000

    defina_tipo estrutura _FILE_NOTIFY_INFORMATION {
      DWORD NextEntryOffset;
      DWORD Action;
      DWORD FileNameLength;
      WCHAR FileName[1];
    } FILE_NOTIFY_INFORMATION,*PFILE_NOTIFY_INFORMATION;

    defina_tipo união _FILE_SEGMENT_ELEMENT {
      PVOID64 Buffer;
      ULONGLONG Alignment;
    }FILE_SEGMENT_ELEMENT,*PFILE_SEGMENT_ELEMENT;

    defina_tipo estrutura _REPARSE_GUID_DATA_BUFFER {
      DWORD ReparseTag;
      WORD ReparseDataLength;
      WORD Reserved;
      GUID ReparseGuid;
      estrutura {
	BYTE DataBuffer[1];
      } GenericReparseBuffer;
    } REPARSE_GUID_DATA_BUFFER,*PREPARSE_GUID_DATA_BUFFER;

#defina REPARSE_GUID_DATA_BUFFER_HEADER_SIZE FIELD_OFFSET(REPARSE_GUID_DATA_BUFFER,GenericReparseBuffer)

#defina MAXIMUM_REPARSE_DATA_BUFFER_SIZE (16 *1024)

#defina IO_REPARSE_TAG_RESERVED_ZERO (0)
#defina IO_REPARSE_TAG_RESERVED_ONE (1)

#defina IO_REPARSE_TAG_RESERVED_RANGE IO_REPARSE_TAG_RESERVED_ONE

#defina IsReparseTagMicrosoft(_tag) (((_tag) & 0x80000000))
#defina IsReparseTagNameSurrogate(_tag) (((_tag) & 0x20000000))

#defina IO_REPARSE_TAG_MOUNT_POINT (0xA0000003L)
#defina IO_REPARSE_TAG_HSM (0xC0000004L)
#defina IO_REPARSE_TAG_SIS (0x80000007L)
#defina IO_REPARSE_TAG_DFS (0x8000000AL)
#defina IO_REPARSE_TAG_FILTER_MANAGER (0x8000000BL)
#defina IO_COMPLETION_MODIFY_STATE 0x0002
#defina IO_COMPLETION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#defina DUPLICATE_CLOSE_SOURCE 0x00000001
#defina DUPLICATE_SAME_ACCESS 0x00000002

    defina_tipo enumeração _SYSTEM_POWER_STATE {
      PowerSystemUnspecified = 0,PowerSystemWorking = 1,PowerSystemSleeping1 = 2,PowerSystemSleeping2 = 3,PowerSystemSleeping3 = 4,PowerSystemHibernate = 5,PowerSystemShutdown = 6,PowerSystemMaximum = 7
    } SYSTEM_POWER_STATE,*PSYSTEM_POWER_STATE;

#defina POWER_SYSTEM_MAXIMUM 7

    defina_tipo enumeração {
      PowerActionNone = 0,PowerActionReserved,PowerActionSleep,PowerActionHibernate,PowerActionShutdown,PowerActionShutdownReset,PowerActionShutdownOff,PowerActionWarmEject
    } POWER_ACTION,*PPOWER_ACTION;

    defina_tipo enumeração _DEVICE_POWER_STATE {
      PowerDeviceUnspecified = 0,PowerDeviceD0,PowerDeviceD1,PowerDeviceD2,PowerDeviceD3,PowerDeviceMaximum
    } DEVICE_POWER_STATE,*PDEVICE_POWER_STATE;

#defina ES_SYSTEM_REQUIRED ((DWORD)0x00000001)
#defina ES_DISPLAY_REQUIRED ((DWORD)0x00000002)
#defina ES_USER_PRESENT ((DWORD)0x00000004)
#defina ES_CONTINUOUS ((DWORD)0x80000000)

    defina_tipo DWORD EXECUTION_STATE;

    defina_tipo enumeração {
      LT_DONT_CARE,LT_LOWEST_LATENCY
    } LATENCY_TIME;

#defina PDCAP_D0_SUPPORTED 0x00000001
#defina PDCAP_D1_SUPPORTED 0x00000002
#defina PDCAP_D2_SUPPORTED 0x00000004
#defina PDCAP_D3_SUPPORTED 0x00000008
#defina PDCAP_WAKE_FROM_D0_SUPPORTED 0x00000010
#defina PDCAP_WAKE_FROM_D1_SUPPORTED 0x00000020
#defina PDCAP_WAKE_FROM_D2_SUPPORTED 0x00000040
#defina PDCAP_WAKE_FROM_D3_SUPPORTED 0x00000080
#defina PDCAP_WARM_EJECT_SUPPORTED 0x00000100

    defina_tipo estrutura CM_Power_Data_s {
      DWORD PD_Size;
      DEVICE_POWER_STATE PD_MostRecentPowerState;
      DWORD PD_Capabilities;
      DWORD PD_D1Latency;
      DWORD PD_D2Latency;
      DWORD PD_D3Latency;
      DEVICE_POWER_STATE PD_PowerStateMapping[POWER_SYSTEM_MAXIMUM];
      SYSTEM_POWER_STATE PD_DeepestSystemWake;
    } CM_POWER_DATA,*PCM_POWER_DATA;

    defina_tipo enumeração {
      SystemPowerPolicyAc,SystemPowerPolicyDc,VerifySystemPolicyAc,VerifySystemPolicyDc,SystemPowerCapabilities,SystemBatteryState,SystemPowerStateHandler,ProcessorStateHandler,SystemPowerPolicyCurrent,AdministratorPowerPolicy,SystemReserveHiberFile,ProcessorInformation,SystemPowerInformation,ProcessorStateHandler2,LastWakeTime,LastSleepTime,SystemExecutionState,SystemPowerStateNotifyHandler,ProcessorPowerPolicyAc,ProcessorPowerPolicyDc,VerifyProcessorPowerPolicyAc,VerifyProcessorPowerPolicyDc,ProcessorPowerPolicyCurrent,SystemPowerStateLogging,SystemPowerLoggingEntry
    } POWER_INFORMATION_LEVEL;

    defina_tipo estrutura {
      DWORD Granularity;
      DWORD Capacity;
    } BATTERY_REPORTING_SCALE,*PBATTERY_REPORTING_SCALE;

    defina_tipo estrutura {
      POWER_ACTION Action;
      DWORD Flags;
      DWORD EventCode;
    } POWER_ACTION_POLICY,*PPOWER_ACTION_POLICY;

#defina POWER_ACTION_QUERY_ALLOWED 0x00000001
#defina POWER_ACTION_UI_ALLOWED 0x00000002
#defina POWER_ACTION_OVERRIDE_APPS 0x00000004
#defina POWER_ACTION_LIGHTEST_FIRST 0x10000000
#defina POWER_ACTION_LOCK_CONSOLE 0x20000000
#defina POWER_ACTION_DISABLE_WAKES 0x40000000
#defina POWER_ACTION_CRITICAL 0x80000000

#defina POWER_LEVEL_USER_NOTIFY_TEXT 0x00000001
#defina POWER_LEVEL_USER_NOTIFY_SOUND 0x00000002
#defina POWER_LEVEL_USER_NOTIFY_EXEC 0x00000004
#defina POWER_USER_NOTIFY_BUTTON 0x00000008
#defina POWER_USER_NOTIFY_SHUTDOWN 0x00000010
#defina POWER_FORCE_TRIGGER_RESET 0x80000000

    defina_tipo estrutura {
      BOOLEAN Enable;
      BYTE Spare[3];
      DWORD BatteryLevel;
      POWER_ACTION_POLICY PowerPolicy;
      SYSTEM_POWER_STATE MinSystemState;
    } SYSTEM_POWER_LEVEL,*PSYSTEM_POWER_LEVEL;

#defina NUM_DISCHARGE_POLICIES 4
#defina DISCHARGE_POLICY_CRITICAL 0
#defina DISCHARGE_POLICY_LOW 1

#defina PO_THROTTLE_NONE 0
#defina PO_THROTTLE_CONSTANT 1
#defina PO_THROTTLE_DEGRADE 2
#defina PO_THROTTLE_ADAPTIVE 3
#defina PO_THROTTLE_MAXIMUM 4

    defina_tipo estrutura _SYSTEM_POWER_POLICY {
      DWORD Revision;
      POWER_ACTION_POLICY PowerButton;
      POWER_ACTION_POLICY SleepButton;
      POWER_ACTION_POLICY LidClose;
      SYSTEM_POWER_STATE LidOpenWake;
      DWORD Reserved;
      POWER_ACTION_POLICY Idle;
      DWORD IdleTimeout;
      BYTE IdleSensitivity;
      BYTE DynamicThrottle;
      BYTE Spare2[2];
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      SYSTEM_POWER_STATE ReducedLatencySleep;
      DWORD WinLogonFlags;
      DWORD Spare3;
      DWORD DozeS4Timeout;
      DWORD BroadcastCapacityResolution;
      SYSTEM_POWER_LEVEL DischargePolicy[NUM_DISCHARGE_POLICIES];
      DWORD VideoTimeout;
      BOOLEAN VideoDimDisplay;
      DWORD VideoReserved[3];
      DWORD SpindownTimeout;
      BOOLEAN OptimizeForPower;
      BYTE FanThrottleTolerance;
      BYTE ForcedThrottle;
      BYTE MinThrottle;
      POWER_ACTION_POLICY OverThrottled;
    } SYSTEM_POWER_POLICY,*PSYSTEM_POWER_POLICY;

    defina_tipo estrutura _PROCESSOR_POWER_POLICY_INFO {
      DWORD TimeCheck;
      DWORD DemoteLimit;
      DWORD PromoteLimit;
      BYTE DemotePercent;
      BYTE PromotePercent;
      BYTE Spare[2];
      DWORD AllowDemotion:1;
      DWORD AllowPromotion:1;
      DWORD Reserved:30;
    } PROCESSOR_POWER_POLICY_INFO,*PPROCESSOR_POWER_POLICY_INFO;

    defina_tipo estrutura _PROCESSOR_POWER_POLICY {
      DWORD Revision;
      BYTE DynamicThrottle;
      BYTE Spare[3];
      DWORD DisableCStates:1;
      DWORD Reserved:31;
      DWORD PolicyCount;
      PROCESSOR_POWER_POLICY_INFO Policy[3];
    } PROCESSOR_POWER_POLICY,*PPROCESSOR_POWER_POLICY;

    defina_tipo estrutura _ADMINISTRATOR_POWER_POLICY {
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      DWORD MinVideoTimeout;
      DWORD MaxVideoTimeout;
      DWORD MinSpindownTimeout;
      DWORD MaxSpindownTimeout;
    } ADMINISTRATOR_POWER_POLICY,*PADMINISTRATOR_POWER_POLICY;

    defina_tipo estrutura {
      BOOLEAN PowerButtonPresent;
      BOOLEAN SleepButtonPresent;
      BOOLEAN LidPresent;
      BOOLEAN SystemS1;
      BOOLEAN SystemS2;
      BOOLEAN SystemS3;
      BOOLEAN SystemS4;
      BOOLEAN SystemS5;
      BOOLEAN HiberFilePresent;
      BOOLEAN FullWake;
      BOOLEAN VideoDimPresent;
      BOOLEAN ApmPresent;
      BOOLEAN UpsPresent;
      BOOLEAN ThermalControl;
      BOOLEAN ProcessorThrottle;
      BYTE ProcessorMinThrottle;
      BYTE ProcessorMaxThrottle;
      BYTE spare2[4];
      BOOLEAN DiskSpinDown;
      BYTE spare3[8];
      BOOLEAN SystemBatteriesPresent;
      BOOLEAN BatteriesAreShortTerm;
      BATTERY_REPORTING_SCALE BatteryScale[3];
      SYSTEM_POWER_STATE AcOnLineWake;
      SYSTEM_POWER_STATE SoftLidWake;
      SYSTEM_POWER_STATE RtcWake;
      SYSTEM_POWER_STATE MinDeviceWakeState;
      SYSTEM_POWER_STATE DefaultLowLatencyWake;
    } SYSTEM_POWER_CAPABILITIES,*PSYSTEM_POWER_CAPABILITIES;

    defina_tipo estrutura {
      BOOLEAN AcOnLine;
      BOOLEAN BatteryPresent;
      BOOLEAN Charging;
      BOOLEAN Discharging;
      BOOLEAN Spare1[4];
      DWORD MaxCapacity;
      DWORD RemainingCapacity;
      DWORD Rate;
      DWORD EstimatedTime;
      DWORD DefaultAlert1;
      DWORD DefaultAlert2;
    } SYSTEM_BATTERY_STATE,*PSYSTEM_BATTERY_STATE;

#inclua "pshpack4.h"

#defina IMAGE_DOS_SIGNATURE 0x5A4D
#defina IMAGE_OS2_SIGNATURE 0x454E
#defina IMAGE_OS2_SIGNATURE_LE 0x454C
#defina IMAGE_VXD_SIGNATURE 0x454C
#defina IMAGE_NT_SIGNATURE 0x00004550

#inclua "pshpack2.h"

    defina_tipo estrutura _IMAGE_DOS_HEADER {
      WORD e_magic;
      WORD e_cblp;
      WORD e_cp;
      WORD e_crlc;
      WORD e_cparhdr;
      WORD e_minalloc;
      WORD e_maxalloc;
      WORD e_ss;
      WORD e_sp;
      WORD e_csum;
      WORD e_ip;
      WORD e_cs;
      WORD e_lfarlc;
      WORD e_ovno;
      WORD e_res[4];
      WORD e_oemid;
      WORD e_oeminfo;
      WORD e_res2[10];
      LONG e_lfanew;
    } IMAGE_DOS_HEADER,*PIMAGE_DOS_HEADER;

    defina_tipo estrutura _IMAGE_OS2_HEADER {
      WORD ne_magic;
      CHAR ne_ver;
      CHAR ne_rev;
      WORD ne_enttab;
      WORD ne_cbenttab;
      LONG ne_crc;
      WORD ne_flags;
      WORD ne_autodata;
      WORD ne_heap;
      WORD ne_stack;
      LONG ne_csip;
      LONG ne_sssp;
      WORD ne_cseg;
      WORD ne_cmod;
      WORD ne_cbnrestab;
      WORD ne_segtab;
      WORD ne_rsrctab;
      WORD ne_restab;
      WORD ne_modtab;
      WORD ne_imptab;
      LONG ne_nrestab;
      WORD ne_cmovent;
      WORD ne_align;
      WORD ne_cres;
      BYTE ne_exetyp;
      BYTE ne_flagsothers;
      WORD ne_pretthunks;
      WORD ne_psegrefbytes;
      WORD ne_swaparea;
      WORD ne_expver;
    } IMAGE_OS2_HEADER,*PIMAGE_OS2_HEADER;

    defina_tipo estrutura _IMAGE_VXD_HEADER {
      WORD e32_magic;
      BYTE e32_border;
      BYTE e32_worder;
      DWORD e32_level;
      WORD e32_cpu;
      WORD e32_os;
      DWORD e32_ver;
      DWORD e32_mflags;
      DWORD e32_mpages;
      DWORD e32_startobj;
      DWORD e32_eip;
      DWORD e32_stackobj;
      DWORD e32_esp;
      DWORD e32_pagesize;
      DWORD e32_lastpagesize;
      DWORD e32_fixupsize;
      DWORD e32_fixupsum;
      DWORD e32_ldrsize;
      DWORD e32_ldrsum;
      DWORD e32_objtab;
      DWORD e32_objcnt;
      DWORD e32_objmap;
      DWORD e32_itermap;
      DWORD e32_rsrctab;
      DWORD e32_rsrccnt;
      DWORD e32_restab;
      DWORD e32_enttab;
      DWORD e32_dirtab;
      DWORD e32_dircnt;
      DWORD e32_fpagetab;
      DWORD e32_frectab;
      DWORD e32_impmod;
      DWORD e32_impmodcnt;
      DWORD e32_impproc;
      DWORD e32_pagesum;
      DWORD e32_datapage;
      DWORD e32_preload;
      DWORD e32_nrestab;
      DWORD e32_cbnrestab;
      DWORD e32_nressum;
      DWORD e32_autodata;
      DWORD e32_debuginfo;
      DWORD e32_debuglen;
      DWORD e32_instpreload;
      DWORD e32_instdemand;
      DWORD e32_heapsize;
      BYTE e32_res3[12];
      DWORD e32_winresoff;
      DWORD e32_winreslen;
      WORD e32_devid;
      WORD e32_ddkver;
    } IMAGE_VXD_HEADER,*PIMAGE_VXD_HEADER;

#inclua "poppack.h"

    defina_tipo estrutura _IMAGE_FILE_HEADER {
      WORD Machine;
      WORD NumberOfSections;
      DWORD TimeDateStamp;
      DWORD PointerToSymbolTable;
      DWORD NumberOfSymbols;
      WORD SizeOfOptionalHeader;
      WORD Characteristics;
    } IMAGE_FILE_HEADER,*PIMAGE_FILE_HEADER;

#defina IMAGE_SIZEOF_FILE_HEADER 20

#defina IMAGE_FILE_RELOCS_STRIPPED 0x0001
#defina IMAGE_FILE_EXECUTABLE_IMAGE 0x0002
#defina IMAGE_FILE_LINE_NUMS_STRIPPED 0x0004
#defina IMAGE_FILE_LOCAL_SYMS_STRIPPED 0x0008
#defina IMAGE_FILE_AGGRESIVE_WS_TRIM 0x0010
#defina IMAGE_FILE_LARGE_ADDRESS_AWARE 0x0020
#defina IMAGE_FILE_BYTES_REVERSED_LO 0x0080
#defina IMAGE_FILE_32BIT_MACHINE 0x0100
#defina IMAGE_FILE_DEBUG_STRIPPED 0x0200
#defina IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP 0x0400
#defina IMAGE_FILE_NET_RUN_FROM_SWAP 0x0800
#defina IMAGE_FILE_SYSTEM 0x1000
#defina IMAGE_FILE_DLL 0x2000
#defina IMAGE_FILE_UP_SYSTEM_ONLY 0x4000
#defina IMAGE_FILE_BYTES_REVERSED_HI 0x8000

#defina IMAGE_FILE_MACHINE_UNKNOWN 0
#defina IMAGE_FILE_MACHINE_I386 0x014c
#defina IMAGE_FILE_MACHINE_R3000 0x0162
#defina IMAGE_FILE_MACHINE_R4000 0x0166
#defina IMAGE_FILE_MACHINE_R10000 0x0168
#defina IMAGE_FILE_MACHINE_WCEMIPSV2 0x0169
#defina IMAGE_FILE_MACHINE_ALPHA 0x0184
#defina IMAGE_FILE_MACHINE_SH3 0x01a2
#defina IMAGE_FILE_MACHINE_SH3DSP 0x01a3
#defina IMAGE_FILE_MACHINE_SH3E 0x01a4
#defina IMAGE_FILE_MACHINE_SH4 0x01a6
#defina IMAGE_FILE_MACHINE_SH5 0x01a8
#defina IMAGE_FILE_MACHINE_ARM 0x01c0
#defina IMAGE_FILE_MACHINE_THUMB 0x01c2
#defina IMAGE_FILE_MACHINE_AM33 0x01d3
#defina IMAGE_FILE_MACHINE_POWERPC 0x01F0
#defina IMAGE_FILE_MACHINE_POWERPCFP 0x01f1
#defina IMAGE_FILE_MACHINE_IA64 0x0200
#defina IMAGE_FILE_MACHINE_MIPS16 0x0266
#defina IMAGE_FILE_MACHINE_ALPHA64 0x0284
#defina IMAGE_FILE_MACHINE_MIPSFPU 0x0366
#defina IMAGE_FILE_MACHINE_MIPSFPU16 0x0466
#defina IMAGE_FILE_MACHINE_AXP64 IMAGE_FILE_MACHINE_ALPHA64
#defina IMAGE_FILE_MACHINE_TRICORE 0x0520
#defina IMAGE_FILE_MACHINE_CEF 0x0CEF
#defina IMAGE_FILE_MACHINE_EBC 0x0EBC
#defina IMAGE_FILE_MACHINE_AMD64 0x8664
#defina IMAGE_FILE_MACHINE_M32R 0x9041
#defina IMAGE_FILE_MACHINE_CEE 0xC0EE

    defina_tipo estrutura _IMAGE_DATA_DIRECTORY {
      DWORD VirtualAddress;
      DWORD Size;
    } IMAGE_DATA_DIRECTORY,*PIMAGE_DATA_DIRECTORY;

#defina IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

    defina_tipo estrutura _IMAGE_OPTIONAL_HEADER {

      WORD Magic;
      BYTE MajorLinkerVersion;
      BYTE MinorLinkerVersion;
      DWORD SizeOfCode;
      DWORD SizeOfInitializedData;
      DWORD SizeOfUninitializedData;
      DWORD AddressOfEntryPoint;
      DWORD BaseOfCode;
      DWORD BaseOfData;
      DWORD ImageBase;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      WORD MajorOperatingSystemVersion;
      WORD MinorOperatingSystemVersion;
      WORD MajorImageVersion;
      WORD MinorImageVersion;
      WORD MajorSubsystemVersion;
      WORD MinorSubsystemVersion;
      DWORD Win32VersionValue;
      DWORD SizeOfImage;
      DWORD SizeOfHeaders;
      DWORD CheckSum;
      WORD Subsystem;
      WORD DllCharacteristics;
      DWORD SizeOfStackReserve;
      DWORD SizeOfStackCommit;
      DWORD SizeOfHeapReserve;
      DWORD SizeOfHeapCommit;
      DWORD LoaderFlags;
      DWORD NumberOfRvaAndSizes;
      IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER32,*PIMAGE_OPTIONAL_HEADER32;

    defina_tipo estrutura _IMAGE_ROM_OPTIONAL_HEADER {
      WORD Magic;
      BYTE MajorLinkerVersion;
      BYTE MinorLinkerVersion;
      DWORD SizeOfCode;
      DWORD SizeOfInitializedData;
      DWORD SizeOfUninitializedData;
      DWORD AddressOfEntryPoint;
      DWORD BaseOfCode;
      DWORD BaseOfData;
      DWORD BaseOfBss;
      DWORD GprMask;
      DWORD CprMask[4];
      DWORD GpValue;
    } IMAGE_ROM_OPTIONAL_HEADER,*PIMAGE_ROM_OPTIONAL_HEADER;

    defina_tipo estrutura _IMAGE_OPTIONAL_HEADER64 {
      WORD Magic;
      BYTE MajorLinkerVersion;
      BYTE MinorLinkerVersion;
      DWORD SizeOfCode;
      DWORD SizeOfInitializedData;
      DWORD SizeOfUninitializedData;
      DWORD AddressOfEntryPoint;
      DWORD BaseOfCode;
      ULONGLONG ImageBase;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      WORD MajorOperatingSystemVersion;
      WORD MinorOperatingSystemVersion;
      WORD MajorImageVersion;
      WORD MinorImageVersion;
      WORD MajorSubsystemVersion;
      WORD MinorSubsystemVersion;
      DWORD Win32VersionValue;
      DWORD SizeOfImage;
      DWORD SizeOfHeaders;
      DWORD CheckSum;
      WORD Subsystem;
      WORD DllCharacteristics;
      ULONGLONG SizeOfStackReserve;
      ULONGLONG SizeOfStackCommit;
      ULONGLONG SizeOfHeapReserve;
      ULONGLONG SizeOfHeapCommit;
      DWORD LoaderFlags;
      DWORD NumberOfRvaAndSizes;
      IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER64,*PIMAGE_OPTIONAL_HEADER64;

#defina IMAGE_SIZEOF_ROM_OPTIONAL_HEADER 56
#defina IMAGE_SIZEOF_STD_OPTIONAL_HEADER 28
#defina IMAGE_SIZEOF_NT_OPTIONAL32_HEADER 224
#defina IMAGE_SIZEOF_NT_OPTIONAL64_HEADER 240

#defina IMAGE_NT_OPTIONAL_HDR32_MAGIC 0x10b
#defina IMAGE_NT_OPTIONAL_HDR64_MAGIC 0x20b
#defina IMAGE_ROM_OPTIONAL_HDR_MAGIC 0x107

#se_definido _WIN64
    defina_tipo IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_HEADER;
    defina_tipo PIMAGE_OPTIONAL_HEADER64 PIMAGE_OPTIONAL_HEADER;
#defina IMAGE_SIZEOF_NT_OPTIONAL_HEADER IMAGE_SIZEOF_NT_OPTIONAL64_HEADER
#defina IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR64_MAGIC
#senão
    defina_tipo IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER;
    defina_tipo PIMAGE_OPTIONAL_HEADER32 PIMAGE_OPTIONAL_HEADER;
#defina IMAGE_SIZEOF_NT_OPTIONAL_HEADER IMAGE_SIZEOF_NT_OPTIONAL32_HEADER
#defina IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR32_MAGIC
#fim_se

    defina_tipo estrutura _IMAGE_NT_HEADERS64 {
      DWORD Signature;
      IMAGE_FILE_HEADER FileHeader;
      IMAGE_OPTIONAL_HEADER64 OptionalHeader;
    } IMAGE_NT_HEADERS64,*PIMAGE_NT_HEADERS64;

    defina_tipo estrutura _IMAGE_NT_HEADERS {
      DWORD Signature;
      IMAGE_FILE_HEADER FileHeader;
      IMAGE_OPTIONAL_HEADER32 OptionalHeader;
    } IMAGE_NT_HEADERS32,*PIMAGE_NT_HEADERS32;

    defina_tipo estrutura _IMAGE_ROM_HEADERS {
      IMAGE_FILE_HEADER FileHeader;
      IMAGE_ROM_OPTIONAL_HEADER OptionalHeader;
    } IMAGE_ROM_HEADERS,*PIMAGE_ROM_HEADERS;

#se_definido _WIN64
    defina_tipo IMAGE_NT_HEADERS64 IMAGE_NT_HEADERS;
    defina_tipo PIMAGE_NT_HEADERS64 PIMAGE_NT_HEADERS;
#senão
    defina_tipo IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS;
    defina_tipo PIMAGE_NT_HEADERS32 PIMAGE_NT_HEADERS;
#fim_se

#defina IMAGE_FIRST_SECTION(ntheader) ((PIMAGE_SECTION_HEADER) ((ULONG_PTR)ntheader + FIELD_OFFSET(IMAGE_NT_HEADERS,OptionalHeader) + ((PIMAGE_NT_HEADERS)(ntheader))->FileHeader.SizeOfOptionalHeader))

#defina IMAGE_SUBSYSTEM_UNKNOWN 0
#defina IMAGE_SUBSYSTEM_NATIVE 1
#defina IMAGE_SUBSYSTEM_WINDOWS_GUI 2
#defina IMAGE_SUBSYSTEM_WINDOWS_CUI 3
#defina IMAGE_SUBSYSTEM_OS2_CUI 5
#defina IMAGE_SUBSYSTEM_POSIX_CUI 7
#defina IMAGE_SUBSYSTEM_NATIVE_WINDOWS 8
#defina IMAGE_SUBSYSTEM_WINDOWS_CE_GUI 9
#defina IMAGE_SUBSYSTEM_EFI_APPLICATION 10
#defina IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#defina IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER 12
#defina IMAGE_SUBSYSTEM_EFI_ROM 13
#defina IMAGE_SUBSYSTEM_XBOX 14

#defina IMAGE_DLLCHARACTERISTICS_NO_ISOLATION 0x0200
#defina IMAGE_DLLCHARACTERISTICS_NO_SEH 0x0400
#defina IMAGE_DLLCHARACTERISTICS_NO_BIND 0x0800
#defina IMAGE_DLLCHARACTERISTICS_WDM_DRIVER 0x2000
#defina IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#defina IMAGE_DIRECTORY_ENTRY_EXPORT 0
#defina IMAGE_DIRECTORY_ENTRY_IMPORT 1
#defina IMAGE_DIRECTORY_ENTRY_RESOURCE 2
#defina IMAGE_DIRECTORY_ENTRY_EXCEPTION 3
#defina IMAGE_DIRECTORY_ENTRY_SECURITY 4
#defina IMAGE_DIRECTORY_ENTRY_BASERELOC 5
#defina IMAGE_DIRECTORY_ENTRY_DEBUG 6

#defina IMAGE_DIRECTORY_ENTRY_ARCHITECTURE 7
#defina IMAGE_DIRECTORY_ENTRY_GLOBALPTR 8
#defina IMAGE_DIRECTORY_ENTRY_TLS 9
#defina IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG 10
#defina IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT 11
#defina IMAGE_DIRECTORY_ENTRY_IAT 12
#defina IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT 13
#defina IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR 14

    defina_tipo estrutura ANON_OBJECT_HEADER {
      WORD Sig1;
      WORD Sig2;
      WORD Version;
      WORD Machine;
      DWORD TimeDateStamp;
      CLSID ClassID;
      DWORD SizeOfData;
    } ANON_OBJECT_HEADER;

#defina IMAGE_SIZEOF_SHORT_NAME 8

    defina_tipo estrutura _IMAGE_SECTION_HEADER {
      BYTE Name[IMAGE_SIZEOF_SHORT_NAME];
      união {
	DWORD PhysicalAddress;
	DWORD VirtualSize;
      } Misc;
      DWORD VirtualAddress;
      DWORD SizeOfRawData;
      DWORD PointerToRawData;
      DWORD PointerToRelocations;
      DWORD PointerToLinenumbers;
      WORD NumberOfRelocations;
      WORD NumberOfLinenumbers;
      DWORD Characteristics;
    } IMAGE_SECTION_HEADER,*PIMAGE_SECTION_HEADER;

#defina IMAGE_SIZEOF_SECTION_HEADER 40

#defina IMAGE_SCN_TYPE_NO_PAD 0x00000008

#defina IMAGE_SCN_CNT_CODE 0x00000020
#defina IMAGE_SCN_CNT_INITIALIZED_DATA 0x00000040
#defina IMAGE_SCN_CNT_UNINITIALIZED_DATA 0x00000080
#defina IMAGE_SCN_LNK_OTHER 0x00000100
#defina IMAGE_SCN_LNK_INFO 0x00000200
#defina IMAGE_SCN_LNK_REMOVE 0x00000800
#defina IMAGE_SCN_LNK_COMDAT 0x00001000
#defina IMAGE_SCN_NO_DEFER_SPEC_EXC 0x00004000
#defina IMAGE_SCN_GPREL 0x00008000
#defina IMAGE_SCN_MEM_FARDATA 0x00008000
#defina IMAGE_SCN_MEM_PURGEABLE 0x00020000
#defina IMAGE_SCN_MEM_16BIT 0x00020000
#defina IMAGE_SCN_MEM_LOCKED 0x00040000
#defina IMAGE_SCN_MEM_PRELOAD 0x00080000

#defina IMAGE_SCN_ALIGN_1BYTES 0x00100000
#defina IMAGE_SCN_ALIGN_2BYTES 0x00200000
#defina IMAGE_SCN_ALIGN_4BYTES 0x00300000
#defina IMAGE_SCN_ALIGN_8BYTES 0x00400000
#defina IMAGE_SCN_ALIGN_16BYTES 0x00500000
#defina IMAGE_SCN_ALIGN_32BYTES 0x00600000
#defina IMAGE_SCN_ALIGN_64BYTES 0x00700000
#defina IMAGE_SCN_ALIGN_128BYTES 0x00800000
#defina IMAGE_SCN_ALIGN_256BYTES 0x00900000
#defina IMAGE_SCN_ALIGN_512BYTES 0x00A00000
#defina IMAGE_SCN_ALIGN_1024BYTES 0x00B00000
#defina IMAGE_SCN_ALIGN_2048BYTES 0x00C00000
#defina IMAGE_SCN_ALIGN_4096BYTES 0x00D00000
#defina IMAGE_SCN_ALIGN_8192BYTES 0x00E00000

#defina IMAGE_SCN_ALIGN_MASK 0x00F00000

#defina IMAGE_SCN_LNK_NRELOC_OVFL 0x01000000
#defina IMAGE_SCN_MEM_DISCARDABLE 0x02000000
#defina IMAGE_SCN_MEM_NOT_CACHED 0x04000000
#defina IMAGE_SCN_MEM_NOT_PAGED 0x08000000
#defina IMAGE_SCN_MEM_SHARED 0x10000000
#defina IMAGE_SCN_MEM_EXECUTE 0x20000000
#defina IMAGE_SCN_MEM_READ 0x40000000
#defina IMAGE_SCN_MEM_WRITE 0x80000000

#defina IMAGE_SCN_SCALE_INDEX 0x00000001

#inclua "pshpack2.h"

    defina_tipo estrutura _IMAGE_SYMBOL {
      união {
	BYTE ShortName[8];
	estrutura {
	  DWORD Short;
	  DWORD Long;
	} Name;
	DWORD LongName[2];
      } N;
      DWORD Value;
      SHORT SectionNumber;
      WORD Type;
      BYTE StorageClass;
      BYTE NumberOfAuxSymbols;
    } IMAGE_SYMBOL;
    defina_tipo IMAGE_SYMBOL UNALIGNED *PIMAGE_SYMBOL;

#defina IMAGE_SIZEOF_SYMBOL 18

#defina IMAGE_SYM_UNDEFINED (SHORT)0
#defina IMAGE_SYM_ABSOLUTE (SHORT)-1
#defina IMAGE_SYM_DEBUG (SHORT)-2
#defina IMAGE_SYM_SECTION_MAX 0xFEFF

#defina IMAGE_SYM_TYPE_NULL 0x0000
#defina IMAGE_SYM_TYPE_VOID 0x0001
#defina IMAGE_SYM_TYPE_CHAR 0x0002
#defina IMAGE_SYM_TYPE_SHORT 0x0003
#defina IMAGE_SYM_TYPE_INT 0x0004
#defina IMAGE_SYM_TYPE_LONG 0x0005
#defina IMAGE_SYM_TYPE_FLOAT 0x0006
#defina IMAGE_SYM_TYPE_DOUBLE 0x0007
#defina IMAGE_SYM_TYPE_STRUCT 0x0008
#defina IMAGE_SYM_TYPE_UNION 0x0009
#defina IMAGE_SYM_TYPE_ENUM 0x000A
#defina IMAGE_SYM_TYPE_MOE 0x000B
#defina IMAGE_SYM_TYPE_BYTE 0x000C
#defina IMAGE_SYM_TYPE_WORD 0x000D
#defina IMAGE_SYM_TYPE_UINT 0x000E
#defina IMAGE_SYM_TYPE_DWORD 0x000F
#defina IMAGE_SYM_TYPE_PCODE 0x8000

#defina IMAGE_SYM_DTYPE_NULL 0
#defina IMAGE_SYM_DTYPE_POINTER 1
#defina IMAGE_SYM_DTYPE_FUNCTION 2
#defina IMAGE_SYM_DTYPE_ARRAY 3

#defina IMAGE_SYM_CLASS_END_OF_FUNCTION (BYTE)-1
#defina IMAGE_SYM_CLASS_NULL 0x0000
#defina IMAGE_SYM_CLASS_AUTOMATIC 0x0001
#defina IMAGE_SYM_CLASS_EXTERNAL 0x0002
#defina IMAGE_SYM_CLASS_STATIC 0x0003
#defina IMAGE_SYM_CLASS_REGISTER 0x0004
#defina IMAGE_SYM_CLASS_EXTERNAL_DEF 0x0005
#defina IMAGE_SYM_CLASS_LABEL 0x0006
#defina IMAGE_SYM_CLASS_UNDEFINED_LABEL 0x0007
#defina IMAGE_SYM_CLASS_MEMBER_OF_STRUCT 0x0008
#defina IMAGE_SYM_CLASS_ARGUMENT 0x0009
#defina IMAGE_SYM_CLASS_STRUCT_TAG 0x000A
#defina IMAGE_SYM_CLASS_MEMBER_OF_UNION 0x000B
#defina IMAGE_SYM_CLASS_UNION_TAG 0x000C
#defina IMAGE_SYM_CLASS_TYPE_DEFINITION 0x000D
#defina IMAGE_SYM_CLASS_UNDEFINED_STATIC 0x000E
#defina IMAGE_SYM_CLASS_ENUM_TAG 0x000F
#defina IMAGE_SYM_CLASS_MEMBER_OF_ENUM 0x0010
#defina IMAGE_SYM_CLASS_REGISTER_PARAM 0x0011
#defina IMAGE_SYM_CLASS_BIT_FIELD 0x0012
#defina IMAGE_SYM_CLASS_FAR_EXTERNAL 0x0044
#defina IMAGE_SYM_CLASS_BLOCK 0x0064
#defina IMAGE_SYM_CLASS_FUNCTION 0x0065
#defina IMAGE_SYM_CLASS_END_OF_STRUCT 0x0066
#defina IMAGE_SYM_CLASS_FILE 0x0067
#defina IMAGE_SYM_CLASS_SECTION 0x0068
#defina IMAGE_SYM_CLASS_WEAK_EXTERNAL 0x0069
#defina IMAGE_SYM_CLASS_CLR_TOKEN 0x006B

#defina N_BTMASK 0x000F
#defina N_TMASK 0x0030
#defina N_TMASK1 0x00C0
#defina N_TMASK2 0x00F0
#defina N_BTSHFT 4
#defina N_TSHIFT 2

#defina BTYPE(x) ((x) & N_BTMASK)

#se_não_definido ISPTR
#defina ISPTR(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_POINTER << N_BTSHFT))
#fim_se

#se_não_definido ISFCN
#defina ISFCN(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
#fim_se

#se_não_definido ISARY
#defina ISARY(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
#fim_se

#se_não_definido ISTAG
#defina ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_TAG || (x)==IMAGE_SYM_CLASS_UNION_TAG || (x)==IMAGE_SYM_CLASS_ENUM_TAG)
#fim_se

#se_não_definido INCREF
#defina INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(IMAGE_SYM_DTYPE_POINTER<<N_BTSHFT)|((x)&N_BTMASK))
#fim_se
#se_não_definido DECREF
#defina DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
#fim_se

    defina_tipo união _IMAGE_AUX_SYMBOL {
      estrutura {
	DWORD TagIndex;
	união {
	  estrutura {
	    WORD Linenumber;
	    WORD Size;
	  } LnSz;
	  DWORD TotalSize;
	} Misc;
	união {
	  estrutura {
	    DWORD PointerToLinenumber;
	    DWORD PointerToNextFunction;
	  } Function;
	  estrutura {
	    WORD Dimension[4];
	  } Array;
	} FcnAry;
	WORD TvIndex;
      } Sym;
      estrutura {
	BYTE Name[IMAGE_SIZEOF_SYMBOL];
      } File;
      estrutura {
	DWORD Length;
	WORD NumberOfRelocations;
	WORD NumberOfLinenumbers;
	DWORD CheckSum;
	SHORT Number;
	BYTE Selection;
      } Section;
    } IMAGE_AUX_SYMBOL;
    defina_tipo IMAGE_AUX_SYMBOL UNALIGNED *PIMAGE_AUX_SYMBOL;

#defina IMAGE_SIZEOF_AUX_SYMBOL 18

    defina_tipo enumeração IMAGE_AUX_SYMBOL_TYPE {
      IMAGE_AUX_SYMBOL_TYPE_TOKEN_DEF = 1
    } IMAGE_AUX_SYMBOL_TYPE;

#inclua <pshpack2.h>

    defina_tipo estrutura IMAGE_AUX_SYMBOL_TOKEN_DEF {
      BYTE bAuxType;
      BYTE bReserved;
      DWORD SymbolTableIndex;
      BYTE rgbReserved[12];
    } IMAGE_AUX_SYMBOL_TOKEN_DEF;

    defina_tipo IMAGE_AUX_SYMBOL_TOKEN_DEF UNALIGNED *PIMAGE_AUX_SYMBOL_TOKEN_DEF;

#inclua <poppack.h>

#defina IMAGE_COMDAT_SELECT_NODUPLICATES 1
#defina IMAGE_COMDAT_SELECT_ANY 2
#defina IMAGE_COMDAT_SELECT_SAME_SIZE 3
#defina IMAGE_COMDAT_SELECT_EXACT_MATCH 4
#defina IMAGE_COMDAT_SELECT_ASSOCIATIVE 5
#defina IMAGE_COMDAT_SELECT_LARGEST 6
#defina IMAGE_COMDAT_SELECT_NEWEST 7

#defina IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY 1
#defina IMAGE_WEAK_EXTERN_SEARCH_LIBRARY 2
#defina IMAGE_WEAK_EXTERN_SEARCH_ALIAS 3

    defina_tipo estrutura _IMAGE_RELOCATION {
      união {
	DWORD VirtualAddress;
	DWORD RelocCount;
      };
      DWORD SymbolTableIndex;
      WORD Type;
    } IMAGE_RELOCATION;
    defina_tipo IMAGE_RELOCATION UNALIGNED *PIMAGE_RELOCATION;

#defina IMAGE_SIZEOF_RELOCATION 10

#defina IMAGE_REL_I386_ABSOLUTE 0x0000
#defina IMAGE_REL_I386_DIR16 0x0001
#defina IMAGE_REL_I386_REL16 0x0002
#defina IMAGE_REL_I386_DIR32 0x0006
#defina IMAGE_REL_I386_DIR32NB 0x0007
#defina IMAGE_REL_I386_SEG12 0x0009
#defina IMAGE_REL_I386_SECTION 0x000A
#defina IMAGE_REL_I386_SECREL 0x000B
#defina IMAGE_REL_I386_TOKEN 0x000C
#defina IMAGE_REL_I386_SECREL7 0x000D
#defina IMAGE_REL_I386_REL32 0x0014

#defina IMAGE_REL_MIPS_ABSOLUTE 0x0000
#defina IMAGE_REL_MIPS_REFHALF 0x0001
#defina IMAGE_REL_MIPS_REFWORD 0x0002
#defina IMAGE_REL_MIPS_JMPADDR 0x0003
#defina IMAGE_REL_MIPS_REFHI 0x0004
#defina IMAGE_REL_MIPS_REFLO 0x0005
#defina IMAGE_REL_MIPS_GPREL 0x0006
#defina IMAGE_REL_MIPS_LITERAL 0x0007
#defina IMAGE_REL_MIPS_SECTION 0x000A
#defina IMAGE_REL_MIPS_SECREL 0x000B
#defina IMAGE_REL_MIPS_SECRELLO 0x000C
#defina IMAGE_REL_MIPS_SECRELHI 0x000D
#defina IMAGE_REL_MIPS_TOKEN 0x000E
#defina IMAGE_REL_MIPS_JMPADDR16 0x0010
#defina IMAGE_REL_MIPS_REFWORDNB 0x0022
#defina IMAGE_REL_MIPS_PAIR 0x0025

#defina IMAGE_REL_ALPHA_ABSOLUTE 0x0000
#defina IMAGE_REL_ALPHA_REFLONG 0x0001
#defina IMAGE_REL_ALPHA_REFQUAD 0x0002
#defina IMAGE_REL_ALPHA_GPREL32 0x0003
#defina IMAGE_REL_ALPHA_LITERAL 0x0004
#defina IMAGE_REL_ALPHA_LITUSE 0x0005
#defina IMAGE_REL_ALPHA_GPDISP 0x0006
#defina IMAGE_REL_ALPHA_BRADDR 0x0007
#defina IMAGE_REL_ALPHA_HINT 0x0008
#defina IMAGE_REL_ALPHA_INLINE_REFLONG 0x0009
#defina IMAGE_REL_ALPHA_REFHI 0x000A
#defina IMAGE_REL_ALPHA_REFLO 0x000B
#defina IMAGE_REL_ALPHA_PAIR 0x000C
#defina IMAGE_REL_ALPHA_MATCH 0x000D
#defina IMAGE_REL_ALPHA_SECTION 0x000E
#defina IMAGE_REL_ALPHA_SECREL 0x000F
#defina IMAGE_REL_ALPHA_REFLONGNB 0x0010
#defina IMAGE_REL_ALPHA_SECRELLO 0x0011
#defina IMAGE_REL_ALPHA_SECRELHI 0x0012
#defina IMAGE_REL_ALPHA_REFQ3 0x0013
#defina IMAGE_REL_ALPHA_REFQ2 0x0014
#defina IMAGE_REL_ALPHA_REFQ1 0x0015
#defina IMAGE_REL_ALPHA_GPRELLO 0x0016
#defina IMAGE_REL_ALPHA_GPRELHI 0x0017

#defina IMAGE_REL_PPC_ABSOLUTE 0x0000
#defina IMAGE_REL_PPC_ADDR64 0x0001
#defina IMAGE_REL_PPC_ADDR32 0x0002
#defina IMAGE_REL_PPC_ADDR24 0x0003
#defina IMAGE_REL_PPC_ADDR16 0x0004
#defina IMAGE_REL_PPC_ADDR14 0x0005
#defina IMAGE_REL_PPC_REL24 0x0006
#defina IMAGE_REL_PPC_REL14 0x0007
#defina IMAGE_REL_PPC_TOCREL16 0x0008
#defina IMAGE_REL_PPC_TOCREL14 0x0009
#defina IMAGE_REL_PPC_ADDR32NB 0x000A
#defina IMAGE_REL_PPC_SECREL 0x000B
#defina IMAGE_REL_PPC_SECTION 0x000C
#defina IMAGE_REL_PPC_IFGLUE 0x000D
#defina IMAGE_REL_PPC_IMGLUE 0x000E
#defina IMAGE_REL_PPC_SECREL16 0x000F
#defina IMAGE_REL_PPC_REFHI 0x0010
#defina IMAGE_REL_PPC_REFLO 0x0011
#defina IMAGE_REL_PPC_PAIR 0x0012
#defina IMAGE_REL_PPC_SECRELLO 0x0013
#defina IMAGE_REL_PPC_SECRELHI 0x0014
#defina IMAGE_REL_PPC_GPREL 0x0015
#defina IMAGE_REL_PPC_TOKEN 0x0016
#defina IMAGE_REL_PPC_TYPEMASK 0x00FF
#defina IMAGE_REL_PPC_NEG 0x0100
#defina IMAGE_REL_PPC_BRTAKEN 0x0200
#defina IMAGE_REL_PPC_BRNTAKEN 0x0400
#defina IMAGE_REL_PPC_TOCDEFN 0x0800

#defina IMAGE_REL_SH3_ABSOLUTE 0x0000
#defina IMAGE_REL_SH3_DIRECT16 0x0001
#defina IMAGE_REL_SH3_DIRECT32 0x0002
#defina IMAGE_REL_SH3_DIRECT8 0x0003
#defina IMAGE_REL_SH3_DIRECT8_WORD 0x0004
#defina IMAGE_REL_SH3_DIRECT8_LONG 0x0005
#defina IMAGE_REL_SH3_DIRECT4 0x0006
#defina IMAGE_REL_SH3_DIRECT4_WORD 0x0007
#defina IMAGE_REL_SH3_DIRECT4_LONG 0x0008
#defina IMAGE_REL_SH3_PCREL8_WORD 0x0009
#defina IMAGE_REL_SH3_PCREL8_LONG 0x000A
#defina IMAGE_REL_SH3_PCREL12_WORD 0x000B
#defina IMAGE_REL_SH3_STARTOF_SECTION 0x000C
#defina IMAGE_REL_SH3_SIZEOF_SECTION 0x000D
#defina IMAGE_REL_SH3_SECTION 0x000E
#defina IMAGE_REL_SH3_SECREL 0x000F
#defina IMAGE_REL_SH3_DIRECT32_NB 0x0010
#defina IMAGE_REL_SH3_GPREL4_LONG 0x0011
#defina IMAGE_REL_SH3_TOKEN 0x0012

#defina IMAGE_REL_SHM_PCRELPT 0x0013
#defina IMAGE_REL_SHM_REFLO 0x0014
#defina IMAGE_REL_SHM_REFHALF 0x0015
#defina IMAGE_REL_SHM_RELLO 0x0016
#defina IMAGE_REL_SHM_RELHALF 0x0017
#defina IMAGE_REL_SHM_PAIR 0x0018

#defina IMAGE_REL_SH_NOMODE 0x8000

#defina IMAGE_REL_ARM_ABSOLUTE 0x0000
#defina IMAGE_REL_ARM_ADDR32 0x0001
#defina IMAGE_REL_ARM_ADDR32NB 0x0002
#defina IMAGE_REL_ARM_BRANCH24 0x0003
#defina IMAGE_REL_ARM_BRANCH11 0x0004
#defina IMAGE_REL_ARM_TOKEN 0x0005
#defina IMAGE_REL_ARM_GPREL12 0x0006
#defina IMAGE_REL_ARM_GPREL7 0x0007
#defina IMAGE_REL_ARM_BLX24 0x0008
#defina IMAGE_REL_ARM_BLX11 0x0009
#defina IMAGE_REL_ARM_SECTION 0x000E
#defina IMAGE_REL_ARM_SECREL 0x000F

#defina IMAGE_REL_AM_ABSOLUTE 0x0000
#defina IMAGE_REL_AM_ADDR32 0x0001
#defina IMAGE_REL_AM_ADDR32NB 0x0002
#defina IMAGE_REL_AM_CALL32 0x0003
#defina IMAGE_REL_AM_FUNCINFO 0x0004
#defina IMAGE_REL_AM_REL32_1 0x0005
#defina IMAGE_REL_AM_REL32_2 0x0006
#defina IMAGE_REL_AM_SECREL 0x0007
#defina IMAGE_REL_AM_SECTION 0x0008
#defina IMAGE_REL_AM_TOKEN 0x0009

#defina IMAGE_REL_AMD64_ABSOLUTE 0x0000
#defina IMAGE_REL_AMD64_ADDR64 0x0001
#defina IMAGE_REL_AMD64_ADDR32 0x0002
#defina IMAGE_REL_AMD64_ADDR32NB 0x0003
#defina IMAGE_REL_AMD64_REL32 0x0004
#defina IMAGE_REL_AMD64_REL32_1 0x0005
#defina IMAGE_REL_AMD64_REL32_2 0x0006
#defina IMAGE_REL_AMD64_REL32_3 0x0007
#defina IMAGE_REL_AMD64_REL32_4 0x0008
#defina IMAGE_REL_AMD64_REL32_5 0x0009
#defina IMAGE_REL_AMD64_SECTION 0x000A
#defina IMAGE_REL_AMD64_SECREL 0x000B
#defina IMAGE_REL_AMD64_SECREL7 0x000C
#defina IMAGE_REL_AMD64_TOKEN 0x000D
#defina IMAGE_REL_AMD64_SREL32 0x000E
#defina IMAGE_REL_AMD64_PAIR 0x000F
#defina IMAGE_REL_AMD64_SSPAN32 0x0010

#defina IMAGE_REL_IA64_ABSOLUTE 0x0000
#defina IMAGE_REL_IA64_IMM14 0x0001
#defina IMAGE_REL_IA64_IMM22 0x0002
#defina IMAGE_REL_IA64_IMM64 0x0003
#defina IMAGE_REL_IA64_DIR32 0x0004
#defina IMAGE_REL_IA64_DIR64 0x0005
#defina IMAGE_REL_IA64_PCREL21B 0x0006
#defina IMAGE_REL_IA64_PCREL21M 0x0007
#defina IMAGE_REL_IA64_PCREL21F 0x0008
#defina IMAGE_REL_IA64_GPREL22 0x0009
#defina IMAGE_REL_IA64_LTOFF22 0x000A
#defina IMAGE_REL_IA64_SECTION 0x000B
#defina IMAGE_REL_IA64_SECREL22 0x000C
#defina IMAGE_REL_IA64_SECREL64I 0x000D
#defina IMAGE_REL_IA64_SECREL32 0x000E

#defina IMAGE_REL_IA64_DIR32NB 0x0010
#defina IMAGE_REL_IA64_SREL14 0x0011
#defina IMAGE_REL_IA64_SREL22 0x0012
#defina IMAGE_REL_IA64_SREL32 0x0013
#defina IMAGE_REL_IA64_UREL32 0x0014
#defina IMAGE_REL_IA64_PCREL60X 0x0015
#defina IMAGE_REL_IA64_PCREL60B 0x0016
#defina IMAGE_REL_IA64_PCREL60F 0x0017
#defina IMAGE_REL_IA64_PCREL60I 0x0018
#defina IMAGE_REL_IA64_PCREL60M 0x0019
#defina IMAGE_REL_IA64_IMMGPREL64 0x001A
#defina IMAGE_REL_IA64_TOKEN 0x001B
#defina IMAGE_REL_IA64_GPREL32 0x001C
#defina IMAGE_REL_IA64_ADDEND 0x001F

#defina IMAGE_REL_CEF_ABSOLUTE 0x0000
#defina IMAGE_REL_CEF_ADDR32 0x0001
#defina IMAGE_REL_CEF_ADDR64 0x0002
#defina IMAGE_REL_CEF_ADDR32NB 0x0003
#defina IMAGE_REL_CEF_SECTION 0x0004
#defina IMAGE_REL_CEF_SECREL 0x0005
#defina IMAGE_REL_CEF_TOKEN 0x0006

#defina IMAGE_REL_CEE_ABSOLUTE 0x0000
#defina IMAGE_REL_CEE_ADDR32 0x0001
#defina IMAGE_REL_CEE_ADDR64 0x0002
#defina IMAGE_REL_CEE_ADDR32NB 0x0003
#defina IMAGE_REL_CEE_SECTION 0x0004
#defina IMAGE_REL_CEE_SECREL 0x0005
#defina IMAGE_REL_CEE_TOKEN 0x0006

#defina IMAGE_REL_M32R_ABSOLUTE 0x0000
#defina IMAGE_REL_M32R_ADDR32 0x0001
#defina IMAGE_REL_M32R_ADDR32NB 0x0002
#defina IMAGE_REL_M32R_ADDR24 0x0003
#defina IMAGE_REL_M32R_GPREL16 0x0004
#defina IMAGE_REL_M32R_PCREL24 0x0005
#defina IMAGE_REL_M32R_PCREL16 0x0006
#defina IMAGE_REL_M32R_PCREL8 0x0007
#defina IMAGE_REL_M32R_REFHALF 0x0008
#defina IMAGE_REL_M32R_REFHI 0x0009
#defina IMAGE_REL_M32R_REFLO 0x000A
#defina IMAGE_REL_M32R_PAIR 0x000B
#defina IMAGE_REL_M32R_SECTION 0x000C
#defina IMAGE_REL_M32R_SECREL32 0x000D
#defina IMAGE_REL_M32R_TOKEN 0x000E

#defina EXT_IMM64(Value,Address,Size,InstPos,ValPos) Value |= (((ULONGLONG)((*(Address) >> InstPos) & (((ULONGLONG)1 << Size) - 1))) << ValPos)
#defina INS_IMM64(Value,Address,Size,InstPos,ValPos) *(PDWORD)Address = (*(PDWORD)Address & ~(((1 << Size) - 1) << InstPos)) | ((DWORD)((((ULONGLONG)Value >> ValPos) & (((ULONGLONG)1 << Size) - 1))) << InstPos)

#defina EMARCH_ENC_I17_IMM7B_INST_WORD_X 3
#defina EMARCH_ENC_I17_IMM7B_SIZE_X 7
#defina EMARCH_ENC_I17_IMM7B_INST_WORD_POS_X 4
#defina EMARCH_ENC_I17_IMM7B_VAL_POS_X 0

#defina EMARCH_ENC_I17_IMM9D_INST_WORD_X 3
#defina EMARCH_ENC_I17_IMM9D_SIZE_X 9
#defina EMARCH_ENC_I17_IMM9D_INST_WORD_POS_X 18
#defina EMARCH_ENC_I17_IMM9D_VAL_POS_X 7

#defina EMARCH_ENC_I17_IMM5C_INST_WORD_X 3
#defina EMARCH_ENC_I17_IMM5C_SIZE_X 5
#defina EMARCH_ENC_I17_IMM5C_INST_WORD_POS_X 13
#defina EMARCH_ENC_I17_IMM5C_VAL_POS_X 16

#defina EMARCH_ENC_I17_IC_INST_WORD_X 3
#defina EMARCH_ENC_I17_IC_SIZE_X 1
#defina EMARCH_ENC_I17_IC_INST_WORD_POS_X 12
#defina EMARCH_ENC_I17_IC_VAL_POS_X 21

#defina EMARCH_ENC_I17_IMM41a_INST_WORD_X 1
#defina EMARCH_ENC_I17_IMM41a_SIZE_X 10
#defina EMARCH_ENC_I17_IMM41a_INST_WORD_POS_X 14
#defina EMARCH_ENC_I17_IMM41a_VAL_POS_X 22

#defina EMARCH_ENC_I17_IMM41b_INST_WORD_X 1
#defina EMARCH_ENC_I17_IMM41b_SIZE_X 8
#defina EMARCH_ENC_I17_IMM41b_INST_WORD_POS_X 24
#defina EMARCH_ENC_I17_IMM41b_VAL_POS_X 32

#defina EMARCH_ENC_I17_IMM41c_INST_WORD_X 2
#defina EMARCH_ENC_I17_IMM41c_SIZE_X 23
#defina EMARCH_ENC_I17_IMM41c_INST_WORD_POS_X 0
#defina EMARCH_ENC_I17_IMM41c_VAL_POS_X 40

#defina EMARCH_ENC_I17_SIGN_INST_WORD_X 3
#defina EMARCH_ENC_I17_SIGN_SIZE_X 1
#defina EMARCH_ENC_I17_SIGN_INST_WORD_POS_X 27
#defina EMARCH_ENC_I17_SIGN_VAL_POS_X 63

#defina X3_OPCODE_INST_WORD_X 3
#defina X3_OPCODE_SIZE_X 4
#defina X3_OPCODE_INST_WORD_POS_X 28
#defina X3_OPCODE_SIGN_VAL_POS_X 0

#defina X3_I_INST_WORD_X 3
#defina X3_I_SIZE_X 1
#defina X3_I_INST_WORD_POS_X 27
#defina X3_I_SIGN_VAL_POS_X 59

#defina X3_D_WH_INST_WORD_X 3
#defina X3_D_WH_SIZE_X 3
#defina X3_D_WH_INST_WORD_POS_X 24
#defina X3_D_WH_SIGN_VAL_POS_X 0

#defina X3_IMM20_INST_WORD_X 3
#defina X3_IMM20_SIZE_X 20
#defina X3_IMM20_INST_WORD_POS_X 4
#defina X3_IMM20_SIGN_VAL_POS_X 0

#defina X3_IMM39_1_INST_WORD_X 2
#defina X3_IMM39_1_SIZE_X 23
#defina X3_IMM39_1_INST_WORD_POS_X 0
#defina X3_IMM39_1_SIGN_VAL_POS_X 36

#defina X3_IMM39_2_INST_WORD_X 1
#defina X3_IMM39_2_SIZE_X 16
#defina X3_IMM39_2_INST_WORD_POS_X 16
#defina X3_IMM39_2_SIGN_VAL_POS_X 20

#defina X3_P_INST_WORD_X 3
#defina X3_P_SIZE_X 4
#defina X3_P_INST_WORD_POS_X 0
#defina X3_P_SIGN_VAL_POS_X 0

#defina X3_TMPLT_INST_WORD_X 0
#defina X3_TMPLT_SIZE_X 4
#defina X3_TMPLT_INST_WORD_POS_X 0
#defina X3_TMPLT_SIGN_VAL_POS_X 0

#defina X3_BTYPE_QP_INST_WORD_X 2
#defina X3_BTYPE_QP_SIZE_X 9
#defina X3_BTYPE_QP_INST_WORD_POS_X 23
#defina X3_BTYPE_QP_INST_VAL_POS_X 0

#defina X3_EMPTY_INST_WORD_X 1
#defina X3_EMPTY_SIZE_X 2
#defina X3_EMPTY_INST_WORD_POS_X 14
#defina X3_EMPTY_INST_VAL_POS_X 0

    defina_tipo estrutura _IMAGE_LINENUMBER {
      união {
	DWORD SymbolTableIndex;
	DWORD VirtualAddress;
      } Type;
      WORD Linenumber;
    } IMAGE_LINENUMBER;
    defina_tipo IMAGE_LINENUMBER UNALIGNED *PIMAGE_LINENUMBER;

#defina IMAGE_SIZEOF_LINENUMBER 6

#inclua "poppack.h"

    defina_tipo estrutura _IMAGE_BASE_RELOCATION {
      DWORD VirtualAddress;
      DWORD SizeOfBlock;

    } IMAGE_BASE_RELOCATION;
    defina_tipo IMAGE_BASE_RELOCATION UNALIGNED *PIMAGE_BASE_RELOCATION;

#defina IMAGE_SIZEOF_BASE_RELOCATION 8

#defina IMAGE_REL_BASED_ABSOLUTE 0
#defina IMAGE_REL_BASED_HIGH 1
#defina IMAGE_REL_BASED_LOW 2
#defina IMAGE_REL_BASED_HIGHLOW 3
#defina IMAGE_REL_BASED_HIGHADJ 4
#defina IMAGE_REL_BASED_MIPS_JMPADDR 5
#defina IMAGE_REL_BASED_MIPS_JMPADDR16 9
#defina IMAGE_REL_BASED_IA64_IMM64 9
#defina IMAGE_REL_BASED_DIR64 10

#defina IMAGE_ARCHIVE_START_SIZE 8
#defina IMAGE_ARCHIVE_START "!<arch>\n"
#defina IMAGE_ARCHIVE_END "`\n"
#defina IMAGE_ARCHIVE_PAD "\n"
#defina IMAGE_ARCHIVE_LINKER_MEMBER "/               "
#defina IMAGE_ARCHIVE_LONGNAMES_MEMBER "//              "

    defina_tipo estrutura _IMAGE_ARCHIVE_MEMBER_HEADER {
      BYTE Name[16];
      BYTE Date[12];
      BYTE UserID[6];
      BYTE GroupID[6];
      BYTE Mode[8];
      BYTE Size[10];
      BYTE EndHeader[2];
    } IMAGE_ARCHIVE_MEMBER_HEADER,*PIMAGE_ARCHIVE_MEMBER_HEADER;

#defina IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR 60

    defina_tipo estrutura _IMAGE_EXPORT_DIRECTORY {
      DWORD Characteristics;
      DWORD TimeDateStamp;
      WORD MajorVersion;
      WORD MinorVersion;
      DWORD Name;
      DWORD Base;
      DWORD NumberOfFunctions;
      DWORD NumberOfNames;
      DWORD AddressOfFunctions;
      DWORD AddressOfNames;
      DWORD AddressOfNameOrdinals;
    } IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

    defina_tipo estrutura _IMAGE_IMPORT_BY_NAME {
      WORD Hint;
      BYTE Name[1];
    } IMAGE_IMPORT_BY_NAME,*PIMAGE_IMPORT_BY_NAME;

#inclua "pshpack8.h"

    defina_tipo estrutura _IMAGE_THUNK_DATA64 {
      união {
	ULONGLONG ForwarderString;
	ULONGLONG Function;
	ULONGLONG Ordinal;
	ULONGLONG AddressOfData;
      } u1;
    } IMAGE_THUNK_DATA64;
    defina_tipo IMAGE_THUNK_DATA64 *PIMAGE_THUNK_DATA64;

#inclua "poppack.h"

    defina_tipo estrutura _IMAGE_THUNK_DATA32 {
      união {
	DWORD ForwarderString;
	DWORD Function;
	DWORD Ordinal;
	DWORD AddressOfData;
      } u1;
    } IMAGE_THUNK_DATA32;
    defina_tipo IMAGE_THUNK_DATA32 *PIMAGE_THUNK_DATA32;

#defina IMAGE_ORDINAL_FLAG64 0x8000000000000000ull
#defina IMAGE_ORDINAL_FLAG32 0x80000000
#defina IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffffull)
#defina IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)
#defina IMAGE_SNAP_BY_ORDINAL64(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG64)!=0)
#defina IMAGE_SNAP_BY_ORDINAL32(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG32)!=0)

    defina_tipo VOID
      (NTAPI *PIMAGE_TLS_CALLBACK)(PVOID DllHandle,DWORD Reason,PVOID Reserved);

    defina_tipo estrutura _IMAGE_TLS_DIRECTORY64 {
      ULONGLONG StartAddressOfRawData;
      ULONGLONG EndAddressOfRawData;
      ULONGLONG AddressOfIndex;
      ULONGLONG AddressOfCallBacks;
      DWORD SizeOfZeroFill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY64;
    defina_tipo IMAGE_TLS_DIRECTORY64 *PIMAGE_TLS_DIRECTORY64;

    defina_tipo estrutura _IMAGE_TLS_DIRECTORY32 {
      DWORD StartAddressOfRawData;
      DWORD EndAddressOfRawData;
      DWORD AddressOfIndex;
      DWORD AddressOfCallBacks;
      DWORD SizeOfZeroFill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY32;
    defina_tipo IMAGE_TLS_DIRECTORY32 *PIMAGE_TLS_DIRECTORY32;

#se_definido _WIN64
#defina IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG64
#defina IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL64(Ordinal)
    defina_tipo IMAGE_THUNK_DATA64 IMAGE_THUNK_DATA;
    defina_tipo PIMAGE_THUNK_DATA64 PIMAGE_THUNK_DATA;
#defina IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL64(Ordinal)
    defina_tipo IMAGE_TLS_DIRECTORY64 IMAGE_TLS_DIRECTORY;
    defina_tipo PIMAGE_TLS_DIRECTORY64 PIMAGE_TLS_DIRECTORY;
#senão
#defina IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG32
#defina IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL32(Ordinal)
    defina_tipo IMAGE_THUNK_DATA32 IMAGE_THUNK_DATA;
    defina_tipo PIMAGE_THUNK_DATA32 PIMAGE_THUNK_DATA;
#defina IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL32(Ordinal)
    defina_tipo IMAGE_TLS_DIRECTORY32 IMAGE_TLS_DIRECTORY;
    defina_tipo PIMAGE_TLS_DIRECTORY32 PIMAGE_TLS_DIRECTORY;
#fim_se

    defina_tipo estrutura _IMAGE_IMPORT_DESCRIPTOR {
      união {
	DWORD Characteristics;
	DWORD OriginalFirstThunk;
      };
      DWORD TimeDateStamp;

      DWORD ForwarderChain;
      DWORD Name;
      DWORD FirstThunk;
    } IMAGE_IMPORT_DESCRIPTOR;
    defina_tipo IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

    defina_tipo estrutura _IMAGE_BOUND_IMPORT_DESCRIPTOR {
      DWORD TimeDateStamp;
      WORD OffsetModuleName;
      WORD NumberOfModuleForwarderRefs;
    } IMAGE_BOUND_IMPORT_DESCRIPTOR,*PIMAGE_BOUND_IMPORT_DESCRIPTOR;

    defina_tipo estrutura _IMAGE_BOUND_FORWARDER_REF {
      DWORD TimeDateStamp;
      WORD OffsetModuleName;
      WORD Reserved;
    } IMAGE_BOUND_FORWARDER_REF,*PIMAGE_BOUND_FORWARDER_REF;

    defina_tipo estrutura _IMAGE_RESOURCE_DIRECTORY {
      DWORD Characteristics;
      DWORD TimeDateStamp;
      WORD MajorVersion;
      WORD MinorVersion;
      WORD NumberOfNamedEntries;
      WORD NumberOfIdEntries;
    } IMAGE_RESOURCE_DIRECTORY,*PIMAGE_RESOURCE_DIRECTORY;

#defina IMAGE_RESOURCE_NAME_IS_STRING 0x80000000
#defina IMAGE_RESOURCE_DATA_IS_DIRECTORY 0x80000000

    defina_tipo estrutura _IMAGE_RESOURCE_DIRECTORY_ENTRY {
      união {
	estrutura {
	  DWORD NameOffset:31;
	  DWORD NameIsString:1;
	};
	DWORD Name;
	WORD Id;
      };
      união {
	DWORD OffsetToData;
	estrutura {
	  DWORD OffsetToDirectory:31;
	  DWORD DataIsDirectory:1;
	};
      };
    } IMAGE_RESOURCE_DIRECTORY_ENTRY,*PIMAGE_RESOURCE_DIRECTORY_ENTRY;

    defina_tipo estrutura _IMAGE_RESOURCE_DIRECTORY_STRING {
      WORD Length;
      CHAR NameString[1];
    } IMAGE_RESOURCE_DIRECTORY_STRING,*PIMAGE_RESOURCE_DIRECTORY_STRING;

    defina_tipo estrutura _IMAGE_RESOURCE_DIR_STRING_U {
      WORD Length;
      WCHAR NameString[1];
    } IMAGE_RESOURCE_DIR_STRING_U,*PIMAGE_RESOURCE_DIR_STRING_U;

    defina_tipo estrutura _IMAGE_RESOURCE_DATA_ENTRY {
      DWORD OffsetToData;
      DWORD Size;
      DWORD CodePage;
      DWORD Reserved;
    } IMAGE_RESOURCE_DATA_ENTRY,*PIMAGE_RESOURCE_DATA_ENTRY;

    defina_tipo estrutura {
      DWORD Size;
      DWORD TimeDateStamp;
      WORD MajorVersion;
      WORD MinorVersion;
      DWORD GlobalFlagsClear;
      DWORD GlobalFlagsSet;
      DWORD CriticalSectionDefaultTimeout;
      DWORD DeCommitFreeBlockThreshold;
      DWORD DeCommitTotalFreeThreshold;
      DWORD LockPrefixTable;
      DWORD MaximumAllocationSize;
      DWORD VirtualMemoryThreshold;
      DWORD ProcessHeapFlags;
      DWORD ProcessAffinityMask;
      WORD CSDVersion;
      WORD Reserved1;
      DWORD EditList;
      DWORD SecurityCookie;
      DWORD SEHandlerTable;
      DWORD SEHandlerCount;
    } IMAGE_LOAD_CONFIG_DIRECTORY32,*PIMAGE_LOAD_CONFIG_DIRECTORY32;

    defina_tipo estrutura {
      DWORD Size;
      DWORD TimeDateStamp;
      WORD MajorVersion;
      WORD MinorVersion;
      DWORD GlobalFlagsClear;
      DWORD GlobalFlagsSet;
      DWORD CriticalSectionDefaultTimeout;
      ULONGLONG DeCommitFreeBlockThreshold;
      ULONGLONG DeCommitTotalFreeThreshold;
      ULONGLONG LockPrefixTable;
      ULONGLONG MaximumAllocationSize;
      ULONGLONG VirtualMemoryThreshold;
      ULONGLONG ProcessAffinityMask;
      DWORD ProcessHeapFlags;
      WORD CSDVersion;
      WORD Reserved1;
      ULONGLONG EditList;
      ULONGLONG SecurityCookie;
      ULONGLONG SEHandlerTable;
      ULONGLONG SEHandlerCount;
    } IMAGE_LOAD_CONFIG_DIRECTORY64,*PIMAGE_LOAD_CONFIG_DIRECTORY64;

#se_definido _WIN64
    defina_tipo IMAGE_LOAD_CONFIG_DIRECTORY64 IMAGE_LOAD_CONFIG_DIRECTORY;
    defina_tipo PIMAGE_LOAD_CONFIG_DIRECTORY64 PIMAGE_LOAD_CONFIG_DIRECTORY;
#senão
    defina_tipo IMAGE_LOAD_CONFIG_DIRECTORY32 IMAGE_LOAD_CONFIG_DIRECTORY;
    defina_tipo PIMAGE_LOAD_CONFIG_DIRECTORY32 PIMAGE_LOAD_CONFIG_DIRECTORY;
#fim_se

    defina_tipo estrutura _IMAGE_CE_RUNTIME_FUNCTION_ENTRY {
      DWORD FuncStart;
      DWORD PrologLen : 8;
      DWORD FuncLen : 22;
      DWORD ThirtyTwoBit : 1;
      DWORD ExceptionFlag : 1;
    } IMAGE_CE_RUNTIME_FUNCTION_ENTRY,*PIMAGE_CE_RUNTIME_FUNCTION_ENTRY;

    defina_tipo estrutura _IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY {
      ULONGLONG BeginAddress;
      ULONGLONG EndAddress;
      ULONGLONG ExceptionHandler;
      ULONGLONG HandlerData;
      ULONGLONG PrologEndAddress;
    } IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY,*PIMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY;

    defina_tipo estrutura _IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD ExceptionHandler;
      DWORD HandlerData;
      DWORD PrologEndAddress;
    } IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY,*PIMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY;

    defina_tipo estrutura _IMAGE_RUNTIME_FUNCTION_ENTRY {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD UnwindInfoAddress;
    } _IMAGE_RUNTIME_FUNCTION_ENTRY,*_PIMAGE_RUNTIME_FUNCTION_ENTRY;

    defina_tipo _IMAGE_RUNTIME_FUNCTION_ENTRY IMAGE_IA64_RUNTIME_FUNCTION_ENTRY;
    defina_tipo _PIMAGE_RUNTIME_FUNCTION_ENTRY PIMAGE_IA64_RUNTIME_FUNCTION_ENTRY;

    defina_tipo _IMAGE_RUNTIME_FUNCTION_ENTRY IMAGE_RUNTIME_FUNCTION_ENTRY;
    defina_tipo _PIMAGE_RUNTIME_FUNCTION_ENTRY PIMAGE_RUNTIME_FUNCTION_ENTRY;

    defina_tipo estrutura _IMAGE_DEBUG_DIRECTORY {
      DWORD Characteristics;
      DWORD TimeDateStamp;
      WORD MajorVersion;
      WORD MinorVersion;
      DWORD Type;
      DWORD SizeOfData;
      DWORD AddressOfRawData;
      DWORD PointerToRawData;
    } IMAGE_DEBUG_DIRECTORY,*PIMAGE_DEBUG_DIRECTORY;

#defina IMAGE_DEBUG_TYPE_UNKNOWN 0
#defina IMAGE_DEBUG_TYPE_COFF 1
#defina IMAGE_DEBUG_TYPE_CODEVIEW 2
#defina IMAGE_DEBUG_TYPE_FPO 3
#defina IMAGE_DEBUG_TYPE_MISC 4
#defina IMAGE_DEBUG_TYPE_EXCEPTION 5
#defina IMAGE_DEBUG_TYPE_FIXUP 6
#defina IMAGE_DEBUG_TYPE_OMAP_TO_SRC 7
#defina IMAGE_DEBUG_TYPE_OMAP_FROM_SRC 8
#defina IMAGE_DEBUG_TYPE_BORLAND 9
#defina IMAGE_DEBUG_TYPE_RESERVED10 10
#defina IMAGE_DEBUG_TYPE_CLSID 11

    defina_tipo estrutura _IMAGE_COFF_SYMBOLS_HEADER {
      DWORD NumberOfSymbols;
      DWORD LvaToFirstSymbol;
      DWORD NumberOfLinenumbers;
      DWORD LvaToFirstLinenumber;
      DWORD RvaToFirstByteOfCode;
      DWORD RvaToLastByteOfCode;
      DWORD RvaToFirstByteOfData;
      DWORD RvaToLastByteOfData;
    } IMAGE_COFF_SYMBOLS_HEADER,*PIMAGE_COFF_SYMBOLS_HEADER;

#defina FRAME_FPO 0
#defina FRAME_TRAP 1
#defina FRAME_TSS 2
#defina FRAME_NONFPO 3

    defina_tipo estrutura _FPO_DATA {
      DWORD ulOffStart;
      DWORD cbProcSize;
      DWORD cdwLocals;
      WORD cdwParams;
      WORD cbProlog : 8;
      WORD cbRegs : 3;
      WORD fHasSEH : 1;
      WORD fUseBP : 1;
      WORD reserved : 1;
      WORD cbFrame : 2;
    } FPO_DATA,*PFPO_DATA;
#defina SIZEOF_RFPO_DATA 16

#defina IMAGE_DEBUG_MISC_EXENAME 1

    defina_tipo estrutura _IMAGE_DEBUG_MISC {
      DWORD DataType;
      DWORD Length;
      BOOLEAN Unicode;
      BYTE Reserved[3];
      BYTE Data[1];
    } IMAGE_DEBUG_MISC,*PIMAGE_DEBUG_MISC;

    defina_tipo estrutura _IMAGE_FUNCTION_ENTRY {
      DWORD StartingAddress;
      DWORD EndingAddress;
      DWORD EndOfPrologue;
    } IMAGE_FUNCTION_ENTRY,*PIMAGE_FUNCTION_ENTRY;

    defina_tipo estrutura _IMAGE_FUNCTION_ENTRY64 {
      ULONGLONG StartingAddress;
      ULONGLONG EndingAddress;
      união {
	ULONGLONG EndOfPrologue;
	ULONGLONG UnwindInfoAddress;
      };
    } IMAGE_FUNCTION_ENTRY64,*PIMAGE_FUNCTION_ENTRY64;

    defina_tipo estrutura _IMAGE_SEPARATE_DEBUG_HEADER {
      WORD Signature;
      WORD Flags;
      WORD Machine;
      WORD Characteristics;
      DWORD TimeDateStamp;
      DWORD CheckSum;
      DWORD ImageBase;
      DWORD SizeOfImage;
      DWORD NumberOfSections;
      DWORD ExportedNamesSize;
      DWORD DebugDirectorySize;
      DWORD SectionAlignment;
      DWORD Reserved[2];
    } IMAGE_SEPARATE_DEBUG_HEADER,*PIMAGE_SEPARATE_DEBUG_HEADER;

    defina_tipo estrutura _NON_PAGED_DEBUG_INFO {
      WORD Signature;
      WORD Flags;
      DWORD Size;
      WORD Machine;
      WORD Characteristics;
      DWORD TimeDateStamp;
      DWORD CheckSum;
      DWORD SizeOfImage;
      ULONGLONG ImageBase;

    } NON_PAGED_DEBUG_INFO,*PNON_PAGED_DEBUG_INFO;

#defina IMAGE_SEPARATE_DEBUG_SIGNATURE 0x4944
#defina NON_PAGED_DEBUG_SIGNATURE 0x494E

#defina IMAGE_SEPARATE_DEBUG_FLAGS_MASK 0x8000
#defina IMAGE_SEPARATE_DEBUG_MISMATCH 0x8000

    defina_tipo estrutura _ImageArchitectureHeader {
      sem_sinal inteiro AmaskValue: 1;
      inteiro Adummy1 :7;
      sem_sinal inteiro AmaskShift: 8;
      inteiro Adummy2 :16;
      DWORD FirstEntryRVA;
    } IMAGE_ARCHITECTURE_HEADER,*PIMAGE_ARCHITECTURE_HEADER;

    defina_tipo estrutura _ImageArchitectureEntry {
      DWORD FixupInstRVA;
      DWORD NewInst;
    } IMAGE_ARCHITECTURE_ENTRY,*PIMAGE_ARCHITECTURE_ENTRY;

#inclua "poppack.h"

#defina IMPORT_OBJECT_HDR_SIG2 0xffff

    defina_tipo estrutura IMPORT_OBJECT_HEADER {
      WORD Sig1;
      WORD Sig2;
      WORD Version;
      WORD Machine;
      DWORD TimeDateStamp;
      DWORD SizeOfData;
      união {
	WORD Ordinal;
	WORD Hint;
      };
      WORD Type : 2;
      WORD NameType : 3;
      WORD Reserved : 11;
    } IMPORT_OBJECT_HEADER;

    defina_tipo enumeração IMPORT_OBJECT_TYPE {
      IMPORT_OBJECT_CODE = 0,IMPORT_OBJECT_DATA = 1,IMPORT_OBJECT_CONST = 2
    } IMPORT_OBJECT_TYPE;

    defina_tipo enumeração IMPORT_OBJECT_NAME_TYPE {
      IMPORT_OBJECT_ORDINAL = 0,IMPORT_OBJECT_NAME = 1,IMPORT_OBJECT_NAME_NO_PREFIX = 2,IMPORT_OBJECT_NAME_UNDECORATE = 3
    } IMPORT_OBJECT_NAME_TYPE;

#se_não_definido __IMAGE_COR20_HEADER_DEFINED__
#defina __IMAGE_COR20_HEADER_DEFINED__
    defina_tipo enumeração ReplacesCorHdrNumericDefines {
      COMIMAGE_FLAGS_ILONLY =0x00000001,COMIMAGE_FLAGS_32BITREQUIRED =0x00000002,COMIMAGE_FLAGS_IL_LIBRARY =0x00000004,
      COMIMAGE_FLAGS_STRONGNAMESIGNED =0x00000008,COMIMAGE_FLAGS_TRACKDEBUGDATA =0x00010000,COR_VERSION_MAJOR_V2 =2,
      COR_VERSION_MAJOR =COR_VERSION_MAJOR_V2,COR_VERSION_MINOR =0,COR_DELETED_NAME_LENGTH =8,COR_VTABLEGAP_NAME_LENGTH =8,
      NATIVE_TYPE_MAX_CB =1,COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,IMAGE_COR_MIH_METHODRVA =0x01,IMAGE_COR_MIH_EHRVA =0x02,
      IMAGE_COR_MIH_BASICBLOCK =0x08,COR_VTABLE_32BIT =0x01,COR_VTABLE_64BIT =0x02,COR_VTABLE_FROM_UNMANAGED =0x04,
      COR_VTABLE_CALL_MOST_DERIVED =0x10,IMAGE_COR_EATJ_THUNK_SIZE =32,MAX_CLASS_NAME =1024,MAX_PACKAGE_NAME =1024
    } ReplacesCorHdrNumericDefines;

    defina_tipo estrutura IMAGE_COR20_HEADER {
      DWORD cb;
      WORD MajorRuntimeVersion;
      WORD MinorRuntimeVersion;
      IMAGE_DATA_DIRECTORY MetaData;
      DWORD Flags;
      DWORD EntryPointToken;
      IMAGE_DATA_DIRECTORY Resources;
      IMAGE_DATA_DIRECTORY StrongNameSignature;
      IMAGE_DATA_DIRECTORY CodeManagerTable;
      IMAGE_DATA_DIRECTORY VTableFixups;
      IMAGE_DATA_DIRECTORY ExportAddressTableJumps;
      IMAGE_DATA_DIRECTORY ManagedNativeHeader;
    } IMAGE_COR20_HEADER,*PIMAGE_COR20_HEADER;
#fim_se

#se definido (__x86_64)
    NTSYSAPI PRUNTIME_FUNCTION NTAPI RtlLookupFunctionEntry (DWORD64 ControlPc, PDWORD64 ImageBase, PUNWIND_HISTORY_TABLE HistoryTable);
    NTSYSAPI VOID NTAPI RtlUnwindEx (PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue, PCONTEXT ContextRecord, PUNWIND_HISTORY_TABLE HistoryTable);
#fim_se

#inclua <string.h>

#se_não_definido _SLIST_HEADER_
#defina _SLIST_HEADER_

#se_definido _WIN64
    defina_tipo estrutura _SLIST_ENTRY *PSLIST_ENTRY;
    defina_tipo DECLSPEC_ALIGN(16) estrutura _SLIST_ENTRY {
      PSLIST_ENTRY Next;
    } SLIST_ENTRY;
#senão

#defina SLIST_ENTRY SINGLE_LIST_ENTRY
#defina _SLIST_ENTRY _SINGLE_LIST_ENTRY
#defina PSLIST_ENTRY PSINGLE_LIST_ENTRY
#fim_se

#se definido(_WIN64)

    defina_tipo DECLSPEC_ALIGN(16) estrutura _SLIST_HEADER {
      ULONGLONG Alignment;
      ULONGLONG Region;
    } SLIST_HEADER;

    defina_tipo estrutura _SLIST_HEADER *PSLIST_HEADER;
#senão

    defina_tipo união _SLIST_HEADER {
      ULONGLONG Alignment;
      estrutura {
	SLIST_ENTRY Next;
	WORD Depth;
	WORD Sequence;
      };
    } SLIST_HEADER,*PSLIST_HEADER;
#fim_se
#fim_se

    NTSYSAPI VOID NTAPI RtlInitializeSListHead(PSLIST_HEADER ListHead);
    NTSYSAPI PSLIST_ENTRY NTAPI RtlFirstEntrySList(constante SLIST_HEADER *ListHead);
    NTSYSAPI PSLIST_ENTRY NTAPI RtlInterlockedPopEntrySList(PSLIST_HEADER ListHead);
    NTSYSAPI PSLIST_ENTRY NTAPI RtlInterlockedPushEntrySList(PSLIST_HEADER ListHead,PSLIST_ENTRY ListEntry);
    NTSYSAPI PSLIST_ENTRY NTAPI RtlInterlockedFlushSList(PSLIST_HEADER ListHead);
    NTSYSAPI WORD NTAPI RtlQueryDepthSList(PSLIST_HEADER ListHead);

#defina HEAP_NO_SERIALIZE 0x00000001
#defina HEAP_GROWABLE 0x00000002
#defina HEAP_GENERATE_EXCEPTIONS 0x00000004
#defina HEAP_ZERO_MEMORY 0x00000008
#defina HEAP_REALLOC_IN_PLACE_ONLY 0x00000010
#defina HEAP_TAIL_CHECKING_ENABLED 0x00000020
#defina HEAP_FREE_CHECKING_ENABLED 0x00000040
#defina HEAP_DISABLE_COALESCE_ON_FREE 0x00000080
#defina HEAP_CREATE_ALIGN_16 0x00010000
#defina HEAP_CREATE_ENABLE_TRACING 0x00020000
#defina HEAP_CREATE_ENABLE_EXECUTE 0x00040000
#defina HEAP_MAXIMUM_TAG 0x0FFF
#defina HEAP_PSEUDO_TAG_FLAG 0x8000
#defina HEAP_TAG_SHIFT 18
#defina HEAP_MAKE_TAG_FLAGS(b,o) ((DWORD)((b) + ((o) << 18)))

    NTSYSAPI VOID NTAPI RtlCaptureContext(PCONTEXT ContextRecord);

#defina IS_TEXT_UNICODE_ASCII16 0x0001
#defina IS_TEXT_UNICODE_REVERSE_ASCII16 0x0010

#defina IS_TEXT_UNICODE_STATISTICS 0x0002
#defina IS_TEXT_UNICODE_REVERSE_STATISTICS 0x0020

#defina IS_TEXT_UNICODE_CONTROLS 0x0004
#defina IS_TEXT_UNICODE_REVERSE_CONTROLS 0x0040

#defina IS_TEXT_UNICODE_SIGNATURE 0x0008
#defina IS_TEXT_UNICODE_REVERSE_SIGNATURE 0x0080

#defina IS_TEXT_UNICODE_ILLEGAL_CHARS 0x0100
#defina IS_TEXT_UNICODE_ODD_LENGTH 0x0200
#defina IS_TEXT_UNICODE_DBCS_LEADBYTE 0x0400
#defina IS_TEXT_UNICODE_NULL_BYTES 0x1000

#defina IS_TEXT_UNICODE_UNICODE_MASK 0x000F
#defina IS_TEXT_UNICODE_REVERSE_MASK 0x00F0
#defina IS_TEXT_UNICODE_NOT_UNICODE_MASK 0x0F00
#defina IS_TEXT_UNICODE_NOT_ASCII_MASK 0xF000

#defina COMPRESSION_FORMAT_NONE (0x0000)
#defina COMPRESSION_FORMAT_DEFAULT (0x0001)
#defina COMPRESSION_FORMAT_LZNT1 (0x0002)
#defina COMPRESSION_ENGINE_STANDARD (0x0000)
#defina COMPRESSION_ENGINE_MAXIMUM (0x0100)
#defina COMPRESSION_ENGINE_HIBER (0x0200)

#se _DBG_MEMCPY_INLINE_ && !definido(_MEMCPY_INLINE_) && !definido(_CRTBLD)
#defina _MEMCPY_INLINE_
    __CRT_INLINE PVOID __cdecl memcpy_inline(vazio *dst,constante vazio *src,size_t size) {
      se(((caractere *)dst > (caractere *)src) && ((caractere *)dst < ((caractere *)src + size))) {
	__debugbreak();
      }
      retorne memcpy(dst,src,size);
    }
#defina memcpy memcpy_inline
#fim_se

    NTSYSAPI SIZE_T NTAPI RtlCompareMemory(constante VOID *Source1,constante VOID *Source2,SIZE_T Length);

#defina RtlEqualMemory(Destination,Source,Length) (!memcmp((Destination),(Source),(Length)))
#defina RtlMoveMemory(Destination,Source,Length) memmove((Destination),(Source),(Length))
#defina RtlCopyMemory(Destination,Source,Length) memcpy((Destination),(Source),(Length))
#defina RtlFillMemory(Destination,Length,Fill) memset((Destination),(Fill),(Length))
#defina RtlZeroMemory(Destination,Length) memset((Destination),0,(Length))

    __CRT_INLINE PVOID RtlSecureZeroMemory(PVOID ptr,SIZE_T cnt) {
      volátil caractere *vptr =(volátil caractere *)ptr;
#se_definido __x86_64
      __stosb((PBYTE)((DWORD64)vptr),0,cnt);
#senão
      enquanto(cnt) {
	*vptr = 0;
	vptr++;
	cnt--;
      }
#fim_se
      retorne ptr;
    }

    defina_tipo estrutura _MESSAGE_RESOURCE_ENTRY {
      WORD Length;
      WORD Flags;
      BYTE Text[1];
    } MESSAGE_RESOURCE_ENTRY,*PMESSAGE_RESOURCE_ENTRY;

#defina MESSAGE_RESOURCE_UNICODE 0x0001

    defina_tipo estrutura _MESSAGE_RESOURCE_BLOCK {
      DWORD LowId;
      DWORD HighId;
      DWORD OffsetToEntries;
    } MESSAGE_RESOURCE_BLOCK,*PMESSAGE_RESOURCE_BLOCK;

    defina_tipo estrutura _MESSAGE_RESOURCE_DATA {
      DWORD NumberOfBlocks;
      MESSAGE_RESOURCE_BLOCK Blocks[1];
    } MESSAGE_RESOURCE_DATA,*PMESSAGE_RESOURCE_DATA;

    defina_tipo estrutura _OSVERSIONINFOA {
      DWORD dwOSVersionInfoSize;
      DWORD dwMajorVersion;
      DWORD dwMinorVersion;
      DWORD dwBuildNumber;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
    } OSVERSIONINFOA,*POSVERSIONINFOA,*LPOSVERSIONINFOA;

    defina_tipo estrutura _OSVERSIONINFOW {
      DWORD dwOSVersionInfoSize;
      DWORD dwMajorVersion;
      DWORD dwMinorVersion;
      DWORD dwBuildNumber;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
    } OSVERSIONINFOW,*POSVERSIONINFOW,*LPOSVERSIONINFOW,RTL_OSVERSIONINFOW,*PRTL_OSVERSIONINFOW;

#se_definido UNICODE
    defina_tipo OSVERSIONINFOW OSVERSIONINFO;
    defina_tipo POSVERSIONINFOW POSVERSIONINFO;
    defina_tipo LPOSVERSIONINFOW LPOSVERSIONINFO;
#senão
    defina_tipo OSVERSIONINFOA OSVERSIONINFO;
    defina_tipo POSVERSIONINFOA POSVERSIONINFO;
    defina_tipo LPOSVERSIONINFOA LPOSVERSIONINFO;
#fim_se

    defina_tipo estrutura _OSVERSIONINFOEXA {
      DWORD dwOSVersionInfoSize;
      DWORD dwMajorVersion;
      DWORD dwMinorVersion;
      DWORD dwBuildNumber;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
      WORD wServicePackMajor;
      WORD wServicePackMinor;
      WORD wSuiteMask;
      BYTE wProductType;
      BYTE wReserved;
    } OSVERSIONINFOEXA,*POSVERSIONINFOEXA,*LPOSVERSIONINFOEXA;

    defina_tipo estrutura _OSVERSIONINFOEXW {
      DWORD dwOSVersionInfoSize;
      DWORD dwMajorVersion;
      DWORD dwMinorVersion;
      DWORD dwBuildNumber;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
      WORD wServicePackMajor;
      WORD wServicePackMinor;
      WORD wSuiteMask;
      BYTE wProductType;
      BYTE wReserved;
    } OSVERSIONINFOEXW,*POSVERSIONINFOEXW,*LPOSVERSIONINFOEXW,RTL_OSVERSIONINFOEXW,*PRTL_OSVERSIONINFOEXW;
#se_definido UNICODE
    defina_tipo OSVERSIONINFOEXW OSVERSIONINFOEX;
    defina_tipo POSVERSIONINFOEXW POSVERSIONINFOEX;
    defina_tipo LPOSVERSIONINFOEXW LPOSVERSIONINFOEX;
#senão
    defina_tipo OSVERSIONINFOEXA OSVERSIONINFOEX;
    defina_tipo POSVERSIONINFOEXA POSVERSIONINFOEX;
    defina_tipo LPOSVERSIONINFOEXA LPOSVERSIONINFOEX;
#fim_se

#defina VER_EQUAL 1
#defina VER_GREATER 2
#defina VER_GREATER_EQUAL 3
#defina VER_LESS 4
#defina VER_LESS_EQUAL 5
#defina VER_AND 6
#defina VER_OR 7

#defina VER_CONDITION_MASK 7
#defina VER_NUM_BITS_PER_CONDITION_MASK 3

#defina VER_MINORVERSION 0x0000001
#defina VER_MAJORVERSION 0x0000002
#defina VER_BUILDNUMBER 0x0000004
#defina VER_PLATFORMID 0x0000008
#defina VER_SERVICEPACKMINOR 0x0000010
#defina VER_SERVICEPACKMAJOR 0x0000020
#defina VER_SUITENAME 0x0000040
#defina VER_PRODUCT_TYPE 0x0000080

#defina VER_NT_WORKSTATION 0x0000001
#defina VER_NT_DOMAIN_CONTROLLER 0x0000002
#defina VER_NT_SERVER 0x0000003

#defina VER_PLATFORM_WIN32s 0
#defina VER_PLATFORM_WIN32_WINDOWS 1
#defina VER_PLATFORM_WIN32_NT 2

#defina VER_SET_CONDITION(_m_,_t_,_c_) ((_m_)=VerSetConditionMask((_m_),(_t_),(_c_)))

    NTSYSAPI ULONGLONG NTAPI VerSetConditionMask(ULONGLONG ConditionMask,DWORD TypeMask,BYTE Condition);

    defina_tipo estrutura _RTL_CRITICAL_SECTION_DEBUG {
      WORD Type;
      WORD CreatorBackTraceIndex;
      estrutura _RTL_CRITICAL_SECTION *CriticalSection;
      LIST_ENTRY ProcessLocksList;
      DWORD EntryCount;
      DWORD ContentionCount;
      DWORD Spare[2];
    } RTL_CRITICAL_SECTION_DEBUG,*PRTL_CRITICAL_SECTION_DEBUG,RTL_RESOURCE_DEBUG,*PRTL_RESOURCE_DEBUG;

#defina RTL_CRITSECT_TYPE 0
#defina RTL_RESOURCE_TYPE 1

    defina_tipo estrutura _RTL_CRITICAL_SECTION {
      PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
      LONG LockCount;
      LONG RecursionCount;
      HANDLE OwningThread;
      HANDLE LockSemaphore;
      ULONG_PTR SpinCount;
    } RTL_CRITICAL_SECTION,*PRTL_CRITICAL_SECTION;

    defina_tipo VOID (NTAPI *RTL_VERIFIER_DLL_LOAD_CALLBACK) (PWSTR DllName,PVOID DllBase,SIZE_T DllSize,PVOID Reserved);
    defina_tipo VOID (NTAPI *RTL_VERIFIER_DLL_UNLOAD_CALLBACK) (PWSTR DllName,PVOID DllBase,SIZE_T DllSize,PVOID Reserved);
    defina_tipo VOID (NTAPI *RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK)(PVOID AllocationBase,SIZE_T AllocationSize);

    defina_tipo estrutura _RTL_VERIFIER_THUNK_DESCRIPTOR {
      PCHAR ThunkName;
      PVOID ThunkOldAddress;
      PVOID ThunkNewAddress;
    } RTL_VERIFIER_THUNK_DESCRIPTOR,*PRTL_VERIFIER_THUNK_DESCRIPTOR;

    defina_tipo estrutura _RTL_VERIFIER_DLL_DESCRIPTOR {
      PWCHAR DllName;
      DWORD DllFlags;
      PVOID DllAddress;
      PRTL_VERIFIER_THUNK_DESCRIPTOR DllThunks;
    } RTL_VERIFIER_DLL_DESCRIPTOR,*PRTL_VERIFIER_DLL_DESCRIPTOR;

    defina_tipo estrutura _RTL_VERIFIER_PROVIDER_DESCRIPTOR {
      DWORD Length;
      PRTL_VERIFIER_DLL_DESCRIPTOR ProviderDlls;
      RTL_VERIFIER_DLL_LOAD_CALLBACK ProviderDllLoadCallback;
      RTL_VERIFIER_DLL_UNLOAD_CALLBACK ProviderDllUnloadCallback;
      PWSTR VerifierImage;
      DWORD VerifierFlags;
      DWORD VerifierDebug;
      PVOID RtlpGetStackTraceAddress;
      PVOID RtlpDebugPageHeapCreate;
      PVOID RtlpDebugPageHeapDestroy;
      RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK ProviderNtdllHeapFreeCallback;
    } RTL_VERIFIER_PROVIDER_DESCRIPTOR,*PRTL_VERIFIER_PROVIDER_DESCRIPTOR;

#defina RTL_VRF_FLG_FULL_PAGE_HEAP 0x00000001
#defina RTL_VRF_FLG_RESERVED_DONOTUSE 0x00000002
#defina RTL_VRF_FLG_HANDLE_CHECKS 0x00000004
#defina RTL_VRF_FLG_STACK_CHECKS 0x00000008
#defina RTL_VRF_FLG_APPCOMPAT_CHECKS 0x00000010
#defina RTL_VRF_FLG_TLS_CHECKS 0x00000020
#defina RTL_VRF_FLG_DIRTY_STACKS 0x00000040
#defina RTL_VRF_FLG_RPC_CHECKS 0x00000080
#defina RTL_VRF_FLG_COM_CHECKS 0x00000100
#defina RTL_VRF_FLG_DANGEROUS_APIS 0x00000200
#defina RTL_VRF_FLG_RACE_CHECKS 0x00000400
#defina RTL_VRF_FLG_DEADLOCK_CHECKS 0x00000800
#defina RTL_VRF_FLG_FIRST_CHANCE_EXCEPTION_CHECKS 0x00001000
#defina RTL_VRF_FLG_VIRTUAL_MEM_CHECKS 0x00002000
#defina RTL_VRF_FLG_ENABLE_LOGGING 0x00004000
#defina RTL_VRF_FLG_FAST_FILL_HEAP 0x00008000
#defina RTL_VRF_FLG_VIRTUAL_SPACE_TRACKING 0x00010000
#defina RTL_VRF_FLG_ENABLED_SYSTEM_WIDE 0x00020000
#defina RTL_VRF_FLG_MISCELLANEOUS_CHECKS 0x00020000
#defina RTL_VRF_FLG_LOCK_CHECKS 0x00040000

#defina APPLICATION_VERIFIER_INTERNAL_ERROR 0x80000000
#defina APPLICATION_VERIFIER_INTERNAL_WARNING 0x40000000
#defina APPLICATION_VERIFIER_NO_BREAK 0x20000000
#defina APPLICATION_VERIFIER_CONTINUABLE_BREAK 0x10000000

#defina APPLICATION_VERIFIER_UNKNOWN_ERROR 0x0001
#defina APPLICATION_VERIFIER_ACCESS_VIOLATION 0x0002
#defina APPLICATION_VERIFIER_UNSYNCHRONIZED_ACCESS 0x0003
#defina APPLICATION_VERIFIER_EXTREME_SIZE_REQUEST 0x0004
#defina APPLICATION_VERIFIER_BAD_HEAP_HANDLE 0x0005
#defina APPLICATION_VERIFIER_SWITCHED_HEAP_HANDLE 0x0006
#defina APPLICATION_VERIFIER_DOUBLE_FREE 0x0007
#defina APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK 0x0008
#defina APPLICATION_VERIFIER_DESTROY_PROCESS_HEAP 0x0009
#defina APPLICATION_VERIFIER_UNEXPECTED_EXCEPTION 0x000A
#defina APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_EXCEPTION_RAISED_FOR_HEADER 0x000B
#defina APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_EXCEPTION_RAISED_FOR_PROBING 0x000C
#defina APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_HEADER 0x000D
#defina APPLICATION_VERIFIER_CORRUPTED_FREED_HEAP_BLOCK 0x000E
#defina APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_SUFFIX 0x000F
#defina APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_START_STAMP 0x0010
#defina APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_END_STAMP 0x0011
#defina APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_PREFIX 0x0012
#defina APPLICATION_VERIFIER_FIRST_CHANCE_ACCESS_VIOLATION 0x0013
#defina APPLICATION_VERIFIER_CORRUPTED_HEAP_LIST 0x0014

#defina APPLICATION_VERIFIER_TERMINATE_THREAD_CALL 0x0100
#defina APPLICATION_VERIFIER_STACK_OVERFLOW 0x0101
#defina APPLICATION_VERIFIER_INVALID_EXIT_PROCESS_CALL 0x0102

#defina APPLICATION_VERIFIER_EXIT_THREAD_OWNS_LOCK 0x0200
#defina APPLICATION_VERIFIER_LOCK_IN_UNLOADED_DLL 0x0201
#defina APPLICATION_VERIFIER_LOCK_IN_FREED_HEAP 0x0202
#defina APPLICATION_VERIFIER_LOCK_DOUBLE_INITIALIZE 0x0203
#defina APPLICATION_VERIFIER_LOCK_IN_FREED_MEMORY 0x0204
#defina APPLICATION_VERIFIER_LOCK_CORRUPTED 0x0205
#defina APPLICATION_VERIFIER_LOCK_INVALID_OWNER 0x0206
#defina APPLICATION_VERIFIER_LOCK_INVALID_RECURSION_COUNT 0x0207
#defina APPLICATION_VERIFIER_LOCK_INVALID_LOCK_COUNT 0x0208
#defina APPLICATION_VERIFIER_LOCK_OVER_RELEASED 0x0209
#defina APPLICATION_VERIFIER_LOCK_NOT_INITIALIZED 0x0210
#defina APPLICATION_VERIFIER_LOCK_ALREADY_INITIALIZED 0x0211
#defina APPLICATION_VERIFIER_LOCK_IN_FREED_VMEM 0x0212
#defina APPLICATION_VERIFIER_LOCK_IN_UNMAPPED_MEM 0x0213
#defina APPLICATION_VERIFIER_THREAD_NOT_LOCK_OWNER 0x0214

#defina APPLICATION_VERIFIER_INVALID_HANDLE 0x0300
#defina APPLICATION_VERIFIER_INVALID_TLS_VALUE 0x0301
#defina APPLICATION_VERIFIER_INCORRECT_WAIT_CALL 0x0302
#defina APPLICATION_VERIFIER_NULL_HANDLE 0x0303
#defina APPLICATION_VERIFIER_WAIT_IN_DLLMAIN 0x0304

#defina APPLICATION_VERIFIER_COM_ERROR 0x0400
#defina APPLICATION_VERIFIER_COM_API_IN_DLLMAIN 0x0401
#defina APPLICATION_VERIFIER_COM_UNHANDLED_EXCEPTION 0x0402
#defina APPLICATION_VERIFIER_COM_UNBALANCED_COINIT 0x0403
#defina APPLICATION_VERIFIER_COM_UNBALANCED_OLEINIT 0x0404
#defina APPLICATION_VERIFIER_COM_UNBALANCED_SWC 0x0405
#defina APPLICATION_VERIFIER_COM_NULL_DACL 0x0406
#defina APPLICATION_VERIFIER_COM_UNSAFE_IMPERSONATION 0x0407
#defina APPLICATION_VERIFIER_COM_SMUGGLED_WRAPPER 0x0408
#defina APPLICATION_VERIFIER_COM_SMUGGLED_PROXY 0x0409
#defina APPLICATION_VERIFIER_COM_CF_SUCCESS_WITH_NULL 0x040A
#defina APPLICATION_VERIFIER_COM_GCO_SUCCESS_WITH_NULL 0x040B
#defina APPLICATION_VERIFIER_COM_OBJECT_IN_FREED_MEMORY 0x040C
#defina APPLICATION_VERIFIER_COM_OBJECT_IN_UNLOADED_DLL 0x040D
#defina APPLICATION_VERIFIER_COM_VTBL_IN_FREED_MEMORY 0x040E
#defina APPLICATION_VERIFIER_COM_VTBL_IN_UNLOADED_DLL 0x040F
#defina APPLICATION_VERIFIER_COM_HOLDING_LOCKS_ON_CALL 0x0410

#defina APPLICATION_VERIFIER_RPC_ERROR 0x0500

#defina APPLICATION_VERIFIER_INVALID_FREEMEM 0x0600
#defina APPLICATION_VERIFIER_INVALID_ALLOCMEM 0x0601
#defina APPLICATION_VERIFIER_INVALID_MAPVIEW 0x0602
#defina APPLICATION_VERIFIER_PROBE_INVALID_ADDRESS 0x0603
#defina APPLICATION_VERIFIER_PROBE_FREE_MEM 0x0604
#defina APPLICATION_VERIFIER_PROBE_GUARD_PAGE 0x0605
#defina APPLICATION_VERIFIER_PROBE_NULL 0x0606
#defina APPLICATION_VERIFIER_PROBE_INVALID_START_OR_SIZE 0x0607
#defina APPLICATION_VERIFIER_SIZE_HEAP_UNEXPECTED_EXCEPTION 0x0618

#defina VERIFIER_STOP(Code,Msg,P1,S1,P2,S2,P3,S3,P4,S4) { RtlApplicationVerifierStop ((Code),(Msg),(ULONG_PTR)(P1),(S1),(ULONG_PTR)(P2),(S2),(ULONG_PTR)(P3),(S3),(ULONG_PTR)(P4),(S4)); }

    VOID NTAPI RtlApplicationVerifierStop(ULONG_PTR Code,PSTR Message,ULONG_PTR Param1,PSTR Description1,ULONG_PTR Param2,PSTR Description2,ULONG_PTR Param3,PSTR Description3,ULONG_PTR Param4,PSTR Description4);

    defina_tipo LONG (NTAPI *PVECTORED_EXCEPTION_HANDLER)(estrutura _EXCEPTION_POINTERS *ExceptionInfo);
#defina SEF_DACL_AUTO_INHERIT 0x01
#defina SEF_SACL_AUTO_INHERIT 0x02
#defina SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT 0x04
#defina SEF_AVOID_PRIVILEGE_CHECK 0x08
#defina SEF_AVOID_OWNER_CHECK 0x10
#defina SEF_DEFAULT_OWNER_FROM_PARENT 0x20
#defina SEF_DEFAULT_GROUP_FROM_PARENT 0x40

    defina_tipo enumeração _HEAP_INFORMATION_CLASS {
      HeapCompatibilityInformation
    } HEAP_INFORMATION_CLASS;

    NTSYSAPI DWORD NTAPI RtlSetHeapInformation(PVOID HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,SIZE_T HeapInformationLength);
    NTSYSAPI DWORD NTAPI RtlQueryHeapInformation(PVOID HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,SIZE_T HeapInformationLength,PSIZE_T ReturnLength);
    DWORD NTAPI RtlMultipleAllocateHeap(PVOID HeapHandle,DWORD Flags,SIZE_T Size,DWORD Count,PVOID *Array);
    DWORD NTAPI RtlMultipleFreeHeap(PVOID HeapHandle,DWORD Flags,DWORD Count,PVOID *Array);

#defina WT_EXECUTEDEFAULT 0x00000000
#defina WT_EXECUTEINIOTHREAD 0x00000001
#defina WT_EXECUTEINUITHREAD 0x00000002
#defina WT_EXECUTEINWAITTHREAD 0x00000004
#defina WT_EXECUTEONLYONCE 0x00000008
#defina WT_EXECUTEINTIMERTHREAD 0x00000020
#defina WT_EXECUTELONGFUNCTION 0x00000010
#defina WT_EXECUTEINPERSISTENTIOTHREAD 0x00000040
#defina WT_EXECUTEINPERSISTENTTHREAD 0x00000080
#defina WT_TRANSFER_IMPERSONATION 0x00000100
#defina WT_SET_MAX_THREADPOOL_THREADS(Flags,Limit) ((Flags) |= (Limit)<<16)
    defina_tipo VOID (NTAPI *WAITORTIMERCALLBACKFUNC)(PVOID,BOOLEAN);
    defina_tipo VOID (NTAPI *WORKERCALLBACKFUNC)(PVOID);
    defina_tipo VOID (NTAPI *APC_CALLBACK_FUNCTION)(DWORD ,PVOID,PVOID);
    defina_tipo
      VOID
      (NTAPI *PFLS_CALLBACK_FUNCTION)(PVOID lpFlsData);
#defina WT_EXECUTEINLONGTHREAD 0x00000010
#defina WT_EXECUTEDELETEWAIT 0x00000008

    defina_tipo enumeração _ACTIVATION_CONTEXT_INFO_CLASS {
      ActivationContextBasicInformation = 1,ActivationContextDetailedInformation = 2,AssemblyDetailedInformationInActivationContext = 3,FileInformationInAssemblyOfAssemblyInActivationContext = 4,MaxActivationContextInfoClass,AssemblyDetailedInformationInActivationContxt = 3,FileInformationInAssemblyOfAssemblyInActivationContxt = 4
    } ACTIVATION_CONTEXT_INFO_CLASS;

#defina ACTIVATIONCONTEXTINFOCLASS ACTIVATION_CONTEXT_INFO_CLASS

    defina_tipo estrutura _ACTIVATION_CONTEXT_QUERY_INDEX {
      DWORD ulAssemblyIndex;
      DWORD ulFileIndexInAssembly;
    } ACTIVATION_CONTEXT_QUERY_INDEX,*PACTIVATION_CONTEXT_QUERY_INDEX;

    defina_tipo constante estrutura _ACTIVATION_CONTEXT_QUERY_INDEX *PCACTIVATION_CONTEXT_QUERY_INDEX;

#defina ACTIVATION_CONTEXT_PATH_TYPE_NONE (1)
#defina ACTIVATION_CONTEXT_PATH_TYPE_WIN32_FILE (2)
#defina ACTIVATION_CONTEXT_PATH_TYPE_URL (3)
#defina ACTIVATION_CONTEXT_PATH_TYPE_ASSEMBLYREF (4)

    defina_tipo estrutura _ASSEMBLY_FILE_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ulFilenameLength;
      DWORD ulPathLength;

      PCWSTR lpFileName;
      PCWSTR lpFilePath;
    } ASSEMBLY_FILE_DETAILED_INFORMATION,*PASSEMBLY_FILE_DETAILED_INFORMATION;
    defina_tipo constante ASSEMBLY_FILE_DETAILED_INFORMATION *PCASSEMBLY_FILE_DETAILED_INFORMATION;

#defina _ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION _ASSEMBLY_FILE_DETAILED_INFORMATION
#defina ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION ASSEMBLY_FILE_DETAILED_INFORMATION
#defina PASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PASSEMBLY_FILE_DETAILED_INFORMATION
#defina PCASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PCASSEMBLY_FILE_DETAILED_INFORMATION

    defina_tipo estrutura _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ulEncodedAssemblyIdentityLength;
      DWORD ulManifestPathType;
      DWORD ulManifestPathLength;
      LARGE_INTEGER liManifestLastWriteTime;
      DWORD ulPolicyPathType;
      DWORD ulPolicyPathLength;
      LARGE_INTEGER liPolicyLastWriteTime;
      DWORD ulMetadataSatelliteRosterIndex;
      DWORD ulManifestVersionMajor;
      DWORD ulManifestVersionMinor;
      DWORD ulPolicyVersionMajor;
      DWORD ulPolicyVersionMinor;
      DWORD ulAssemblyDirectoryNameLength;
      PCWSTR lpAssemblyEncodedAssemblyIdentity;
      PCWSTR lpAssemblyManifestPath;
      PCWSTR lpAssemblyPolicyPath;
      PCWSTR lpAssemblyDirectoryName;
      DWORD ulFileCount;
    } ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    defina_tipo constante estrutura _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    defina_tipo estrutura _ACTIVATION_CONTEXT_DETAILED_INFORMATION {
      DWORD dwFlags;
      DWORD ulFormatVersion;
      DWORD ulAssemblyCount;
      DWORD ulRootManifestPathType;
      DWORD ulRootManifestPathChars;
      DWORD ulRootConfigurationPathType;
      DWORD ulRootConfigurationPathChars;
      DWORD ulAppDirPathType;
      DWORD ulAppDirPathChars;
      PCWSTR lpRootManifestPath;
      PCWSTR lpRootConfigurationPath;
      PCWSTR lpAppDirPath;
    } ACTIVATION_CONTEXT_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_DETAILED_INFORMATION;

    defina_tipo constante estrutura _ACTIVATION_CONTEXT_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_DETAILED_INFORMATION;

#defina DLL_PROCESS_ATTACH 1
#defina DLL_THREAD_ATTACH 2
#defina DLL_THREAD_DETACH 3
#defina DLL_PROCESS_DETACH 0
#defina DLL_PROCESS_VERIFIER 4

#defina EVENTLOG_SEQUENTIAL_READ 0x0001
#defina EVENTLOG_SEEK_READ 0x0002
#defina EVENTLOG_FORWARDS_READ 0x0004
#defina EVENTLOG_BACKWARDS_READ 0x0008

#defina EVENTLOG_SUCCESS 0x0000
#defina EVENTLOG_ERROR_TYPE 0x0001
#defina EVENTLOG_WARNING_TYPE 0x0002
#defina EVENTLOG_INFORMATION_TYPE 0x0004
#defina EVENTLOG_AUDIT_SUCCESS 0x0008
#defina EVENTLOG_AUDIT_FAILURE 0x0010

#defina EVENTLOG_START_PAIRED_EVENT 0x0001
#defina EVENTLOG_END_PAIRED_EVENT 0x0002
#defina EVENTLOG_END_ALL_PAIRED_EVENTS 0x0004
#defina EVENTLOG_PAIRED_EVENT_ACTIVE 0x0008
#defina EVENTLOG_PAIRED_EVENT_INACTIVE 0x0010

    defina_tipo estrutura _EVENTLOGRECORD {
      DWORD Length;
      DWORD Reserved;
      DWORD RecordNumber;
      DWORD TimeGenerated;
      DWORD TimeWritten;
      DWORD EventID;
      WORD EventType;
      WORD NumStrings;
      WORD EventCategory;
      WORD ReservedFlags;
      DWORD ClosingRecordNumber;
      DWORD StringOffset;
      DWORD UserSidLength;
      DWORD UserSidOffset;
      DWORD DataLength;
      DWORD DataOffset;
    } EVENTLOGRECORD,*PEVENTLOGRECORD;

#defina MAXLOGICALLOGNAMESIZE 256

    defina_tipo estrutura _EVENTSFORLOGFILE{
      DWORD ulSize;
      WCHAR szLogicalLogFile[MAXLOGICALLOGNAMESIZE];
      DWORD ulNumRecords;
      EVENTLOGRECORD pEventLogRecords[];
    } EVENTSFORLOGFILE,*PEVENTSFORLOGFILE;

    defina_tipo estrutura _PACKEDEVENTINFO{
      DWORD ulSize;
      DWORD ulNumEventsForLogFile;
      DWORD ulOffsets[];
    } PACKEDEVENTINFO,*PPACKEDEVENTINFO;

#defina KEY_QUERY_VALUE (0x0001)
#defina KEY_SET_VALUE (0x0002)
#defina KEY_CREATE_SUB_KEY (0x0004)
#defina KEY_ENUMERATE_SUB_KEYS (0x0008)
#defina KEY_NOTIFY (0x0010)
#defina KEY_CREATE_LINK (0x0020)
#defina KEY_WOW64_32KEY (0x0200)
#defina KEY_WOW64_64KEY (0x0100)
#defina KEY_WOW64_RES (0x0300)

#defina KEY_READ ((STANDARD_RIGHTS_READ | KEY_QUERY_VALUE | KEY_ENUMERATE_SUB_KEYS | KEY_NOTIFY) & (~SYNCHRONIZE))
#defina KEY_WRITE ((STANDARD_RIGHTS_WRITE | KEY_SET_VALUE | KEY_CREATE_SUB_KEY) & (~SYNCHRONIZE))
#defina KEY_EXECUTE ((KEY_READ) & (~SYNCHRONIZE))
#defina KEY_ALL_ACCESS ((STANDARD_RIGHTS_ALL | KEY_QUERY_VALUE | KEY_SET_VALUE | KEY_CREATE_SUB_KEY | KEY_ENUMERATE_SUB_KEYS | KEY_NOTIFY | KEY_CREATE_LINK) & (~SYNCHRONIZE))
#defina REG_OPTION_RESERVED (0x00000000L)

#defina REG_OPTION_NON_VOLATILE (0x00000000L)
#defina REG_OPTION_VOLATILE (0x00000001L)
#defina REG_OPTION_CREATE_LINK (0x00000002L)
#defina REG_OPTION_BACKUP_RESTORE (0x00000004L)
#defina REG_OPTION_OPEN_LINK (0x00000008L)
#defina REG_LEGAL_OPTION (REG_OPTION_RESERVED | REG_OPTION_NON_VOLATILE | REG_OPTION_VOLATILE | REG_OPTION_CREATE_LINK | REG_OPTION_BACKUP_RESTORE | REG_OPTION_OPEN_LINK)
#defina REG_CREATED_NEW_KEY (0x00000001L)
#defina REG_OPENED_EXISTING_KEY (0x00000002L)
#defina REG_STANDARD_FORMAT 1
#defina REG_LATEST_FORMAT 2
#defina REG_NO_COMPRESSION 4
#defina REG_WHOLE_HIVE_VOLATILE (0x00000001L)
#defina REG_REFRESH_HIVE (0x00000002L)
#defina REG_NO_LAZY_FLUSH (0x00000004L)
#defina REG_FORCE_RESTORE (0x00000008L)
#defina REG_FORCE_UNLOAD 1

#defina REG_NOTIFY_CHANGE_NAME (0x00000001L)
#defina REG_NOTIFY_CHANGE_ATTRIBUTES (0x00000002L)
#defina REG_NOTIFY_CHANGE_LAST_SET (0x00000004L)
#defina REG_NOTIFY_CHANGE_SECURITY (0x00000008L)

#defina REG_LEGAL_CHANGE_FILTER (REG_NOTIFY_CHANGE_NAME | REG_NOTIFY_CHANGE_ATTRIBUTES | REG_NOTIFY_CHANGE_LAST_SET | REG_NOTIFY_CHANGE_SECURITY)

#defina REG_NONE (0)
#defina REG_SZ (1)
#defina REG_EXPAND_SZ (2)

#defina REG_BINARY (3)
#defina REG_DWORD (4)
#defina REG_DWORD_LITTLE_ENDIAN (4)
#defina REG_DWORD_BIG_ENDIAN (5)
#defina REG_LINK (6)
#defina REG_MULTI_SZ (7)
#defina REG_RESOURCE_LIST (8)
#defina REG_FULL_RESOURCE_DESCRIPTOR (9)
#defina REG_RESOURCE_REQUIREMENTS_LIST (10)
#defina REG_QWORD (11)
#defina REG_QWORD_LITTLE_ENDIAN (11)

#defina SERVICE_KERNEL_DRIVER 0x00000001
#defina SERVICE_FILE_SYSTEM_DRIVER 0x00000002
#defina SERVICE_ADAPTER 0x00000004
#defina SERVICE_RECOGNIZER_DRIVER 0x00000008

#defina SERVICE_DRIVER (SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER | SERVICE_RECOGNIZER_DRIVER)

#defina SERVICE_WIN32_OWN_PROCESS 0x00000010
#defina SERVICE_WIN32_SHARE_PROCESS 0x00000020
#defina SERVICE_WIN32 (SERVICE_WIN32_OWN_PROCESS | SERVICE_WIN32_SHARE_PROCESS)

#defina SERVICE_INTERACTIVE_PROCESS 0x00000100

#defina SERVICE_TYPE_ALL (SERVICE_WIN32 | SERVICE_ADAPTER | SERVICE_DRIVER | SERVICE_INTERACTIVE_PROCESS)

#defina SERVICE_BOOT_START 0x00000000
#defina SERVICE_SYSTEM_START 0x00000001
#defina SERVICE_AUTO_START 0x00000002
#defina SERVICE_DEMAND_START 0x00000003
#defina SERVICE_DISABLED 0x00000004

#defina SERVICE_ERROR_IGNORE 0x00000000
#defina SERVICE_ERROR_NORMAL 0x00000001
#defina SERVICE_ERROR_SEVERE 0x00000002
#defina SERVICE_ERROR_CRITICAL 0x00000003

    defina_tipo enumeração _CM_SERVICE_NODE_TYPE {
      DriverType = SERVICE_KERNEL_DRIVER,FileSystemType = SERVICE_FILE_SYSTEM_DRIVER,Win32ServiceOwnProcess = SERVICE_WIN32_OWN_PROCESS,
      Win32ServiceShareProcess = SERVICE_WIN32_SHARE_PROCESS,AdapterType = SERVICE_ADAPTER,RecognizerType = SERVICE_RECOGNIZER_DRIVER
    } SERVICE_NODE_TYPE;

    defina_tipo enumeração _CM_SERVICE_LOAD_TYPE {
      BootLoad = SERVICE_BOOT_START,SystemLoad = SERVICE_SYSTEM_START,AutoLoad = SERVICE_AUTO_START,DemandLoad = SERVICE_DEMAND_START,
      DisableLoad = SERVICE_DISABLED
    } SERVICE_LOAD_TYPE;

    defina_tipo enumeração _CM_ERROR_CONTROL_TYPE {
      IgnoreError = SERVICE_ERROR_IGNORE,NormalError = SERVICE_ERROR_NORMAL,SevereError = SERVICE_ERROR_SEVERE,CriticalError = SERVICE_ERROR_CRITICAL
    } SERVICE_ERROR_TYPE;

#defina TAPE_ERASE_SHORT 0L
#defina TAPE_ERASE_LONG 1L

    defina_tipo estrutura _TAPE_ERASE {
      DWORD Type;
      BOOLEAN Immediate;
    } TAPE_ERASE,*PTAPE_ERASE;

#defina TAPE_LOAD 0L
#defina TAPE_UNLOAD 1L
#defina TAPE_TENSION 2L
#defina TAPE_LOCK 3L
#defina TAPE_UNLOCK 4L
#defina TAPE_FORMAT 5L

    defina_tipo estrutura _TAPE_PREPARE {
      DWORD Operation;
      BOOLEAN Immediate;
    } TAPE_PREPARE,*PTAPE_PREPARE;

#defina TAPE_SETMARKS 0L
#defina TAPE_FILEMARKS 1L
#defina TAPE_SHORT_FILEMARKS 2L
#defina TAPE_LONG_FILEMARKS 3L

    defina_tipo estrutura _TAPE_WRITE_MARKS {
      DWORD Type;
      DWORD Count;
      BOOLEAN Immediate;
    } TAPE_WRITE_MARKS,*PTAPE_WRITE_MARKS;

#defina TAPE_ABSOLUTE_POSITION 0L
#defina TAPE_LOGICAL_POSITION 1L
#defina TAPE_PSEUDO_LOGICAL_POSITION 2L

    defina_tipo estrutura _TAPE_GET_POSITION {
      DWORD Type;
      DWORD Partition;
      LARGE_INTEGER Offset;
    } TAPE_GET_POSITION,*PTAPE_GET_POSITION;

#defina TAPE_REWIND 0L
#defina TAPE_ABSOLUTE_BLOCK 1L
#defina TAPE_LOGICAL_BLOCK 2L
#defina TAPE_PSEUDO_LOGICAL_BLOCK 3L
#defina TAPE_SPACE_END_OF_DATA 4L
#defina TAPE_SPACE_RELATIVE_BLOCKS 5L
#defina TAPE_SPACE_FILEMARKS 6L
#defina TAPE_SPACE_SEQUENTIAL_FMKS 7L
#defina TAPE_SPACE_SETMARKS 8L
#defina TAPE_SPACE_SEQUENTIAL_SMKS 9L

    defina_tipo estrutura _TAPE_SET_POSITION {
      DWORD Method;
      DWORD Partition;
      LARGE_INTEGER Offset;
      BOOLEAN Immediate;
    } TAPE_SET_POSITION,*PTAPE_SET_POSITION;

#defina TAPE_DRIVE_FIXED 0x00000001
#defina TAPE_DRIVE_SELECT 0x00000002
#defina TAPE_DRIVE_INITIATOR 0x00000004

#defina TAPE_DRIVE_ERASE_SHORT 0x00000010
#defina TAPE_DRIVE_ERASE_LONG 0x00000020
#defina TAPE_DRIVE_ERASE_BOP_ONLY 0x00000040
#defina TAPE_DRIVE_ERASE_IMMEDIATE 0x00000080

#defina TAPE_DRIVE_TAPE_CAPACITY 0x00000100
#defina TAPE_DRIVE_TAPE_REMAINING 0x00000200
#defina TAPE_DRIVE_FIXED_BLOCK 0x00000400
#defina TAPE_DRIVE_VARIABLE_BLOCK 0x00000800

#defina TAPE_DRIVE_WRITE_PROTECT 0x00001000
#defina TAPE_DRIVE_EOT_WZ_SIZE 0x00002000

#defina TAPE_DRIVE_ECC 0x00010000
#defina TAPE_DRIVE_COMPRESSION 0x00020000
#defina TAPE_DRIVE_PADDING 0x00040000
#defina TAPE_DRIVE_REPORT_SMKS 0x00080000

#defina TAPE_DRIVE_GET_ABSOLUTE_BLK 0x00100000
#defina TAPE_DRIVE_GET_LOGICAL_BLK 0x00200000
#defina TAPE_DRIVE_SET_EOT_WZ_SIZE 0x00400000

#defina TAPE_DRIVE_EJECT_MEDIA 0x01000000
#defina TAPE_DRIVE_CLEAN_REQUESTS 0x02000000
#defina TAPE_DRIVE_SET_CMP_BOP_ONLY 0x04000000

#defina TAPE_DRIVE_RESERVED_BIT 0x80000000

#defina TAPE_DRIVE_LOAD_UNLOAD 0x80000001
#defina TAPE_DRIVE_TENSION 0x80000002
#defina TAPE_DRIVE_LOCK_UNLOCK 0x80000004
#defina TAPE_DRIVE_REWIND_IMMEDIATE 0x80000008

#defina TAPE_DRIVE_SET_BLOCK_SIZE 0x80000010
#defina TAPE_DRIVE_LOAD_UNLD_IMMED 0x80000020
#defina TAPE_DRIVE_TENSION_IMMED 0x80000040
#defina TAPE_DRIVE_LOCK_UNLK_IMMED 0x80000080

#defina TAPE_DRIVE_SET_ECC 0x80000100
#defina TAPE_DRIVE_SET_COMPRESSION 0x80000200
#defina TAPE_DRIVE_SET_PADDING 0x80000400
#defina TAPE_DRIVE_SET_REPORT_SMKS 0x80000800

#defina TAPE_DRIVE_ABSOLUTE_BLK 0x80001000
#defina TAPE_DRIVE_ABS_BLK_IMMED 0x80002000
#defina TAPE_DRIVE_LOGICAL_BLK 0x80004000
#defina TAPE_DRIVE_LOG_BLK_IMMED 0x80008000

#defina TAPE_DRIVE_END_OF_DATA 0x80010000
#defina TAPE_DRIVE_RELATIVE_BLKS 0x80020000
#defina TAPE_DRIVE_FILEMARKS 0x80040000
#defina TAPE_DRIVE_SEQUENTIAL_FMKS 0x80080000

#defina TAPE_DRIVE_SETMARKS 0x80100000
#defina TAPE_DRIVE_SEQUENTIAL_SMKS 0x80200000
#defina TAPE_DRIVE_REVERSE_POSITION 0x80400000
#defina TAPE_DRIVE_SPACE_IMMEDIATE 0x80800000

#defina TAPE_DRIVE_WRITE_SETMARKS 0x81000000
#defina TAPE_DRIVE_WRITE_FILEMARKS 0x82000000
#defina TAPE_DRIVE_WRITE_SHORT_FMKS 0x84000000
#defina TAPE_DRIVE_WRITE_LONG_FMKS 0x88000000

#defina TAPE_DRIVE_WRITE_MARK_IMMED 0x90000000
#defina TAPE_DRIVE_FORMAT 0xA0000000
#defina TAPE_DRIVE_FORMAT_IMMEDIATE 0xC0000000
#defina TAPE_DRIVE_HIGH_FEATURES 0x80000000

    defina_tipo estrutura _TAPE_GET_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN DataPadding;
      BOOLEAN ReportSetmarks;
      DWORD DefaultBlockSize;
      DWORD MaximumBlockSize;
      DWORD MinimumBlockSize;
      DWORD MaximumPartitionCount;
      DWORD FeaturesLow;
      DWORD FeaturesHigh;
      DWORD EOTWarningZoneSize;
    } TAPE_GET_DRIVE_PARAMETERS,*PTAPE_GET_DRIVE_PARAMETERS;

    defina_tipo estrutura _TAPE_SET_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN DataPadding;
      BOOLEAN ReportSetmarks;
      DWORD EOTWarningZoneSize;
    } TAPE_SET_DRIVE_PARAMETERS,*PTAPE_SET_DRIVE_PARAMETERS;

    defina_tipo estrutura _TAPE_GET_MEDIA_PARAMETERS {
      LARGE_INTEGER Capacity;
      LARGE_INTEGER Remaining;
      DWORD BlockSize;
      DWORD PartitionCount;
      BOOLEAN WriteProtected;
    } TAPE_GET_MEDIA_PARAMETERS,*PTAPE_GET_MEDIA_PARAMETERS;

    defina_tipo estrutura _TAPE_SET_MEDIA_PARAMETERS {
      DWORD BlockSize;
    } TAPE_SET_MEDIA_PARAMETERS,*PTAPE_SET_MEDIA_PARAMETERS;

#defina TAPE_FIXED_PARTITIONS 0L
#defina TAPE_SELECT_PARTITIONS 1L
#defina TAPE_INITIATOR_PARTITIONS 2L

    defina_tipo estrutura _TAPE_CREATE_PARTITION {
      DWORD Method;
      DWORD Count;
      DWORD Size;
    } TAPE_CREATE_PARTITION,*PTAPE_CREATE_PARTITION;

#defina TAPE_QUERY_DRIVE_PARAMETERS 0L
#defina TAPE_QUERY_MEDIA_CAPACITY 1L
#defina TAPE_CHECK_FOR_DRIVE_PROBLEM 2L
#defina TAPE_QUERY_IO_ERROR_DATA 3L
#defina TAPE_QUERY_DEVICE_ERROR_DATA 4L

    defina_tipo estrutura _TAPE_WMI_OPERATIONS {
      DWORD Method;
      DWORD DataBufferSize;
      PVOID DataBuffer;
    } TAPE_WMI_OPERATIONS,*PTAPE_WMI_OPERATIONS;

    defina_tipo enumeração _TAPE_DRIVE_PROBLEM_TYPE {
      TapeDriveProblemNone,TapeDriveReadWriteWarning,TapeDriveReadWriteError,TapeDriveReadWarning,TapeDriveWriteWarning,TapeDriveReadError,TapeDriveWriteError,TapeDriveHardwareError,TapeDriveUnsupportedMedia,TapeDriveScsiConnectionError,TapeDriveTimetoClean,TapeDriveCleanDriveNow,TapeDriveMediaLifeExpired,TapeDriveSnappedTape
    } TAPE_DRIVE_PROBLEM_TYPE;

#se definido(__x86_64)
    __CRT_INLINE estrutura _TEB *NtCurrentTeb(VOID) { retorne (estrutura _TEB *)__readgsqword(FIELD_OFFSET(NT_TIB,Self)); }
    __CRT_INLINE PVOID GetCurrentFiber(VOID) { retorne(PVOID)__readgsqword(FIELD_OFFSET(NT_TIB,FiberData)); }
    __CRT_INLINE PVOID GetFiberData(VOID) {
      retorne *(PVOID *)GetCurrentFiber();
    }
#fim_se

#se(definido(_X86_) && !definido(__x86_64))
#defina PcTeb 0x18
    __CRT_INLINE estrutura _TEB *NtCurrentTeb(vazio) {
      estrutura _TEB *ret;
      __asm__ volátil ("movl	%%fs:0x18,%0"
	: "=r" (ret));
      retorne ret;
    }
#fim_se

#defina ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION (1)
#defina ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION (2)
#defina ACTIVATION_CONTEXT_SECTION_WINDOW_CLASS_REDIRECTION (3)
#defina ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION (4)
#defina ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION (5)
#defina ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION (6)
#defina ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION (7)
#defina ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_TABLE (8)
#defina ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES (9)
#defina ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS (10)

#se_definido __cplusplus
  }
#fim_se
#fim_se
