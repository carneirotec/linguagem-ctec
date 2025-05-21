/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _WINBASE_
#defina _WINBASE_

#defina WINADVAPI DECLSPEC_IMPORT
#defina WINBASEAPI DECLSPEC_IMPORT
#defina ZAWPROXYAPI DECLSPEC_IMPORT

#se_definido __cplusplus
externo "C" {
#fim_se

#defina DefineHandleTable(w) ((w),TRUE)
#defina LimitEmsPages(dw)
#defina SetSwapAreaSize(w) (w)
#defina LockSegment(w) GlobalFix((HANDLE)(w))
#defina UnlockSegment(w) GlobalUnfix((HANDLE)(w))
#defina GetCurrentTime() GetTickCount()

#defina Yield()

#defina INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
#defina INVALID_FILE_SIZE ((DWORD)0xffffffff)
#defina INVALID_SET_FILE_POINTER ((DWORD)-1)
#defina INVALID_FILE_ATTRIBUTES ((DWORD)-1)

#defina FILE_BEGIN 0
#defina FILE_CURRENT 1
#defina FILE_END 2

#defina TIME_ZONE_ID_INVALID ((DWORD)0xffffffff)

#defina WAIT_FAILED ((DWORD)0xffffffff)
#defina WAIT_OBJECT_0 ((STATUS_WAIT_0) + 0)
#defina WAIT_ABANDONED ((STATUS_ABANDONED_WAIT_0) + 0)
#defina WAIT_ABANDONED_0 ((STATUS_ABANDONED_WAIT_0) + 0)
#defina WAIT_IO_COMPLETION STATUS_USER_APC
#defina STILL_ACTIVE STATUS_PENDING
#defina EXCEPTION_ACCESS_VIOLATION STATUS_ACCESS_VIOLATION
#defina EXCEPTION_DATATYPE_MISALIGNMENT STATUS_DATATYPE_MISALIGNMENT
#defina EXCEPTION_BREAKPOINT STATUS_BREAKPOINT
#defina EXCEPTION_SINGLE_STEP STATUS_SINGLE_STEP
#defina EXCEPTION_ARRAY_BOUNDS_EXCEEDED STATUS_ARRAY_BOUNDS_EXCEEDED
#defina EXCEPTION_FLT_DENORMAL_OPERAND STATUS_FLOAT_DENORMAL_OPERAND
#defina EXCEPTION_FLT_DIVIDE_BY_ZERO STATUS_FLOAT_DIVIDE_BY_ZERO
#defina EXCEPTION_FLT_INEXACT_RESULT STATUS_FLOAT_INEXACT_RESULT
#defina EXCEPTION_FLT_INVALID_OPERATION STATUS_FLOAT_INVALID_OPERATION
#defina EXCEPTION_FLT_OVERFLOW STATUS_FLOAT_OVERFLOW
#defina EXCEPTION_FLT_STACK_CHECK STATUS_FLOAT_STACK_CHECK
#defina EXCEPTION_FLT_UNDERFLOW STATUS_FLOAT_UNDERFLOW
#defina EXCEPTION_INT_DIVIDE_BY_ZERO STATUS_INTEGER_DIVIDE_BY_ZERO
#defina EXCEPTION_INT_OVERFLOW STATUS_INTEGER_OVERFLOW
#defina EXCEPTION_PRIV_INSTRUCTION STATUS_PRIVILEGED_INSTRUCTION
#defina EXCEPTION_IN_PAGE_ERROR STATUS_IN_PAGE_ERROR
#defina EXCEPTION_ILLEGAL_INSTRUCTION STATUS_ILLEGAL_INSTRUCTION
#defina EXCEPTION_NONCONTINUABLE_EXCEPTION STATUS_NONCONTINUABLE_EXCEPTION
#defina EXCEPTION_STACK_OVERFLOW STATUS_STACK_OVERFLOW
#defina EXCEPTION_INVALID_DISPOSITION STATUS_INVALID_DISPOSITION
#defina EXCEPTION_GUARD_PAGE STATUS_GUARD_PAGE_VIOLATION
#defina EXCEPTION_INVALID_HANDLE STATUS_INVALID_HANDLE
#defina EXCEPTION_POSSIBLE_DEADLOCK STATUS_POSSIBLE_DEADLOCK
#defina CONTROL_C_EXIT STATUS_CONTROL_C_EXIT
#defina MoveMemory RtlMoveMemory
#defina CopyMemory RtlCopyMemory
#defina FillMemory RtlFillMemory
#defina ZeroMemory RtlZeroMemory
#defina SecureZeroMemory RtlSecureZeroMemory

#defina FILE_FLAG_WRITE_THROUGH 0x80000000
#defina FILE_FLAG_OVERLAPPED 0x40000000
#defina FILE_FLAG_NO_BUFFERING 0x20000000
#defina FILE_FLAG_RANDOM_ACCESS 0x10000000
#defina FILE_FLAG_SEQUENTIAL_SCAN 0x8000000
#defina FILE_FLAG_DELETE_ON_CLOSE 0x4000000
#defina FILE_FLAG_BACKUP_SEMANTICS 0x2000000
#defina FILE_FLAG_POSIX_SEMANTICS 0x1000000
#defina FILE_FLAG_OPEN_REPARSE_POINT 0x200000
#defina FILE_FLAG_OPEN_NO_RECALL 0x100000
#defina FILE_FLAG_FIRST_PIPE_INSTANCE 0x80000

#defina CREATE_NEW 1
#defina CREATE_ALWAYS 2
#defina OPEN_EXISTING 3
#defina OPEN_ALWAYS 4
#defina TRUNCATE_EXISTING 5

#defina PROGRESS_CONTINUE 0
#defina PROGRESS_CANCEL 1
#defina PROGRESS_STOP 2
#defina PROGRESS_QUIET 3

#defina CALLBACK_CHUNK_FINISHED 0x0
#defina CALLBACK_STREAM_SWITCH 0x1

#defina COPY_FILE_FAIL_IF_EXISTS 0x1
#defina COPY_FILE_RESTARTABLE 0x2
#defina COPY_FILE_OPEN_SOURCE_FOR_WRITE 0x4
#defina COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x8

#defina REPLACEFILE_WRITE_THROUGH 0x1
#defina REPLACEFILE_IGNORE_MERGE_ERRORS 0x2

#defina PIPE_ACCESS_INBOUND 0x1
#defina PIPE_ACCESS_OUTBOUND 0x2
#defina PIPE_ACCESS_DUPLEX 0x3

#defina PIPE_CLIENT_END 0x0
#defina PIPE_SERVER_END 0x1

#defina PIPE_WAIT 0x0
#defina PIPE_NOWAIT 0x1
#defina PIPE_READMODE_BYTE 0x0
#defina PIPE_READMODE_MESSAGE 0x2
#defina PIPE_TYPE_BYTE 0x0
#defina PIPE_TYPE_MESSAGE 0x4

#defina PIPE_UNLIMITED_INSTANCES 255

#defina SECURITY_ANONYMOUS (SecurityAnonymous << 16)
#defina SECURITY_IDENTIFICATION (SecurityIdentification << 16)
#defina SECURITY_IMPERSONATION (SecurityImpersonation << 16)
#defina SECURITY_DELEGATION (SecurityDelegation << 16)

#defina SECURITY_CONTEXT_TRACKING 0x40000
#defina SECURITY_EFFECTIVE_ONLY 0x80000

#defina SECURITY_SQOS_PRESENT 0x100000
#defina SECURITY_VALID_SQOS_FLAGS 0x1f0000

  defina_tipo estrutura _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    união {
      estrutura {
	DWORD Offset;
	DWORD OffsetHigh;
      };
      PVOID Pointer;
    };
    HANDLE hEvent;
  } OVERLAPPED,*LPOVERLAPPED;

  defina_tipo estrutura _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    WINBOOL bInheritHandle;
  } SECURITY_ATTRIBUTES,*PSECURITY_ATTRIBUTES,*LPSECURITY_ATTRIBUTES;

  defina_tipo estrutura _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
  } PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;

#se_não_definido _FILETIME_
#defina _FILETIME_
  defina_tipo estrutura _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
  } FILETIME,*PFILETIME,*LPFILETIME;
#fim_se

  defina_tipo estrutura _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
  } SYSTEMTIME,*PSYSTEMTIME,*LPSYSTEMTIME;

  defina_tipo DWORD (WINAPI *PTHREAD_START_ROUTINE)(LPVOID lpThreadParameter);
  defina_tipo PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;
  defina_tipo VOID (WINAPI *PFIBER_START_ROUTINE)(LPVOID lpFiberParameter);
  defina_tipo PFIBER_START_ROUTINE LPFIBER_START_ROUTINE;

  defina_tipo RTL_CRITICAL_SECTION CRITICAL_SECTION;
  defina_tipo PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
  defina_tipo PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;
  defina_tipo RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
  defina_tipo PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
  defina_tipo PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

  WINBASEAPI PVOID WINAPI EncodePointer(PVOID Ptr);
  WINBASEAPI PVOID WINAPI DecodePointer(PVOID Ptr);
  WINBASEAPI PVOID WINAPI EncodeSystemPointer(PVOID Ptr);
  WINBASEAPI PVOID WINAPI DecodeSystemPointer(PVOID Ptr);

#se_definido I_X86_
  defina_tipo PLDT_ENTRY LPLDT_ENTRY;
#senão
  defina_tipo LPVOID LPLDT_ENTRY;
#fim_se

#defina MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#defina MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

#defina SP_SERIALCOMM ((DWORD)0x1)

#defina PST_UNSPECIFIED ((DWORD)0x0)
#defina PST_RS232 ((DWORD)0x1)
#defina PST_PARALLELPORT ((DWORD)0x2)
#defina PST_RS422 ((DWORD)0x3)
#defina PST_RS423 ((DWORD)0x4)
#defina PST_RS449 ((DWORD)0x5)
#defina PST_MODEM ((DWORD)0x6)
#defina PST_FAX ((DWORD)0x21)
#defina PST_SCANNER ((DWORD)0x22)
#defina PST_NETWORK_BRIDGE ((DWORD)0x100)
#defina PST_LAT ((DWORD)0x101)
#defina PST_TCPIP_TELNET ((DWORD)0x102)
#defina PST_X25 ((DWORD)0x103)

#defina PCF_DTRDSR ((DWORD)0x1)
#defina PCF_RTSCTS ((DWORD)0x2)
#defina PCF_RLSD ((DWORD)0x4)
#defina PCF_PARITY_CHECK ((DWORD)0x8)
#defina PCF_XONXOFF ((DWORD)0x10)
#defina PCF_SETXCHAR ((DWORD)0x20)
#defina PCF_TOTALTIMEOUTS ((DWORD)0x40)
#defina PCF_INTTIMEOUTS ((DWORD)0x80)
#defina PCF_SPECIALCHARS ((DWORD)0x100)
#defina PCF_16BITMODE ((DWORD)0x200)

#defina SP_PARITY ((DWORD)0x1)
#defina SP_BAUD ((DWORD)0x2)
#defina SP_DATABITS ((DWORD)0x4)
#defina SP_STOPBITS ((DWORD)0x8)
#defina SP_HANDSHAKING ((DWORD)0x10)
#defina SP_PARITY_CHECK ((DWORD)0x20)
#defina SP_RLSD ((DWORD)0x40)

#defina BAUD_075 ((DWORD)0x1)
#defina BAUD_110 ((DWORD)0x2)
#defina BAUD_134_5 ((DWORD)0x4)
#defina BAUD_150 ((DWORD)0x8)
#defina BAUD_300 ((DWORD)0x10)
#defina BAUD_600 ((DWORD)0x20)
#defina BAUD_1200 ((DWORD)0x40)
#defina BAUD_1800 ((DWORD)0x80)
#defina BAUD_2400 ((DWORD)0x100)
#defina BAUD_4800 ((DWORD)0x200)
#defina BAUD_7200 ((DWORD)0x400)
#defina BAUD_9600 ((DWORD)0x800)
#defina BAUD_14400 ((DWORD)0x1000)
#defina BAUD_19200 ((DWORD)0x2000)
#defina BAUD_38400 ((DWORD)0x4000)
#defina BAUD_56K ((DWORD)0x8000)
#defina BAUD_128K ((DWORD)0x10000)
#defina BAUD_115200 ((DWORD)0x20000)
#defina BAUD_57600 ((DWORD)0x40000)
#defina BAUD_USER ((DWORD)0x10000000)

#defina DATABITS_5 ((WORD)0x1)
#defina DATABITS_6 ((WORD)0x2)
#defina DATABITS_7 ((WORD)0x4)
#defina DATABITS_8 ((WORD)0x8)
#defina DATABITS_16 ((WORD)0x10)
#defina DATABITS_16X ((WORD)0x20)

#defina STOPBITS_10 ((WORD)0x1)
#defina STOPBITS_15 ((WORD)0x2)
#defina STOPBITS_20 ((WORD)0x4)
#defina PARITY_NONE ((WORD)0x100)
#defina PARITY_ODD ((WORD)0x200)
#defina PARITY_EVEN ((WORD)0x400)
#defina PARITY_MARK ((WORD)0x800)
#defina PARITY_SPACE ((WORD)0x1000)

  defina_tipo estrutura _COMMPROP {
    WORD wPacketLength;
    WORD wPacketVersion;
    DWORD dwServiceMask;
    DWORD dwReserved1;
    DWORD dwMaxTxQueue;
    DWORD dwMaxRxQueue;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    WORD wSettableData;
    WORD wSettableStopParity;
    DWORD dwCurrentTxQueue;
    DWORD dwCurrentRxQueue;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
  } COMMPROP,*LPCOMMPROP;

#defina COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)

  defina_tipo estrutura _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD fXoffSent : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cbInQue;
    DWORD cbOutQue;
  } COMSTAT,*LPCOMSTAT;

#defina DTR_CONTROL_DISABLE 0x0
#defina DTR_CONTROL_ENABLE 0x1
#defina DTR_CONTROL_HANDSHAKE 0x2

#defina RTS_CONTROL_DISABLE 0x0
#defina RTS_CONTROL_ENABLE 0x1
#defina RTS_CONTROL_HANDSHAKE 0x2
#defina RTS_CONTROL_TOGGLE 0x3

  defina_tipo estrutura _DCB {
    DWORD DCBlength;
    DWORD BaudRate;
    DWORD fBinary: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD fDsrSensitivity:1;
    DWORD fTXContinueOnXoff: 1;
    DWORD fOutX: 1;
    DWORD fInX: 1;
    DWORD fErrorChar: 1;
    DWORD fNull: 1;
    DWORD fRtsControl:2;
    DWORD fAbortOnError:1;
    DWORD fDummy2:17;
    WORD wReserved;
    WORD XonLim;
    WORD XoffLim;
    BYTE ByteSize;
    BYTE Parity;
    BYTE StopBits;
    caractere XonChar;
    caractere XoffChar;
    caractere ErrorChar;
    caractere EofChar;
    caractere EvtChar;
    WORD wReserved1;
  } DCB,*LPDCB;

  defina_tipo estrutura _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD ReadTotalTimeoutMultiplier;
    DWORD ReadTotalTimeoutConstant;
    DWORD WriteTotalTimeoutMultiplier;
    DWORD WriteTotalTimeoutConstant;
  } COMMTIMEOUTS,*LPCOMMTIMEOUTS;

  defina_tipo estrutura _COMMCONFIG {
    DWORD dwSize;
    WORD wVersion;
    WORD wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dwProviderOffset;
    DWORD dwProviderSize;
    WCHAR wcProviderData[1];
  } COMMCONFIG,*LPCOMMCONFIG;

  defina_tipo estrutura _SYSTEM_INFO {
    união {
      DWORD dwOemId;
      estrutura {
	WORD wProcessorArchitecture;
	WORD wReserved;
      };
    };
    DWORD dwPageSize;
    LPVOID lpMinimumApplicationAddress;
    LPVOID lpMaximumApplicationAddress;
    DWORD_PTR dwActiveProcessorMask;
    DWORD dwNumberOfProcessors;
    DWORD dwProcessorType;
    DWORD dwAllocationGranularity;
    WORD wProcessorLevel;
    WORD wProcessorRevision;
  } SYSTEM_INFO,*LPSYSTEM_INFO;

#defina FreeModule(hLibModule) FreeLibrary((hLibModule))
#defina MakeProcInstance(lpProc,hInstance) (lpProc)
#defina FreeProcInstance(lpProc) (lpProc)

#defina GMEM_FIXED 0x0
#defina GMEM_MOVEABLE 0x2
#defina GMEM_NOCOMPACT 0x10
#defina GMEM_NODISCARD 0x20
#defina GMEM_ZEROINIT 0x40
#defina GMEM_MODIFY 0x80
#defina GMEM_DISCARDABLE 0x100
#defina GMEM_NOT_BANKED 0x1000
#defina GMEM_SHARE 0x2000
#defina GMEM_DDESHARE 0x2000
#defina GMEM_NOTIFY 0x4000
#defina GMEM_LOWER GMEM_NOT_BANKED
#defina GMEM_VALID_FLAGS 0x7F72
#defina GMEM_INVALID_HANDLE 0x8000

#defina GHND (GMEM_MOVEABLE | GMEM_ZEROINIT)
#defina GPTR (GMEM_FIXED | GMEM_ZEROINIT)

#defina GlobalLRUNewest(h) ((HANDLE)(h))
#defina GlobalLRUOldest(h) ((HANDLE)(h))
#defina GlobalDiscard(h) GlobalReAlloc((h),0,GMEM_MOVEABLE)

#defina GMEM_DISCARDED 0x4000
#defina GMEM_LOCKCOUNT 0xff

  defina_tipo estrutura _MEMORYSTATUS {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    SIZE_T dwTotalPhys;
    SIZE_T dwAvailPhys;
    SIZE_T dwTotalPageFile;
    SIZE_T dwAvailPageFile;
    SIZE_T dwTotalVirtual;
    SIZE_T dwAvailVirtual;
  } MEMORYSTATUS,*LPMEMORYSTATUS;

#defina LMEM_FIXED 0x0
#defina LMEM_MOVEABLE 0x2
#defina LMEM_NOCOMPACT 0x10
#defina LMEM_NODISCARD 0x20
#defina LMEM_ZEROINIT 0x40
#defina LMEM_MODIFY 0x80
#defina LMEM_DISCARDABLE 0xf00
#defina LMEM_VALID_FLAGS 0xf72
#defina LMEM_INVALID_HANDLE 0x8000

#defina LHND (LMEM_MOVEABLE | LMEM_ZEROINIT)
#defina LPTR (LMEM_FIXED | LMEM_ZEROINIT)

#defina NONZEROLHND (LMEM_MOVEABLE)
#defina NONZEROLPTR (LMEM_FIXED)

#defina LocalDiscard(h) LocalReAlloc((h),0,LMEM_MOVEABLE)

#defina LMEM_DISCARDED 0x4000
#defina LMEM_LOCKCOUNT 0xff

#defina DEBUG_PROCESS 0x1
#defina DEBUG_ONLY_THIS_PROCESS 0x2
#defina CREATE_SUSPENDED 0x4
#defina DETACHED_PROCESS 0x8
#defina CREATE_NEW_CONSOLE 0x10
#defina NORMAL_PRIORITY_CLASS 0x20
#defina IDLE_PRIORITY_CLASS 0x40
#defina HIGH_PRIORITY_CLASS 0x80
#defina REALTIME_PRIORITY_CLASS 0x100
#defina CREATE_NEW_PROCESS_GROUP 0x200
#defina CREATE_UNICODE_ENVIRONMENT 0x400
#defina CREATE_SEPARATE_WOW_VDM 0x800
#defina CREATE_SHARED_WOW_VDM 0x1000
#defina CREATE_FORCEDOS 0x2000
#defina BELOW_NORMAL_PRIORITY_CLASS 0x4000
#defina ABOVE_NORMAL_PRIORITY_CLASS 0x8000
#defina STACK_SIZE_PARAM_IS_A_RESERVATION 0x10000

#defina CREATE_BREAKAWAY_FROM_JOB 0x1000000
#defina CREATE_PRESERVE_CODE_AUTHZ_LEVEL 0x2000000

#defina CREATE_DEFAULT_ERROR_MODE 0x4000000
#defina CREATE_NO_WINDOW 0x8000000

#defina PROFILE_USER 0x10000000
#defina PROFILE_KERNEL 0x20000000
#defina PROFILE_SERVER 0x40000000

#defina CREATE_IGNORE_SYSTEM_DEFAULT 0x80000000

