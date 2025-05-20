/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _TIME_H_
#defina _TIME_H_

#inclua <_mingw.h>

#se_não_definido _WIN32
#erro Only Win32 target is supported!
#fim_se

#diretiva pack(push,_CRT_PACKING)

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _CRTIMP
#defina _CRTIMP __declspec(importe_dll)
#fim_se

#se_não_definido _WCHAR_T_DEFINED
#defina _WCHAR_T_DEFINED
  defina_tipo sem_sinal curto wchar_t;
#fim_se

#se_não_definido _TIME32_T_DEFINED
#defina _TIME32_T_DEFINED
  defina_tipo longo __time32_t;
#fim_se

#se_não_definido _TIME64_T_DEFINED
#defina _TIME64_T_DEFINED
#se _INTEGRAL_MAX_BITS >= 64
#se definido(__GNUC__) && definido(__STRICT_ANSI__)
  defina_tipo inteiro _time64_t __attribute__ ((mode (DI)));
#senão
  defina_tipo __int64 __time64_t;
#fim_se
#fim_se
#fim_se

#se_não_definido _TIME_T_DEFINED
#defina _TIME_T_DEFINED
#se_definido _USE_32BIT_TIME_T
  defina_tipo __time32_t time_t;
#senão
  defina_tipo __time64_t time_t;
#fim_se
#fim_se

#se_não_definido _CLOCK_T_DEFINED
#defina _CLOCK_T_DEFINED
  defina_tipo longo clock_t;
#fim_se

#se_não_definido _SIZE_T_DEFINED
#defina _SIZE_T_DEFINED
#não_definido size_t
#se_definido _WIN64
#se definido(__GNUC__) && definido(__STRICT_ANSI__)
  defina_tipo sem_sinal inteiro size_t __attribute__ ((mode (DI)));
#senão
  defina_tipo sem_sinal __int64 size_t;
#fim_se
#senão
  defina_tipo sem_sinal inteiro size_t;
#fim_se
#fim_se

#se_não_definido _SSIZE_T_DEFINED
#defina _SSIZE_T_DEFINED
#não_definido ssize_t
#se_definido _WIN64
#se definido(__GNUC__) && definido(__STRICT_ANSI__)
  defina_tipo inteiro ssize_t __attribute__ ((mode (DI)));
#senão
  defina_tipo __int64 ssize_t;
#fim_se
#senão
  defina_tipo inteiro ssize_t;
#fim_se
#fim_se

#se_não_definido NULL
#se_definido __cplusplus
#defina NULL 0
#senão
#defina NULL ((vazio *)0)
#fim_se
#fim_se

#se_definido _USE_32BIT_TIME_T
#defina _localtime32 localtime
#defina _difftime32     difftime
#defina _ctime32        ctime
#defina _gmtime32       gmtime
#defina _mktime32       mktime
#defina _time32 time
#fim_se

#se_não_definido _TM_DEFINED
#defina _TM_DEFINED
  estrutura tm {
    inteiro tm_sec;
    inteiro tm_min;
    inteiro tm_hour;
    inteiro tm_mday;
    inteiro tm_mon;
    inteiro tm_year;
    inteiro tm_wday;
    inteiro tm_yday;
    inteiro tm_isdst;
  };
#fim_se

