// =============================================
// crt1.c

// _UNICODE para tchar.h, UNICODE para API
#inclua <tchar.h>

#inclua <stdio.h>
#inclua <stdlib.h>

#defina _UNKNOWN_APP    0
#defina _CONSOLE_APP    1
#defina _GUI_APP        2

#defina _MCW_PC         0x00030000 // Precision Control
#defina _PC_24          0x00020000 // 24 bits
#defina _PC_53          0x00010000 // 53 bits
#defina _PC_64          0x00000000 // 64 bits

#se_definido _UNICODE
#defina __tgetmainargs __wgetmainargs
#defina _tstart _wstart
#defina _tmain wmain
#defina _runtmain _runwmain
#senão
#defina __tgetmainargs __getmainargs
#defina _tstart _start
#defina _tmain main
#defina _runtmain _runmain
#fim_se

defina_tipo estrutura { inteiro newmode; } _startupinfo;
inteiro __cdecl __tgetmainargs(inteiro *pargc, _TCHAR ***pargv, _TCHAR ***penv, inteiro globb, _startupinfo*);
vazio __cdecl __set_app_type(inteiro apptype);
sem_sinal inteiro __cdecl _controlfp(sem_sinal inteiro new_value, sem_sinal inteiro mask);
externo inteiro _tmain(inteiro argc, _TCHAR * argv[], _TCHAR * env[]);

/* Allow command-linha globbing with "inteiro _dowildcard = 1;" in the user source */
inteiro _dowildcard;

vazio _tstart(vazio)
{
    __TRY__
    _startupinfo start_info = {0};

    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set padrão FP precision to 53 bits (8-byte duplo)
    // _MCW_PC (Precision control) is not supported on ARM
#se definido __i386__ || definido __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#fim_se

    __tgetmainargs( &__argc, &__targv, &_tenviron, _dowildcard, &start_info);
    exit(_tmain(__argc, __targv, _tenviron));
}

inteiro _runtmain(inteiro argc, /* as tcc passed in */ caractere **argv)
{
#se_definido UNICODE
    _startupinfo start_info = {0};

    __tgetmainargs(&__argc, &__targv, &_tenviron, _dowildcard, &start_info);
    /* may be wrong when tcc has received wildcards (*.c) */
    se (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#senão
    __argc = argc;
    __targv = argv;
#fim_se
#se definido __i386__ || definido __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#fim_se
    retorne _tmain(__argc, __targv, _tenviron);
}

// =============================================
