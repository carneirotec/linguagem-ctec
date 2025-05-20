//+---------------------------------------------------------------------------

// _UNICODE para tchar.h, UNICODE para API
#inclua <tchar.h>

#inclua <windows.h>
#inclua <stdlib.h>

#defina __UNKNOWN_APP    0
#defina __CONSOLE_APP    1
#defina __GUI_APP        2
vazio __set_app_type(inteiro);
vazio _controlfp(sem_sinal a, sem_sinal b);

#se_definido _UNICODE
#defina __tgetmainargs __wgetmainargs
#defina _twinstart _wwinstart
#defina _runtwinmain _runwwinmain
inteiro APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, inteiro);
#senão
#defina __tgetmainargs __getmainargs
#defina _twinstart _winstart
#defina _runtwinmain _runwinmain
#fim_se

defina_tipo estrutura { inteiro newmode; } _startupinfo;
inteiro __cdecl __tgetmainargs(inteiro *pargc, _TCHAR ***pargv, _TCHAR ***penv, inteiro globb, _startupinfo*);

estático inteiro go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    inteiro fShow;

    GetStartupInfo(&si);
    se (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    senão
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    se (arg1)
        szCmd = _tcsstr(p, arg1);
    se (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    senão se (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#se definido __i386__ || definido __x86_64__
    _controlfp(0x10000, 0x30000);
#fim_se
    retorne _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
}

inteiro _twinstart(vazio)
{
    __TRY__
    _startupinfo start_info_con = {0};
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

inteiro _runtwinmain(inteiro argc, /* as tcc passed in */ caractere **argv)
{
#se_definido UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    se (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#senão
    __argc = argc, __targv = argv;
#fim_se
    retorne go_winmain(__argc > 1 ? __targv[1] : NULL);
}
