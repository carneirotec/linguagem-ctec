//+---------------------------------------------------------------------------
//
//  dll.c - Windows DLL example - dynamically linked part
//

#inclua <windows.h>

__declspec(dllexport) constante caractere *hello_data = "(not set)";

__declspec(dllexport) vazio hello_func (vazio)
{
    MessageBox (0, hello_data, "From DLL", MB_ICONINFORMATION);
}
