/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _WINDEF_
#defina _WINDEF_

#se_não_definido STRICT
#defina STRICT 1
#fim_se

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido WINVER
#defina WINVER 0x0502
#fim_se

#se_não_definido BASETYPES
#defina BASETYPES
  defina_tipo sem_sinal longo ULONG;
  defina_tipo ULONG *PULONG;
  defina_tipo sem_sinal curto USHORT;
  defina_tipo USHORT *PUSHORT;
  defina_tipo sem_sinal caractere UCHAR;
  defina_tipo UCHAR *PUCHAR;
  defina_tipo caractere *PSZ;
#fim_se

#defina MAX_PATH 260

#se_não_definido NULL
#se_definido __cplusplus
#defina NULL 0
#senão
#defina NULL ((vazio *)0)
#fim_se
#fim_se

#se_não_definido FALSE
#defina FALSE 0
#fim_se

#se_não_definido TRUE
#defina TRUE 1
#fim_se

#se_não_definido IN
#defina IN
#fim_se

#se_não_definido OUT
#defina OUT
#fim_se

#se_não_definido OPTIONAL
#defina OPTIONAL
#fim_se

#não_definido far
#não_definido near
#não_definido pascal

#defina far
#defina near
#defina pascal __stdcall

#defina cdecl
#se_não_definido CDECL
#defina CDECL
#fim_se
#se_não_definido CALLBACK
#defina CALLBACK __stdcall
#fim_se
#se_não_definido WINAPI
#defina WINAPI __stdcall
#fim_se
#defina WINAPIV __cdecl
#defina APIENTRY WINAPI
#defina APIPRIVATE WINAPI
#defina PASCAL WINAPI
#defina WINAPI_INLINE WINAPI

#não_definido FAR
#não_definido NEAR
#defina FAR
#defina NEAR
#se_não_definido CONST
#defina CONST constante
#fim_se

  defina_tipo sem_sinal longo DWORD;
  defina_tipo inteiro WINBOOL;
#defina BOOL WINBOOL
  defina_tipo sem_sinal caractere BYTE;
  defina_tipo sem_sinal curto WORD;
  defina_tipo real FLOAT;
  defina_tipo FLOAT *PFLOAT;
  defina_tipo WINBOOL *PBOOL;
  defina_tipo WINBOOL *LPBOOL;
  defina_tipo BYTE *PBYTE;
  defina_tipo BYTE *LPBYTE;
  defina_tipo inteiro *PINT;
  defina_tipo inteiro *LPINT;
  defina_tipo WORD *PWORD;
  defina_tipo WORD *LPWORD;
  defina_tipo longo *LPLONG;
  defina_tipo DWORD *PDWORD;
  defina_tipo DWORD *LPDWORD;
  defina_tipo vazio *LPVOID;
# se_não_definido _LPCVOID_DEFINED
#defina _LPCVOID_DEFINED
defina_tipo CONST vazio *LPCVOID;
#fim_se
  defina_tipo inteiro INT;
  defina_tipo sem_sinal inteiro UINT;
  defina_tipo sem_sinal inteiro *PUINT;

#se_não_definido NT_INCLUDED
#inclua <winnt.h>
#fim_se

//gr #inclua <specstrings.h>

  defina_tipo UINT_PTR WPARAM;
  defina_tipo LONG_PTR LPARAM;
  defina_tipo LONG_PTR LRESULT;

#se_não_definido __cplusplus
#se_não_definido NOMINMAX
#se_não_definido max
#defina max(a,b) (((a) > (b)) ? (a) : (b))
#fim_se

#se_não_definido min
#defina min(a,b) (((a) < (b)) ? (a) : (b))
#fim_se
#fim_se
#fim_se

#defina MAKEWORD(a,b) ((WORD)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((WORD)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
#defina MAKELONG(a,b) ((LONG)(((WORD)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((WORD)((DWORD_PTR)(b) & 0xffff))) << 16))
#defina LOWORD(l) ((WORD)((DWORD_PTR)(l) & 0xffff))
#defina HIWORD(l) ((WORD)((DWORD_PTR)(l) >> 16))
#defina LOBYTE(w) ((BYTE)((DWORD_PTR)(w) & 0xff))
#defina HIBYTE(w) ((BYTE)((DWORD_PTR)(w) >> 8))

#se_não_definido WIN_INTERNAL
  DECLARE_HANDLE (HWND);
  DECLARE_HANDLE (HHOOK);
