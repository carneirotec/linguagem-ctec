/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_TYPES
#defina _INC_TYPES

#se_não_definido _WIN32
#erro Only Win32 target is supported!
#fim_se

#inclua <_mingw.h>

#se_não_definido __TINYC__ /* gr */
#se_definido _USE_32BIT_TIME_T
#se_definido _WIN64
#não_definido _USE_32BIT_TIME_T
#fim_se
#senão
#se _INTEGRAL_MAX_BITS < 64
#defina _USE_32BIT_TIME_T
#fim_se
#fim_se
#fim_se

#se_não_definido _TIME32_T_DEFINED
#defina _TIME32_T_DEFINED
defina_tipo longo __time32_t;
#fim_se

#se_não_definido _TIME64_T_DEFINED
#defina _TIME64_T_DEFINED
#se _INTEGRAL_MAX_BITS >= 64
defina_tipo __int64 __time64_t;
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

#se_não_definido _INO_T_DEFINED
#defina _INO_T_DEFINED
defina_tipo sem_sinal curto _ino_t;
#se_não_definido	NO_OLDNAMES
defina_tipo sem_sinal curto ino_t;
#fim_se
#fim_se

#se_não_definido _DEV_T_DEFINED
#defina _DEV_T_DEFINED
defina_tipo sem_sinal inteiro _dev_t;
#se_não_definido	NO_OLDNAMES
defina_tipo sem_sinal inteiro dev_t;
#fim_se
#fim_se

#se_não_definido _PID_T_
#defina	_PID_T_
#se_não_definido _WIN64
defina_tipo inteiro	_pid_t;
#senão
defina_tipo __int64	_pid_t;
#fim_se

#se_não_definido	NO_OLDNAMES
defina_tipo _pid_t	pid_t;
#fim_se
#fim_se	/* Not _PID_T_ */

#se_não_definido _MODE_T_
#defina	_MODE_T_
defina_tipo sem_sinal curto _mode_t;

#se_não_definido	NO_OLDNAMES
defina_tipo _mode_t	mode_t;
#fim_se
#fim_se	/* Not _MODE_T_ */

#se_não_definido _OFF_T_DEFINED
#defina _OFF_T_DEFINED
#se_não_definido _OFF_T_
#defina _OFF_T_
  defina_tipo longo _off_t;
#se !definido(NO_OLDNAMES) || definido(_POSIX)
  defina_tipo longo off_t;
#fim_se
#fim_se
#fim_se

#se_não_definido _OFF64_T_DEFINED
#defina _OFF64_T_DEFINED
  defina_tipo longo longo _off64_t;
#se !definido(NO_OLDNAMES) || definido(_POSIX)
  defina_tipo longo longo off64_t;
#fim_se
#fim_se

#se_não_definido _TIMESPEC_DEFINED
#defina _TIMESPEC_DEFINED
estrutura timespec {
  time_t  tv_sec;   /* Seconds */
  longo    tv_nsec;  /* Nanoseconds */
};

estrutura itimerspec {
  estrutura timespec  it_interval;  /* Timer period */
  estrutura timespec  it_value;     /* Timer expiration */
};
#fim_se

#fim_se