#defina THREAD_PRIORITY_LOWEST THREAD_BASE_PRIORITY_MIN
#defina THREAD_PRIORITY_BELOW_NORMAL (THREAD_PRIORITY_LOWEST+1)
#defina THREAD_PRIORITY_NORMAL 0
#defina THREAD_PRIORITY_HIGHEST THREAD_BASE_PRIORITY_MAX
#defina THREAD_PRIORITY_ABOVE_NORMAL (THREAD_PRIORITY_HIGHEST-1)
#defina THREAD_PRIORITY_ERROR_RETURN (MAXLONG)

#defina THREAD_PRIORITY_TIME_CRITICAL THREAD_BASE_PRIORITY_LOWRT
#defina THREAD_PRIORITY_IDLE THREAD_BASE_PRIORITY_IDLE

#defina EXCEPTION_DEBUG_EVENT 1
#defina CREATE_THREAD_DEBUG_EVENT 2
#defina CREATE_PROCESS_DEBUG_EVENT 3
#defina EXIT_THREAD_DEBUG_EVENT 4
#defina EXIT_PROCESS_DEBUG_EVENT 5
#defina LOAD_DLL_DEBUG_EVENT 6
#defina UNLOAD_DLL_DEBUG_EVENT 7
#defina OUTPUT_DEBUG_STRING_EVENT 8
#defina RIP_EVENT 9

  defina_tipo estrutura _EXCEPTION_DEBUG_INFO {
    EXCEPTION_RECORD ExceptionRecord;
    DWORD dwFirstChance;
  } EXCEPTION_DEBUG_INFO,*LPEXCEPTION_DEBUG_INFO;

  defina_tipo estrutura _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
  } CREATE_THREAD_DEBUG_INFO,*LPCREATE_THREAD_DEBUG_INFO;

  defina_tipo estrutura _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lpBaseOfImage;
    DWORD dwDebugInfoFileOffset;
    DWORD nDebugInfoSize;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
    LPVOID lpImageName;
    WORD fUnicode;
  } CREATE_PROCESS_DEBUG_INFO,*LPCREATE_PROCESS_DEBUG_INFO;

  defina_tipo estrutura _EXIT_THREAD_DEBUG_INFO {
    DWORD dwExitCode;
  } EXIT_THREAD_DEBUG_INFO,*LPEXIT_THREAD_DEBUG_INFO;

  defina_tipo estrutura _EXIT_PROCESS_DEBUG_INFO {
    DWORD dwExitCode;
  } EXIT_PROCESS_DEBUG_INFO,*LPEXIT_PROCESS_DEBUG_INFO;

  defina_tipo estrutura _LOAD_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lpBaseOfDll;
    DWORD dwDebugInfoFileOffset;
    DWORD nDebugInfoSize;
    LPVOID lpImageName;
    WORD fUnicode;
  } LOAD_DLL_DEBUG_INFO,*LPLOAD_DLL_DEBUG_INFO;

  defina_tipo estrutura _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lpBaseOfDll;
  } UNLOAD_DLL_DEBUG_INFO,*LPUNLOAD_DLL_DEBUG_INFO;

  defina_tipo estrutura _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lpDebugStringData;
    WORD fUnicode;
    WORD nDebugStringLength;
  } OUTPUT_DEBUG_STRING_INFO,*LPOUTPUT_DEBUG_STRING_INFO;

  defina_tipo estrutura _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
  } RIP_INFO,*LPRIP_INFO;

  defina_tipo estrutura _DEBUG_EVENT {
    DWORD dwDebugEventCode;
    DWORD dwProcessId;
    DWORD dwThreadId;
    união {
      EXCEPTION_DEBUG_INFO Exception;
      CREATE_THREAD_DEBUG_INFO CreateThread;
      CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
      EXIT_THREAD_DEBUG_INFO ExitThread;
      EXIT_PROCESS_DEBUG_INFO ExitProcess;
      LOAD_DLL_DEBUG_INFO LoadDll;
      UNLOAD_DLL_DEBUG_INFO UnloadDll;
      OUTPUT_DEBUG_STRING_INFO DebugString;
      RIP_INFO RipInfo;
    } u;
  } DEBUG_EVENT,*LPDEBUG_EVENT;

  defina_tipo PCONTEXT LPCONTEXT;
  defina_tipo PEXCEPTION_RECORD LPEXCEPTION_RECORD;
  defina_tipo PEXCEPTION_POINTERS LPEXCEPTION_POINTERS;

#defina DRIVE_UNKNOWN 0
#defina DRIVE_NO_ROOT_DIR 1
#defina DRIVE_REMOVABLE 2
#defina DRIVE_FIXED 3
#defina DRIVE_REMOTE 4
#defina DRIVE_CDROM 5
#defina DRIVE_RAMDISK 6

#defina GetFreeSpace(w) (0x100000L)
#defina FILE_TYPE_UNKNOWN 0x0
#defina FILE_TYPE_DISK 0x1
#defina FILE_TYPE_CHAR 0x2
#defina FILE_TYPE_PIPE 0x3
#defina FILE_TYPE_REMOTE 0x8000

#defina STD_INPUT_HANDLE ((DWORD)-10)
#defina STD_OUTPUT_HANDLE ((DWORD)-11)
#defina STD_ERROR_HANDLE ((DWORD)-12)

#defina NOPARITY 0
#defina ODDPARITY 1
#defina EVENPARITY 2
#defina MARKPARITY 3
#defina SPACEPARITY 4

#defina ONESTOPBIT 0
#defina ONE5STOPBITS 1
#defina TWOSTOPBITS 2

#defina IGNORE 0
#defina INFINITE 0xffffffff

#defina CBR_110 110
#defina CBR_300 300
#defina CBR_600 600
#defina CBR_1200 1200
#defina CBR_2400 2400
#defina CBR_4800 4800
#defina CBR_9600 9600
#defina CBR_14400 14400
#defina CBR_19200 19200
#defina CBR_38400 38400
#defina CBR_56000 56000
#defina CBR_57600 57600
#defina CBR_115200 115200
#defina CBR_128000 128000
#defina CBR_256000 256000

#defina CE_RXOVER 0x1
#defina CE_OVERRUN 0x2
#defina CE_RXPARITY 0x4
#defina CE_FRAME 0x8
#defina CE_BREAK 0x10
#defina CE_TXFULL 0x100
#defina CE_PTO 0x200
#defina CE_IOE 0x400
#defina CE_DNS 0x800
#defina CE_OOP 0x1000
#defina CE_MODE 0x8000

#defina IE_BADID (-1)
#defina IE_OPEN (-2)
#defina IE_NOPEN (-3)
#defina IE_MEMORY (-4)
#defina IE_DEFAULT (-5)
#defina IE_HARDWARE (-10)
#defina IE_BYTESIZE (-11)
#defina IE_BAUDRATE (-12)

#defina EV_RXCHAR 0x1
#defina EV_RXFLAG 0x2
#defina EV_TXEMPTY 0x4
#defina EV_CTS 0x8
#defina EV_DSR 0x10
#defina EV_RLSD 0x20
#defina EV_BREAK 0x40
#defina EV_ERR 0x80
#defina EV_RING 0x100
#defina EV_PERR 0x200
#defina EV_RX80FULL 0x400
#defina EV_EVENT1 0x800
#defina EV_EVENT2 0x1000

#defina SETXOFF 1
#defina SETXON 2
#defina SETRTS 3
#defina CLRRTS 4
#defina SETDTR 5
#defina CLRDTR 6
#defina RESETDEV 7
#defina SETBREAK 8
#defina CLRBREAK 9

#defina PURGE_TXABORT 0x1
#defina PURGE_RXABORT 0x2
#defina PURGE_TXCLEAR 0x4
#defina PURGE_RXCLEAR 0x8

#defina LPTx 0x80

#defina MS_CTS_ON ((DWORD)0x10)
#defina MS_DSR_ON ((DWORD)0x20)
#defina MS_RING_ON ((DWORD)0x40)
#defina MS_RLSD_ON ((DWORD)0x80)

#defina S_QUEUEEMPTY 0
#defina S_THRESHOLD 1
#defina S_ALLTHRESHOLD 2

#defina S_NORMAL 0
#defina S_LEGATO 1
#defina S_STACCATO 2

#defina S_PERIOD512 0
#defina S_PERIOD1024 1
#defina S_PERIOD2048 2
#defina S_PERIODVOICE 3
#defina S_WHITE512 4
#defina S_WHITE1024 5
#defina S_WHITE2048 6
#defina S_WHITEVOICE 7

#defina S_SERDVNA (-1)
#defina S_SEROFM (-2)
#defina S_SERMACT (-3)
#defina S_SERQFUL (-4)
#defina S_SERBDNT (-5)
#defina S_SERDLN (-6)
#defina S_SERDCC (-7)
#defina S_SERDTP (-8)
#defina S_SERDVL (-9)
#defina S_SERDMD (-10)
#defina S_SERDSH (-11)
#defina S_SERDPT (-12)
#defina S_SERDFQ (-13)
#defina S_SERDDR (-14)
#defina S_SERDSR (-15)
#defina S_SERDST (-16)

#defina NMPWAIT_WAIT_FOREVER 0xffffffff
#defina NMPWAIT_NOWAIT 0x1
#defina NMPWAIT_USE_DEFAULT_WAIT 0x0

#defina FS_CASE_IS_PRESERVED FILE_CASE_PRESERVED_NAMES
#defina FS_CASE_SENSITIVE FILE_CASE_SENSITIVE_SEARCH
#defina FS_UNICODE_STORED_ON_DISK FILE_UNICODE_ON_DISK
#defina FS_PERSISTENT_ACLS FILE_PERSISTENT_ACLS
#defina FS_VOL_IS_COMPRESSED FILE_VOLUME_IS_COMPRESSED
#defina FS_FILE_COMPRESSION FILE_FILE_COMPRESSION
#defina FS_FILE_ENCRYPTION FILE_SUPPORTS_ENCRYPTION

#defina FILE_MAP_COPY SECTION_QUERY
#defina FILE_MAP_WRITE SECTION_MAP_WRITE
#defina FILE_MAP_READ SECTION_MAP_READ
#defina FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#defina FILE_MAP_EXECUTE SECTION_MAP_EXECUTE_EXPLICIT

#defina OF_READ 0x0
#defina OF_WRITE 0x1
#defina OF_READWRITE 0x2
#defina OF_SHARE_COMPAT 0x0
#defina OF_SHARE_EXCLUSIVE 0x10
#defina OF_SHARE_DENY_WRITE 0x20
#defina OF_SHARE_DENY_READ 0x30
#defina OF_SHARE_DENY_NONE 0x40
#defina OF_PARSE 0x100
#defina OF_DELETE 0x200
#defina OF_VERIFY 0x400
#defina OF_CANCEL 0x800
#defina OF_CREATE 0x1000
#defina OF_PROMPT 0x2000
#defina OF_EXIST 0x4000
#defina OF_REOPEN 0x8000

#defina OFS_MAXPATHNAME 128
  defina_tipo estrutura _OFSTRUCT {
    BYTE cBytes;
    BYTE fFixedDisk;
    WORD nErrCode;
    WORD Reserved1;
    WORD Reserved2;
    CHAR szPathName[OFS_MAXPATHNAME];
  } OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;

#se_não_definido NOWINBASEINTERLOCK

#se_não_definido _NTOS_

#se definido(__ia64__) && !definido(RC_INVOKED)

#defina InterlockedIncrement _InterlockedIncrement
#defina InterlockedIncrementAcquire _InterlockedIncrement_acq
#defina InterlockedIncrementRelease _InterlockedIncrement_rel
#defina InterlockedDecrement _InterlockedDecrement
#defina InterlockedDecrementAcquire _InterlockedDecrement_acq
#defina InterlockedDecrementRelease _InterlockedDecrement_rel
#defina InterlockedExchange _InterlockedExchange
#defina InterlockedExchangeAdd _InterlockedExchangeAdd
#defina InterlockedCompareExchange _InterlockedCompareExchange
#defina InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#defina InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#defina InterlockedExchangePointer _InterlockedExchangePointer
#defina InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#defina InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer_rel
#defina InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer_acq

#defina InterlockedIncrement64 _InterlockedIncrement64
#defina InterlockedDecrement64 _InterlockedDecrement64
#defina InterlockedExchange64 _InterlockedExchange64
#defina InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#defina InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#defina InterlockedCompareExchange64 _InterlockedCompareExchange64
#defina InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#defina InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel

  LONGLONG __cdecl InterlockedIncrement64(LONGLONG volátil *Addend);
  LONGLONG __cdecl InterlockedDecrement64(LONGLONG volátil *Addend);
  LONG __cdecl InterlockedIncrementAcquire(LONG volátil *Addend);
  LONG __cdecl InterlockedDecrementAcquire(LONG volátil *Addend);
  LONG __cdecl InterlockedIncrementRelease(LONG volátil *Addend);
  LONG __cdecl InterlockedDecrementRelease(LONG volátil *Addend);
  LONGLONG __cdecl InterlockedExchange64 (LONGLONG volátil *Target,LONGLONG Value);
  LONGLONG __cdecl InterlockedExchangeAcquire64 (LONGLONG volátil *Target,LONGLONG Value);
  LONGLONG __cdecl InterlockedExchangeAdd64 (LONGLONG volátil *Addend,LONGLONG Value);
  LONGLONG __cdecl InterlockedCompareExchange64 (LONGLONG volátil *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeAcquire64 (LONGLONG volátil *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeRelease64 (LONGLONG volátil *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONG __cdecl InterlockedIncrement(LONG volátil *lpAddend);
  LONG __cdecl InterlockedDecrement(LONG volátil *lpAddend);
  LONG __cdecl InterlockedExchange(LONG volátil *Target,LONG Value);
  LONG __cdecl InterlockedExchangeAdd(LONG volátil *Addend,LONG Value);
  LONG __cdecl InterlockedCompareExchange(LONG volátil *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeRelease(LONG volátil *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeAcquire(LONG volátil *Destination,LONG ExChange,LONG Comperand);
  PVOID __cdecl InterlockedExchangePointer(PVOID volátil *Target,PVOID Value);
  PVOID __cdecl InterlockedCompareExchangePointer(PVOID volátil *Destination,PVOID ExChange,PVOID Comperand);
  PVOID __cdecl InterlockedCompareExchangePointerAcquire(PVOID volátil *Destination,PVOID Exchange,PVOID Comperand);
  PVOID __cdecl InterlockedCompareExchangePointerRelease(PVOID volátil *Destination,PVOID Exchange,PVOID Comperand);

#se_não_definido InterlockedAnd
#defina InterlockedAnd InterlockedAnd_Inline
  __CRT_INLINE LONG InterlockedAnd_Inline(LONG volátil *Target,LONG Set) {
    LONG i;
    LONG j;
    j = *Target;
    faça {
      i = j;
      j = InterlockedCompareExchange(Target,i & Set,i);
    } enquanto(i!=j);
    retorne j;
  }
#fim_se

#se_não_definido InterlockedOr
#defina InterlockedOr InterlockedOr_Inline

  __CRT_INLINE LONG InterlockedOr_Inline(LONG volátil *Target,LONG Set) {
    LONG i;
    LONG j;
    j = *Target;
    faça {
      i = j;
      j = InterlockedCompareExchange(Target,i | Set,i);
    } enquanto(i!=j);
    retorne j;
  }
#fim_se

#se_não_definido InterlockedXor
#defina InterlockedXor InterlockedXor_Inline

  __CRT_INLINE LONG InterlockedXor_Inline(LONG volátil *Target,LONG Set) {
    LONG i;
    LONG j;
    j = *Target;
    faça {
      i = j;
      j = InterlockedCompareExchange(Target,i ^ Set,i);
    } enquanto(i!=j);
    retorne j;
  }
#fim_se

#se_não_definido !definido (InterlockedAnd64)
#defina InterlockedAnd64 InterlockedAnd64_Inline

  __CRT_INLINE LONGLONG InterlockedAnd64_Inline (LONGLONG volátil *Destination,LONGLONG Value) {
    LONGLONG Old;
    faça {
      Old = *Destination;
    } enquanto(InterlockedCompareExchange64(Destination,Old & Value,Old)!=Old);
    retorne Old;
  }
#fim_se

#se_não_definido InterlockedOr64
#defina InterlockedOr64 InterlockedOr64_Inline

  __CRT_INLINE LONGLONG InterlockedOr64_Inline (LONGLONG volátil *Destination,LONGLONG Value) {
    LONGLONG Old;
    faça {
      Old = *Destination;
    } enquanto(InterlockedCompareExchange64(Destination,Old | Value,Old)!=Old);
    retorne Old;
  }
#fim_se

#se_não_definido InterlockedXor64
#defina InterlockedXor64 InterlockedXor64_Inline

  __CRT_INLINE LONGLONG InterlockedXor64_Inline (LONGLONG volátil *Destination,LONGLONG Value) {
    LONGLONG Old;
    faça {
      Old = *Destination;
    } enquanto(InterlockedCompareExchange64(Destination,Old ^ Value,Old)!=Old);
    retorne Old;
  }
#fim_se

#se_não_definido InterlockedBitTestAndSet
#defina InterlockedBitTestAndSet InterlockedBitTestAndSet_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndSet_Inline(LONG *Base,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (sizeof (*Base)*8-1));
    retorne (BOOLEAN)((InterlockedOr(&Base[Bit/(sizeof(*Base)*8)],tBit)&tBit)!=0);
  }
#fim_se

#se_não_definido InterlockedBitTestAndReset
#defina InterlockedBitTestAndReset InterlockedBitTestAndReset_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndReset_Inline(LONG *Base,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (sizeof (*Base)*8-1));
    retorne (BOOLEAN)((InterlockedAnd(&Base[Bit/(sizeof(*Base)*8)],~tBit)&tBit)!=0);
  }
#fim_se

#se_não_definido InterlockedBitTestAndComplement
#defina InterlockedBitTestAndComplement InterlockedBitTestAndComplement_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndComplement_Inline(LONG *Base,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (sizeof (*Base)*8-1));
    retorne (BOOLEAN)((InterlockedXor(&Base[Bit/(sizeof(*Base)*8)],tBit)&tBit)!=0);
  }
#fim_se
#senão_se definido(__x86_64) && !definido(RC_INVOKED)

#defina InterlockedIncrement _InterlockedIncrement
#defina InterlockedIncrementAcquire InterlockedIncrement
#defina InterlockedIncrementRelease InterlockedIncrement
#defina InterlockedDecrement _InterlockedDecrement
#defina InterlockedDecrementAcquire InterlockedDecrement
#defina InterlockedDecrementRelease InterlockedDecrement
#defina InterlockedExchange _InterlockedExchange
#defina InterlockedExchangeAdd _InterlockedExchangeAdd
#defina InterlockedCompareExchange _InterlockedCompareExchange
#defina InterlockedCompareExchangeAcquire InterlockedCompareExchange
#defina InterlockedCompareExchangeRelease InterlockedCompareExchange
#defina InterlockedExchangePointer _InterlockedExchangePointer
#defina InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#defina InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer
#defina InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer
#defina InterlockedAnd64 _InterlockedAnd64
#defina InterlockedOr64 _InterlockedOr64
#defina InterlockedXor64 _InterlockedXor64
#defina InterlockedIncrement64 _InterlockedIncrement64
#defina InterlockedDecrement64 _InterlockedDecrement64
#defina InterlockedExchange64 _InterlockedExchange64
#defina InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#defina InterlockedCompareExchange64 _InterlockedCompareExchange64
#defina InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#defina InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

  LONG InterlockedIncrement(LONG volátil *Addend);
  LONG InterlockedDecrement(LONG volátil *Addend);
  LONG InterlockedExchange(LONG volátil *Target,LONG Value);
  LONG InterlockedExchangeAdd(LONG volátil *Addend,LONG Value);
  LONG InterlockedCompareExchange(LONG volátil *Destination,LONG ExChange,LONG Comperand);
  PVOID InterlockedCompareExchangePointer(PVOID volátil *Destination,PVOID Exchange,PVOID Comperand);
  PVOID InterlockedExchangePointer(PVOID volátil *Target,PVOID Value);
  LONG64 InterlockedAnd64(LONG64 volátil *Destination,LONG64 Value);
  LONG64 InterlockedOr64(LONG64 volátil *Destination,LONG64 Value);
  LONG64 InterlockedXor64(LONG64 volátil *Destination,LONG64 Value);
  LONG64 InterlockedIncrement64(LONG64 volátil *Addend);
  LONG64 InterlockedDecrement64(LONG64 volátil *Addend);
  LONG64 InterlockedExchange64(LONG64 volátil *Target,LONG64 Value);
  LONG64 InterlockedExchangeAdd64(LONG64 volátil *Addend,LONG64 Value);
  LONG64 InterlockedCompareExchange64(LONG64 volátil *Destination,LONG64 ExChange,LONG64 Comperand);
#senão
  LONG WINAPI InterlockedIncrement(LONG volátil *lpAddend);
  LONG WINAPI InterlockedDecrement(LONG volátil *lpAddend);
  LONG WINAPI InterlockedExchange(LONG volátil *Target,LONG Value);

#defina InterlockedExchangePointer(Target,Value) (PVOID)InterlockedExchange((PLONG)(Target),(LONG)(Value))

  LONG WINAPI InterlockedExchangeAdd(LONG volátil *Addend,LONG Value);
  LONG WINAPI InterlockedCompareExchange(LONG volátil *Destination,LONG Exchange,LONG Comperand);
  LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG volátil *Destination,LONGLONG Exchange,LONGLONG Comperand);

  __CRT_INLINE LONGLONG InterlockedAnd64 (LONGLONG volátil *Destination,LONGLONG Value) {
    LONGLONG Old;
    faça {
      Old = *Destination;
    } enquanto(InterlockedCompareExchange64(Destination,Old & Value,Old)!=Old);
    retorne Old;
  }

  __CRT_INLINE LONGLONG InterlockedOr64 (LONGLONG volátil *Destination,LONGLONG Value) {
    LONGLONG Old;
    faça {
      Old = *Destination;
    } enquanto(InterlockedCompareExchange64(Destination,Old | Value,Old)!=Old);
    retorne Old;
  }

  __CRT_INLINE LONGLONG InterlockedXor64 (LONGLONG volátil *Destination,LONGLONG Value) {
    LONGLONG Old;
    faça {
      Old = *Destination;
    } enquanto(InterlockedCompareExchange64(Destination,Old ^ Value,Old)!=Old);

    retorne Old;
  }

  __CRT_INLINE LONGLONG InterlockedIncrement64(LONGLONG volátil *Addend) {
    LONGLONG Old;
    faça {
      Old = *Addend;
    } enquanto(InterlockedCompareExchange64(Addend,Old + 1,Old)!=Old);
    retorne Old + 1;
  }

  __CRT_INLINE LONGLONG InterlockedDecrement64(LONGLONG volátil *Addend) {
    LONGLONG Old;
    faça {
      Old = *Addend;
    } enquanto(InterlockedCompareExchange64(Addend,Old - 1,Old)!=Old);
    retorne Old - 1;
  }

  __CRT_INLINE LONGLONG InterlockedExchange64(LONGLONG volátil *Target,LONGLONG Value) {
    LONGLONG Old;
    faça {
      Old = *Target;
    } enquanto(InterlockedCompareExchange64(Target,Value,Old)!=Old);
    retorne Old;
  }

  __CRT_INLINE LONGLONG InterlockedExchangeAdd64(LONGLONG volátil *Addend,LONGLONG Value) {
    LONGLONG Old;
    faça {
      Old = *Addend;
    } enquanto(InterlockedCompareExchange64(Addend,Old + Value,Old)!=Old);
    retorne Old;
  }

#se_definido __cplusplus
  __CRT_INLINE PVOID __cdecl __InlineInterlockedCompareExchangePointer(PVOID volátil *Destination,PVOID ExChange,PVOID Comperand) {
    retorne((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG volátil *)Destination,(LONG)(LONG_PTR)ExChange,(LONG)(LONG_PTR)Comperand));
  }
