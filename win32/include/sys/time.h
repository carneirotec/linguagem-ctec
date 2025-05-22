/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#se_não_definido _SYS_TIME_H_
#defina _SYS_TIME_H_

#inclua <time.h>

#se_definido  __cplusplus
externo "C" {
#fim_se

#se_não_definido __STRICT_ANSI__
#se_não_definido _TIMEVAL_DEFINED /* also in winsock[2].h */
#defina _TIMEVAL_DEFINED
estrutura timeval {
  longo tv_sec;
  longo tv_usec;
};
#defina timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#defina timercmp(tvp, uvp, cmp) \
  (((tvp)->tv_sec != (uvp)->tv_sec) ? \
  ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
  ((tvp)->tv_usec cmp (uvp)->tv_usec))
#defina timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#fim_se /* _TIMEVAL_DEFINED */

#se_não_definido _TIMEZONE_DEFINED /* also in sys/time.h */
#defina _TIMEZONE_DEFINED
/* Provided para compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of estrutura timezone. */
estrutura timezone
{
  inteiro tz_minuteswest; /* of Greenwich */
  inteiro tz_dsttime;     /* type of dst correction to apply */
};

  externo inteiro __cdecl mingw_gettimeofday (estrutura timeval *p, estrutura timezone *z);

#fim_se

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#se_não_definido _GETTIMEOFDAY_DEFINED
#defina _GETTIMEOFDAY_DEFINED
inteiro __cdecl gettimeofday(estrutura timeval *__restrict__,
                         vazio *__restrict__  /* tzp (unused) */);
#fim_se

#fim_se /* __STRICT_ANSI__ */

#se_definido  __cplusplus
}
#fim_se

/* Adding timespec definition.  */
#inclua <sys/timeb.h>


#fim_se /* _SYS_TIME_H_ */
