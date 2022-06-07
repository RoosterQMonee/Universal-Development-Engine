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
# include <time.h>
# include <stdio.h>
# include <windows.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int utc(void)
{
    time_t t;
    struct tm *tmp;

    t = time(NULL);
    tmp = localtime(&t);

    return t;
}

int date(void)
{
    time_t t;
    struct tm *tmp;

    t = time(NULL);
    tmp = localtime(&t);

    printf("%d-%d-%d %d:%d:%d\n", tmp->tm_year + 1900, tmp->tm_mon + 1, tmp->tm_mday, tmp->tm_hour, tmp->tm_min, tmp->tm_sec);
}


int sleep(int milliseconds)
{
    Sleep(milliseconds);
    return 0;
}

int fps(int fps)
{
    return 1000 / fps;
}
# include <windows.h>
# include <winuser.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// create a window with the title and size as arguments


HWND create_window(char *title, int width, int height) {
    HINSTANCE hInstance = GetModuleHandle(NULL);
    WNDCLASSEX wc;
    HWND hWnd;

    // set the window class parameters
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = DefWindowProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = title;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    // register the window class
    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
                    MB_ICONEXCLAMATION | MB_OK);

        return NULL;
    }

    // create the window
    hWnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        title,
        title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        NULL, NULL, hInstance, NULL
    );

    // check if the window was created
    if (hWnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
                    MB_ICONEXCLAMATION | MB_OK);

        return NULL;
    }

    // show the window
    //ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    return hWnd;
}


// add a button to a previously created window


HWND add_button(HWND hWnd, char *text, int x, int y, int width, int height) {
    HWND hButton;

    hButton = CreateWindow(
        "button",
        text,
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        x, y, width, height,
        hWnd,
        (HMENU)1,
        GetModuleHandle(NULL),
        NULL
    );

    return hButton;
}


// add a label to a previously created window


HWND add_label(HWND hWnd, char *text, int x, int y, int width, int height) {
    HWND hLabel;

    hLabel = CreateWindow(
        "static",
        text,
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | SS_LEFT,
        x, y, width, height,
        hWnd,
        (HMENU)1,
        GetModuleHandle(NULL),
        NULL
    );

    return hLabel;
}


// add a textbox to a previously created window


HWND add_textbox(HWND hWnd, int x, int y, int width, int height) {
    HWND hTextbox;

    hTextbox = CreateWindow(
        "edit",
        "",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | ES_LEFT | ES_AUTOHSCROLL,
        x, y, width, height,
        hWnd,
        (HMENU)1,
        GetModuleHandle(NULL),
        NULL
    );

    return hTextbox;
}


// add a combobox to a previously created window


HWND add_combobox(HWND hWnd, int x, int y, int width, int height) {
    HWND hCombobox;

    hCombobox = CreateWindow(
        "combobox",
        "",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
        x, y, width, height,
        hWnd,
        (HMENU)1,
        GetModuleHandle(NULL),
        NULL
    );

    return hCombobox;
}


// add a listbox to a previously created window


HWND add_listbox(HWND hWnd, int x, int y, int width, int height) {
    HWND hListbox;

    hListbox = CreateWindow(
        "listbox",
        "",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY,
        x, y, width, height,
        hWnd,
        (HMENU)1,
        GetModuleHandle(NULL),
        NULL
    );

    return hListbox;
}


// add a checkbox to a previously created window


HWND add_checkbox(HWND hWnd, char *text, int x, int y, int width, int height) {
    HWND hCheckbox;

    hCheckbox = CreateWindow(
        "button",
        text,
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
        x, y, width, height,
        hWnd,
        (HMENU)1,
        GetModuleHandle(NULL),
        NULL
    );

    return hCheckbox;
}


// function to add to a listbox


void add_to_listbox(HWND hListbox, char *text) {
    SendMessage(hListbox, LB_ADDSTRING, 0, (LPARAM)text);
}


// Add properties


HWND new_listbox(HWND hWnd, int x, int y, int width, int height) {
    HWND hListbox = add_listbox(hWnd, x, y, width, height);
    //ShowWindow(hListBox, SW_SHOW);
    UpdateWindow(hListbox);

    return hListbox;
}


HWND new_combobox(HWND hWnd, int x, int y, int width, int height) {
    HWND hComboBox = add_combobox(hWnd, x, y, width, height);
    //ShowWindow(hComboBox, SW_SHOW);
    UpdateWindow(hComboBox);

    return hComboBox;
}