#defina InterlockedCompareExchangePointer __InlineInterlockedCompareExchangePointer
#senão
#defina InterlockedCompareExchangePointer(Destination,ExChange,Comperand)(PVOID)(LONG_PTR)InterlockedCompareExchange((LONG volátil *)(Destination),(LONG)(LONG_PTR)(ExChange),(LONG)(LONG_PTR)(Comperand))
#fim_se

#defina InterlockedIncrementAcquire InterlockedIncrement
#defina InterlockedIncrementRelease InterlockedIncrement
#defina InterlockedDecrementAcquire InterlockedDecrement
#defina InterlockedDecrementRelease InterlockedDecrement
#defina InterlockedIncrementAcquire InterlockedIncrement
#defina InterlockedIncrementRelease InterlockedIncrement
#defina InterlockedCompareExchangeAcquire InterlockedCompareExchange
#defina InterlockedCompareExchangeRelease InterlockedCompareExchange
#defina InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#defina InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#defina InterlockedCompareExchangePointerAcquire InterlockedCompareExchangePointer
#defina InterlockedCompareExchangePointerRelease InterlockedCompareExchangePointer
#fim_se

#se definido(_SLIST_HEADER_) && !definido(_NTOSP_)
  WINBASEAPI VOID WINAPI InitializeSListHead(PSLIST_HEADER ListHead);
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPopEntrySList(PSLIST_HEADER ListHead);
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPushEntrySList(PSLIST_HEADER ListHead,PSLIST_ENTRY ListEntry);
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedFlushSList(PSLIST_HEADER ListHead);
  WINBASEAPI USHORT WINAPI QueryDepthSList(PSLIST_HEADER ListHead);
#fim_se
#fim_se
#fim_se

  WINBASEAPI WINBOOL WINAPI FreeResource(HGLOBAL hResData);
  WINBASEAPI LPVOID WINAPI LockResource(HGLOBAL hResData);

