/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido VER_H
#defina VER_H

#se_definido __cplusplus
externo "C" {
#fim_se

#defina VS_FILE_INFO RT_VERSION
#defina VS_VERSION_INFO 1
#defina VS_USER_DEFINED 100

#defina VS_FFI_SIGNATURE 0xFEEF04BDL
#defina VS_FFI_STRUCVERSION 0x00010000L
#defina VS_FFI_FILEFLAGSMASK 0x0000003FL

#defina VS_FF_DEBUG 0x00000001L
#defina VS_FF_PRERELEASE 0x00000002L
#defina VS_FF_PATCHED 0x00000004L
#defina VS_FF_PRIVATEBUILD 0x00000008L
#defina VS_FF_INFOINFERRED 0x00000010L
#defina VS_FF_SPECIALBUILD 0x00000020L

#defina VOS_UNKNOWN 0x00000000L
#defina VOS_DOS 0x00010000L
#defina VOS_OS216 0x00020000L
#defina VOS_OS232 0x00030000L
#defina VOS_NT 0x00040000L
#defina VOS_WINCE 0x00050000L

#defina VOS__BASE 0x00000000L
#defina VOS__WINDOWS16 0x00000001L
#defina VOS__PM16 0x00000002L
#defina VOS__PM32 0x00000003L
#defina VOS__WINDOWS32 0x00000004L

#defina VOS_DOS_WINDOWS16 0x00010001L
#defina VOS_DOS_WINDOWS32 0x00010004L
#defina VOS_OS216_PM16 0x00020002L
#defina VOS_OS232_PM32 0x00030003L
#defina VOS_NT_WINDOWS32 0x00040004L

#defina VFT_UNKNOWN 0x00000000L
#defina VFT_APP 0x00000001L
#defina VFT_DLL 0x00000002L
#defina VFT_DRV 0x00000003L
#defina VFT_FONT 0x00000004L
#defina VFT_VXD 0x00000005L
#defina VFT_STATIC_LIB 0x00000007L

#defina VFT2_UNKNOWN 0x00000000L
#defina VFT2_DRV_PRINTER 0x00000001L
#defina VFT2_DRV_KEYBOARD 0x00000002L
#defina VFT2_DRV_LANGUAGE 0x00000003L
#defina VFT2_DRV_DISPLAY 0x00000004L
#defina VFT2_DRV_MOUSE 0x00000005L
#defina VFT2_DRV_NETWORK 0x00000006L
#defina VFT2_DRV_SYSTEM 0x00000007L
#defina VFT2_DRV_INSTALLABLE 0x00000008L
#defina VFT2_DRV_SOUND 0x00000009L
#defina VFT2_DRV_COMM 0x0000000AL
#defina VFT2_DRV_INPUTMETHOD 0x0000000BL
#defina VFT2_DRV_VERSIONED_PRINTER 0x0000000CL

#defina VFT2_FONT_RASTER 0x00000001L
#defina VFT2_FONT_VECTOR 0x00000002L
#defina VFT2_FONT_TRUETYPE 0x00000003L

#defina VFFF_ISSHAREDFILE 0x0001

#defina VFF_CURNEDEST 0x0001
#defina VFF_FILEINUSE 0x0002
#defina VFF_BUFFTOOSMALL 0x0004

#defina VIFF_FORCEINSTALL 0x0001
#defina VIFF_DONTDELETEOLD 0x0002

#defina VIF_TEMPFILE 0x00000001L
#defina VIF_MISMATCH 0x00000002L
#defina VIF_SRCOLD 0x00000004L

#defina VIF_DIFFLANG 0x00000008L
#defina VIF_DIFFCODEPG 0x00000010L
#defina VIF_DIFFTYPE 0x00000020L

#defina VIF_WRITEPROT 0x00000040L
#defina VIF_FILEINUSE 0x00000080L
#defina VIF_OUTOFSPACE 0x00000100L
#defina VIF_ACCESSVIOLATION 0x00000200L
#defina VIF_SHARINGVIOLATION 0x00000400L
#defina VIF_CANNOTCREATE 0x00000800L
#defina VIF_CANNOTDELETE 0x00001000L
#defina VIF_CANNOTRENAME 0x00002000L
#defina VIF_CANNOTDELETECUR 0x00004000L
#defina VIF_OUTOFMEMORY 0x00008000L

#defina VIF_CANNOTREADSRC 0x00010000L
#defina VIF_CANNOTREADDST 0x00020000L

#defina VIF_BUFFTOOSMALL 0x00040000L
#defina VIF_CANNOTLOADLZ32 0x00080000L
#defina VIF_CANNOTLOADCABINET 0x00100000L

#se_não_definido RC_INVOKED

  defina_tipo estrutura tagVS_FIXEDFILEINFO
  {
    DWORD dwSignature;
    DWORD dwStrucVersion;
    DWORD dwFileVersionMS;
    DWORD dwFileVersionLS;
    DWORD dwProductVersionMS;
    DWORD dwProductVersionLS;
    DWORD dwFileFlagsMask;
    DWORD dwFileFlags;
    DWORD dwFileOS;
    DWORD dwFileType;
    DWORD dwFileSubtype;
    DWORD dwFileDateMS;
    DWORD dwFileDateLS;
  } VS_FIXEDFILEINFO;

#se_definido UNICODE
#defina VerFindFile VerFindFileW
#defina VerInstallFile VerInstallFileW
#defina GetFileVersionInfoSize GetFileVersionInfoSizeW
#defina GetFileVersionInfo GetFileVersionInfoW
#defina VerLanguageName VerLanguageNameW
#defina VerQueryValue VerQueryValueW
#senão
#defina VerFindFile VerFindFileA
#defina VerInstallFile VerInstallFileA
#defina GetFileVersionInfoSize GetFileVersionInfoSizeA
#defina GetFileVersionInfo GetFileVersionInfoA
#defina VerLanguageName VerLanguageNameA
#defina VerQueryValue VerQueryValueA
#fim_se

  DWORD WINAPI VerFindFileA(DWORD uFlags,LPSTR szFileName,LPSTR szWinDir,LPSTR szAppDir,LPSTR szCurDir,PUINT lpuCurDirLen,LPSTR szDestDir,PUINT lpuDestDirLen);
  DWORD WINAPI VerFindFileW(DWORD uFlags,LPWSTR szFileName,LPWSTR szWinDir,LPWSTR szAppDir,LPWSTR szCurDir,PUINT lpuCurDirLen,LPWSTR szDestDir,PUINT lpuDestDirLen);
  DWORD WINAPI VerInstallFileA(DWORD uFlags,LPSTR szSrcFileName,LPSTR szDestFileName,LPSTR szSrcDir,LPSTR szDestDir,LPSTR szCurDir,LPSTR szTmpFile,PUINT lpuTmpFileLen);
  DWORD WINAPI VerInstallFileW(DWORD uFlags,LPWSTR szSrcFileName,LPWSTR szDestFileName,LPWSTR szSrcDir,LPWSTR szDestDir,LPWSTR szCurDir,LPWSTR szTmpFile,PUINT lpuTmpFileLen);
  DWORD WINAPI GetFileVersionInfoSizeA(LPCSTR lptstrFilename,LPDWORD lpdwHandle);
  DWORD WINAPI GetFileVersionInfoSizeW(LPCWSTR lptstrFilename,LPDWORD lpdwHandle);
  WINBOOL WINAPI GetFileVersionInfoA(LPCSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lpData);
  WINBOOL WINAPI GetFileVersionInfoW(LPCWSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lpData);
  DWORD WINAPI VerLanguageNameA(DWORD wLang,LPSTR szLang,DWORD nSize);
  DWORD WINAPI VerLanguageNameW(DWORD wLang,LPWSTR szLang,DWORD nSize);
  WINBOOL WINAPI VerQueryValueA(constante LPVOID pBlock,LPSTR lpSubBlock,LPVOID *lplpBuffer,PUINT puLen);
  WINBOOL WINAPI VerQueryValueW(constante LPVOID pBlock,LPWSTR lpSubBlock,LPVOID *lplpBuffer,PUINT puLen);
#fim_se

#se_definido __cplusplus
}
#fim_se
#fim_se
