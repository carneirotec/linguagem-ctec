/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _WINUSER_
#defina _WINUSER_

#defina WINUSERAPI DECLSPEC_IMPORT

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido WINVER
#defina WINVER 0x0502
#fim_se

#inclua <stdarg.h>

#se_não_definido NOUSER
  defina_tipo HANDLE HDWP;
  defina_tipo VOID MENUTEMPLATEA;
  defina_tipo VOID MENUTEMPLATEW;
  defina_tipo PVOID LPMENUTEMPLATEA;
  defina_tipo PVOID LPMENUTEMPLATEW;

#se_definido UNICODE
  defina_tipo MENUTEMPLATEW MENUTEMPLATE;
  defina_tipo LPMENUTEMPLATEW LPMENUTEMPLATE;
#senão
  defina_tipo MENUTEMPLATEA MENUTEMPLATE;
  defina_tipo LPMENUTEMPLATEA LPMENUTEMPLATE;
#fim_se

  defina_tipo LRESULT (CALLBACK *WNDPROC)(HWND,UINT,WPARAM,LPARAM);
  defina_tipo INT_PTR (CALLBACK *DLGPROC)(HWND,UINT,WPARAM,LPARAM);
  defina_tipo VOID (CALLBACK *TIMERPROC)(HWND,UINT,UINT_PTR,DWORD);
  defina_tipo WINBOOL (CALLBACK *GRAYSTRINGPROC)(HDC,LPARAM,inteiro);
  defina_tipo WINBOOL (CALLBACK *WNDENUMPROC)(HWND,LPARAM);
  defina_tipo LRESULT (CALLBACK *HOOKPROC)(inteiro code,WPARAM wParam,LPARAM lParam);
  defina_tipo VOID (CALLBACK *SENDASYNCPROC)(HWND,UINT,ULONG_PTR,LRESULT);
  defina_tipo WINBOOL (CALLBACK *PROPENUMPROCA)(HWND,LPCSTR,HANDLE);
  defina_tipo WINBOOL (CALLBACK *PROPENUMPROCW)(HWND,LPCWSTR,HANDLE);
  defina_tipo WINBOOL (CALLBACK *PROPENUMPROCEXA)(HWND,LPSTR,HANDLE,ULONG_PTR);
  defina_tipo WINBOOL (CALLBACK *PROPENUMPROCEXW)(HWND,LPWSTR,HANDLE,ULONG_PTR);
  defina_tipo inteiro (CALLBACK *EDITWORDBREAKPROCA)(LPSTR lpch,inteiro ichCurrent,inteiro cch,inteiro code);
  defina_tipo inteiro (CALLBACK *EDITWORDBREAKPROCW)(LPWSTR lpch,inteiro ichCurrent,inteiro cch,inteiro code);
  defina_tipo WINBOOL (CALLBACK *DRAWSTATEPROC)(HDC hdc,LPARAM lData,WPARAM wData,inteiro cx,inteiro cy);

#se_definido UNICODE
  defina_tipo PROPENUMPROCW PROPENUMPROC;
  defina_tipo PROPENUMPROCEXW PROPENUMPROCEX;
  defina_tipo EDITWORDBREAKPROCW EDITWORDBREAKPROC;
#senão
  defina_tipo PROPENUMPROCA PROPENUMPROC;
  defina_tipo PROPENUMPROCEXA PROPENUMPROCEX;
  defina_tipo EDITWORDBREAKPROCA EDITWORDBREAKPROC;
#fim_se

  defina_tipo WINBOOL (CALLBACK *NAMEENUMPROCA)(LPSTR,LPARAM);
  defina_tipo WINBOOL (CALLBACK *NAMEENUMPROCW)(LPWSTR,LPARAM);
  defina_tipo NAMEENUMPROCA WINSTAENUMPROCA;
  defina_tipo NAMEENUMPROCA DESKTOPENUMPROCA;
  defina_tipo NAMEENUMPROCW WINSTAENUMPROCW;
  defina_tipo NAMEENUMPROCW DESKTOPENUMPROCW;

#se_definido UNICODE
  defina_tipo WINSTAENUMPROCW WINSTAENUMPROC;
  defina_tipo DESKTOPENUMPROCW DESKTOPENUMPROC;
#senão
  defina_tipo WINSTAENUMPROCA WINSTAENUMPROC;
  defina_tipo DESKTOPENUMPROCA DESKTOPENUMPROC;
#fim_se

#defina IS_INTRESOURCE(_r) ((((ULONG_PTR)(_r)) >> 16)==0)
#defina MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((WORD)(i))))
#defina MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((WORD)(i))))
#se_definido UNICODE
#defina MAKEINTRESOURCE MAKEINTRESOURCEW
#senão
#defina MAKEINTRESOURCE MAKEINTRESOURCEA
#fim_se

#se_não_definido NORESOURCE

#defina RT_CURSOR MAKEINTRESOURCE(1)
#defina RT_BITMAP MAKEINTRESOURCE(2)
#defina RT_ICON MAKEINTRESOURCE(3)
#defina RT_MENU MAKEINTRESOURCE(4)
#defina RT_DIALOG MAKEINTRESOURCE(5)
#defina RT_STRING MAKEINTRESOURCE(6)
#defina RT_FONTDIR MAKEINTRESOURCE(7)
#defina RT_FONT MAKEINTRESOURCE(8)
#defina RT_ACCELERATOR MAKEINTRESOURCE(9)
#defina RT_RCDATA MAKEINTRESOURCE(10)
#defina RT_MESSAGETABLE MAKEINTRESOURCE(11)

#defina DIFFERENCE 11
#defina RT_GROUP_CURSOR MAKEINTRESOURCE((ULONG_PTR)RT_CURSOR + DIFFERENCE)
#defina RT_GROUP_ICON MAKEINTRESOURCE((ULONG_PTR)RT_ICON + DIFFERENCE)
#defina RT_VERSION MAKEINTRESOURCE(16)
#defina RT_DLGINCLUDE MAKEINTRESOURCE(17)
#defina RT_PLUGPLAY MAKEINTRESOURCE(19)
#defina RT_VXD MAKEINTRESOURCE(20)
#defina RT_ANICURSOR MAKEINTRESOURCE(21)
#defina RT_ANIICON MAKEINTRESOURCE(22)
#defina RT_HTML MAKEINTRESOURCE(23)
#se_definido RC_INVOKED
#defina RT_MANIFEST 24
#defina CREATEPROCESS_MANIFEST_RESOURCE_ID 1
#defina ISOLATIONAWARE_MANIFEST_RESOURCE_ID 2
#defina ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID 3
#defina MINIMUM_RESERVED_MANIFEST_RESOURCE_ID 1
#defina MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID 16
#senão
#defina RT_MANIFEST MAKEINTRESOURCE(24)
#defina CREATEPROCESS_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#defina ISOLATIONAWARE_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(2)
#defina ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(3)
#defina MINIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#defina MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(16)
#fim_se
#fim_se

#se_definido UNICODE
#defina wvsprintf wvsprintfW
#defina wsprintf wsprintfW
#senão
#defina wvsprintf wvsprintfA
#defina wsprintf wsprintfA
#fim_se

  WINUSERAPI inteiro WINAPI wvsprintfA(LPSTR,LPCSTR,va_list arglist);
  WINUSERAPI inteiro WINAPI wvsprintfW(LPWSTR,LPCWSTR,va_list arglist);
  WINUSERAPI inteiro WINAPIV wsprintfA(LPSTR,LPCSTR,...);
  WINUSERAPI inteiro WINAPIV wsprintfW(LPWSTR,LPCWSTR,...);

#defina SETWALLPAPER_DEFAULT ((LPWSTR)-1)

#se_não_definido NOSCROLL
#defina SB_HORZ 0
#defina SB_VERT 1
#defina SB_CTL 2
#defina SB_BOTH 3

#defina SB_LINEUP 0
#defina SB_LINELEFT 0
#defina SB_LINEDOWN 1
#defina SB_LINERIGHT 1
#defina SB_PAGEUP 2
#defina SB_PAGELEFT 2
#defina SB_PAGEDOWN 3
#defina SB_PAGERIGHT 3
#defina SB_THUMBPOSITION 4
#defina SB_THUMBTRACK 5
#defina SB_TOP 6
#defina SB_LEFT 6
#defina SB_BOTTOM 7
#defina SB_RIGHT 7
#defina SB_ENDSCROLL 8
#fim_se

#se_não_definido NOSHOWWINDOW
#defina SW_HIDE 0
#defina SW_SHOWNORMAL 1
#defina SW_NORMAL 1
#defina SW_SHOWMINIMIZED 2
#defina SW_SHOWMAXIMIZED 3
#defina SW_MAXIMIZE 3
#defina SW_SHOWNOACTIVATE 4
#defina SW_SHOW 5
#defina SW_MINIMIZE 6
#defina SW_SHOWMINNOACTIVE 7
#defina SW_SHOWNA 8
#defina SW_RESTORE 9
#defina SW_SHOWDEFAULT 10
#defina SW_FORCEMINIMIZE 11
#defina SW_MAX 11

#defina HIDE_WINDOW 0
#defina SHOW_OPENWINDOW 1
#defina SHOW_ICONWINDOW 2
#defina SHOW_FULLSCREEN 3
#defina SHOW_OPENNOACTIVATE 4

#defina SW_PARENTCLOSING 1
#defina SW_OTHERZOOM 2
#defina SW_PARENTOPENING 3
#defina SW_OTHERUNZOOM 4
#fim_se

#defina AW_HOR_POSITIVE 0x00000001
#defina AW_HOR_NEGATIVE 0x00000002
#defina AW_VER_POSITIVE 0x00000004
#defina AW_VER_NEGATIVE 0x00000008
#defina AW_CENTER 0x00000010
#defina AW_HIDE 0x00010000
#defina AW_ACTIVATE 0x00020000
#defina AW_SLIDE 0x00040000
#defina AW_BLEND 0x00080000

#defina KF_EXTENDED 0x0100
#defina KF_DLGMODE 0x0800
#defina KF_MENUMODE 0x1000
#defina KF_ALTDOWN 0x2000
#defina KF_REPEAT 0x4000
#defina KF_UP 0x8000

#se_não_definido NOVIRTUALKEYCODES

#defina VK_LBUTTON 0x01
#defina VK_RBUTTON 0x02
#defina VK_CANCEL 0x03
#defina VK_MBUTTON 0x04
#defina VK_XBUTTON1 0x05
#defina VK_XBUTTON2 0x06
#defina VK_BACK 0x08
#defina VK_TAB 0x09
#defina VK_CLEAR 0x0C
#defina VK_RETURN 0x0D
#defina VK_SHIFT 0x10
#defina VK_CONTROL 0x11
#defina VK_MENU 0x12
#defina VK_PAUSE 0x13
#defina VK_CAPITAL 0x14
#defina VK_KANA 0x15
#defina VK_HANGEUL 0x15
#defina VK_HANGUL 0x15
#defina VK_JUNJA 0x17
#defina VK_FINAL 0x18
#defina VK_HANJA 0x19
#defina VK_KANJI 0x19
#defina VK_ESCAPE 0x1B
#defina VK_CONVERT 0x1C
#defina VK_NONCONVERT 0x1D
#defina VK_ACCEPT 0x1E
#defina VK_MODECHANGE 0x1F
#defina VK_SPACE 0x20
#defina VK_PRIOR 0x21
#defina VK_NEXT 0x22
#defina VK_END 0x23
#defina VK_HOME 0x24
#defina VK_LEFT 0x25
#defina VK_UP 0x26
#defina VK_RIGHT 0x27
#defina VK_DOWN 0x28
#defina VK_SELECT 0x29
#defina VK_PRINT 0x2A
#defina VK_EXECUTE 0x2B
#defina VK_SNAPSHOT 0x2C
#defina VK_INSERT 0x2D
#defina VK_DELETE 0x2E
#defina VK_HELP 0x2F

#defina VK_LWIN 0x5B
#defina VK_RWIN 0x5C
#defina VK_APPS 0x5D
#defina VK_SLEEP 0x5F
#defina VK_NUMPAD0 0x60
#defina VK_NUMPAD1 0x61
#defina VK_NUMPAD2 0x62
#defina VK_NUMPAD3 0x63
#defina VK_NUMPAD4 0x64
#defina VK_NUMPAD5 0x65
#defina VK_NUMPAD6 0x66
#defina VK_NUMPAD7 0x67
#defina VK_NUMPAD8 0x68
#defina VK_NUMPAD9 0x69
#defina VK_MULTIPLY 0x6A
#defina VK_ADD 0x6B
#defina VK_SEPARATOR 0x6C
#defina VK_SUBTRACT 0x6D
#defina VK_DECIMAL 0x6E
#defina VK_DIVIDE 0x6F
#defina VK_F1 0x70
#defina VK_F2 0x71
#defina VK_F3 0x72
#defina VK_F4 0x73
#defina VK_F5 0x74
#defina VK_F6 0x75
#defina VK_F7 0x76
#defina VK_F8 0x77
#defina VK_F9 0x78
#defina VK_F10 0x79
#defina VK_F11 0x7A
#defina VK_F12 0x7B
#defina VK_F13 0x7C
#defina VK_F14 0x7D
#defina VK_F15 0x7E
#defina VK_F16 0x7F
#defina VK_F17 0x80
#defina VK_F18 0x81
#defina VK_F19 0x82
#defina VK_F20 0x83
#defina VK_F21 0x84
#defina VK_F22 0x85
#defina VK_F23 0x86
#defina VK_F24 0x87
#defina VK_NUMLOCK 0x90
#defina VK_SCROLL 0x91
#defina VK_OEM_NEC_EQUAL 0x92
#defina VK_OEM_FJ_JISHO 0x92
#defina VK_OEM_FJ_MASSHOU 0x93
#defina VK_OEM_FJ_TOUROKU 0x94
#defina VK_OEM_FJ_LOYA 0x95
#defina VK_OEM_FJ_ROYA 0x96
#defina VK_LSHIFT 0xA0
#defina VK_RSHIFT 0xA1
#defina VK_LCONTROL 0xA2
#defina VK_RCONTROL 0xA3
#defina VK_LMENU 0xA4
#defina VK_RMENU 0xA5
#defina VK_BROWSER_BACK 0xA6
#defina VK_BROWSER_FORWARD 0xA7
#defina VK_BROWSER_REFRESH 0xA8
#defina VK_BROWSER_STOP 0xA9
#defina VK_BROWSER_SEARCH 0xAA
#defina VK_BROWSER_FAVORITES 0xAB
#defina VK_BROWSER_HOME 0xAC
#defina VK_VOLUME_MUTE 0xAD
#defina VK_VOLUME_DOWN 0xAE
#defina VK_VOLUME_UP 0xAF
#defina VK_MEDIA_NEXT_TRACK 0xB0
#defina VK_MEDIA_PREV_TRACK 0xB1
#defina VK_MEDIA_STOP 0xB2
#defina VK_MEDIA_PLAY_PAUSE 0xB3
#defina VK_LAUNCH_MAIL 0xB4
#defina VK_LAUNCH_MEDIA_SELECT 0xB5
#defina VK_LAUNCH_APP1 0xB6
#defina VK_LAUNCH_APP2 0xB7
#defina VK_OEM_1 0xBA
#defina VK_OEM_PLUS 0xBB
#defina VK_OEM_COMMA 0xBC
#defina VK_OEM_MINUS 0xBD
#defina VK_OEM_PERIOD 0xBE
#defina VK_OEM_2 0xBF
#defina VK_OEM_3 0xC0
#defina VK_OEM_4 0xDB
#defina VK_OEM_5 0xDC
#defina VK_OEM_6 0xDD
#defina VK_OEM_7 0xDE
#defina VK_OEM_8 0xDF
#defina VK_OEM_AX 0xE1
#defina VK_OEM_102 0xE2
#defina VK_ICO_HELP 0xE3
#defina VK_ICO_00 0xE4
#defina VK_PROCESSKEY 0xE5
#defina VK_ICO_CLEAR 0xE6
#defina VK_PACKET 0xE7
#defina VK_OEM_RESET 0xE9
#defina VK_OEM_JUMP 0xEA
#defina VK_OEM_PA1 0xEB
#defina VK_OEM_PA2 0xEC
#defina VK_OEM_PA3 0xED
#defina VK_OEM_WSCTRL 0xEE
#defina VK_OEM_CUSEL 0xEF
#defina VK_OEM_ATTN 0xF0
#defina VK_OEM_FINISH 0xF1
#defina VK_OEM_COPY 0xF2
#defina VK_OEM_AUTO 0xF3
#defina VK_OEM_ENLW 0xF4
#defina VK_OEM_BACKTAB 0xF5
#defina VK_ATTN 0xF6
#defina VK_CRSEL 0xF7
#defina VK_EXSEL 0xF8
#defina VK_EREOF 0xF9
#defina VK_PLAY 0xFA
#defina VK_ZOOM 0xFB
#defina VK_NONAME 0xFC
#defina VK_PA1 0xFD
#defina VK_OEM_CLEAR 0xFE
#fim_se

#se_não_definido NOWH

#defina WH_MIN (-1)
#defina WH_MSGFILTER (-1)
#defina WH_JOURNALRECORD 0
#defina WH_JOURNALPLAYBACK 1
#defina WH_KEYBOARD 2
#defina WH_GETMESSAGE 3
#defina WH_CALLWNDPROC 4
#defina WH_CBT 5
#defina WH_SYSMSGFILTER 6
#defina WH_MOUSE 7
#defina WH_HARDWARE 8
#defina WH_DEBUG 9
#defina WH_SHELL 10
#defina WH_FOREGROUNDIDLE 11
#defina WH_CALLWNDPROCRET 12

#defina WH_KEYBOARD_LL 13
#defina WH_MOUSE_LL 14

#defina WH_MAX 14

#defina WH_MINHOOK WH_MIN
#defina WH_MAXHOOK WH_MAX

#defina HC_ACTION 0
#defina HC_GETNEXT 1
#defina HC_SKIP 2
#defina HC_NOREMOVE 3
#defina HC_NOREM HC_NOREMOVE
#defina HC_SYSMODALON 4
#defina HC_SYSMODALOFF 5

#defina HCBT_MOVESIZE 0
#defina HCBT_MINMAX 1
#defina HCBT_QS 2
#defina HCBT_CREATEWND 3
#defina HCBT_DESTROYWND 4
#defina HCBT_ACTIVATE 5
#defina HCBT_CLICKSKIPPED 6
#defina HCBT_KEYSKIPPED 7
#defina HCBT_SYSCOMMAND 8
#defina HCBT_SETFOCUS 9

  defina_tipo estrutura tagCBT_CREATEWNDA {
    estrutura tagCREATESTRUCTA *lpcs;
    HWND hwndInsertAfter;
  } CBT_CREATEWNDA,*LPCBT_CREATEWNDA;

  defina_tipo estrutura tagCBT_CREATEWNDW {
    estrutura tagCREATESTRUCTW *lpcs;
    HWND hwndInsertAfter;
  } CBT_CREATEWNDW,*LPCBT_CREATEWNDW;
#se_definido UNICODE
  defina_tipo CBT_CREATEWNDW CBT_CREATEWND;
  defina_tipo LPCBT_CREATEWNDW LPCBT_CREATEWND;
#senão
  defina_tipo CBT_CREATEWNDA CBT_CREATEWND;
  defina_tipo LPCBT_CREATEWNDA LPCBT_CREATEWND;
#fim_se

  defina_tipo estrutura tagCBTACTIVATESTRUCT
  {
    WINBOOL fMouse;
    HWND hWndActive;
  } CBTACTIVATESTRUCT,*LPCBTACTIVATESTRUCT;

  defina_tipo estrutura tagWTSSESSION_NOTIFICATION {
    DWORD cbSize;
    DWORD dwSessionId;

  } WTSSESSION_NOTIFICATION,*PWTSSESSION_NOTIFICATION;

#defina WTS_CONSOLE_CONNECT 0x1
#defina WTS_CONSOLE_DISCONNECT 0x2
#defina WTS_REMOTE_CONNECT 0x3
#defina WTS_REMOTE_DISCONNECT 0x4
#defina WTS_SESSION_LOGON 0x5
#defina WTS_SESSION_LOGOFF 0x6
#defina WTS_SESSION_LOCK 0x7
#defina WTS_SESSION_UNLOCK 0x8
#defina WTS_SESSION_REMOTE_CONTROL 0x9

#defina MSGF_DIALOGBOX 0
#defina MSGF_MESSAGEBOX 1
#defina MSGF_MENU 2
#defina MSGF_SCROLLBAR 5
#defina MSGF_NEXTWINDOW 6
#defina MSGF_MAX 8
#defina MSGF_USER 4096

#defina HSHELL_WINDOWCREATED 1
#defina HSHELL_WINDOWDESTROYED 2
#defina HSHELL_ACTIVATESHELLWINDOW 3

#defina HSHELL_WINDOWACTIVATED 4
#defina HSHELL_GETMINRECT 5
#defina HSHELL_REDRAW 6
#defina HSHELL_TASKMAN 7
#defina HSHELL_LANGUAGE 8
#defina HSHELL_SYSMENU 9
#defina HSHELL_ENDTASK 10
#defina HSHELL_ACCESSIBILITYSTATE 11
#defina HSHELL_APPCOMMAND 12
#defina HSHELL_WINDOWREPLACED 13
#defina HSHELL_WINDOWREPLACING 14
#defina HSHELL_HIGHBIT 0x8000
#defina HSHELL_FLASH (HSHELL_REDRAW|HSHELL_HIGHBIT)
#defina HSHELL_RUDEAPPACTIVATED (HSHELL_WINDOWACTIVATED|HSHELL_HIGHBIT)

#defina ACCESS_STICKYKEYS 0x0001
#defina ACCESS_FILTERKEYS 0x0002
#defina ACCESS_MOUSEKEYS 0x0003

#defina APPCOMMAND_BROWSER_BACKWARD 1
#defina APPCOMMAND_BROWSER_FORWARD 2
#defina APPCOMMAND_BROWSER_REFRESH 3
#defina APPCOMMAND_BROWSER_STOP 4
#defina APPCOMMAND_BROWSER_SEARCH 5
#defina APPCOMMAND_BROWSER_FAVORITES 6
#defina APPCOMMAND_BROWSER_HOME 7
#defina APPCOMMAND_VOLUME_MUTE 8
#defina APPCOMMAND_VOLUME_DOWN 9
#defina APPCOMMAND_VOLUME_UP 10
#defina APPCOMMAND_MEDIA_NEXTTRACK 11
#defina APPCOMMAND_MEDIA_PREVIOUSTRACK 12
#defina APPCOMMAND_MEDIA_STOP 13
#defina APPCOMMAND_MEDIA_PLAY_PAUSE 14
#defina APPCOMMAND_LAUNCH_MAIL 15
#defina APPCOMMAND_LAUNCH_MEDIA_SELECT 16
#defina APPCOMMAND_LAUNCH_APP1 17
#defina APPCOMMAND_LAUNCH_APP2 18
#defina APPCOMMAND_BASS_DOWN 19
#defina APPCOMMAND_BASS_BOOST 20
#defina APPCOMMAND_BASS_UP 21
#defina APPCOMMAND_TREBLE_DOWN 22
#defina APPCOMMAND_TREBLE_UP 23
#defina APPCOMMAND_MICROPHONE_VOLUME_MUTE 24
#defina APPCOMMAND_MICROPHONE_VOLUME_DOWN 25
#defina APPCOMMAND_MICROPHONE_VOLUME_UP 26
#defina APPCOMMAND_HELP 27
#defina APPCOMMAND_FIND 28
#defina APPCOMMAND_NEW 29
#defina APPCOMMAND_OPEN 30
#defina APPCOMMAND_CLOSE 31
#defina APPCOMMAND_SAVE 32
#defina APPCOMMAND_PRINT 33
#defina APPCOMMAND_UNDO 34
#defina APPCOMMAND_REDO 35
#defina APPCOMMAND_COPY 36
#defina APPCOMMAND_CUT 37
#defina APPCOMMAND_PASTE 38
#defina APPCOMMAND_REPLY_TO_MAIL 39
#defina APPCOMMAND_FORWARD_MAIL 40
#defina APPCOMMAND_SEND_MAIL 41
#defina APPCOMMAND_SPELL_CHECK 42
#defina APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE 43
#defina APPCOMMAND_MIC_ON_OFF_TOGGLE 44
#defina APPCOMMAND_CORRECTION_LIST 45
#defina APPCOMMAND_MEDIA_PLAY 46
#defina APPCOMMAND_MEDIA_PAUSE 47
#defina APPCOMMAND_MEDIA_RECORD 48
#defina APPCOMMAND_MEDIA_FAST_FORWARD 49
#defina APPCOMMAND_MEDIA_REWIND 50
#defina APPCOMMAND_MEDIA_CHANNEL_UP 51
#defina APPCOMMAND_MEDIA_CHANNEL_DOWN 52

#defina FAPPCOMMAND_MOUSE 0x8000
#defina FAPPCOMMAND_KEY 0
#defina FAPPCOMMAND_OEM 0x1000
#defina FAPPCOMMAND_MASK 0xF000

#defina GET_APPCOMMAND_LPARAM(lParam) ((curto)(HIWORD(lParam) & ~FAPPCOMMAND_MASK))
#defina GET_DEVICE_LPARAM(lParam) ((WORD)(HIWORD(lParam) & FAPPCOMMAND_MASK))
#defina GET_MOUSEORKEY_LPARAM GET_DEVICE_LPARAM
#defina GET_FLAGS_LPARAM(lParam) (LOWORD(lParam))
#defina GET_KEYSTATE_LPARAM(lParam) GET_FLAGS_LPARAM(lParam)

  defina_tipo estrutura {
    HWND hwnd;
    RECT rc;
  } SHELLHOOKINFO,*LPSHELLHOOKINFO;

  defina_tipo estrutura tagEVENTMSG {
    UINT message;
    UINT paramL;
    UINT paramH;
    DWORD time;
    HWND hwnd;
  } EVENTMSG,*PEVENTMSGMSG,*NPEVENTMSGMSG,*LPEVENTMSGMSG;

  defina_tipo estrutura tagEVENTMSG *PEVENTMSG,*NPEVENTMSG,*LPEVENTMSG;

  defina_tipo estrutura tagCWPSTRUCT {
    LPARAM lParam;
    WPARAM wParam;
    UINT message;
    HWND hwnd;
  } CWPSTRUCT,*PCWPSTRUCT,*NPCWPSTRUCT,*LPCWPSTRUCT;

  defina_tipo estrutura tagCWPRETSTRUCT {
    LRESULT lResult;
    LPARAM lParam;
    WPARAM wParam;
    UINT message;
    HWND hwnd;
  } CWPRETSTRUCT,*PCWPRETSTRUCT,*NPCWPRETSTRUCT,*LPCWPRETSTRUCT;

#defina LLKHF_EXTENDED (KF_EXTENDED >> 8)
#defina LLKHF_INJECTED 0x00000010
#defina LLKHF_ALTDOWN (KF_ALTDOWN >> 8)
#defina LLKHF_UP (KF_UP >> 8)

#defina LLMHF_INJECTED 0x00000001

  defina_tipo estrutura tagKBDLLHOOKSTRUCT {
    DWORD vkCode;
    DWORD scanCode;
    DWORD flags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
  } KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;

  defina_tipo estrutura tagMSLLHOOKSTRUCT {
    POINT pt;
    DWORD mouseData;
    DWORD flags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
  } MSLLHOOKSTRUCT,*LPMSLLHOOKSTRUCT,*PMSLLHOOKSTRUCT;

  defina_tipo estrutura tagDEBUGHOOKINFO {
    DWORD idThread;
    DWORD idThreadInstaller;
    LPARAM lParam;
    WPARAM wParam;
    inteiro code;
  } DEBUGHOOKINFO,*PDEBUGHOOKINFO,*NPDEBUGHOOKINFO,*LPDEBUGHOOKINFO;

  defina_tipo estrutura tagMOUSEHOOKSTRUCT {
    POINT pt;
    HWND hwnd;
    UINT wHitTestCode;
    ULONG_PTR dwExtraInfo;
  } MOUSEHOOKSTRUCT,*LPMOUSEHOOKSTRUCT,*PMOUSEHOOKSTRUCT;

