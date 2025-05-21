//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#inclua <windows.h>

vazio hello_func (vazio);
__declspec(dllimport) externo constante caractere *hello_data;

inteiro WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    inteiro       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    retorne 0;
}