#defina UnlockResource(hResData) ((hResData),0)
#defina MAXINTATOM 0xC000
#defina MAKEINTATOM(i) (LPTSTR)((ULONG_PTR)((WORD)(i)))
#defina INVALID_ATOM ((ATOM)0)

  inteiro WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,inteiro nShowCmd);
  WINBASEAPI WINBOOL WINAPI FreeLibrary(HMODULE hLibModule);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI FreeLibraryAndExitThread(HMODULE hLibModule,DWORD dwExitCode);
  WINBASEAPI WINBOOL WINAPI DisableThreadLibraryCalls(HMODULE hLibModule);
  WINBASEAPI FARPROC WINAPI GetProcAddress(HMODULE hModule,LPCSTR lpProcName);
  WINBASEAPI DWORD WINAPI GetVersion(VOID);
  WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT uFlags,SIZE_T dwBytes);
  WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL hMem,SIZE_T dwBytes,UINT uFlags);
  WINBASEAPI SIZE_T WINAPI GlobalSize(HGLOBAL hMem);
  WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalLock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnlock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
  WINBASEAPI SIZE_T WINAPI GlobalCompact(DWORD dwMinFree);
  WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL hMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnWire(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalMemoryStatus(LPMEMORYSTATUS lpBuffer);

  defina_tipo estrutura _MEMORYSTATUSEX {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    DWORDLONG ullTotalPhys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ullTotalPageFile;
    DWORDLONG ullAvailPageFile;
    DWORDLONG ullTotalVirtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
  } MEMORYSTATUSEX,*LPMEMORYSTATUSEX;

  WINBASEAPI WINBOOL WINAPI GlobalMemoryStatusEx(LPMEMORYSTATUSEX lpBuffer);
  WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,SIZE_T uBytes);
  WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,SIZE_T uBytes,UINT uFlags);
  WINBASEAPI LPVOID WINAPI LocalLock(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI LocalUnlock(HLOCAL hMem);
  WINBASEAPI SIZE_T WINAPI LocalSize(HLOCAL hMem);
  WINBASEAPI UINT WINAPI LocalFlags(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
  WINBASEAPI SIZE_T WINAPI LocalShrink(HLOCAL hMem,UINT cbNewSize);
  WINBASEAPI SIZE_T WINAPI LocalCompact(UINT uMinFree);
  WINBASEAPI WINBOOL WINAPI FlushInstructionCache(HANDLE hProcess,LPCVOID lpBaseAddress,SIZE_T dwSize);
  WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lpAddress,SIZE_T dwSize,DWORD flAllocationType,DWORD flProtect);
  WINBASEAPI WINBOOL WINAPI VirtualFree(LPVOID lpAddress,SIZE_T dwSize,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtect(LPVOID lpAddress,SIZE_T dwSize,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI SIZE_T WINAPI VirtualQuery(LPCVOID lpAddress,PMEMORY_BASIC_INFORMATION lpBuffer,SIZE_T dwLength);
  WINBASEAPI LPVOID WINAPI VirtualAllocEx(HANDLE hProcess,LPVOID lpAddress,SIZE_T dwSize,DWORD flAllocationType,DWORD flProtect);
  WINBASEAPI UINT WINAPI GetWriteWatch(DWORD dwFlags,PVOID lpBaseAddress,SIZE_T dwRegionSize,PVOID *lpAddresses,ULONG_PTR *lpdwCount,PULONG lpdwGranularity);
  WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID lpBaseAddress,SIZE_T dwRegionSize);
  WINBASEAPI SIZE_T WINAPI GetLargePageMinimum(VOID);
  WINBASEAPI UINT WINAPI EnumSystemFirmwareTables(DWORD FirmwareTableProviderSignature,PVOID pFirmwareTableEnumBuffer,DWORD BufferSize);
  WINBASEAPI UINT WINAPI GetSystemFirmwareTable(DWORD FirmwareTableProviderSignature,DWORD FirmwareTableID,PVOID pFirmwareTableBuffer,DWORD BufferSize);
  WINBASEAPI WINBOOL WINAPI VirtualFreeEx(HANDLE hProcess,LPVOID lpAddress,SIZE_T dwSize,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtectEx(HANDLE hProcess,LPVOID lpAddress,SIZE_T dwSize,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI SIZE_T WINAPI VirtualQueryEx(HANDLE hProcess,LPCVOID lpAddress,PMEMORY_BASIC_INFORMATION lpBuffer,SIZE_T dwLength);
  WINBASEAPI HANDLE WINAPI HeapCreate(DWORD flOptions,SIZE_T dwInitialSize,SIZE_T dwMaximumSize);
  WINBASEAPI WINBOOL WINAPI HeapDestroy(HANDLE hHeap);
  WINBASEAPI LPVOID WINAPI HeapAlloc(HANDLE hHeap,DWORD dwFlags,SIZE_T dwBytes);
  WINBASEAPI LPVOID WINAPI HeapReAlloc(HANDLE hHeap,DWORD dwFlags,LPVOID lpMem,SIZE_T dwBytes);
  WINBASEAPI WINBOOL WINAPI HeapFree(HANDLE hHeap,DWORD dwFlags,LPVOID lpMem);
  WINBASEAPI SIZE_T WINAPI HeapSize(HANDLE hHeap,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI WINBOOL WINAPI HeapValidate(HANDLE hHeap,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI SIZE_T WINAPI HeapCompact(HANDLE hHeap,DWORD dwFlags);
  WINBASEAPI HANDLE WINAPI GetProcessHeap(VOID);
  WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD NumberOfHeaps,PHANDLE ProcessHeaps);

  defina_tipo estrutura _PROCESS_HEAP_ENTRY {
    PVOID lpData;
    DWORD cbData;
    BYTE cbOverhead;
    BYTE iRegionIndex;
    WORD wFlags;
    união {
      estrutura {
	HANDLE hMem;
	DWORD dwReserved[3];
      } Block;
      estrutura {
	DWORD dwCommittedSize;
	DWORD dwUnCommittedSize;
	LPVOID lpFirstBlock;
	LPVOID lpLastBlock;
      } Region;
    };
  } PROCESS_HEAP_ENTRY,*LPPROCESS_HEAP_ENTRY,*PPROCESS_HEAP_ENTRY;

#defina PROCESS_HEAP_REGION 0x1
#defina PROCESS_HEAP_UNCOMMITTED_RANGE 0x2
#defina PROCESS_HEAP_ENTRY_BUSY 0x4
#defina PROCESS_HEAP_ENTRY_MOVEABLE 0x10
#defina PROCESS_HEAP_ENTRY_DDESHARE 0x20

  WINBASEAPI WINBOOL WINAPI HeapLock(HANDLE hHeap);
  WINBASEAPI WINBOOL WINAPI HeapUnlock(HANDLE hHeap);
  WINBASEAPI WINBOOL WINAPI HeapWalk(HANDLE hHeap,LPPROCESS_HEAP_ENTRY lpEntry);
  WINBASEAPI WINBOOL WINAPI HeapSetInformation(HANDLE HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,SIZE_T HeapInformationLength);
  WINBASEAPI WINBOOL WINAPI HeapQueryInformation(HANDLE HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,SIZE_T HeapInformationLength,PSIZE_T ReturnLength);

#defina SCS_32BIT_BINARY 0
#defina SCS_DOS_BINARY 1
#defina SCS_WOW_BINARY 2
#defina SCS_PIF_BINARY 3
#defina SCS_POSIX_BINARY 4
#defina SCS_OS216_BINARY 5
#defina SCS_64BIT_BINARY 6

#se_definido UNICODE
#defina GetBinaryType GetBinaryTypeW
#defina GetShortPathName GetShortPathNameW
#defina GetLongPathName GetLongPathNameW
#defina GetEnvironmentStrings GetEnvironmentStringsW
#defina SetEnvironmentStrings SetEnvironmentStringsW
#defina FreeEnvironmentStrings FreeEnvironmentStringsW
#senão
#defina GetBinaryType GetBinaryTypeA
#defina GetShortPathName GetShortPathNameA
#defina GetLongPathName GetLongPathNameA
#defina GetEnvironmentStringsA GetEnvironmentStrings
#defina SetEnvironmentStrings SetEnvironmentStringsA
#defina FreeEnvironmentStrings FreeEnvironmentStringsA
#fim_se

#se_definido _WIN64
#defina SCS_THIS_PLATFORM_BINARY SCS_64BIT_BINARY
#senão
#defina SCS_THIS_PLATFORM_BINARY SCS_32BIT_BINARY
#fim_se

  WINBASEAPI WINBOOL WINAPI GetBinaryTypeA(LPCSTR lpApplicationName,LPDWORD lpBinaryType);
  WINBASEAPI WINBOOL WINAPI GetBinaryTypeW(LPCWSTR lpApplicationName,LPDWORD lpBinaryType);
  WINBASEAPI DWORD WINAPI GetShortPathNameA(LPCSTR lpszLongPath,LPSTR lpszShortPath,DWORD cchBuffer);
  WINBASEAPI DWORD WINAPI GetShortPathNameW(LPCWSTR lpszLongPath,LPWSTR lpszShortPath,DWORD cchBuffer);
  WINBASEAPI DWORD WINAPI GetLongPathNameA(LPCSTR lpszShortPath,LPSTR lpszLongPath,DWORD cchBuffer);
  WINBASEAPI DWORD WINAPI GetLongPathNameW(LPCWSTR lpszShortPath,LPWSTR lpszLongPath,DWORD cchBuffer);
  WINBASEAPI WINBOOL WINAPI GetProcessAffinityMask(HANDLE hProcess,PDWORD_PTR lpProcessAffinityMask,PDWORD_PTR lpSystemAffinityMask);
  WINBASEAPI WINBOOL WINAPI SetProcessAffinityMask(HANDLE hProcess,DWORD_PTR dwProcessAffinityMask);
  WINBASEAPI WINBOOL WINAPI GetProcessHandleCount(HANDLE hProcess,PDWORD pdwHandleCount);
  WINBASEAPI WINBOOL WINAPI GetProcessTimes(HANDLE hProcess,LPFILETIME lpCreationTime,LPFILETIME lpExitTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
  WINBASEAPI WINBOOL WINAPI GetProcessIoCounters(HANDLE hProcess,PIO_COUNTERS lpIoCounters);
  WINBASEAPI WINBOOL WINAPI GetProcessWorkingSetSize(HANDLE hProcess,PSIZE_T lpMinimumWorkingSetSize,PSIZE_T lpMaximumWorkingSetSize);
  WINBASEAPI WINBOOL WINAPI GetProcessWorkingSetSizeEx(HANDLE hProcess,PSIZE_T lpMinimumWorkingSetSize,PSIZE_T lpMaximumWorkingSetSize,PDWORD Flags);
  WINBASEAPI WINBOOL WINAPI SetProcessWorkingSetSize(HANDLE hProcess,SIZE_T dwMinimumWorkingSetSize,SIZE_T dwMaximumWorkingSetSize);
  WINBASEAPI WINBOOL WINAPI SetProcessWorkingSetSizeEx(HANDLE hProcess,SIZE_T dwMinimumWorkingSetSize,SIZE_T dwMaximumWorkingSetSize,DWORD Flags);
  WINBASEAPI HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwProcessId);
  WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT uExitCode);
  WINBASEAPI WINBOOL WINAPI TerminateProcess(HANDLE hProcess,UINT uExitCode);
  WINBASEAPI WINBOOL WINAPI GetExitCodeProcess(HANDLE hProcess,LPDWORD lpExitCode);
  WINBASEAPI VOID WINAPI FatalExit(inteiro ExitCode);
  /*	WINBASEAPI LPCH WINAPI GetEnvironmentStrings(VOID); */
  WINBASEAPI LPWCH WINAPI GetEnvironmentStringsW(VOID);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentStringsA(LPCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentStringsW(LPWCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI FreeEnvironmentStringsA(LPCH);
  WINBASEAPI WINBOOL WINAPI FreeEnvironmentStringsW(LPWCH);
  WINBASEAPI VOID WINAPI RaiseException(DWORD dwExceptionCode,DWORD dwExceptionFlags,DWORD nNumberOfArguments,CONST ULONG_PTR *lpArguments);
  WINBASEAPI LONG WINAPI UnhandledExceptionFilter(estrutura _EXCEPTION_POINTERS *ExceptionInfo);

  defina_tipo LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(estrutura _EXCEPTION_POINTERS *ExceptionInfo);
  defina_tipo PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

  WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter);

#defina FIBER_FLAG_FLOAT_SWITCH 0x1

  WINBASEAPI LPVOID WINAPI CreateFiber(SIZE_T dwStackSize,LPFIBER_START_ROUTINE lpStartAddress,LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI CreateFiberEx(SIZE_T dwStackCommitSize,SIZE_T dwStackReserveSize,DWORD dwFlags,LPFIBER_START_ROUTINE lpStartAddress,LPVOID lpParameter);
  WINBASEAPI VOID WINAPI DeleteFiber(LPVOID lpFiber);
  WINBASEAPI LPVOID WINAPI ConvertThreadToFiber(LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI ConvertThreadToFiberEx(LPVOID lpParameter,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI ConvertFiberToThread(VOID);
  WINBASEAPI VOID WINAPI SwitchToFiber(LPVOID lpFiber);
  WINBASEAPI WINBOOL WINAPI SwitchToThread(VOID);
  WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,SIZE_T dwStackSize,LPTHREAD_START_ROUTINE lpStartAddress,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,LPSECURITY_ATTRIBUTES lpThreadAttributes,SIZE_T dwStackSize,LPTHREAD_START_ROUTINE lpStartAddress,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI GetCurrentThread(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
  WINBASEAPI WINBOOL WINAPI SetThreadStackGuarantee (PULONG StackSizeInBytes);
  WINBASEAPI DWORD WINAPI GetProcessIdOfThread(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetThreadId(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetProcessId(HANDLE Process);
  WINBASEAPI DWORD WINAPI GetCurrentProcessorNumber(VOID);
  WINBASEAPI DWORD_PTR WINAPI SetThreadAffinityMask(HANDLE hThread,DWORD_PTR dwThreadAffinityMask);
  WINBASEAPI DWORD WINAPI SetThreadIdealProcessor(HANDLE hThread,DWORD dwIdealProcessor);
  WINBASEAPI WINBOOL WINAPI SetProcessPriorityBoost(HANDLE hProcess,WINBOOL bDisablePriorityBoost);
  WINBASEAPI WINBOOL WINAPI GetProcessPriorityBoost(HANDLE hProcess,PBOOL pDisablePriorityBoost);
  WINBASEAPI WINBOOL WINAPI RequestWakeupLatency(LATENCY_TIME latency);
  WINBASEAPI WINBOOL WINAPI IsSystemResumeAutomatic(VOID);
  WINBASEAPI HANDLE WINAPI OpenThread(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwThreadId);
  WINBASEAPI WINBOOL WINAPI SetThreadPriority(HANDLE hThread,inteiro nPriority);
  WINBASEAPI WINBOOL WINAPI SetThreadPriorityBoost(HANDLE hThread,WINBOOL bDisablePriorityBoost);
  WINBASEAPI WINBOOL WINAPI GetThreadPriorityBoost(HANDLE hThread,PBOOL pDisablePriorityBoost);
  WINBASEAPI inteiro WINAPI GetThreadPriority(HANDLE hThread);
  WINBASEAPI WINBOOL WINAPI GetThreadTimes(HANDLE hThread,LPFILETIME lpCreationTime,LPFILETIME lpExitTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
  WINBASEAPI WINBOOL WINAPI GetThreadIOPendingFlag(HANDLE hThread,PBOOL lpIOIsPending);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitThread(DWORD dwExitCode);
  WINBASEAPI WINBOOL WINAPI TerminateThread(HANDLE hThread,DWORD dwExitCode);
  WINBASEAPI WINBOOL WINAPI GetExitCodeThread(HANDLE hThread,LPDWORD lpExitCode);
  WINBASEAPI WINBOOL WINAPI GetThreadSelectorEntry(HANDLE hThread,DWORD dwSelector,LPLDT_ENTRY lpSelectorEntry);
  WINBASEAPI EXECUTION_STATE WINAPI SetThreadExecutionState(EXECUTION_STATE esFlags);
  WINBASEAPI DWORD WINAPI GetLastError(VOID);
  WINBASEAPI VOID WINAPI SetLastError(DWORD dwErrCode);

#se_não_definido RC_INVOKED
#se_definido WINBASE_DECLARE_RESTORE_LAST_ERROR
  WINBASEAPI VOID WINAPI RestoreLastError(DWORD dwErrCode);

  defina_tipo VOID (WINAPI *PRESTORE_LAST_ERROR)(DWORD);

#defina RESTORE_LAST_ERROR_NAME_A "RestoreLastError"
#defina RESTORE_LAST_ERROR_NAME_W L"RestoreLastError"
#defina RESTORE_LAST_ERROR_NAME TEXT("RestoreLastError")
#fim_se
#fim_se

#defina HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->Internal)!=STATUS_PENDING)

  WINBASEAPI WINBOOL WINAPI GetOverlappedResult(HANDLE hFile,LPOVERLAPPED lpOverlapped,LPDWORD lpNumberOfBytesTransferred,WINBOOL bWait);
  WINBASEAPI HANDLE WINAPI CreateIoCompletionPort(HANDLE FileHandle,HANDLE ExistingCompletionPort,ULONG_PTR CompletionKey,DWORD NumberOfConcurrentThreads);
  WINBASEAPI WINBOOL WINAPI GetQueuedCompletionStatus(HANDLE CompletionPort,LPDWORD lpNumberOfBytesTransferred,PULONG_PTR lpCompletionKey,LPOVERLAPPED *lpOverlapped,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI PostQueuedCompletionStatus(HANDLE CompletionPort,DWORD dwNumberOfBytesTransferred,ULONG_PTR dwCompletionKey,LPOVERLAPPED lpOverlapped);

#defina SEM_FAILCRITICALERRORS 0x1
#defina SEM_NOGPFAULTERRORBOX 0x2
#defina SEM_NOALIGNMENTFAULTEXCEPT 0x4
#defina SEM_NOOPENFILEERRORBOX 0x8000

  WINBASEAPI UINT WINAPI SetErrorMode(UINT uMode);
  WINBASEAPI WINBOOL WINAPI ReadProcessMemory(HANDLE hProcess,LPCVOID lpBaseAddress,LPVOID lpBuffer,SIZE_T nSize,SIZE_T *lpNumberOfBytesRead);
  WINBASEAPI WINBOOL WINAPI WriteProcessMemory(HANDLE hProcess,LPVOID lpBaseAddress,LPCVOID lpBuffer,SIZE_T nSize,SIZE_T *lpNumberOfBytesWritten);
  WINBASEAPI WINBOOL WINAPI GetThreadContext(HANDLE hThread,LPCONTEXT lpContext);
  WINBASEAPI WINBOOL WINAPI SetThreadContext(HANDLE hThread,CONST CONTEXT *lpContext);
  WINBASEAPI DWORD WINAPI SuspendThread(HANDLE hThread);
  WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);

  defina_tipo VOID (WINAPI *PAPCFUNC)(ULONG_PTR dwParam);

  WINBASEAPI DWORD WINAPI QueueUserAPC(PAPCFUNC pfnAPC,HANDLE hThread,ULONG_PTR dwData);
  WINBASEAPI WINBOOL WINAPI IsDebuggerPresent(VOID);
  WINBASEAPI WINBOOL WINAPI CheckRemoteDebuggerPresent(HANDLE hProcess,PBOOL pbDebuggerPresent);
  WINBASEAPI VOID WINAPI DebugBreak(VOID);
  WINBASEAPI WINBOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI ContinueDebugEvent(DWORD dwProcessId,DWORD dwThreadId,DWORD dwContinueStatus);
  WINBASEAPI WINBOOL WINAPI DebugActiveProcess(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI DebugActiveProcessStop(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI DebugSetProcessKillOnExit(WINBOOL KillOnExit);
  WINBASEAPI WINBOOL WINAPI DebugBreakProcess(HANDLE Process);
  WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION lpCriticalSection,DWORD dwSpinCount);
  WINBASEAPI DWORD WINAPI SetCriticalSectionSpinCount(LPCRITICAL_SECTION lpCriticalSection,DWORD dwSpinCount);
  WINBASEAPI WINBOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI SetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ResetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI PulseEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore,LONG lReleaseCount,LPLONG lpPreviousCount);
  WINBASEAPI WINBOOL WINAPI ReleaseMutex(HANDLE hMutex);
  WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds);
  WINBASEAPI DWORD WINAPI WaitForMultipleObjects(DWORD nCount,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds);
  WINBASEAPI VOID WINAPI Sleep(DWORD dwMilliseconds);
  WINBASEAPI HGLOBAL WINAPI LoadResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI DWORD WINAPI SizeofResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM nAtom);
  WINBASEAPI WINBOOL WINAPI InitAtomTable(DWORD nSize);
  WINBASEAPI ATOM WINAPI DeleteAtom(ATOM nAtom);
  WINBASEAPI UINT WINAPI SetHandleCount(UINT uNumber);
  WINBASEAPI DWORD WINAPI GetLogicalDrives(VOID);
  WINBASEAPI WINBOOL WINAPI LockFile(HANDLE hFile,DWORD dwFileOffsetLow,DWORD dwFileOffsetHigh,DWORD nNumberOfBytesToLockLow,DWORD nNumberOfBytesToLockHigh);
  WINBASEAPI WINBOOL WINAPI UnlockFile(HANDLE hFile,DWORD dwFileOffsetLow,DWORD dwFileOffsetHigh,DWORD nNumberOfBytesToUnlockLow,DWORD nNumberOfBytesToUnlockHigh);
  WINBASEAPI WINBOOL WINAPI LockFileEx(HANDLE hFile,DWORD dwFlags,DWORD dwReserved,DWORD nNumberOfBytesToLockLow,DWORD nNumberOfBytesToLockHigh,LPOVERLAPPED lpOverlapped);

#defina LOCKFILE_FAIL_IMMEDIATELY 0x1
#defina LOCKFILE_EXCLUSIVE_LOCK 0x2

  WINBASEAPI WINBOOL WINAPI UnlockFileEx(HANDLE hFile,DWORD dwReserved,DWORD nNumberOfBytesToUnlockLow,DWORD nNumberOfBytesToUnlockHigh,LPOVERLAPPED lpOverlapped);

  defina_tipo estrutura _BY_HANDLE_FILE_INFORMATION {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD dwVolumeSerialNumber;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD nNumberOfLinks;
    DWORD nFileIndexHigh;
    DWORD nFileIndexLow;
  } BY_HANDLE_FILE_INFORMATION,*PBY_HANDLE_FILE_INFORMATION,*LPBY_HANDLE_FILE_INFORMATION;

#se_definido UNICODE
#defina SetFileShortName SetFileShortNameW
#senão
#defina SetFileShortName SetFileShortNameA
#fim_se

  WINBASEAPI WINBOOL WINAPI GetFileInformationByHandle(HANDLE hFile,LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
  WINBASEAPI DWORD WINAPI GetFileType(HANDLE hFile);
  WINBASEAPI DWORD WINAPI GetFileSize(HANDLE hFile,LPDWORD lpFileSizeHigh);
  WINBASEAPI WINBOOL WINAPI GetFileSizeEx(HANDLE hFile,PLARGE_INTEGER lpFileSize);
  WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
  WINBASEAPI WINBOOL WINAPI SetStdHandle(DWORD nStdHandle,HANDLE hHandle);
  WINBASEAPI WINBOOL WINAPI WriteFile(HANDLE hFile,LPCVOID lpBuffer,DWORD nNumberOfBytesToWrite,LPDWORD lpNumberOfBytesWritten,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI ReadFile(HANDLE hFile,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,LPDWORD lpNumberOfBytesRead,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI FlushFileBuffers(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI DeviceIoControl(HANDLE hDevice,DWORD dwIoControlCode,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesReturned,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI RequestDeviceWakeup(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI CancelDeviceWakeupRequest(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI GetDevicePowerState(HANDLE hDevice,WINBOOL *pfOn);
  WINBASEAPI WINBOOL WINAPI SetMessageWaitingIndicator(HANDLE hMsgIndicator,ULONG ulMsgCount);
  WINBASEAPI WINBOOL WINAPI SetEndOfFile(HANDLE hFile);
  WINBASEAPI DWORD WINAPI SetFilePointer(HANDLE hFile,LONG lDistanceToMove,PLONG lpDistanceToMoveHigh,DWORD dwMoveMethod);
  WINBASEAPI WINBOOL WINAPI SetFilePointerEx(HANDLE hFile,LARGE_INTEGER liDistanceToMove,PLARGE_INTEGER lpNewFilePointer,DWORD dwMoveMethod);
  WINBASEAPI WINBOOL WINAPI FindClose(HANDLE hFindFile);
  WINBASEAPI WINBOOL WINAPI GetFileTime(HANDLE hFile,LPFILETIME lpCreationTime,LPFILETIME lpLastAccessTime,LPFILETIME lpLastWriteTime);
  WINBASEAPI WINBOOL WINAPI SetFileTime(HANDLE hFile,CONST FILETIME *lpCreationTime,CONST FILETIME *lpLastAccessTime,CONST FILETIME *lpLastWriteTime);
  WINBASEAPI WINBOOL WINAPI SetFileValidData(HANDLE hFile,LONGLONG ValidDataLength);
  WINBASEAPI WINBOOL WINAPI SetFileShortNameA(HANDLE hFile,LPCSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI SetFileShortNameW(HANDLE hFile,LPCWSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI CloseHandle(HANDLE hObject);
  WINBASEAPI WINBOOL WINAPI DuplicateHandle(HANDLE hSourceProcessHandle,HANDLE hSourceHandle,HANDLE hTargetProcessHandle,LPHANDLE lpTargetHandle,DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwOptions);
  WINBASEAPI WINBOOL WINAPI GetHandleInformation(HANDLE hObject,LPDWORD lpdwFlags);
  WINBASEAPI WINBOOL WINAPI SetHandleInformation(HANDLE hObject,DWORD dwMask,DWORD dwFlags);

#defina HANDLE_FLAG_INHERIT 0x1
#defina HANDLE_FLAG_PROTECT_FROM_CLOSE 0x2

#defina HINSTANCE_ERROR 32

  WINBASEAPI DWORD WINAPI LoadModule(LPCSTR lpModuleName,LPVOID lpParameterBlock);
  WINBASEAPI UINT WINAPI WinExec(LPCSTR lpCmdLine,UINT uCmdShow);
  WINBASEAPI WINBOOL WINAPI ClearCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ClearCommError(HANDLE hFile,LPDWORD lpErrors,LPCOMSTAT lpStat);
  WINBASEAPI WINBOOL WINAPI SetupComm(HANDLE hFile,DWORD dwInQueue,DWORD dwOutQueue);
  WINBASEAPI WINBOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);
  WINBASEAPI WINBOOL WINAPI GetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,LPDWORD lpdwSize);
  WINBASEAPI WINBOOL WINAPI GetCommMask(HANDLE hFile,LPDWORD lpEvtMask);
  WINBASEAPI WINBOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
  WINBASEAPI WINBOOL WINAPI GetCommModemStatus(HANDLE hFile,LPDWORD lpModemStat);
  WINBASEAPI WINBOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI SetCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI SetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,DWORD dwSize);
  WINBASEAPI WINBOOL WINAPI SetCommMask(HANDLE hFile,DWORD dwEvtMask);
  WINBASEAPI WINBOOL WINAPI SetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI SetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI TransmitCommChar(HANDLE hFile,caractere cChar);
  WINBASEAPI WINBOOL WINAPI WaitCommEvent(HANDLE hFile,LPDWORD lpEvtMask,LPOVERLAPPED lpOverlapped);
  WINBASEAPI DWORD WINAPI SetTapePosition(HANDLE hDevice,DWORD dwPositionMethod,DWORD dwPartition,DWORD dwOffsetLow,DWORD dwOffsetHigh,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI GetTapePosition(HANDLE hDevice,DWORD dwPositionType,LPDWORD lpdwPartition,LPDWORD lpdwOffsetLow,LPDWORD lpdwOffsetHigh);
  WINBASEAPI DWORD WINAPI PrepareTape(HANDLE hDevice,DWORD dwOperation,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI EraseTape(HANDLE hDevice,DWORD dwEraseType,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI CreateTapePartition(HANDLE hDevice,DWORD dwPartitionMethod,DWORD dwCount,DWORD dwSize);
  WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE hDevice,DWORD dwTapemarkType,DWORD dwTapemarkCount,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI GetTapeStatus(HANDLE hDevice);
  WINBASEAPI DWORD WINAPI GetTapeParameters(HANDLE hDevice,DWORD dwOperation,LPDWORD lpdwSize,LPVOID lpTapeInformation);

#defina GET_TAPE_MEDIA_INFORMATION 0
#defina GET_TAPE_DRIVE_INFORMATION 1

  WINBASEAPI DWORD WINAPI SetTapeParameters(HANDLE hDevice,DWORD dwOperation,LPVOID lpTapeInformation);

#defina SET_TAPE_MEDIA_INFORMATION 0
#defina SET_TAPE_DRIVE_INFORMATION 1

  WINBASEAPI WINBOOL WINAPI Beep(DWORD dwFreq,DWORD dwDuration);
  WINBASEAPI inteiro WINAPI MulDiv(inteiro nNumber,inteiro nNumerator,inteiro nDenominator);
  WINBASEAPI VOID WINAPI GetSystemTime(LPSYSTEMTIME lpSystemTime);
  WINBASEAPI VOID WINAPI GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime);
  WINBASEAPI WINBOOL WINAPI SetSystemTime(CONST SYSTEMTIME *lpSystemTime);
  WINBASEAPI VOID WINAPI GetLocalTime(LPSYSTEMTIME lpSystemTime);
  WINBASEAPI WINBOOL WINAPI SetLocalTime(CONST SYSTEMTIME *lpSystemTime);
  WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI SetSystemFileCacheSize(SIZE_T MinimumFileCacheSize,SIZE_T MaximumFileCacheSize,DWORD Flags);
  WINBASEAPI WINBOOL WINAPI GetSystemFileCacheSize(PSIZE_T lpMinimumFileCacheSize,PSIZE_T lpMaximumFileCacheSize,PDWORD lpFlags);
  WINBASEAPI WINBOOL WINAPI GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,PDWORD pdwQuotaUsed);
  WINBOOL WINAPI GetSystemTimes(LPFILETIME lpIdleTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
  WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature);

  defina_tipo estrutura _TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
  } TIME_ZONE_INFORMATION,*PTIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;

#se_definido UNICODE
#defina FormatMessage FormatMessageW
#senão
#defina FormatMessage FormatMessageA
#fim_se

  WINBASEAPI WINBOOL WINAPI SystemTimeToTzSpecificLocalTime(LPTIME_ZONE_INFORMATION lpTimeZoneInformation,LPSYSTEMTIME lpUniversalTime,LPSYSTEMTIME lpLocalTime);
  WINBASEAPI WINBOOL WINAPI TzSpecificLocalTimeToSystemTime(LPTIME_ZONE_INFORMATION lpTimeZoneInformation,LPSYSTEMTIME lpLocalTime,LPSYSTEMTIME lpUniversalTime);
  WINBASEAPI DWORD WINAPI GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation);
  WINBASEAPI WINBOOL WINAPI SetTimeZoneInformation(CONST TIME_ZONE_INFORMATION *lpTimeZoneInformation);
  WINBASEAPI WINBOOL WINAPI SystemTimeToFileTime(CONST SYSTEMTIME *lpSystemTime,LPFILETIME lpFileTime);
  WINBASEAPI WINBOOL WINAPI FileTimeToLocalFileTime(CONST FILETIME *lpFileTime,LPFILETIME lpLocalFileTime);
  WINBASEAPI WINBOOL WINAPI LocalFileTimeToFileTime(CONST FILETIME *lpLocalFileTime,LPFILETIME lpFileTime);
  WINBASEAPI WINBOOL WINAPI FileTimeToSystemTime(CONST FILETIME *lpFileTime,LPSYSTEMTIME lpSystemTime);
  WINBASEAPI LONG WINAPI CompareFileTime(CONST FILETIME *lpFileTime1,CONST FILETIME *lpFileTime2);
  WINBASEAPI WINBOOL WINAPI FileTimeToDosDateTime(CONST FILETIME *lpFileTime,LPWORD lpFatDate,LPWORD lpFatTime);
  WINBASEAPI WINBOOL WINAPI DosDateTimeToFileTime(WORD wFatDate,WORD wFatTime,LPFILETIME lpFileTime);
  WINBASEAPI DWORD WINAPI GetTickCount(VOID);
  WINBASEAPI WINBOOL WINAPI SetSystemTimeAdjustment(DWORD dwTimeAdjustment,WINBOOL bTimeAdjustmentDisabled);
  WINBASEAPI WINBOOL WINAPI GetSystemTimeAdjustment(PDWORD lpTimeAdjustment,PDWORD lpTimeIncrement,PBOOL lpTimeAdjustmentDisabled);
  WINBASEAPI DWORD WINAPI FormatMessageA(DWORD dwFlags,LPCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,LPSTR lpBuffer,DWORD nSize,va_list *Arguments);
  WINBASEAPI DWORD WINAPI FormatMessageW(DWORD dwFlags,LPCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,LPWSTR lpBuffer,DWORD nSize,va_list *Arguments);

#defina FORMAT_MESSAGE_ALLOCATE_BUFFER 0x100
#defina FORMAT_MESSAGE_IGNORE_INSERTS 0x200
#defina FORMAT_MESSAGE_FROM_STRING 0x400
#defina FORMAT_MESSAGE_FROM_HMODULE 0x800
#defina FORMAT_MESSAGE_FROM_SYSTEM 0x1000
#defina FORMAT_MESSAGE_ARGUMENT_ARRAY 0x2000
#defina FORMAT_MESSAGE_MAX_WIDTH_MASK 0xff

#se_definido UNICODE
#defina CreateMailslot CreateMailslotW
#defina EncryptFile EncryptFileW
#defina DecryptFile DecryptFileW
#defina FileEncryptionStatus FileEncryptionStatusW
#senão
#defina CreateMailslot CreateMailslotA
#defina EncryptFile EncryptFileA
#defina DecryptFile DecryptFileA
#defina FileEncryptionStatus FileEncryptionStatusA
#fim_se

  WINBASEAPI WINBOOL WINAPI CreatePipe(PHANDLE hReadPipe,PHANDLE hWritePipe,LPSECURITY_ATTRIBUTES lpPipeAttributes,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI ConnectNamedPipe(HANDLE hNamedPipe,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI DisconnectNamedPipe(HANDLE hNamedPipe);
  WINBASEAPI WINBOOL WINAPI SetNamedPipeHandleState(HANDLE hNamedPipe,LPDWORD lpMode,LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeInfo(HANDLE hNamedPipe,LPDWORD lpFlags,LPDWORD lpOutBufferSize,LPDWORD lpInBufferSize,LPDWORD lpMaxInstances);
  WINBASEAPI WINBOOL WINAPI PeekNamedPipe(HANDLE hNamedPipe,LPVOID lpBuffer,DWORD nBufferSize,LPDWORD lpBytesRead,LPDWORD lpTotalBytesAvail,LPDWORD lpBytesLeftThisMessage);
  WINBASEAPI WINBOOL WINAPI TransactNamedPipe(HANDLE hNamedPipe,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesRead,LPOVERLAPPED lpOverlapped);
  WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR lpName,DWORD nMaxMessageSize,DWORD lReadTimeout,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR lpName,DWORD nMaxMessageSize,DWORD lReadTimeout,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI GetMailslotInfo(HANDLE hMailslot,LPDWORD lpMaxMessageSize,LPDWORD lpNextSize,LPDWORD lpMessageCount,LPDWORD lpReadTimeout);
  WINBASEAPI WINBOOL WINAPI SetMailslotInfo(HANDLE hMailslot,DWORD lReadTimeout);
  WINBASEAPI LPVOID WINAPI MapViewOfFile(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dwFileOffsetHigh,DWORD dwFileOffsetLow,SIZE_T dwNumberOfBytesToMap);
  WINBASEAPI WINBOOL WINAPI FlushViewOfFile(LPCVOID lpBaseAddress,SIZE_T dwNumberOfBytesToFlush);
  WINBASEAPI WINBOOL WINAPI UnmapViewOfFile(LPCVOID lpBaseAddress);
  WINADVAPI WINBOOL WINAPI EncryptFileA(LPCSTR lpFileName);
  WINADVAPI WINBOOL WINAPI EncryptFileW(LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI DecryptFileA(LPCSTR lpFileName,DWORD dwReserved);
  WINADVAPI WINBOOL WINAPI DecryptFileW(LPCWSTR lpFileName,DWORD dwReserved);

#defina FILE_ENCRYPTABLE 0
#defina FILE_IS_ENCRYPTED 1
#defina FILE_SYSTEM_ATTR 2
#defina FILE_ROOT_DIR 3
#defina FILE_SYSTEM_DIR 4
#defina FILE_UNKNOWN 5
#defina FILE_SYSTEM_NOT_SUPPORT 6
#defina FILE_USER_DISALLOWED 7
#defina FILE_READ_ONLY 8
#defina FILE_DIR_DISALLOWED 9

  WINADVAPI WINBOOL WINAPI FileEncryptionStatusA(LPCSTR lpFileName,LPDWORD lpStatus);
  WINADVAPI WINBOOL WINAPI FileEncryptionStatusW(LPCWSTR lpFileName,LPDWORD lpStatus);

#defina EFS_USE_RECOVERY_KEYS (0x1)

  defina_tipo DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE pbData,PVOID pvCallbackContext,ULONG ulLength);
  defina_tipo DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE pbData,PVOID pvCallbackContext,PULONG ulLength);

#defina CREATE_FOR_IMPORT (1)
#defina CREATE_FOR_DIR (2)
#defina OVERWRITE_HIDDEN (4)

#se_definido UNICODE
#defina OpenEncryptedFileRaw OpenEncryptedFileRawW
#defina lstrcmp lstrcmpW
#defina lstrcmpi lstrcmpiW
#defina lstrcpyn lstrcpynW
#defina lstrcpy lstrcpyW
#defina lstrcat lstrcatW
#defina lstrlen lstrlenW
#senão
#defina OpenEncryptedFileRaw OpenEncryptedFileRawA
#defina lstrcmp lstrcmpA
#defina lstrcmpi lstrcmpiA
#defina lstrcpyn lstrcpynA
#defina lstrcpy lstrcpyA
#defina lstrcat lstrcatA
#defina lstrlen lstrlenA
#fim_se

  WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC pfExportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC pfImportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID pvContext);
  WINBASEAPI inteiro WINAPI lstrcmpA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI inteiro WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI inteiro WINAPI lstrcmpiA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI inteiro WINAPI lstrcmpiW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR lpString1,LPCSTR lpString2,inteiro iMaxLength);
  WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR lpString1,LPCWSTR lpString2,inteiro iMaxLength);
  WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI inteiro WINAPI lstrlenA(LPCSTR lpString);
  WINBASEAPI inteiro WINAPI lstrlenW(LPCWSTR lpString);
  WINBASEAPI HFILE WINAPI OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle);
  WINBASEAPI HFILE WINAPI _lopen(LPCSTR lpPathName,inteiro iReadWrite);
  WINBASEAPI HFILE WINAPI _lcreat(LPCSTR lpPathName,inteiro iAttribute);
  WINBASEAPI UINT WINAPI _lread(HFILE hFile,LPVOID lpBuffer,UINT uBytes);
  WINBASEAPI UINT WINAPI _lwrite(HFILE hFile,LPCCH lpBuffer,UINT uBytes);
  WINBASEAPI longo WINAPI _hread(HFILE hFile,LPVOID lpBuffer,longo lBytes);
  WINBASEAPI longo WINAPI _hwrite(HFILE hFile,LPCCH lpBuffer,longo lBytes);
  WINBASEAPI HFILE WINAPI _lclose(HFILE hFile);
  WINBASEAPI LONG WINAPI _llseek(HFILE hFile,LONG lOffset,inteiro iOrigin);
  WINADVAPI WINBOOL WINAPI IsTextUnicode(CONST VOID *lpv,inteiro iSize,LPINT lpiResult);

#defina FLS_OUT_OF_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  WINBASEAPI PVOID WINAPI FlsGetValue(DWORD dwFlsIndex);
  WINBASEAPI WINBOOL WINAPI FlsSetValue(DWORD dwFlsIndex,PVOID lpFlsData);
  WINBASEAPI WINBOOL WINAPI FlsFree(DWORD dwFlsIndex);

#defina TLS_OUT_OF_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
  WINBASEAPI LPVOID WINAPI TlsGetValue(DWORD dwTlsIndex);
  WINBASEAPI WINBOOL WINAPI TlsSetValue(DWORD dwTlsIndex,LPVOID lpTlsValue);
  WINBASEAPI WINBOOL WINAPI TlsFree(DWORD dwTlsIndex);

  defina_tipo VOID (WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwErrorCode,DWORD dwNumberOfBytesTransfered,LPOVERLAPPED lpOverlapped);

  WINBASEAPI DWORD WINAPI SleepEx(DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForMultipleObjectsEx(DWORD nCount,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE hObjectToSignal,HANDLE hObjectToWaitOn,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI WINBOOL WINAPI ReadFileEx(HANDLE hFile,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI WriteFileEx(HANDLE hFile,LPCVOID lpBuffer,DWORD nNumberOfBytesToWrite,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI BackupRead(HANDLE hFile,LPBYTE lpBuffer,DWORD nNumberOfBytesToRead,LPDWORD lpNumberOfBytesRead,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupSeek(HANDLE hFile,DWORD dwLowBytesToSeek,DWORD dwHighBytesToSeek,LPDWORD lpdwLowByteSeeked,LPDWORD lpdwHighByteSeeked,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupWrite(HANDLE hFile,LPBYTE lpBuffer,DWORD nNumberOfBytesToWrite,LPDWORD lpNumberOfBytesWritten,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);

  defina_tipo estrutura _WIN32_STREAM_ID {
    DWORD dwStreamId;
    DWORD dwStreamAttributes;
    LARGE_INTEGER Size;
    DWORD dwStreamNameSize;
    WCHAR cStreamName[ANYSIZE_ARRAY];
  } WIN32_STREAM_ID,*LPWIN32_STREAM_ID;

#defina BACKUP_INVALID 0x0
#defina BACKUP_DATA 0x1
#defina BACKUP_EA_DATA 0x2
#defina BACKUP_SECURITY_DATA 0x3
#defina BACKUP_ALTERNATE_DATA 0x4
#defina BACKUP_LINK 0x5
#defina BACKUP_PROPERTY_DATA 0x6
#defina BACKUP_OBJECT_ID 0x7
#defina BACKUP_REPARSE_DATA 0x8
#defina BACKUP_SPARSE_BLOCK 0x9

#defina STREAM_NORMAL_ATTRIBUTE 0x0
#defina STREAM_MODIFIED_WHEN_READ 0x1
#defina STREAM_CONTAINS_SECURITY 0x2
#defina STREAM_CONTAINS_PROPERTIES 0x4
#defina STREAM_SPARSE_ATTRIBUTE 0x8

  WINBASEAPI WINBOOL WINAPI ReadFileScatter(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD nNumberOfBytesToRead,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI WriteFileGather(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD nNumberOfBytesToWrite,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);

#defina STARTF_USESHOWWINDOW 0x1
#defina STARTF_USESIZE 0x2
#defina STARTF_USEPOSITION 0x4
#defina STARTF_USECOUNTCHARS 0x8
#defina STARTF_USEFILLATTRIBUTE 0x10
#defina STARTF_RUNFULLSCREEN 0x20
#defina STARTF_FORCEONFEEDBACK 0x40
#defina STARTF_FORCEOFFFEEDBACK 0x80
#defina STARTF_USESTDHANDLES 0x100

#defina STARTF_USEHOTKEY 0x200

  defina_tipo estrutura _STARTUPINFOA {
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOA,*LPSTARTUPINFOA;

  defina_tipo estrutura _STARTUPINFOW {
    DWORD cb;
    LPWSTR lpReserved;
    LPWSTR lpDesktop;
    LPWSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOW,*LPSTARTUPINFOW;

#se_definido UNICODE
  defina_tipo STARTUPINFOW STARTUPINFO;
  defina_tipo LPSTARTUPINFOW LPSTARTUPINFO;
#senão
  defina_tipo STARTUPINFOA STARTUPINFO;
  defina_tipo LPSTARTUPINFOA LPSTARTUPINFO;
#fim_se

#defina SHUTDOWN_NORETRY 0x1

  defina_tipo estrutura _WIN32_FIND_DATAA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[MAX_PATH];
    CHAR cAlternateFileName[14];
  } WIN32_FIND_DATAA,*PWIN32_FIND_DATAA,*LPWIN32_FIND_DATAA;

  defina_tipo estrutura _WIN32_FIND_DATAW {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[MAX_PATH];
    WCHAR cAlternateFileName[14];
  } WIN32_FIND_DATAW,*PWIN32_FIND_DATAW,*LPWIN32_FIND_DATAW;

#se_definido UNICODE
  defina_tipo WIN32_FIND_DATAW WIN32_FIND_DATA;
  defina_tipo PWIN32_FIND_DATAW PWIN32_FIND_DATA;
  defina_tipo LPWIN32_FIND_DATAW LPWIN32_FIND_DATA;
#senão
  defina_tipo WIN32_FIND_DATAA WIN32_FIND_DATA;
  defina_tipo PWIN32_FIND_DATAA PWIN32_FIND_DATA;
  defina_tipo LPWIN32_FIND_DATAA LPWIN32_FIND_DATA;
#fim_se

  defina_tipo estrutura _WIN32_FILE_ATTRIBUTE_DATA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
  } WIN32_FILE_ATTRIBUTE_DATA,*LPWIN32_FILE_ATTRIBUTE_DATA;

#se_definido UNICODE
#defina CreateMutex CreateMutexW
#defina OpenMutex OpenMutexW
#defina CreateEvent CreateEventW
#defina OpenEvent OpenEventW
#defina CreateSemaphore CreateSemaphoreW
#defina OpenSemaphore OpenSemaphoreW
#senão
#defina CreateMutex CreateMutexA
#defina OpenMutex OpenMutexA
#defina CreateEvent CreateEventA
#defina OpenEvent OpenEventA
#defina CreateSemaphore CreateSemaphoreA
#defina OpenSemaphore OpenSemaphoreA
#fim_se

  WINBASEAPI HANDLE WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes,WINBOOL bInitialOwner,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes,WINBOOL bInitialOwner,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes,WINBOOL bManualReset,WINBOOL bInitialState,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes,WINBOOL bManualReset,WINBOOL bInitialState,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,LONG lInitialCount,LONG lMaximumCount,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,LONG lInitialCount,LONG lMaximumCount,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);

  defina_tipo VOID (WINAPI *PTIMERAPCROUTINE)(LPVOID lpArgToCompletionRoutine,DWORD dwTimerLowValue,DWORD dwTimerHighValue);

#se_definido UNICODE
#defina CreateWaitableTimer CreateWaitableTimerW
#defina OpenWaitableTimer OpenWaitableTimerW
#defina CreateFileMapping CreateFileMappingW
#defina OpenFileMapping OpenFileMappingW
#defina GetLogicalDriveStrings GetLogicalDriveStringsW
#defina LoadLibrary LoadLibraryW
#defina LoadLibraryEx LoadLibraryExW
#defina GetModuleFileName GetModuleFileNameW
#defina GetModuleHandle GetModuleHandleW
#senão
#defina CreateWaitableTimer CreateWaitableTimerA
#defina OpenWaitableTimer OpenWaitableTimerA
#defina CreateFileMapping CreateFileMappingA
#defina OpenFileMapping OpenFileMappingA
#defina GetLogicalDriveStrings GetLogicalDriveStringsA
#defina LoadLibrary LoadLibraryA
#defina LoadLibraryEx LoadLibraryExA
#defina GetModuleFileName GetModuleFileNameA
#defina GetModuleHandle GetModuleHandleA
#fim_se

  WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_ATTRIBUTES lpTimerAttributes,WINBOOL bManualReset,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_ATTRIBUTES lpTimerAttributes,WINBOOL bManualReset,LPCWSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpTimerName);
  WINBASEAPI WINBOOL WINAPI SetWaitableTimer(HANDLE hTimer,constante LARGE_INTEGER *lpDueTime,LONG lPeriod,PTIMERAPCROUTINE pfnCompletionRoutine,LPVOID lpArgToCompletionRoutine,WINBOOL fResume);
  WINBASEAPI WINBOOL WINAPI CancelWaitableTimer(HANDLE hTimer);
  WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE hFile,LPSECURITY_ATTRIBUTES lpFileMappingAttributes,DWORD flProtect,DWORD dwMaximumSizeHigh,DWORD dwMaximumSizeLow,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE hFile,LPSECURITY_ATTRIBUTES lpFileMappingAttributes,DWORD flProtect,DWORD dwMaximumSizeHigh,DWORD dwMaximumSizeLow,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI DWORD WINAPI GetLogicalDriveStringsA(DWORD nBufferLength,LPSTR lpBuffer);
  WINBASEAPI DWORD WINAPI GetLogicalDriveStringsW(DWORD nBufferLength,LPWSTR lpBuffer);

  defina_tipo enumeração _MEMORY_RESOURCE_NOTIFICATION_TYPE {
    LowMemoryResourceNotification,HighMemoryResourceNotification
  } MEMORY_RESOURCE_NOTIFICATION_TYPE;

  WINBASEAPI HANDLE WINAPI CreateMemoryResourceNotification(MEMORY_RESOURCE_NOTIFICATION_TYPE NotificationType);
  WINBASEAPI WINBOOL WINAPI QueryMemoryResourceNotification(HANDLE ResourceNotificationHandle,PBOOL ResourceState);
  WINBASEAPI HMODULE WINAPI LoadLibraryA(LPCSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI LoadLibraryW(LPCWSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI LoadLibraryExA(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
  WINBASEAPI HMODULE WINAPI LoadLibraryExW(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);

#defina DONT_RESOLVE_DLL_REFERENCES 0x1
#defina LOAD_LIBRARY_AS_DATAFILE 0x2
#defina LOAD_WITH_ALTERED_SEARCH_PATH 0x8
#defina LOAD_IGNORE_CODE_AUTHZ_LEVEL 0x10
#defina LOAD_LINRARY_AS_IMAGE_RESOURCE 0x20
#defina LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE 0x40

  WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE hModule,LPCH lpFilename,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE hModule,LPWCH lpFilename,DWORD nSize);
  WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
  WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

#se_não_definido RC_INVOKED
#defina GET_MODULE_HANDLE_EX_FLAG_PIN (0x1)
#defina GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT (0x2)
#defina GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS (0x4)

  defina_tipo WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXA)(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  defina_tipo WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXW)(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);

#se_definido UNICODE
#defina PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXW
#defina GetModuleHandleEx GetModuleHandleExW
#senão
#defina PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXA
#defina GetModuleHandleEx GetModuleHandleExA
#fim_se

  WINBASEAPI WINBOOL WINAPI GetModuleHandleExA(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  WINBASEAPI WINBOOL WINAPI GetModuleHandleExW(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);
#fim_se

#se_definido UNICODE
#defina NeedCurrentDirectoryForExePath NeedCurrentDirectoryForExePathW
#defina CreateProcess CreateProcessW
#defina FatalAppExit FatalAppExitW
#defina GetStartupInfo GetStartupInfoW
#defina GetCommandLine GetCommandLineW
#defina GetEnvironmentVariable GetEnvironmentVariableW
#defina SetEnvironmentVariable SetEnvironmentVariableW
#defina ExpandEnvironmentStrings ExpandEnvironmentStringsW
#defina GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
#defina SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableW
#defina OutputDebugString OutputDebugStringW
#defina FindResource FindResourceW
#defina FindResourceEx FindResourceExW
#senão
#defina NeedCurrentDirectoryForExePath NeedCurrentDirectoryForExePathA
#defina CreateProcess CreateProcessA
#defina FatalAppExit FatalAppExitA
#defina GetStartupInfo GetStartupInfoA
#defina GetCommandLine GetCommandLineA
#defina GetEnvironmentVariable GetEnvironmentVariableA
#defina SetEnvironmentVariable SetEnvironmentVariableA
#defina ExpandEnvironmentStrings ExpandEnvironmentStringsA
#defina GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
#defina SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableA
#defina OutputDebugString OutputDebugStringA
#defina FindResource FindResourceA
#defina FindResourceEx FindResourceExA
#fim_se

  WINBASEAPI WINBOOL WINAPI NeedCurrentDirectoryForExePathA(LPCSTR ExeName);
  WINBASEAPI WINBOOL WINAPI NeedCurrentDirectoryForExePathW(LPCWSTR ExeName);
  WINBASEAPI WINBOOL WINAPI CreateProcessA(LPCSTR lpApplicationName,LPSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI WINBOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName,LPWSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI DWORD WINAPI AddLocalAlternateComputerNameA(LPCSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI DWORD WINAPI AddLocalAlternateComputerNameW(LPCWSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI WINBOOL WINAPI SetProcessShutdownParameters(DWORD dwLevel,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel,LPDWORD lpdwFlags);
  WINBASEAPI DWORD WINAPI GetProcessVersion(DWORD ProcessId);
  WINBASEAPI VOID WINAPI FatalAppExitA(UINT uAction,LPCSTR lpMessageText);
  WINBASEAPI VOID WINAPI FatalAppExitW(UINT uAction,LPCWSTR lpMessageText);
  WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
  WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
  WINBASEAPI LPSTR WINAPI GetCommandLineA(VOID);
  WINBASEAPI LPWSTR WINAPI GetCommandLineW(VOID);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName,LPSTR lpBuffer,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName,LPWSTR lpBuffer,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentVariableA(LPCSTR lpName,LPCSTR lpValue);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpValue);
  WINBASEAPI DWORD WINAPI ExpandEnvironmentStringsA(LPCSTR lpSrc,LPSTR lpDst,DWORD nSize);
  WINBASEAPI DWORD WINAPI ExpandEnvironmentStringsW(LPCWSTR lpSrc,LPWSTR lpDst,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID pBuffer,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID pBuffer,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID pValue,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID pValue,DWORD nSize);
  WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);
  WINBASEAPI VOID WINAPI OutputDebugStringW(LPCWSTR lpOutputString);
  WINBASEAPI HRSRC WINAPI FindResourceA(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
  WINBASEAPI HRSRC WINAPI FindResourceW(HMODULE hModule,LPCWSTR lpName,LPCWSTR lpType);
  WINBASEAPI HRSRC WINAPI FindResourceExA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,WORD wLanguage);
  WINBASEAPI HRSRC WINAPI FindResourceExW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage);

#se_definido UNICODE
#defina ENUMRESTYPEPROC ENUMRESTYPEPROCW
#defina ENUMRESNAMEPROC ENUMRESNAMEPROCW
#defina ENUMRESLANGPROC ENUMRESLANGPROCW
#defina EnumResourceTypes EnumResourceTypesW
#defina EnumResourceNames EnumResourceNamesW
#defina EnumResourceLanguages EnumResourceLanguagesW
#defina BeginUpdateResource BeginUpdateResourceW
#defina UpdateResource UpdateResourceW
#defina EndUpdateResource EndUpdateResourceW
#defina GlobalAddAtom GlobalAddAtomW
#defina GlobalFindAtom GlobalFindAtomW
#defina GlobalGetAtomName GlobalGetAtomNameW
#defina AddAtom AddAtomW
#defina FindAtom FindAtomW
#defina GetAtomName GetAtomNameW
#defina GetProfileInt GetProfileIntW
#defina GetProfileString GetProfileStringW
#defina WriteProfileString WriteProfileStringW
#defina GetProfileSection GetProfileSectionW
#defina WriteProfileSection WriteProfileSectionW
#defina GetPrivateProfileInt GetPrivateProfileIntW
#defina GetPrivateProfileString GetPrivateProfileStringW
#defina WritePrivateProfileString WritePrivateProfileStringW
#defina GetPrivateProfileSection GetPrivateProfileSectionW
#defina WritePrivateProfileSection WritePrivateProfileSectionW
#defina GetPrivateProfileSectionNames GetPrivateProfileSectionNamesW
#defina GetPrivateProfileStruct GetPrivateProfileStructW
#defina WritePrivateProfileStruct WritePrivateProfileStructW
#defina GetDriveType GetDriveTypeW
#defina GetSystemDirectory GetSystemDirectoryW
#defina GetTempPath GetTempPathW
#defina GetTempFileName GetTempFileNameW
#defina GetWindowsDirectory GetWindowsDirectoryW
#defina GetSystemWindowsDirectory GetSystemWindowsDirectoryW
#defina AddLocalAlternateComputerName AddLocalAlternateComputerNameW
#senão
#defina ENUMRESTYPEPROC ENUMRESTYPEPROCA
#defina ENUMRESNAMEPROC ENUMRESNAMEPROCA
#defina ENUMRESLANGPROC ENUMRESLANGPROCA
#defina EnumResourceTypes EnumResourceTypesA
#defina EnumResourceNames EnumResourceNamesA
#defina EnumResourceLanguages EnumResourceLanguagesA
#defina BeginUpdateResource BeginUpdateResourceA
#defina UpdateResource UpdateResourceA
#defina EndUpdateResource EndUpdateResourceA
#defina GlobalAddAtom GlobalAddAtomA
#defina GlobalFindAtom GlobalFindAtomA
#defina GlobalGetAtomName GlobalGetAtomNameA
#defina AddAtom AddAtomA
#defina FindAtom FindAtomA
#defina GetAtomName GetAtomNameA
#defina GetProfileInt GetProfileIntA
#defina GetProfileString GetProfileStringA
#defina WriteProfileString WriteProfileStringA
#defina GetProfileSection GetProfileSectionA
#defina WriteProfileSection WriteProfileSectionA
#defina GetPrivateProfileInt GetPrivateProfileIntA
#defina GetPrivateProfileString GetPrivateProfileStringA
#defina WritePrivateProfileString WritePrivateProfileStringA
#defina GetPrivateProfileSection GetPrivateProfileSectionA
#defina WritePrivateProfileSection WritePrivateProfileSectionA
#defina GetPrivateProfileSectionNames GetPrivateProfileSectionNamesA
#defina GetPrivateProfileStruct GetPrivateProfileStructA
#defina WritePrivateProfileStruct WritePrivateProfileStructA
#defina GetDriveType GetDriveTypeA
#defina GetSystemDirectory GetSystemDirectoryA
#defina GetTempPath GetTempPathA
#defina GetTempFileName GetTempFileNameA
#defina GetWindowsDirectory GetWindowsDirectoryA
#defina GetSystemWindowsDirectory GetSystemWindowsDirectoryA
#defina AddLocalAlternateComputerName AddLocalAlternateComputerNameA
#fim_se

  defina_tipo WINBOOL (CALLBACK *ENUMRESTYPEPROCA)(HMODULE hModule,LPSTR lpType,LONG_PTR lParam);
  defina_tipo WINBOOL (CALLBACK *ENUMRESTYPEPROCW)(HMODULE hModule,LPWSTR lpType,LONG_PTR lParam);
  defina_tipo WINBOOL (CALLBACK *ENUMRESNAMEPROCA)(HMODULE hModule,LPCSTR lpType,LPSTR lpName,LONG_PTR lParam);
  defina_tipo WINBOOL (CALLBACK *ENUMRESNAMEPROCW)(HMODULE hModule,LPCWSTR lpType,LPWSTR lpName,LONG_PTR lParam);
  defina_tipo WINBOOL (CALLBACK *ENUMRESLANGPROCA)(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,WORD wLanguage,LONG_PTR lParam);
  defina_tipo WINBOOL (CALLBACK *ENUMRESLANGPROCW)(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage,LONG_PTR lParam);

  WINBASEAPI WINBOOL WINAPI EnumResourceTypesA(HMODULE hModule,ENUMRESTYPEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceTypesW(HMODULE hModule,ENUMRESTYPEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceNamesA(HMODULE hModule,LPCSTR lpType,ENUMRESNAMEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceNamesW(HMODULE hModule,LPCWSTR lpType,ENUMRESNAMEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ENUMRESLANGPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ENUMRESLANGPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI WINBOOL WINAPI UpdateResourceA(HANDLE hUpdate,LPCSTR lpType,LPCSTR lpName,WORD wLanguage,LPVOID lpData,DWORD cb);
  WINBASEAPI WINBOOL WINAPI UpdateResourceW(HANDLE hUpdate,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage,LPVOID lpData,DWORD cb);
  WINBASEAPI WINBOOL WINAPI EndUpdateResourceA(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI WINBOOL WINAPI EndUpdateResourceW(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI ATOM WINAPI GlobalAddAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalAddAtomW(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalFindAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalFindAtomW(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM nAtom,LPSTR lpBuffer,inteiro nSize);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM nAtom,LPWSTR lpBuffer,inteiro nSize);
  WINBASEAPI ATOM WINAPI AddAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI AddAtomW(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI FindAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI FindAtomW(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetAtomNameA(ATOM nAtom,LPSTR lpBuffer,inteiro nSize);
  WINBASEAPI UINT WINAPI GetAtomNameW(ATOM nAtom,LPWSTR lpBuffer,inteiro nSize);
  WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR lpAppName,LPCSTR lpKeyName,INT nDefault);
  WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR lpAppName,LPCWSTR lpKeyName,INT nDefault);
  WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpString);
  WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetPrivateProfileIntA(LPCSTR lpAppName,LPCSTR lpKeyName,INT nDefault,LPCSTR lpFileName);
  WINBASEAPI UINT WINAPI GetPrivateProfileIntW(LPCWSTR lpAppName,LPCWSTR lpKeyName,INT nDefault,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD nSize,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD nSize,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStringA(LPCSTR lpAppName,LPCSTR lpKeyName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStringW(LPCWSTR lpAppName,LPCWSTR lpKeyName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD nSize,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD nSize,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileSectionA(LPCSTR lpAppName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesA(LPSTR lpszReturnBuffer,DWORD nSize,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesW(LPWSTR lpszReturnBuffer,DWORD nSize,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI GetPrivateProfileStructA(LPCSTR lpszSection,LPCSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI GetPrivateProfileStructW(LPCWSTR lpszSection,LPCWSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCWSTR szFile);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStructA(LPCSTR lpszSection,LPCSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStructW(LPCWSTR lpszSection,LPCWSTR lpszKey,LPVOID lpStruct,UINT uSizeStruct,LPCWSTR szFile);
  WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR lpRootPathName);
  WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR lpRootPathName);
  WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR lpBuffer,UINT uSize);
  WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR lpBuffer,UINT uSize);
  WINBASEAPI DWORD WINAPI GetTempPathA(DWORD nBufferLength,LPSTR lpBuffer);
  WINBASEAPI DWORD WINAPI GetTempPathW(DWORD nBufferLength,LPWSTR lpBuffer);
  WINBASEAPI UINT WINAPI GetTempFileNameA(LPCSTR lpPathName,LPCSTR lpPrefixString,UINT uUnique,LPSTR lpTempFileName);
  WINBASEAPI UINT WINAPI GetTempFileNameW(LPCWSTR lpPathName,LPCWSTR lpPrefixString,UINT uUnique,LPWSTR lpTempFileName);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR lpBuffer,UINT uSize);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR lpBuffer,UINT uSize);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR lpBuffer,UINT uSize);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR lpBuffer,UINT uSize);

#se_não_definido RC_INVOKED
#se_definido UNICODE
#defina GetSystemWow64Directory GetSystemWow64DirectoryW
#senão
#defina GetSystemWow64Directory GetSystemWow64DirectoryA
#fim_se

  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR lpBuffer,UINT uSize);
  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR lpBuffer,UINT uSize);
  WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection);
  WINBASEAPI WINBOOL WINAPI Wow64DisableWow64FsRedirection(PVOID *OldValue);
  WINBASEAPI WINBOOL WINAPI Wow64RevertWow64FsRedirection(PVOID OlValue);

  defina_tipo UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR lpBuffer,UINT uSize);
  defina_tipo UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR lpBuffer,UINT uSize);

#defina GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A "GetSystemWow64DirectoryA"
#defina GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W L"GetSystemWow64DirectoryA"
#defina GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T TEXT("GetSystemWow64DirectoryA")
#defina GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A "GetSystemWow64DirectoryW"
#defina GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W L"GetSystemWow64DirectoryW"
#defina GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T TEXT("GetSystemWow64DirectoryW")

#se_definido UNICODE
#defina GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#defina GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#defina GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#senão
#defina GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#defina GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#defina GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#fim_se
#fim_se

#se_definido UNICODE
#defina SetCurrentDirectory SetCurrentDirectoryW
#defina GetCurrentDirectory GetCurrentDirectoryW
#defina SetDllDirectory SetDllDirectoryW
#defina GetDllDirectory GetDllDirectoryW
#defina GetDiskFreeSpace GetDiskFreeSpaceW
#defina GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#defina CreateDirectory CreateDirectoryW
#defina CreateDirectoryEx CreateDirectoryExW
#defina RemoveDirectory RemoveDirectoryW
#defina GetFullPathName GetFullPathNameW
#defina DefineDosDevice DefineDosDeviceW
#defina QueryDosDevice QueryDosDeviceW
#defina CreateFile CreateFileW
#defina SetFileAttributes SetFileAttributesW
#defina GetFileAttributes GetFileAttributesW
#senão
#defina SetCurrentDirectory SetCurrentDirectoryA
#defina GetCurrentDirectory GetCurrentDirectoryA
#defina SetDllDirectory SetDllDirectoryA
#defina GetDllDirectory GetDllDirectoryA
#defina GetDiskFreeSpace GetDiskFreeSpaceA
#defina GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#defina CreateDirectory CreateDirectoryA
#defina CreateDirectoryEx CreateDirectoryExA
#defina RemoveDirectory RemoveDirectoryA
#defina GetFullPathName GetFullPathNameA
#defina DefineDosDevice DefineDosDeviceA
#defina QueryDosDevice QueryDosDeviceA
#defina CreateFile CreateFileA
#defina SetFileAttributes SetFileAttributesA
#defina GetFileAttributes GetFileAttributesA
#fim_se

  WINBASEAPI WINBOOL WINAPI SetCurrentDirectoryA(LPCSTR lpPathName);
  WINBASEAPI WINBOOL WINAPI SetCurrentDirectoryW(LPCWSTR lpPathName);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD nBufferLength,LPSTR lpBuffer);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD nBufferLength,LPWSTR lpBuffer);
  WINBASEAPI WINBOOL WINAPI SetDllDirectoryA(LPCSTR lpPathName);
  WINBASEAPI WINBOOL WINAPI SetDllDirectoryW(LPCWSTR lpPathName);
  WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD nBufferLength,LPSTR lpBuffer);
  WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD nBufferLength,LPWSTR lpBuffer);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceA(LPCSTR lpRootPathName,LPDWORD lpSectorsPerCluster,LPDWORD lpBytesPerSector,LPDWORD lpNumberOfFreeClusters,LPDWORD lpTotalNumberOfClusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lpRootPathName,LPDWORD lpSectorsPerCluster,LPDWORD lpBytesPerSector,LPDWORD lpNumberOfFreeClusters,LPDWORD lpTotalNumberOfClusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpDirectoryName,PULARGE_INTEGER lpFreeBytesAvailableToCaller,PULARGE_INTEGER lpTotalNumberOfBytes,PULARGE_INTEGER lpTotalNumberOfFreeBytes);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,PULARGE_INTEGER lpFreeBytesAvailableToCaller,PULARGE_INTEGER lpTotalNumberOfBytes,PULARGE_INTEGER lpTotalNumberOfFreeBytes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryA(LPCSTR lpPathName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryW(LPCWSTR lpPathName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory,LPCSTR lpNewDirectory,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory,LPCWSTR lpNewDirectory,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryA(LPCSTR lpPathName);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryW(LPCWSTR lpPathName);
  WINBASEAPI DWORD WINAPI GetFullPathNameA(LPCSTR lpFileName,DWORD nBufferLength,LPSTR lpBuffer,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI GetFullPathNameW(LPCWSTR lpFileName,DWORD nBufferLength,LPWSTR lpBuffer,LPWSTR *lpFilePart);

#defina DDD_RAW_TARGET_PATH 0x1
#defina DDD_REMOVE_DEFINITION 0x2
#defina DDD_EXACT_MATCH_ON_REMOVE 0x4
#defina DDD_NO_BROADCAST_SYSTEM 0x8
#defina DDD_LUID_BROADCAST_DRIVE 0x10

  WINBASEAPI WINBOOL WINAPI DefineDosDeviceA(DWORD dwFlags,LPCSTR lpDeviceName,LPCSTR lpTargetPath);
  WINBASEAPI WINBOOL WINAPI DefineDosDeviceW(DWORD dwFlags,LPCWSTR lpDeviceName,LPCWSTR lpTargetPath);
  WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR lpDeviceName,LPSTR lpTargetPath,DWORD ucchMax);
  WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR lpDeviceName,LPWSTR lpTargetPath,DWORD ucchMax);

#defina EXPAND_LOCAL_DRIVES

  WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE hOriginalFile,DWORD dwDesiredAccess,DWORD dwShareMode,DWORD dwFlagsAndAttributes);
  WINBASEAPI WINBOOL WINAPI SetFileAttributesA(LPCSTR lpFileName,DWORD dwFileAttributes);
  WINBASEAPI WINBOOL WINAPI SetFileAttributesW(LPCWSTR lpFileName,DWORD dwFileAttributes);
  WINBASEAPI DWORD WINAPI GetFileAttributesA(LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetFileAttributesW(LPCWSTR lpFileName);

  defina_tipo enumeração _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard,GetFileExMaxInfoLevel
  } GET_FILEEX_INFO_LEVELS;

#se_definido UNICODE
#defina GetFileAttributesEx GetFileAttributesExW
#defina GetCompressedFileSize GetCompressedFileSizeW
#defina DeleteFile DeleteFileW
#defina CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
#senão
#defina GetFileAttributesEx GetFileAttributesExA
#defina GetCompressedFileSize GetCompressedFileSizeA
#defina DeleteFile DeleteFileA
#defina CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
#fim_se

  WINBASEAPI WINBOOL WINAPI GetFileAttributesExA(LPCSTR lpFileName,GET_FILEEX_INFO_LEVELS fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI WINBOOL WINAPI GetFileAttributesExW(LPCWSTR lpFileName,GET_FILEEX_INFO_LEVELS fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI DWORD WINAPI GetCompressedFileSizeA(LPCSTR lpFileName,LPDWORD lpFileSizeHigh);
  WINBASEAPI DWORD WINAPI GetCompressedFileSizeW(LPCWSTR lpFileName,LPDWORD lpFileSizeHigh);
  WINBASEAPI WINBOOL WINAPI DeleteFileA(LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR lpName,LPSTR lpOemName,DWORD OemNameSize,PBOOL pbNameContainsSpaces,PBOOL pbNameLegal);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR lpName,LPSTR lpOemName,DWORD OemNameSize,PBOOL pbNameContainsSpaces,PBOOL pbNameLegal);

  defina_tipo enumeração _FINDEX_INFO_LEVELS {
    FindExInfoStandard,FindExInfoMaxInfoLevel
  } FINDEX_INFO_LEVELS;

  defina_tipo enumeração _FINDEX_SEARCH_OPS {
    FindExSearchNameMatch,FindExSearchLimitToDirectories,FindExSearchLimitToDevices,FindExSearchMaxSearchOp
  } FINDEX_SEARCH_OPS;

#defina FIND_FIRST_EX_CASE_SENSITIVE 0x1

#se_definido UNICODE
#defina FindFirstFileEx FindFirstFileExW
#defina FindFirstFile FindFirstFileW
#defina FindNextFile FindNextFileW
#defina SearchPath SearchPathW
#defina CopyFile CopyFileW
#defina CopyFileEx CopyFileExW
#defina MoveFile MoveFileW
#defina MoveFileEx MoveFileExW
#defina MoveFileWithProgress MoveFileWithProgressW
#defina ReplaceFile ReplaceFileW
#defina CreateHardLink CreateHardLinkW
#defina CreateNamedPipe CreateNamedPipeW
#defina GetNamedPipeHandleState GetNamedPipeHandleStateW
#defina CallNamedPipe CallNamedPipeW
#defina WaitNamedPipe WaitNamedPipeW
#defina SetVolumeLabel SetVolumeLabelW
#defina GetVolumeInformation GetVolumeInformationW
#defina ClearEventLog ClearEventLogW
#defina BackupEventLog BackupEventLogW
#defina OpenEventLog OpenEventLogW
#defina RegisterEventSource RegisterEventSourceW
#defina OpenBackupEventLog OpenBackupEventLogW
#defina ReadEventLog ReadEventLogW
#defina ReportEvent ReportEventW
#defina AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#defina AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
#defina AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmW
#defina AccessCheckByTypeResultListAndAuditAlarmByHandle AccessCheckByTypeResultListAndAuditAlarmByHandleW
#defina ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#defina ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#defina ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#defina ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
#defina PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#defina SetFileSecurity SetFileSecurityW
#defina GetFileSecurity GetFileSecurityW
#defina FindFirstChangeNotification FindFirstChangeNotificationW
#defina IsBadStringPtr IsBadStringPtrW
#defina LookupAccountSid LookupAccountSidW
#defina LookupAccountName LookupAccountNameW
#defina LookupPrivilegeValue LookupPrivilegeValueW
#defina LookupPrivilegeName LookupPrivilegeNameW
#defina LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#defina BuildCommDCB BuildCommDCBW
#defina BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#defina CommConfigDialog CommConfigDialogW
#defina GetDefaultCommConfig GetDefaultCommConfigW
#defina SetDefaultCommConfig SetDefaultCommConfigW
#defina GetComputerName GetComputerNameW
#defina SetComputerName SetComputerNameW
#defina GetComputerNameEx GetComputerNameExW
#defina SetComputerNameEx SetComputerNameExW
#defina DnsHostnameToComputerName DnsHostnameToComputerNameW
#defina GetUserName GetUserNameW
#senão
#defina FindFirstFileEx FindFirstFileExA
#defina FindFirstFile FindFirstFileA
#defina FindNextFile FindNextFileA
#defina SearchPath SearchPathA
#defina CopyFile CopyFileA
#defina CopyFileEx CopyFileExA
#defina MoveFile MoveFileA
#defina MoveFileEx MoveFileExA
#defina MoveFileWithProgress MoveFileWithProgressA
#defina ReplaceFile ReplaceFileA
#defina CreateHardLink CreateHardLinkA
#defina CreateNamedPipe CreateNamedPipeA
#defina GetNamedPipeHandleState GetNamedPipeHandleStateA
#defina CallNamedPipe CallNamedPipeA
#defina WaitNamedPipe WaitNamedPipeA
#defina SetVolumeLabel SetVolumeLabelA
#defina GetVolumeInformation GetVolumeInformationA
#defina ClearEventLog ClearEventLogA
#defina BackupEventLog BackupEventLogA
#defina OpenEventLog OpenEventLogA
#defina RegisterEventSource RegisterEventSourceA
#defina OpenBackupEventLog OpenBackupEventLogA
#defina ReadEventLog ReadEventLogA
#defina ReportEvent ReportEventA
#defina AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#defina AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
#defina AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmA
#defina AccessCheckByTypeResultListAndAuditAlarmByHandle AccessCheckByTypeResultListAndAuditAlarmByHandleA
#defina ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#defina ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#defina ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#defina ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#defina PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#defina SetFileSecurity SetFileSecurityA
#defina GetFileSecurity GetFileSecurityA
#defina FindFirstChangeNotification FindFirstChangeNotificationA
#defina IsBadStringPtr IsBadStringPtrA
#defina LookupAccountSid LookupAccountSidA
#defina LookupAccountName LookupAccountNameA
#defina LookupPrivilegeValue LookupPrivilegeValueA
#defina LookupPrivilegeName LookupPrivilegeNameA
#defina LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#defina BuildCommDCB BuildCommDCBA
#defina BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#defina CommConfigDialog CommConfigDialogA
#defina GetDefaultCommConfig GetDefaultCommConfigA
#defina SetDefaultCommConfig SetDefaultCommConfigA
#defina GetComputerName GetComputerNameA
#defina SetComputerName SetComputerNameA
#defina GetComputerNameEx GetComputerNameExA
#defina SetComputerNameEx SetComputerNameExA
#defina DnsHostnameToComputerName DnsHostnameToComputerNameA
#defina GetUserName GetUserNameA
#fim_se

  WINBASEAPI HANDLE WINAPI FindFirstFileExA(LPCSTR lpFileName,FINDEX_INFO_LEVELS fInfoLevelId,LPVOID lpFindFileData,FINDEX_SEARCH_OPS fSearchOp,LPVOID lpSearchFilter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI FindFirstFileExW(LPCWSTR lpFileName,FINDEX_INFO_LEVELS fInfoLevelId,LPVOID lpFindFileData,FINDEX_SEARCH_OPS fSearchOp,LPVOID lpSearchFilter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI FindFirstFileA(LPCSTR lpFileName,LPWIN32_FIND_DATAA lpFindFileData);
  WINBASEAPI HANDLE WINAPI FindFirstFileW(LPCWSTR lpFileName,LPWIN32_FIND_DATAW lpFindFileData);
  WINBASEAPI WINBOOL WINAPI FindNextFileA(HANDLE hFindFile,LPWIN32_FIND_DATAA lpFindFileData);
  WINBASEAPI WINBOOL WINAPI FindNextFileW(HANDLE hFindFile,LPWIN32_FIND_DATAW lpFindFileData);
  WINBASEAPI DWORD WINAPI SearchPathA(LPCSTR lpPath,LPCSTR lpFileName,LPCSTR lpExtension,DWORD nBufferLength,LPSTR lpBuffer,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI SearchPathW(LPCWSTR lpPath,LPCWSTR lpFileName,LPCWSTR lpExtension,DWORD nBufferLength,LPWSTR lpBuffer,LPWSTR *lpFilePart);
  WINBASEAPI WINBOOL WINAPI CopyFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,WINBOOL bFailIfExists);
  WINBASEAPI WINBOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,WINBOOL bFailIfExists);

  defina_tipo DWORD (WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER TotalFileSize,LARGE_INTEGER TotalBytesTransferred,LARGE_INTEGER StreamSize,LARGE_INTEGER StreamBytesTransferred,DWORD dwStreamNumber,DWORD dwCallbackReason,HANDLE hSourceFile,HANDLE hDestinationFile,LPVOID lpData);

  WINBASEAPI WINBOOL WINAPI CopyFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI CopyFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileWithProgressA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileWithProgressW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lpData,DWORD dwFlags);

#defina MOVEFILE_REPLACE_EXISTING 0x1
#defina MOVEFILE_COPY_ALLOWED 0x2
#defina MOVEFILE_DELAY_UNTIL_REBOOT 0x4
#defina MOVEFILE_WRITE_THROUGH 0x8
#defina MOVEFILE_CREATE_HARDLINK 0x10
#defina MOVEFILE_FAIL_IF_NOT_TRACKABLE 0x20

  WINBASEAPI WINBOOL WINAPI ReplaceFileA(LPCSTR lpReplacedFileName,LPCSTR lpReplacementFileName,LPCSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReplaceFileW(LPCWSTR lpReplacedFileName,LPCWSTR lpReplacementFileName,LPCWSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkA(LPCSTR lpFileName,LPCSTR lpExistingFileName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkW(LPCWSTR lpFileName,LPCWSTR lpExistingFileName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);

  defina_tipo enumeração _STREAM_INFO_LEVELS {
    FindStreamInfoStandard,FindStreamInfoMaxInfoLevel
  } STREAM_INFO_LEVELS;

  defina_tipo estrutura _WIN32_FIND_STREAM_DATA {
    LARGE_INTEGER StreamSize;
    WCHAR cStreamName[MAX_PATH + 36];
  } WIN32_FIND_STREAM_DATA,*PWIN32_FIND_STREAM_DATA;

  HANDLE WINAPI FindFirstStreamW(LPCWSTR lpFileName,STREAM_INFO_LEVELS InfoLevel,LPVOID lpFindStreamData,DWORD dwFlags);
  WINBOOL WINAPI FindNextStreamW(HANDLE hFindStream,LPVOID lpFindStreamData);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName,DWORD dwOpenMode,DWORD dwPipeMode,DWORD nMaxInstances,DWORD nOutBufferSize,DWORD nInBufferSize,DWORD nDefaultTimeOut,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR lpName,DWORD dwOpenMode,DWORD dwPipeMode,DWORD nMaxInstances,DWORD nOutBufferSize,DWORD nInBufferSize,DWORD nDefaultTimeOut,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateA(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout,LPSTR lpUserName,DWORD nMaxUserNameSize);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateW(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lpMaxCollectionCount,LPDWORD lpCollectDataTimeout,LPWSTR lpUserName,DWORD nMaxUserNameSize);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeA(LPCSTR lpNamedPipeName,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesRead,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeW(LPCWSTR lpNamedPipeName,LPVOID lpInBuffer,DWORD nInBufferSize,LPVOID lpOutBuffer,DWORD nOutBufferSize,LPDWORD lpBytesRead,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeA(LPCSTR lpNamedPipeName,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeW(LPCWSTR lpNamedPipeName,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI SetVolumeLabelA(LPCSTR lpRootPathName,LPCSTR lpVolumeName);
  WINBASEAPI WINBOOL WINAPI SetVolumeLabelW(LPCWSTR lpRootPathName,LPCWSTR lpVolumeName);
  WINBASEAPI VOID WINAPI SetFileApisToOEM(VOID);
  WINBASEAPI VOID WINAPI SetFileApisToANSI(VOID);
  WINBASEAPI WINBOOL WINAPI AreFileApisANSI(VOID);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationA(LPCSTR lpRootPathName,LPSTR lpVolumeNameBuffer,DWORD nVolumeNameSize,LPDWORD lpVolumeSerialNumber,LPDWORD lpMaximumComponentLength,LPDWORD lpFileSystemFlags,LPSTR lpFileSystemNameBuffer,DWORD nFileSystemNameSize);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationW(LPCWSTR lpRootPathName,LPWSTR lpVolumeNameBuffer,DWORD nVolumeNameSize,LPDWORD lpVolumeSerialNumber,LPDWORD lpMaximumComponentLength,LPDWORD lpFileSystemFlags,LPWSTR lpFileSystemNameBuffer,DWORD nFileSystemNameSize);
  WINBASEAPI WINBOOL WINAPI CancelIo(HANDLE hFile);
  WINADVAPI WINBOOL WINAPI ClearEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI ClearEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI CloseEventLog(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI DeregisterEventSource(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI NotifyChangeEventLog(HANDLE hEventLog,HANDLE hEvent);
  WINADVAPI WINBOOL WINAPI GetNumberOfEventLogRecords(HANDLE hEventLog,PDWORD NumberOfRecords);
  WINADVAPI WINBOOL WINAPI GetOldestEventLogRecord(HANDLE hEventLog,PDWORD OldestRecord);
  WINADVAPI HANDLE WINAPI OpenEventLogA(LPCSTR lpUNCServerName,LPCSTR lpSourceName);
  WINADVAPI HANDLE WINAPI OpenEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpSourceName);
  WINADVAPI HANDLE WINAPI RegisterEventSourceA(LPCSTR lpUNCServerName,LPCSTR lpSourceName);
  WINADVAPI HANDLE WINAPI RegisterEventSourceW(LPCWSTR lpUNCServerName,LPCWSTR lpSourceName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR lpUNCServerName,LPCSTR lpFileName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI ReadEventLogA(HANDLE hEventLog,DWORD dwReadFlags,DWORD dwRecordOffset,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,DWORD *pnBytesRead,DWORD *pnMinNumberOfBytesNeeded);
  WINADVAPI WINBOOL WINAPI ReadEventLogW(HANDLE hEventLog,DWORD dwReadFlags,DWORD dwRecordOffset,LPVOID lpBuffer,DWORD nNumberOfBytesToRead,DWORD *pnBytesRead,DWORD *pnMinNumberOfBytesNeeded);
  WINADVAPI WINBOOL WINAPI ReportEventA(HANDLE hEventLog,WORD wType,WORD wCategory,DWORD dwEventID,PSID lpUserSid,WORD wNumStrings,DWORD dwDataSize,LPCSTR *lpStrings,LPVOID lpRawData);
  WINADVAPI WINBOOL WINAPI ReportEventW(HANDLE hEventLog,WORD wType,WORD wCategory,DWORD dwEventID,PSID lpUserSid,WORD wNumStrings,DWORD dwDataSize,LPCWSTR *lpStrings,LPVOID lpRawData);

#defina EVENTLOG_FULL_INFO 0

  defina_tipo estrutura _EVENTLOG_FULL_INFORMATION {
    DWORD dwFull;
  } EVENTLOG_FULL_INFORMATION,*LPEVENTLOG_FULL_INFORMATION;

  WINADVAPI WINBOOL WINAPI GetEventLogInformation(HANDLE hEventLog,DWORD dwInfoLevel,LPVOID lpBuffer,DWORD cbBufSize,LPDWORD pcbBytesNeeded);
  WINADVAPI WINBOOL WINAPI DuplicateToken(HANDLE ExistingTokenHandle,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,PHANDLE DuplicateTokenHandle);
  WINADVAPI WINBOOL WINAPI GetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD nLength,LPDWORD lpnLengthNeeded);
  WINADVAPI WINBOOL WINAPI ImpersonateNamedPipeClient(HANDLE hNamedPipe);
  WINADVAPI WINBOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
  WINADVAPI WINBOOL WINAPI RevertToSelf(VOID);
  WINADVAPI WINBOOL WINAPI SetThreadToken (PHANDLE Thread,HANDLE Token);
  WINADVAPI WINBOOL WINAPI AccessCheck(PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_SET PrivilegeSet,LPDWORD PrivilegeSetLength,LPDWORD GrantedAccess,LPBOOL AccessStatus);
  WINADVAPI WINBOOL WINAPI AccessCheckByType(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_SET PrivilegeSet,LPDWORD PrivilegeSetLength,LPDWORD GrantedAccess,LPBOOL AccessStatus);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeResultList(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_SET PrivilegeSet,LPDWORD PrivilegeSetLength,LPDWORD GrantedAccessList,LPDWORD AccessStatusList);
  WINADVAPI WINBOOL WINAPI OpenProcessToken(HANDLE ProcessHandle,DWORD DesiredAccess,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI OpenThreadToken(HANDLE ThreadHandle,DWORD DesiredAccess,WINBOOL OpenAsSelf,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI GetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD TokenInformationLength,PDWORD ReturnLength);
  WINADVAPI WINBOOL WINAPI SetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD TokenInformationLength);
  WINADVAPI WINBOOL WINAPI AdjustTokenPrivileges(HANDLE TokenHandle,WINBOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState,DWORD BufferLength,PTOKEN_PRIVILEGES PreviousState,PDWORD ReturnLength);
  WINADVAPI WINBOOL WINAPI AdjustTokenGroups(HANDLE TokenHandle,WINBOOL ResetToDefault,PTOKEN_GROUPS NewState,DWORD BufferLength,PTOKEN_GROUPS PreviousState,PDWORD ReturnLength);
  WINADVAPI WINBOOL WINAPI PrivilegeCheck(HANDLE ClientToken,PPRIVILEGE_SET RequiredPrivileges,LPBOOL pfResult);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmByHandleA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeResultListAndAuditAlarmByHandleW(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD ObjectTypeListLength,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_SET Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_SET Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName,LPCSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR SubsystemName,LPCWSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI IsWellKnownSid(PSID pSid,WELL_KNOWN_SID_TYPE WellKnownSidType);
  WINADVAPI WINBOOL WINAPI CreateWellKnownSid(WELL_KNOWN_SID_TYPE WellKnownSidType,PSID DomainSid,PSID pSid,DWORD *cbSid);
  WINADVAPI WINBOOL WINAPI EqualDomainSid(PSID pSid1,PSID pSid2,WINBOOL *pfEqual);
  WINADVAPI WINBOOL WINAPI GetWindowsAccountDomainSid(PSID pSid,PSID pDomainSid,DWORD *cbDomainSid);
  WINADVAPI WINBOOL WINAPI IsValidSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI EqualSid(PSID pSid1,PSID pSid2);
  WINADVAPI WINBOOL WINAPI EqualPrefixSid(PSID pSid1,PSID pSid2);
  WINADVAPI DWORD WINAPI GetSidLengthRequired (UCHAR nSubAuthorityCount);
  WINADVAPI WINBOOL WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE nSubAuthorityCount,DWORD nSubAuthority0,DWORD nSubAuthority1,DWORD nSubAuthority2,DWORD nSubAuthority3,DWORD nSubAuthority4,DWORD nSubAuthority5,DWORD nSubAuthority6,DWORD nSubAuthority7,PSID *pSid);
  WINADVAPI PVOID WINAPI FreeSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI InitializeSid(PSID Sid,PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE nSubAuthorityCount);
  WINADVAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID pSid);
  WINADVAPI PDWORD WINAPI GetSidSubAuthority(PSID pSid,DWORD nSubAuthority);
  WINADVAPI PUCHAR WINAPI GetSidSubAuthorityCount(PSID pSid);
  WINADVAPI DWORD WINAPI GetLengthSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI CopySid(DWORD nDestinationSidLength,PSID pDestinationSid,PSID pSourceSid);
  WINADVAPI WINBOOL WINAPI AreAllAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI WINBOOL WINAPI AreAnyAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI VOID WINAPI MapGenericMask(PDWORD AccessMask,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI IsValidAcl(PACL pAcl);
  WINADVAPI WINBOOL WINAPI InitializeAcl(PACL pAcl,DWORD nAclLength,DWORD dwAclRevision);
  WINADVAPI WINBOOL WINAPI GetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD nAclInformationLength,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI SetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD nAclInformationLength,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI AddAce(PACL pAcl,DWORD dwAceRevision,DWORD dwStartingAceIndex,LPVOID pAceList,DWORD nAceListLength);
  WINADVAPI WINBOOL WINAPI DeleteAce(PACL pAcl,DWORD dwAceIndex);
  WINADVAPI WINBOOL WINAPI GetAce(PACL pAcl,DWORD dwAceIndex,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI AddAccessAllowedAce(PACL pAcl,DWORD dwAceRevision,DWORD AccessMask,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAccessAllowedAceEx(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAccessDeniedAce(PACL pAcl,DWORD dwAceRevision,DWORD AccessMask,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAccessDeniedAceEx(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAuditAccessAce(PACL pAcl,DWORD dwAceRevision,DWORD dwAccessMask,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI AddAuditAccessAceEx(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD dwAccessMask,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI AddAccessAllowedObjectAce(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAccessDeniedObjectAce(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAuditAccessObjectAce(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI FindFirstFreeAce(PACL pAcl,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD dwRevision);
  WINADVAPI WINBOOL WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI DWORD WINAPI GetSecurityDescriptorLength(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSECURITY_DESCRIPTOR_CONTROL pControl,LPDWORD lpdwRevision);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest,SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bDaclPresent,PACL pDacl,WINBOOL bDaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbDaclPresent,PACL *pDacl,LPBOOL lpbDaclDefaulted);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bSaclPresent,PACL pSacl,WINBOOL bSaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbSaclPresent,PACL *pSacl,LPBOOL lpbSaclDefaulted);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pOwner,WINBOOL bOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pOwner,LPBOOL lpbOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pGroup,WINBOOL bGroupDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pGroup,LPBOOL lpbGroupDefaulted);
  WINADVAPI DWORD WINAPI SetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI DWORD WINAPI GetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI WINBOOL WINAPI CreatePrivateObjectSecurity(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,WINBOOL IsDirectoryObject,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI ConvertToAutoInheritPrivateObjectSecurity(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,PSECURITY_DESCRIPTOR *NewSecurityDescriptor,GUID *ObjectType,BOOLEAN IsDirectoryObject,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI CreatePrivateObjectSecurityEx(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID *ObjectType,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI CreatePrivateObjectSecurityWithMultipleInheritance(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID **ObjectTypes,ULONG GuidCount,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI SetPrivateObjectSecurity (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI SetPrivateObjectSecurityEx (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,ULONG AutoInheritFlags,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI GetPrivateObjectSecurity(PSECURITY_DESCRIPTOR ObjectDescriptor,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ResultantDescriptor,DWORD DescriptorLength,PDWORD ReturnLength);
  WINADVAPI WINBOOL WINAPI DestroyPrivateObjectSecurity(PSECURITY_DESCRIPTOR *ObjectDescriptor);
  WINADVAPI WINBOOL WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdwBufferLength);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,LPDWORD lpdwAbsoluteSecurityDescriptorSize,PACL pDacl,LPDWORD lpdwDaclSize,PACL pSacl,LPDWORD lpdwSaclSize,PSID pOwner,LPDWORD lpdwOwnerSize,PSID pPrimaryGroup,LPDWORD lpdwPrimaryGroupSize);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD2(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdwBufferSize);
  WINADVAPI WINBOOL WINAPI SetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI SetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD nLength,LPDWORD lpnLengthNeeded);
  WINADVAPI WINBOOL WINAPI GetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD nLength,LPDWORD lpnLengthNeeded);
  WINADVAPI WINBOOL WINAPI SetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR SecurityDescriptor);
  WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationA(LPCSTR lpPathName,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationW(LPCWSTR lpPathName,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI WINBOOL WINAPI FindNextChangeNotification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI FindCloseChangeNotification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ReadDirectoryChangesW(HANDLE hDirectory,LPVOID lpBuffer,DWORD nBufferLength,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,LPDWORD lpBytesReturned,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI VirtualLock(LPVOID lpAddress,SIZE_T dwSize);
  WINBASEAPI WINBOOL WINAPI VirtualUnlock(LPVOID lpAddress,SIZE_T dwSize);
  WINBASEAPI LPVOID WINAPI MapViewOfFileEx(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dwFileOffsetHigh,DWORD dwFileOffsetLow,SIZE_T dwNumberOfBytesToMap,LPVOID lpBaseAddress);
  WINBASEAPI WINBOOL WINAPI SetPriorityClass(HANDLE hProcess,DWORD dwPriorityClass);
  WINBASEAPI DWORD WINAPI GetPriorityClass(HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadCodePtr(FARPROC lpfn);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrA(LPCSTR lpsz,UINT_PTR ucchMax);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrW(LPCWSTR lpsz,UINT_PTR ucchMax);
  WINADVAPI WINBOOL WINAPI LookupAccountSidA(LPCSTR lpSystemName,PSID Sid,LPSTR Name,LPDWORD cchName,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountSidW(LPCWSTR lpSystemName,PSID Sid,LPWSTR Name,LPDWORD cchName,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameA(LPCSTR lpSystemName,LPCSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameW(LPCWSTR lpSystemName,LPCWSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeValueA(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeValueW(LPCWSTR lpSystemName,LPCWSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeNameA(LPCSTR lpSystemName,PLUID lpLuid,LPSTR lpName,LPDWORD cchName);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeNameW(LPCWSTR lpSystemName,PLUID lpLuid,LPWSTR lpName,LPDWORD cchName);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeDisplayNameA(LPCSTR lpSystemName,LPCSTR lpName,LPSTR lpDisplayName,LPDWORD cchDisplayName,LPDWORD lpLanguageId);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeDisplayNameW(LPCWSTR lpSystemName,LPCWSTR lpName,LPWSTR lpDisplayName,LPDWORD cchDisplayName,LPDWORD lpLanguageId);
  WINADVAPI WINBOOL WINAPI AllocateLocallyUniqueId(PLUID Luid);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBA(LPCSTR lpDef,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBW(LPCWSTR lpDef,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBAndTimeoutsA(LPCSTR lpDef,LPDCB lpDCB,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBAndTimeoutsW(LPCWSTR lpDef,LPDCB lpDCB,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI CommConfigDialogA(LPCSTR lpszName,HWND hWnd,LPCOMMCONFIG lpCC);
  WINBASEAPI WINBOOL WINAPI CommConfigDialogW(LPCWSTR lpszName,HWND hWnd,LPCOMMCONFIG lpCC);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdwSize);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdwSize);
  WINBASEAPI WINBOOL WINAPI SetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,DWORD dwSize);
  WINBASEAPI WINBOOL WINAPI SetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,DWORD dwSize);

#defina MAX_COMPUTERNAME_LENGTH 15

  WINBASEAPI WINBOOL WINAPI GetComputerNameA(LPSTR lpBuffer,LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI GetComputerNameW(LPWSTR lpBuffer,LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetComputerNameA(LPCSTR lpComputerName);
  WINBASEAPI WINBOOL WINAPI SetComputerNameW(LPCWSTR lpComputerName);

  defina_tipo enumeração _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,ComputerNameDnsHostname,ComputerNameDnsDomain,ComputerNameDnsFullyQualified,ComputerNamePhysicalNetBIOS,ComputerNamePhysicalDnsHostname,ComputerNamePhysicalDnsDomain,ComputerNamePhysicalDnsFullyQualified,ComputerNameMax
  } COMPUTER_NAME_FORMAT;

  WINBASEAPI WINBOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPSTR lpBuffer,LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPWSTR lpBuffer,LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPCSTR lpBuffer);
  WINBASEAPI WINBOOL WINAPI SetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPCWSTR lpBuffer);
  WINBASEAPI WINBOOL WINAPI DnsHostnameToComputerNameA(LPCSTR Hostname,LPSTR ComputerName,LPDWORD nSize);
  WINBASEAPI WINBOOL WINAPI DnsHostnameToComputerNameW(LPCWSTR Hostname,LPWSTR ComputerName,LPDWORD nSize);
  WINADVAPI WINBOOL WINAPI GetUserNameA(LPSTR lpBuffer,LPDWORD pcbBuffer);
  WINADVAPI WINBOOL WINAPI GetUserNameW(LPWSTR lpBuffer,LPDWORD pcbBuffer);

#defina LOGON32_LOGON_INTERACTIVE 2
#defina LOGON32_LOGON_NETWORK 3
#defina LOGON32_LOGON_BATCH 4
#defina LOGON32_LOGON_SERVICE 5
#defina LOGON32_LOGON_UNLOCK 7
#defina LOGON32_LOGON_NETWORK_CLEARTEXT 8
#defina LOGON32_LOGON_NEW_CREDENTIALS 9

#defina LOGON32_PROVIDER_DEFAULT 0
#defina LOGON32_PROVIDER_WINNT35 1
#defina LOGON32_PROVIDER_WINNT40 2
#defina LOGON32_PROVIDER_WINNT50 3

#se_definido UNICODE
#defina LogonUser LogonUserW
#defina LogonUserEx LogonUserExW
#defina CreateProcessAsUser CreateProcessAsUserW
#senão
#defina LogonUser LogonUserA
#defina LogonUserEx LogonUserExA
#defina CreateProcessAsUser CreateProcessAsUserA
#fim_se

  WINADVAPI WINBOOL WINAPI LogonUserA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserExA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *ppProfileBuffer,LPDWORD pdwProfileLength,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI LogonUserExW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *ppProfileBuffer,LPDWORD pdwProfileLength,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI ImpersonateLoggedOnUser(HANDLE hToken);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserA(HANDLE hToken,LPCSTR lpApplicationName,LPSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserW(HANDLE hToken,LPCWSTR lpApplicationName,LPWSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);

#defina LOGON_WITH_PROFILE 0x1
#defina LOGON_NETCREDENTIALS_ONLY 0x2
#defina LOGON_ZERO_PASSWORD_BUFFER 0x80000000

  WINADVAPI WINBOOL WINAPI CreateProcessWithLogonW(LPCWSTR lpUsername,LPCWSTR lpDomain,LPCWSTR lpPassword,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lpCommandLine,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessWithTokenW(HANDLE hToken,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lpCommandLine,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI ImpersonateAnonymousToken(HANDLE ThreadHandle);
  WINADVAPI WINBOOL WINAPI DuplicateTokenEx(HANDLE hExistingToken,DWORD dwDesiredAccess,LPSECURITY_ATTRIBUTES lpTokenAttributes,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,TOKEN_TYPE TokenType,PHANDLE phNewToken);
  WINADVAPI WINBOOL WINAPI CreateRestrictedToken(HANDLE ExistingTokenHandle,DWORD Flags,DWORD DisableSidCount,PSID_AND_ATTRIBUTES SidsToDisable,DWORD DeletePrivilegeCount,PLUID_AND_ATTRIBUTES PrivilegesToDelete,DWORD RestrictedSidCount,PSID_AND_ATTRIBUTES SidsToRestrict,PHANDLE NewTokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenRestricted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenUntrusted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI CheckTokenMembership(HANDLE TokenHandle,PSID SidToCheck,PBOOL IsMember);

  defina_tipo WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

  WINBASEAPI WINBOOL WINAPI RegisterWaitForSingleObject(PHANDLE phNewWaitObject,HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI HANDLE WINAPI RegisterWaitForSingleObjectEx(HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI WINBOOL WINAPI UnregisterWait(HANDLE WaitHandle);
  WINBASEAPI WINBOOL WINAPI UnregisterWaitEx(HANDLE WaitHandle,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI QueueUserWorkItem(LPTHREAD_START_ROUTINE Function,PVOID Context,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI BindIoCompletionCallback(HANDLE FileHandle,LPOVERLAPPED_COMPLETION_ROUTINE Function,ULONG Flags);
  WINBASEAPI HANDLE WINAPI CreateTimerQueue(VOID);
  WINBASEAPI WINBOOL WINAPI CreateTimerQueueTimer(PHANDLE phNewTimer,HANDLE TimerQueue,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD DueTime,DWORD Period,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI ChangeTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer,ULONG DueTime,ULONG Period);
  WINBASEAPI WINBOOL WINAPI DeleteTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI DeleteTimerQueueEx(HANDLE TimerQueue,HANDLE CompletionEvent);
  WINBASEAPI HANDLE WINAPI SetTimerQueueTimer(HANDLE TimerQueue,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD DueTime,DWORD Period,WINBOOL PreferIo);
  WINBASEAPI WINBOOL WINAPI CancelTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer);
  WINBASEAPI WINBOOL WINAPI DeleteTimerQueue(HANDLE TimerQueue);

#defina HW_PROFILE_GUIDLEN 39
#defina MAX_PROFILE_LEN 80

#defina DOCKINFO_UNDOCKED (0x1)
#defina DOCKINFO_DOCKED (0x2)
#defina DOCKINFO_USER_SUPPLIED (0x4)
#defina DOCKINFO_USER_UNDOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#defina DOCKINFO_USER_DOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

  defina_tipo estrutura tagHW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;

  defina_tipo estrutura tagHW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;

#se_definido UNICODE
  defina_tipo HW_PROFILE_INFOW HW_PROFILE_INFO;
  defina_tipo LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#senão
  defina_tipo HW_PROFILE_INFOA HW_PROFILE_INFO;
  defina_tipo LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#fim_se

#se_definido UNICODE
#defina GetCurrentHwProfile GetCurrentHwProfileW
#defina GetVersionEx GetVersionExW
#defina VerifyVersionInfo VerifyVersionInfoW
#senão
#defina GetCurrentHwProfile GetCurrentHwProfileA
#defina GetVersionEx GetVersionExA
#defina VerifyVersionInfo VerifyVersionInfoA
#fim_se

  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileA (LPHW_PROFILE_INFOA lpHwProfileInfo);
  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileW (LPHW_PROFILE_INFOW lpHwProfileInfo);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
  WINBASEAPI WINBOOL WINAPI GetVersionExA(LPOSVERSIONINFOA lpVersionInformation);
  WINBASEAPI WINBOOL WINAPI GetVersionExW(LPOSVERSIONINFOW lpVersionInformation);
  WINBASEAPI WINBOOL WINAPI VerifyVersionInfoA(LPOSVERSIONINFOEXA lpVersionInformation,DWORD dwTypeMask,DWORDLONG dwlConditionMask);
  WINBASEAPI WINBOOL WINAPI VerifyVersionInfoW(LPOSVERSIONINFOEXW lpVersionInformation,DWORD dwTypeMask,DWORDLONG dwlConditionMask);

#inclua <winerror.h>

#defina TC_NORMAL 0
#defina TC_HARDERR 1
#defina TC_GP_TRAP 2
#defina TC_SIGNAL 3

#defina AC_LINE_OFFLINE 0x0
#defina AC_LINE_ONLINE 0x1
#defina AC_LINE_BACKUP_POWER 0x2
#defina AC_LINE_UNKNOWN 0xff

#defina BATTERY_FLAG_HIGH 0x1
#defina BATTERY_FLAG_LOW 0x2
#defina BATTERY_FLAG_CRITICAL 0x4
#defina BATTERY_FLAG_CHARGING 0x8
#defina BATTERY_FLAG_NO_BATTERY 0x80
#defina BATTERY_FLAG_UNKNOWN 0xff

#defina BATTERY_PERCENTAGE_UNKNOWN 0xff

#defina BATTERY_LIFE_UNKNOWN 0xffffffff

  defina_tipo estrutura _SYSTEM_POWER_STATUS {
    BYTE ACLineStatus;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD BatteryLifeTime;
    DWORD BatteryFullLifeTime;
  } SYSTEM_POWER_STATUS,*LPSYSTEM_POWER_STATUS;

#se_definido UNICODE
#defina CreateJobObject CreateJobObjectW
#defina OpenJobObject OpenJobObjectW
#defina FindFirstVolume FindFirstVolumeW
#defina FindNextVolume FindNextVolumeW
#defina FindFirstVolumeMountPoint FindFirstVolumeMountPointW
#defina FindNextVolumeMountPoint FindNextVolumeMountPointW
#defina SetVolumeMountPoint SetVolumeMountPointW
#defina DeleteVolumeMountPoint DeleteVolumeMountPointW
#defina GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointW
#defina GetVolumePathName GetVolumePathNameW
#defina GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameW
#senão
#defina CreateJobObject CreateJobObjectA
#defina OpenJobObject OpenJobObjectA
#defina FindFirstVolume FindFirstVolumeA
#defina FindNextVolume FindNextVolumeA
#defina FindFirstVolumeMountPoint FindFirstVolumeMountPointA
#defina FindNextVolumeMountPoint FindNextVolumeMountPointA
#defina SetVolumeMountPoint SetVolumeMountPointA
#defina DeleteVolumeMountPoint DeleteVolumeMountPointA
#defina GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointA
#defina GetVolumePathName GetVolumePathNameA
#defina GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameA
#fim_se

  WINBOOL WINAPI GetSystemPowerStatus(LPSYSTEM_POWER_STATUS lpSystemPowerStatus);
  WINBOOL WINAPI SetSystemPowerState(WINBOOL fSuspend,WINBOOL fForce);
  WINBASEAPI WINBOOL WINAPI AllocateUserPhysicalPages(HANDLE hProcess,PULONG_PTR NumberOfPages,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI FreeUserPhysicalPages(HANDLE hProcess,PULONG_PTR NumberOfPages,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI MapUserPhysicalPages(PVOID VirtualAddress,ULONG_PTR NumberOfPages,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI MapUserPhysicalPagesScatter(PVOID *VirtualAddresses,ULONG_PTR NumberOfPages,PULONG_PTR PageArray);
  WINBASEAPI HANDLE WINAPI CreateJobObjectA(LPSECURITY_ATTRIBUTES lpJobAttributes,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateJobObjectW(LPSECURITY_ATTRIBUTES lpJobAttributes,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenJobObjectA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenJobObjectW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI WINBOOL WINAPI AssignProcessToJobObject(HANDLE hJob,HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI TerminateJobObject(HANDLE hJob,UINT uExitCode);
  WINBASEAPI WINBOOL WINAPI QueryInformationJobObject(HANDLE hJob,JOBOBJECTINFOCLASS JobObjectInformationClass,LPVOID lpJobObjectInformation,DWORD cbJobObjectInformationLength,LPDWORD lpReturnLength);
  WINBASEAPI WINBOOL WINAPI SetInformationJobObject(HANDLE hJob,JOBOBJECTINFOCLASS JobObjectInformationClass,LPVOID lpJobObjectInformation,DWORD cbJobObjectInformationLength);
  WINBASEAPI WINBOOL WINAPI IsProcessInJob(HANDLE ProcessHandle,HANDLE JobHandle,PBOOL Result);
  WINBASEAPI WINBOOL WINAPI CreateJobSet(ULONG NumJob,PJOB_SET_ARRAY UserJobSet,ULONG Flags);
  WINBASEAPI PVOID WINAPI AddVectoredExceptionHandler (ULONG First,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler(PVOID Handle);
  WINBASEAPI PVOID WINAPI AddVectoredContinueHandler (ULONG First,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredContinueHandler(PVOID Handle);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeA(LPSTR lpszVolumeName,DWORD cchBufferLength);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeW(LPWSTR lpszVolumeName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindNextVolumeA(HANDLE hFindVolume,LPSTR lpszVolumeName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindNextVolumeW(HANDLE hFindVolume,LPWSTR lpszVolumeName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindVolumeClose(HANDLE hFindVolume);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointA(LPCSTR lpszRootPathName,LPSTR lpszVolumeMountPoint,DWORD cchBufferLength);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointW(LPCWSTR lpszRootPathName,LPWSTR lpszVolumeMountPoint,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindNextVolumeMountPointA(HANDLE hFindVolumeMountPoint,LPSTR lpszVolumeMountPoint,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindNextVolumeMountPointW(HANDLE hFindVolumeMountPoint,LPWSTR lpszVolumeMountPoint,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI FindVolumeMountPointClose(HANDLE hFindVolumeMountPoint);
  WINBASEAPI WINBOOL WINAPI SetVolumeMountPointA(LPCSTR lpszVolumeMountPoint,LPCSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI SetVolumeMountPointW(LPCWSTR lpszVolumeMountPoint,LPCWSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI DeleteVolumeMountPointA(LPCSTR lpszVolumeMountPoint);
  WINBASEAPI WINBOOL WINAPI DeleteVolumeMountPointW(LPCWSTR lpszVolumeMountPoint);
  WINBASEAPI WINBOOL WINAPI GetVolumeNameForVolumeMountPointA(LPCSTR lpszVolumeMountPoint,LPSTR lpszVolumeName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI GetVolumeNameForVolumeMountPointW(LPCWSTR lpszVolumeMountPoint,LPWSTR lpszVolumeName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI GetVolumePathNameA(LPCSTR lpszFileName,LPSTR lpszVolumePathName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI GetVolumePathNameW(LPCWSTR lpszFileName,LPWSTR lpszVolumePathName,DWORD cchBufferLength);
  WINBASEAPI WINBOOL WINAPI GetVolumePathNamesForVolumeNameA(LPCSTR lpszVolumeName,LPCH lpszVolumePathNames,DWORD cchBufferLength,PDWORD lpcchReturnLength);
  WINBASEAPI WINBOOL WINAPI GetVolumePathNamesForVolumeNameW(LPCWSTR lpszVolumeName,LPWCH lpszVolumePathNames,DWORD cchBufferLength,PDWORD lpcchReturnLength);

#defina ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 0x1
#defina ACTCTX_FLAG_LANGID_VALID 0x2
#defina ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 0x4
#defina ACTCTX_FLAG_RESOURCE_NAME_VALID 0x8
#defina ACTCTX_FLAG_SET_PROCESS_DEFAULT 0x10
#defina ACTCTX_FLAG_APPLICATION_NAME_VALID 0x20
#defina ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF 0x40
#defina ACTCTX_FLAG_HMODULE_VALID 0x80

  defina_tipo estrutura tagACTCTXA {
    ULONG cbSize;
    DWORD dwFlags;
    LPCSTR lpSource;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCSTR lpAssemblyDirectory;
    LPCSTR lpResourceName;
    LPCSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXA,*PACTCTXA;

  defina_tipo estrutura tagACTCTXW {
    ULONG cbSize;
    DWORD dwFlags;
    LPCWSTR lpSource;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXW,*PACTCTXW;

  defina_tipo constante ACTCTXA *PCACTCTXA;
  defina_tipo constante ACTCTXW *PCACTCTXW;

#se_definido UNICODE
  defina_tipo ACTCTXW ACTCTX;
  defina_tipo PACTCTXW PACTCTX;
  defina_tipo PCACTCTXW PCACTCTX;
#senão
  defina_tipo ACTCTXA ACTCTX;
  defina_tipo PACTCTXA PACTCTX;
  defina_tipo PCACTCTXA PCACTCTX;
#fim_se

#se_definido UNICODE
#defina CreateActCtx CreateActCtxW
#senão
#defina CreateActCtx CreateActCtxA
#fim_se

  WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA pActCtx);
  WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW pActCtx);
  WINBASEAPI VOID WINAPI AddRefActCtx(HANDLE hActCtx);
  WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ZombifyActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ActivateActCtx(HANDLE hActCtx,ULONG_PTR *lpCookie);

#defina DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION (0x1)

  WINBASEAPI WINBOOL WINAPI DeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
  WINBASEAPI WINBOOL WINAPI GetCurrentActCtx(HANDLE *lphActCtx);

  defina_tipo estrutura tagACTCTX_SECTION_KEYED_DATA_2600 {
    ULONG cbSize;
    ULONG ulDataFormatVersion;
    PVOID lpData;
    ULONG ulLength;
    PVOID lpSectionGlobalData;
    ULONG ulSectionGlobalDataLength;
    PVOID lpSectionBase;
    ULONG ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG ulAssemblyRosterIndex;
  } ACTCTX_SECTION_KEYED_DATA_2600,*PACTCTX_SECTION_KEYED_DATA_2600;

  defina_tipo constante ACTCTX_SECTION_KEYED_DATA_2600 *PCACTCTX_SECTION_KEYED_DATA_2600;

  defina_tipo estrutura tagACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lpSectionBase;
    ULONG ulSectionLength;
    PVOID lpSectionGlobalDataBase;
    ULONG ulSectionGlobalDataLength;
  } ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA,*PACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;

  defina_tipo constante ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA;

  defina_tipo estrutura tagACTCTX_SECTION_KEYED_DATA {
    ULONG cbSize;
    ULONG ulDataFormatVersion;
    PVOID lpData;
    ULONG ulLength;
    PVOID lpSectionGlobalData;
    ULONG ulSectionGlobalDataLength;
    PVOID lpSectionBase;
    ULONG ulSectionTotalLength;
    HANDLE hActCtx;
    ULONG ulAssemblyRosterIndex;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA AssemblyMetadata;
  } ACTCTX_SECTION_KEYED_DATA,*PACTCTX_SECTION_KEYED_DATA;

  defina_tipo constante ACTCTX_SECTION_KEYED_DATA *PCACTCTX_SECTION_KEYED_DATA;

#defina FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX 0x1
#defina FIND_ACTCTX_SECTION_KEY_RETURN_FLAGS 0x2
#defina FIND_ACTCTX_SECTION_KEY_RETURN_ASSEMBLY_METADATA 0x4

#se_definido UNICODE
#defina FindActCtxSectionString FindActCtxSectionStringW
#senão
#defina FindActCtxSectionString FindActCtxSectionStringA
#fim_se

  WINBASEAPI WINBOOL WINAPI FindActCtxSectionStringA(DWORD dwFlags,constante GUID *lpExtensionGuid,ULONG ulSectionId,LPCSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
  WINBASEAPI WINBOOL WINAPI FindActCtxSectionStringW(DWORD dwFlags,constante GUID *lpExtensionGuid,ULONG ulSectionId,LPCWSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
  WINBASEAPI WINBOOL WINAPI FindActCtxSectionGuid(DWORD dwFlags,constante GUID *lpExtensionGuid,ULONG ulSectionId,constante GUID *lpGuidToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);

#se_não_definido RC_INVOKED
#se_não_definido ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED

  defina_tipo estrutura _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD dwFlags;
  } ACTIVATION_CONTEXT_BASIC_INFORMATION,*PACTIVATION_CONTEXT_BASIC_INFORMATION;

  defina_tipo constante estrutura _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;

#defina ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1
#fim_se
#fim_se

#defina QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX 0x4
#defina QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 0x8
#defina QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS 0x10
#defina QUERY_ACTCTX_FLAG_NO_ADDREF 0x80000000

  WINBASEAPI WINBOOL WINAPI QueryActCtxW(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pvBuffer,SIZE_T cbBuffer,SIZE_T *pcbWrittenOrRequired);

  defina_tipo WINBOOL (WINAPI *PQUERYACTCTXW_FUNC)(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pvBuffer,SIZE_T cbBuffer,SIZE_T *pcbWrittenOrRequired);

  WINBASEAPI WINBOOL WINAPI ProcessIdToSessionId(DWORD dwProcessId,DWORD *pSessionId);
  WINBASEAPI DWORD WINAPI WTSGetActiveConsoleSessionId();
  WINBASEAPI WINBOOL WINAPI IsWow64Process(HANDLE hProcess,PBOOL Wow64Process);
  WINBASEAPI WINBOOL WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer,PDWORD ReturnedLength);
  WINBASEAPI WINBOOL WINAPI GetNumaHighestNodeNumber(PULONG HighestNodeNumber);
  WINBASEAPI WINBOOL WINAPI GetNumaProcessorNode(UCHAR Processor,PUCHAR NodeNumber);
  WINBASEAPI WINBOOL WINAPI GetNumaNodeProcessorMask(UCHAR Node,PULONGLONG ProcessorMask);
  WINBASEAPI WINBOOL WINAPI GetNumaAvailableMemoryNode(UCHAR Node,PULONGLONG AvailableBytes);

#se_definido __cplusplus
}
#fim_se
#fim_se
