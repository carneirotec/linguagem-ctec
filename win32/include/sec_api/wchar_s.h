/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_WCHAR_S
#defina _INC_WCHAR_S

#inclua <wchar.h>

#se definido(MINGW_HAS_SECURE_API)

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _WIO_S_DEFINED
#defina _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(constante wchar_t *_Filename,inteiro _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(wchar_t *_TemplateName,size_t _SizeInWords);
#fim_se

#se_não_definido _WCONIO_S_DEFINED
#defina _WCONIO_S_DEFINED
  _CRTIMP errno_t __cdecl _cgetws_s(wchar_t *_Buffer,size_t _SizeInWords,size_t *_SizeRead);
  _CRTIMP inteiro __cdecl _cwprintf_s(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _cwscanf_s(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _cwscanf_s_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcwprintf_s(constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _cwprintf_s_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vcwprintf_s_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#fim_se

#se_não_definido _WSTDIO_S_DEFINED
#defina _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t _SizeInWords);
  inteiro __cdecl fwprintf_s(FILE *_File,constante wchar_t *_Format,...);
  inteiro __cdecl wprintf_s(constante wchar_t *_Format,...);
  inteiro __cdecl vfwprintf_s(FILE *_File,constante wchar_t *_Format,va_list _ArgList);
  inteiro __cdecl vwprintf_s(constante wchar_t *_Format,va_list _ArgList);
  inteiro __cdecl swprintf_s(wchar_t *_Dst,size_t _SizeInWords,constante wchar_t *_Format,...);
  inteiro __cdecl vswprintf_s(wchar_t *_Dst,size_t _SizeInWords,constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _snwprintf_s(wchar_t *_DstBuf,size_t _DstSizeInWords,size_t _MaxCount,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vsnwprintf_s(wchar_t *_DstBuf,size_t _DstSizeInWords,size_t _MaxCount,constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _wprintf_s_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vwprintf_s_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _fwprintf_s_l(FILE *_File,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vfwprintf_s_l(FILE *_File,constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _swprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vswprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _snwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vsnwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _fwscanf_s_l(FILE *_File,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _swscanf_s_l(constante wchar_t *_Src,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _snwscanf_s(constante wchar_t *_Src,size_t _MaxCount,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _snwscanf_s_l(constante wchar_t *_Src,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _wscanf_s_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t __cdecl _wfopen_s(FILE **_File,constante wchar_t *_Filename,constante wchar_t *_Mode);
  _CRTIMP errno_t __cdecl _wfreopen_s(FILE **_File,constante wchar_t *_Filename,constante wchar_t *_Mode,FILE *_OldFile);
  _CRTIMP errno_t __cdecl _wtmpnam_s(wchar_t *_DstBuf,size_t _SizeInWords);
#fim_se

#se_não_definido _WSTDLIB_S_DEFINED
#defina _WSTDLIB_S_DEFINED
  _CRTIMP errno_t __cdecl _itow_s (inteiro _Val,wchar_t *_DstBuf,size_t _SizeInWords,inteiro _Radix);
  _CRTIMP errno_t __cdecl _ltow_s (longo _Val,wchar_t *_DstBuf,size_t _SizeInWords,inteiro _Radix);
  _CRTIMP errno_t __cdecl _ultow_s (sem_sinal longo _Val,wchar_t *_DstBuf,size_t _SizeInWords,inteiro _Radix);
  _CRTIMP errno_t __cdecl _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t _DstSizeInWords,constante wchar_t *_VarName);
  _CRTIMP errno_t __cdecl _wdupenv_s(wchar_t **_Buffer,size_t *_BufferSizeInWords,constante wchar_t *_VarName);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t _SizeInWords,inteiro _Radix);
  _CRTIMP errno_t __cdecl _ui64tow_s(sem_sinal __int64 _Val,wchar_t *_DstBuf,size_t _SizeInWords,inteiro _Radix);
#fim_se
#fim_se

#se_não_definido _POSIX_
#se_não_definido _WSTDLIBP_S_DEFINED
#defina _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t _SizeInWords,constante wchar_t *_Drive,constante wchar_t *_Dir,constante wchar_t *_Filename,constante wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(constante wchar_t *_Name,constante wchar_t *_Value);
  _CRTIMP errno_t __cdecl _wsearchenv_s(constante wchar_t *_Filename,constante wchar_t *_EnvVar,wchar_t *_ResultPath,size_t _SizeInWords);
  _CRTIMP errno_t __cdecl _wsplitpath_s(constante wchar_t *_FullPath,wchar_t *_Drive,size_t _DriveSizeInWords,wchar_t *_Dir,size_t _DirSizeInWords,wchar_t *_Filename,size_t _FilenameSizeInWords,wchar_t *_Ext,size_t _ExtSizeInWords);
#fim_se
#fim_se

#se_não_definido _WSTRING_S_DEFINED
#defina _WSTRING_S_DEFINED
  _CRTIMP wchar_t *__cdecl wcstok_s(wchar_t *_Str,constante wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t __cdecl _wcserror_s(wchar_t *_Buf,size_t _SizeInWords,inteiro _ErrNum);
  _CRTIMP errno_t __cdecl __wcserror_s(wchar_t *_Buffer,size_t _SizeInWords,constante wchar_t *_ErrMsg);
  _CRTIMP errno_t __cdecl _wcsnset_s(wchar_t *_Dst,size_t _DstSizeInWords,wchar_t _Val,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _wcsset_s(wchar_t *_Str,size_t _SizeInWords,wchar_t _Val);
  _CRTIMP errno_t __cdecl _wcslwr_s(wchar_t *_Str,size_t _SizeInWords);
  _CRTIMP errno_t __cdecl _wcslwr_s_l(wchar_t *_Str,size_t _SizeInWords,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wcsupr_s(wchar_t *_Str,size_t _Size);
  _CRTIMP errno_t __cdecl _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
#fim_se

#se_não_definido _WTIME_S_DEFINED
#defina _WTIME_S_DEFINED
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,size_t _SizeInWords,constante estrutura tm *_Tm);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,size_t _SizeInWords,constante __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,size_t _SizeInWords);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,size_t _SizeInWords);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,size_t _SizeInWords,constante __time64_t *_Time);
#fim_se

#se !definido (RC_INVOKED) && !definido (_INC_WTIME_S_INL)
#defina _INC_WTIME_S_INL
#se_definido _USE_32BIT_TIME_T
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t _SizeInWords,constante time_t *_Time) { retorne _wctime32_s(_Buffer,_SizeInWords,_Time); }
#senão
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t _SizeInWords,constante time_t *_Time) { retorne _wctime64_s(_Buffer,_SizeInWords,_Time); }
#fim_se
#fim_se
#fim_se

  _CRTIMP errno_t __cdecl mbsrtowcs_s(size_t *_Retval,wchar_t *_Dst,size_t _SizeInWords,constante caractere **_PSrc,size_t _N,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcrtomb_s(size_t *_Retval,caractere *_Dst,size_t _SizeInBytes,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t __cdecl wcsrtombs_s(size_t *_Retval,caractere *_Dst,size_t _SizeInBytes,constante wchar_t **_Src,size_t _Size,mbstate_t *_State);

#se_definido __cplusplus
}
#fim_se

#fim_se
#fim_se
