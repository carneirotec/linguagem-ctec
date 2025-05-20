/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_STDIO_S
#defina _INC_STDIO_S

#inclua <stdio.h>

#se definido(MINGW_HAS_SECURE_API)

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _STDIO_S_DEFINED
#defina _STDIO_S_DEFINED
  _CRTIMP errno_t __cdecl clearerr_s(FILE *_File);
  inteiro __cdecl fprintf_s(FILE *_File,constante caractere *_Format,...);
  size_t __cdecl fread_s(vazio *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File);
  _CRTIMP inteiro __cdecl _fscanf_s_l(FILE *_File,constante caractere *_Format,_locale_t _Locale,...);
  inteiro __cdecl printf_s(constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _scanf_l(constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _scanf_s_l(constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _snprintf_s(caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _snprintf_c(caractere *_DstBuf,size_t _MaxCount,constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _vsnprintf_c(caractere *_DstBuf,size_t _MaxCount,constante caractere *_Format,va_list _ArgList);
  inteiro __cdecl sprintf_s(caractere *_DstBuf,size_t _DstSize,constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _fscanf_l(FILE *_File,constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _sscanf_l(constante caractere *_Src,constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _sscanf_s_l(constante caractere *_Src,constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _snscanf_s(constante caractere *_Src,size_t _MaxCount,constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _snscanf_l(constante caractere *_Src,size_t _MaxCount,constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _snscanf_s_l(constante caractere *_Src,size_t _MaxCount,constante caractere *_Format,_locale_t _Locale,...);
  inteiro __cdecl vfprintf_s(FILE *_File,constante caractere *_Format,va_list _ArgList);
  inteiro __cdecl vprintf_s(constante caractere *_Format,va_list _ArgList);
  inteiro __cdecl vsnprintf_s(caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,constante caractere *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vsnprintf_s(caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,constante caractere *_Format,va_list _ArgList);
  inteiro __cdecl vsprintf_s(caractere *_DstBuf,size_t _Size,constante caractere *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _fprintf_p(FILE *_File,constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _printf_p(constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _sprintf_p(caractere *_Dst,size_t _MaxCount,constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _vfprintf_p(FILE *_File,constante caractere *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vprintf_p(constante caractere *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vsprintf_p(caractere *_Dst,size_t _MaxCount,constante caractere *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _scprintf_p(constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _vscprintf_p(constante caractere *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _printf_l(constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _printf_p_l(constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vprintf_l(constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vprintf_p_l(constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _fprintf_l(FILE *_File,constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _fprintf_p_l(FILE *_File,constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vfprintf_l(FILE *_File,constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vfprintf_p_l(FILE *_File,constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _sprintf_l(caractere *_DstBuf,constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _sprintf_p_l(caractere *_DstBuf,size_t _MaxCount,constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vsprintf_l(caractere *_DstBuf,constante caractere *_Format,_locale_t,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vsprintf_p_l(caractere *_DstBuf,size_t _MaxCount,constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _scprintf_l(constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _scprintf_p_l(constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vscprintf_l(constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vscprintf_p_l(constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _printf_s_l(constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vprintf_s_l(constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _fprintf_s_l(FILE *_File,constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vfprintf_s_l(FILE *_File,constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _sprintf_s_l(caractere *_DstBuf,size_t _DstSize,constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vsprintf_s_l(caractere *_DstBuf,size_t _DstSize,constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _snprintf_s_l(caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vsnprintf_s_l(caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _snprintf_l(caractere *_DstBuf,size_t _MaxCount,constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _snprintf_c_l(caractere *_DstBuf,size_t _MaxCount,constante caractere *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vsnprintf_l(caractere *_DstBuf,size_t _MaxCount,constante caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vsnprintf_c_l(caractere *_DstBuf,size_t _MaxCount,constante caractere *,_locale_t _Locale,va_list _ArgList);

#se_não_definido _WSTDIO_S_DEFINED
#defina _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *__cdecl _getws_s(wchar_t *_Str,size_t _SizeInWords);
  inteiro __cdecl fwprintf_s(FILE *_File,constante wchar_t *_Format,...);
  inteiro __cdecl wprintf_s(constante wchar_t *_Format,...);
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
  _CRTIMP inteiro __cdecl _fwprintf_p(FILE *_File,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _wprintf_p(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vfwprintf_p(FILE *_File,constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vwprintf_p(constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _swprintf_p(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vswprintf_p(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _scwprintf_p(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vscwprintf_p(constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _wprintf_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _wprintf_p_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vwprintf_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vwprintf_p_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _fwprintf_l(FILE *_File,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _fwprintf_p_l(FILE *_File,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vfwprintf_l(FILE *_File,constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vfwprintf_p_l(FILE *_File,constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _swprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _swprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vswprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _vswprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _scwprintf_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _scwprintf_p_l(constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vscwprintf_p_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _snwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl __swprintf_l(wchar_t *_Dest,constante wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP inteiro __cdecl __vswprintf_l(wchar_t *_Dest,constante wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  _CRTIMP inteiro __cdecl _vscwprintf_l(constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP inteiro __cdecl _fwscanf_l(FILE *_File,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _swscanf_l(constante wchar_t *_Src,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _snwscanf_l(constante wchar_t *_Src,size_t _MaxCount,constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP inteiro __cdecl _wscanf_l(constante wchar_t *_Format,_locale_t _Locale,...);
#fim_se
#fim_se

  _CRTIMP size_t __cdecl _fread_nolock_s(vazio *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File);

#se_definido __cplusplus
}
#fim_se
#fim_se
#fim_se