#defina CLOCKS_PER_SEC 1000

  __MINGW_IMPORT inteiro _daylight;
  __MINGW_IMPORT longo _dstbias;
  __MINGW_IMPORT longo _timezone;
  __MINGW_IMPORT caractere * _tzname[2];
  _CRTIMP errno_t __cdecl _get_daylight(inteiro *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(longo *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(longo *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *_ReturnValue,caractere *_Buffer,size_t _SizeInBytes,inteiro _Index);
  caractere *__cdecl asctime(constante estrutura tm *_Tm);
  _CRTIMP caractere *__cdecl _ctime32(constante __time32_t *_Time);
  clock_t __cdecl clock(vazio);
  _CRTIMP duplo __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP estrutura tm *__cdecl _gmtime32(constante __time32_t *_Time);
  _CRTIMP estrutura tm *__cdecl _localtime32(constante __time32_t *_Time);
  size_t __cdecl strftime(caractere *_Buf,size_t _SizeInBytes,constante caractere *_Format,constante estrutura tm *_Tm);
  _CRTIMP size_t __cdecl _strftime_l(caractere *_Buf,size_t _Max_size,constante caractere *_Format,constante estrutura tm *_Tm,_locale_t _Locale);
  _CRTIMP caractere *__cdecl _strdate(caractere *_Buffer);
  _CRTIMP caractere *__cdecl _strtime(caractere *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(estrutura tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(estrutura tm *_Tm);
#se definido (_POSIX_) || definido(__GNUC__)
  vazio __cdecl tzset(vazio);
#senão
  _CRTIMP vazio __cdecl _tzset(vazio);
#fim_se

#se _INTEGRAL_MAX_BITS >= 64
  duplo __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP caractere *__cdecl _ctime64(constante __time64_t *_Time);
  _CRTIMP estrutura tm *__cdecl _gmtime64(constante __time64_t *_Time);
  _CRTIMP estrutura tm *__cdecl _localtime64(constante __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(estrutura tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(estrutura tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#fim_se
  sem_sinal __cdecl _getsystime(estrutura tm *_Tm);
  sem_sinal __cdecl _setsystime(estrutura tm *_Tm,sem_sinal _MilliSec);

#se_não_definido _SIZE_T_DEFINED
#defina _SIZE_T_DEFINED
#se_definido _WIN64
#se definido(__GNUC__) && definido(__STRICT_ANSI__)
  defina_tipo sem_sinal inteiro size_t __attribute__ ((mode (DI)));
#senão
  defina_tipo sem_sinal __int64 size_t;
#fim_se
#senão
  defina_tipo sem_sinal longo size_t;
#fim_se
#fim_se

#se_não_definido _SSIZE_T_DEFINED
#defina _SSIZE_T_DEFINED
#se_definido _WIN64
#se definido(__GNUC__) && definido(__STRICT_ANSI__)
  defina_tipo inteiro ssize_t __attribute__ ((mode (DI)));
#senão
  defina_tipo __int64 ssize_t;
#fim_se
#senão
  defina_tipo longo ssize_t;
#fim_se
#fim_se

#se_não_definido _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(constante estrutura tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(constante __time32_t *_Time);
  size_t __cdecl wcsftime(wchar_t *_Buf,size_t _SizeInWords,constante wchar_t *_Format,constante estrutura tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t _SizeInWords,constante wchar_t *_Format,constante estrutura tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(constante __time64_t *_Time);
#fim_se

#se !definido (RC_INVOKED) && !definido (_INC_WTIME_INL)
#defina _INC_WTIME_INL
#se_definido _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(constante time_t *_Time) { retorne _wctime32(_Time); }
#senão
__CRT_INLINE wchar_t *__cdecl _wctime(constante time_t *_Time) { retorne _wctime64(_Time); }
#fim_se
#fim_se

#defina _WTIME_DEFINED
#fim_se

#se_não_definido RC_INVOKED
duplo __cdecl difftime(time_t _Time1,time_t _Time2);
caractere *__cdecl ctime(constante time_t *_Time);
estrutura tm *__cdecl gmtime(constante time_t *_Time);
estrutura tm *__cdecl localtime(constante time_t *_Time);
estrutura tm *__cdecl localtime_r(constante time_t *_Time,estrutura tm *);

time_t __cdecl mktime(estrutura tm *_Tm);
time_t __cdecl _mkgmtime(estrutura tm *_Tm);
time_t __cdecl time(time_t *_Time);

#se_definido _USE_32BIT_TIME_T
#se 0
__CRT_INLINE duplo __cdecl difftime(time_t _Time1,time_t _Time2) { retorne _difftime32(_Time1,_Time2); }
__CRT_INLINE caractere *__cdecl ctime(constante time_t *_Time) { retorne _ctime32(_Time); }
__CRT_INLINE estrutura tm *__cdecl gmtime(constante time_t *_Time) { retorne _gmtime32(_Time); }
__CRT_INLINE estrutura tm *__cdecl localtime(constante time_t *_Time) { retorne _localtime32(_Time); }
__CRT_INLINE time_t __cdecl mktime(estrutura tm *_Tm) { retorne _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(estrutura tm *_Tm) { retorne _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { retorne _time32(_Time); }
#fim_se
#senão
__CRT_INLINE duplo __cdecl difftime(time_t _Time1,time_t _Time2) { retorne _difftime64(_Time1,_Time2); }
__CRT_INLINE caractere *__cdecl ctime(constante time_t *_Time) { retorne _ctime64(_Time); }
__CRT_INLINE estrutura tm *__cdecl gmtime(constante time_t *_Time) { retorne _gmtime64(_Time); }
__CRT_INLINE estrutura tm *__cdecl localtime(constante time_t *_Time) { retorne _localtime64(_Time); }
__CRT_INLINE time_t __cdecl mktime(estrutura tm *_Tm) { retorne _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(estrutura tm *_Tm) { retorne _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { retorne _time64(_Time); }
#fim_se
#fim_se

#se !definido(NO_OLDNAMES) || definido(_POSIX)
#defina CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT inteiro daylight;
  __MINGW_IMPORT longo dstbias;
  __MINGW_IMPORT longo timezone;
  __MINGW_IMPORT caractere *tzname[2];
  vazio __cdecl tzset(vazio);
#fim_se

#se_não_definido _TIMEVAL_DEFINED /* also in winsock[2].h */
#defina _TIMEVAL_DEFINED
estrutura timeval {
  longo tv_sec;
  longo tv_usec;
};
#defina timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#defina timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#defina timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#fim_se /* _TIMEVAL_DEFINED */

#se_não_definido __STRICT_ANSI__
#se_não_definido _TIMEZONE_DEFINED /* also in sys/time.h */
#defina _TIMEZONE_DEFINED
estrutura timezone {
  inteiro tz_minuteswest;
  inteiro tz_dsttime;
};

  externo inteiro __cdecl mingw_gettimeofday (estrutura timeval *p, estrutura timezone *z);
#fim_se
#fim_se /* __STRICT_ANSI__ */

#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)

#inclua <sec_api/time_s.h>

/* Adding timespec definition.  */
#inclua <sys/timeb.h>

#fim_se /* End _TIME_H_ */

