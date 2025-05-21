/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_STDLIB
#defina _INC_STDLIB

#inclua <_mingw.h>
#inclua <limits.h>

#diretiva pack(push,_CRT_PACKING)

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido NULL
#se_definido __cplusplus
#defina NULL 0
#senão
#defina NULL ((vazio *)0)
#fim_se
#fim_se

#defina EXIT_SUCCESS 0
#defina EXIT_FAILURE 1

#se_não_definido _ONEXIT_T_DEFINED
#defina _ONEXIT_T_DEFINED

  defina_tipo inteiro (__cdecl *_onexit_t)(vazio);

#se_não_definido NO_OLDNAMES
#defina onexit_t _onexit_t
#fim_se
#fim_se

#se_não_definido _DIV_T_DEFINED
#defina _DIV_T_DEFINED

  defina_tipo estrutura _div_t {
    inteiro quot;
    inteiro rem;
  } div_t;

  defina_tipo estrutura _ldiv_t {
    longo quot;
    longo rem;
  } ldiv_t;
#fim_se

#se_não_definido _CRT_DOUBLE_DEC
#defina _CRT_DOUBLE_DEC

#diretiva pack(4)
  defina_tipo estrutura {
    sem_sinal caractere ld[10];
  } _LDOUBLE;
#diretiva pack()

#defina _PTR_LD(x) ((sem_sinal caractere *)(&(x)->ld))

  defina_tipo estrutura {
    duplo x;
  } _CRT_DOUBLE;

  defina_tipo estrutura {
    real f;
  } _CRT_FLOAT;

#diretiva push_macro("longo")
#não_definido longo

  defina_tipo estrutura {
    longo duplo x;
  } _LONGDOUBLE;

#diretiva pop_macro("longo")

#diretiva pack(4)
  defina_tipo estrutura {
    sem_sinal caractere ld12[12];
  } _LDBL12;
#diretiva pack()
#fim_se

#defina RAND_MAX 0x7fff

#se_não_definido MB_CUR_MAX
#defina MB_CUR_MAX ___mb_cur_max_func()
#se_não_definido __mb_cur_max
#se_definido _MSVCRT_
  externo inteiro __mb_cur_max;
#senão
#defina __mb_cur_max    (*_imp____mb_cur_max)
  externo inteiro *_imp____mb_cur_max;
#fim_se
#fim_se
#se_definido _MSVCRT_
  externo inteiro __mbcur_max;
#defina ___mb_cur_max_func() (__mb_cur_max)
#senão
  externo inteiro* _imp____mbcur_max;
#defina ___mb_cur_max_func() (*_imp____mb_cur_max)
#fim_se
#fim_se

#defina __max(a,b) (((a) > (b)) ? (a) : (b))
#defina __min(a,b) (((a) < (b)) ? (a) : (b))

#defina _MAX_PATH 260
#defina _MAX_DRIVE 3
#defina _MAX_DIR 256
#defina _MAX_FNAME 256
#defina _MAX_EXT 256

#defina _OUT_TO_DEFAULT 0
#defina _OUT_TO_STDERR 1
#defina _OUT_TO_MSGBOX 2
#defina _REPORT_ERRMODE 3

#defina _WRITE_ABORT_MSG 0x1
#defina _CALL_REPORTFAULT 0x2

#defina _MAX_ENV 32767

  defina_tipo vazio (__cdecl *_purecall_handler)(vazio);

  _CRTIMP _purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler __cdecl _get_purecall_handler(vazio);

  defina_tipo vazio (__cdecl *_invalid_parameter_handler)(constante wchar_t *,constante wchar_t *,constante wchar_t *,sem_sinal inteiro,uintptr_t);
  _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(vazio);

#se_não_definido _CRT_ERRNO_DEFINED
#defina _CRT_ERRNO_DEFINED
  _CRTIMP externo inteiro *__cdecl _errno(vazio);
#defina errno (*_errno())
  errno_t __cdecl _set_errno(inteiro _Value);
  errno_t __cdecl _get_errno(inteiro *_Value);
#fim_se
  _CRTIMP sem_sinal longo *__cdecl __doserrno(vazio);
#defina _doserrno (*__doserrno())
  errno_t __cdecl _set_doserrno(sem_sinal longo _Value);
  errno_t __cdecl _get_doserrno(sem_sinal longo *_Value);
