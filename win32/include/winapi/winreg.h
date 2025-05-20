/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _WINREG_
#defina _WINREG_

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido WINVER
#defina WINVER 0x0502
#fim_se

#defina RRF_RT_REG_NONE 0x00000001
#defina RRF_RT_REG_SZ 0x00000002
#defina RRF_RT_REG_EXPAND_SZ 0x00000004
#defina RRF_RT_REG_BINARY 0x00000008
#defina RRF_RT_REG_DWORD 0x00000010
#defina RRF_RT_REG_MULTI_SZ 0x00000020
#defina RRF_RT_REG_QWORD 0x00000040

#defina RRF_RT_DWORD (RRF_RT_REG_BINARY | RRF_RT_REG_DWORD)
#defina RRF_RT_QWORD (RRF_RT_REG_BINARY | RRF_RT_REG_QWORD)
#defina RRF_RT_ANY 0x0000ffff

#defina RRF_NOEXPAND 0x10000000
#defina RRF_ZEROONFAILURE 0x20000000

  defina_tipo ACCESS_MASK REGSAM;

#defina HKEY_CLASSES_ROOT ((HKEY) (ULONG_PTR)((LONG)0x80000000))
#defina HKEY_CURRENT_USER ((HKEY) (ULONG_PTR)((LONG)0x80000001))
#defina HKEY_LOCAL_MACHINE ((HKEY) (ULONG_PTR)((LONG)0x80000002))
#defina HKEY_USERS ((HKEY) (ULONG_PTR)((LONG)0x80000003))
#defina HKEY_PERFORMANCE_DATA ((HKEY) (ULONG_PTR)((LONG)0x80000004))
#defina HKEY_PERFORMANCE_TEXT ((HKEY) (ULONG_PTR)((LONG)0x80000050))
#defina HKEY_PERFORMANCE_NLSTEXT ((HKEY) (ULONG_PTR)((LONG)0x80000060))
#defina HKEY_CURRENT_CONFIG ((HKEY) (ULONG_PTR)((LONG)0x80000005))
#defina HKEY_DYN_DATA ((HKEY) (ULONG_PTR)((LONG)0x80000006))

#defina REG_SECURE_CONNECTION 1

#se_não_definido _PROVIDER_STRUCTS_DEFINED
#defina _PROVIDER_STRUCTS_DEFINED

