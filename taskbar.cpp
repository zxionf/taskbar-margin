#include <iostream>
#include <windows.h>
#include <tchar.h>

int main(int argc, char* argv[]){
    int margin = 5;
    int radius = 16;
    int taskbarheight;
    int taskbarwidth;
    double globaldpi;
    RECT rect;
    HWND mainTaskbar = FindWindow(TEXT("Shell_TrayWnd"), NULL);
    HMODULE hUser32 = GetModuleHandle(TEXT("user32.dll"));
    if (hUser32) {
        typedef UINT (WINAPI *GetDpiForWindowPtr)(HWND);
        GetDpiForWindowPtr pGetDpiForWindow = (GetDpiForWindowPtr)GetProcAddress(hUser32, "GetDpiForWindow");
        if (pGetDpiForWindow) {
            UINT dpi = pGetDpiForWindow(mainTaskbar);
            globaldpi = static_cast<double>(dpi) / 96.0;
        }
    }

    // reset
    if(argc > 1 && strcmp(argv[1], "-r") == 0)
    {
        SetWindowRgn(mainTaskbar, NULL, TRUE);
        RedrawWindow(mainTaskbar, NULL, NULL, RDW_INVALIDATE | RDW_FRAME);
        return 0;
    }

    GetWindowRect(mainTaskbar, &rect);

    taskbarheight = static_cast<int>((rect.bottom - rect.top) * globaldpi + 0.5);
    taskbarwidth = static_cast<int>((rect.right) * globaldpi + 0.5);

    std::cout << "global dpi:" << globaldpi << std::endl;
    std::cout << "taskbar rect(left,right,top,bottom):" << rect.left << " " << rect.right << " " << rect.top << " " << rect.bottom << std::endl;
    std::cout << "teskbar rect height:" << (rect.bottom-rect.top) << std::endl;
    std::cout << "calculated taskbar(width,height)" << taskbarwidth << " " <<taskbarheight << std::endl;

    // rect
    // HRGN region = CreateRectRgn(margin, margin, taskbarwidth-margin, taskbarheight-margin);

    // roundedrect
    HRGN region = CreateRoundRectRgn(margin, margin, taskbarwidth-margin, taskbarheight-margin, radius, radius);

    SetWindowRgn(mainTaskbar, region, TRUE);
    RedrawWindow(mainTaskbar, NULL, NULL, RDW_INVALIDATE | RDW_FRAME | RDW_ALLCHILDREN);

    return 0;
}