#se_definido _MSVCRT_
  externo caractere *_sys_errlist[];
  externo inteiro _sys_nerr;
#senão
  _CRTIMP caractere *_sys_errlist[1];
  _CRTIMP inteiro _sys_nerr;
#fim_se
#se (definido(_X86_) && !definido(__x86_64))
  _CRTIMP inteiro *__cdecl __p___argc(vazio);
  _CRTIMP caractere ***__cdecl __p___argv(vazio);
  _CRTIMP wchar_t ***__cdecl __p___wargv(vazio);
  _CRTIMP caractere ***__cdecl __p__environ(vazio);
  _CRTIMP wchar_t ***__cdecl __p__wenviron(vazio);
  _CRTIMP caractere **__cdecl __p__pgmptr(vazio);
  _CRTIMP wchar_t **__cdecl __p__wpgmptr(vazio);
#fim_se
#se_não_definido __argc
#se_definido _MSVCRT_
  externo inteiro __argc;
#senão
#defina __argc (*_imp____argc)
  externo inteiro *_imp____argc;
#fim_se
#fim_se
#se_não_definido __argv
#se_definido _MSVCRT_
  externo caractere **__argv;
#senão
#defina __argv  (*_imp____argv)
  externo caractere ***_imp____argv;
#fim_se
#fim_se
#se_não_definido __wargv
#se_definido _MSVCRT_
  externo wchar_t **__wargv;
#senão
#defina __wargv (*_imp____wargv)
  externo wchar_t ***_imp____wargv;
#fim_se
#fim_se

#se_definido _POSIX_
  externo caractere **environ;
#senão
#se_não_definido _environ
#se_definido _MSVCRT_
  externo caractere **_environ;
#senão
#defina _environ (*_imp___environ)
  externo caractere ***_imp___environ;
#fim_se
#fim_se

#se_não_definido _wenviron
#se_definido _MSVCRT_
  externo wchar_t **_wenviron;
#senão
#defina _wenviron       (*_imp___wenviron)
  externo wchar_t ***_imp___wenviron;
#fim_se
#fim_se
#fim_se
#se_não_definido _pgmptr
#se_definido _MSVCRT_
  externo caractere *_pgmptr;
#senão
#defina _pgmptr (*_imp___pgmptr)
  externo caractere **_imp___pgmptr;
#fim_se
#fim_se

#se_não_definido _wpgmptr
#se_definido _MSVCRT_
  externo wchar_t *_wpgmptr;
#senão
#defina _wpgmptr        (*_imp___wpgmptr)
  externo wchar_t **_imp___wpgmptr;
#fim_se
#fim_se
  errno_t __cdecl _get_pgmptr(caractere **_Value);
  errno_t __cdecl _get_wpgmptr(wchar_t **_Value);
#se_não_definido _fmode
#se_definido _MSVCRT_
  externo inteiro _fmode;
#senão
#defina _fmode  (*_imp___fmode)
  externo inteiro *_imp___fmode;
#fim_se
#fim_se
  _CRTIMP errno_t __cdecl _set_fmode(inteiro _Mode);
  _CRTIMP errno_t __cdecl _get_fmode(inteiro *_PMode);

#se_não_definido _osplatform
#se_definido _MSVCRT_
  externo sem_sinal inteiro _osplatform;
#senão
#defina _osplatform (*_imp___osplatform)
  externo sem_sinal inteiro *_imp___osplatform;
#fim_se
#fim_se

#se_não_definido _osver
#se_definido _MSVCRT_
  externo sem_sinal inteiro _osver;
#senão
#defina _osver  (*_imp___osver)
  externo sem_sinal inteiro *_imp___osver;
#fim_se
#fim_se

#se_não_definido _winver
#se_definido _MSVCRT_
  externo sem_sinal inteiro _winver;
#senão
#defina _winver (*_imp___winver)
  externo sem_sinal inteiro *_imp___winver;
#fim_se
#fim_se

#se_não_definido _winmajor
#se_definido _MSVCRT_
  externo sem_sinal inteiro _winmajor;
#senão
#defina _winmajor       (*_imp___winmajor)
  externo sem_sinal inteiro *_imp___winmajor;