HWND new_checkbox(HWND hWnd, char *text, int x, int y, int width, int height) {
    HWND hCheckbox = add_checkbox(hWnd, text, x, y, width, height);
    //ShowWindow(hCheckbox, SW_SHOW);
    UpdateWindow(hCheckbox);

    return hCheckbox;
}


HWND new_textbox(HWND hWnd, int x, int y, int width, int height) {
    HWND hTextBox = add_textbox(hWnd, x, y, width, height);
    //ShowWindow(hTextBox, SW_SHOW);
    UpdateWindow(hTextBox);

    return hTextBox;
}


HWND new_label(HWND hWnd, char *text, int x, int y, int width, int height) {
    HWND hLabel = add_label(hWnd, text, x, y, width, height);
    //ShowWindow(hLabel, SW_SHOW);
    UpdateWindow(hLabel);

    return hLabel;
}


HWND new_button(HWND hWnd, char *text, int x, int y, int width, int height) {
    HWND hButton = add_button(hWnd, text, x, y, width, height);
    //ShowWindow(hButton, SW_SHOW);
    UpdateWindow(hButton);

    return hButton;
}


int update(HWND hWnd) {
    MSG msg;
    ShowWindow(hWnd, SW_SHOW);

    while (GetMessage(&msg, NULL, 0, 0)) {

        TranslateMessage(&msg);
        DispatchMessage(&msg);

        if (msg.message == WM_QUIT) {

            return msg.wParam;

        }

        if (msg.message == WM_CLOSE) {

            return msg.wParam;

        }

        if (msg.message == WM_DESTROY) {

            return msg.wParam;

        }

        if (msg.message == WM_COMMAND) {

            return msg.wParam;

        }

        if (msg.message == WM_KEYDOWN) {

            return msg.wParam;

        }

        if (msg.message == WM_KEYUP) {

            return msg.wParam;

        }

        if (msg.message == WM_CHAR) {

            return msg.wParam;

        }   

        if (msg.message == WM_LBUTTONDOWN) {

            return msg.wParam;

        }

        if (msg.message == WM_RBUTTONDOWN) {

            return msg.wParam;

        }

        if (msg.message == WM_MBUTTONDOWN) {

            return msg.wParam;

        }

        if (msg.message == WM_MOUSEMOVE) {

            return msg.wParam;

        }

        if (msg.message == WM_MOUSEWHEEL) {

            return msg.wParam;

        }

        if (msg.message == WM_MOUSELEAVE) {

            return msg.wParam;

        }

        if (msg.message == WM_MOUSEHOVER) {

            return msg.wParam;

        }

        if (msg.message == WM_MOUSEACTIVATE) {

            return msg.wParam;

        }

        return 0;
    }
}


LRESULT get_textbox_text(HWND hTextbox) {
    return SendMessage(hTextbox, WM_GETTEXT, 0, 0);
}


// check state of a checkbox


int check_checkbox(HWND hCheckbox) {
    return SendMessage(hCheckbox, BM_GETCHECK, 0, 0);
}


// check state of a button


int get_button_state(HWND hButton) {
    int state = SendMessage(hButton, BM_GETSTATE, 0, 0);

    return state;
}


BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
  Sleep(1);
  DWORD wndPid;
  char Title[1024];

  GetWindowThreadProcessId(hwnd, &wndPid);

  GetWindowText(hwnd,Title,1024);
  if ( wndPid == (DWORD)lParam && strlen(Title) != 0)
  {
    PostMessage(hwnd, WM_CLOSE, 0, 0);
    return 0;
  }
  else
  {
    return 1;
  }
}


// function to close a window


void close_window(HWND hWnd) {
    PostMessage(hWnd, WM_CLOSE, 0, 0);
}


void message_box(char *text, char* title) {
    MessageBox(NULL, text, title, MB_OK);
}


// function to change the text of a label


void set_label_text(HWND hLabel, char *text) {
    SetWindowText(hLabel, text);
}


// function to change the text of a textbox


void set_textbox_text(HWND hTextbox, char *text) {
    SetWindowText(hTextbox, text);
}


// function to change the text of a button


void set_button_text(HWND hButton, char *text) {
    SetWindowText(hButton, text);
}