#se_definido __cplusplus
  defina_tipo estrutura tagMOUSEHOOKSTRUCTEX : public tagMOUSEHOOKSTRUCT {
    DWORD mouseData;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#senão
  defina_tipo estrutura tagMOUSEHOOKSTRUCTEX {
    MOUSEHOOKSTRUCT _unnamed;
    DWORD mouseData;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#fim_se

  defina_tipo estrutura tagHARDWAREHOOKSTRUCT {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
  } HARDWAREHOOKSTRUCT,*LPHARDWAREHOOKSTRUCT,*PHARDWAREHOOKSTRUCT;
#fim_se

#defina HKL_PREV 0
#defina HKL_NEXT 1

#defina KLF_ACTIVATE 0x00000001
#defina KLF_SUBSTITUTE_OK 0x00000002
#defina KLF_REORDER 0x00000008
#defina KLF_REPLACELANG 0x00000010
#defina KLF_NOTELLSHELL 0x00000080
#defina KLF_SETFORPROCESS 0x00000100
#defina KLF_SHIFTLOCK 0x00010000
#defina KLF_RESET 0x40000000

#defina INPUTLANGCHANGE_SYSCHARSET 0x0001
#defina INPUTLANGCHANGE_FORWARD 0x0002
#defina INPUTLANGCHANGE_BACKWARD 0x0004

#defina KL_NAMELENGTH 9

#se_definido UNICODE
#defina LoadKeyboardLayout LoadKeyboardLayoutW
#defina GetKeyboardLayoutName GetKeyboardLayoutNameW
#senão
#defina LoadKeyboardLayout LoadKeyboardLayoutA
#defina GetKeyboardLayoutName GetKeyboardLayoutNameA
#fim_se

  WINUSERAPI HKL WINAPI LoadKeyboardLayoutA(LPCSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI LoadKeyboardLayoutW(LPCWSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI ActivateKeyboardLayout(HKL hkl,UINT Flags);
  WINUSERAPI inteiro WINAPI ToUnicodeEx(UINT wVirtKey,UINT wScanCode,CONST BYTE *lpKeyState,LPWSTR pwszBuff,inteiro cchBuff,UINT wFlags,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI UnloadKeyboardLayout(HKL hkl);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameA(LPSTR pwszKLID);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameW(LPWSTR pwszKLID);
  WINUSERAPI inteiro WINAPI GetKeyboardLayoutList(inteiro nBuff,HKL *lpList);
  WINUSERAPI HKL WINAPI GetKeyboardLayout(DWORD idThread);

  defina_tipo estrutura tagMOUSEMOVEPOINT {
    inteiro x;
    inteiro y;
    DWORD time;
    ULONG_PTR dwExtraInfo;
  } MOUSEMOVEPOINT,*PMOUSEMOVEPOINT,*LPMOUSEMOVEPOINT;

#defina GMMP_USE_DISPLAY_POINTS 1
#defina GMMP_USE_HIGH_RESOLUTION_POINTS 2

  WINUSERAPI inteiro WINAPI GetMouseMovePointsEx(UINT cbSize,LPMOUSEMOVEPOINT lppt,LPMOUSEMOVEPOINT lpptBuf,inteiro nBufPoints,DWORD resolution);

#se_não_definido NODESKTOP

#defina DESKTOP_READOBJECTS 0x0001L
#defina DESKTOP_CREATEWINDOW 0x0002L
#defina DESKTOP_CREATEMENU 0x0004L
#defina DESKTOP_HOOKCONTROL 0x0008L
#defina DESKTOP_JOURNALRECORD 0x0010L
#defina DESKTOP_JOURNALPLAYBACK 0x0020L
#defina DESKTOP_ENUMERATE 0x0040L
#defina DESKTOP_WRITEOBJECTS 0x0080L
#defina DESKTOP_SWITCHDESKTOP 0x0100L

#defina DF_ALLOWOTHERACCOUNTHOOK 0x0001L

#se_definido _WINGDI_
#se_não_definido NOGDI
#se_definido UNICODE
#defina CreateDesktop CreateDesktopW
#senão
#defina CreateDesktop CreateDesktopA
#fim_se

  WINUSERAPI HDESK WINAPI CreateDesktopA(LPCSTR lpszDesktop,LPCSTR lpszDevice,LPDEVMODEA pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa);
  WINUSERAPI HDESK WINAPI CreateDesktopW(LPCWSTR lpszDesktop,LPCWSTR lpszDevice,LPDEVMODEW pDevmode,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa);
#fim_se
#fim_se

#se_definido UNICODE
#defina OpenDesktop OpenDesktopW
#defina EnumDesktops EnumDesktopsW
#senão
#defina OpenDesktop OpenDesktopA
#defina EnumDesktops EnumDesktopsA
#fim_se

  WINUSERAPI HDESK WINAPI OpenDesktopA(LPCSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_MASK dwDesiredAccess);
  WINUSERAPI HDESK WINAPI OpenDesktopW(LPCWSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_MASK dwDesiredAccess);
  WINUSERAPI HDESK WINAPI OpenInputDesktop(DWORD dwFlags,WINBOOL fInherit,ACCESS_MASK dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsA(HWINSTA hwinsta,DESKTOPENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsW(HWINSTA hwinsta,DESKTOPENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopWindows(HDESK hDesktop,WNDENUMPROC lpfn,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI SwitchDesktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI SetThreadDesktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI CloseDesktop(HDESK hDesktop);
  WINUSERAPI HDESK WINAPI GetThreadDesktop(DWORD dwThreadId);
#fim_se

#se_não_definido NOWINDOWSTATION
#defina WINSTA_ENUMDESKTOPS 0x0001L
#defina WINSTA_READATTRIBUTES 0x0002L
#defina WINSTA_ACCESSCLIPBOARD 0x0004L
#defina WINSTA_CREATEDESKTOP 0x0008L
#defina WINSTA_WRITEATTRIBUTES 0x0010L
#defina WINSTA_ACCESSGLOBALATOMS 0x0020L
#defina WINSTA_EXITWINDOWS 0x0040L
#defina WINSTA_ENUMERATE 0x0100L
#defina WINSTA_READSCREEN 0x0200L
#defina WINSTA_ALL_ACCESS (WINSTA_ENUMDESKTOPS | WINSTA_READATTRIBUTES | WINSTA_ACCESSCLIPBOARD | WINSTA_CREATEDESKTOP | WINSTA_WRITEATTRIBUTES | WINSTA_ACCESSGLOBALATOMS | WINSTA_EXITWINDOWS | WINSTA_ENUMERATE | WINSTA_READSCREEN)

#defina CWF_CREATE_ONLY 0x0001L

#defina WSF_VISIBLE 0x0001L

#se_definido UNICODE
#defina CreateWindowStation CreateWindowStationW
#defina OpenWindowStation OpenWindowStationW
#defina EnumWindowStations EnumWindowStationsW
#senão
#defina CreateWindowStation CreateWindowStationA
#defina OpenWindowStation OpenWindowStationA
#defina EnumWindowStations EnumWindowStationsA
#fim_se

  WINUSERAPI HWINSTA WINAPI CreateWindowStationA(LPCSTR lpwinsta,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa);
  WINUSERAPI HWINSTA WINAPI CreateWindowStationW(LPCWSTR lpwinsta,DWORD dwFlags,ACCESS_MASK dwDesiredAccess,LPSECURITY_ATTRIBUTES lpsa);
  WINUSERAPI HWINSTA WINAPI OpenWindowStationA(LPCSTR lpszWinSta,WINBOOL fInherit,ACCESS_MASK dwDesiredAccess);
  WINUSERAPI HWINSTA WINAPI OpenWindowStationW(LPCWSTR lpszWinSta,WINBOOL fInherit,ACCESS_MASK dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI EnumWindowStationsA(WINSTAENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumWindowStationsW(WINSTAENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI CloseWindowStation(HWINSTA hWinSta);
  WINUSERAPI WINBOOL WINAPI SetProcessWindowStation(HWINSTA hWinSta);
  WINUSERAPI HWINSTA WINAPI GetProcessWindowStation(VOID);
#fim_se

#se_não_definido NOSECURITY
  WINUSERAPI WINBOOL WINAPI SetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID);
  WINUSERAPI WINBOOL WINAPI GetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID,DWORD nLength,LPDWORD lpnLengthNeeded);

#defina UOI_FLAGS 1
#defina UOI_NAME 2
#defina UOI_TYPE 3
#defina UOI_USER_SID 4

  defina_tipo estrutura tagUSEROBJECTFLAGS {
    WINBOOL fInherit;
    WINBOOL fReserved;
    DWORD dwFlags;
  } USEROBJECTFLAGS,*PUSEROBJECTFLAGS;

#se_definido UNICODE
#defina GetUserObjectInformation GetUserObjectInformationW
#defina SetUserObjectInformation SetUserObjectInformationW
#senão
#defina GetUserObjectInformation GetUserObjectInformationA
#defina SetUserObjectInformation SetUserObjectInformationA
#fim_se

  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationA(HANDLE hObj,inteiro nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded);
  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationW(HANDLE hObj,inteiro nIndex,PVOID pvInfo,DWORD nLength,LPDWORD lpnLengthNeeded);
  WINUSERAPI WINBOOL WINAPI SetUserObjectInformationA(HANDLE hObj,inteiro nIndex,PVOID pvInfo,DWORD nLength);
  WINUSERAPI WINBOOL WINAPI SetUserObjectInformationW(HANDLE hObj,inteiro nIndex,PVOID pvInfo,DWORD nLength);
#fim_se

  defina_tipo estrutura tagWNDCLASSEXA {
    UINT cbSize;
    UINT style;
    WNDPROC lpfnWndProc;
    inteiro cbClsExtra;
    inteiro cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
    HICON hIconSm;
  } WNDCLASSEXA,*PWNDCLASSEXA,*NPWNDCLASSEXA,*LPWNDCLASSEXA;

  defina_tipo estrutura tagWNDCLASSEXW {
    UINT cbSize;
    UINT style;
    WNDPROC lpfnWndProc;
    inteiro cbClsExtra;
    inteiro cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;

    HICON hIconSm;
  } WNDCLASSEXW,*PWNDCLASSEXW,*NPWNDCLASSEXW,*LPWNDCLASSEXW;

#se_definido UNICODE
  defina_tipo WNDCLASSEXW WNDCLASSEX;
  defina_tipo PWNDCLASSEXW PWNDCLASSEX;
  defina_tipo NPWNDCLASSEXW NPWNDCLASSEX;
  defina_tipo LPWNDCLASSEXW LPWNDCLASSEX;
#senão
  defina_tipo WNDCLASSEXA WNDCLASSEX;
  defina_tipo PWNDCLASSEXA PWNDCLASSEX;
  defina_tipo NPWNDCLASSEXA NPWNDCLASSEX;
  defina_tipo LPWNDCLASSEXA LPWNDCLASSEX;
#fim_se

  defina_tipo estrutura tagWNDCLASSA {
    UINT style;
    WNDPROC lpfnWndProc;
    inteiro cbClsExtra;
    inteiro cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
  } WNDCLASSA,*PWNDCLASSA,*NPWNDCLASSA,*LPWNDCLASSA;

  defina_tipo estrutura tagWNDCLASSW {
    UINT style;
    WNDPROC lpfnWndProc;
    inteiro cbClsExtra;
    inteiro cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
  } WNDCLASSW,*PWNDCLASSW,*NPWNDCLASSW,*LPWNDCLASSW;

#se_definido UNICODE
  defina_tipo WNDCLASSW WNDCLASS;
  defina_tipo PWNDCLASSW PWNDCLASS;
  defina_tipo NPWNDCLASSW NPWNDCLASS;
  defina_tipo LPWNDCLASSW LPWNDCLASS;
#senão
  defina_tipo WNDCLASSA WNDCLASS;
  defina_tipo PWNDCLASSA PWNDCLASS;
  defina_tipo NPWNDCLASSA NPWNDCLASS;
  defina_tipo LPWNDCLASSA LPWNDCLASS;
#fim_se

  WINUSERAPI WINBOOL WINAPI IsHungAppWindow(HWND hwnd);
  WINUSERAPI VOID WINAPI DisableProcessWindowsGhosting(VOID);

#se_não_definido NOMSG
  defina_tipo estrutura tagMSG {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
  } MSG,*PMSG,*NPMSG,*LPMSG;

#defina POINTSTOPOINT(pt,pts) { (pt).x = (LONG)(SHORT)LOWORD(*(LONG*)&pts); (pt).y = (LONG)(SHORT)HIWORD(*(LONG*)&pts); }

#defina POINTTOPOINTS(pt) (MAKELONG((curto)((pt).x),(curto)((pt).y)))
#defina MAKEWPARAM(l,h) ((WPARAM)(DWORD)MAKELONG(l,h))
#defina MAKELPARAM(l,h) ((LPARAM)(DWORD)MAKELONG(l,h))
#defina MAKELRESULT(l,h) ((LRESULT)(DWORD)MAKELONG(l,h))
#fim_se

#se_não_definido NOWINOFFSETS
#defina GWL_WNDPROC (-4)
#defina GWL_HINSTANCE (-6)
#defina GWL_HWNDPARENT (-8)
#defina GWL_STYLE (-16)
#defina GWL_EXSTYLE (-20)
#defina GWL_USERDATA (-21)
#defina GWL_ID (-12)

#se_definido _WIN64
#não_definido GWL_WNDPROC
#não_definido GWL_HINSTANCE
#não_definido GWL_HWNDPARENT
#não_definido GWL_USERDATA
#fim_se

#defina GWLP_WNDPROC (-4)
#defina GWLP_HINSTANCE (-6)
#defina GWLP_HWNDPARENT (-8)
#defina GWLP_USERDATA (-21)
#defina GWLP_ID (-12)

#defina GCL_MENUNAME (-8)
#defina GCL_HBRBACKGROUND (-10)
#defina GCL_HCURSOR (-12)
#defina GCL_HICON (-14)
#defina GCL_HMODULE (-16)
#defina GCL_CBWNDEXTRA (-18)
#defina GCL_CBCLSEXTRA (-20)
#defina GCL_WNDPROC (-24)
#defina GCL_STYLE (-26)
#defina GCW_ATOM (-32)
#defina GCL_HICONSM (-34)

#se_definido _WIN64

#não_definido GCL_MENUNAME
#não_definido GCL_HBRBACKGROUND
#não_definido GCL_HCURSOR
#não_definido GCL_HICON
#não_definido GCL_HMODULE
#não_definido GCL_WNDPROC
#não_definido GCL_HICONSM
#fim_se

#defina GCLP_MENUNAME (-8)
#defina GCLP_HBRBACKGROUND (-10)
#defina GCLP_HCURSOR (-12)
#defina GCLP_HICON (-14)
#defina GCLP_HMODULE (-16)
#defina GCLP_WNDPROC (-24)
#defina GCLP_HICONSM (-34)
#fim_se

#se_não_definido NOWINMESSAGES

#defina WM_NULL 0x0000
#defina WM_CREATE 0x0001
#defina WM_DESTROY 0x0002
#defina WM_MOVE 0x0003
#defina WM_SIZE 0x0005

#defina WM_ACTIVATE 0x0006

#defina WA_INACTIVE 0
#defina WA_ACTIVE 1
#defina WA_CLICKACTIVE 2

#defina WM_SETFOCUS 0x0007
#defina WM_KILLFOCUS 0x0008
#defina WM_ENABLE 0x000A
#defina WM_SETREDRAW 0x000B
#defina WM_SETTEXT 0x000C
#defina WM_GETTEXT 0x000D
#defina WM_GETTEXTLENGTH 0x000E
#defina WM_PAINT 0x000F
#defina WM_CLOSE 0x0010
#se_não_definido _WIN32_WCE
#defina WM_QUERYENDSESSION 0x0011
#defina WM_QUERYOPEN 0x0013
#defina WM_ENDSESSION 0x0016
#fim_se
#defina WM_QUIT 0x0012
#defina WM_ERASEBKGND 0x0014
#defina WM_SYSCOLORCHANGE 0x0015
#defina WM_SHOWWINDOW 0x0018
#defina WM_WININICHANGE 0x001A
#defina WM_SETTINGCHANGE WM_WININICHANGE
#defina WM_DEVMODECHANGE 0x001B
#defina WM_ACTIVATEAPP 0x001C
#defina WM_FONTCHANGE 0x001D
#defina WM_TIMECHANGE 0x001E
#defina WM_CANCELMODE 0x001F
#defina WM_SETCURSOR 0x0020
#defina WM_MOUSEACTIVATE 0x0021
#defina WM_CHILDACTIVATE 0x0022
#defina WM_QUEUESYNC 0x0023

#defina WM_GETMINMAXINFO 0x0024

  defina_tipo estrutura tagMINMAXINFO {
    POINT ptReserved;
    POINT ptMaxSize;
    POINT ptMaxPosition;
    POINT ptMinTrackSize;
    POINT ptMaxTrackSize;
  } MINMAXINFO,*PMINMAXINFO,*LPMINMAXINFO;

#defina WM_PAINTICON 0x0026
#defina WM_ICONERASEBKGND 0x0027
#defina WM_NEXTDLGCTL 0x0028
#defina WM_SPOOLERSTATUS 0x002A
#defina WM_DRAWITEM 0x002B
#defina WM_MEASUREITEM 0x002C
#defina WM_DELETEITEM 0x002D
#defina WM_VKEYTOITEM 0x002E
#defina WM_CHARTOITEM 0x002F
#defina WM_SETFONT 0x0030
#defina WM_GETFONT 0x0031
#defina WM_SETHOTKEY 0x0032
#defina WM_GETHOTKEY 0x0033
#defina WM_QUERYDRAGICON 0x0037
#defina WM_COMPAREITEM 0x0039
#se_não_definido _WIN32_WCE
#defina WM_GETOBJECT 0x003D
#fim_se
#defina WM_COMPACTING 0x0041
#defina WM_COMMNOTIFY 0x0044
#defina WM_WINDOWPOSCHANGING 0x0046
#defina WM_WINDOWPOSCHANGED 0x0047

#defina WM_POWER 0x0048

#defina PWR_OK 1
#defina PWR_FAIL (-1)
#defina PWR_SUSPENDREQUEST 1
#defina PWR_SUSPENDRESUME 2
#defina PWR_CRITICALRESUME 3

#defina WM_COPYDATA 0x004A
#defina WM_CANCELJOURNAL 0x004B

  defina_tipo estrutura tagCOPYDATASTRUCT {
    ULONG_PTR dwData;
    DWORD cbData;
    PVOID lpData;
  } COPYDATASTRUCT,*PCOPYDATASTRUCT;

  defina_tipo estrutura tagMDINEXTMENU {
    HMENU hmenuIn;
    HMENU hmenuNext;
    HWND hwndNext;
  } MDINEXTMENU,*PMDINEXTMENU,*LPMDINEXTMENU;

#defina WM_NOTIFY 0x004E
#defina WM_INPUTLANGCHANGEREQUEST 0x0050
#defina WM_INPUTLANGCHANGE 0x0051
#defina WM_TCARD 0x0052
#defina WM_HELP 0x0053
#defina WM_USERCHANGED 0x0054
#defina WM_NOTIFYFORMAT 0x0055

#defina NFR_ANSI 1
#defina NFR_UNICODE 2
#defina NF_QUERY 3
#defina NF_REQUERY 4

#defina WM_CONTEXTMENU 0x007B
#defina WM_STYLECHANGING 0x007C
#defina WM_STYLECHANGED 0x007D
#defina WM_DISPLAYCHANGE 0x007E
#defina WM_GETICON 0x007F
#defina WM_SETICON 0x0080

#defina WM_NCCREATE 0x0081
#defina WM_NCDESTROY 0x0082
#defina WM_NCCALCSIZE 0x0083
#defina WM_NCHITTEST 0x0084
#defina WM_NCPAINT 0x0085
#defina WM_NCACTIVATE 0x0086
#defina WM_GETDLGCODE 0x0087
#se_não_definido _WIN32_WCE
#defina WM_SYNCPAINT 0x0088
#fim_se
#defina WM_NCMOUSEMOVE 0x00A0
#defina WM_NCLBUTTONDOWN 0x00A1
#defina WM_NCLBUTTONUP 0x00A2
#defina WM_NCLBUTTONDBLCLK 0x00A3
#defina WM_NCRBUTTONDOWN 0x00A4
#defina WM_NCRBUTTONUP 0x00A5
#defina WM_NCRBUTTONDBLCLK 0x00A6
#defina WM_NCMBUTTONDOWN 0x00A7
#defina WM_NCMBUTTONUP 0x00A8
#defina WM_NCMBUTTONDBLCLK 0x00A9

#defina WM_NCXBUTTONDOWN 0x00AB
#defina WM_NCXBUTTONUP 0x00AC
#defina WM_NCXBUTTONDBLCLK 0x00AD
#defina WM_INPUT 0x00FF
#defina WM_KEYFIRST 0x0100
#defina WM_KEYDOWN 0x0100
#defina WM_KEYUP 0x0101
#defina WM_CHAR 0x0102
#defina WM_DEADCHAR 0x0103
#defina WM_SYSKEYDOWN 0x0104
#defina WM_SYSKEYUP 0x0105
#defina WM_SYSCHAR 0x0106
#defina WM_SYSDEADCHAR 0x0107
#defina WM_UNICHAR 0x0109
#defina WM_KEYLAST 0x0109
#defina UNICODE_NOCHAR 0xFFFF
#defina WM_IME_STARTCOMPOSITION 0x010D
#defina WM_IME_ENDCOMPOSITION 0x010E
#defina WM_IME_COMPOSITION 0x010F
#defina WM_IME_KEYLAST 0x010F
#defina WM_INITDIALOG 0x0110
#defina WM_COMMAND 0x0111
#defina WM_SYSCOMMAND 0x0112
#defina WM_TIMER 0x0113
#defina WM_HSCROLL 0x0114
#defina WM_VSCROLL 0x0115
#defina WM_INITMENU 0x0116
#defina WM_INITMENUPOPUP 0x0117
#defina WM_MENUSELECT 0x011F
#defina WM_MENUCHAR 0x0120
#defina WM_ENTERIDLE 0x0121
#se_não_definido _WIN32_WCE
#defina WM_MENURBUTTONUP 0x0122
#defina WM_MENUDRAG 0x0123
#defina WM_MENUGETOBJECT 0x0124
#defina WM_UNINITMENUPOPUP 0x0125
#defina WM_MENUCOMMAND 0x0126

#se_não_definido _WIN32_WCE
#defina WM_CHANGEUISTATE 0x0127
#defina WM_UPDATEUISTATE 0x0128
#defina WM_QUERYUISTATE 0x0129

#defina UIS_SET 1
#defina UIS_CLEAR 2
#defina UIS_INITIALIZE 3

#defina UISF_HIDEFOCUS 0x1
#defina UISF_HIDEACCEL 0x2
#defina UISF_ACTIVE 0x4
#fim_se
#fim_se

#defina WM_CTLCOLORMSGBOX 0x0132
#defina WM_CTLCOLOREDIT 0x0133
#defina WM_CTLCOLORLISTBOX 0x0134
#defina WM_CTLCOLORBTN 0x0135
#defina WM_CTLCOLORDLG 0x0136
#defina WM_CTLCOLORSCROLLBAR 0x0137
#defina WM_CTLCOLORSTATIC 0x0138
#defina MN_GETHMENU 0x01E1

#defina WM_MOUSEFIRST 0x0200
#defina WM_MOUSEMOVE 0x0200
#defina WM_LBUTTONDOWN 0x0201
#defina WM_LBUTTONUP 0x0202
#defina WM_LBUTTONDBLCLK 0x0203
#defina WM_RBUTTONDOWN 0x0204
#defina WM_RBUTTONUP 0x0205
#defina WM_RBUTTONDBLCLK 0x0206
#defina WM_MBUTTONDOWN 0x0207
#defina WM_MBUTTONUP 0x0208
#defina WM_MBUTTONDBLCLK 0x0209
#defina WM_MOUSEWHEEL 0x020A
#defina WM_XBUTTONDOWN 0x020B
#defina WM_XBUTTONUP 0x020C
#defina WM_XBUTTONDBLCLK 0x020D
#defina WM_MOUSELAST 0x020D

#defina WHEEL_DELTA 120
#defina GET_WHEEL_DELTA_WPARAM(wParam) ((curto)HIWORD(wParam))

#defina WHEEL_PAGESCROLL (UINT_MAX)

#defina GET_KEYSTATE_WPARAM(wParam) (LOWORD(wParam))
#defina GET_NCHITTEST_WPARAM(wParam) ((curto)LOWORD(wParam))
#defina GET_XBUTTON_WPARAM(wParam) (HIWORD(wParam))

#defina XBUTTON1 0x0001
#defina XBUTTON2 0x0002

#defina WM_PARENTNOTIFY 0x0210
#defina WM_ENTERMENULOOP 0x0211
#defina WM_EXITMENULOOP 0x0212

#defina WM_NEXTMENU 0x0213
#defina WM_SIZING 0x0214
#defina WM_CAPTURECHANGED 0x0215
#defina WM_MOVING 0x0216

#defina WM_POWERBROADCAST 0x0218

#se_não_definido _WIN32_WCE
#defina PBT_APMQUERYSUSPEND 0x0000
#defina PBT_APMQUERYSTANDBY 0x0001

#defina PBT_APMQUERYSUSPENDFAILED 0x0002
#defina PBT_APMQUERYSTANDBYFAILED 0x0003

#defina PBT_APMSUSPEND 0x0004
#defina PBT_APMSTANDBY 0x0005

#defina PBT_APMRESUMECRITICAL 0x0006
#defina PBT_APMRESUMESUSPEND 0x0007
#defina PBT_APMRESUMESTANDBY 0x0008

#defina PBTF_APMRESUMEFROMFAILURE 0x00000001

#defina PBT_APMBATTERYLOW 0x0009
#defina PBT_APMPOWERSTATUSCHANGE 0x000A

#defina PBT_APMOEMEVENT 0x000B
#defina PBT_APMRESUMEAUTOMATIC 0x0012
#fim_se

#defina WM_DEVICECHANGE 0x0219

#defina WM_MDICREATE 0x0220
#defina WM_MDIDESTROY 0x0221
#defina WM_MDIACTIVATE 0x0222
#defina WM_MDIRESTORE 0x0223
#defina WM_MDINEXT 0x0224
#defina WM_MDIMAXIMIZE 0x0225
#defina WM_MDITILE 0x0226
#defina WM_MDICASCADE 0x0227
#defina WM_MDIICONARRANGE 0x0228
#defina WM_MDIGETACTIVE 0x0229

#defina WM_MDISETMENU 0x0230
#defina WM_ENTERSIZEMOVE 0x0231
#defina WM_EXITSIZEMOVE 0x0232
#defina WM_DROPFILES 0x0233
#defina WM_MDIREFRESHMENU 0x0234

#defina WM_IME_SETCONTEXT 0x0281
#defina WM_IME_NOTIFY 0x0282
#defina WM_IME_CONTROL 0x0283
#defina WM_IME_COMPOSITIONFULL 0x0284
#defina WM_IME_SELECT 0x0285
#defina WM_IME_CHAR 0x0286
#defina WM_IME_REQUEST 0x0288
#defina WM_IME_KEYDOWN 0x0290
#defina WM_IME_KEYUP 0x0291

#defina WM_MOUSEHOVER 0x02A1
#defina WM_MOUSELEAVE 0x02A3
#defina WM_NCMOUSEHOVER 0x02A0
#defina WM_NCMOUSELEAVE 0x02A2
#defina WM_WTSSESSION_CHANGE 0x02B1
#defina WM_TABLET_FIRST 0x02c0
#defina WM_TABLET_LAST 0x02df
#defina WM_CUT 0x0300
#defina WM_COPY 0x0301
#defina WM_PASTE 0x0302
#defina WM_CLEAR 0x0303
#defina WM_UNDO 0x0304
#defina WM_RENDERFORMAT 0x0305
#defina WM_RENDERALLFORMATS 0x0306
#defina WM_DESTROYCLIPBOARD 0x0307
#defina WM_DRAWCLIPBOARD 0x0308
#defina WM_PAINTCLIPBOARD 0x0309
#defina WM_VSCROLLCLIPBOARD 0x030A
#defina WM_SIZECLIPBOARD 0x030B
#defina WM_ASKCBFORMATNAME 0x030C
#defina WM_CHANGECBCHAIN 0x030D
#defina WM_HSCROLLCLIPBOARD 0x030E
#defina WM_QUERYNEWPALETTE 0x030F
#defina WM_PALETTEISCHANGING 0x0310
#defina WM_PALETTECHANGED 0x0311
#defina WM_HOTKEY 0x0312
#defina WM_PRINT 0x0317
#defina WM_PRINTCLIENT 0x0318
#defina WM_APPCOMMAND 0x0319
#defina WM_THEMECHANGED 0x031A
#defina WM_HANDHELDFIRST 0x0358
#defina WM_HANDHELDLAST 0x035F
#defina WM_AFXFIRST 0x0360
#defina WM_AFXLAST 0x037F
#defina WM_PENWINFIRST 0x0380
#defina WM_PENWINLAST 0x038F
#defina WM_APP 0x8000
#defina WM_USER 0x0400

#defina WMSZ_LEFT 1
#defina WMSZ_RIGHT 2
#defina WMSZ_TOP 3
#defina WMSZ_TOPLEFT 4
#defina WMSZ_TOPRIGHT 5
#defina WMSZ_BOTTOM 6
#defina WMSZ_BOTTOMLEFT 7
#defina WMSZ_BOTTOMRIGHT 8

#se_não_definido NONCMESSAGES

#defina HTERROR (-2)
#defina HTTRANSPARENT (-1)
#defina HTNOWHERE 0
#defina HTCLIENT 1
#defina HTCAPTION 2
#defina HTSYSMENU 3
#defina HTGROWBOX 4
#defina HTSIZE HTGROWBOX
#defina HTMENU 5
#defina HTHSCROLL 6
#defina HTVSCROLL 7
#defina HTMINBUTTON 8
#defina HTMAXBUTTON 9
#defina HTLEFT 10
#defina HTRIGHT 11
#defina HTTOP 12
#defina HTTOPLEFT 13
#defina HTTOPRIGHT 14
#defina HTBOTTOM 15
#defina HTBOTTOMLEFT 16
#defina HTBOTTOMRIGHT 17
#defina HTBORDER 18
#defina HTREDUCE HTMINBUTTON
#defina HTZOOM HTMAXBUTTON
#defina HTSIZEFIRST HTLEFT
#defina HTSIZELAST HTBOTTOMRIGHT
#defina HTOBJECT 19
#defina HTCLOSE 20
#defina HTHELP 21

#defina SMTO_NORMAL 0x0000
#defina SMTO_BLOCK 0x0001
#defina SMTO_ABORTIFHUNG 0x0002
#defina SMTO_NOTIMEOUTIFNOTHUNG 0x0008
#fim_se

#defina MA_ACTIVATE 1
#defina MA_ACTIVATEANDEAT 2
#defina MA_NOACTIVATE 3
#defina MA_NOACTIVATEANDEAT 4

#defina ICON_SMALL 0
#defina ICON_BIG 1
#defina ICON_SMALL2 2

#se_definido UNICODE
#defina RegisterWindowMessage RegisterWindowMessageW
#senão
#defina RegisterWindowMessage RegisterWindowMessageA
#fim_se

  WINUSERAPI UINT WINAPI RegisterWindowMessageA(LPCSTR lpString);
  WINUSERAPI UINT WINAPI RegisterWindowMessageW(LPCWSTR lpString);

#defina SIZE_RESTORED 0
#defina SIZE_MINIMIZED 1
#defina SIZE_MAXIMIZED 2
#defina SIZE_MAXSHOW 3
#defina SIZE_MAXHIDE 4

#defina SIZENORMAL SIZE_RESTORED
#defina SIZEICONIC SIZE_MINIMIZED
#defina SIZEFULLSCREEN SIZE_MAXIMIZED
#defina SIZEZOOMSHOW SIZE_MAXSHOW
#defina SIZEZOOMHIDE SIZE_MAXHIDE

  defina_tipo estrutura tagWINDOWPOS {
    HWND hwnd;
    HWND hwndInsertAfter;
    inteiro x;
    inteiro y;
    inteiro cx;
    inteiro cy;
    UINT flags;
  } WINDOWPOS,*LPWINDOWPOS,*PWINDOWPOS;

  defina_tipo estrutura tagNCCALCSIZE_PARAMS {
    RECT rgrc[3];
    PWINDOWPOS lppos;
  } NCCALCSIZE_PARAMS,*LPNCCALCSIZE_PARAMS;

#defina WVR_ALIGNTOP 0x0010
#defina WVR_ALIGNLEFT 0x0020
#defina WVR_ALIGNBOTTOM 0x0040
#defina WVR_ALIGNRIGHT 0x0080
#defina WVR_HREDRAW 0x0100
#defina WVR_VREDRAW 0x0200
#defina WVR_REDRAW (WVR_HREDRAW | WVR_VREDRAW)
#defina WVR_VALIDRECTS 0x0400

#se_não_definido NOKEYSTATES

#defina MK_LBUTTON 0x0001
#defina MK_RBUTTON 0x0002
#defina MK_SHIFT 0x0004
#defina MK_CONTROL 0x0008
#defina MK_MBUTTON 0x0010
#defina MK_XBUTTON1 0x0020
#defina MK_XBUTTON2 0x0040
#fim_se

#se_não_definido NOTRACKMOUSEEVENT
#defina TME_HOVER 0x00000001
#defina TME_LEAVE 0x00000002
#defina TME_NONCLIENT 0x00000010
#defina TME_QUERY 0x40000000
#defina TME_CANCEL 0x80000000

#defina HOVER_DEFAULT 0xFFFFFFFF
#fim_se

  defina_tipo estrutura tagTRACKMOUSEEVENT {
    DWORD cbSize;
    DWORD dwFlags;
    HWND hwndTrack;
    DWORD dwHoverTime;
  } TRACKMOUSEEVENT,*LPTRACKMOUSEEVENT;

  WINUSERAPI WINBOOL WINAPI TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack);
#fim_se

#se_não_definido NOWINSTYLES

#defina WS_OVERLAPPED 0x00000000L
#defina WS_POPUP 0x80000000L
#defina WS_CHILD 0x40000000L
#defina WS_MINIMIZE 0x20000000L
#defina WS_VISIBLE 0x10000000L
#defina WS_DISABLED 0x08000000L
#defina WS_CLIPSIBLINGS 0x04000000L
#defina WS_CLIPCHILDREN 0x02000000L
#defina WS_MAXIMIZE 0x01000000L
#defina WS_CAPTION 0x00C00000L
#defina WS_BORDER 0x00800000L
#defina WS_DLGFRAME 0x00400000L
#defina WS_VSCROLL 0x00200000L
#defina WS_HSCROLL 0x00100000L
#defina WS_SYSMENU 0x00080000L
#defina WS_THICKFRAME 0x00040000L
#defina WS_GROUP 0x00020000L
#defina WS_TABSTOP 0x00010000L
#defina WS_MINIMIZEBOX 0x00020000L
#defina WS_MAXIMIZEBOX 0x00010000L
#defina WS_TILED WS_OVERLAPPED
#defina WS_ICONIC WS_MINIMIZE
#defina WS_SIZEBOX WS_THICKFRAME
#defina WS_TILEDWINDOW WS_OVERLAPPEDWINDOW
#defina WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#defina WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#defina WS_CHILDWINDOW (WS_CHILD)

#defina WS_EX_DLGMODALFRAME 0x00000001L
#defina WS_EX_NOPARENTNOTIFY 0x00000004L
#defina WS_EX_TOPMOST 0x00000008L
#defina WS_EX_ACCEPTFILES 0x00000010L
#defina WS_EX_TRANSPARENT 0x00000020L
#defina WS_EX_MDICHILD 0x00000040L
#defina WS_EX_TOOLWINDOW 0x00000080L
#defina WS_EX_WINDOWEDGE 0x00000100L
#defina WS_EX_CLIENTEDGE 0x00000200L
#defina WS_EX_CONTEXTHELP 0x00000400L
#defina WS_EX_RIGHT 0x00001000L
#defina WS_EX_LEFT 0x00000000L
#defina WS_EX_RTLREADING 0x00002000L
#defina WS_EX_LTRREADING 0x00000000L
#defina WS_EX_LEFTSCROLLBAR 0x00004000L
#defina WS_EX_RIGHTSCROLLBAR 0x00000000L
#defina WS_EX_CONTROLPARENT 0x00010000L
#defina WS_EX_STATICEDGE 0x00020000L
#defina WS_EX_APPWINDOW 0x00040000L
#defina WS_EX_OVERLAPPEDWINDOW (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#defina WS_EX_PALETTEWINDOW (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)
#defina WS_EX_LAYERED 0x00080000
#defina WS_EX_NOINHERITLAYOUT 0x00100000L
#defina WS_EX_LAYOUTRTL 0x00400000L
#defina WS_EX_COMPOSITED 0x02000000L
#defina WS_EX_NOACTIVATE 0x08000000L

#defina CS_VREDRAW 0x0001
#defina CS_HREDRAW 0x0002
#defina CS_DBLCLKS 0x0008
#defina CS_OWNDC 0x0020
#defina CS_CLASSDC 0x0040
#defina CS_PARENTDC 0x0080
#defina CS_NOCLOSE 0x0200
#defina CS_SAVEBITS 0x0800
#defina CS_BYTEALIGNCLIENT 0x1000
#defina CS_BYTEALIGNWINDOW 0x2000
#defina CS_GLOBALCLASS 0x4000
#defina CS_IME 0x00010000
#defina CS_DROPSHADOW 0x00020000
#fim_se

#defina PRF_CHECKVISIBLE 0x00000001L
#defina PRF_NONCLIENT 0x00000002L
#defina PRF_CLIENT 0x00000004L
#defina PRF_ERASEBKGND 0x00000008L
#defina PRF_CHILDREN 0x00000010L
#defina PRF_OWNED 0x00000020L

#defina BDR_RAISEDOUTER 0x0001
#defina BDR_SUNKENOUTER 0x0002
#defina BDR_RAISEDINNER 0x0004
#defina BDR_SUNKENINNER 0x0008

#defina BDR_OUTER (BDR_RAISEDOUTER | BDR_SUNKENOUTER)
#defina BDR_INNER (BDR_RAISEDINNER | BDR_SUNKENINNER)
#defina BDR_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#defina BDR_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)

#defina EDGE_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#defina EDGE_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#defina EDGE_ETCHED (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#defina EDGE_BUMP (BDR_RAISEDOUTER | BDR_SUNKENINNER)

#defina BF_LEFT 0x0001
#defina BF_TOP 0x0002
#defina BF_RIGHT 0x0004
#defina BF_BOTTOM 0x0008

#defina BF_TOPLEFT (BF_TOP | BF_LEFT)
#defina BF_TOPRIGHT (BF_TOP | BF_RIGHT)
#defina BF_BOTTOMLEFT (BF_BOTTOM | BF_LEFT)
#defina BF_BOTTOMRIGHT (BF_BOTTOM | BF_RIGHT)
#defina BF_RECT (BF_LEFT | BF_TOP | BF_RIGHT | BF_BOTTOM)

#defina BF_DIAGONAL 0x0010

#defina BF_DIAGONAL_ENDTOPRIGHT (BF_DIAGONAL | BF_TOP | BF_RIGHT)
#defina BF_DIAGONAL_ENDTOPLEFT (BF_DIAGONAL | BF_TOP | BF_LEFT)
#defina BF_DIAGONAL_ENDBOTTOMLEFT (BF_DIAGONAL | BF_BOTTOM | BF_LEFT)
#defina BF_DIAGONAL_ENDBOTTOMRIGHT (BF_DIAGONAL | BF_BOTTOM | BF_RIGHT)

#defina BF_MIDDLE 0x0800
#defina BF_SOFT 0x1000
#defina BF_ADJUST 0x2000
#defina BF_FLAT 0x4000
#defina BF_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI DrawEdge(HDC hdc,LPRECT qrc,UINT edge,UINT grfFlags);

#defina DFC_CAPTION 1
#defina DFC_MENU 2
#defina DFC_SCROLL 3
#defina DFC_BUTTON 4
#defina DFC_POPUPMENU 5

#defina DFCS_CAPTIONCLOSE 0x0000
#defina DFCS_CAPTIONMIN 0x0001
#defina DFCS_CAPTIONMAX 0x0002
#defina DFCS_CAPTIONRESTORE 0x0003
#defina DFCS_CAPTIONHELP 0x0004

#defina DFCS_MENUARROW 0x0000
#defina DFCS_MENUCHECK 0x0001
#defina DFCS_MENUBULLET 0x0002
#defina DFCS_MENUARROWRIGHT 0x0004
#defina DFCS_SCROLLUP 0x0000
#defina DFCS_SCROLLDOWN 0x0001
#defina DFCS_SCROLLLEFT 0x0002
#defina DFCS_SCROLLRIGHT 0x0003
#defina DFCS_SCROLLCOMBOBOX 0x0005
#defina DFCS_SCROLLSIZEGRIP 0x0008
#defina DFCS_SCROLLSIZEGRIPRIGHT 0x0010

#defina DFCS_BUTTONCHECK 0x0000
#defina DFCS_BUTTONRADIOIMAGE 0x0001
#defina DFCS_BUTTONRADIOMASK 0x0002
#defina DFCS_BUTTONRADIO 0x0004
#defina DFCS_BUTTON3STATE 0x0008
#defina DFCS_BUTTONPUSH 0x0010

#defina DFCS_INACTIVE 0x0100
#defina DFCS_PUSHED 0x0200
#defina DFCS_CHECKED 0x0400

#defina DFCS_TRANSPARENT 0x0800
#defina DFCS_HOT 0x1000

#defina DFCS_ADJUSTRECT 0x2000
#defina DFCS_FLAT 0x4000
#defina DFCS_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI DrawFrameControl(HDC,LPRECT,UINT,UINT);

#defina DC_ACTIVE 0x0001
#defina DC_SMALLCAP 0x0002
#defina DC_ICON 0x0004
#defina DC_TEXT 0x0008
#defina DC_INBUTTON 0x0010
#defina DC_GRADIENT 0x0020
#defina DC_BUTTONS 0x1000

  WINUSERAPI WINBOOL WINAPI DrawCaption(HWND hwnd,HDC hdc,CONST RECT *lprect,UINT flags);

#defina IDANI_OPEN 1
#defina IDANI_CAPTION 3

  WINUSERAPI WINBOOL WINAPI DrawAnimatedRects(HWND hwnd,inteiro idAni,CONST RECT *lprcFrom,CONST RECT *lprcTo);

#se_não_definido NOCLIPBOARD

#defina CF_TEXT 1
#defina CF_BITMAP 2
#defina CF_METAFILEPICT 3
#defina CF_SYLK 4
#defina CF_DIF 5
#defina CF_TIFF 6
#defina CF_OEMTEXT 7
#defina CF_DIB 8
#defina CF_PALETTE 9
#defina CF_PENDATA 10
#defina CF_RIFF 11
#defina CF_WAVE 12
#defina CF_UNICODETEXT 13
#defina CF_ENHMETAFILE 14
#defina CF_HDROP 15
#defina CF_LOCALE 16
#defina CF_DIBV5 17
#defina CF_MAX 18

#defina CF_OWNERDISPLAY 0x0080
#defina CF_DSPTEXT 0x0081
#defina CF_DSPBITMAP 0x0082
#defina CF_DSPMETAFILEPICT 0x0083
#defina CF_DSPENHMETAFILE 0x008E

#defina CF_PRIVATEFIRST 0x0200
#defina CF_PRIVATELAST 0x02FF

#defina CF_GDIOBJFIRST 0x0300
#defina CF_GDIOBJLAST 0x03FF
#fim_se

#defina FVIRTKEY TRUE
#defina FNOINVERT 0x02
#defina FSHIFT 0x04
#defina FCONTROL 0x08
#defina FALT 0x10

  defina_tipo estrutura tagACCEL {
    BYTE fVirt;
    WORD key;
    WORD cmd;
  } ACCEL,*LPACCEL;

  defina_tipo estrutura tagPAINTSTRUCT {
    HDC hdc;
    WINBOOL fErase;
    RECT rcPaint;
    WINBOOL fRestore;
    WINBOOL fIncUpdate;
    BYTE rgbReserved[32];
  } PAINTSTRUCT,*PPAINTSTRUCT,*NPPAINTSTRUCT,*LPPAINTSTRUCT;

  defina_tipo estrutura tagCREATESTRUCTA {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwndParent;
    inteiro cy;
    inteiro cx;
    inteiro y;
    inteiro x;
    LONG style;
    LPCSTR lpszName;
    LPCSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTA,*LPCREATESTRUCTA;

  defina_tipo estrutura tagCREATESTRUCTW {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwndParent;
    inteiro cy;
    inteiro cx;
    inteiro y;
    inteiro x;
    LONG style;
    LPCWSTR lpszName;
    LPCWSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTW,*LPCREATESTRUCTW;

#se_definido UNICODE
  defina_tipo CREATESTRUCTW CREATESTRUCT;
  defina_tipo LPCREATESTRUCTW LPCREATESTRUCT;
#senão
  defina_tipo CREATESTRUCTA CREATESTRUCT;
  defina_tipo LPCREATESTRUCTA LPCREATESTRUCT;
#fim_se

  defina_tipo estrutura tagWINDOWPLACEMENT {
    UINT length;
    UINT flags;
    UINT showCmd;
    POINT ptMinPosition;
    POINT ptMaxPosition;
    RECT rcNormalPosition;
  } WINDOWPLACEMENT;
  defina_tipo WINDOWPLACEMENT *PWINDOWPLACEMENT,*LPWINDOWPLACEMENT;

#defina WPF_SETMINPOSITION 0x0001
#defina WPF_RESTORETOMAXIMIZED 0x0002
#defina WPF_ASYNCWINDOWPLACEMENT 0x0004

  defina_tipo estrutura tagNMHDR {
    HWND hwndFrom;
    UINT_PTR idFrom;
    UINT code;
  } NMHDR;

  defina_tipo NMHDR *LPNMHDR;

  defina_tipo estrutura tagSTYLESTRUCT {
    DWORD styleOld;
    DWORD styleNew;
  } STYLESTRUCT,*LPSTYLESTRUCT;

#defina ODT_MENU 1
#defina ODT_LISTBOX 2
#defina ODT_COMBOBOX 3
#defina ODT_BUTTON 4
#defina ODT_STATIC 5

#defina ODA_DRAWENTIRE 0x0001
#defina ODA_SELECT 0x0002
#defina ODA_FOCUS 0x0004

#defina ODS_SELECTED 0x0001
#defina ODS_GRAYED 0x0002
#defina ODS_DISABLED 0x0004
#defina ODS_CHECKED 0x0008
#defina ODS_FOCUS 0x0010
#defina ODS_DEFAULT 0x0020
#defina ODS_COMBOBOXEDIT 0x1000
#defina ODS_HOTLIGHT 0x0040
#defina ODS_INACTIVE 0x0080
#defina ODS_NOACCEL 0x0100
#defina ODS_NOFOCUSRECT 0x0200

  defina_tipo estrutura tagMEASUREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    UINT itemWidth;
    UINT itemHeight;
    ULONG_PTR itemData;
  } MEASUREITEMSTRUCT,*PMEASUREITEMSTRUCT,*LPMEASUREITEMSTRUCT;

  defina_tipo estrutura tagDRAWITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    UINT itemAction;
    UINT itemState;
    HWND hwndItem;
    HDC hDC;
    RECT rcItem;
    ULONG_PTR itemData;
  } DRAWITEMSTRUCT,*PDRAWITEMSTRUCT,*LPDRAWITEMSTRUCT;

  defina_tipo estrutura tagDELETEITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    HWND hwndItem;
    ULONG_PTR itemData;
  } DELETEITEMSTRUCT,*PDELETEITEMSTRUCT,*LPDELETEITEMSTRUCT;

  defina_tipo estrutura tagCOMPAREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    HWND hwndItem;
    UINT itemID1;
    ULONG_PTR itemData1;
    UINT itemID2;
    ULONG_PTR itemData2;
    DWORD dwLocaleId;
  } COMPAREITEMSTRUCT,*PCOMPAREITEMSTRUCT,*LPCOMPAREITEMSTRUCT;

#se_não_definido NOMSG
#se_definido UNICODE
#defina GetMessage GetMessageW
#defina DispatchMessage DispatchMessageW
#defina PeekMessage PeekMessageW
#senão
#defina GetMessage GetMessageA
#defina DispatchMessage DispatchMessageA
#defina PeekMessage PeekMessageA
#fim_se

  WINUSERAPI WINBOOL WINAPI GetMessageA(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax);
  WINUSERAPI WINBOOL WINAPI GetMessageW(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax);
  WINUSERAPI WINBOOL WINAPI TranslateMessage(CONST MSG *lpMsg);
  WINUSERAPI LRESULT WINAPI DispatchMessageA(CONST MSG *lpMsg);
  WINUSERAPI LRESULT WINAPI DispatchMessageW(CONST MSG *lpMsg);
  WINUSERAPI WINBOOL WINAPI SetMessageQueue(inteiro cMessagesMax);
  WINUSERAPI WINBOOL WINAPI PeekMessageA(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg);
  WINUSERAPI WINBOOL WINAPI PeekMessageW(LPMSG lpMsg,HWND hWnd,UINT wMsgFilterMin,UINT wMsgFilterMax,UINT wRemoveMsg);

#defina PM_NOREMOVE 0x0000
#defina PM_REMOVE 0x0001
#defina PM_NOYIELD 0x0002
#defina PM_QS_INPUT (QS_INPUT << 16)
#defina PM_QS_POSTMESSAGE ((QS_POSTMESSAGE | QS_HOTKEY | QS_TIMER) << 16)
#defina PM_QS_PAINT (QS_PAINT << 16)
#defina PM_QS_SENDMESSAGE (QS_SENDMESSAGE << 16)
#fim_se

  WINUSERAPI WINBOOL WINAPI RegisterHotKey(HWND hWnd,inteiro id,UINT fsModifiers,UINT vk);
  WINUSERAPI WINBOOL WINAPI UnregisterHotKey(HWND hWnd,inteiro id);

#defina MOD_ALT 0x0001
#defina MOD_CONTROL 0x0002
#defina MOD_SHIFT 0x0004
#defina MOD_WIN 0x0008

#defina IDHOT_SNAPWINDOW (-1)
#defina IDHOT_SNAPDESKTOP (-2)

#se_definido WIN_INTERNAL
#se_não_definido LSTRING
#defina NOLSTRING
#fim_se
#se_não_definido LFILEIO
#defina NOLFILEIO
#fim_se
#fim_se

#defina ENDSESSION_LOGOFF 0x80000000

#defina EWX_LOGOFF 0
#defina EWX_SHUTDOWN 0x00000001
#defina EWX_REBOOT 0x00000002
#defina EWX_FORCE 0x00000004
#defina EWX_POWEROFF 0x00000008
#defina EWX_FORCEIFHUNG 0x00000010

#defina ExitWindows(dwReserved,Code) ExitWindowsEx(EWX_LOGOFF,0xFFFFFFFF)

#se_definido UNICODE
#defina SendMessage SendMessageW
#defina SendMessageTimeout SendMessageTimeoutW
#defina SendNotifyMessage SendNotifyMessageW
#defina SendMessageCallback SendMessageCallbackW
#senão
#defina SendMessage SendMessageA
#defina SendMessageTimeout SendMessageTimeoutA
#defina SendNotifyMessage SendNotifyMessageA
#defina SendMessageCallback SendMessageCallbackA
#fim_se

  WINUSERAPI WINBOOL WINAPI ExitWindowsEx(UINT uFlags,DWORD dwReason);
  WINUSERAPI WINBOOL WINAPI SwapMouseButton(WINBOOL fSwap);
  WINUSERAPI DWORD WINAPI GetMessagePos(VOID);
  WINUSERAPI LONG WINAPI GetMessageTime(VOID);
  WINUSERAPI LPARAM WINAPI GetMessageExtraInfo(VOID);
  WINUSERAPI WINBOOL WINAPI IsWow64Message(VOID);
  WINUSERAPI LPARAM WINAPI SetMessageExtraInfo(LPARAM lParam);
  WINUSERAPI LRESULT WINAPI SendMessageA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI SendMessageW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI SendMessageTimeoutA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdwResult);
  WINUSERAPI LRESULT WINAPI SendMessageTimeoutW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdwResult);
  WINUSERAPI WINBOOL WINAPI SendNotifyMessageA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI SendNotifyMessageW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI SendMessageCallbackA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lpResultCallBack,ULONG_PTR dwData);
  WINUSERAPI WINBOOL WINAPI SendMessageCallbackW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lpResultCallBack,ULONG_PTR dwData);

  defina_tipo estrutura {
    UINT cbSize;
    HDESK hdesk;
    HWND hwnd;
    LUID luid;
  } BSMINFO,*PBSMINFO;

#se_definido UNICODE
#defina BroadcastSystemMessageEx BroadcastSystemMessageExW
#defina BroadcastSystemMessage BroadcastSystemMessageW
#senão
#defina BroadcastSystemMessageEx BroadcastSystemMessageExA
#defina BroadcastSystemMessage BroadcastSystemMessageA
#fim_se

  WINUSERAPI longo WINAPI BroadcastSystemMessageExA(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI longo WINAPI BroadcastSystemMessageExW(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI longo WINAPI BroadcastSystemMessageA(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI longo WINAPI BroadcastSystemMessageW(DWORD flags,LPDWORD lpInfo,UINT Msg,WPARAM wParam,LPARAM lParam);

#defina BSM_ALLCOMPONENTS 0x00000000
#defina BSM_VXDS 0x00000001
#defina BSM_NETDRIVER 0x00000002
#defina BSM_INSTALLABLEDRIVERS 0x00000004
#defina BSM_APPLICATIONS 0x00000008
#defina BSM_ALLDESKTOPS 0x00000010

#defina BSF_QUERY 0x00000001
#defina BSF_IGNORECURRENTTASK 0x00000002
#defina BSF_FLUSHDISK 0x00000004
#defina BSF_NOHANG 0x00000008
#defina BSF_POSTMESSAGE 0x00000010
#defina BSF_FORCEIFHUNG 0x00000020
#defina BSF_NOTIMEOUTIFNOTHUNG 0x00000040
#defina BSF_ALLOWSFW 0x00000080
#defina BSF_SENDNOTIFYMESSAGE 0x00000100
#defina BSF_RETURNHDESK 0x00000200
#defina BSF_LUID 0x00000400

#defina BROADCAST_QUERY_DENY 0x424D5144

  defina_tipo PVOID HDEVNOTIFY;
  defina_tipo HDEVNOTIFY *PHDEVNOTIFY;

#defina DEVICE_NOTIFY_WINDOW_HANDLE 0x00000000
#defina DEVICE_NOTIFY_SERVICE_HANDLE 0x00000001
#defina DEVICE_NOTIFY_ALL_INTERFACE_CLASSES 0x00000004

#se_definido UNICODE
#defina RegisterDeviceNotification RegisterDeviceNotificationW
#defina PostMessage PostMessageW
#defina PostThreadMessage PostThreadMessageW
#defina PostAppMessage PostAppMessageW
#defina DefWindowProc DefWindowProcW
#defina CallWindowProc CallWindowProcW
#defina RegisterClass RegisterClassW
#defina UnregisterClass UnregisterClassW
#defina GetClassInfo GetClassInfoW
#defina RegisterClassEx RegisterClassExW
#defina GetClassInfoEx GetClassInfoExW
#senão
#defina RegisterDeviceNotification RegisterDeviceNotificationA
#defina PostMessage PostMessageA
#defina PostThreadMessage PostThreadMessageA
#defina PostAppMessage PostAppMessageA
#defina DefWindowProc DefWindowProcA
#defina CallWindowProc CallWindowProcA
#defina RegisterClass RegisterClassA
#defina UnregisterClass UnregisterClassA
#defina GetClassInfo GetClassInfoA
#defina RegisterClassEx RegisterClassExA
#defina GetClassInfoEx GetClassInfoExA
#fim_se

  WINUSERAPI HDEVNOTIFY WINAPI RegisterDeviceNotificationA(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI HDEVNOTIFY WINAPI RegisterDeviceNotificationW(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI WINBOOL WINAPI UnregisterDeviceNotification(HDEVNOTIFY Handle);
  WINUSERAPI WINBOOL WINAPI PostMessageA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI PostMessageW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI PostThreadMessageA(DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI PostThreadMessageW(DWORD idThread,UINT Msg,WPARAM wParam,LPARAM lParam);
#defina PostAppMessageA(idThread,wMsg,wParam,lParam) PostThreadMessageA((DWORD)idThread,wMsg,wParam,lParam)
#defina PostAppMessageW(idThread,wMsg,wParam,lParam) PostThreadMessageW((DWORD)idThread,wMsg,wParam,lParam)

#defina HWND_BROADCAST ((HWND)0xffff)
#defina HWND_MESSAGE ((HWND)-3)

  WINUSERAPI WINBOOL WINAPI AttachThreadInput(DWORD idAttach,DWORD idAttachTo,WINBOOL fAttach);
  WINUSERAPI WINBOOL WINAPI ReplyMessage(LRESULT lResult);
  WINUSERAPI WINBOOL WINAPI WaitMessage(VOID);
  WINUSERAPI DWORD WINAPI WaitForInputIdle(HANDLE hProcess,DWORD dwMilliseconds);
  WINUSERAPI LRESULT WINAPI DefWindowProcA(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefWindowProcW(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI VOID WINAPI PostQuitMessage(inteiro nExitCode);
  WINUSERAPI LRESULT WINAPI CallWindowProcA(WNDPROC lpPrevWndFunc,HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI CallWindowProcW(WNDPROC lpPrevWndFunc,HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI InSendMessage(VOID);
  WINUSERAPI DWORD WINAPI InSendMessageEx(LPVOID lpReserved);

#defina ISMEX_NOSEND 0x00000000
#defina ISMEX_SEND 0x00000001
#defina ISMEX_NOTIFY 0x00000002
#defina ISMEX_CALLBACK 0x00000004
#defina ISMEX_REPLIED 0x00000008

  WINUSERAPI UINT WINAPI GetDoubleClickTime(VOID);
  WINUSERAPI WINBOOL WINAPI SetDoubleClickTime(UINT);
  WINUSERAPI ATOM WINAPI RegisterClassA(CONST WNDCLASSA *lpWndClass);
  WINUSERAPI ATOM WINAPI RegisterClassW(CONST WNDCLASSW *lpWndClass);
  WINUSERAPI WINBOOL WINAPI UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI UnregisterClassW(LPCWSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI GetClassInfoA(HINSTANCE hInstance,LPCSTR lpClassName,LPWNDCLASSA lpWndClass);
  WINUSERAPI WINBOOL WINAPI GetClassInfoW(HINSTANCE hInstance,LPCWSTR lpClassName,LPWNDCLASSW lpWndClass);
  WINUSERAPI ATOM WINAPI RegisterClassExA(CONST WNDCLASSEXA *);
  WINUSERAPI ATOM WINAPI RegisterClassExW(CONST WNDCLASSEXW *);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExA(HINSTANCE hInstance,LPCSTR lpszClass,LPWNDCLASSEXA lpwcx);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExW(HINSTANCE hInstance,LPCWSTR lpszClass,LPWNDCLASSEXW lpwcx);

#defina CW_USEDEFAULT ((inteiro)0x80000000)

#defina HWND_DESKTOP ((HWND)0)

  defina_tipo BOOLEAN (WINAPI *PREGISTERCLASSNAMEW)(LPCWSTR);

#se_definido UNICODE
#defina CreateWindowEx CreateWindowExW
#defina CreateWindow CreateWindowW
#senão
#defina CreateWindowEx CreateWindowExA
#defina CreateWindow CreateWindowA
#fim_se

  WINUSERAPI HWND WINAPI CreateWindowExA(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,inteiro X,inteiro Y,inteiro nWidth,inteiro nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
  WINUSERAPI HWND WINAPI CreateWindowExW(DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lpWindowName,DWORD dwStyle,inteiro X,inteiro Y,inteiro nWidth,inteiro nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
#defina CreateWindowA(lpClassName,lpWindowName,dwStyle,x,y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam) CreateWindowExA(0L,lpClassName,lpWindowName,dwStyle,x,y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam)
#defina CreateWindowW(lpClassName,lpWindowName,dwStyle,x,y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam) CreateWindowExW(0L,lpClassName,lpWindowName,dwStyle,x,y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam)
  WINUSERAPI WINBOOL WINAPI IsWindow(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsMenu(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI IsChild(HWND hWndParent,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI DestroyWindow(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ShowWindow(HWND hWnd,inteiro nCmdShow);
  WINUSERAPI WINBOOL WINAPI AnimateWindow(HWND hWnd,DWORD dwTime,DWORD dwFlags);

#se definido(_WINGDI_) && !definido(NOGDI)
  WINUSERAPI WINBOOL WINAPI UpdateLayeredWindow(HWND hWnd,HDC hdcDst,POINT *pptDst,SIZE *psize,HDC hdcSrc,POINT *pptSrc,COLORREF crKey,BLENDFUNCTION *pblend,DWORD dwFlags);

  defina_tipo estrutura tagUPDATELAYEREDWINDOWINFO {
    DWORD cbSize;
    HDC hdcDst;
    POINT CONST *pptDst;
    SIZE CONST *psize;
    HDC hdcSrc;
    POINT CONST *pptSrc;
    COLORREF crKey;
    BLENDFUNCTION CONST *pblend;
    DWORD dwFlags;
    RECT CONST *prcDirty;
  } UPDATELAYEREDWINDOWINFO,*PUPDATELAYEREDWINDOWINFO;

  WINUSERAPI WINBOOL WINAPI UpdateLayeredWindowIndirect(HWND hWnd,UPDATELAYEREDWINDOWINFO CONST *pULWInfo);
  WINUSERAPI WINBOOL WINAPI GetLayeredWindowAttributes(HWND hwnd,COLORREF *pcrKey,BYTE *pbAlpha,DWORD *pdwFlags);

#defina PW_CLIENTONLY 0x00000001

  WINUSERAPI WINBOOL WINAPI PrintWindow(HWND hwnd,HDC hdcBlt,UINT nFlags);
  WINUSERAPI WINBOOL WINAPI SetLayeredWindowAttributes(HWND hwnd,COLORREF crKey,BYTE bAlpha,DWORD dwFlags);

#defina LWA_COLORKEY 0x00000001
#defina LWA_ALPHA 0x00000002

#defina ULW_COLORKEY 0x00000001
#defina ULW_ALPHA 0x00000002
#defina ULW_OPAQUE 0x00000004

#defina ULW_EX_NORESIZE 0x00000008

  WINUSERAPI WINBOOL WINAPI ShowWindowAsync(HWND hWnd,inteiro nCmdShow);
  WINUSERAPI WINBOOL WINAPI FlashWindow(HWND hWnd,WINBOOL bInvert);

  defina_tipo estrutura {
    UINT cbSize;
    HWND hwnd;
    DWORD dwFlags;
    UINT uCount;
    DWORD dwTimeout;
  } FLASHWINFO,*PFLASHWINFO;

  WINUSERAPI WINBOOL WINAPI FlashWindowEx(PFLASHWINFO pfwi);

#defina FLASHW_STOP 0
#defina FLASHW_CAPTION 0x00000001
#defina FLASHW_TRAY 0x00000002
#defina FLASHW_ALL (FLASHW_CAPTION | FLASHW_TRAY)
#defina FLASHW_TIMER 0x00000004
#defina FLASHW_TIMERNOFG 0x0000000C

  WINUSERAPI WINBOOL WINAPI ShowOwnedPopups(HWND hWnd,WINBOOL fShow);
  WINUSERAPI WINBOOL WINAPI OpenIcon(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI CloseWindow(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI MoveWindow(HWND hWnd,inteiro X,inteiro Y,inteiro nWidth,inteiro nHeight,WINBOOL bRepaint);
  WINUSERAPI WINBOOL WINAPI SetWindowPos(HWND hWnd,HWND hWndInsertAfter,inteiro X,inteiro Y,inteiro cx,inteiro cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI GetWindowPlacement(HWND hWnd,WINDOWPLACEMENT *lpwndpl);
  WINUSERAPI WINBOOL WINAPI SetWindowPlacement(HWND hWnd,CONST WINDOWPLACEMENT *lpwndpl);

#se_não_definido NODEFERWINDOWPOS
  WINUSERAPI HDWP WINAPI BeginDeferWindowPos(inteiro nNumWindows);
  WINUSERAPI HDWP WINAPI DeferWindowPos(HDWP hWinPosInfo,HWND hWnd,HWND hWndInsertAfter,inteiro x,inteiro y,inteiro cx,inteiro cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI EndDeferWindowPos(HDWP hWinPosInfo);
#fim_se

  WINUSERAPI WINBOOL WINAPI IsWindowVisible(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsIconic(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI AnyPopup(VOID);
  WINUSERAPI WINBOOL WINAPI BringWindowToTop(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsZoomed(HWND hWnd);

#defina SWP_NOSIZE 0x0001
#defina SWP_NOMOVE 0x0002
#defina SWP_NOZORDER 0x0004
#defina SWP_NOREDRAW 0x0008
#defina SWP_NOACTIVATE 0x0010
#defina SWP_FRAMECHANGED 0x0020
#defina SWP_SHOWWINDOW 0x0040
#defina SWP_HIDEWINDOW 0x0080
#defina SWP_NOCOPYBITS 0x0100
#defina SWP_NOOWNERZORDER 0x0200
#defina SWP_NOSENDCHANGING 0x0400

#defina SWP_DRAWFRAME SWP_FRAMECHANGED
#defina SWP_NOREPOSITION SWP_NOOWNERZORDER
#defina SWP_DEFERERASE 0x2000
#defina SWP_ASYNCWINDOWPOS 0x4000

#defina HWND_TOP ((HWND)0)
#defina HWND_BOTTOM ((HWND)1)
#defina HWND_TOPMOST ((HWND)-1)
#defina HWND_NOTOPMOST ((HWND)-2)

#se_não_definido NOCTLMGR

#inclua <pshpack2.h>

  defina_tipo estrutura {
    DWORD style;
    DWORD dwExtendedStyle;
    WORD cdit;
    curto x;
    curto y;
    curto cx;
    curto cy;
  } DLGTEMPLATE;

  defina_tipo DLGTEMPLATE *LPDLGTEMPLATEA;
  defina_tipo DLGTEMPLATE *LPDLGTEMPLATEW;

#se_definido UNICODE
  defina_tipo LPDLGTEMPLATEW LPDLGTEMPLATE;
#senão
  defina_tipo LPDLGTEMPLATEA LPDLGTEMPLATE;
#fim_se

  defina_tipo CONST DLGTEMPLATE *LPCDLGTEMPLATEA;
  defina_tipo CONST DLGTEMPLATE *LPCDLGTEMPLATEW;

#se_definido UNICODE
  defina_tipo LPCDLGTEMPLATEW LPCDLGTEMPLATE;
#senão
  defina_tipo LPCDLGTEMPLATEA LPCDLGTEMPLATE;
#fim_se

  defina_tipo estrutura {
    DWORD style;
    DWORD dwExtendedStyle;
    curto x;
    curto y;
    curto cx;
    curto cy;
    WORD id;
  } DLGITEMTEMPLATE;

  defina_tipo DLGITEMTEMPLATE *PDLGITEMTEMPLATEA;
  defina_tipo DLGITEMTEMPLATE *PDLGITEMTEMPLATEW;

#se_definido UNICODE
  defina_tipo PDLGITEMTEMPLATEW PDLGITEMTEMPLATE;
#senão
  defina_tipo PDLGITEMTEMPLATEA PDLGITEMTEMPLATE;
#fim_se

  defina_tipo DLGITEMTEMPLATE *LPDLGITEMTEMPLATEA;
  defina_tipo DLGITEMTEMPLATE *LPDLGITEMTEMPLATEW;

#se_definido UNICODE
  defina_tipo LPDLGITEMTEMPLATEW LPDLGITEMTEMPLATE;
#senão
  defina_tipo LPDLGITEMTEMPLATEA LPDLGITEMTEMPLATE;
#fim_se

#inclua <poppack.h>

#se_definido UNICODE
#defina CreateDialogParam CreateDialogParamW
#defina CreateDialogIndirectParam CreateDialogIndirectParamW
#defina CreateDialog CreateDialogW
#defina CreateDialogIndirect CreateDialogIndirectW
#defina DialogBoxParam DialogBoxParamW
#defina DialogBoxIndirectParam DialogBoxIndirectParamW
#defina DialogBox DialogBoxW
#defina DialogBoxIndirect DialogBoxIndirectW
#defina SetDlgItemText SetDlgItemTextW
#defina GetDlgItemText GetDlgItemTextW
#defina SendDlgItemMessage SendDlgItemMessageW
#defina DefDlgProc DefDlgProcW
#senão
#defina CreateDialogParam CreateDialogParamA
#defina CreateDialogIndirectParam CreateDialogIndirectParamA
#defina CreateDialog CreateDialogA
#defina CreateDialogIndirect CreateDialogIndirectA
#defina DialogBoxParam DialogBoxParamA
#defina DialogBoxIndirectParam DialogBoxIndirectParamA
#defina DialogBox DialogBoxA
#defina DialogBoxIndirect DialogBoxIndirectA
#defina SetDlgItemText SetDlgItemTextA
#defina GetDlgItemText GetDlgItemTextA
#defina SendDlgItemMessage SendDlgItemMessageA
#defina DefDlgProc DefDlgProcA
#fim_se

  WINUSERAPI HWND WINAPI CreateDialogParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI CreateDialogParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI CreateDialogIndirectParamA(HINSTANCE hInstance,LPCDLGTEMPLATEA lpTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI CreateDialogIndirectParamW(HINSTANCE hInstance,LPCDLGTEMPLATEW lpTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#defina CreateDialogA(hInstance,lpName,hWndParent,lpDialogFunc) CreateDialogParamA(hInstance,lpName,hWndParent,lpDialogFunc,0L)
#defina CreateDialogW(hInstance,lpName,hWndParent,lpDialogFunc) CreateDialogParamW(hInstance,lpName,hWndParent,lpDialogFunc,0L)
#defina CreateDialogIndirectA(hInstance,lpTemplate,hWndParent,lpDialogFunc) CreateDialogIndirectParamA(hInstance,lpTemplate,hWndParent,lpDialogFunc,0L)
#defina CreateDialogIndirectW(hInstance,lpTemplate,hWndParent,lpDialogFunc) CreateDialogIndirectParamW(hInstance,lpTemplate,hWndParent,lpDialogFunc,0L)
  WINUSERAPI INT_PTR WINAPI DialogBoxParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI DialogBoxParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI DialogBoxIndirectParamA(HINSTANCE hInstance,LPCDLGTEMPLATEA hDialogTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI DialogBoxIndirectParamW(HINSTANCE hInstance,LPCDLGTEMPLATEW hDialogTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#defina DialogBoxA(hInstance,lpTemplate,hWndParent,lpDialogFunc) DialogBoxParamA(hInstance,lpTemplate,hWndParent,lpDialogFunc,0L)
#defina DialogBoxW(hInstance,lpTemplate,hWndParent,lpDialogFunc) DialogBoxParamW(hInstance,lpTemplate,hWndParent,lpDialogFunc,0L)
#defina DialogBoxIndirectA(hInstance,lpTemplate,hWndParent,lpDialogFunc) DialogBoxIndirectParamA(hInstance,lpTemplate,hWndParent,lpDialogFunc,0L)
#defina DialogBoxIndirectW(hInstance,lpTemplate,hWndParent,lpDialogFunc) DialogBoxIndirectParamW(hInstance,lpTemplate,hWndParent,lpDialogFunc,0L)
  WINUSERAPI WINBOOL WINAPI EndDialog(HWND hDlg,INT_PTR nResult);
  WINUSERAPI HWND WINAPI GetDlgItem(HWND hDlg,inteiro nIDDlgItem);
  WINUSERAPI WINBOOL WINAPI SetDlgItemInt(HWND hDlg,inteiro nIDDlgItem,UINT uValue,WINBOOL bSigned);
  WINUSERAPI UINT WINAPI GetDlgItemInt(HWND hDlg,inteiro nIDDlgItem,WINBOOL *lpTranslated,WINBOOL bSigned);
  WINUSERAPI WINBOOL WINAPI SetDlgItemTextA(HWND hDlg,inteiro nIDDlgItem,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI SetDlgItemTextW(HWND hDlg,inteiro nIDDlgItem,LPCWSTR lpString);
  WINUSERAPI UINT WINAPI GetDlgItemTextA(HWND hDlg,inteiro nIDDlgItem,LPSTR lpString,inteiro cchMax);
  WINUSERAPI UINT WINAPI GetDlgItemTextW(HWND hDlg,inteiro nIDDlgItem,LPWSTR lpString,inteiro cchMax);
  WINUSERAPI WINBOOL WINAPI CheckDlgButton(HWND hDlg,inteiro nIDButton,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI CheckRadioButton(HWND hDlg,inteiro nIDFirstButton,inteiro nIDLastButton,inteiro nIDCheckButton);
  WINUSERAPI UINT WINAPI IsDlgButtonChecked(HWND hDlg,inteiro nIDButton);
  WINUSERAPI LRESULT WINAPI SendDlgItemMessageA(HWND hDlg,inteiro nIDDlgItem,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI SendDlgItemMessageW(HWND hDlg,inteiro nIDDlgItem,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI HWND WINAPI GetNextDlgGroupItem(HWND hDlg,HWND hCtl,WINBOOL bPrevious);
  WINUSERAPI HWND WINAPI GetNextDlgTabItem(HWND hDlg,HWND hCtl,WINBOOL bPrevious);
  WINUSERAPI inteiro WINAPI GetDlgCtrlID(HWND hWnd);
  WINUSERAPI longo WINAPI GetDialogBaseUnits(VOID);
  WINUSERAPI LRESULT WINAPI DefDlgProcA(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefDlgProcW(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam);

#defina DLGWINDOWEXTRA 30
#fim_se

#se_não_definido NOMSG

#se_definido UNICODE
#defina CallMsgFilter CallMsgFilterW
#senão
#defina CallMsgFilter CallMsgFilterA
#fim_se

  WINUSERAPI WINBOOL WINAPI CallMsgFilterA(LPMSG lpMsg,inteiro nCode);
  WINUSERAPI WINBOOL WINAPI CallMsgFilterW(LPMSG lpMsg,inteiro nCode);
#fim_se

#se_não_definido NOCLIPBOARD

#se_definido UNICODE
#defina RegisterClipboardFormat RegisterClipboardFormatW
#defina GetClipboardFormatName GetClipboardFormatNameW
#senão
#defina RegisterClipboardFormat RegisterClipboardFormatA
#defina GetClipboardFormatName GetClipboardFormatNameA
#fim_se

  WINUSERAPI WINBOOL WINAPI OpenClipboard(HWND hWndNewOwner);
  WINUSERAPI WINBOOL WINAPI CloseClipboard(VOID);
  WINUSERAPI DWORD WINAPI GetClipboardSequenceNumber(VOID);
  WINUSERAPI HWND WINAPI GetClipboardOwner(VOID);
  WINUSERAPI HWND WINAPI SetClipboardViewer(HWND hWndNewViewer);
  WINUSERAPI HWND WINAPI GetClipboardViewer(VOID);
  WINUSERAPI WINBOOL WINAPI ChangeClipboardChain(HWND hWndRemove,HWND hWndNewNext);
  WINUSERAPI HANDLE WINAPI SetClipboardData(UINT uFormat,HANDLE hMem);
  WINUSERAPI HANDLE WINAPI GetClipboardData(UINT uFormat);
  WINUSERAPI UINT WINAPI RegisterClipboardFormatA(LPCSTR lpszFormat);
  WINUSERAPI UINT WINAPI RegisterClipboardFormatW(LPCWSTR lpszFormat);
  WINUSERAPI inteiro WINAPI CountClipboardFormats(VOID);
  WINUSERAPI UINT WINAPI EnumClipboardFormats(UINT format);
  WINUSERAPI inteiro WINAPI GetClipboardFormatNameA(UINT format,LPSTR lpszFormatName,inteiro cchMaxCount);
  WINUSERAPI inteiro WINAPI GetClipboardFormatNameW(UINT format,LPWSTR lpszFormatName,inteiro cchMaxCount);
  WINUSERAPI WINBOOL WINAPI EmptyClipboard(VOID);
  WINUSERAPI WINBOOL WINAPI IsClipboardFormatAvailable(UINT format);
  WINUSERAPI inteiro WINAPI GetPriorityClipboardFormat(UINT *paFormatPriorityList,inteiro cFormats);
  WINUSERAPI HWND WINAPI GetOpenClipboardWindow(VOID);
#fim_se

#se_definido UNICODE
#defina CharToOem CharToOemW
#defina OemToChar OemToCharW
#defina CharToOemBuff CharToOemBuffW
#defina OemToCharBuff OemToCharBuffW
#defina CharUpper CharUpperW
#defina CharUpperBuff CharUpperBuffW
#defina CharLower CharLowerW
#defina CharLowerBuff CharLowerBuffW
#defina CharNext CharNextW
#defina CharPrev CharPrevW
#senão
#defina CharToOem CharToOemA
#defina OemToChar OemToCharA
#defina CharToOemBuff CharToOemBuffA
#defina OemToCharBuff OemToCharBuffA
#defina CharUpper CharUpperA
#defina CharUpperBuff CharUpperBuffA
#defina CharLower CharLowerA
#defina CharLowerBuff CharLowerBuffA
#defina CharNext CharNextA
#defina CharPrev CharPrevA
#fim_se

  WINUSERAPI WINBOOL WINAPI CharToOemA(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI CharToOemW(LPCWSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI OemToCharA(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI OemToCharW(LPCSTR lpszSrc,LPWSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI CharToOemBuffA(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength);
  WINUSERAPI WINBOOL WINAPI CharToOemBuffW(LPCWSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength);
  WINUSERAPI WINBOOL WINAPI OemToCharBuffA(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cchDstLength);
  WINUSERAPI WINBOOL WINAPI OemToCharBuffW(LPCSTR lpszSrc,LPWSTR lpszDst,DWORD cchDstLength);
  WINUSERAPI LPSTR WINAPI CharUpperA(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI CharUpperW(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI CharUpperBuffA(LPSTR lpsz,DWORD cchLength);
  WINUSERAPI DWORD WINAPI CharUpperBuffW(LPWSTR lpsz,DWORD cchLength);
  WINUSERAPI LPSTR WINAPI CharLowerA(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI CharLowerW(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI CharLowerBuffA(LPSTR lpsz,DWORD cchLength);
  WINUSERAPI DWORD WINAPI CharLowerBuffW(LPWSTR lpsz,DWORD cchLength);
  WINUSERAPI LPSTR WINAPI CharNextA(LPCSTR lpsz);
  WINUSERAPI LPWSTR WINAPI CharNextW(LPCWSTR lpsz);
  WINUSERAPI LPSTR WINAPI CharPrevA(LPCSTR lpszStart,LPCSTR lpszCurrent);
  WINUSERAPI LPWSTR WINAPI CharPrevW(LPCWSTR lpszStart,LPCWSTR lpszCurrent);
  WINUSERAPI LPSTR WINAPI CharNextExA(WORD CodePage,LPCSTR lpCurrentChar,DWORD dwFlags);
  WINUSERAPI LPSTR WINAPI CharPrevExA(WORD CodePage,LPCSTR lpStart,LPCSTR lpCurrentChar,DWORD dwFlags);

#defina AnsiToOem CharToOemA
#defina OemToAnsi OemToCharA
#defina AnsiToOemBuff CharToOemBuffA
#defina OemToAnsiBuff OemToCharBuffA
#defina AnsiUpper CharUpperA
#defina AnsiUpperBuff CharUpperBuffA
#defina AnsiLower CharLowerA
#defina AnsiLowerBuff CharLowerBuffA
#defina AnsiNext CharNextA
#defina AnsiPrev CharPrevA

#se_não_definido NOLANGUAGE

#se_definido UNICODE
#defina IsCharAlpha IsCharAlphaW
#defina IsCharAlphaNumeric IsCharAlphaNumericW
#defina IsCharUpper IsCharUpperW
#defina IsCharLower IsCharLowerW
#senão
#defina IsCharAlpha IsCharAlphaA
#defina IsCharAlphaNumeric IsCharAlphaNumericA
#defina IsCharUpper IsCharUpperA
#defina IsCharLower IsCharLowerA
#fim_se

  WINUSERAPI WINBOOL WINAPI IsCharAlphaA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharUpperA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharUpperW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharLowerA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharLowerW(WCHAR ch);
#fim_se

#se_definido UNICODE
#defina GetKeyNameText GetKeyNameTextW
#defina VkKeyScan VkKeyScanW
#defina VkKeyScanEx VkKeyScanExW
#senão
#defina GetKeyNameText GetKeyNameTextA
#defina VkKeyScan VkKeyScanA
#defina VkKeyScanEx VkKeyScanExA
#fim_se

  WINUSERAPI HWND WINAPI SetFocus(HWND hWnd);
  WINUSERAPI HWND WINAPI GetActiveWindow(VOID);
  WINUSERAPI HWND WINAPI GetFocus(VOID);
  WINUSERAPI UINT WINAPI GetKBCodePage(VOID);
  WINUSERAPI SHORT WINAPI GetKeyState(inteiro nVirtKey);
  WINUSERAPI SHORT WINAPI GetAsyncKeyState(inteiro vKey);
  WINUSERAPI WINBOOL WINAPI GetKeyboardState(PBYTE lpKeyState);
  WINUSERAPI WINBOOL WINAPI SetKeyboardState(LPBYTE lpKeyState);
  WINUSERAPI inteiro WINAPI GetKeyNameTextA(LONG lParam,LPSTR lpString,inteiro cchSize);
  WINUSERAPI inteiro WINAPI GetKeyNameTextW(LONG lParam,LPWSTR lpString,inteiro cchSize);
  WINUSERAPI inteiro WINAPI GetKeyboardType(inteiro nTypeFlag);
  WINUSERAPI inteiro WINAPI ToAscii(UINT uVirtKey,UINT uScanCode,CONST BYTE *lpKeyState,LPWORD lpChar,UINT uFlags);
  WINUSERAPI inteiro WINAPI ToAsciiEx(UINT uVirtKey,UINT uScanCode,CONST BYTE *lpKeyState,LPWORD lpChar,UINT uFlags,HKL dwhkl);
  WINUSERAPI inteiro WINAPI ToUnicode(UINT wVirtKey,UINT wScanCode,CONST BYTE *lpKeyState,LPWSTR pwszBuff,inteiro cchBuff,UINT wFlags);
  WINUSERAPI DWORD WINAPI OemKeyScan(WORD wOemChar);
  WINUSERAPI SHORT WINAPI VkKeyScanA(CHAR ch);
  WINUSERAPI SHORT WINAPI VkKeyScanW(WCHAR ch);
  WINUSERAPI SHORT WINAPI VkKeyScanExA(CHAR ch,HKL dwhkl);
  WINUSERAPI SHORT WINAPI VkKeyScanExW(WCHAR ch,HKL dwhkl);

#defina KEYEVENTF_EXTENDEDKEY 0x0001
#defina KEYEVENTF_KEYUP 0x0002
#defina KEYEVENTF_UNICODE 0x0004
#defina KEYEVENTF_SCANCODE 0x0008

  WINUSERAPI VOID WINAPI keybd_event(BYTE bVk,BYTE bScan,DWORD dwFlags,ULONG_PTR dwExtraInfo);

#defina MOUSEEVENTF_MOVE 0x0001
#defina MOUSEEVENTF_LEFTDOWN 0x0002
#defina MOUSEEVENTF_LEFTUP 0x0004
#defina MOUSEEVENTF_RIGHTDOWN 0x0008
#defina MOUSEEVENTF_RIGHTUP 0x0010
#defina MOUSEEVENTF_MIDDLEDOWN 0x0020
#defina MOUSEEVENTF_MIDDLEUP 0x0040
#defina MOUSEEVENTF_XDOWN 0x0080
#defina MOUSEEVENTF_XUP 0x0100
#defina MOUSEEVENTF_WHEEL 0x0800
#defina MOUSEEVENTF_VIRTUALDESK 0x4000
#defina MOUSEEVENTF_ABSOLUTE 0x8000

  WINUSERAPI VOID WINAPI mouse_event(DWORD dwFlags,DWORD dx,DWORD dy,DWORD dwData,ULONG_PTR dwExtraInfo);

  defina_tipo estrutura tagMOUSEINPUT {
    LONG dx;
    LONG dy;
    DWORD mouseData;
    DWORD dwFlags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
  } MOUSEINPUT,*PMOUSEINPUT,*LPMOUSEINPUT;

  defina_tipo estrutura tagKEYBDINPUT {
    WORD wVk;
    WORD wScan;
    DWORD dwFlags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
  } KEYBDINPUT,*PKEYBDINPUT,*LPKEYBDINPUT;

  defina_tipo estrutura tagHARDWAREINPUT {
    DWORD uMsg;
    WORD wParamL;
    WORD wParamH;
  } HARDWAREINPUT,*PHARDWAREINPUT,*LPHARDWAREINPUT;

#defina INPUT_MOUSE 0
#defina INPUT_KEYBOARD 1
#defina INPUT_HARDWARE 2

  defina_tipo estrutura tagINPUT {
    DWORD type;
    união {
      MOUSEINPUT mi;
      KEYBDINPUT ki;
      HARDWAREINPUT hi;
    };
  } INPUT,*PINPUT,*LPINPUT;

  WINUSERAPI UINT WINAPI SendInput(UINT cInputs,LPINPUT pInputs,inteiro cbSize);

  defina_tipo estrutura tagLASTINPUTINFO {
    UINT cbSize;
    DWORD dwTime;
  } LASTINPUTINFO,*PLASTINPUTINFO;

#se_definido UNICODE
#defina MapVirtualKey MapVirtualKeyW
#defina MapVirtualKeyEx MapVirtualKeyExW
#senão
#defina MapVirtualKey MapVirtualKeyA
#defina MapVirtualKeyEx MapVirtualKeyExA
#fim_se

  WINUSERAPI WINBOOL WINAPI GetLastInputInfo(PLASTINPUTINFO plii);
  WINUSERAPI UINT WINAPI MapVirtualKeyA(UINT uCode,UINT uMapType);
  WINUSERAPI UINT WINAPI MapVirtualKeyW(UINT uCode,UINT uMapType);
  WINUSERAPI UINT WINAPI MapVirtualKeyExA(UINT uCode,UINT uMapType,HKL dwhkl);
  WINUSERAPI UINT WINAPI MapVirtualKeyExW(UINT uCode,UINT uMapType,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI GetInputState(VOID);
  WINUSERAPI DWORD WINAPI GetQueueStatus(UINT flags);
  WINUSERAPI HWND WINAPI GetCapture(VOID);
  WINUSERAPI HWND WINAPI SetCapture(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ReleaseCapture(VOID);
  WINUSERAPI DWORD WINAPI MsgWaitForMultipleObjects(DWORD nCount,CONST HANDLE *pHandles,WINBOOL fWaitAll,DWORD dwMilliseconds,DWORD dwWakeMask);
  WINUSERAPI DWORD WINAPI MsgWaitForMultipleObjectsEx(DWORD nCount,CONST HANDLE *pHandles,DWORD dwMilliseconds,DWORD dwWakeMask,DWORD dwFlags);

#defina MWMO_WAITALL 0x0001
#defina MWMO_ALERTABLE 0x0002
#defina MWMO_INPUTAVAILABLE 0x0004

#defina QS_KEY 0x0001
#defina QS_MOUSEMOVE 0x0002
#defina QS_MOUSEBUTTON 0x0004
#defina QS_POSTMESSAGE 0x0008
#defina QS_TIMER 0x0010
#defina QS_PAINT 0x0020
#defina QS_SENDMESSAGE 0x0040
#defina QS_HOTKEY 0x0080
#defina QS_ALLPOSTMESSAGE 0x0100
#defina QS_RAWINPUT 0x0400
#defina QS_MOUSE (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#defina QS_INPUT (QS_MOUSE | QS_KEY | QS_RAWINPUT)
#defina QS_ALLEVENTS (QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)
#defina QS_ALLINPUT (QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE)

#defina USER_TIMER_MAXIMUM 0x7FFFFFFF
#defina USER_TIMER_MINIMUM 0x0000000A

#se_definido UNICODE
#defina LoadAccelerators LoadAcceleratorsW
#defina CreateAcceleratorTable CreateAcceleratorTableW
#defina CopyAcceleratorTable CopyAcceleratorTableW
#senão
#defina LoadAccelerators LoadAcceleratorsA
#defina CreateAcceleratorTable CreateAcceleratorTableA
#defina CopyAcceleratorTable CopyAcceleratorTableA
#fim_se

  WINUSERAPI UINT_PTR WINAPI SetTimer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc);
  WINUSERAPI WINBOOL WINAPI KillTimer(HWND hWnd,UINT_PTR uIDEvent);
  WINUSERAPI WINBOOL WINAPI IsWindowUnicode(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI EnableWindow(HWND hWnd,WINBOOL bEnable);
  WINUSERAPI WINBOOL WINAPI IsWindowEnabled(HWND hWnd);
  WINUSERAPI HACCEL WINAPI LoadAcceleratorsA(HINSTANCE hInstance,LPCSTR lpTableName);
  WINUSERAPI HACCEL WINAPI LoadAcceleratorsW(HINSTANCE hInstance,LPCWSTR lpTableName);
  WINUSERAPI HACCEL WINAPI CreateAcceleratorTableA(LPACCEL paccel,inteiro cAccel);
  WINUSERAPI HACCEL WINAPI CreateAcceleratorTableW(LPACCEL paccel,inteiro cAccel);
  WINUSERAPI WINBOOL WINAPI DestroyAcceleratorTable(HACCEL hAccel);
  WINUSERAPI inteiro WINAPI CopyAcceleratorTableA(HACCEL hAccelSrc,LPACCEL lpAccelDst,inteiro cAccelEntries);
  WINUSERAPI inteiro WINAPI CopyAcceleratorTableW(HACCEL hAccelSrc,LPACCEL lpAccelDst,inteiro cAccelEntries);

#se_não_definido NOMSG

#se_definido UNICODE
#defina TranslateAccelerator TranslateAcceleratorW
#senão
#defina TranslateAccelerator TranslateAcceleratorA
#fim_se

  WINUSERAPI inteiro WINAPI TranslateAcceleratorA(HWND hWnd,HACCEL hAccTable,LPMSG lpMsg);
  WINUSERAPI inteiro WINAPI TranslateAcceleratorW(HWND hWnd,HACCEL hAccTable,LPMSG lpMsg);
#fim_se

#se_não_definido NOSYSMETRICS

#defina SM_CXSCREEN 0
#defina SM_CYSCREEN 1
#defina SM_CXVSCROLL 2
#defina SM_CYHSCROLL 3
#defina SM_CYCAPTION 4
#defina SM_CXBORDER 5
#defina SM_CYBORDER 6
#defina SM_CXDLGFRAME 7
#defina SM_CYDLGFRAME 8
#defina SM_CYVTHUMB 9
#defina SM_CXHTHUMB 10
#defina SM_CXICON 11
#defina SM_CYICON 12
#defina SM_CXCURSOR 13
#defina SM_CYCURSOR 14
#defina SM_CYMENU 15
#defina SM_CXFULLSCREEN 16
#defina SM_CYFULLSCREEN 17
#defina SM_CYKANJIWINDOW 18
#defina SM_MOUSEPRESENT 19
#defina SM_CYVSCROLL 20
#defina SM_CXHSCROLL 21
#defina SM_DEBUG 22
#defina SM_SWAPBUTTON 23
#defina SM_RESERVED1 24
#defina SM_RESERVED2 25
#defina SM_RESERVED3 26
#defina SM_RESERVED4 27
#defina SM_CXMIN 28
#defina SM_CYMIN 29
#defina SM_CXSIZE 30
#defina SM_CYSIZE 31
#defina SM_CXFRAME 32
#defina SM_CYFRAME 33
#defina SM_CXMINTRACK 34
#defina SM_CYMINTRACK 35
#defina SM_CXDOUBLECLK 36
#defina SM_CYDOUBLECLK 37
#defina SM_CXICONSPACING 38
#defina SM_CYICONSPACING 39
#defina SM_MENUDROPALIGNMENT 40
#defina SM_PENWINDOWS 41
#defina SM_DBCSENABLED 42
#defina SM_CMOUSEBUTTONS 43

#defina SM_CXFIXEDFRAME SM_CXDLGFRAME
#defina SM_CYFIXEDFRAME SM_CYDLGFRAME
#defina SM_CXSIZEFRAME SM_CXFRAME
#defina SM_CYSIZEFRAME SM_CYFRAME

#defina SM_SECURE 44
#defina SM_CXEDGE 45
#defina SM_CYEDGE 46
#defina SM_CXMINSPACING 47
#defina SM_CYMINSPACING 48
#defina SM_CXSMICON 49
#defina SM_CYSMICON 50
#defina SM_CYSMCAPTION 51
#defina SM_CXSMSIZE 52
#defina SM_CYSMSIZE 53
#defina SM_CXMENUSIZE 54
#defina SM_CYMENUSIZE 55
#defina SM_ARRANGE 56
#defina SM_CXMINIMIZED 57
#defina SM_CYMINIMIZED 58
#defina SM_CXMAXTRACK 59
#defina SM_CYMAXTRACK 60
#defina SM_CXMAXIMIZED 61
#defina SM_CYMAXIMIZED 62
#defina SM_NETWORK 63
#defina SM_CLEANBOOT 67
#defina SM_CXDRAG 68
#defina SM_CYDRAG 69
#defina SM_SHOWSOUNDS 70
#defina SM_CXMENUCHECK 71
#defina SM_CYMENUCHECK 72
#defina SM_SLOWMACHINE 73
#defina SM_MIDEASTENABLED 74
#defina SM_MOUSEWHEELPRESENT 75
#defina SM_XVIRTUALSCREEN 76
#defina SM_YVIRTUALSCREEN 77
#defina SM_CXVIRTUALSCREEN 78
#defina SM_CYVIRTUALSCREEN 79
#defina SM_CMONITORS 80
#defina SM_SAMEDISPLAYFORMAT 81
#defina SM_IMMENABLED 82
#defina SM_CXFOCUSBORDER 83
#defina SM_CYFOCUSBORDER 84
#defina SM_TABLETPC 86
#defina SM_MEDIACENTER 87
#defina SM_STARTER 88
#defina SM_SERVERR2 89
#defina SM_CMETRICS 90
#defina SM_REMOTESESSION 0x1000
#defina SM_SHUTTINGDOWN 0x2000
#defina SM_REMOTECONTROL 0x2001
#defina SM_CARETBLINKINGENABLED 0x2002

  WINUSERAPI inteiro WINAPI GetSystemMetrics(inteiro nIndex);
#fim_se

#se_não_definido NOMENUS

#se_definido UNICODE
#defina LoadMenu LoadMenuW
#defina LoadMenuIndirect LoadMenuIndirectW
#defina ChangeMenu ChangeMenuW
#defina GetMenuString GetMenuStringW
#defina InsertMenu InsertMenuW
#defina AppendMenu AppendMenuW
#defina ModifyMenu ModifyMenuW
#senão
#defina LoadMenu LoadMenuA
#defina LoadMenuIndirect LoadMenuIndirectA
#defina ChangeMenu ChangeMenuA
#defina GetMenuString GetMenuStringA
#defina InsertMenu InsertMenuA
#defina AppendMenu AppendMenuA
#defina ModifyMenu ModifyMenuA
#fim_se

  WINUSERAPI HMENU WINAPI LoadMenuA(HINSTANCE hInstance,LPCSTR lpMenuName);
  WINUSERAPI HMENU WINAPI LoadMenuW(HINSTANCE hInstance,LPCWSTR lpMenuName);
  WINUSERAPI HMENU WINAPI LoadMenuIndirectA(CONST MENUTEMPLATEA *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI LoadMenuIndirectW(CONST MENUTEMPLATEW *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI GetMenu(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI SetMenu(HWND hWnd,HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI ChangeMenuA(HMENU hMenu,UINT cmd,LPCSTR lpszNewItem,UINT cmdInsert,UINT flags);
  WINUSERAPI WINBOOL WINAPI ChangeMenuW(HMENU hMenu,UINT cmd,LPCWSTR lpszNewItem,UINT cmdInsert,UINT flags);
  WINUSERAPI WINBOOL WINAPI HiliteMenuItem(HWND hWnd,HMENU hMenu,UINT uIDHiliteItem,UINT uHilite);
  WINUSERAPI inteiro WINAPI GetMenuStringA(HMENU hMenu,UINT uIDItem,LPSTR lpString,inteiro cchMax,UINT flags);
  WINUSERAPI inteiro WINAPI GetMenuStringW(HMENU hMenu,UINT uIDItem,LPWSTR lpString,inteiro cchMax,UINT flags);
  WINUSERAPI UINT WINAPI GetMenuState(HMENU hMenu,UINT uId,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawMenuBar(HWND hWnd);

#defina PMB_ACTIVE 0x00000001

  WINUSERAPI HMENU WINAPI GetSystemMenu(HWND hWnd,WINBOOL bRevert);
  WINUSERAPI HMENU WINAPI CreateMenu(VOID);
  WINUSERAPI HMENU WINAPI CreatePopupMenu(VOID);
  WINUSERAPI WINBOOL WINAPI DestroyMenu(HMENU hMenu);
  WINUSERAPI DWORD WINAPI CheckMenuItem(HMENU hMenu,UINT uIDCheckItem,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI EnableMenuItem(HMENU hMenu,UINT uIDEnableItem,UINT uEnable);
  WINUSERAPI HMENU WINAPI GetSubMenu(HMENU hMenu,inteiro nPos);
  WINUSERAPI UINT WINAPI GetMenuItemID(HMENU hMenu,inteiro nPos);
  WINUSERAPI inteiro WINAPI GetMenuItemCount(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI InsertMenuA(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem);
  WINUSERAPI WINBOOL WINAPI InsertMenuW(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem);
  WINUSERAPI WINBOOL WINAPI AppendMenuA(HMENU hMenu,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem);
  WINUSERAPI WINBOOL WINAPI AppendMenuW(HMENU hMenu,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem);
  WINUSERAPI WINBOOL WINAPI ModifyMenuA(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem);
  WINUSERAPI WINBOOL WINAPI ModifyMenuW(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem);
  WINUSERAPI WINBOOL WINAPI RemoveMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DeleteMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI SetMenuItemBitmaps(HMENU hMenu,UINT uPosition,UINT uFlags,HBITMAP hBitmapUnchecked,HBITMAP hBitmapChecked);
  WINUSERAPI LONG WINAPI GetMenuCheckMarkDimensions(VOID);
  WINUSERAPI WINBOOL WINAPI TrackPopupMenu(HMENU hMenu,UINT uFlags,inteiro x,inteiro y,inteiro nReserved,HWND hWnd,CONST RECT *prcRect);

#defina MNC_IGNORE 0
#defina MNC_CLOSE 1
#defina MNC_EXECUTE 2
#defina MNC_SELECT 3

  defina_tipo estrutura tagTPMPARAMS {
    UINT cbSize;
    RECT rcExclude;
  } TPMPARAMS;

  defina_tipo TPMPARAMS *LPTPMPARAMS;

  WINUSERAPI WINBOOL WINAPI TrackPopupMenuEx(HMENU,UINT,inteiro,inteiro,HWND,LPTPMPARAMS);

#defina MNS_NOCHECK 0x80000000
#defina MNS_MODELESS 0x40000000
#defina MNS_DRAGDROP 0x20000000
#defina MNS_AUTODISMISS 0x10000000
#defina MNS_NOTIFYBYPOS 0x08000000
#defina MNS_CHECKORBMP 0x04000000

#defina MIM_MAXHEIGHT 0x00000001
#defina MIM_BACKGROUND 0x00000002
#defina MIM_HELPID 0x00000004
#defina MIM_MENUDATA 0x00000008
#defina MIM_STYLE 0x00000010
#defina MIM_APPLYTOSUBMENUS 0x80000000

  defina_tipo estrutura tagMENUINFO {
    DWORD cbSize;
    DWORD fMask;
    DWORD dwStyle;
    UINT cyMax;
    HBRUSH hbrBack;
    DWORD dwContextHelpID;
    ULONG_PTR dwMenuData;
  } MENUINFO,*LPMENUINFO;

  defina_tipo MENUINFO CONST *LPCMENUINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuInfo(HMENU,LPMENUINFO);
  WINUSERAPI WINBOOL WINAPI SetMenuInfo(HMENU,LPCMENUINFO);
  WINUSERAPI WINBOOL WINAPI EndMenu(VOID);

#defina MND_CONTINUE 0
#defina MND_ENDMENU 1

  defina_tipo estrutura tagMENUGETOBJECTINFO {
    DWORD dwFlags;
    UINT uPos;
    HMENU hmenu;
    PVOID riid;
    PVOID pvObj;
  } MENUGETOBJECTINFO,*PMENUGETOBJECTINFO;

#defina MNGOF_TOPGAP 0x00000001
#defina MNGOF_BOTTOMGAP 0x00000002

#defina MNGO_NOINTERFACE 0x00000000
#defina MNGO_NOERROR 0x00000001

#defina MIIM_STATE 0x00000001
#defina MIIM_ID 0x00000002
#defina MIIM_SUBMENU 0x00000004
#defina MIIM_CHECKMARKS 0x00000008
#defina MIIM_TYPE 0x00000010
#defina MIIM_DATA 0x00000020

#defina MIIM_STRING 0x00000040
#defina MIIM_BITMAP 0x00000080
#defina MIIM_FTYPE 0x00000100

#defina HBMMENU_CALLBACK ((HBITMAP) -1)
#defina HBMMENU_SYSTEM ((HBITMAP) 1)
#defina HBMMENU_MBAR_RESTORE ((HBITMAP) 2)
#defina HBMMENU_MBAR_MINIMIZE ((HBITMAP) 3)
#defina HBMMENU_MBAR_CLOSE ((HBITMAP) 5)
#defina HBMMENU_MBAR_CLOSE_D ((HBITMAP) 6)
#defina HBMMENU_MBAR_MINIMIZE_D ((HBITMAP) 7)
#defina HBMMENU_POPUP_CLOSE ((HBITMAP) 8)
#defina HBMMENU_POPUP_RESTORE ((HBITMAP) 9)
#defina HBMMENU_POPUP_MAXIMIZE ((HBITMAP) 10)
#defina HBMMENU_POPUP_MINIMIZE ((HBITMAP) 11)

  defina_tipo estrutura tagMENUITEMINFOA {
    UINT cbSize;
    UINT fMask;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dwItemData;
    LPSTR dwTypeData;
    UINT cch;
    HBITMAP hbmpItem;
  } MENUITEMINFOA,*LPMENUITEMINFOA;

  defina_tipo estrutura tagMENUITEMINFOW {
    UINT cbSize;
    UINT fMask;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dwItemData;
    LPWSTR dwTypeData;
    UINT cch;
    HBITMAP hbmpItem;
  } MENUITEMINFOW,*LPMENUITEMINFOW;

#se_definido UNICODE
  defina_tipo MENUITEMINFOW MENUITEMINFO;
  defina_tipo LPMENUITEMINFOW LPMENUITEMINFO;
#senão
  defina_tipo MENUITEMINFOA MENUITEMINFO;
  defina_tipo LPMENUITEMINFOA LPMENUITEMINFO;
#fim_se
  defina_tipo MENUITEMINFOA CONST *LPCMENUITEMINFOA;
  defina_tipo MENUITEMINFOW CONST *LPCMENUITEMINFOW;
#se_definido UNICODE
  defina_tipo LPCMENUITEMINFOW LPCMENUITEMINFO;
#senão
  defina_tipo LPCMENUITEMINFOA LPCMENUITEMINFO;
#fim_se

#se_definido UNICODE
#defina InsertMenuItem InsertMenuItemW
#defina GetMenuItemInfo GetMenuItemInfoW
#defina SetMenuItemInfo SetMenuItemInfoW
#senão
#defina InsertMenuItem InsertMenuItemA
#defina GetMenuItemInfo GetMenuItemInfoA
#defina SetMenuItemInfo SetMenuItemInfoA
#fim_se

  WINUSERAPI WINBOOL WINAPI InsertMenuItemA(HMENU hmenu,UINT item,WINBOOL fByPosition,LPCMENUITEMINFOA lpmi);
  WINUSERAPI WINBOOL WINAPI InsertMenuItemW(HMENU hmenu,UINT item,WINBOOL fByPosition,LPCMENUITEMINFOW lpmi);
  WINUSERAPI WINBOOL WINAPI GetMenuItemInfoA(HMENU hmenu,UINT item,WINBOOL fByPosition,LPMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI GetMenuItemInfoW(HMENU hmenu,UINT item,WINBOOL fByPosition,LPMENUITEMINFOW lpmii);
  WINUSERAPI WINBOOL WINAPI SetMenuItemInfoA(HMENU hmenu,UINT item,WINBOOL fByPositon,LPCMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI SetMenuItemInfoW(HMENU hmenu,UINT item,WINBOOL fByPositon,LPCMENUITEMINFOW lpmii);

#defina GMDI_USEDISABLED 0x0001L
#defina GMDI_GOINTOPOPUPS 0x0002L

  WINUSERAPI UINT WINAPI GetMenuDefaultItem(HMENU hMenu,UINT fByPos,UINT gmdiFlags);
  WINUSERAPI WINBOOL WINAPI SetMenuDefaultItem(HMENU hMenu,UINT uItem,UINT fByPos);
  WINUSERAPI WINBOOL WINAPI GetMenuItemRect(HWND hWnd,HMENU hMenu,UINT uItem,LPRECT lprcItem);
  WINUSERAPI inteiro WINAPI MenuItemFromPoint(HWND hWnd,HMENU hMenu,POINT ptScreen);

#defina TPM_LEFTBUTTON 0x0000L
#defina TPM_RIGHTBUTTON 0x0002L
#defina TPM_LEFTALIGN 0x0000L
#defina TPM_CENTERALIGN 0x0004L
#defina TPM_RIGHTALIGN 0x0008L
#defina TPM_TOPALIGN 0x0000L
#defina TPM_VCENTERALIGN 0x0010L
#defina TPM_BOTTOMALIGN 0x0020L

#defina TPM_HORIZONTAL 0x0000L
#defina TPM_VERTICAL 0x0040L
#defina TPM_NONOTIFY 0x0080L
#defina TPM_RETURNCMD 0x0100L
#defina TPM_RECURSE 0x0001L
#defina TPM_HORPOSANIMATION 0x0400L
#defina TPM_HORNEGANIMATION 0x0800L
#defina TPM_VERPOSANIMATION 0x1000L
#defina TPM_VERNEGANIMATION 0x2000L
#defina TPM_NOANIMATION 0x4000L
#defina TPM_LAYOUTRTL 0x8000L
#fim_se

  defina_tipo estrutura tagDROPSTRUCT {
    HWND hwndSource;
    HWND hwndSink;
    DWORD wFmt;
    ULONG_PTR dwData;
    POINT ptDrop;
    DWORD dwControlData;
  } DROPSTRUCT,*PDROPSTRUCT,*LPDROPSTRUCT;

#defina DOF_EXECUTABLE 0x8001
#defina DOF_DOCUMENT 0x8002
#defina DOF_DIRECTORY 0x8003
#defina DOF_MULTIPLE 0x8004
#defina DOF_PROGMAN 0x0001
#defina DOF_SHELLDATA 0x0002

#defina DO_DROPFILE 0x454C4946L
#defina DO_PRINTFILE 0x544E5250L

  WINUSERAPI DWORD WINAPI DragObject(HWND hwndParent,HWND hwndFrom,UINT fmt,ULONG_PTR data,HCURSOR hcur);
  WINUSERAPI WINBOOL WINAPI DragDetect(HWND hwnd,POINT pt);
  WINUSERAPI WINBOOL WINAPI DrawIcon(HDC hDC,inteiro X,inteiro Y,HICON hIcon);

#se_não_definido NODRAWTEXT

#defina DT_TOP 0x00000000
#defina DT_LEFT 0x00000000
#defina DT_CENTER 0x00000001
#defina DT_RIGHT 0x00000002
#defina DT_VCENTER 0x00000004
#defina DT_BOTTOM 0x00000008
#defina DT_WORDBREAK 0x00000010
#defina DT_SINGLELINE 0x00000020
#defina DT_EXPANDTABS 0x00000040
#defina DT_TABSTOP 0x00000080
#defina DT_NOCLIP 0x00000100
#defina DT_EXTERNALLEADING 0x00000200
#defina DT_CALCRECT 0x00000400
#defina DT_NOPREFIX 0x00000800
#defina DT_INTERNAL 0x00001000

#defina DT_EDITCONTROL 0x00002000
#defina DT_PATH_ELLIPSIS 0x00004000
#defina DT_END_ELLIPSIS 0x00008000
#defina DT_MODIFYSTRING 0x00010000
#defina DT_RTLREADING 0x00020000
#defina DT_WORD_ELLIPSIS 0x00040000
#defina DT_NOFULLWIDTHCHARBREAK 0x00080000
#defina DT_HIDEPREFIX 0x00100000
#defina DT_PREFIXONLY 0x00200000

  defina_tipo estrutura tagDRAWTEXTPARAMS {
    UINT cbSize;
    inteiro iTabLength;
    inteiro iLeftMargin;
    inteiro iRightMargin;
    UINT uiLengthDrawn;
  } DRAWTEXTPARAMS,*LPDRAWTEXTPARAMS;

#se_definido UNICODE
#defina DrawText DrawTextW
#defina DrawTextEx DrawTextExW
#senão
#defina DrawText DrawTextA
#defina DrawTextEx DrawTextExA
#fim_se

  WINUSERAPI inteiro WINAPI DrawTextA(HDC hdc,LPCSTR lpchText,inteiro cchText,LPRECT lprc,UINT format);
  WINUSERAPI inteiro WINAPI DrawTextW(HDC hdc,LPCWSTR lpchText,inteiro cchText,LPRECT lprc,UINT format);
  WINUSERAPI inteiro WINAPI DrawTextExA(HDC hdc,LPSTR lpchText,inteiro cchText,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
  WINUSERAPI inteiro WINAPI DrawTextExW(HDC hdc,LPWSTR lpchText,inteiro cchText,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
#fim_se

#se_definido UNICODE
#defina GrayString GrayStringW
#defina DrawState DrawStateW
#defina TabbedTextOut TabbedTextOutW
#defina GetTabbedTextExtent GetTabbedTextExtentW
#senão
#defina GrayString GrayStringA
#defina DrawState DrawStateA
#defina TabbedTextOut TabbedTextOutA
#defina GetTabbedTextExtent GetTabbedTextExtentA
#fim_se

  WINUSERAPI WINBOOL WINAPI GrayStringA(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lpData,inteiro nCount,inteiro X,inteiro Y,inteiro nWidth,inteiro nHeight);
  WINUSERAPI WINBOOL WINAPI GrayStringW(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lpData,inteiro nCount,inteiro X,inteiro Y,inteiro nWidth,inteiro nHeight);

#defina DST_COMPLEX 0x0000
#defina DST_TEXT 0x0001
#defina DST_PREFIXTEXT 0x0002
#defina DST_ICON 0x0003
#defina DST_BITMAP 0x0004

#defina DSS_NORMAL 0x0000
#defina DSS_UNION 0x0010
#defina DSS_DISABLED 0x0020
#defina DSS_MONO 0x0080
#defina DSS_HIDEPREFIX 0x0200
#defina DSS_PREFIXONLY 0x0400
#defina DSS_RIGHT 0x8000

  WINUSERAPI WINBOOL WINAPI DrawStateA(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfnCallBack,LPARAM lData,WPARAM wData,inteiro x,inteiro y,inteiro cx,inteiro cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawStateW(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfnCallBack,LPARAM lData,WPARAM wData,inteiro x,inteiro y,inteiro cx,inteiro cy,UINT uFlags);
  WINUSERAPI LONG WINAPI TabbedTextOutA(HDC hdc,inteiro x,inteiro y,LPCSTR lpString,inteiro chCount,inteiro nTabPositions,CONST INT *lpnTabStopPositions,inteiro nTabOrigin);
  WINUSERAPI LONG WINAPI TabbedTextOutW(HDC hdc,inteiro x,inteiro y,LPCWSTR lpString,inteiro chCount,inteiro nTabPositions,CONST INT *lpnTabStopPositions,inteiro nTabOrigin);
  WINUSERAPI DWORD WINAPI GetTabbedTextExtentA(HDC hdc,LPCSTR lpString,inteiro chCount,inteiro nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI DWORD WINAPI GetTabbedTextExtentW(HDC hdc,LPCWSTR lpString,inteiro chCount,inteiro nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI WINBOOL WINAPI UpdateWindow(HWND hWnd);
  WINUSERAPI HWND WINAPI SetActiveWindow(HWND hWnd);
  WINUSERAPI HWND WINAPI GetForegroundWindow(VOID);
  WINUSERAPI WINBOOL WINAPI PaintDesktop(HDC hdc);
  WINUSERAPI VOID WINAPI SwitchToThisWindow(HWND hwnd,WINBOOL fUnknown);
  WINUSERAPI WINBOOL WINAPI SetForegroundWindow(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI AllowSetForegroundWindow(DWORD dwProcessId);

#defina ASFW_ANY ((DWORD)-1)

  WINUSERAPI WINBOOL WINAPI LockSetForegroundWindow(UINT uLockCode);

#defina LSFW_LOCK 1
#defina LSFW_UNLOCK 2

  WINUSERAPI HWND WINAPI WindowFromDC(HDC hDC);
  WINUSERAPI HDC WINAPI GetDC(HWND hWnd);
  WINUSERAPI HDC WINAPI GetDCEx(HWND hWnd,HRGN hrgnClip,DWORD flags);

#defina DCX_WINDOW 0x00000001L
#defina DCX_CACHE 0x00000002L
#defina DCX_NORESETATTRS 0x00000004L
#defina DCX_CLIPCHILDREN 0x00000008L
#defina DCX_CLIPSIBLINGS 0x00000010L
#defina DCX_PARENTCLIP 0x00000020L
#defina DCX_EXCLUDERGN 0x00000040L
#defina DCX_INTERSECTRGN 0x00000080L
#defina DCX_EXCLUDEUPDATE 0x00000100L
#defina DCX_INTERSECTUPDATE 0x00000200L
#defina DCX_LOCKWINDOWUPDATE 0x00000400L

#defina DCX_VALIDATE 0x00200000L

  WINUSERAPI HDC WINAPI GetWindowDC(HWND hWnd);
  WINUSERAPI inteiro WINAPI ReleaseDC(HWND hWnd,HDC hDC);
  WINUSERAPI HDC WINAPI BeginPaint(HWND hWnd,LPPAINTSTRUCT lpPaint);
  WINUSERAPI WINBOOL WINAPI EndPaint(HWND hWnd,CONST PAINTSTRUCT *lpPaint);
  WINUSERAPI WINBOOL WINAPI GetUpdateRect(HWND hWnd,LPRECT lpRect,WINBOOL bErase);
  WINUSERAPI inteiro WINAPI GetUpdateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI inteiro WINAPI SetWindowRgn(HWND hWnd,HRGN hRgn,WINBOOL bRedraw);
  WINUSERAPI inteiro WINAPI GetWindowRgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI inteiro WINAPI GetWindowRgnBox(HWND hWnd,LPRECT lprc);
  WINUSERAPI inteiro WINAPI ExcludeUpdateRgn(HDC hDC,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI InvalidateRect(HWND hWnd,CONST RECT *lpRect,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRect(HWND hWnd,CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI InvalidateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI WINBOOL WINAPI RedrawWindow(HWND hWnd,CONST RECT *lprcUpdate,HRGN hrgnUpdate,UINT flags);

#defina RDW_INVALIDATE 0x0001
#defina RDW_INTERNALPAINT 0x0002
#defina RDW_ERASE 0x0004

#defina RDW_VALIDATE 0x0008
#defina RDW_NOINTERNALPAINT 0x0010
#defina RDW_NOERASE 0x0020

#defina RDW_NOCHILDREN 0x0040
#defina RDW_ALLCHILDREN 0x0080

#defina RDW_UPDATENOW 0x0100
#defina RDW_ERASENOW 0x0200

#defina RDW_FRAME 0x0400
#defina RDW_NOFRAME 0x0800

  WINUSERAPI WINBOOL WINAPI LockWindowUpdate(HWND hWndLock);
  WINUSERAPI WINBOOL WINAPI ScrollWindow(HWND hWnd,inteiro XAmount,inteiro YAmount,CONST RECT *lpRect,CONST RECT *lpClipRect);
  WINUSERAPI WINBOOL WINAPI ScrollDC(HDC hDC,inteiro dx,inteiro dy,CONST RECT *lprcScroll,CONST RECT *lprcClip,HRGN hrgnUpdate,LPRECT lprcUpdate);
  WINUSERAPI inteiro WINAPI ScrollWindowEx(HWND hWnd,inteiro dx,inteiro dy,CONST RECT *prcScroll,CONST RECT *prcClip,HRGN hrgnUpdate,LPRECT prcUpdate,UINT flags);

#defina SW_SCROLLCHILDREN 0x0001
#defina SW_INVALIDATE 0x0002
#defina SW_ERASE 0x0004
#defina SW_SMOOTHSCROLL 0x0010

#se_não_definido NOSCROLL
  WINUSERAPI inteiro WINAPI SetScrollPos(HWND hWnd,inteiro nBar,inteiro nPos,WINBOOL bRedraw);
  WINUSERAPI inteiro WINAPI GetScrollPos(HWND hWnd,inteiro nBar);
  WINUSERAPI WINBOOL WINAPI SetScrollRange(HWND hWnd,inteiro nBar,inteiro nMinPos,inteiro nMaxPos,WINBOOL bRedraw);
  WINUSERAPI WINBOOL WINAPI GetScrollRange(HWND hWnd,inteiro nBar,LPINT lpMinPos,LPINT lpMaxPos);
  WINUSERAPI WINBOOL WINAPI ShowScrollBar(HWND hWnd,inteiro wBar,WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI EnableScrollBar(HWND hWnd,UINT wSBflags,UINT wArrows);

#defina ESB_ENABLE_BOTH 0x0000
#defina ESB_DISABLE_BOTH 0x0003

#defina ESB_DISABLE_LEFT 0x0001
#defina ESB_DISABLE_RIGHT 0x0002

#defina ESB_DISABLE_UP 0x0001
#defina ESB_DISABLE_DOWN 0x0002

#defina ESB_DISABLE_LTUP ESB_DISABLE_LEFT
#defina ESB_DISABLE_RTDN ESB_DISABLE_RIGHT
#fim_se

#se_definido UNICODE
#defina SetProp SetPropW
#defina GetProp GetPropW
#defina RemoveProp RemovePropW
#defina EnumPropsEx EnumPropsExW
#defina EnumProps EnumPropsW
#defina SetWindowText SetWindowTextW
#defina GetWindowText GetWindowTextW
#defina GetWindowTextLength GetWindowTextLengthW
#senão
#defina SetProp SetPropA
#defina GetProp GetPropA
#defina RemoveProp RemovePropA
#defina EnumPropsEx EnumPropsExA
#defina EnumProps EnumPropsA
#defina SetWindowText SetWindowTextA
#defina GetWindowText GetWindowTextA
#defina GetWindowTextLength GetWindowTextLengthA
#fim_se

  WINUSERAPI WINBOOL WINAPI SetPropA(HWND hWnd,LPCSTR lpString,HANDLE hData);
  WINUSERAPI WINBOOL WINAPI SetPropW(HWND hWnd,LPCWSTR lpString,HANDLE hData);
  WINUSERAPI HANDLE WINAPI GetPropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI GetPropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI inteiro WINAPI EnumPropsExA(HWND hWnd,PROPENUMPROCEXA lpEnumFunc,LPARAM lParam);
  WINUSERAPI inteiro WINAPI EnumPropsExW(HWND hWnd,PROPENUMPROCEXW lpEnumFunc,LPARAM lParam);
  WINUSERAPI inteiro WINAPI EnumPropsA(HWND hWnd,PROPENUMPROCA lpEnumFunc);
  WINUSERAPI inteiro WINAPI EnumPropsW(HWND hWnd,PROPENUMPROCW lpEnumFunc);
  WINUSERAPI WINBOOL WINAPI SetWindowTextA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI SetWindowTextW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI inteiro WINAPI GetWindowTextA(HWND hWnd,LPSTR lpString,inteiro nMaxCount);
  WINUSERAPI inteiro WINAPI GetWindowTextW(HWND hWnd,LPWSTR lpString,inteiro nMaxCount);
  WINUSERAPI inteiro WINAPI GetWindowTextLengthA(HWND hWnd);
  WINUSERAPI inteiro WINAPI GetWindowTextLengthW(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI GetClientRect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI GetWindowRect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI AdjustWindowRect(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu);
  WINUSERAPI WINBOOL WINAPI AdjustWindowRectEx(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu,DWORD dwExStyle);

#defina HELPINFO_WINDOW 0x0001
#defina HELPINFO_MENUITEM 0x0002

  defina_tipo estrutura tagHELPINFO {
    UINT cbSize;
    inteiro iContextType;
    inteiro iCtrlId;
    HANDLE hItemHandle;
    DWORD_PTR dwContextId;
    POINT MousePos;
  } HELPINFO,*LPHELPINFO;

  WINUSERAPI WINBOOL WINAPI SetWindowContextHelpId(HWND,DWORD);
  WINUSERAPI DWORD WINAPI GetWindowContextHelpId(HWND);
  WINUSERAPI WINBOOL WINAPI SetMenuContextHelpId(HMENU,DWORD);
  WINUSERAPI DWORD WINAPI GetMenuContextHelpId(HMENU);

#se_não_definido NOMB

#defina MB_OK 0x00000000L
#defina MB_OKCANCEL 0x00000001L
#defina MB_ABORTRETRYIGNORE 0x00000002L
#defina MB_YESNOCANCEL 0x00000003L
#defina MB_YESNO 0x00000004L
#defina MB_RETRYCANCEL 0x00000005L
#defina MB_CANCELTRYCONTINUE 0x00000006L
#defina MB_ICONHAND 0x00000010L
#defina MB_ICONQUESTION 0x00000020L
#defina MB_ICONEXCLAMATION 0x00000030L
#defina MB_ICONASTERISK 0x00000040L
#defina MB_USERICON 0x00000080L
#defina MB_ICONWARNING MB_ICONEXCLAMATION
#defina MB_ICONERROR MB_ICONHAND
#defina MB_ICONINFORMATION MB_ICONASTERISK
#defina MB_ICONSTOP MB_ICONHAND
#defina MB_DEFBUTTON1 0x00000000L
#defina MB_DEFBUTTON2 0x00000100L
#defina MB_DEFBUTTON3 0x00000200L
#defina MB_DEFBUTTON4 0x00000300L
#defina MB_APPLMODAL 0x00000000L
#defina MB_SYSTEMMODAL 0x00001000L
#defina MB_TASKMODAL 0x00002000L
#defina MB_HELP 0x00004000L
#defina MB_NOFOCUS 0x00008000L
#defina MB_SETFOREGROUND 0x00010000L
#defina MB_DEFAULT_DESKTOP_ONLY 0x00020000L
#defina MB_TOPMOST 0x00040000L
#defina MB_RIGHT 0x00080000L
#defina MB_RTLREADING 0x00100000L
#defina MB_SERVICE_NOTIFICATION 0x00200000L
#defina MB_SERVICE_NOTIFICATION_NT3X 0x00040000L
#defina MB_TYPEMASK 0x0000000FL
#defina MB_ICONMASK 0x000000F0L
#defina MB_DEFMASK 0x00000F00L
#defina MB_MODEMASK 0x00003000L
#defina MB_MISCMASK 0x0000C000L

#se_definido UNICODE
#defina MessageBox MessageBoxW
#defina MessageBoxEx MessageBoxExW
#senão
#defina MessageBox MessageBoxA
#defina MessageBoxEx MessageBoxExA
#fim_se

  WINUSERAPI inteiro WINAPI MessageBoxA(HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType);
  WINUSERAPI inteiro WINAPI MessageBoxW(HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType);
  WINUSERAPI inteiro WINAPI MessageBoxExA(HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType,WORD wLanguageId);
  WINUSERAPI inteiro WINAPI MessageBoxExW(HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType,WORD wLanguageId);

  defina_tipo VOID (CALLBACK *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

  defina_tipo estrutura tagMSGBOXPARAMSA {
    UINT cbSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpszText;
    LPCSTR lpszCaption;
    DWORD dwStyle;
    LPCSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfnMsgBoxCallback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSA,*PMSGBOXPARAMSA,*LPMSGBOXPARAMSA;

  defina_tipo estrutura tagMSGBOXPARAMSW {
    UINT cbSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpszText;
    LPCWSTR lpszCaption;
    DWORD dwStyle;
    LPCWSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfnMsgBoxCallback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSW,*PMSGBOXPARAMSW,*LPMSGBOXPARAMSW;

#se_definido UNICODE
  defina_tipo MSGBOXPARAMSW MSGBOXPARAMS;
  defina_tipo PMSGBOXPARAMSW PMSGBOXPARAMS;
  defina_tipo LPMSGBOXPARAMSW LPMSGBOXPARAMS;
#senão
  defina_tipo MSGBOXPARAMSA MSGBOXPARAMS;
  defina_tipo PMSGBOXPARAMSA PMSGBOXPARAMS;
  defina_tipo LPMSGBOXPARAMSA LPMSGBOXPARAMS;
#fim_se

#se_definido UNICODE
#defina MessageBoxIndirect MessageBoxIndirectW
#senão
#defina MessageBoxIndirect MessageBoxIndirectA
#fim_se

  WINUSERAPI inteiro WINAPI MessageBoxIndirectA(CONST MSGBOXPARAMSA *lpmbp);
  WINUSERAPI inteiro WINAPI MessageBoxIndirectW(CONST MSGBOXPARAMSW *lpmbp);
  WINUSERAPI WINBOOL WINAPI MessageBeep(UINT uType);
#fim_se

  WINUSERAPI inteiro WINAPI ShowCursor(WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI SetCursorPos(inteiro X,inteiro Y);
  WINUSERAPI HCURSOR WINAPI SetCursor(HCURSOR hCursor);
  WINUSERAPI WINBOOL WINAPI GetCursorPos(LPPOINT lpPoint);
  WINUSERAPI WINBOOL WINAPI ClipCursor(CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI GetClipCursor(LPRECT lpRect);
  WINUSERAPI HCURSOR WINAPI GetCursor(VOID);
  WINUSERAPI WINBOOL WINAPI CreateCaret(HWND hWnd,HBITMAP hBitmap,inteiro nWidth,inteiro nHeight);
  WINUSERAPI UINT WINAPI GetCaretBlinkTime(VOID);
  WINUSERAPI WINBOOL WINAPI SetCaretBlinkTime(UINT uMSeconds);
  WINUSERAPI WINBOOL WINAPI DestroyCaret(VOID);
  WINUSERAPI WINBOOL WINAPI HideCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ShowCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI SetCaretPos(inteiro X,inteiro Y);
  WINUSERAPI WINBOOL WINAPI GetCaretPos(LPPOINT lpPoint);
  WINUSERAPI WINBOOL WINAPI ClientToScreen(HWND hWnd,LPPOINT lpPoint);
  WINUSERAPI WINBOOL WINAPI ScreenToClient(HWND hWnd,LPPOINT lpPoint);
  WINUSERAPI inteiro WINAPI MapWindowPoints(HWND hWndFrom,HWND hWndTo,LPPOINT lpPoints,UINT cPoints);
  WINUSERAPI HWND WINAPI WindowFromPoint(POINT Point);
  WINUSERAPI HWND WINAPI ChildWindowFromPoint(HWND hWndParent,POINT Point);

#defina CWP_ALL 0x0000
#defina CWP_SKIPINVISIBLE 0x0001
#defina CWP_SKIPDISABLED 0x0002
#defina CWP_SKIPTRANSPARENT 0x0004

  WINUSERAPI HWND WINAPI ChildWindowFromPointEx(HWND hwnd,POINT pt,UINT flags);

#se_não_definido NOCOLOR

#defina CTLCOLOR_MSGBOX 0
#defina CTLCOLOR_EDIT 1
#defina CTLCOLOR_LISTBOX 2
#defina CTLCOLOR_BTN 3
#defina CTLCOLOR_DLG 4
#defina CTLCOLOR_SCROLLBAR 5
#defina CTLCOLOR_STATIC 6
#defina CTLCOLOR_MAX 7

#defina COLOR_SCROLLBAR 0
#defina COLOR_BACKGROUND 1
#defina COLOR_ACTIVECAPTION 2
#defina COLOR_INACTIVECAPTION 3
#defina COLOR_MENU 4
#defina COLOR_WINDOW 5
#defina COLOR_WINDOWFRAME 6
#defina COLOR_MENUTEXT 7
#defina COLOR_WINDOWTEXT 8
#defina COLOR_CAPTIONTEXT 9
#defina COLOR_ACTIVEBORDER 10
#defina COLOR_INACTIVEBORDER 11
#defina COLOR_APPWORKSPACE 12
#defina COLOR_HIGHLIGHT 13
#defina COLOR_HIGHLIGHTTEXT 14
#defina COLOR_BTNFACE 15
#defina COLOR_BTNSHADOW 16
#defina COLOR_GRAYTEXT 17
#defina COLOR_BTNTEXT 18
#defina COLOR_INACTIVECAPTIONTEXT 19
#defina COLOR_BTNHIGHLIGHT 20

#defina COLOR_3DDKSHADOW 21
#defina COLOR_3DLIGHT 22
#defina COLOR_INFOTEXT 23
#defina COLOR_INFOBK 24

#defina COLOR_HOTLIGHT 26
#defina COLOR_GRADIENTACTIVECAPTION 27
#defina COLOR_GRADIENTINACTIVECAPTION 28
#defina COLOR_MENUHILIGHT 29
#defina COLOR_MENUBAR 30

#defina COLOR_DESKTOP COLOR_BACKGROUND
#defina COLOR_3DFACE COLOR_BTNFACE
#defina COLOR_3DSHADOW COLOR_BTNSHADOW
#defina COLOR_3DHIGHLIGHT COLOR_BTNHIGHLIGHT
#defina COLOR_3DHILIGHT COLOR_BTNHIGHLIGHT
#defina COLOR_BTNHILIGHT COLOR_BTNHIGHLIGHT

  WINUSERAPI DWORD WINAPI GetSysColor(inteiro nIndex);
  WINUSERAPI HBRUSH WINAPI GetSysColorBrush(inteiro nIndex);
  WINUSERAPI WINBOOL WINAPI SetSysColors(inteiro cElements,CONST INT *lpaElements,CONST COLORREF *lpaRgbValues);
#fim_se

  WINUSERAPI WINBOOL WINAPI DrawFocusRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI inteiro WINAPI FillRect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI inteiro WINAPI FrameRect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI WINBOOL WINAPI InvertRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI SetRect(LPRECT lprc,inteiro xLeft,inteiro yTop,inteiro xRight,inteiro yBottom);
  WINUSERAPI WINBOOL WINAPI SetRectEmpty(LPRECT lprc);
  WINUSERAPI WINBOOL WINAPI CopyRect(LPRECT lprcDst,CONST RECT *lprcSrc);
  WINUSERAPI WINBOOL WINAPI InflateRect(LPRECT lprc,inteiro dx,inteiro dy);
  WINUSERAPI WINBOOL WINAPI IntersectRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI UnionRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI SubtractRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI OffsetRect(LPRECT lprc,inteiro dx,inteiro dy);
  WINUSERAPI WINBOOL WINAPI IsRectEmpty(CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI EqualRect(CONST RECT *lprc1,CONST RECT *lprc2);
  WINUSERAPI WINBOOL WINAPI PtInRect(CONST RECT *lprc,POINT pt);

#se_não_definido NOWINOFFSETS

#se_definido UNICODE
#defina GetWindowLong GetWindowLongW
#defina SetWindowLong SetWindowLongW
#senão
#defina GetWindowLong GetWindowLongA
#defina SetWindowLong SetWindowLongA
#fim_se

  WINUSERAPI WORD WINAPI GetWindowWord(HWND hWnd,inteiro nIndex);
  WINUSERAPI WORD WINAPI SetWindowWord(HWND hWnd,inteiro nIndex,WORD wNewWord);
  WINUSERAPI LONG WINAPI GetWindowLongA(HWND hWnd,inteiro nIndex);
  WINUSERAPI LONG WINAPI GetWindowLongW(HWND hWnd,inteiro nIndex);
  WINUSERAPI LONG WINAPI SetWindowLongA(HWND hWnd,inteiro nIndex,LONG dwNewLong);
  WINUSERAPI LONG WINAPI SetWindowLongW(HWND hWnd,inteiro nIndex,LONG dwNewLong);

#se_definido _WIN64

#se_definido UNICODE
#defina GetWindowLongPtr GetWindowLongPtrW
#defina SetWindowLongPtr SetWindowLongPtrW
#senão
#defina GetWindowLongPtr GetWindowLongPtrA
#defina SetWindowLongPtr SetWindowLongPtrA
#fim_se

  WINUSERAPI LONG_PTR WINAPI GetWindowLongPtrA(HWND hWnd,inteiro nIndex);
  WINUSERAPI LONG_PTR WINAPI GetWindowLongPtrW(HWND hWnd,inteiro nIndex);
  WINUSERAPI LONG_PTR WINAPI SetWindowLongPtrA(HWND hWnd,inteiro nIndex,LONG_PTR dwNewLong);
  WINUSERAPI LONG_PTR WINAPI SetWindowLongPtrW(HWND hWnd,inteiro nIndex,LONG_PTR dwNewLong);
#senão

#se_definido UNICODE
#defina GetWindowLongPtr GetWindowLongPtrW
#defina SetWindowLongPtr SetWindowLongPtrW
#senão
#defina GetWindowLongPtr GetWindowLongPtrA
#defina SetWindowLongPtr SetWindowLongPtrA
#fim_se

#defina GetWindowLongPtrA GetWindowLongA
#defina GetWindowLongPtrW GetWindowLongW
#defina SetWindowLongPtrA SetWindowLongA
#defina SetWindowLongPtrW SetWindowLongW
#fim_se

#se_definido UNICODE
#defina GetClassLong GetClassLongW
#defina SetClassLong SetClassLongW
#senão
#defina GetClassLong GetClassLongA
#defina SetClassLong SetClassLongA
#fim_se

  WINUSERAPI WORD WINAPI GetClassWord(HWND hWnd,inteiro nIndex);
  WINUSERAPI WORD WINAPI SetClassWord(HWND hWnd,inteiro nIndex,WORD wNewWord);
  WINUSERAPI DWORD WINAPI GetClassLongA(HWND hWnd,inteiro nIndex);
  WINUSERAPI DWORD WINAPI GetClassLongW(HWND hWnd,inteiro nIndex);
  WINUSERAPI DWORD WINAPI SetClassLongA(HWND hWnd,inteiro nIndex,LONG dwNewLong);
  WINUSERAPI DWORD WINAPI SetClassLongW(HWND hWnd,inteiro nIndex,LONG dwNewLong);

#se_definido _WIN64

#se_definido UNICODE
#defina GetClassLongPtr GetClassLongPtrW
#defina SetClassLongPtr SetClassLongPtrW
#senão
#defina GetClassLongPtr GetClassLongPtrA
#defina SetClassLongPtr SetClassLongPtrA
#fim_se

  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrA(HWND hWnd,inteiro nIndex);
  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrW(HWND hWnd,inteiro nIndex);
  WINUSERAPI ULONG_PTR WINAPI SetClassLongPtrA(HWND hWnd,inteiro nIndex,LONG_PTR dwNewLong);
  WINUSERAPI ULONG_PTR WINAPI SetClassLongPtrW(HWND hWnd,inteiro nIndex,LONG_PTR dwNewLong);
#senão
#se_definido UNICODE
#defina GetClassLongPtr GetClassLongPtrW
#defina SetClassLongPtr SetClassLongPtrW
#senão
#defina GetClassLongPtr GetClassLongPtrA
#defina SetClassLongPtr SetClassLongPtrA
#fim_se

#defina GetClassLongPtrA GetClassLongA
#defina GetClassLongPtrW GetClassLongW
#defina SetClassLongPtrA SetClassLongA
#defina SetClassLongPtrW SetClassLongW
#fim_se
#fim_se

#se_definido UNICODE
#defina FindWindow FindWindowW
#defina FindWindowEx FindWindowExW
#defina GetClassName GetClassNameW
#senão
#defina FindWindow FindWindowA
#defina FindWindowEx FindWindowExA
#defina GetClassName GetClassNameA
#fim_se

  WINUSERAPI WINBOOL WINAPI GetProcessDefaultLayout(DWORD *pdwDefaultLayout);
  WINUSERAPI WINBOOL WINAPI SetProcessDefaultLayout(DWORD dwDefaultLayout);
  WINUSERAPI HWND WINAPI GetDesktopWindow(VOID);
  WINUSERAPI HWND WINAPI GetParent(HWND hWnd);
  WINUSERAPI HWND WINAPI SetParent(HWND hWndChild,HWND hWndNewParent);
  WINUSERAPI WINBOOL WINAPI EnumChildWindows(HWND hWndParent,WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI HWND WINAPI FindWindowA(LPCSTR lpClassName,LPCSTR lpWindowName);
  WINUSERAPI HWND WINAPI FindWindowW(LPCWSTR lpClassName,LPCWSTR lpWindowName);
  WINUSERAPI HWND WINAPI FindWindowExA(HWND hWndParent,HWND hWndChildAfter,LPCSTR lpszClass,LPCSTR lpszWindow);
  WINUSERAPI HWND WINAPI FindWindowExW(HWND hWndParent,HWND hWndChildAfter,LPCWSTR lpszClass,LPCWSTR lpszWindow);
  WINUSERAPI HWND WINAPI GetShellWindow(VOID);
  WINUSERAPI WINBOOL WINAPI RegisterShellHookWindow(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI DeregisterShellHookWindow(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI EnumWindows(WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam);

#defina EnumTaskWindows(hTask,lpfn,lParam) EnumThreadWindows(HandleToUlong(hTask),lpfn,lParam)

  WINUSERAPI inteiro WINAPI GetClassNameA(HWND hWnd,LPSTR lpClassName,inteiro nMaxCount);
  WINUSERAPI inteiro WINAPI GetClassNameW(HWND hWnd,LPWSTR lpClassName,inteiro nMaxCount);
  WINUSERAPI HWND WINAPI GetTopWindow(HWND hWnd);

#defina GetNextWindow(hWnd,wCmd) GetWindow(hWnd,wCmd)
#defina GetSysModalWindow() (NULL)
#defina SetSysModalWindow(hWnd) (NULL)

  WINUSERAPI DWORD WINAPI GetWindowThreadProcessId(HWND hWnd,LPDWORD lpdwProcessId);
  WINUSERAPI WINBOOL WINAPI IsGUIThread(WINBOOL bConvert);

#defina GetWindowTask(hWnd) ((HANDLE)(DWORD_PTR)GetWindowThreadProcessId(hWnd,NULL))

  WINUSERAPI HWND WINAPI GetLastActivePopup(HWND hWnd);

#defina GW_HWNDFIRST 0
#defina GW_HWNDLAST 1
#defina GW_HWNDNEXT 2
#defina GW_HWNDPREV 3
#defina GW_OWNER 4
#defina GW_CHILD 5
#defina GW_ENABLEDPOPUP 6
#defina GW_MAX 6

  WINUSERAPI HWND WINAPI GetWindow(HWND hWnd,UINT uCmd);

#se_não_definido NOWH

#se_definido UNICODE
#defina SetWindowsHook SetWindowsHookW
#defina SetWindowsHookEx SetWindowsHookExW
#senão
#defina SetWindowsHook SetWindowsHookA
#defina SetWindowsHookEx SetWindowsHookExA
#fim_se

  WINUSERAPI HHOOK WINAPI SetWindowsHookA(inteiro nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI SetWindowsHookW(inteiro nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHook(inteiro nCode,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI SetWindowsHookExA(inteiro idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI HHOOK WINAPI SetWindowsHookExW(inteiro idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHookEx(HHOOK hhk);
  WINUSERAPI LRESULT WINAPI CallNextHookEx(HHOOK hhk,inteiro nCode,WPARAM wParam,LPARAM lParam);
#defina DefHookProc(nCode,wParam,lParam,phhk) CallNextHookEx(*phhk,nCode,wParam,lParam)
#fim_se

#se_não_definido NOMENUS

#defina MF_INSERT 0x00000000L
#defina MF_CHANGE 0x00000080L
#defina MF_APPEND 0x00000100L
#defina MF_DELETE 0x00000200L
#defina MF_REMOVE 0x00001000L
#defina MF_BYCOMMAND 0x00000000L
#defina MF_BYPOSITION 0x00000400L
#defina MF_SEPARATOR 0x00000800L
#defina MF_ENABLED 0x00000000L
#defina MF_GRAYED 0x00000001L
#defina MF_DISABLED 0x00000002L
#defina MF_UNCHECKED 0x00000000L
#defina MF_CHECKED 0x00000008L
#defina MF_USECHECKBITMAPS 0x00000200L
#defina MF_STRING 0x00000000L
#defina MF_BITMAP 0x00000004L
#defina MF_OWNERDRAW 0x00000100L
#defina MF_POPUP 0x00000010L
#defina MF_MENUBARBREAK 0x00000020L
#defina MF_MENUBREAK 0x00000040L
#defina MF_UNHILITE 0x00000000L
#defina MF_HILITE 0x00000080L
#defina MF_DEFAULT 0x00001000L
#defina MF_SYSMENU 0x00002000L
#defina MF_HELP 0x00004000L
#defina MF_RIGHTJUSTIFY 0x00004000L
#defina MF_MOUSESELECT 0x00008000L
#defina MF_END 0x00000080L

#defina MFT_STRING MF_STRING
#defina MFT_BITMAP MF_BITMAP
#defina MFT_MENUBARBREAK MF_MENUBARBREAK
#defina MFT_MENUBREAK MF_MENUBREAK
#defina MFT_OWNERDRAW MF_OWNERDRAW
#defina MFT_RADIOCHECK 0x00000200L
#defina MFT_SEPARATOR MF_SEPARATOR
#defina MFT_RIGHTORDER 0x00002000L
#defina MFT_RIGHTJUSTIFY MF_RIGHTJUSTIFY

#defina MFS_GRAYED 0x00000003L
#defina MFS_DISABLED MFS_GRAYED
#defina MFS_CHECKED MF_CHECKED
#defina MFS_HILITE MF_HILITE
#defina MFS_ENABLED MF_ENABLED
#defina MFS_UNCHECKED MF_UNCHECKED
#defina MFS_UNHILITE MF_UNHILITE
#defina MFS_DEFAULT MF_DEFAULT

  WINUSERAPI WINBOOL WINAPI CheckMenuRadioItem(HMENU hmenu,UINT first,UINT last,UINT check,UINT flags);

  defina_tipo estrutura {
    WORD versionNumber;
    WORD offset;
  } MENUITEMTEMPLATEHEADER,*PMENUITEMTEMPLATEHEADER;

  defina_tipo estrutura {
    WORD mtOption;
    WORD mtID;
    WCHAR mtString[1];
  } MENUITEMTEMPLATE,*PMENUITEMTEMPLATE;
#defina MF_END 0x00000080L
#fim_se

#se_não_definido NOSYSCOMMANDS

#defina SC_SIZE 0xF000
#defina SC_MOVE 0xF010
#defina SC_MINIMIZE 0xF020
#defina SC_MAXIMIZE 0xF030
#defina SC_NEXTWINDOW 0xF040
#defina SC_PREVWINDOW 0xF050
#defina SC_CLOSE 0xF060
#defina SC_VSCROLL 0xF070
#defina SC_HSCROLL 0xF080
#defina SC_MOUSEMENU 0xF090
#defina SC_KEYMENU 0xF100
#defina SC_ARRANGE 0xF110
#defina SC_RESTORE 0xF120
#defina SC_TASKLIST 0xF130
#defina SC_SCREENSAVE 0xF140
#defina SC_HOTKEY 0xF150
#defina SC_DEFAULT 0xF160
#defina SC_MONITORPOWER 0xF170
#defina SC_CONTEXTHELP 0xF180
#defina SC_SEPARATOR 0xF00F
#defina SC_ICON SC_MINIMIZE
#defina SC_ZOOM SC_MAXIMIZE
#fim_se

#se_definido UNICODE
#defina LoadBitmap LoadBitmapW
#defina LoadCursor LoadCursorW
#defina LoadCursorFromFile LoadCursorFromFileW
#senão
#defina LoadBitmap LoadBitmapA
#defina LoadCursor LoadCursorA
#defina LoadCursorFromFile LoadCursorFromFileA
#fim_se

  WINUSERAPI HBITMAP WINAPI LoadBitmapA(HINSTANCE hInstance,LPCSTR lpBitmapName);
  WINUSERAPI HBITMAP WINAPI LoadBitmapW(HINSTANCE hInstance,LPCWSTR lpBitmapName);
  WINUSERAPI HCURSOR WINAPI LoadCursorA(HINSTANCE hInstance,LPCSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI LoadCursorW(HINSTANCE hInstance,LPCWSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI LoadCursorFromFileA(LPCSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI LoadCursorFromFileW(LPCWSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI CreateCursor(HINSTANCE hInst,inteiro xHotSpot,inteiro yHotSpot,inteiro nWidth,inteiro nHeight,CONST VOID *pvANDPlane,CONST VOID *pvXORPlane);
  WINUSERAPI WINBOOL WINAPI DestroyCursor(HCURSOR hCursor);

#defina CopyCursor(pcur) ((HCURSOR)CopyIcon((HICON)(pcur)))

#defina IDC_ARROW MAKEINTRESOURCE(32512)
#defina IDC_IBEAM MAKEINTRESOURCE(32513)
#defina IDC_WAIT MAKEINTRESOURCE(32514)
#defina IDC_CROSS MAKEINTRESOURCE(32515)
#defina IDC_UPARROW MAKEINTRESOURCE(32516)
#defina IDC_SIZE MAKEINTRESOURCE(32640)
#defina IDC_ICON MAKEINTRESOURCE(32641)
#defina IDC_SIZENWSE MAKEINTRESOURCE(32642)
#defina IDC_SIZENESW MAKEINTRESOURCE(32643)
#defina IDC_SIZEWE MAKEINTRESOURCE(32644)
#defina IDC_SIZENS MAKEINTRESOURCE(32645)
#defina IDC_SIZEALL MAKEINTRESOURCE(32646)
#defina IDC_NO MAKEINTRESOURCE(32648)
#defina IDC_HAND MAKEINTRESOURCE(32649)
#defina IDC_APPSTARTING MAKEINTRESOURCE(32650)
#defina IDC_HELP MAKEINTRESOURCE(32651)

  WINUSERAPI WINBOOL WINAPI SetSystemCursor(HCURSOR hcur,DWORD id);

  defina_tipo estrutura _ICONINFO {
    WINBOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbmMask;
    HBITMAP hbmColor;
  } ICONINFO;
  defina_tipo ICONINFO *PICONINFO;

#se_definido UNICODE
#defina LoadIcon LoadIconW
#defina PrivateExtractIcons PrivateExtractIconsW
#senão
#defina LoadIcon LoadIconA
#defina PrivateExtractIcons PrivateExtractIconsA
#fim_se

  WINUSERAPI HICON WINAPI LoadIconA(HINSTANCE hInstance,LPCSTR lpIconName);
  WINUSERAPI HICON WINAPI LoadIconW(HINSTANCE hInstance,LPCWSTR lpIconName);
  WINUSERAPI UINT WINAPI PrivateExtractIconsA(LPCSTR szFileName,inteiro nIconIndex,inteiro cxIcon,inteiro cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI UINT WINAPI PrivateExtractIconsW(LPCWSTR szFileName,inteiro nIconIndex,inteiro cxIcon,inteiro cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI HICON WINAPI CreateIcon(HINSTANCE hInstance,inteiro nWidth,inteiro nHeight,BYTE cPlanes,BYTE cBitsPixel,CONST BYTE *lpbANDbits,CONST BYTE *lpbXORbits);
  WINUSERAPI WINBOOL WINAPI DestroyIcon(HICON hIcon);
  WINUSERAPI inteiro WINAPI LookupIconIdFromDirectory(PBYTE presbits,WINBOOL fIcon);
  WINUSERAPI inteiro WINAPI LookupIconIdFromDirectoryEx(PBYTE presbits,WINBOOL fIcon,inteiro cxDesired,inteiro cyDesired,UINT Flags);
  WINUSERAPI HICON WINAPI CreateIconFromResource(PBYTE presbits,DWORD dwResSize,WINBOOL fIcon,DWORD dwVer);
  WINUSERAPI HICON WINAPI CreateIconFromResourceEx(PBYTE presbits,DWORD dwResSize,WINBOOL fIcon,DWORD dwVer,inteiro cxDesired,inteiro cyDesired,UINT Flags);

  defina_tipo estrutura tagCURSORSHAPE {
    inteiro xHotSpot;
    inteiro yHotSpot;
    inteiro cx;
    inteiro cy;
    inteiro cbWidth;
    BYTE Planes;
    BYTE BitsPixel;
  } CURSORSHAPE,*LPCURSORSHAPE;

#defina IMAGE_BITMAP 0
#defina IMAGE_ICON 1
#defina IMAGE_CURSOR 2
#defina IMAGE_ENHMETAFILE 3

#defina LR_DEFAULTCOLOR 0x0000
#defina LR_MONOCHROME 0x0001
#defina LR_COLOR 0x0002
#defina LR_COPYRETURNORG 0x0004
#defina LR_COPYDELETEORG 0x0008
#defina LR_LOADFROMFILE 0x0010
#defina LR_LOADTRANSPARENT 0x0020
#defina LR_DEFAULTSIZE 0x0040
#defina LR_VGACOLOR 0x0080
#defina LR_LOADMAP3DCOLORS 0x1000
#defina LR_CREATEDIBSECTION 0x2000
#defina LR_COPYFROMRESOURCE 0x4000
#defina LR_SHARED 0x8000

#se_definido UNICODE
#defina LoadImage LoadImageW
#senão
#defina LoadImage LoadImageA
#fim_se

  WINUSERAPI HANDLE WINAPI LoadImageA(HINSTANCE hInst,LPCSTR name,UINT type,inteiro cx,inteiro cy,UINT fuLoad);
  WINUSERAPI HANDLE WINAPI LoadImageW(HINSTANCE hInst,LPCWSTR name,UINT type,inteiro cx,inteiro cy,UINT fuLoad);
  WINUSERAPI HANDLE WINAPI CopyImage(HANDLE h,UINT type,inteiro cx,inteiro cy,UINT flags);

#defina DI_MASK 0x0001
#defina DI_IMAGE 0x0002
#defina DI_NORMAL 0x0003
#defina DI_COMPAT 0x0004
#defina DI_DEFAULTSIZE 0x0008
#defina DI_NOMIRROR 0x0010

  WINUSERAPI WINBOOL WINAPI DrawIconEx(HDC hdc,inteiro xLeft,inteiro yTop,HICON hIcon,inteiro cxWidth,inteiro cyWidth,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags);
  WINUSERAPI HICON WINAPI CreateIconIndirect(PICONINFO piconinfo);
  WINUSERAPI HICON WINAPI CopyIcon(HICON hIcon);
  WINUSERAPI WINBOOL WINAPI GetIconInfo(HICON hIcon,PICONINFO piconinfo);

#defina RES_ICON 1
#defina RES_CURSOR 2

#se_definido OEMRESOURCE

#defina OBM_CLOSE 32754
#defina OBM_UPARROW 32753
#defina OBM_DNARROW 32752
#defina OBM_RGARROW 32751
#defina OBM_LFARROW 32750
#defina OBM_REDUCE 32749
#defina OBM_ZOOM 32748
#defina OBM_RESTORE 32747
#defina OBM_REDUCED 32746
#defina OBM_ZOOMD 32745
#defina OBM_RESTORED 32744
#defina OBM_UPARROWD 32743
#defina OBM_DNARROWD 32742
#defina OBM_RGARROWD 32741
#defina OBM_LFARROWD 32740
#defina OBM_MNARROW 32739
#defina OBM_COMBO 32738
#defina OBM_UPARROWI 32737
#defina OBM_DNARROWI 32736
#defina OBM_RGARROWI 32735
#defina OBM_LFARROWI 32734

#defina OBM_OLD_CLOSE 32767
#defina OBM_SIZE 32766
#defina OBM_OLD_UPARROW 32765
#defina OBM_OLD_DNARROW 32764
#defina OBM_OLD_RGARROW 32763
#defina OBM_OLD_LFARROW 32762
#defina OBM_BTSIZE 32761
#defina OBM_CHECK 32760
#defina OBM_CHECKBOXES 32759
#defina OBM_BTNCORNERS 32758
#defina OBM_OLD_REDUCE 32757
#defina OBM_OLD_ZOOM 32756
#defina OBM_OLD_RESTORE 32755

#defina OCR_NORMAL 32512
#defina OCR_IBEAM 32513
#defina OCR_WAIT 32514
#defina OCR_CROSS 32515
#defina OCR_UP 32516
#defina OCR_SIZE 32640
#defina OCR_ICON 32641
#defina OCR_SIZENWSE 32642
#defina OCR_SIZENESW 32643
#defina OCR_SIZEWE 32644
#defina OCR_SIZENS 32645
#defina OCR_SIZEALL 32646
#defina OCR_ICOCUR 32647
#defina OCR_NO 32648
#defina OCR_HAND 32649
#defina OCR_APPSTARTING 32650

#defina OIC_SAMPLE 32512
#defina OIC_HAND 32513
#defina OIC_QUES 32514
#defina OIC_BANG 32515
#defina OIC_NOTE 32516
#defina OIC_WINLOGO 32517
#defina OIC_WARNING OIC_BANG
#defina OIC_ERROR OIC_HAND
#defina OIC_INFORMATION OIC_NOTE
#fim_se

#defina ORD_LANGDRIVER 1

#se_não_definido NOICONS

#se_definido RC_INVOKED
#defina IDI_APPLICATION 32512
#defina IDI_HAND 32513
#defina IDI_QUESTION 32514
#defina IDI_EXCLAMATION 32515
#defina IDI_ASTERISK 32516
#defina IDI_WINLOGO 32517
#senão
#defina IDI_APPLICATION MAKEINTRESOURCE(32512)
#defina IDI_HAND MAKEINTRESOURCE(32513)
#defina IDI_QUESTION MAKEINTRESOURCE(32514)
#defina IDI_EXCLAMATION MAKEINTRESOURCE(32515)
#defina IDI_ASTERISK MAKEINTRESOURCE(32516)
#defina IDI_WINLOGO MAKEINTRESOURCE(32517)
#fim_se

#defina IDI_WARNING IDI_EXCLAMATION
#defina IDI_ERROR IDI_HAND
#defina IDI_INFORMATION IDI_ASTERISK
#fim_se

#se_definido UNICODE
#defina LoadString LoadStringW
#senão
#defina LoadString LoadStringA
#fim_se

  WINUSERAPI inteiro WINAPI LoadStringA(HINSTANCE hInstance,UINT uID,LPSTR lpBuffer,inteiro cchBufferMax);
  WINUSERAPI inteiro WINAPI LoadStringW(HINSTANCE hInstance,UINT uID,LPWSTR lpBuffer,inteiro cchBufferMax);

#defina IDOK 1
#defina IDCANCEL 2
#defina IDABORT 3
#defina IDRETRY 4
#defina IDIGNORE 5
#defina IDYES 6
#defina IDNO 7
#defina IDCLOSE 8
#defina IDHELP 9
#defina IDTRYAGAIN 10
#defina IDCONTINUE 11

#se_não_definido IDTIMEOUT
#defina IDTIMEOUT 32000
#fim_se

#se_não_definido NOCTLMGR

#se_não_definido NOWINSTYLES
#defina ES_LEFT 0x0000L
#defina ES_CENTER 0x0001L
#defina ES_RIGHT 0x0002L
#defina ES_MULTILINE 0x0004L
#defina ES_UPPERCASE 0x0008L
#defina ES_LOWERCASE 0x0010L
#defina ES_PASSWORD 0x0020L
#defina ES_AUTOVSCROLL 0x0040L
#defina ES_AUTOHSCROLL 0x0080L
#defina ES_NOHIDESEL 0x0100L
#defina ES_OEMCONVERT 0x0400L
#defina ES_READONLY 0x0800L
#defina ES_WANTRETURN 0x1000L
#defina ES_NUMBER 0x2000L
#fim_se

#defina EN_SETFOCUS 0x0100
#defina EN_KILLFOCUS 0x0200
#defina EN_CHANGE 0x0300
#defina EN_UPDATE 0x0400
#defina EN_ERRSPACE 0x0500
#defina EN_MAXTEXT 0x0501
#defina EN_HSCROLL 0x0601
#defina EN_VSCROLL 0x0602
#defina EN_ALIGN_LTR_EC 0x0700
#defina EN_ALIGN_RTL_EC 0x0701

#defina EC_LEFTMARGIN 0x0001
#defina EC_RIGHTMARGIN 0x0002
#defina EC_USEFONTINFO 0xffff

#defina EMSIS_COMPOSITIONSTRING 0x0001

#defina EIMES_GETCOMPSTRATONCE 0x0001
#defina EIMES_CANCELCOMPSTRINFOCUS 0x0002
#defina EIMES_COMPLETECOMPSTRKILLFOCUS 0x0004

#se_não_definido NOWINMESSAGES

#defina EM_GETSEL 0x00B0
#defina EM_SETSEL 0x00B1
#defina EM_GETRECT 0x00B2
#defina EM_SETRECT 0x00B3
#defina EM_SETRECTNP 0x00B4
#defina EM_SCROLL 0x00B5
#defina EM_LINESCROLL 0x00B6
#defina EM_SCROLLCARET 0x00B7
#defina EM_GETMODIFY 0x00B8
#defina EM_SETMODIFY 0x00B9
#defina EM_GETLINECOUNT 0x00BA
#defina EM_LINEINDEX 0x00BB
#defina EM_SETHANDLE 0x00BC
#defina EM_GETHANDLE 0x00BD
#defina EM_GETTHUMB 0x00BE
#defina EM_LINELENGTH 0x00C1
#defina EM_REPLACESEL 0x00C2
#defina EM_GETLINE 0x00C4
#defina EM_LIMITTEXT 0x00C5
#defina EM_CANUNDO 0x00C6
#defina EM_UNDO 0x00C7
#defina EM_FMTLINES 0x00C8
#defina EM_LINEFROMCHAR 0x00C9
#defina EM_SETTABSTOPS 0x00CB
#defina EM_SETPASSWORDCHAR 0x00CC
#defina EM_EMPTYUNDOBUFFER 0x00CD
#defina EM_GETFIRSTVISIBLELINE 0x00CE
#defina EM_SETREADONLY 0x00CF
#defina EM_SETWORDBREAKPROC 0x00D0
#defina EM_GETWORDBREAKPROC 0x00D1
#defina EM_GETPASSWORDCHAR 0x00D2
#defina EM_SETMARGINS 0x00D3
#defina EM_GETMARGINS 0x00D4
#defina EM_SETLIMITTEXT EM_LIMITTEXT
#defina EM_GETLIMITTEXT 0x00D5
#defina EM_POSFROMCHAR 0x00D6
#defina EM_CHARFROMPOS 0x00D7
#defina EM_SETIMESTATUS 0x00D8
#defina EM_GETIMESTATUS 0x00D9
#fim_se

#defina WB_LEFT 0
#defina WB_RIGHT 1
#defina WB_ISDELIMITER 2

#defina BS_PUSHBUTTON 0x00000000L
#defina BS_DEFPUSHBUTTON 0x00000001L
#defina BS_CHECKBOX 0x00000002L
#defina BS_AUTOCHECKBOX 0x00000003L
#defina BS_RADIOBUTTON 0x00000004L
#defina BS_3STATE 0x00000005L
#defina BS_AUTO3STATE 0x00000006L
#defina BS_GROUPBOX 0x00000007L
#defina BS_USERBUTTON 0x00000008L
#defina BS_AUTORADIOBUTTON 0x00000009L
#defina BS_PUSHBOX 0x0000000AL
#defina BS_OWNERDRAW 0x0000000BL
#defina BS_TYPEMASK 0x0000000FL
#defina BS_LEFTTEXT 0x00000020L
#defina BS_TEXT 0x00000000L
#defina BS_ICON 0x00000040L
#defina BS_BITMAP 0x00000080L
#defina BS_LEFT 0x00000100L
#defina BS_RIGHT 0x00000200L
#defina BS_CENTER 0x00000300L
#defina BS_TOP 0x00000400L
#defina BS_BOTTOM 0x00000800L
#defina BS_VCENTER 0x00000C00L
#defina BS_PUSHLIKE 0x00001000L
#defina BS_MULTILINE 0x00002000L
#defina BS_NOTIFY 0x00004000L
#defina BS_FLAT 0x00008000L
#defina BS_RIGHTBUTTON BS_LEFTTEXT

#defina BN_CLICKED 0
#defina BN_PAINT 1
#defina BN_HILITE 2
#defina BN_UNHILITE 3
#defina BN_DISABLE 4
#defina BN_DOUBLECLICKED 5
#defina BN_PUSHED BN_HILITE
#defina BN_UNPUSHED BN_UNHILITE
#defina BN_DBLCLK BN_DOUBLECLICKED
#defina BN_SETFOCUS 6
#defina BN_KILLFOCUS 7

#defina BM_GETCHECK 0x00F0
#defina BM_SETCHECK 0x00F1
#defina BM_GETSTATE 0x00F2
#defina BM_SETSTATE 0x00F3
#defina BM_SETSTYLE 0x00F4
#defina BM_CLICK 0x00F5
#defina BM_GETIMAGE 0x00F6
#defina BM_SETIMAGE 0x00F7

#defina BST_UNCHECKED 0x0000
#defina BST_CHECKED 0x0001
#defina BST_INDETERMINATE 0x0002
#defina BST_PUSHED 0x0004
#defina BST_FOCUS 0x0008

#defina SS_LEFT 0x00000000L
#defina SS_CENTER 0x00000001L
#defina SS_RIGHT 0x00000002L
#defina SS_ICON 0x00000003L
#defina SS_BLACKRECT 0x00000004L
#defina SS_GRAYRECT 0x00000005L
#defina SS_WHITERECT 0x00000006L
#defina SS_BLACKFRAME 0x00000007L
#defina SS_GRAYFRAME 0x00000008L
#defina SS_WHITEFRAME 0x00000009L
#defina SS_USERITEM 0x0000000AL
#defina SS_SIMPLE 0x0000000BL
#defina SS_LEFTNOWORDWRAP 0x0000000CL
#defina SS_OWNERDRAW 0x0000000DL
#defina SS_BITMAP 0x0000000EL
#defina SS_ENHMETAFILE 0x0000000FL
#defina SS_ETCHEDHORZ 0x00000010L
#defina SS_ETCHEDVERT 0x00000011L
#defina SS_ETCHEDFRAME 0x00000012L
#defina SS_TYPEMASK 0x0000001FL
#defina SS_REALSIZECONTROL 0x00000040L
#defina SS_NOPREFIX 0x00000080L
#defina SS_NOTIFY 0x00000100L
#defina SS_CENTERIMAGE 0x00000200L
#defina SS_RIGHTJUST 0x00000400L
#defina SS_REALSIZEIMAGE 0x00000800L
#defina SS_SUNKEN 0x00001000L
#defina SS_EDITCONTROL 0x00002000L
#defina SS_ENDELLIPSIS 0x00004000L
#defina SS_PATHELLIPSIS 0x00008000L
#defina SS_WORDELLIPSIS 0x0000C000L
#defina SS_ELLIPSISMASK 0x0000C000L

#se_não_definido NOWINMESSAGES

#defina STM_SETICON 0x0170
#defina STM_GETICON 0x0171
#defina STM_SETIMAGE 0x0172
#defina STM_GETIMAGE 0x0173
#defina STN_CLICKED 0
#defina STN_DBLCLK 1
#defina STN_ENABLE 2
#defina STN_DISABLE 3
#defina STM_MSGMAX 0x0174
#fim_se

#defina WC_DIALOG (MAKEINTATOM(0x8002))

#defina DWL_MSGRESULT 0
#defina DWL_DLGPROC 4
#defina DWL_USER 8

#se_definido _WIN64

#não_definido DWL_MSGRESULT
#não_definido DWL_DLGPROC
#não_definido DWL_USER
#fim_se

#defina DWLP_MSGRESULT 0
#defina DWLP_DLGPROC DWLP_MSGRESULT + sizeof(LRESULT)
#defina DWLP_USER DWLP_DLGPROC + sizeof(DLGPROC)

#se_não_definido NOMSG

#se_definido UNICODE
#defina IsDialogMessage IsDialogMessageW
#senão
#defina IsDialogMessage IsDialogMessageA
#fim_se

  WINUSERAPI WINBOOL WINAPI IsDialogMessageA(HWND hDlg,LPMSG lpMsg);
  WINUSERAPI WINBOOL WINAPI IsDialogMessageW(HWND hDlg,LPMSG lpMsg);
#fim_se

#se_definido UNICODE
#defina DlgDirList DlgDirListW
#defina DlgDirSelectEx DlgDirSelectExW
#defina DlgDirListComboBox DlgDirListComboBoxW
#defina DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
#senão
#defina DlgDirList DlgDirListA
#defina DlgDirSelectEx DlgDirSelectExA
#defina DlgDirListComboBox DlgDirListComboBoxA
#defina DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
#fim_se

  WINUSERAPI WINBOOL WINAPI MapDialogRect(HWND hDlg,LPRECT lpRect);
  WINUSERAPI inteiro WINAPI DlgDirListA(HWND hDlg,LPSTR lpPathSpec,inteiro nIDListBox,inteiro nIDStaticPath,UINT uFileType);
  WINUSERAPI inteiro WINAPI DlgDirListW(HWND hDlg,LPWSTR lpPathSpec,inteiro nIDListBox,inteiro nIDStaticPath,UINT uFileType);

#defina DDL_READWRITE 0x0000
#defina DDL_READONLY 0x0001
#defina DDL_HIDDEN 0x0002
#defina DDL_SYSTEM 0x0004
#defina DDL_DIRECTORY 0x0010
#defina DDL_ARCHIVE 0x0020

#defina DDL_POSTMSGS 0x2000
#defina DDL_DRIVES 0x4000
#defina DDL_EXCLUSIVE 0x8000

  WINUSERAPI WINBOOL WINAPI DlgDirSelectExA(HWND hwndDlg,LPSTR lpString,inteiro chCount,inteiro idListBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectExW(HWND hwndDlg,LPWSTR lpString,inteiro chCount,inteiro idListBox);
  WINUSERAPI inteiro WINAPI DlgDirListComboBoxA(HWND hDlg,LPSTR lpPathSpec,inteiro nIDComboBox,inteiro nIDStaticPath,UINT uFiletype);
  WINUSERAPI inteiro WINAPI DlgDirListComboBoxW(HWND hDlg,LPWSTR lpPathSpec,inteiro nIDComboBox,inteiro nIDStaticPath,UINT uFiletype);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExA(HWND hwndDlg,LPSTR lpString,inteiro cchOut,inteiro idComboBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExW(HWND hwndDlg,LPWSTR lpString,inteiro cchOut,inteiro idComboBox);

#defina DS_ABSALIGN 0x01L
#defina DS_SYSMODAL 0x02L
#defina DS_LOCALEDIT 0x20L
#defina DS_SETFONT 0x40L
#defina DS_MODALFRAME 0x80L
#defina DS_NOIDLEMSG 0x100L
#defina DS_SETFOREGROUND 0x200L

#defina DS_3DLOOK 0x0004L
#defina DS_FIXEDSYS 0x0008L
#defina DS_NOFAILCREATE 0x0010L
#defina DS_CONTROL 0x0400L
#defina DS_CENTER 0x0800L
#defina DS_CENTERMOUSE 0x1000L
#defina DS_CONTEXTHELP 0x2000L

#defina DS_SHELLFONT (DS_SETFONT | DS_FIXEDSYS)

#se(_WIN32_WCE >= 0x0500)
#defina DS_USEPIXELS 0x8000L
#fim_se

#defina DM_GETDEFID (WM_USER+0)
#defina DM_SETDEFID (WM_USER+1)
#defina DM_REPOSITION (WM_USER+2)

#defina DC_HASDEFID 0x534B

#defina DLGC_WANTARROWS 0x0001
#defina DLGC_WANTTAB 0x0002
#defina DLGC_WANTALLKEYS 0x0004
#defina DLGC_WANTMESSAGE 0x0004
#defina DLGC_HASSETSEL 0x0008
#defina DLGC_DEFPUSHBUTTON 0x0010
#defina DLGC_UNDEFPUSHBUTTON 0x0020
#defina DLGC_RADIOBUTTON 0x0040
#defina DLGC_WANTCHARS 0x0080
#defina DLGC_STATIC 0x0100
#defina DLGC_BUTTON 0x2000

#defina LB_CTLCODE 0L

#defina LB_OKAY 0
#defina LB_ERR (-1)
#defina LB_ERRSPACE (-2)

#defina LBN_ERRSPACE (-2)
#defina LBN_SELCHANGE 1
#defina LBN_DBLCLK 2
#defina LBN_SELCANCEL 3
#defina LBN_SETFOCUS 4
#defina LBN_KILLFOCUS 5

#se_não_definido NOWINMESSAGES

#defina LB_ADDSTRING 0x0180
#defina LB_INSERTSTRING 0x0181
#defina LB_DELETESTRING 0x0182
#defina LB_SELITEMRANGEEX 0x0183
#defina LB_RESETCONTENT 0x0184
#defina LB_SETSEL 0x0185
#defina LB_SETCURSEL 0x0186
#defina LB_GETSEL 0x0187
#defina LB_GETCURSEL 0x0188
#defina LB_GETTEXT 0x0189
#defina LB_GETTEXTLEN 0x018A
#defina LB_GETCOUNT 0x018B
#defina LB_SELECTSTRING 0x018C
#defina LB_DIR 0x018D
#defina LB_GETTOPINDEX 0x018E
#defina LB_FINDSTRING 0x018F
#defina LB_GETSELCOUNT 0x0190
#defina LB_GETSELITEMS 0x0191
#defina LB_SETTABSTOPS 0x0192
#defina LB_GETHORIZONTALEXTENT 0x0193
#defina LB_SETHORIZONTALEXTENT 0x0194
#defina LB_SETCOLUMNWIDTH 0x0195
#defina LB_ADDFILE 0x0196
#defina LB_SETTOPINDEX 0x0197
#defina LB_GETITEMRECT 0x0198
#defina LB_GETITEMDATA 0x0199
#defina LB_SETITEMDATA 0x019A
#defina LB_SELITEMRANGE 0x019B
#defina LB_SETANCHORINDEX 0x019C
#defina LB_GETANCHORINDEX 0x019D
#defina LB_SETCARETINDEX 0x019E
#defina LB_GETCARETINDEX 0x019F
#defina LB_SETITEMHEIGHT 0x01A0
#defina LB_GETITEMHEIGHT 0x01A1
#defina LB_FINDSTRINGEXACT 0x01A2
#defina LB_SETLOCALE 0x01A5
#defina LB_GETLOCALE 0x01A6
#defina LB_SETCOUNT 0x01A7
#defina LB_INITSTORAGE 0x01A8
#defina LB_ITEMFROMPOINT 0x01A9
#se(_WIN32_WCE >= 0x0400)
#defina LB_MULTIPLEADDSTRING 0x01B1
#fim_se
#defina LB_GETLISTBOXINFO 0x01B2
#defina LB_MSGMAX 0x01B3
#fim_se

#se_não_definido NOWINSTYLES

#defina LBS_NOTIFY 0x0001L
#defina LBS_SORT 0x0002L
#defina LBS_NOREDRAW 0x0004L
#defina LBS_MULTIPLESEL 0x0008L
#defina LBS_OWNERDRAWFIXED 0x0010L
#defina LBS_OWNERDRAWVARIABLE 0x0020L
#defina LBS_HASSTRINGS 0x0040L
#defina LBS_USETABSTOPS 0x0080L
#defina LBS_NOINTEGRALHEIGHT 0x0100L
#defina LBS_MULTICOLUMN 0x0200L
#defina LBS_WANTKEYBOARDINPUT 0x0400L
#defina LBS_EXTENDEDSEL 0x0800L
#defina LBS_DISABLENOSCROLL 0x1000L
#defina LBS_NODATA 0x2000L
#defina LBS_NOSEL 0x4000L
#defina LBS_COMBOBOX 0x8000L

#defina LBS_STANDARD (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)
#fim_se

#defina CB_OKAY 0
#defina CB_ERR (-1)
#defina CB_ERRSPACE (-2)

#defina CBN_ERRSPACE (-1)
#defina CBN_SELCHANGE 1
#defina CBN_DBLCLK 2
#defina CBN_SETFOCUS 3
#defina CBN_KILLFOCUS 4
#defina CBN_EDITCHANGE 5
#defina CBN_EDITUPDATE 6
#defina CBN_DROPDOWN 7
#defina CBN_CLOSEUP 8
#defina CBN_SELENDOK 9
#defina CBN_SELENDCANCEL 10

#se_não_definido NOWINSTYLES

#defina CBS_SIMPLE 0x0001L
#defina CBS_DROPDOWN 0x0002L
#defina CBS_DROPDOWNLIST 0x0003L
#defina CBS_OWNERDRAWFIXED 0x0010L
#defina CBS_OWNERDRAWVARIABLE 0x0020L
#defina CBS_AUTOHSCROLL 0x0040L
#defina CBS_OEMCONVERT 0x0080L
#defina CBS_SORT 0x0100L
#defina CBS_HASSTRINGS 0x0200L
#defina CBS_NOINTEGRALHEIGHT 0x0400L
#defina CBS_DISABLENOSCROLL 0x0800L
#defina CBS_UPPERCASE 0x2000L
#defina CBS_LOWERCASE 0x4000L
#fim_se

#se_não_definido NOWINMESSAGES
#defina CB_GETEDITSEL 0x0140
#defina CB_LIMITTEXT 0x0141
#defina CB_SETEDITSEL 0x0142
#defina CB_ADDSTRING 0x0143
#defina CB_DELETESTRING 0x0144
#defina CB_DIR 0x0145
#defina CB_GETCOUNT 0x0146
#defina CB_GETCURSEL 0x0147
#defina CB_GETLBTEXT 0x0148
#defina CB_GETLBTEXTLEN 0x0149
#defina CB_INSERTSTRING 0x014A
#defina CB_RESETCONTENT 0x014B
#defina CB_FINDSTRING 0x014C
#defina CB_SELECTSTRING 0x014D
#defina CB_SETCURSEL 0x014E
#defina CB_SHOWDROPDOWN 0x014F
#defina CB_GETITEMDATA 0x0150
#defina CB_SETITEMDATA 0x0151
#defina CB_GETDROPPEDCONTROLRECT 0x0152
#defina CB_SETITEMHEIGHT 0x0153
#defina CB_GETITEMHEIGHT 0x0154
#defina CB_SETEXTENDEDUI 0x0155
#defina CB_GETEXTENDEDUI 0x0156
#defina CB_GETDROPPEDSTATE 0x0157
#defina CB_FINDSTRINGEXACT 0x0158
#defina CB_SETLOCALE 0x0159
#defina CB_GETLOCALE 0x015A
#defina CB_GETTOPINDEX 0x015b
#defina CB_SETTOPINDEX 0x015c
#defina CB_GETHORIZONTALEXTENT 0x015d
#defina CB_SETHORIZONTALEXTENT 0x015e
#defina CB_GETDROPPEDWIDTH 0x015f
#defina CB_SETDROPPEDWIDTH 0x0160
#defina CB_INITSTORAGE 0x0161
#se(_WIN32_WCE >= 0x0400)
#defina CB_MULTIPLEADDSTRING 0x0163
#fim_se
#defina CB_GETCOMBOBOXINFO 0x0164
#defina CB_MSGMAX 0x0165
#fim_se

#se_não_definido NOWINSTYLES

#defina SBS_HORZ 0x0000L
#defina SBS_VERT 0x0001L
#defina SBS_TOPALIGN 0x0002L
#defina SBS_LEFTALIGN 0x0002L
#defina SBS_BOTTOMALIGN 0x0004L
#defina SBS_RIGHTALIGN 0x0004L
#defina SBS_SIZEBOXTOPLEFTALIGN 0x0002L
#defina SBS_SIZEBOXBOTTOMRIGHTALIGN 0x0004L
#defina SBS_SIZEBOX 0x0008L
#defina SBS_SIZEGRIP 0x0010L
#fim_se

#se_não_definido NOWINMESSAGES
#defina SBM_SETPOS 0x00E0
#defina SBM_GETPOS 0x00E1
#defina SBM_SETRANGE 0x00E2
#defina SBM_SETRANGEREDRAW 0x00E6
#defina SBM_GETRANGE 0x00E3
#defina SBM_ENABLE_ARROWS 0x00E4
#defina SBM_SETSCROLLINFO 0x00E9
#defina SBM_GETSCROLLINFO 0x00EA
#defina SBM_GETSCROLLBARINFO 0x00EB

#defina SIF_RANGE 0x0001
#defina SIF_PAGE 0x0002
#defina SIF_POS 0x0004
#defina SIF_DISABLENOSCROLL 0x0008
#defina SIF_TRACKPOS 0x0010
#defina SIF_ALL (SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS)

  defina_tipo estrutura tagSCROLLINFO {
    UINT cbSize;
    UINT fMask;
    inteiro nMin;
    inteiro nMax;
    UINT nPage;
    inteiro nPos;
    inteiro nTrackPos;
  } SCROLLINFO,*LPSCROLLINFO;
  defina_tipo SCROLLINFO CONST *LPCSCROLLINFO;

  WINUSERAPI inteiro WINAPI SetScrollInfo(HWND hwnd,inteiro nBar,LPCSCROLLINFO lpsi,WINBOOL redraw);
  WINUSERAPI WINBOOL WINAPI GetScrollInfo(HWND hwnd,inteiro nBar,LPSCROLLINFO lpsi);
#fim_se
#fim_se

#se_não_definido NOMDI

#defina MDIS_ALLCHILDSTYLES 0x0001

#defina MDITILE_VERTICAL 0x0000
#defina MDITILE_HORIZONTAL 0x0001
#defina MDITILE_SKIPDISABLED 0x0002
#defina MDITILE_ZORDER 0x0004

  defina_tipo estrutura tagMDICREATESTRUCTA {
    LPCSTR szClass;
    LPCSTR szTitle;
    HANDLE hOwner;
    inteiro x;
    inteiro y;
    inteiro cx;
    inteiro cy;
    DWORD style;
    LPARAM lParam;
  } MDICREATESTRUCTA,*LPMDICREATESTRUCTA;

  defina_tipo estrutura tagMDICREATESTRUCTW {
    LPCWSTR szClass;
    LPCWSTR szTitle;
    HANDLE hOwner;
    inteiro x;
    inteiro y;
    inteiro cx;
    inteiro cy;
    DWORD style;
    LPARAM lParam;
  } MDICREATESTRUCTW,*LPMDICREATESTRUCTW;

#se_definido UNICODE
  defina_tipo MDICREATESTRUCTW MDICREATESTRUCT;
  defina_tipo LPMDICREATESTRUCTW LPMDICREATESTRUCT;
#senão
  defina_tipo MDICREATESTRUCTA MDICREATESTRUCT;
  defina_tipo LPMDICREATESTRUCTA LPMDICREATESTRUCT;
#fim_se

  defina_tipo estrutura tagCLIENTCREATESTRUCT {
    HANDLE hWindowMenu;
    UINT idFirstChild;
  } CLIENTCREATESTRUCT,*LPCLIENTCREATESTRUCT;

#se_definido UNICODE
#defina DefFrameProc DefFrameProcW
#defina DefMDIChildProc DefMDIChildProcW
#defina CreateMDIWindow CreateMDIWindowW
#senão
#defina DefFrameProc DefFrameProcA
#defina DefMDIChildProc DefMDIChildProcA
#defina CreateMDIWindow CreateMDIWindowA
#fim_se

  WINUSERAPI LRESULT WINAPI DefFrameProcA(HWND hWnd,HWND hWndMDIClient,UINT uMsg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefFrameProcW(HWND hWnd,HWND hWndMDIClient,UINT uMsg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcA(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcW(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);

#se_não_definido NOMSG
  WINUSERAPI WINBOOL WINAPI TranslateMDISysAccel(HWND hWndClient,LPMSG lpMsg);
#fim_se

  WINUSERAPI UINT WINAPI ArrangeIconicWindows(HWND hWnd);
  WINUSERAPI HWND WINAPI CreateMDIWindowA(LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,inteiro X,inteiro Y,inteiro nWidth,inteiro nHeight,HWND hWndParent,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI HWND WINAPI CreateMDIWindowW(LPCWSTR lpClassName,LPCWSTR lpWindowName,DWORD dwStyle,inteiro X,inteiro Y,inteiro nWidth,inteiro nHeight,HWND hWndParent,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI WORD WINAPI TileWindows(HWND hwndParent,UINT wHow,CONST RECT *lpRect,UINT cKids,constante HWND *lpKids);
  WINUSERAPI WORD WINAPI CascadeWindows(HWND hwndParent,UINT wHow,CONST RECT *lpRect,UINT cKids,constante HWND *lpKids);
#fim_se
#fim_se

#se_não_definido NOHELP

  defina_tipo DWORD HELPPOLY;
  defina_tipo estrutura tagMULTIKEYHELPA {
    DWORD mkSize;
    CHAR mkKeylist;
    CHAR szKeyphrase[1];
  } MULTIKEYHELPA,*PMULTIKEYHELPA,*LPMULTIKEYHELPA;

  defina_tipo estrutura tagMULTIKEYHELPW {
    DWORD mkSize;
    WCHAR mkKeylist;
    WCHAR szKeyphrase[1];
  } MULTIKEYHELPW,*PMULTIKEYHELPW,*LPMULTIKEYHELPW;

#se_definido UNICODE
  defina_tipo MULTIKEYHELPW MULTIKEYHELP;
  defina_tipo PMULTIKEYHELPW PMULTIKEYHELP;
  defina_tipo LPMULTIKEYHELPW LPMULTIKEYHELP;
#senão
  defina_tipo MULTIKEYHELPA MULTIKEYHELP;
  defina_tipo PMULTIKEYHELPA PMULTIKEYHELP;
  defina_tipo LPMULTIKEYHELPA LPMULTIKEYHELP;
#fim_se

  defina_tipo estrutura tagHELPWININFOA {
    inteiro wStructSize;
    inteiro x;
    inteiro y;
    inteiro dx;
    inteiro dy;
    inteiro wMax;
    CHAR rgchMember[2];
  } HELPWININFOA,*PHELPWININFOA,*LPHELPWININFOA;

  defina_tipo estrutura tagHELPWININFOW {
    inteiro wStructSize;
    inteiro x;
    inteiro y;
    inteiro dx;
    inteiro dy;
    inteiro wMax;
    WCHAR rgchMember[2];
  } HELPWININFOW,*PHELPWININFOW,*LPHELPWININFOW;

#se_definido UNICODE
  defina_tipo HELPWININFOW HELPWININFO;
  defina_tipo PHELPWININFOW PHELPWININFO;
  defina_tipo LPHELPWININFOW LPHELPWININFO;
#senão
  defina_tipo HELPWININFOA HELPWININFO;
  defina_tipo PHELPWININFOA PHELPWININFO;
  defina_tipo LPHELPWININFOA LPHELPWININFO;
#fim_se

#defina HELP_CONTEXT 0x0001L
#defina HELP_QUIT 0x0002L
#defina HELP_INDEX 0x0003L
#defina HELP_CONTENTS 0x0003L
#defina HELP_HELPONHELP 0x0004L
#defina HELP_SETINDEX 0x0005L
#defina HELP_SETCONTENTS 0x0005L
#defina HELP_CONTEXTPOPUP 0x0008L
#defina HELP_FORCEFILE 0x0009L
#defina HELP_KEY 0x0101L
#defina HELP_COMMAND 0x0102L
#defina HELP_PARTIALKEY 0x0105L
#defina HELP_MULTIKEY 0x0201L
#defina HELP_SETWINPOS 0x0203L
#defina HELP_CONTEXTMENU 0x000a
#defina HELP_FINDER 0x000b
#defina HELP_WM_HELP 0x000c
#defina HELP_SETPOPUP_POS 0x000d

#defina HELP_TCARD 0x8000
#defina HELP_TCARD_DATA 0x0010
#defina HELP_TCARD_OTHER_CALLER 0x0011

#defina IDH_NO_HELP 28440
#defina IDH_MISSING_CONTEXT 28441
#defina IDH_GENERIC_HELP_BUTTON 28442
#defina IDH_OK 28443
#defina IDH_CANCEL 28444
#defina IDH_HELP 28445

#se_definido UNICODE
#defina WinHelp WinHelpW
#senão
#defina WinHelp WinHelpA
#fim_se

  WINUSERAPI WINBOOL WINAPI WinHelpA(HWND hWndMain,LPCSTR lpszHelp,UINT uCommand,ULONG_PTR dwData);
  WINUSERAPI WINBOOL WINAPI WinHelpW(HWND hWndMain,LPCWSTR lpszHelp,UINT uCommand,ULONG_PTR dwData);
#fim_se

#defina GR_GDIOBJECTS 0
#defina GR_USEROBJECTS 1

  WINUSERAPI DWORD WINAPI GetGuiResources(HANDLE hProcess,DWORD uiFlags);

#se_não_definido NOSYSPARAMSINFO

#defina SPI_GETBEEP 0x0001
#defina SPI_SETBEEP 0x0002
#defina SPI_GETMOUSE 0x0003
#defina SPI_SETMOUSE 0x0004
#defina SPI_GETBORDER 0x0005
#defina SPI_SETBORDER 0x0006
#defina SPI_GETKEYBOARDSPEED 0x000A
#defina SPI_SETKEYBOARDSPEED 0x000B
#defina SPI_LANGDRIVER 0x000C
#defina SPI_ICONHORIZONTALSPACING 0x000D
#defina SPI_GETSCREENSAVETIMEOUT 0x000E
#defina SPI_SETSCREENSAVETIMEOUT 0x000F
#defina SPI_GETSCREENSAVEACTIVE 0x0010
#defina SPI_SETSCREENSAVEACTIVE 0x0011
#defina SPI_GETGRIDGRANULARITY 0x0012
#defina SPI_SETGRIDGRANULARITY 0x0013
#defina SPI_SETDESKWALLPAPER 0x0014
#defina SPI_SETDESKPATTERN 0x0015
#defina SPI_GETKEYBOARDDELAY 0x0016
#defina SPI_SETKEYBOARDDELAY 0x0017
#defina SPI_ICONVERTICALSPACING 0x0018
#defina SPI_GETICONTITLEWRAP 0x0019
#defina SPI_SETICONTITLEWRAP 0x001A
#defina SPI_GETMENUDROPALIGNMENT 0x001B
#defina SPI_SETMENUDROPALIGNMENT 0x001C
#defina SPI_SETDOUBLECLKWIDTH 0x001D
#defina SPI_SETDOUBLECLKHEIGHT 0x001E
#defina SPI_GETICONTITLELOGFONT 0x001F
#defina SPI_SETDOUBLECLICKTIME 0x0020
#defina SPI_SETMOUSEBUTTONSWAP 0x0021
#defina SPI_SETICONTITLELOGFONT 0x0022
#defina SPI_GETFASTTASKSWITCH 0x0023
#defina SPI_SETFASTTASKSWITCH 0x0024
#defina SPI_SETDRAGFULLWINDOWS 0x0025
#defina SPI_GETDRAGFULLWINDOWS 0x0026
#defina SPI_GETNONCLIENTMETRICS 0x0029
#defina SPI_SETNONCLIENTMETRICS 0x002A
#defina SPI_GETMINIMIZEDMETRICS 0x002B
#defina SPI_SETMINIMIZEDMETRICS 0x002C
#defina SPI_GETICONMETRICS 0x002D
#defina SPI_SETICONMETRICS 0x002E
#defina SPI_SETWORKAREA 0x002F
#defina SPI_GETWORKAREA 0x0030
#defina SPI_SETPENWINDOWS 0x0031

#defina SPI_GETHIGHCONTRAST 0x0042
#defina SPI_SETHIGHCONTRAST 0x0043
#defina SPI_GETKEYBOARDPREF 0x0044
#defina SPI_SETKEYBOARDPREF 0x0045
#defina SPI_GETSCREENREADER 0x0046
#defina SPI_SETSCREENREADER 0x0047
#defina SPI_GETANIMATION 0x0048
#defina SPI_SETANIMATION 0x0049
#defina SPI_GETFONTSMOOTHING 0x004A
#defina SPI_SETFONTSMOOTHING 0x004B
#defina SPI_SETDRAGWIDTH 0x004C
#defina SPI_SETDRAGHEIGHT 0x004D
#defina SPI_SETHANDHELD 0x004E
#defina SPI_GETLOWPOWERTIMEOUT 0x004F
#defina SPI_GETPOWEROFFTIMEOUT 0x0050
#defina SPI_SETLOWPOWERTIMEOUT 0x0051
#defina SPI_SETPOWEROFFTIMEOUT 0x0052
#defina SPI_GETLOWPOWERACTIVE 0x0053
#defina SPI_GETPOWEROFFACTIVE 0x0054
#defina SPI_SETLOWPOWERACTIVE 0x0055
#defina SPI_SETPOWEROFFACTIVE 0x0056
#defina SPI_SETCURSORS 0x0057
#defina SPI_SETICONS 0x0058
#defina SPI_GETDEFAULTINPUTLANG 0x0059
#defina SPI_SETDEFAULTINPUTLANG 0x005A
#defina SPI_SETLANGTOGGLE 0x005B
#defina SPI_GETWINDOWSEXTENSION 0x005C
#defina SPI_SETMOUSETRAILS 0x005D
#defina SPI_GETMOUSETRAILS 0x005E
#defina SPI_SETSCREENSAVERRUNNING 0x0061
#defina SPI_SCREENSAVERRUNNING SPI_SETSCREENSAVERRUNNING
#defina SPI_GETFILTERKEYS 0x0032
#defina SPI_SETFILTERKEYS 0x0033
#defina SPI_GETTOGGLEKEYS 0x0034
#defina SPI_SETTOGGLEKEYS 0x0035
#defina SPI_GETMOUSEKEYS 0x0036
#defina SPI_SETMOUSEKEYS 0x0037
#defina SPI_GETSHOWSOUNDS 0x0038
#defina SPI_SETSHOWSOUNDS 0x0039
#defina SPI_GETSTICKYKEYS 0x003A
#defina SPI_SETSTICKYKEYS 0x003B
#defina SPI_GETACCESSTIMEOUT 0x003C
#defina SPI_SETACCESSTIMEOUT 0x003D
#defina SPI_GETSERIALKEYS 0x003E
#defina SPI_SETSERIALKEYS 0x003F
#defina SPI_GETSOUNDSENTRY 0x0040
#defina SPI_SETSOUNDSENTRY 0x0041
#defina SPI_GETSNAPTODEFBUTTON 0x005F
#defina SPI_SETSNAPTODEFBUTTON 0x0060
#defina SPI_GETMOUSEHOVERWIDTH 0x0062
#defina SPI_SETMOUSEHOVERWIDTH 0x0063
#defina SPI_GETMOUSEHOVERHEIGHT 0x0064
#defina SPI_SETMOUSEHOVERHEIGHT 0x0065
#defina SPI_GETMOUSEHOVERTIME 0x0066
#defina SPI_SETMOUSEHOVERTIME 0x0067
#defina SPI_GETWHEELSCROLLLINES 0x0068
#defina SPI_SETWHEELSCROLLLINES 0x0069
#defina SPI_GETMENUSHOWDELAY 0x006A
#defina SPI_SETMENUSHOWDELAY 0x006B
#defina SPI_GETSHOWIMEUI 0x006E
#defina SPI_SETSHOWIMEUI 0x006F
#defina SPI_GETMOUSESPEED 0x0070
#defina SPI_SETMOUSESPEED 0x0071
#defina SPI_GETSCREENSAVERRUNNING 0x0072
#defina SPI_GETDESKWALLPAPER 0x0073

#defina SPI_GETACTIVEWINDOWTRACKING 0x1000
#defina SPI_SETACTIVEWINDOWTRACKING 0x1001
#defina SPI_GETMENUANIMATION 0x1002
#defina SPI_SETMENUANIMATION 0x1003
#defina SPI_GETCOMBOBOXANIMATION 0x1004
#defina SPI_SETCOMBOBOXANIMATION 0x1005
#defina SPI_GETLISTBOXSMOOTHSCROLLING 0x1006
#defina SPI_SETLISTBOXSMOOTHSCROLLING 0x1007
#defina SPI_GETGRADIENTCAPTIONS 0x1008
#defina SPI_SETGRADIENTCAPTIONS 0x1009
#defina SPI_GETKEYBOARDCUES 0x100A
#defina SPI_SETKEYBOARDCUES 0x100B
#defina SPI_GETMENUUNDERLINES SPI_GETKEYBOARDCUES
#defina SPI_SETMENUUNDERLINES SPI_SETKEYBOARDCUES
#defina SPI_GETACTIVEWNDTRKZORDER 0x100C
#defina SPI_SETACTIVEWNDTRKZORDER 0x100D
#defina SPI_GETHOTTRACKING 0x100E
#defina SPI_SETHOTTRACKING 0x100F
#defina SPI_GETMENUFADE 0x1012
#defina SPI_SETMENUFADE 0x1013
#defina SPI_GETSELECTIONFADE 0x1014
#defina SPI_SETSELECTIONFADE 0x1015
#defina SPI_GETTOOLTIPANIMATION 0x1016
#defina SPI_SETTOOLTIPANIMATION 0x1017
#defina SPI_GETTOOLTIPFADE 0x1018
#defina SPI_SETTOOLTIPFADE 0x1019
#defina SPI_GETCURSORSHADOW 0x101A
#defina SPI_SETCURSORSHADOW 0x101B
#defina SPI_GETMOUSESONAR 0x101C
#defina SPI_SETMOUSESONAR 0x101D
#defina SPI_GETMOUSECLICKLOCK 0x101E
#defina SPI_SETMOUSECLICKLOCK 0x101F
#defina SPI_GETMOUSEVANISH 0x1020
#defina SPI_SETMOUSEVANISH 0x1021
#defina SPI_GETFLATMENU 0x1022
#defina SPI_SETFLATMENU 0x1023
#defina SPI_GETDROPSHADOW 0x1024
#defina SPI_SETDROPSHADOW 0x1025
#defina SPI_GETBLOCKSENDINPUTRESETS 0x1026
#defina SPI_SETBLOCKSENDINPUTRESETS 0x1027
#defina SPI_GETUIEFFECTS 0x103E
#defina SPI_SETUIEFFECTS 0x103F
#defina SPI_GETFOREGROUNDLOCKTIMEOUT 0x2000
#defina SPI_SETFOREGROUNDLOCKTIMEOUT 0x2001
#defina SPI_GETACTIVEWNDTRKTIMEOUT 0x2002
#defina SPI_SETACTIVEWNDTRKTIMEOUT 0x2003
#defina SPI_GETFOREGROUNDFLASHCOUNT 0x2004
#defina SPI_SETFOREGROUNDFLASHCOUNT 0x2005
#defina SPI_GETCARETWIDTH 0x2006
#defina SPI_SETCARETWIDTH 0x2007
#defina SPI_GETMOUSECLICKLOCKTIME 0x2008
#defina SPI_SETMOUSECLICKLOCKTIME 0x2009
#defina SPI_GETFONTSMOOTHINGTYPE 0x200A
#defina SPI_SETFONTSMOOTHINGTYPE 0x200B

#defina FE_FONTSMOOTHINGSTANDARD 0x0001
#defina FE_FONTSMOOTHINGCLEARTYPE 0x0002
#defina FE_FONTSMOOTHINGDOCKING 0x8000

#defina SPI_GETFONTSMOOTHINGCONTRAST 0x200C
#defina SPI_SETFONTSMOOTHINGCONTRAST 0x200D
#defina SPI_GETFOCUSBORDERWIDTH 0x200E
#defina SPI_SETFOCUSBORDERWIDTH 0x200F
#defina SPI_GETFOCUSBORDERHEIGHT 0x2010
#defina SPI_SETFOCUSBORDERHEIGHT 0x2011
#defina SPI_GETFONTSMOOTHINGORIENTATION 0x2012
#defina SPI_SETFONTSMOOTHINGORIENTATION 0x2013

#defina FE_FONTSMOOTHINGORIENTATIONBGR 0x0000
#defina FE_FONTSMOOTHINGORIENTATIONRGB 0x0001

#defina SPIF_UPDATEINIFILE 0x0001
#defina SPIF_SENDWININICHANGE 0x0002
#defina SPIF_SENDCHANGE SPIF_SENDWININICHANGE

#defina METRICS_USEDEFAULT -1
#se_definido _WINGDI_
#se_não_definido NOGDI
  defina_tipo estrutura tagNONCLIENTMETRICSA {
    UINT cbSize;
    inteiro iBorderWidth;
    inteiro iScrollWidth;
    inteiro iScrollHeight;
    inteiro iCaptionWidth;
    inteiro iCaptionHeight;
    LOGFONTA lfCaptionFont;
    inteiro iSmCaptionWidth;
    inteiro iSmCaptionHeight;
    LOGFONTA lfSmCaptionFont;
    inteiro iMenuWidth;
    inteiro iMenuHeight;
    LOGFONTA lfMenuFont;
    LOGFONTA lfStatusFont;
    LOGFONTA lfMessageFont;
  } NONCLIENTMETRICSA,*PNONCLIENTMETRICSA,*LPNONCLIENTMETRICSA;

  defina_tipo estrutura tagNONCLIENTMETRICSW {
    UINT cbSize;
    inteiro iBorderWidth;
    inteiro iScrollWidth;
    inteiro iScrollHeight;
    inteiro iCaptionWidth;
    inteiro iCaptionHeight;
    LOGFONTW lfCaptionFont;
    inteiro iSmCaptionWidth;
    inteiro iSmCaptionHeight;
    LOGFONTW lfSmCaptionFont;
    inteiro iMenuWidth;
    inteiro iMenuHeight;
    LOGFONTW lfMenuFont;
    LOGFONTW lfStatusFont;
    LOGFONTW lfMessageFont;
  } NONCLIENTMETRICSW,*PNONCLIENTMETRICSW,*LPNONCLIENTMETRICSW;

#se_definido UNICODE
  defina_tipo NONCLIENTMETRICSW NONCLIENTMETRICS;
  defina_tipo PNONCLIENTMETRICSW PNONCLIENTMETRICS;
  defina_tipo LPNONCLIENTMETRICSW LPNONCLIENTMETRICS;
#senão
  defina_tipo NONCLIENTMETRICSA NONCLIENTMETRICS;
  defina_tipo PNONCLIENTMETRICSA PNONCLIENTMETRICS;
  defina_tipo LPNONCLIENTMETRICSA LPNONCLIENTMETRICS;
#fim_se
#fim_se
#fim_se

#defina ARW_BOTTOMLEFT 0x0000L
#defina ARW_BOTTOMRIGHT 0x0001L
#defina ARW_TOPLEFT 0x0002L
#defina ARW_TOPRIGHT 0x0003L
#defina ARW_STARTMASK 0x0003L
#defina ARW_STARTRIGHT 0x0001L
#defina ARW_STARTTOP 0x0002L

#defina ARW_LEFT 0x0000L
#defina ARW_RIGHT 0x0000L
#defina ARW_UP 0x0004L
#defina ARW_DOWN 0x0004L
#defina ARW_HIDE 0x0008L

  defina_tipo estrutura tagMINIMIZEDMETRICS {
    UINT cbSize;
    inteiro iWidth;
    inteiro iHorzGap;
    inteiro iVertGap;
    inteiro iArrange;
  } MINIMIZEDMETRICS,*PMINIMIZEDMETRICS,*LPMINIMIZEDMETRICS;

#se_definido _WINGDI_
#se_não_definido NOGDI
  defina_tipo estrutura tagICONMETRICSA {
    UINT cbSize;
    inteiro iHorzSpacing;
    inteiro iVertSpacing;
    inteiro iTitleWrap;
    LOGFONTA lfFont;
  } ICONMETRICSA,*PICONMETRICSA,*LPICONMETRICSA;

  defina_tipo estrutura tagICONMETRICSW {
    UINT cbSize;
    inteiro iHorzSpacing;
    inteiro iVertSpacing;
    inteiro iTitleWrap;
    LOGFONTW lfFont;
  } ICONMETRICSW,*PICONMETRICSW,*LPICONMETRICSW;

#se_definido UNICODE
  defina_tipo ICONMETRICSW ICONMETRICS;
  defina_tipo PICONMETRICSW PICONMETRICS;
  defina_tipo LPICONMETRICSW LPICONMETRICS;
#senão
  defina_tipo ICONMETRICSA ICONMETRICS;
  defina_tipo PICONMETRICSA PICONMETRICS;
  defina_tipo LPICONMETRICSA LPICONMETRICS;
#fim_se
#fim_se
#fim_se

  defina_tipo estrutura tagANIMATIONINFO {
    UINT cbSize;
    inteiro iMinAnimate;
  } ANIMATIONINFO,*LPANIMATIONINFO;

  defina_tipo estrutura tagSERIALKEYSA {
    UINT cbSize;
    DWORD dwFlags;
    LPSTR lpszActivePort;
    LPSTR lpszPort;
    UINT iBaudRate;
    UINT iPortState;
    UINT iActive;
  } SERIALKEYSA,*LPSERIALKEYSA;

  defina_tipo estrutura tagSERIALKEYSW {
    UINT cbSize;
    DWORD dwFlags;
    LPWSTR lpszActivePort;
    LPWSTR lpszPort;
    UINT iBaudRate;
    UINT iPortState;
    UINT iActive;
  } SERIALKEYSW,*LPSERIALKEYSW;

#se_definido UNICODE
  defina_tipo SERIALKEYSW SERIALKEYS;
  defina_tipo LPSERIALKEYSW LPSERIALKEYS;
#senão
  defina_tipo SERIALKEYSA SERIALKEYS;
  defina_tipo LPSERIALKEYSA LPSERIALKEYS;
#fim_se

#defina SERKF_SERIALKEYSON 0x00000001
#defina SERKF_AVAILABLE 0x00000002
#defina SERKF_INDICATOR 0x00000004

  defina_tipo estrutura tagHIGHCONTRASTA {
    UINT cbSize;
    DWORD dwFlags;
    LPSTR lpszDefaultScheme;
  } HIGHCONTRASTA,*LPHIGHCONTRASTA;

  defina_tipo estrutura tagHIGHCONTRASTW {
    UINT cbSize;
    DWORD dwFlags;
    LPWSTR lpszDefaultScheme;
  } HIGHCONTRASTW,*LPHIGHCONTRASTW;

#se_definido UNICODE
  defina_tipo HIGHCONTRASTW HIGHCONTRAST;
  defina_tipo LPHIGHCONTRASTW LPHIGHCONTRAST;
#senão
  defina_tipo HIGHCONTRASTA HIGHCONTRAST;
  defina_tipo LPHIGHCONTRASTA LPHIGHCONTRAST;
#fim_se

#defina HCF_HIGHCONTRASTON 0x00000001
#defina HCF_AVAILABLE 0x00000002
#defina HCF_HOTKEYACTIVE 0x00000004
#defina HCF_CONFIRMHOTKEY 0x00000008
#defina HCF_HOTKEYSOUND 0x00000010
#defina HCF_INDICATOR 0x00000020
#defina HCF_HOTKEYAVAILABLE 0x00000040
#defina HCF_LOGONDESKTOP 0x00000100
#defina HCF_DEFAULTDESKTOP 0x00000200

#defina CDS_UPDATEREGISTRY 0x00000001
#defina CDS_TEST 0x00000002
#defina CDS_FULLSCREEN 0x00000004
#defina CDS_GLOBAL 0x00000008
#defina CDS_SET_PRIMARY 0x00000010
#defina CDS_VIDEOPARAMETERS 0x00000020
#defina CDS_RESET 0x40000000
#defina CDS_NORESET 0x10000000

//gr #inclua <tvout.h>

#defina DISP_CHANGE_SUCCESSFUL 0
#defina DISP_CHANGE_RESTART 1
#defina DISP_CHANGE_FAILED -1
#defina DISP_CHANGE_BADMODE -2
#defina DISP_CHANGE_NOTUPDATED -3
#defina DISP_CHANGE_BADFLAGS -4
#defina DISP_CHANGE_BADPARAM -5
#defina DISP_CHANGE_BADDUALVIEW -6

#se_definido _WINGDI_
#se_não_definido NOGDI

#se_definido UNICODE
#defina ChangeDisplaySettings ChangeDisplaySettingsW
#defina ChangeDisplaySettingsEx ChangeDisplaySettingsExW
#defina EnumDisplaySettings EnumDisplaySettingsW
#defina EnumDisplaySettingsEx EnumDisplaySettingsExW
#defina EnumDisplayDevices EnumDisplayDevicesW
#senão
#defina ChangeDisplaySettings ChangeDisplaySettingsA
#defina ChangeDisplaySettingsEx ChangeDisplaySettingsExA
#defina EnumDisplaySettings EnumDisplaySettingsA
#defina EnumDisplaySettingsEx EnumDisplaySettingsExA
#defina EnumDisplayDevices EnumDisplayDevicesA
#fim_se

  WINUSERAPI LONG WINAPI ChangeDisplaySettingsA(LPDEVMODEA lpDevMode,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsW(LPDEVMODEW lpDevMode,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExA(LPCSTR lpszDeviceName,LPDEVMODEA lpDevMode,HWND hwnd,DWORD dwflags,LPVOID lParam);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExW(LPCWSTR lpszDeviceName,LPDEVMODEW lpDevMode,HWND hwnd,DWORD dwflags,LPVOID lParam);

#defina ENUM_CURRENT_SETTINGS ((DWORD)-1)
#defina ENUM_REGISTRY_SETTINGS ((DWORD)-2)

  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsA(LPCSTR lpszDeviceName,DWORD iModeNum,LPDEVMODEA lpDevMode);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsW(LPCWSTR lpszDeviceName,DWORD iModeNum,LPDEVMODEW lpDevMode);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExA(LPCSTR lpszDeviceName,DWORD iModeNum,LPDEVMODEA lpDevMode,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExW(LPCWSTR lpszDeviceName,DWORD iModeNum,LPDEVMODEW lpDevMode,DWORD dwFlags);

#defina EDS_RAWMODE 0x00000002

  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesA(LPCSTR lpDevice,DWORD iDevNum,PDISPLAY_DEVICEA lpDisplayDevice,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesW(LPCWSTR lpDevice,DWORD iDevNum,PDISPLAY_DEVICEW lpDisplayDevice,DWORD dwFlags);
#fim_se
#fim_se

#se_definido UNICODE
#defina SystemParametersInfo SystemParametersInfoW
#senão
#defina SystemParametersInfo SystemParametersInfoA
#fim_se

  WINUSERAPI WINBOOL WINAPI SystemParametersInfoA(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
  WINUSERAPI WINBOOL WINAPI SystemParametersInfoW(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
#fim_se

  defina_tipo estrutura tagFILTERKEYS {
    UINT cbSize;
    DWORD dwFlags;
    DWORD iWaitMSec;
    DWORD iDelayMSec;
    DWORD iRepeatMSec;
    DWORD iBounceMSec;
  } FILTERKEYS,*LPFILTERKEYS;

#defina FKF_FILTERKEYSON 0x00000001
#defina FKF_AVAILABLE 0x00000002
#defina FKF_HOTKEYACTIVE 0x00000004
#defina FKF_CONFIRMHOTKEY 0x00000008
#defina FKF_HOTKEYSOUND 0x00000010
#defina FKF_INDICATOR 0x00000020
#defina FKF_CLICKON 0x00000040

  defina_tipo estrutura tagSTICKYKEYS {
    UINT cbSize;
    DWORD dwFlags;
  } STICKYKEYS,*LPSTICKYKEYS;

#defina SKF_STICKYKEYSON 0x00000001
#defina SKF_AVAILABLE 0x00000002
#defina SKF_HOTKEYACTIVE 0x00000004
#defina SKF_CONFIRMHOTKEY 0x00000008
#defina SKF_HOTKEYSOUND 0x00000010
#defina SKF_INDICATOR 0x00000020
#defina SKF_AUDIBLEFEEDBACK 0x00000040
#defina SKF_TRISTATE 0x00000080
#defina SKF_TWOKEYSOFF 0x00000100
#defina SKF_LALTLATCHED 0x10000000
#defina SKF_LCTLLATCHED 0x04000000
#defina SKF_LSHIFTLATCHED 0x01000000
#defina SKF_RALTLATCHED 0x20000000
#defina SKF_RCTLLATCHED 0x08000000
#defina SKF_RSHIFTLATCHED 0x02000000
#defina SKF_LWINLATCHED 0x40000000
#defina SKF_RWINLATCHED 0x80000000
#defina SKF_LALTLOCKED 0x00100000
#defina SKF_LCTLLOCKED 0x00040000
#defina SKF_LSHIFTLOCKED 0x00010000
#defina SKF_RALTLOCKED 0x00200000
#defina SKF_RCTLLOCKED 0x00080000
#defina SKF_RSHIFTLOCKED 0x00020000
#defina SKF_LWINLOCKED 0x00400000
#defina SKF_RWINLOCKED 0x00800000

  defina_tipo estrutura tagMOUSEKEYS {
    UINT cbSize;
    DWORD dwFlags;
    DWORD iMaxSpeed;
    DWORD iTimeToMaxSpeed;
    DWORD iCtrlSpeed;
    DWORD dwReserved1;
    DWORD dwReserved2;
  } MOUSEKEYS,*LPMOUSEKEYS;

#defina MKF_MOUSEKEYSON 0x00000001
#defina MKF_AVAILABLE 0x00000002
#defina MKF_HOTKEYACTIVE 0x00000004
#defina MKF_CONFIRMHOTKEY 0x00000008
#defina MKF_HOTKEYSOUND 0x00000010
#defina MKF_INDICATOR 0x00000020
#defina MKF_MODIFIERS 0x00000040
#defina MKF_REPLACENUMBERS 0x00000080
#defina MKF_LEFTBUTTONSEL 0x10000000
#defina MKF_RIGHTBUTTONSEL 0x20000000
#defina MKF_LEFTBUTTONDOWN 0x01000000
#defina MKF_RIGHTBUTTONDOWN 0x02000000
#defina MKF_MOUSEMODE 0x80000000

  defina_tipo estrutura tagACCESSTIMEOUT {
    UINT cbSize;
    DWORD dwFlags;
    DWORD iTimeOutMSec;
  } ACCESSTIMEOUT,*LPACCESSTIMEOUT;

#defina ATF_TIMEOUTON 0x00000001
#defina ATF_ONOFFFEEDBACK 0x00000002

#defina SSGF_NONE 0
#defina SSGF_DISPLAY 3

#defina SSTF_NONE 0
#defina SSTF_CHARS 1
#defina SSTF_BORDER 2
#defina SSTF_DISPLAY 3

#defina SSWF_NONE 0
#defina SSWF_TITLE 1
#defina SSWF_WINDOW 2
#defina SSWF_DISPLAY 3
#defina SSWF_CUSTOM 4

  defina_tipo estrutura tagSOUNDSENTRYA {
    UINT cbSize;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD iFSTextEffectColorBits;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYA,*LPSOUNDSENTRYA;

  defina_tipo estrutura tagSOUNDSENTRYW {
    UINT cbSize;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD iFSTextEffectColorBits;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPWSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYW,*LPSOUNDSENTRYW;

#se_definido UNICODE
  defina_tipo SOUNDSENTRYW SOUNDSENTRY;
  defina_tipo LPSOUNDSENTRYW LPSOUNDSENTRY;
#senão
  defina_tipo SOUNDSENTRYA SOUNDSENTRY;
  defina_tipo LPSOUNDSENTRYA LPSOUNDSENTRY;
#fim_se

#defina SSF_SOUNDSENTRYON 0x00000001
#defina SSF_AVAILABLE 0x00000002
#defina SSF_INDICATOR 0x00000004

  defina_tipo estrutura tagTOGGLEKEYS {
    UINT cbSize;
    DWORD dwFlags;
  } TOGGLEKEYS,*LPTOGGLEKEYS;

#defina TKF_TOGGLEKEYSON 0x00000001
#defina TKF_AVAILABLE 0x00000002
#defina TKF_HOTKEYACTIVE 0x00000004
#defina TKF_CONFIRMHOTKEY 0x00000008
#defina TKF_HOTKEYSOUND 0x00000010
#defina TKF_INDICATOR 0x00000020

  WINUSERAPI VOID WINAPI SetDebugErrorLevel(DWORD dwLevel);

#defina SLE_ERROR 0x00000001
#defina SLE_MINORERROR 0x00000002
#defina SLE_WARNING 0x00000003

  WINUSERAPI VOID WINAPI SetLastErrorEx(DWORD dwErrCode,DWORD dwType);
  WINUSERAPI inteiro WINAPI InternalGetWindowText(HWND hWnd,LPWSTR pString,inteiro cchMaxCount);

#se_definido WINNT
  WINUSERAPI WINBOOL WINAPI EndTask(HWND hWnd,WINBOOL fShutDown,WINBOOL fForce);
#fim_se

#defina MONITOR_DEFAULTTONULL 0x00000000
#defina MONITOR_DEFAULTTOPRIMARY 0x00000001
#defina MONITOR_DEFAULTTONEAREST 0x00000002

  WINUSERAPI HMONITOR WINAPI MonitorFromPoint(POINT pt,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI MonitorFromRect(LPCRECT lprc,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI MonitorFromWindow(HWND hwnd,DWORD dwFlags);

#defina MONITORINFOF_PRIMARY 0x00000001

#se_não_definido CCHDEVICENAME
#defina CCHDEVICENAME 32
#fim_se

  defina_tipo estrutura tagMONITORINFO {
    DWORD cbSize;
    RECT rcMonitor;
    RECT rcWork;
    DWORD dwFlags;
  } MONITORINFO,*LPMONITORINFO;

#se_definido __cplusplus
  defina_tipo estrutura tagMONITORINFOEXA : public tagMONITORINFO {
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  defina_tipo estrutura tagMONITORINFOEXW : public tagMONITORINFO {
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;

#se_definido UNICODE
  defina_tipo MONITORINFOEXW MONITORINFOEX;
  defina_tipo LPMONITORINFOEXW LPMONITORINFOEX;
#senão
  defina_tipo MONITORINFOEXA MONITORINFOEX;
  defina_tipo LPMONITORINFOEXA LPMONITORINFOEX;
#fim_se
#senão
  defina_tipo estrutura tagMONITORINFOEXA {
    MONITORINFO mi;
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  defina_tipo estrutura tagMONITORINFOEXW {
    MONITORINFO mi;
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;
#se_definido UNICODE
  defina_tipo MONITORINFOEXW MONITORINFOEX;
  defina_tipo LPMONITORINFOEXW LPMONITORINFOEX;
#senão
  defina_tipo MONITORINFOEXA MONITORINFOEX;
  defina_tipo LPMONITORINFOEXA LPMONITORINFOEX;
#fim_se
#fim_se

#se_definido UNICODE 
#defina GetMonitorInfo GetMonitorInfoW
#senão
#defina GetMonitorInfo GetMonitorInfoA
#fim_se

  WINUSERAPI WINBOOL WINAPI GetMonitorInfoA(HMONITOR hMonitor,LPMONITORINFO lpmi);
  WINUSERAPI WINBOOL WINAPI GetMonitorInfoW(HMONITOR hMonitor,LPMONITORINFO lpmi);

  defina_tipo WINBOOL (CALLBACK *MONITORENUMPROC)(HMONITOR,HDC,LPRECT,LPARAM);

  WINUSERAPI WINBOOL WINAPI EnumDisplayMonitors(HDC hdc,LPCRECT lprcClip,MONITORENUMPROC lpfnEnum,LPARAM dwData);

#se_não_definido NOWINABLE
  WINUSERAPI VOID WINAPI NotifyWinEvent(DWORD event,HWND hwnd,LONG idObject,LONG idChild);

  defina_tipo VOID (CALLBACK *WINEVENTPROC)(HWINEVENTHOOK hWinEventHook,DWORD event,HWND hwnd,LONG idObject,LONG idChild,DWORD idEventThread,DWORD dwmsEventTime);

  WINUSERAPI HWINEVENTHOOK WINAPI SetWinEventHook(DWORD eventMin,DWORD eventMax,HMODULE hmodWinEventProc,WINEVENTPROC pfnWinEventProc,DWORD idProcess,DWORD idThread,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI IsWinEventHookInstalled(DWORD event);

#defina WINEVENT_OUTOFCONTEXT 0x0000
#defina WINEVENT_SKIPOWNTHREAD 0x0001
#defina WINEVENT_SKIPOWNPROCESS 0x0002
#defina WINEVENT_INCONTEXT 0x0004

  WINUSERAPI WINBOOL WINAPI UnhookWinEvent(HWINEVENTHOOK hWinEventHook);

#defina CHILDID_SELF 0
#defina INDEXID_OBJECT 0
#defina INDEXID_CONTAINER 0

#defina OBJID_WINDOW ((LONG)0x00000000)
#defina OBJID_SYSMENU ((LONG)0xFFFFFFFF)
#defina OBJID_TITLEBAR ((LONG)0xFFFFFFFE)
#defina OBJID_MENU ((LONG)0xFFFFFFFD)
#defina OBJID_CLIENT ((LONG)0xFFFFFFFC)
#defina OBJID_VSCROLL ((LONG)0xFFFFFFFB)
#defina OBJID_HSCROLL ((LONG)0xFFFFFFFA)
#defina OBJID_SIZEGRIP ((LONG)0xFFFFFFF9)
#defina OBJID_CARET ((LONG)0xFFFFFFF8)
#defina OBJID_CURSOR ((LONG)0xFFFFFFF7)
#defina OBJID_ALERT ((LONG)0xFFFFFFF6)
#defina OBJID_SOUND ((LONG)0xFFFFFFF5)
#defina OBJID_QUERYCLASSNAMEIDX ((LONG)0xFFFFFFF4)
#defina OBJID_NATIVEOM ((LONG)0xFFFFFFF0)

#defina EVENT_MIN 0x00000001
#defina EVENT_MAX 0x7FFFFFFF

#defina EVENT_SYSTEM_SOUND 0x0001
#defina EVENT_SYSTEM_ALERT 0x0002
#defina EVENT_SYSTEM_FOREGROUND 0x0003
#defina EVENT_SYSTEM_MENUSTART 0x0004
#defina EVENT_SYSTEM_MENUEND 0x0005
#defina EVENT_SYSTEM_MENUPOPUPSTART 0x0006
#defina EVENT_SYSTEM_MENUPOPUPEND 0x0007
#defina EVENT_SYSTEM_CAPTURESTART 0x0008
#defina EVENT_SYSTEM_CAPTUREEND 0x0009
#defina EVENT_SYSTEM_MOVESIZESTART 0x000A
#defina EVENT_SYSTEM_MOVESIZEEND 0x000B
#defina EVENT_SYSTEM_CONTEXTHELPSTART 0x000C
#defina EVENT_SYSTEM_CONTEXTHELPEND 0x000D
#defina EVENT_SYSTEM_DRAGDROPSTART 0x000E
#defina EVENT_SYSTEM_DRAGDROPEND 0x000F
#defina EVENT_SYSTEM_DIALOGSTART 0x0010
#defina EVENT_SYSTEM_DIALOGEND 0x0011
#defina EVENT_SYSTEM_SCROLLINGSTART 0x0012
#defina EVENT_SYSTEM_SCROLLINGEND 0x0013
#defina EVENT_SYSTEM_SWITCHSTART 0x0014
#defina EVENT_SYSTEM_SWITCHEND 0x0015
#defina EVENT_SYSTEM_MINIMIZESTART 0x0016
#defina EVENT_SYSTEM_MINIMIZEEND 0x0017

#defina EVENT_CONSOLE_CARET 0x4001
#defina EVENT_CONSOLE_UPDATE_REGION 0x4002
#defina EVENT_CONSOLE_UPDATE_SIMPLE 0x4003
#defina EVENT_CONSOLE_UPDATE_SCROLL 0x4004
#defina EVENT_CONSOLE_LAYOUT 0x4005
#defina EVENT_CONSOLE_START_APPLICATION 0x4006
#defina EVENT_CONSOLE_END_APPLICATION 0x4007

#defina CONSOLE_APPLICATION_16BIT 0x0001

#defina CONSOLE_CARET_SELECTION 0x0001
#defina CONSOLE_CARET_VISIBLE 0x0002

#defina EVENT_OBJECT_CREATE 0x8000
#defina EVENT_OBJECT_DESTROY 0x8001
#defina EVENT_OBJECT_SHOW 0x8002
#defina EVENT_OBJECT_HIDE 0x8003
#defina EVENT_OBJECT_REORDER 0x8004

#defina EVENT_OBJECT_FOCUS 0x8005
#defina EVENT_OBJECT_SELECTION 0x8006
#defina EVENT_OBJECT_SELECTIONADD 0x8007
#defina EVENT_OBJECT_SELECTIONREMOVE 0x8008
#defina EVENT_OBJECT_SELECTIONWITHIN 0x8009

#defina EVENT_OBJECT_STATECHANGE 0x800A

#defina EVENT_OBJECT_LOCATIONCHANGE 0x800B

#defina EVENT_OBJECT_NAMECHANGE 0x800C
#defina EVENT_OBJECT_DESCRIPTIONCHANGE 0x800D
#defina EVENT_OBJECT_VALUECHANGE 0x800E
#defina EVENT_OBJECT_PARENTCHANGE 0x800F
#defina EVENT_OBJECT_HELPCHANGE 0x8010
#defina EVENT_OBJECT_DEFACTIONCHANGE 0x8011
#defina EVENT_OBJECT_ACCELERATORCHANGE 0x8012

#defina SOUND_SYSTEM_STARTUP 1
#defina SOUND_SYSTEM_SHUTDOWN 2
#defina SOUND_SYSTEM_BEEP 3
#defina SOUND_SYSTEM_ERROR 4
#defina SOUND_SYSTEM_QUESTION 5
#defina SOUND_SYSTEM_WARNING 6
#defina SOUND_SYSTEM_INFORMATION 7
#defina SOUND_SYSTEM_MAXIMIZE 8
#defina SOUND_SYSTEM_MINIMIZE 9
#defina SOUND_SYSTEM_RESTOREUP 10
#defina SOUND_SYSTEM_RESTOREDOWN 11
#defina SOUND_SYSTEM_APPSTART 12
#defina SOUND_SYSTEM_FAULT 13
#defina SOUND_SYSTEM_APPEND 14
#defina SOUND_SYSTEM_MENUCOMMAND 15
#defina SOUND_SYSTEM_MENUPOPUP 16
#defina CSOUND_SYSTEM 16

#defina ALERT_SYSTEM_INFORMATIONAL 1
#defina ALERT_SYSTEM_WARNING 2
#defina ALERT_SYSTEM_ERROR 3
#defina ALERT_SYSTEM_QUERY 4
#defina ALERT_SYSTEM_CRITICAL 5
#defina CALERT_SYSTEM 6

  defina_tipo estrutura tagGUITHREADINFO {
    DWORD cbSize;
    DWORD flags;
    HWND hwndActive;
    HWND hwndFocus;
    HWND hwndCapture;
    HWND hwndMenuOwner;
    HWND hwndMoveSize;
    HWND hwndCaret;
    RECT rcCaret;
  } GUITHREADINFO,*PGUITHREADINFO,*LPGUITHREADINFO;

#defina GUI_CARETBLINKING 0x00000001
#defina GUI_INMOVESIZE 0x00000002
#defina GUI_INMENUMODE 0x00000004
#defina GUI_SYSTEMMENUMODE 0x00000008
#defina GUI_POPUPMENUMODE 0x00000010
#defina GUI_16BITTASK 0x00000020

#se_definido UNICODE
#defina GetWindowModuleFileName GetWindowModuleFileNameW
#senão
#defina GetWindowModuleFileName GetWindowModuleFileNameA
#fim_se

  WINUSERAPI WINBOOL WINAPI GetGUIThreadInfo(DWORD idThread,PGUITHREADINFO pgui);
  WINUSERAPI UINT WINAPI GetWindowModuleFileNameA(HWND hwnd,LPSTR pszFileName,UINT cchFileNameMax);
  WINUSERAPI UINT WINAPI GetWindowModuleFileNameW(HWND hwnd,LPWSTR pszFileName,UINT cchFileNameMax);

#se_não_definido NO_STATE_FLAGS
#defina STATE_SYSTEM_UNAVAILABLE 0x00000001
#defina STATE_SYSTEM_SELECTED 0x00000002
#defina STATE_SYSTEM_FOCUSED 0x00000004
#defina STATE_SYSTEM_PRESSED 0x00000008
#defina STATE_SYSTEM_CHECKED 0x00000010
#defina STATE_SYSTEM_MIXED 0x00000020
#defina STATE_SYSTEM_INDETERMINATE STATE_SYSTEM_MIXED
#defina STATE_SYSTEM_READONLY 0x00000040
#defina STATE_SYSTEM_HOTTRACKED 0x00000080
#defina STATE_SYSTEM_DEFAULT 0x00000100
#defina STATE_SYSTEM_EXPANDED 0x00000200
#defina STATE_SYSTEM_COLLAPSED 0x00000400
#defina STATE_SYSTEM_BUSY 0x00000800
#defina STATE_SYSTEM_FLOATING 0x00001000
#defina STATE_SYSTEM_MARQUEED 0x00002000
#defina STATE_SYSTEM_ANIMATED 0x00004000
#defina STATE_SYSTEM_INVISIBLE 0x00008000
#defina STATE_SYSTEM_OFFSCREEN 0x00010000
#defina STATE_SYSTEM_SIZEABLE 0x00020000
#defina STATE_SYSTEM_MOVEABLE 0x00040000
#defina STATE_SYSTEM_SELFVOICING 0x00080000
#defina STATE_SYSTEM_FOCUSABLE 0x00100000
#defina STATE_SYSTEM_SELECTABLE 0x00200000
#defina STATE_SYSTEM_LINKED 0x00400000
#defina STATE_SYSTEM_TRAVERSED 0x00800000
#defina STATE_SYSTEM_MULTISELECTABLE 0x01000000
#defina STATE_SYSTEM_EXTSELECTABLE 0x02000000
#defina STATE_SYSTEM_ALERT_LOW 0x04000000
#defina STATE_SYSTEM_ALERT_MEDIUM 0x08000000
#defina STATE_SYSTEM_ALERT_HIGH 0x10000000
#defina STATE_SYSTEM_PROTECTED 0x20000000
#defina STATE_SYSTEM_VALID 0x3FFFFFFF
#fim_se

#defina CCHILDREN_TITLEBAR 5
#defina CCHILDREN_SCROLLBAR 5

  defina_tipo estrutura tagCURSORINFO {
    DWORD cbSize;
    DWORD flags;
    HCURSOR hCursor;
    POINT ptScreenPos;
  } CURSORINFO,*PCURSORINFO,*LPCURSORINFO;

#defina CURSOR_SHOWING 0x00000001

  WINUSERAPI WINBOOL WINAPI GetCursorInfo(PCURSORINFO pci);

  defina_tipo estrutura tagWINDOWINFO {
    DWORD cbSize;
    RECT rcWindow;
    RECT rcClient;
    DWORD dwStyle;
    DWORD dwExStyle;
    DWORD dwWindowStatus;
    UINT cxWindowBorders;
    UINT cyWindowBorders;
    ATOM atomWindowType;
    WORD wCreatorVersion;
  } WINDOWINFO,*PWINDOWINFO,*LPWINDOWINFO;

#defina WS_ACTIVECAPTION 0x0001

  WINUSERAPI WINBOOL WINAPI GetWindowInfo(HWND hwnd,PWINDOWINFO pwi);

  defina_tipo estrutura tagTITLEBARINFO {
    DWORD cbSize;
    RECT rcTitleBar;
    DWORD rgstate[CCHILDREN_TITLEBAR + 1];
  } TITLEBARINFO,*PTITLEBARINFO,*LPTITLEBARINFO;

  WINUSERAPI WINBOOL WINAPI GetTitleBarInfo(HWND hwnd,PTITLEBARINFO pti);

  defina_tipo estrutura tagMENUBARINFO {
    DWORD cbSize;
    RECT rcBar;
    HMENU hMenu;
    HWND hwndMenu;
    WINBOOL fBarFocused:1;
    WINBOOL fFocused:1;
  } MENUBARINFO,*PMENUBARINFO,*LPMENUBARINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuBarInfo(HWND hwnd,LONG idObject,LONG idItem,PMENUBARINFO pmbi);

  defina_tipo estrutura tagSCROLLBARINFO {
    DWORD cbSize;
    RECT rcScrollBar;
    inteiro dxyLineButton;
    inteiro xyThumbTop;
    inteiro xyThumbBottom;
    inteiro reserved;
    DWORD rgstate[CCHILDREN_SCROLLBAR + 1];
  } SCROLLBARINFO,*PSCROLLBARINFO,*LPSCROLLBARINFO;

  WINUSERAPI WINBOOL WINAPI GetScrollBarInfo(HWND hwnd,LONG idObject,PSCROLLBARINFO psbi);

  defina_tipo estrutura tagCOMBOBOXINFO {
    DWORD cbSize;
    RECT rcItem;
    RECT rcButton;
    DWORD stateButton;
    HWND hwndCombo;
    HWND hwndItem;
    HWND hwndList;
  } COMBOBOXINFO,*PCOMBOBOXINFO,*LPCOMBOBOXINFO;

  WINUSERAPI WINBOOL WINAPI GetComboBoxInfo(HWND hwndCombo,PCOMBOBOXINFO pcbi);

#defina GA_PARENT 1
#defina GA_ROOT 2
#defina GA_ROOTOWNER 3

  WINUSERAPI HWND WINAPI GetAncestor(HWND hwnd,UINT gaFlags);
  WINUSERAPI HWND WINAPI RealChildWindowFromPoint(HWND hwndParent,POINT ptParentClientCoords);
  WINUSERAPI UINT WINAPI RealGetWindowClassA(HWND hwnd,LPSTR ptszClassName,UINT cchClassNameMax);
  WINUSERAPI UINT WINAPI RealGetWindowClassW(HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax);
#se_definido UNICODE
#defina RealGetWindowClass RealGetWindowClassW
#senão
#defina RealGetWindowClass RealGetWindowClassA
#fim_se

  defina_tipo estrutura tagALTTABINFO {
    DWORD cbSize;
    inteiro cItems;
    inteiro cColumns;
    inteiro cRows;
    inteiro iColFocus;
    inteiro iRowFocus;
    inteiro cxItem;
    inteiro cyItem;
    POINT ptStart;
  } ALTTABINFO,*PALTTABINFO,*LPALTTABINFO;

#se_definido UNICODE
#defina GetAltTabInfo GetAltTabInfoW
#senão
#defina GetAltTabInfo GetAltTabInfoA
#fim_se

  WINUSERAPI WINBOOL WINAPI GetAltTabInfoA(HWND hwnd,inteiro iItem,PALTTABINFO pati,LPSTR pszItemText,UINT cchItemText);
  WINUSERAPI WINBOOL WINAPI GetAltTabInfoW(HWND hwnd,inteiro iItem,PALTTABINFO pati,LPWSTR pszItemText,UINT cchItemText);
  WINUSERAPI DWORD WINAPI GetListBoxInfo(HWND hwnd);
#fim_se

  WINUSERAPI WINBOOL WINAPI LockWorkStation(VOID);
  WINUSERAPI WINBOOL WINAPI UserHandleGrantAccess(HANDLE hUserHandle,HANDLE hJob,WINBOOL bGrant);

  DECLARE_HANDLE(HRAWINPUT);

#defina GET_RAWINPUT_CODE_WPARAM(wParam) ((wParam) & 0xff)

#defina RIM_INPUT 0
#defina RIM_INPUTSINK 1

  defina_tipo estrutura tagRAWINPUTHEADER {
    DWORD dwType;
    DWORD dwSize;
    HANDLE hDevice;
    WPARAM wParam;
  } RAWINPUTHEADER,*PRAWINPUTHEADER,*LPRAWINPUTHEADER;

#defina RIM_TYPEMOUSE 0
#defina RIM_TYPEKEYBOARD 1
#defina RIM_TYPEHID 2

  defina_tipo estrutura tagRAWMOUSE {
    USHORT usFlags;
    união {
      ULONG ulButtons;
      estrutura {
	USHORT usButtonFlags;
	USHORT usButtonData;
      };
    };
    ULONG ulRawButtons;
    LONG lLastX;
    LONG lLastY;
    ULONG ulExtraInformation;
  } RAWMOUSE,*PRAWMOUSE,*LPRAWMOUSE;

#defina RI_MOUSE_LEFT_BUTTON_DOWN 0x0001
#defina RI_MOUSE_LEFT_BUTTON_UP 0x0002
#defina RI_MOUSE_RIGHT_BUTTON_DOWN 0x0004
#defina RI_MOUSE_RIGHT_BUTTON_UP 0x0008
#defina RI_MOUSE_MIDDLE_BUTTON_DOWN 0x0010
#defina RI_MOUSE_MIDDLE_BUTTON_UP 0x0020

#defina RI_MOUSE_BUTTON_1_DOWN RI_MOUSE_LEFT_BUTTON_DOWN
#defina RI_MOUSE_BUTTON_1_UP RI_MOUSE_LEFT_BUTTON_UP
#defina RI_MOUSE_BUTTON_2_DOWN RI_MOUSE_RIGHT_BUTTON_DOWN
#defina RI_MOUSE_BUTTON_2_UP RI_MOUSE_RIGHT_BUTTON_UP
#defina RI_MOUSE_BUTTON_3_DOWN RI_MOUSE_MIDDLE_BUTTON_DOWN
#defina RI_MOUSE_BUTTON_3_UP RI_MOUSE_MIDDLE_BUTTON_UP

#defina RI_MOUSE_BUTTON_4_DOWN 0x0040
#defina RI_MOUSE_BUTTON_4_UP 0x0080
#defina RI_MOUSE_BUTTON_5_DOWN 0x0100
#defina RI_MOUSE_BUTTON_5_UP 0x0200

#defina RI_MOUSE_WHEEL 0x0400

#defina MOUSE_MOVE_RELATIVE 0
#defina MOUSE_MOVE_ABSOLUTE 1
#defina MOUSE_VIRTUAL_DESKTOP 0x02
#defina MOUSE_ATTRIBUTES_CHANGED 0x04

  defina_tipo estrutura tagRAWKEYBOARD {
    USHORT MakeCode;
    USHORT Flags;
    USHORT Reserved;
    USHORT VKey;
    UINT Message;
    ULONG ExtraInformation;
  } RAWKEYBOARD,*PRAWKEYBOARD,*LPRAWKEYBOARD;

#defina KEYBOARD_OVERRUN_MAKE_CODE 0xFF

#defina RI_KEY_MAKE 0
#defina RI_KEY_BREAK 1
#defina RI_KEY_E0 2
#defina RI_KEY_E1 4
#defina RI_KEY_TERMSRV_SET_LED 8
#defina RI_KEY_TERMSRV_SHADOW 0x10

  defina_tipo estrutura tagRAWHID {
    DWORD dwSizeHid;
    DWORD dwCount;
    BYTE bRawData[1];
  } RAWHID,*PRAWHID,*LPRAWHID;

  defina_tipo estrutura tagRAWINPUT {
    RAWINPUTHEADER header;
    união {
      RAWMOUSE mouse;
      RAWKEYBOARD keyboard;
      RAWHID hid;
    } data;
  } RAWINPUT,*PRAWINPUT,*LPRAWINPUT;

#se_definido _WIN64
#defina RAWINPUT_ALIGN(x) (((x) + sizeof(QWORD) - 1) & ~(sizeof(QWORD) - 1))
#senão
#defina RAWINPUT_ALIGN(x) (((x) + sizeof(DWORD) - 1) & ~(sizeof(DWORD) - 1))
#fim_se

#defina NEXTRAWINPUTBLOCK(ptr) ((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->header.dwSize)))

#defina RID_INPUT 0x10000003
#defina RID_HEADER 0x10000005

  WINUSERAPI UINT WINAPI GetRawInputData(HRAWINPUT hRawInput,UINT uiCommand,LPVOID pData,PUINT pcbSize,UINT cbSizeHeader);

#defina RIDI_PREPARSEDDATA 0x20000005
#defina RIDI_DEVICENAME 0x20000007
#defina RIDI_DEVICEINFO 0x2000000b

  defina_tipo estrutura tagRID_DEVICE_INFO_MOUSE {
    DWORD dwId;
    DWORD dwNumberOfButtons;
    DWORD dwSampleRate;
  } RID_DEVICE_INFO_MOUSE,*PRID_DEVICE_INFO_MOUSE;

  defina_tipo estrutura tagRID_DEVICE_INFO_KEYBOARD {
    DWORD dwType;
    DWORD dwSubType;
    DWORD dwKeyboardMode;
    DWORD dwNumberOfFunctionKeys;
    DWORD dwNumberOfIndicators;
    DWORD dwNumberOfKeysTotal;
  } RID_DEVICE_INFO_KEYBOARD,*PRID_DEVICE_INFO_KEYBOARD;

  defina_tipo estrutura tagRID_DEVICE_INFO_HID {
    DWORD dwVendorId;
    DWORD dwProductId;
    DWORD dwVersionNumber;
    USHORT usUsagePage;
    USHORT usUsage;
  } RID_DEVICE_INFO_HID,*PRID_DEVICE_INFO_HID;

  defina_tipo estrutura tagRID_DEVICE_INFO {
    DWORD cbSize;
    DWORD dwType;
    união {
      RID_DEVICE_INFO_MOUSE mouse;
      RID_DEVICE_INFO_KEYBOARD keyboard;
      RID_DEVICE_INFO_HID hid;
    };
  } RID_DEVICE_INFO,*PRID_DEVICE_INFO,*LPRID_DEVICE_INFO;

#se_definido UNICODE
#defina GetRawInputDeviceInfo GetRawInputDeviceInfoW
#senão
#defina GetRawInputDeviceInfo GetRawInputDeviceInfoA
#fim_se

  WINUSERAPI UINT WINAPI GetRawInputDeviceInfoA(HANDLE hDevice,UINT uiCommand,LPVOID pData,PUINT pcbSize);
  WINUSERAPI UINT WINAPI GetRawInputDeviceInfoW(HANDLE hDevice,UINT uiCommand,LPVOID pData,PUINT pcbSize);
  WINUSERAPI UINT WINAPI GetRawInputBuffer(PRAWINPUT pData,PUINT pcbSize,UINT cbSizeHeader);

  defina_tipo estrutura tagRAWINPUTDEVICE {
    USHORT usUsagePage;
    USHORT usUsage;
    DWORD dwFlags;
    HWND hwndTarget;
  } RAWINPUTDEVICE,*PRAWINPUTDEVICE,*LPRAWINPUTDEVICE;

  defina_tipo CONST RAWINPUTDEVICE *PCRAWINPUTDEVICE;

#defina RIDEV_REMOVE 0x00000001
#defina RIDEV_EXCLUDE 0x00000010
#defina RIDEV_PAGEONLY 0x00000020
#defina RIDEV_NOLEGACY 0x00000030
#defina RIDEV_INPUTSINK 0x00000100
#defina RIDEV_CAPTUREMOUSE 0x00000200
#defina RIDEV_NOHOTKEYS 0x00000200
#defina RIDEV_APPKEYS 0x00000400
#defina RIDEV_EXMODEMASK 0x000000F0
#defina RIDEV_EXMODE(mode) ((mode) & RIDEV_EXMODEMASK)

  WINUSERAPI WINBOOL WINAPI RegisterRawInputDevices(PCRAWINPUTDEVICE pRawInputDevices,UINT uiNumDevices,UINT cbSize);
  WINUSERAPI UINT WINAPI GetRegisteredRawInputDevices(PRAWINPUTDEVICE pRawInputDevices,PUINT puiNumDevices,UINT cbSize);

  defina_tipo estrutura tagRAWINPUTDEVICELIST {
    HANDLE hDevice;
    DWORD dwType;
  } RAWINPUTDEVICELIST,*PRAWINPUTDEVICELIST;

  WINUSERAPI UINT WINAPI GetRawInputDeviceList(PRAWINPUTDEVICELIST pRawInputDeviceList,PUINT puiNumDevices,UINT cbSize);
  WINUSERAPI LRESULT WINAPI DefRawInputProc(PRAWINPUT *paRawInput,INT nInput,UINT cbSizeHeader);

#fim_se /* NOUSER */

#se_definido __cplusplus
}
#fim_se
#fim_se