#defina PROVIDER_KEEPS_VALUE_LENGTH 0x1
  estrutura val_context {
    inteiro valuelen;
    LPVOID value_context;
    LPVOID val_buff_ptr;
  };

  defina_tipo estrutura val_context *PVALCONTEXT;

  defina_tipo estrutura pvalueA {
    LPSTR pv_valuename;
    inteiro pv_valuelen;
    LPVOID pv_value_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  defina_tipo estrutura pvalueW {
    LPWSTR pv_valuename;
    inteiro pv_valuelen;
    LPVOID pv_value_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#se_definido UNICODE
  defina_tipo PVALUEW PVALUE;
  defina_tipo PPVALUEW PPVALUE;
#senão
  defina_tipo PVALUEA PVALUE;
  defina_tipo PPVALUEA PPVALUE;
#fim_se

  defina_tipo DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD num_vals,LPVOID outputbuffer,DWORD *total_outlen,DWORD input_blen);

  defina_tipo QUERYHANDLER *PQUERYHANDLER;

  defina_tipo estrutura provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_key_context;
  } REG_PROVIDER;

  defina_tipo estrutura provider_info *PPROVIDER;

  defina_tipo estrutura value_entA {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  defina_tipo estrutura value_entW {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#se_definido UNICODE
  defina_tipo VALENTW VALENT;
  defina_tipo PVALENTW PVALENT;
#senão
  defina_tipo VALENTA VALENT;
  defina_tipo PVALENTA PVALENT;
#fim_se
#fim_se

#defina WIN31_CLASS NULL

#se_definido UNICODE
#defina RegConnectRegistry RegConnectRegistryW
#defina RegConnectRegistryEx RegConnectRegistryExW
#defina RegCreateKey RegCreateKeyW
#defina RegCreateKeyEx RegCreateKeyExW
#defina RegDeleteKey RegDeleteKeyW
#defina RegDeleteKeyEx RegDeleteKeyExW
#defina RegDeleteValue RegDeleteValueW
#defina RegEnumKey RegEnumKeyW
#defina RegEnumKeyEx RegEnumKeyExW
#defina RegEnumValue RegEnumValueW
#defina RegLoadKey RegLoadKeyW
#defina RegOpenKey RegOpenKeyW
#defina RegOpenKeyEx RegOpenKeyExW
#defina RegQueryInfoKey RegQueryInfoKeyW
#defina RegQueryValue RegQueryValueW
#defina RegQueryMultipleValues RegQueryMultipleValuesW
#defina RegQueryValueEx RegQueryValueExW
#defina RegReplaceKey RegReplaceKeyW
#defina RegRestoreKey RegRestoreKeyW
#defina RegSaveKey RegSaveKeyW
#defina RegSetValue RegSetValueW
#defina RegSetValueEx RegSetValueExW
#defina RegUnLoadKey RegUnLoadKeyW
#defina RegGetValue RegGetValueW
#defina InitiateSystemShutdown InitiateSystemShutdownW
#defina AbortSystemShutdown AbortSystemShutdownW
#senão
#defina RegConnectRegistry RegConnectRegistryA
#defina RegConnectRegistryEx RegConnectRegistryExA
#defina RegCreateKey RegCreateKeyA
#defina RegCreateKeyEx RegCreateKeyExA
#defina RegDeleteKey RegDeleteKeyA
#defina RegDeleteKeyEx RegDeleteKeyExA
#defina RegDeleteValue RegDeleteValueA
#defina RegEnumKey RegEnumKeyA
#defina RegEnumKeyEx RegEnumKeyExA
#defina RegEnumValue RegEnumValueA
#defina RegLoadKey RegLoadKeyA
#defina RegOpenKey RegOpenKeyA
#defina RegOpenKeyEx RegOpenKeyExA
#defina RegQueryInfoKey RegQueryInfoKeyA
#defina RegQueryValue RegQueryValueA
#defina RegQueryMultipleValues RegQueryMultipleValuesA
#defina RegQueryValueEx RegQueryValueExA
#defina RegReplaceKey RegReplaceKeyA
#defina RegRestoreKey RegRestoreKeyA
#defina RegSaveKey RegSaveKeyA
#defina RegSetValue RegSetValueA
#defina RegSetValueEx RegSetValueExA
#defina RegUnLoadKey RegUnLoadKeyA
#defina RegGetValue RegGetValueA
#defina InitiateSystemShutdown InitiateSystemShutdownA
#defina AbortSystemShutdown AbortSystemShutdownA
#fim_se

  WINADVAPI LONG WINAPI RegCloseKey(HKEY hKey);
  WINADVAPI LONG WINAPI RegOverridePredefKey(HKEY hKey,HKEY hNewHKey);
  WINADVAPI LONG WINAPI RegOpenUserClassesRoot(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY hKey,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY hKey,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY hKey,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY hKey,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegCreateKeyA(HKEY hKey,LPCSTR lpSubKey,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegCreateKeyW(HKEY hKey,LPCWSTR lpSubKey,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegCreateKeyExA(HKEY hKey,LPCSTR lpSubKey,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI RegCreateKeyExW(HKEY hKey,LPCWSTR lpSubKey,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI RegDeleteKeyA(HKEY hKey,LPCSTR lpSubKey);
  WINADVAPI LONG WINAPI RegDeleteKeyW(HKEY hKey,LPCWSTR lpSubKey);
  WINADVAPI LONG WINAPI RegDeleteKeyExA(HKEY hKey,LPCSTR lpSubKey,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI RegDeleteKeyExW(HKEY hKey,LPCWSTR lpSubKey,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI RegDisableReflectionKey(HKEY hBase);
  WINADVAPI LONG WINAPI RegEnableReflectionKey(HKEY hBase);
  WINADVAPI LONG WINAPI RegQueryReflectionKey(HKEY hBase,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI RegDeleteValueA(HKEY hKey,LPCSTR lpValueName);
  WINADVAPI LONG WINAPI RegDeleteValueW(HKEY hKey,LPCWSTR lpValueName);
  WINADVAPI LONG WINAPI RegEnumKeyA(HKEY hKey,DWORD dwIndex,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI RegEnumKeyW(HKEY hKey,DWORD dwIndex,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI RegEnumKeyExA(HKEY hKey,DWORD dwIndex,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI RegEnumKeyExW(HKEY hKey,DWORD dwIndex,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI RegEnumValueA(HKEY hKey,DWORD dwIndex,LPSTR lpValueName,LPDWORD lpcchValueName,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI RegEnumValueW(HKEY hKey,DWORD dwIndex,LPWSTR lpValueName,LPDWORD lpcchValueName,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI RegFlushKey(HKEY hKey);
  WINADVAPI LONG WINAPI RegGetKeySecurity(HKEY hKey,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI RegLoadKeyA(HKEY hKey,LPCSTR lpSubKey,LPCSTR lpFile);
  WINADVAPI LONG WINAPI RegLoadKeyW(HKEY hKey,LPCWSTR lpSubKey,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI RegNotifyChangeKeyValue(HKEY hKey,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI RegOpenKeyA(HKEY hKey,LPCSTR lpSubKey,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenKeyW(HKEY hKey,LPCWSTR lpSubKey,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenKeyExA(HKEY hKey,LPCSTR lpSubKey,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenKeyExW(HKEY hKey,LPCWSTR lpSubKey,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegQueryInfoKeyA(HKEY hKey,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpcSubKeys,LPDWORD lpcbMaxSubKeyLen,LPDWORD lpcbMaxClassLen,LPDWORD lpcValues,LPDWORD lpcbMaxValueNameLen,LPDWORD lpcbMaxValueLen,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI RegQueryInfoKeyW(HKEY hKey,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpcSubKeys,LPDWORD lpcbMaxSubKeyLen,LPDWORD lpcbMaxClassLen,LPDWORD lpcValues,LPDWORD lpcbMaxValueNameLen,LPDWORD lpcbMaxValueLen,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI RegQueryValueA(HKEY hKey,LPCSTR lpSubKey,LPSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI RegQueryValueW(HKEY hKey,LPCWSTR lpSubKey,LPWSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI RegQueryMultipleValuesA(HKEY hKey,PVALENTA val_list,DWORD num_vals,LPSTR lpValueBuf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI RegQueryMultipleValuesW(HKEY hKey,PVALENTW val_list,DWORD num_vals,LPWSTR lpValueBuf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI RegQueryValueExA(HKEY hKey,LPCSTR lpValueName,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI RegQueryValueExW(HKEY hKey,LPCWSTR lpValueName,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI RegReplaceKeyA(HKEY hKey,LPCSTR lpSubKey,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI RegReplaceKeyW(HKEY hKey,LPCWSTR lpSubKey,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI RegRestoreKeyA(HKEY hKey,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI RegRestoreKeyW(HKEY hKey,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI RegSaveKeyA(HKEY hKey,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI RegSaveKeyW(HKEY hKey,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI RegSetKeySecurity(HKEY hKey,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI RegSetValueA(HKEY hKey,LPCSTR lpSubKey,DWORD dwType,LPCSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI RegSetValueW(HKEY hKey,LPCWSTR lpSubKey,DWORD dwType,LPCWSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI RegSetValueExA(HKEY hKey,LPCSTR lpValueName,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI RegSetValueExW(HKEY hKey,LPCWSTR lpValueName,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI RegUnLoadKeyA(HKEY hKey,LPCSTR lpSubKey);
  WINADVAPI LONG WINAPI RegUnLoadKeyW(HKEY hKey,LPCWSTR lpSubKey);
  WINADVAPI LONG WINAPI RegGetValueA(HKEY hkey,LPCSTR lpSubKey,LPCSTR lpValue,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
  WINADVAPI LONG WINAPI RegGetValueW(HKEY hkey,LPCWSTR lpSubKey,LPCWSTR lpValue,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownA(LPSTR lpMachineName);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownW(LPWSTR lpMachineName);

//gr #inclua <reason.h>

#defina REASON_SWINSTALL SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION
#defina REASON_HWINSTALL SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION
#defina REASON_SERVICEHANG SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG
#defina REASON_UNSTABLE SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE
#defina REASON_SWHWRECONF SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG
#defina REASON_OTHER SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER
#defina REASON_UNKNOWN SHTDN_REASON_UNKNOWN
#defina REASON_LEGACY_API SHTDN_REASON_LEGACY_API
#defina REASON_PLANNED_FLAG SHTDN_REASON_FLAG_PLANNED

#defina MAX_SHUTDOWN_TIMEOUT (10*365*24*60*60)

#se_definido UNICODE
#defina InitiateSystemShutdownEx InitiateSystemShutdownExW
#defina RegSaveKeyEx RegSaveKeyExW
#senão
#defina InitiateSystemShutdownEx InitiateSystemShutdownExA
#defina RegSaveKeyEx RegSaveKeyExA
#fim_se

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI RegSaveKeyExA(HKEY hKey,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI RegSaveKeyExW(HKEY hKey,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64Win32ApiEntry (DWORD dwFuncNumber,DWORD dwFlag,DWORD dwRes);

#se_definido __cplusplus
}
#fim_se
#fim_se
