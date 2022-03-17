#include <windows.h>
#include "FaceApp.h"
HANDLE hFile;

DWORD dwBytesRead = 0;

WCHAR ReadBuffer[200] = { (WCHAR)("fasfasf") };
TCHAR stdPath[80] = TEXT("C:\\Users\\Admin\\source\\repos\\FaceApp-CPP\\out\\build\\x64-Debug\\FaceApp\\info.txt");
static LRESULT WindowProc(HWND h, UINT msg, WPARAM wp, LPARAM lp) {
    /* More info at [2] */
    switch (msg)
    {
        /*                                                              */
        /* Add a win32 push button and do something when it's clicked.  */
        /* Google will help you with the other widget types.  There are */
        /* many tutorials.                                              */
        /*                                                              */
    case WM_CREATE: {
        HWND hbutton = CreateWindow("BUTTON", "EXIT",  /* class and title */
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, /* style */
            500, 350, 100, 30,            /* position */
            h,                     /* parent */
            (HMENU)101,            /* unique (within the application) integer identifier */
            GetModuleHandle(0), 0   /* GetModuleHandle(0) gets the hinst */
        );
        HWND bbutton = CreateWindow("BUTTON", "START",  /* class and title */
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, /* style */
            500, 150, 100, 30,            /* position */
            h,                     /* parent */
            (HMENU)102,            /* unique (within the application) integer identifier */
            GetModuleHandle(0), 0   /* GetModuleHandle(0) gets the hinst */
        );
        HWND cbutton = CreateWindow("BUTTON", "Info",  /* class and title */
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, /* style */
            500, 250, 100, 30,            /* position */
            h,                     /* parent */
            (HMENU)103,            /* unique (within the application) integer identifier */
            GetModuleHandle(0), 0   /* GetModuleHandle(0) gets the hinst */
        );
    } break;

    case WM_COMMAND: {
        switch (LOWORD(wp)) {
        case 103:
            hFile = CreateFile(stdPath    ,       // file to open

                GENERIC_WRITE,          // open for reading

                FILE_SHARE_WRITE,    // share for reading

                NULL,                  // default security

                OPEN_EXISTING,         // existing file only

                FILE_ATTRIBUTE_NORMAL, // normal file

                NULL);                 // no attr. template

            WriteFile(hFile, ReadBuffer, 256, NULL, NULL);
            CloseHandle(hFile);
            break;

        case 102:
            DestroyWindow(h);
            mabc();
            PostQuitMessage(0);
            break;
        case 101: /* the unique identifier used above. These are usually #define's */
            PostQuitMessage(0);
            break;
        default:;
        }
    } break;


        /*                                 */
        /* Minimally need the cases below: */
        /*                                 */
    case WM_CLOSE: PostQuitMessage(0); break;
    default:
        return DefWindowProc(h, msg, wp, lp);
    }
    return 0;
}

int WinMain(HINSTANCE hinst,
    HINSTANCE hprev,
    LPSTR     cmdline,
    int       show) {
    if (!hprev) {
        WNDCLASS c = { 0 };
        c.lpfnWndProc = WindowProc;
        c.hInstance = hinst;
        c.hIcon = LoadIcon(0, IDI_APPLICATION);
        c.hCursor = LoadCursor(0, IDC_ARROW);
        c.lpszClassName = "MainWindow";
        RegisterClass(&c);
    }
    
    HWND h = CreateWindow("MainWindow",          /* window class name*/
        "WindowTitle",              /* title  */
        WS_OVERLAPPEDWINDOW,        /* style */
        CW_USEDEFAULT, CW_USEDEFAULT,/* position */
        CW_USEDEFAULT, CW_USEDEFAULT,/* size */
        0,                          /* parent */
        0,                          /* menu */
        hinst,
        0                           /* lparam -- crazytown */
    );
    ShowWindow(h, show);

    while (1) {  /* or while(running) */
        MSG msg;
        while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) { /* See Note 3,4 */
            if (msg.message == WM_QUIT)
                return (int)msg.wParam;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return 0;
}

/* NOTES
 1. when googling for api docs, etc. prefix everything with msdn.  e.g: msdn winmain
 2. prefer msdn docs to stack overflow for most things.
    When in doubt look for Raymond Chen's blog "The Old New Thing."
 3. Overview of the event loop is at [1].
 4. This event-loop spins when no events are available, consuming all available cpu.
    Also see GetMessage, which blocks until the next message is received.
    Use PeekMessage when you want your application loop to do something while not recieving
    events from the message queue.  You would do that work after the while(PeekMessage(...))
    block.
*/
/* REFERENCES
  [1] : https://msdn.microsoft.com/en-us/library/windows/desktop/ms644927%28v=vs.85%29.aspx
  [2]: https://msdn.microsoft.com/en-us/library/windows/desktop/ms633570(v=vs.85).aspx#designing_proc
*/