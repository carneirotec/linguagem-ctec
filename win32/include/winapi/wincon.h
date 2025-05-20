/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _WINCON_
#defina _WINCON_

#se_definido __cplusplus
externo "C" {
#fim_se

  defina_tipo estrutura _COORD {
    SHORT X;
    SHORT Y;
  } COORD,*PCOORD;

  defina_tipo estrutura _SMALL_RECT {
    SHORT Left;
    SHORT Top;
    SHORT Right;
    SHORT Bottom;
  } SMALL_RECT,*PSMALL_RECT;

  defina_tipo estrutura _KEY_EVENT_RECORD {
    WINBOOL bKeyDown;
    WORD wRepeatCount;
    WORD wVirtualKeyCode;
    WORD wVirtualScanCode;
    união {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } uChar;
    DWORD dwControlKeyState;
  } KEY_EVENT_RECORD,*PKEY_EVENT_RECORD;

#defina RIGHT_ALT_PRESSED 0x1
#defina LEFT_ALT_PRESSED 0x2
#defina RIGHT_CTRL_PRESSED 0x4
#defina LEFT_CTRL_PRESSED 0x8
#defina SHIFT_PRESSED 0x10
#defina NUMLOCK_ON 0x20
#defina SCROLLLOCK_ON 0x40
#defina CAPSLOCK_ON 0x80
#defina ENHANCED_KEY 0x100
#defina NLS_DBCSCHAR 0x10000
#defina NLS_ALPHANUMERIC 0x0
#defina NLS_KATAKANA 0x20000
#defina NLS_HIRAGANA 0x40000
#defina NLS_ROMAN 0x400000
#defina NLS_IME_CONVERSION 0x800000
#defina NLS_IME_DISABLE 0x20000000

  defina_tipo estrutura _MOUSE_EVENT_RECORD {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dwControlKeyState;
    DWORD dwEventFlags;
  } MOUSE_EVENT_RECORD,*PMOUSE_EVENT_RECORD;

#defina FROM_LEFT_1ST_BUTTON_PRESSED 0x1
#defina RIGHTMOST_BUTTON_PRESSED 0x2
#defina FROM_LEFT_2ND_BUTTON_PRESSED 0x4
#defina FROM_LEFT_3RD_BUTTON_PRESSED 0x8
#defina FROM_LEFT_4TH_BUTTON_PRESSED 0x10

#defina MOUSE_MOVED 0x1
#defina DOUBLE_CLICK 0x2
#defina MOUSE_WHEELED 0x4

  defina_tipo estrutura _WINDOW_BUFFER_SIZE_RECORD {
    COORD dwSize;
  } WINDOW_BUFFER_SIZE_RECORD,*PWINDOW_BUFFER_SIZE_RECORD;

  defina_tipo estrutura _MENU_EVENT_RECORD {
    UINT dwCommandId;
  } MENU_EVENT_RECORD,*PMENU_EVENT_RECORD;

  defina_tipo estrutura _FOCUS_EVENT_RECORD {
    WINBOOL bSetFocus;
  } FOCUS_EVENT_RECORD,*PFOCUS_EVENT_RECORD;

  defina_tipo estrutura _INPUT_RECORD {
    WORD EventType;
    união {
      KEY_EVENT_RECORD KeyEvent;
      MOUSE_EVENT_RECORD MouseEvent;
      WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
      MENU_EVENT_RECORD MenuEvent;
      FOCUS_EVENT_RECORD FocusEvent;
    } Event;
  } INPUT_RECORD,*PINPUT_RECORD;

#defina KEY_EVENT 0x1
#defina MOUSE_EVENT 0x2
#defina WINDOW_BUFFER_SIZE_EVENT 0x4
#defina MENU_EVENT 0x8
#defina FOCUS_EVENT 0x10

  defina_tipo estrutura _CHAR_INFO {
    união {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } Char;
    WORD Attributes;
  } CHAR_INFO,*PCHAR_INFO;

#defina FOREGROUND_BLUE 0x1
#defina FOREGROUND_GREEN 0x2
#defina FOREGROUND_RED 0x4
#defina FOREGROUND_INTENSITY 0x8
#defina BACKGROUND_BLUE 0x10
#defina BACKGROUND_GREEN 0x20
#defina BACKGROUND_RED 0x40
#defina BACKGROUND_INTENSITY 0x80
#defina COMMON_LVB_LEADING_BYTE 0x100
#defina COMMON_LVB_TRAILING_BYTE 0x200
#defina COMMON_LVB_GRID_HORIZONTAL 0x400
#defina COMMON_LVB_GRID_LVERTICAL 0x800
#defina COMMON_LVB_GRID_RVERTICAL 0x1000
#defina COMMON_LVB_REVERSE_VIDEO 0x4000
#defina COMMON_LVB_UNDERSCORE 0x8000

#defina COMMON_LVB_SBCSDBCS 0x300

  defina_tipo estrutura _CONSOLE_SCREEN_BUFFER_INFO {
    COORD dwSize;
    COORD dwCursorPosition;
    WORD wAttributes;
    SMALL_RECT srWindow;
    COORD dwMaximumWindowSize;
  } CONSOLE_SCREEN_BUFFER_INFO,*PCONSOLE_SCREEN_BUFFER_INFO;

  defina_tipo estrutura _CONSOLE_CURSOR_INFO {
    DWORD dwSize;
    WINBOOL bVisible;
  } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;

  defina_tipo estrutura _CONSOLE_FONT_INFO {
    DWORD nFont;
    COORD dwFontSize;
  } CONSOLE_FONT_INFO,*PCONSOLE_FONT_INFO;

  defina_tipo estrutura _CONSOLE_SELECTION_INFO {
    DWORD dwFlags;
    COORD dwSelectionAnchor;
    SMALL_RECT srSelection;
  } CONSOLE_SELECTION_INFO,*PCONSOLE_SELECTION_INFO;

#defina CONSOLE_NO_SELECTION 0x0
#defina CONSOLE_SELECTION_IN_PROGRESS 0x1
#defina CONSOLE_SELECTION_NOT_EMPTY 0x2
#defina CONSOLE_MOUSE_SELECTION 0x4
#defina CONSOLE_MOUSE_DOWN 0x8

  defina_tipo WINBOOL (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);

#defina CTRL_C_EVENT 0
#defina CTRL_BREAK_EVENT 1
#defina CTRL_CLOSE_EVENT 2

#defina CTRL_LOGOFF_EVENT 5
#defina CTRL_SHUTDOWN_EVENT 6

#defina ENABLE_PROCESSED_INPUT 0x1
#defina ENABLE_LINE_INPUT 0x2
#defina ENABLE_ECHO_INPUT 0x4
#defina ENABLE_WINDOW_INPUT 0x8
#defina ENABLE_MOUSE_INPUT 0x10

#defina ENABLE_PROCESSED_OUTPUT 0x1
#defina ENABLE_WRAP_AT_EOL_OUTPUT 0x2

#se_definido UNICODE
#defina PeekConsoleInput PeekConsoleInputW
#defina ReadConsoleInput ReadConsoleInputW
#defina WriteConsoleInput WriteConsoleInputW
#defina ReadConsoleOutput ReadConsoleOutputW
#defina WriteConsoleOutput WriteConsoleOutputW
#defina ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#defina WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#defina FillConsoleOutputCharacter FillConsoleOutputCharacterW
#defina ScrollConsoleScreenBuffer ScrollConsoleScreenBufferW
#defina GetConsoleTitle GetConsoleTitleW
#defina SetConsoleTitle SetConsoleTitleW
#defina ReadConsole ReadConsoleW
#defina WriteConsole WriteConsoleW
#defina AddConsoleAlias AddConsoleAliasW
#defina GetConsoleAlias GetConsoleAliasW
#defina GetConsoleAliasesLength GetConsoleAliasesLengthW
#defina GetConsoleAliasExesLength GetConsoleAliasExesLengthW
#defina GetConsoleAliases GetConsoleAliasesW
#defina GetConsoleAliasExes GetConsoleAliasExesW
#senão
#defina PeekConsoleInput PeekConsoleInputA
#defina ReadConsoleInput ReadConsoleInputA
#defina WriteConsoleInput WriteConsoleInputA
#defina ReadConsoleOutput ReadConsoleOutputA
#defina WriteConsoleOutput WriteConsoleOutputA
#defina ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#defina WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#defina FillConsoleOutputCharacter FillConsoleOutputCharacterA
#defina ScrollConsoleScreenBuffer ScrollConsoleScreenBufferA
#defina GetConsoleTitle GetConsoleTitleA
#defina SetConsoleTitle SetConsoleTitleA
#defina ReadConsole ReadConsoleA
#defina WriteConsole WriteConsoleA
#defina AddConsoleAlias AddConsoleAliasA
#defina GetConsoleAlias GetConsoleAliasA
#defina GetConsoleAliasesLength GetConsoleAliasesLengthA
#defina GetConsoleAliasExesLength GetConsoleAliasExesLengthA
#defina GetConsoleAliases GetConsoleAliasesA
#defina GetConsoleAliasExes GetConsoleAliasExesA
#fim_se

  WINBASEAPI WINBOOL WINAPI PeekConsoleInputA(HANDLE hConsoleInput,PINPUT_RECORD lpBuffer,DWORD nLength,LPDWORD lpNumberOfEventsRead);
  WINBASEAPI WINBOOL WINAPI PeekConsoleInputW(HANDLE hConsoleInput,PINPUT_RECORD lpBuffer,DWORD nLength,LPDWORD lpNumberOfEventsRead);
  WINBASEAPI WINBOOL WINAPI ReadConsoleInputA(HANDLE hConsoleInput,PINPUT_RECORD lpBuffer,DWORD nLength,LPDWORD lpNumberOfEventsRead);
  WINBASEAPI WINBOOL WINAPI ReadConsoleInputW(HANDLE hConsoleInput,PINPUT_RECORD lpBuffer,DWORD nLength,LPDWORD lpNumberOfEventsRead);
  WINBASEAPI WINBOOL WINAPI WriteConsoleInputA(HANDLE hConsoleInput,CONST INPUT_RECORD *lpBuffer,DWORD nLength,LPDWORD lpNumberOfEventsWritten);
  WINBASEAPI WINBOOL WINAPI WriteConsoleInputW(HANDLE hConsoleInput,CONST INPUT_RECORD *lpBuffer,DWORD nLength,LPDWORD lpNumberOfEventsWritten);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput,PCHAR_INFO lpBuffer,COORD dwBufferSize,COORD dwBufferCoord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput,PCHAR_INFO lpBuffer,COORD dwBufferSize,COORD dwBufferCoord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput,CONST CHAR_INFO *lpBuffer,COORD dwBufferSize,COORD dwBufferCoord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput,CONST CHAR_INFO *lpBuffer,COORD dwBufferSize,COORD dwBufferCoord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput,LPSTR lpCharacter,DWORD nLength,COORD dwReadCoord,LPDWORD lpNumberOfCharsRead);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput,LPWSTR lpCharacter,DWORD nLength,COORD dwReadCoord,LPDWORD lpNumberOfCharsRead);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput,LPWORD lpAttribute,DWORD nLength,COORD dwReadCoord,LPDWORD lpNumberOfAttrsRead);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput,LPCSTR lpCharacter,DWORD nLength,COORD dwWriteCoord,LPDWORD lpNumberOfCharsWritten);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput,LPCWSTR lpCharacter,DWORD nLength,COORD dwWriteCoord,LPDWORD lpNumberOfCharsWritten);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput,CONST WORD *lpAttribute,DWORD nLength,COORD dwWriteCoord,LPDWORD lpNumberOfAttrsWritten);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput,CHAR cCharacter,DWORD nLength,COORD dwWriteCoord,LPDWORD lpNumberOfCharsWritten);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput,WCHAR cCharacter,DWORD nLength,COORD dwWriteCoord,LPDWORD lpNumberOfCharsWritten);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput,WORD wAttribute,DWORD nLength,COORD dwWriteCoord,LPDWORD lpNumberOfAttrsWritten);
  WINBASEAPI WINBOOL WINAPI GetConsoleMode(HANDLE hConsoleHandle,LPDWORD lpMode);
  WINBASEAPI WINBOOL WINAPI GetNumberOfConsoleInputEvents(HANDLE hConsoleInput,LPDWORD lpNumberOfEvents);
  WINBASEAPI WINBOOL WINAPI GetConsoleScreenBufferInfo(HANDLE hConsoleOutput,PCONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo);
  WINBASEAPI COORD WINAPI GetLargestConsoleWindowSize(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput,PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,WINBOOL bMaximumWindow,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
  WINBASEAPI COORD WINAPI GetConsoleFontSize(HANDLE hConsoleOutput,DWORD nFont);
  WINBASEAPI WINBOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);
  WINBASEAPI WINBOOL WINAPI GetNumberOfConsoleMouseButtons(LPDWORD lpNumberOfMouseButtons);
  WINBASEAPI WINBOOL WINAPI SetConsoleMode(HANDLE hConsoleHandle,DWORD dwMode);
  WINBASEAPI WINBOOL WINAPI SetConsoleActiveScreenBuffer(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI FlushConsoleInputBuffer(HANDLE hConsoleInput);
  WINBASEAPI WINBOOL WINAPI SetConsoleScreenBufferSize(HANDLE hConsoleOutput,COORD dwSize);
  WINBASEAPI WINBOOL WINAPI SetConsoleCursorPosition(HANDLE hConsoleOutput,COORD dwCursorPosition);
  WINBASEAPI WINBOOL WINAPI SetConsoleCursorInfo(HANDLE hConsoleOutput,CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI ScrollConsoleScreenBufferA(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI ScrollConsoleScreenBufferW(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI SetConsoleWindowInfo(HANDLE hConsoleOutput,WINBOOL bAbsolute,CONST SMALL_RECT *lpConsoleWindow);
  WINBASEAPI WINBOOL WINAPI SetConsoleTextAttribute(HANDLE hConsoleOutput,WORD wAttributes);
  WINBASEAPI WINBOOL WINAPI SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine,WINBOOL Add);
  WINBASEAPI WINBOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent,DWORD dwProcessGroupId);
  WINBASEAPI WINBOOL WINAPI AllocConsole(VOID);
  WINBASEAPI WINBOOL WINAPI FreeConsole(VOID);
  WINBASEAPI WINBOOL WINAPI AttachConsole(DWORD dwProcessId);

#defina ATTACH_PARENT_PROCESS ((DWORD)-1)

  WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetConsoleTitleA(LPCSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI SetConsoleTitleW(LPCWSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ReadConsoleA(HANDLE hConsoleInput,LPVOID lpBuffer,DWORD nNumberOfCharsToRead,LPDWORD lpNumberOfCharsRead,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReadConsoleW(HANDLE hConsoleInput,LPVOID lpBuffer,DWORD nNumberOfCharsToRead,LPDWORD lpNumberOfCharsRead,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleA(HANDLE hConsoleOutput,CONST VOID *lpBuffer,DWORD nNumberOfCharsToWrite,LPDWORD lpNumberOfCharsWritten,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleW(HANDLE hConsoleOutput,CONST VOID *lpBuffer,DWORD nNumberOfCharsToWrite,LPDWORD lpNumberOfCharsWritten,LPVOID lpReserved);

#defina CONSOLE_TEXTMODE_BUFFER 1

  WINBASEAPI HANDLE WINAPI CreateConsoleScreenBuffer(DWORD dwDesiredAccess,DWORD dwShareMode,CONST SECURITY_ATTRIBUTES *lpSecurityAttributes,DWORD dwFlags,LPVOID lpScreenBufferData);
  WINBASEAPI UINT WINAPI GetConsoleCP(VOID);
  WINBASEAPI WINBOOL WINAPI SetConsoleCP(UINT wCodePageID);
  WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID);
  WINBASEAPI WINBOOL WINAPI SetConsoleOutputCP(UINT wCodePageID);

#defina CONSOLE_FULLSCREEN 1
#defina CONSOLE_FULLSCREEN_HARDWARE 2

  WINBASEAPI WINBOOL WINAPI GetConsoleDisplayMode(LPDWORD lpModeFlags);
  WINBASEAPI HWND WINAPI GetConsoleWindow(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleProcessList(LPDWORD lpdwProcessList,DWORD dwProcessCount);
  WINBASEAPI WINBOOL WINAPI AddConsoleAliasA(LPSTR Source,LPSTR Target,LPSTR ExeName);
  WINBASEAPI WINBOOL WINAPI AddConsoleAliasW(LPWSTR Source,LPWSTR Target,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasA(LPSTR Source,LPSTR TargetBuffer,DWORD TargetBufferLength,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasW(LPWSTR Source,LPWSTR TargetBuffer,DWORD TargetBufferLength,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesLengthA(LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesLengthW(LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesLengthA(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesLengthW(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesA(LPSTR AliasBuffer,DWORD AliasBufferLength,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesW(LPWSTR AliasBuffer,DWORD AliasBufferLength,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesA(LPSTR ExeNameBuffer,DWORD ExeNameBufferLength);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesW(LPWSTR ExeNameBuffer,DWORD ExeNameBufferLength);

#se_definido __cplusplus
}
#fim_se
#fim_se
