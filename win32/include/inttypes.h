/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* 7.8 Format conversion of integer types <inttypes.h> */

#se_não_definido _INTTYPES_H_
#defina _INTTYPES_H_

#inclua <_mingw.h>
#inclua <stdint.h>
#defina __need_wchar_t
#inclua <stddef.h>

#se_definido	__cplusplus
externo	"C"	{
#fim_se

defina_tipo estrutura {
	intmax_t quot;
	intmax_t rem;
	} imaxdiv_t;

#se !definido(__cplusplus) || definido(__STDC_FORMAT_MACROS)

/* 7.8.1 Macros para format specifiers
 * 
 * MS runtime does not yet understand C9x standard "ll"
 * length specifier. It appears to treat "ll" as "l".
 * The non-standard I64 length specifier causes aviso in GCC,
 * but understood by MS runtime functions.
 */

/* fprintf macros para sinalizado types */
#defina PRId8 "d"
#defina PRId16 "d"
#defina PRId32 "d"
#defina PRId64 "I64d"

#defina PRIdLEAST8 "d"
#defina PRIdLEAST16 "d"
#defina PRIdLEAST32 "d"
#defina PRIdLEAST64 "I64d"

#defina PRIdFAST8 "d"
#defina PRIdFAST16 "d"
#defina PRIdFAST32 "d"
#defina PRIdFAST64 "I64d"

#defina PRIdMAX "I64d"

#defina PRIi8 "i"
#defina PRIi16 "i"
#defina PRIi32 "i"
#defina PRIi64 "I64i"

#defina PRIiLEAST8 "i"
#defina PRIiLEAST16 "i"
#defina PRIiLEAST32 "i"
#defina PRIiLEAST64 "I64i"

#defina PRIiFAST8 "i"
#defina PRIiFAST16 "i"
#defina PRIiFAST32 "i"
#defina PRIiFAST64 "I64i"

#defina PRIiMAX "I64i"

#defina PRIo8 "o"
#defina PRIo16 "o"
#defina PRIo32 "o"
#defina PRIo64 "I64o"

#defina PRIoLEAST8 "o"
#defina PRIoLEAST16 "o"
#defina PRIoLEAST32 "o"
#defina PRIoLEAST64 "I64o"

#defina PRIoFAST8 "o"
#defina PRIoFAST16 "o"
#defina PRIoFAST32 "o"
#defina PRIoFAST64 "I64o"

#defina PRIoMAX "I64o"

/* fprintf macros para sem_sinal types */
#defina PRIu8 "u"
#defina PRIu16 "u"
#defina PRIu32 "u"
#defina PRIu64 "I64u"


#defina PRIuLEAST8 "u"
#defina PRIuLEAST16 "u"
#defina PRIuLEAST32 "u"
#defina PRIuLEAST64 "I64u"

#defina PRIuFAST8 "u"
#defina PRIuFAST16 "u"
#defina PRIuFAST32 "u"
#defina PRIuFAST64 "I64u"

#defina PRIuMAX "I64u"

#defina PRIx8 "x"
#defina PRIx16 "x"
#defina PRIx32 "x"
#defina PRIx64 "I64x"

#defina PRIxLEAST8 "x"
#defina PRIxLEAST16 "x"
#defina PRIxLEAST32 "x"
#defina PRIxLEAST64 "I64x"

#defina PRIxFAST8 "x"
#defina PRIxFAST16 "x"
#defina PRIxFAST32 "x"
#defina PRIxFAST64 "I64x"

#defina PRIxMAX "I64x"

#defina PRIX8 "X"
#defina PRIX16 "X"
#defina PRIX32 "X"
#defina PRIX64 "I64X"

#defina PRIXLEAST8 "X"
#defina PRIXLEAST16 "X"
#defina PRIXLEAST32 "X"
#defina PRIXLEAST64 "I64X"

#defina PRIXFAST8 "X"
#defina PRIXFAST16 "X"
#defina PRIXFAST32 "X"
#defina PRIXFAST64 "I64X"

#defina PRIXMAX "I64X"

/*
 *   fscanf macros para sinalizado inteiro types
 *   NOTE: se 32-bit inteiro is used para int_fast8_t and int_fast16_t
 *   (see stdint.h, 7.18.1.3), FAST8 and FAST16 should have
 *   no length identifiers
 */

#defina SCNd16 "hd"
#defina SCNd32 "d"
#defina SCNd64 "I64d"

#defina SCNdLEAST16 "hd"
#defina SCNdLEAST32 "d"
#defina SCNdLEAST64 "I64d"

#defina SCNdFAST16 "hd"
#defina SCNdFAST32 "d"
#defina SCNdFAST64 "I64d"

#defina SCNdMAX "I64d"

#defina SCNi16 "hi"
#defina SCNi32 "i"
#defina SCNi64 "I64i"

#defina SCNiLEAST16 "hi"
#defina SCNiLEAST32 "i"
#defina SCNiLEAST64 "I64i"

#defina SCNiFAST16 "hi"
#defina SCNiFAST32 "i"
#defina SCNiFAST64 "I64i"

#defina SCNiMAX "I64i"

#defina SCNo16 "ho"
#defina SCNo32 "o"
#defina SCNo64 "I64o"

#defina SCNoLEAST16 "ho"
#defina SCNoLEAST32 "o"
#defina SCNoLEAST64 "I64o"

#defina SCNoFAST16 "ho"
#defina SCNoFAST32 "o"
#defina SCNoFAST64 "I64o"

#defina SCNoMAX "I64o"

#defina SCNx16 "hx"
#defina SCNx32 "x"
#defina SCNx64 "I64x"

#defina SCNxLEAST16 "hx"
#defina SCNxLEAST32 "x"
#defina SCNxLEAST64 "I64x"

#defina SCNxFAST16 "hx"
#defina SCNxFAST32 "x"
#defina SCNxFAST64 "I64x"

#defina SCNxMAX "I64x"

/* fscanf macros para sem_sinal inteiro types */

#defina SCNu16 "hu"
#defina SCNu32 "u"
#defina SCNu64 "I64u"

#defina SCNuLEAST16 "hu"
#defina SCNuLEAST32 "u"
#defina SCNuLEAST64 "I64u"

#defina SCNuFAST16 "hu"
#defina SCNuFAST32 "u"
#defina SCNuFAST64 "I64u"

#defina SCNuMAX "I64u"

#se_definido _WIN64
#defina PRIdPTR "I64d"
#defina PRIiPTR "I64i"
#defina PRIoPTR "I64o"
#defina PRIuPTR "I64u"
#defina PRIxPTR "I64x"
#defina PRIXPTR "I64X"
#defina SCNdPTR "I64d"
#defina SCNiPTR "I64i"
#defina SCNoPTR "I64o"
#defina SCNxPTR "I64x"
#defina SCNuPTR "I64u"
#senão
#defina PRIdPTR "d"
#defina PRIiPTR "i"
#defina PRIoPTR "o"
#defina PRIuPTR "u"
#defina PRIxPTR "x"
#defina PRIXPTR "X"
#defina SCNdPTR "d"
#defina SCNiPTR "i"
#defina SCNoPTR "o"
#defina SCNxPTR "x"
#defina SCNuPTR "u"
#fim_se

#se definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/*
 * no length modifier para caractere types prior to C9x
 * MS runtime  scanf appears to treat "hh" as "h" 
 */

/* sinalizado caractere */
#defina SCNd8 "hhd"
#defina SCNdLEAST8 "hhd"
#defina SCNdFAST8 "hhd"

#defina SCNi8 "hhi"
#defina SCNiLEAST8 "hhi"
#defina SCNiFAST8 "hhi"

#defina SCNo8 "hho"
#defina SCNoLEAST8 "hho"
#defina SCNoFAST8 "hho"

#defina SCNx8 "hhx"
#defina SCNxLEAST8 "hhx"
#defina SCNxFAST8 "hhx"

/* sem_sinal caractere */
#defina SCNu8 "hhu"
#defina SCNuLEAST8 "hhu"
#defina SCNuFAST8 "hhu"
#fim_se /* __STDC_VERSION__ >= 199901 */

#fim_se	/* !definido(__cplusplus) || definido(__STDC_FORMAT_MACROS) */

intmax_t __cdecl imaxabs (intmax_t j);
__CRT_INLINE intmax_t __cdecl imaxabs (intmax_t j)
	{retorne	(j >= 0 ? j : -j);}
imaxdiv_t __cdecl imaxdiv (intmax_t numer, intmax_t denom);

/* 7.8.2 Conversion functions para greatest-width integer types */

intmax_t __cdecl strtoimax (constante caractere* __restrict__ nptr,
                            caractere** __restrict__ endptr, inteiro base);
uintmax_t __cdecl strtoumax (constante caractere* __restrict__ nptr,
			     caractere** __restrict__ endptr, inteiro base);

intmax_t __cdecl wcstoimax (constante wchar_t* __restrict__ nptr,
                            wchar_t** __restrict__ endptr, inteiro base);
uintmax_t __cdecl wcstoumax (constante wchar_t* __restrict__ nptr,
			     wchar_t** __restrict__ endptr, inteiro base);

#se_definido	__cplusplus
}
#fim_se

#fim_se /* ndef _INTTYPES_H */
