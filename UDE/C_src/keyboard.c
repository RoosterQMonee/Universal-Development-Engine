# include <windows.h>
# include <winuser.h>
# include <stdio.h>


int get_key_id(void)
{
    int key;
    key = GetKeyState(VK_LBUTTON);
    return key;
}

  
int get_keypresses(HWND hWnd) {
    MSG msg;

    GetMessage(&msg, NULL, 0, 0);

    TranslateMessage(&msg);
    DispatchMessage(&msg);

    return msg.wParam;

}