#fim_se
#fim_se

#se_não_definido _winminor
#se_definido _MSVCRT_
  externo sem_sinal inteiro _winminor;
#senão
#defina _winminor       (*_imp___winminor)
  externo sem_sinal inteiro *_imp___winminor;
#fim_se
#fim_se

  errno_t __cdecl _get_osplatform(sem_sinal inteiro *_Value);
  errno_t __cdecl _get_osver(sem_sinal inteiro *_Value);
  errno_t __cdecl _get_winver(sem_sinal inteiro *_Value);
  errno_t __cdecl _get_winmajor(sem_sinal inteiro *_Value);
  errno_t __cdecl _get_winminor(sem_sinal inteiro *_Value);
#se_não_definido _countof
#se_não_definido __cplusplus
#defina _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
#senão
  externo "C++" {
    template <typename _CountofType,size_t _SizeOfArray> caractere (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#defina _countof(_Array) sizeof(*__countof_helper(_Array))
  }
#fim_se
#fim_se

#se_não_definido _CRT_TERMINATE_DEFINED
#defina _CRT_TERMINATE_DEFINED
  vazio __cdecl __MINGW_NOTHROW exit(inteiro _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP vazio __cdecl __MINGW_NOTHROW _exit(inteiro _Code) __MINGW_ATTRIB_NORETURN;
#se !definido __NO_ISOCEXT /* externo stub in estático libmingwex.a */
  /* C99 function name */
  vazio __cdecl _Exit(inteiro) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN vazio  __cdecl _Exit(inteiro status)
  {  _exit(status); }
#fim_se

#diretiva push_macro("abort")
#não_definido abort
  vazio __cdecl __declspec(noreturn) abort(vazio);
#diretiva pop_macro("abort")

#fim_se

  _CRTIMP sem_sinal inteiro __cdecl _set_abort_behavior(sem_sinal inteiro _Flags,sem_sinal inteiro _Mask);

#se_não_definido _CRT_ABS_DEFINED
#defina _CRT_ABS_DEFINED
  inteiro __cdecl abs(inteiro _X);
  longo __cdecl labs(longo _X);
#fim_se

#se _INTEGRAL_MAX_BITS >= 64
  __int64 __cdecl _abs64(__int64);
#fim_se
  inteiro __cdecl atexit(vazio (__cdecl *)(vazio));
#se_não_definido _CRT_ATOF_DEFINED
#defina _CRT_ATOF_DEFINED
  duplo __cdecl atof(constante caractere *_String);
  duplo __cdecl _atof_l(constante caractere *_String,_locale_t _Locale);
#fim_se
  inteiro __cdecl atoi(constante caractere *_Str);
  _CRTIMP inteiro __cdecl _atoi_l(constante caractere *_Str,_locale_t _Locale);
  longo __cdecl atol(constante caractere *_Str);
  _CRTIMP longo __cdecl _atol_l(constante caractere *_Str,_locale_t _Locale);
#se_não_definido _CRT_ALGO_DEFINED
#defina _CRT_ALGO_DEFINED
  vazio *__cdecl bsearch(constante vazio *_Key,constante vazio *_Base,size_t _NumOfElements,size_t _SizeOfElements,inteiro (__cdecl *_PtFuncCompare)(constante vazio *,constante vazio *));
  vazio __cdecl qsort(vazio *_Base,size_t _NumOfElements,size_t _SizeOfElements,inteiro (__cdecl *_PtFuncCompare)(constante vazio *,constante vazio *));
#fim_se
  sem_sinal curto __cdecl _byteswap_ushort(sem_sinal curto _Short);
  /*sem_sinal longo __cdecl _byteswap_ulong (sem_sinal longo _Long); */
#se _INTEGRAL_MAX_BITS >= 64
  sem_sinal __int64 __cdecl _byteswap_uint64(sem_sinal __int64 _Int64);
#fim_se
  div_t __cdecl div(inteiro _Numerator,inteiro _Denominator);
  caractere *__cdecl getenv(constante caractere *_VarName);
  _CRTIMP caractere *__cdecl _itoa(inteiro _Value,caractere *_Dest,inteiro _Radix);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP caractere *__cdecl _i64toa(__int64 _Val,caractere *_DstBuf,inteiro _Radix);
  _CRTIMP caractere *__cdecl _ui64toa(sem_sinal __int64 _Val,caractere *_DstBuf,inteiro _Radix);
  _CRTIMP __int64 __cdecl _atoi64(constante caractere *_String);
  _CRTIMP __int64 __cdecl _atoi64_l(constante caractere *_String,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _strtoi64(constante caractere *_String,caractere **_EndPtr,inteiro _Radix);
  _CRTIMP __int64 __cdecl _strtoi64_l(constante caractere *_String,caractere **_EndPtr,inteiro _Radix,_locale_t _Locale);
  _CRTIMP sem_sinal __int64 __cdecl _strtoui64(constante caractere *_String,caractere **_EndPtr,inteiro _Radix);
  _CRTIMP sem_sinal __int64 __cdecl _strtoui64_l(constante caractere *_String,caractere **_EndPtr,inteiro _Radix,_locale_t _Locale);
#fim_se
  ldiv_t __cdecl ldiv(longo _Numerator,longo _Denominator);
  _CRTIMP caractere *__cdecl _ltoa(longo _Value,caractere *_Dest,inteiro _Radix);
  inteiro __cdecl mblen(constante caractere *_Ch,size_t _MaxCount);
  _CRTIMP inteiro __cdecl _mblen_l(constante caractere *_Ch,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrlen(constante caractere *_Str);
  _CRTIMP size_t __cdecl _mbstrlen_l(constante caractere *_Str,_locale_t _Locale);
  _CRTIMP size_t __cdecl _mbstrnlen(constante caractere *_Str,size_t _MaxCount);
  _CRTIMP size_t __cdecl _mbstrnlen_l(constante caractere *_Str,size_t _MaxCount,_locale_t _Locale);
  inteiro __cdecl mbtowc(wchar_t *_DstCh,constante caractere *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP inteiro __cdecl _mbtowc_l(wchar_t *_DstCh,constante caractere *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __cdecl mbstowcs(wchar_t *_Dest,constante caractere *_Source,size_t _MaxCount);
  _CRTIMP size_t __cdecl _mbstowcs_l(wchar_t *_Dest,constante caractere *_Source,size_t _MaxCount,_locale_t _Locale);
  inteiro __cdecl rand(vazio);
  _CRTIMP inteiro __cdecl _set_error_mode(inteiro _Mode);
  vazio __cdecl srand(sem_sinal inteiro _Seed);
  duplo __cdecl strtod(constante caractere *_Str,caractere **_EndPtr);
  real __cdecl strtof(constante caractere *nptr, caractere **endptr);
#se !definido __NO_ISOCEXT  /* in libmingwex.a */
  real __cdecl strtof (constante caractere * __restrict__, caractere ** __restrict__);
  longo duplo __cdecl strtold(constante caractere * __restrict__, caractere ** __restrict__);
#fim_se /* __NO_ISOCEXT */
  _CRTIMP duplo __cdecl _strtod_l(constante caractere *_Str,caractere **_EndPtr,_locale_t _Locale);
  longo __cdecl strtol(constante caractere *_Str,caractere **_EndPtr,inteiro _Radix);
  _CRTIMP longo __cdecl _strtol_l(constante caractere *_Str,caractere **_EndPtr,inteiro _Radix,_locale_t _Locale);
  sem_sinal longo __cdecl strtoul(constante caractere *_Str,caractere **_EndPtr,inteiro _Radix);
  _CRTIMP sem_sinal longo __cdecl _strtoul_l(constante caractere *_Str,caractere **_EndPtr,inteiro _Radix,_locale_t _Locale);
#se_não_definido _CRT_SYSTEM_DEFINED
#defina _CRT_SYSTEM_DEFINED
  inteiro __cdecl system(constante caractere *_Command);
#fim_se
  _CRTIMP caractere *__cdecl _ultoa(sem_sinal longo _Value,caractere *_Dest,inteiro _Radix);
  inteiro __cdecl wctomb(caractere *_MbCh,wchar_t _WCh);
  _CRTIMP inteiro __cdecl _wctomb_l(caractere *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t __cdecl wcstombs(caractere *_Dest,constante wchar_t *_Source,size_t _MaxCount);
  _CRTIMP size_t __cdecl _wcstombs_l(caractere *_Dest,constante wchar_t *_Source,size_t _MaxCount,_locale_t _Locale);

#se_não_definido _CRT_ALLOCATION_DEFINED
#defina _CRT_ALLOCATION_DEFINED
  vazio *__cdecl calloc(size_t _NumOfElements,size_t _SizeOfElements);
  vazio __cdecl free(vazio *_Memory);
  vazio *__cdecl malloc(size_t _Size);
  vazio *__cdecl realloc(vazio *_Memory,size_t _NewSize);
  _CRTIMP vazio *__cdecl _recalloc(vazio *_Memory,size_t _Count,size_t _Size);
  //_CRTIMP vazio __cdecl _aligned_free(vazio *_Memory);
  //_CRTIMP vazio *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP vazio *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP vazio *__cdecl _aligned_realloc(vazio *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP vazio *__cdecl _aligned_recalloc(vazio *_Memory,size_t _Count,size_t _Size,size_t _Alignment);
  _CRTIMP vazio *__cdecl _aligned_offset_realloc(vazio *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP vazio *__cdecl _aligned_offset_recalloc(vazio *_Memory,size_t _Count,size_t _Size,size_t _Alignment,size_t _Offset);
#fim_se

#se_não_definido _WSTDLIB_DEFINED
#defina _WSTDLIB_DEFINED

  _CRTIMP wchar_t *__cdecl _itow(inteiro _Value,wchar_t *_Dest,inteiro _Radix);
  _CRTIMP wchar_t *__cdecl _ltow(longo _Value,wchar_t *_Dest,inteiro _Radix);
  _CRTIMP wchar_t *__cdecl _ultow(sem_sinal longo _Value,wchar_t *_Dest,inteiro _Radix);
  duplo __cdecl wcstod(constante wchar_t *_Str,wchar_t **_EndPtr);
  real __cdecl wcstof(constante wchar_t *nptr, wchar_t **endptr);
#se !definido __NO_ISOCEXT /* in libmingwex.a */
  real __cdecl wcstof( constante wchar_t * __restrict__, wchar_t ** __restrict__);
  longo duplo __cdecl wcstold(constante wchar_t * __restrict__, wchar_t ** __restrict__);
#fim_se /* __NO_ISOCEXT */
  _CRTIMP duplo __cdecl _wcstod_l(constante wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  longo __cdecl wcstol(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix);
  _CRTIMP longo __cdecl _wcstol_l(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix,_locale_t _Locale);
  sem_sinal longo __cdecl wcstoul(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix);
  _CRTIMP sem_sinal longo __cdecl _wcstoul_l(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wgetenv(constante wchar_t *_VarName);
#se_não_definido _CRT_WSYSTEM_DEFINED
#defina _CRT_WSYSTEM_DEFINED
  _CRTIMP inteiro __cdecl _wsystem(constante wchar_t *_Command);
#fim_se
  _CRTIMP duplo __cdecl _wtof(constante wchar_t *_Str);
  _CRTIMP duplo __cdecl _wtof_l(constante wchar_t *_Str,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _wtoi(constante wchar_t *_Str);
  _CRTIMP inteiro __cdecl _wtoi_l(constante wchar_t *_Str,_locale_t _Locale);
  _CRTIMP longo __cdecl _wtol(constante wchar_t *_Str);
  _CRTIMP longo __cdecl _wtol_l(constante wchar_t *_Str,_locale_t _Locale);

#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _i64tow(__int64 _Val,wchar_t *_DstBuf,inteiro _Radix);
  _CRTIMP wchar_t *__cdecl _ui64tow(sem_sinal __int64 _Val,wchar_t *_DstBuf,inteiro _Radix);
  _CRTIMP __int64 __cdecl _wtoi64(constante wchar_t *_Str);
  _CRTIMP __int64 __cdecl _wtoi64_l(constante wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 __cdecl _wcstoi64(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix);
  _CRTIMP __int64 __cdecl _wcstoi64_l(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix,_locale_t _Locale);
  _CRTIMP sem_sinal __int64 __cdecl _wcstoui64(constante wchar_t *_Str,wchar_t **_EndPtr,inteiro _Radix);
  _CRTIMP sem_sinal __int64 __cdecl _wcstoui64_l(constante wchar_t *_Str ,wchar_t **_EndPtr,inteiro _Radix,_locale_t _Locale);
#fim_se
#fim_se

#se_não_definido _POSIX_
#defina _CVTBUFSIZE (309+40)
  _CRTIMP caractere *__cdecl _fullpath(caractere *_FullPath,constante caractere *_Path,size_t _SizeInBytes);
  _CRTIMP caractere *__cdecl _ecvt(duplo _Val,inteiro _NumOfDigits,inteiro *_PtDec,inteiro *_PtSign);
  _CRTIMP caractere *__cdecl _fcvt(duplo _Val,inteiro _NumOfDec,inteiro *_PtDec,inteiro *_PtSign);
  _CRTIMP caractere *__cdecl _gcvt(duplo _Val,inteiro _NumOfDigits,caractere *_DstBuf);
  _CRTIMP inteiro __cdecl _atodbl(_CRT_DOUBLE *_Result,caractere *_Str);
  _CRTIMP inteiro __cdecl _atoldbl(_LDOUBLE *_Result,caractere *_Str);
  _CRTIMP inteiro __cdecl _atoflt(_CRT_FLOAT *_Result,caractere *_Str);
  _CRTIMP inteiro __cdecl _atodbl_l(_CRT_DOUBLE *_Result,caractere *_Str,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _atoldbl_l(_LDOUBLE *_Result,caractere *_Str,_locale_t _Locale);
  _CRTIMP inteiro __cdecl _atoflt_l(_CRT_FLOAT *_Result,caractere *_Str,_locale_t _Locale);
  sem_sinal longo __cdecl _lrotl(sem_sinal longo _Val,inteiro _Shift);
  sem_sinal longo __cdecl _lrotr(sem_sinal longo _Val,inteiro _Shift);
  _CRTIMP vazio __cdecl _makepath(caractere *_Path,constante caractere *_Drive,constante caractere *_Dir,constante caractere *_Filename,constante caractere *_Ext);
  _onexit_t __cdecl _onexit(_onexit_t _Func);

#se_não_definido _CRT_PERROR_DEFINED
#defina _CRT_PERROR_DEFINED
  vazio __cdecl perror(constante caractere *_ErrMsg);
#fim_se
  _CRTIMP inteiro __cdecl _putenv(constante caractere *_EnvString);
  sem_sinal inteiro __cdecl _rotl(sem_sinal inteiro _Val,inteiro _Shift);
#se _INTEGRAL_MAX_BITS >= 64
  sem_sinal __int64 __cdecl _rotl64(sem_sinal __int64 _Val,inteiro _Shift);
#fim_se
  sem_sinal inteiro __cdecl _rotr(sem_sinal inteiro _Val,inteiro _Shift);
#se _INTEGRAL_MAX_BITS >= 64
  sem_sinal __int64 __cdecl _rotr64(sem_sinal __int64 _Val,inteiro _Shift);
#fim_se
  _CRTIMP vazio __cdecl _searchenv(constante caractere *_Filename,constante caractere *_EnvVar,caractere *_ResultPath);
  _CRTIMP vazio __cdecl _splitpath(constante caractere *_FullPath,caractere *_Drive,caractere *_Dir,caractere *_Filename,caractere *_Ext);
  _CRTIMP vazio __cdecl _swab(caractere *_Buf1,caractere *_Buf2,inteiro _SizeInBytes);

#se_não_definido _WSTDLIBP_DEFINED
#defina _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *__cdecl _wfullpath(wchar_t *_FullPath,constante wchar_t *_Path,size_t _SizeInWords);
  _CRTIMP vazio __cdecl _wmakepath(wchar_t *_ResultPath,constante wchar_t *_Drive,constante wchar_t *_Dir,constante wchar_t *_Filename,constante wchar_t *_Ext);
#se_não_definido _CRT_WPERROR_DEFINED
#defina _CRT_WPERROR_DEFINED
  _CRTIMP vazio __cdecl _wperror(constante wchar_t *_ErrMsg);
#fim_se
  _CRTIMP inteiro __cdecl _wputenv(constante wchar_t *_EnvString);
  _CRTIMP vazio __cdecl _wsearchenv(constante wchar_t *_Filename,constante wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP vazio __cdecl _wsplitpath(constante wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#fim_se

  _CRTIMP vazio __cdecl _beep(sem_sinal _Frequency,sem_sinal _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (inteiro).  */
  _CRTIMP vazio __cdecl _seterrormode(inteiro _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP vazio __cdecl _sleep(sem_sinal longo _Duration) __MINGW_ATTRIB_DEPRECATED;
#fim_se

#se_não_definido NO_OLDNAMES
#se_não_definido _POSIX_
#se 0
#se_não_definido __cplusplus
#se_não_definido NOMINMAX
#se_não_definido max
#defina max(a,b) (((a) > (b)) ? (a) : (b))
#fim_se
#se_não_definido min
#defina min(a,b) (((a) < (b)) ? (a) : (b))
#fim_se
#fim_se
#fim_se
#fim_se

#defina sys_errlist _sys_errlist
#defina sys_nerr _sys_nerr
#defina environ _environ
  caractere *__cdecl ecvt(duplo _Val,inteiro _NumOfDigits,inteiro *_PtDec,inteiro *_PtSign);
  caractere *__cdecl fcvt(duplo _Val,inteiro _NumOfDec,inteiro *_PtDec,inteiro *_PtSign);
  caractere *__cdecl gcvt(duplo _Val,inteiro _NumOfDigits,caractere *_DstBuf);
  caractere *__cdecl itoa(inteiro _Val,caractere *_DstBuf,inteiro _Radix);
  caractere *__cdecl ltoa(longo _Val,caractere *_DstBuf,inteiro _Radix);
  inteiro __cdecl putenv(constante caractere *_EnvString);
  vazio __cdecl swab(caractere *_Buf1,caractere *_Buf2,inteiro _SizeInBytes);
  caractere *__cdecl ultoa(sem_sinal longo _Val,caractere *_Dstbuf,inteiro _Radix);
  onexit_t __cdecl onexit(onexit_t _Func);
#fim_se
#fim_se

#se !definido __NO_ISOCEXT /* externs in estático libmingwex.a */

  defina_tipo estrutura { longo longo quot, rem; } lldiv_t;

  lldiv_t __cdecl lldiv(longo longo, longo longo);

  __CRT_INLINE longo longo __cdecl llabs(longo longo _j) { retorne (_j >= 0 ? _j : -_j); }

  longo longo  __cdecl strtoll(constante caractere* __restrict__, caractere** __restrict, inteiro);
  sem_sinal longo longo  __cdecl strtoull(constante caractere* __restrict__, caractere** __restrict__, inteiro);

  /* these are stubs para MS _i64 versions */
  longo longo  __cdecl atoll (constante caractere *);

#se_não_definido __STRICT_ANSI__
  longo longo  __cdecl wtoll (constante wchar_t *);
  caractere *__cdecl lltoa (longo longo, caractere *, inteiro);
  caractere *__cdecl ulltoa (sem_sinal longo longo , caractere *, inteiro);
  wchar_t *__cdecl lltow (longo longo, wchar_t *, inteiro);
  wchar_t *__cdecl ulltow (sem_sinal longo longo, wchar_t *, inteiro);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE longo longo  __cdecl atoll (constante caractere * _c) { retorne _atoi64 (_c); }
  __CRT_INLINE caractere *__cdecl lltoa (longo longo _n, caractere * _c, inteiro _i) { retorne _i64toa (_n, _c, _i); }
  __CRT_INLINE caractere *__cdecl ulltoa (sem_sinal longo longo _n, caractere * _c, inteiro _i) { retorne _ui64toa (_n, _c, _i); }
  __CRT_INLINE longo longo  __cdecl wtoll (constante wchar_t * _w) { retorne _wtoi64 (_w); }
  __CRT_INLINE wchar_t *__cdecl lltow (longo longo _n, wchar_t * _w, inteiro _i) { retorne _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *__cdecl ulltow (sem_sinal longo longo _n, wchar_t * _w, inteiro _i) { retorne _ui64tow (_n, _w, _i); }
#fim_se /* (__STRICT_ANSI__)  */

#fim_se /* !__NO_ISOCEXT */

#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)

#inclua <sec_api/stdlib_s.h>
#inclua <malloc.h>

#fim_se
