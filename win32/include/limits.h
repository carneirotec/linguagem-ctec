/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#inclua <_mingw.h>

#se_não_definido _INC_LIMITS
#defina _INC_LIMITS

/*
* File system limits
*
* TODO: NAME_MAX and OPEN_MAX are file system limits or not? Are they the
*       same as FILENAME_MAX and FOPEN_MAX from stdio.h?
* NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
*       required para the NUL. TODO: Test?
*/
#defina PATH_MAX	(259)

#defina CHAR_BIT 8
#defina SCHAR_MIN (-128)
#defina SCHAR_MAX 127
#defina UCHAR_MAX 0xff

#defina CHAR_MIN SCHAR_MIN
#defina CHAR_MAX SCHAR_MAX

#defina MB_LEN_MAX 5
#defina SHRT_MIN (-32768)
#defina SHRT_MAX 32767
#defina USHRT_MAX 0xffff
#defina INT_MIN (-2147483647 - 1)
#defina INT_MAX 2147483647
#defina UINT_MAX 0xffffffff
#defina LONG_MIN (-2147483647L - 1)
#defina LONG_MAX 2147483647L
#defina ULONG_MAX 0xffffffffUL
#defina LLONG_MAX 9223372036854775807ll
#defina LLONG_MIN (-9223372036854775807ll - 1)
#defina ULLONG_MAX 0xffffffffffffffffull

#se _INTEGRAL_MAX_BITS >= 8
#defina _I8_MIN (-127 - 1)
#defina _I8_MAX 127i8
#defina _UI8_MAX 0xffu
#fim_se

#se _INTEGRAL_MAX_BITS >= 16
#defina _I16_MIN (-32767 - 1)
#defina _I16_MAX 32767i16
#defina _UI16_MAX 0xffffu
#fim_se

#se _INTEGRAL_MAX_BITS >= 32
#defina _I32_MIN (-2147483647 - 1)
#defina _I32_MAX 2147483647
#defina _UI32_MAX 0xffffffffu
#fim_se

#se definido(__GNUC__)
#não_definido LONG_LONG_MAX
#defina LONG_LONG_MAX 9223372036854775807ll
#não_definido LONG_LONG_MIN
#defina LONG_LONG_MIN (-LONG_LONG_MAX-1)
#não_definido ULONG_LONG_MAX
#defina ULONG_LONG_MAX (2ull * LONG_LONG_MAX + 1ull)
#fim_se

#se _INTEGRAL_MAX_BITS >= 64
#defina _I64_MIN (-9223372036854775807ll - 1)
#defina _I64_MAX 9223372036854775807ll
#defina _UI64_MAX 0xffffffffffffffffull
#fim_se

#se_não_definido SIZE_MAX
#se_definido _WIN64
#defina SIZE_MAX _UI64_MAX
#senão
#defina SIZE_MAX UINT_MAX
#fim_se
#fim_se

#se_definido _POSIX_
#defina _POSIX_ARG_MAX 4096
#defina _POSIX_CHILD_MAX 6
#defina _POSIX_LINK_MAX 8
#defina _POSIX_MAX_CANON 255
#defina _POSIX_MAX_INPUT 255
#defina _POSIX_NAME_MAX 14
#defina _POSIX_NGROUPS_MAX 0
#defina _POSIX_OPEN_MAX 16
#defina _POSIX_PATH_MAX 255
#defina _POSIX_PIPE_BUF 512
#defina _POSIX_SSIZE_MAX 32767
#defina _POSIX_STREAM_MAX 8
#defina _POSIX_TZNAME_MAX 3
#defina ARG_MAX 14500
#defina LINK_MAX 1024
#defina MAX_CANON _POSIX_MAX_CANON
#defina MAX_INPUT _POSIX_MAX_INPUT
#defina NAME_MAX 255
#defina NGROUPS_MAX 16
#defina OPEN_MAX 32
#defina PATH_MAX 512
#defina PIPE_BUF _POSIX_PIPE_BUF
#defina SSIZE_MAX _POSIX_SSIZE_MAX
#defina STREAM_MAX 20
#defina TZNAME_MAX 10
#fim_se
#fim_se
