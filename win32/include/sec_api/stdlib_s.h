/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_STDLIB_S
#defina _INC_STDLIB_S

#inclua <stdlib.h>

#se definido(MINGW_HAS_SECURE_API)

#se_definido __cplusplus
externo "C" {
#fim_se

  _CRTIMP errno_t __cdecl _dupenv_s(caractere **_PBuffer,size_t *_PBufferSizeInBytes,constante caractere *_VarName);
  _CRTIMP errno_t __cdecl _itoa_s(inteiro _Value,caractere *_DstBuf,size_t _Size,inteiro _Radix);
#se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t __cdecl _i64toa_s(__int64 _Val,caractere *_DstBuf,size_t _Size,inteiro _Radix);
  _CRTIMP errno_t __cdecl _ui64toa_s(sem_sinal __int64 _Val,caractere *_DstBuf,size_t _Size,inteiro _Radix);
#fim_se
  _CRTIMP errno_t __cdecl _ltoa_s(longo _Val,caractere *_DstBuf,size_t _Size,inteiro _Radix);
  _CRTIMP errno_t __cdecl mbstowcs_s(size_t *_PtNumOfCharConverted,wchar_t *_DstBuf,size_t _SizeInWords,constante caractere *_SrcBuf,size_t _MaxCount);
  _CRTIMP errno_t __cdecl _mbstowcs_s_l(size_t *_PtNumOfCharConverted,wchar_t *_DstBuf,size_t _SizeInWords,constante caractere *_SrcBuf,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _ultoa_s(sem_sinal longo _Val,caractere *_DstBuf,size_t _Size,inteiro _Radix);
  _CRTIMP errno_t __cdecl _wctomb_s_l(inteiro *_SizeConverted,caractere *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  _CRTIMP errno_t __cdecl wcstombs_s(size_t *_PtNumOfCharConverted,caractere *_Dst,size_t _DstSizeInBytes,constante wchar_t *_Src,size_t _MaxCountInBytes);
  _CRTIMP errno_t __cdecl _wcstombs_s_l(size_t *_PtNumOfCharConverted,caractere *_Dst,size_t _DstSizeInBytes,constante wchar_t *_Src,size_t _MaxCountInBytes,_locale_t _Locale);

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
  _CRTIMP errno_t __cdecl _ecvt_s(caractere *_DstBuf,size_t _Size,duplo _Val,inteiro _NumOfDights,inteiro *_PtDec,inteiro *_PtSign);
  _CRTIMP errno_t __cdecl _fcvt_s(caractere *_DstBuf,size_t _Size,duplo _Val,inteiro _NumOfDec,inteiro *_PtDec,inteiro *_PtSign);
  _CRTIMP errno_t __cdecl _gcvt_s(caractere *_DstBuf,size_t _Size,duplo _Val,inteiro _NumOfDigits);
  _CRTIMP errno_t __cdecl _makepath_s(caractere *_PathResult,size_t _Size,constante caractere *_Drive,constante caractere *_Dir,constante caractere *_Filename,constante caractere *_Ext);
  _CRTIMP errno_t __cdecl _putenv_s(constante caractere *_Name,constante caractere *_Value);
  _CRTIMP errno_t __cdecl _searchenv_s(constante caractere *_Filename,constante caractere *_EnvVar,caractere *_ResultPath,size_t _SizeInBytes);
  _CRTIMP errno_t __cdecl _splitpath_s(constante caractere *_FullPath,caractere *_Drive,size_t _DriveSize,caractere *_Dir,size_t _DirSize,caractere *_Filename,size_t _FilenameSize,caractere *_Ext,size_t _ExtSize);

#se_não_definido _WSTDLIBP_S_DEFINED
#defina _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t __cdecl _wmakepath_s(wchar_t *_PathResult,size_t _SizeInWords,constante wchar_t *_Drive,constante wchar_t *_Dir,constante wchar_t *_Filename,constante wchar_t *_Ext);
  _CRTIMP errno_t __cdecl _wputenv_s(constante wchar_t *_Name,constante wchar_t *_Value);
  _CRTIMP errno_t __cdecl _wsearchenv_s(constante wchar_t *_Filename,constante wchar_t *_EnvVar,wchar_t *_ResultPath,size_t _SizeInWords);
  _CRTIMP errno_t __cdecl _wsplitpath_s(constante wchar_t *_FullPath,wchar_t *_Drive,size_t _DriveSizeInWords,wchar_t *_Dir,size_t _DirSizeInWords,wchar_t *_Filename,size_t _FilenameSizeInWords,wchar_t *_Ext,size_t _ExtSizeInWords);
#fim_se
#fim_se

#se_definido __cplusplus
}
#fim_se

#fim_se
#fim_se
