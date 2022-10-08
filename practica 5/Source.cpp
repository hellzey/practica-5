#include <windows.h>
#include "resource.h"

HWND ghDlg = 0;
int x = rand()% 100 + 1;
int y = rand() % 100 + 1;
BOOL CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);



int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow)
{
    ghDlg = CreateDialog(hInstance, MAKEINTRESOURCE(101), 0, (DLGPROC)WindowProc);
    ShowWindow(ghDlg, nCmdShow);
    MSG msg;
    ZeroMemory(&msg, sizeof(MSG));
        while (GetMessage(&msg, 0, 0, 0))
    {
        if (ghDlg == 0 || !IsDialogMessage(ghDlg, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int)msg.wParam;
}

BOOL CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {

    case WM_INITDIALOG:
        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case 1001:
             int x = rand() % 500 + 1;
            int y = rand() % 500 + 1;
            SetWindowPos(hwnd, NULL, x, y, 400, 400, SWP_SHOWWINDOW);
           
            break;
        }
        break;
    case WM_CLOSE:
        int opc = MessageBox(NULL, L"¿Seguro que desea salir?.", L"Alerta", MB_OKCANCEL | MB_DEFBUTTON2);
        if (opc == 1) {
            WM_DESTROY;
            PostQuitMessage(0);
           
        }
        else {
            int x = rand() % 500 + 1;
            int y = rand() % 500 + 1;
        SetWindowPos(hwnd, NULL, x, y, 400, 400, SWP_SHOWWINDOW);
        }
      
        break;
  

   

    }

    return FALSE;
}