#se_definido WINABLE
  DECLARE_HANDLE (HEVENT);
#fim_se
#fim_se

  defina_tipo WORD ATOM;

  defina_tipo HANDLE *SPHANDLE;
  defina_tipo HANDLE *LPHANDLE;
  defina_tipo HANDLE HGLOBAL;
  defina_tipo HANDLE HLOCAL;
  defina_tipo HANDLE GLOBALHANDLE;
  defina_tipo HANDLE LOCALHANDLE;
#se_definido _WIN64
  defina_tipo INT_PTR (WINAPI *FARPROC)();
  defina_tipo INT_PTR (WINAPI *NEARPROC)();
  defina_tipo INT_PTR (WINAPI *PROC)();
#senão
  defina_tipo inteiro (WINAPI *FARPROC)();
  defina_tipo inteiro (WINAPI *NEARPROC)();
  defina_tipo inteiro (WINAPI *PROC)();
#fim_se

  defina_tipo vazio *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  defina_tipo HKEY *PHKEY;

  DECLARE_HANDLE(HACCEL);
  DECLARE_HANDLE(HBITMAP);
  DECLARE_HANDLE(HBRUSH);
  DECLARE_HANDLE(HCOLORSPACE);
  DECLARE_HANDLE(HDC);
  DECLARE_HANDLE(HGLRC);
  DECLARE_HANDLE(HDESK);
  DECLARE_HANDLE(HENHMETAFILE);
  DECLARE_HANDLE(HFONT);
  DECLARE_HANDLE(HICON);
  DECLARE_HANDLE(HMENU);
  DECLARE_HANDLE(HMETAFILE);
  DECLARE_HANDLE(HINSTANCE);
  defina_tipo HINSTANCE HMODULE;
  DECLARE_HANDLE(HPALETTE);
  DECLARE_HANDLE(HPEN);
  DECLARE_HANDLE(HRGN);
  DECLARE_HANDLE(HRSRC);
  DECLARE_HANDLE(HSTR);
  DECLARE_HANDLE(HTASK);
  DECLARE_HANDLE(HWINSTA);
  DECLARE_HANDLE(HKL);
  DECLARE_HANDLE(HMONITOR);
  DECLARE_HANDLE(HWINEVENTHOOK);
  DECLARE_HANDLE(HUMPD);

  defina_tipo inteiro HFILE;
  defina_tipo HICON HCURSOR;
  defina_tipo DWORD COLORREF;
  defina_tipo DWORD *LPCOLORREF;

#defina HFILE_ERROR ((HFILE)-1)

  defina_tipo estrutura tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  defina_tipo constante RECT *LPCRECT;

  defina_tipo estrutura _RECTL {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  defina_tipo constante RECTL *LPCRECTL;

  defina_tipo estrutura tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  defina_tipo estrutura _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  defina_tipo estrutura tagSIZE {
    LONG cx;
    LONG cy;
  } SIZE,*PSIZE,*LPSIZE;

  defina_tipo SIZE SIZEL;
  defina_tipo SIZE *PSIZEL,*LPSIZEL;

  defina_tipo estrutura tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  defina_tipo estrutura _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
  } FILETIME,*PFILETIME,*LPFILETIME;
#defina _FILETIME_

#defina DM_UPDATE 1
#defina DM_COPY 2
#defina DM_PROMPT 4
#defina DM_MODIFY 8

#defina DM_IN_BUFFER DM_MODIFY
#defina DM_IN_PROMPT DM_PROMPT
#defina DM_OUT_BUFFER DM_COPY
#defina DM_OUT_DEFAULT DM_UPDATE

#defina DC_FIELDS 1
#defina DC_PAPERS 2
#defina DC_PAPERSIZE 3
#defina DC_MINEXTENT 4
#defina DC_MAXEXTENT 5
#defina DC_BINS 6
#defina DC_DUPLEX 7
#defina DC_SIZE 8
#defina DC_EXTRA 9
#defina DC_VERSION 10
#defina DC_DRIVER 11
#defina DC_BINNAMES 12
#defina DC_ENUMRESOLUTIONS 13
#defina DC_FILEDEPENDENCIES 14
#defina DC_TRUETYPE 15
#defina DC_PAPERNAMES 16
#defina DC_ORIENTATION 17
#defina DC_COPIES 18

#se_definido __cplusplus
}
#fim_se
#fim_se
