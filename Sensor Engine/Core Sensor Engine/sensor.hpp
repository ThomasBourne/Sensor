#pragma once
/* TODO
* acc build it now lol gd luck
* check sensor::vec2<T>::Point2() works
* make mesh work as even though it compiles it is bad
* make audio engine work by using threading
* move input from terminal to the actual window
* fix terminal as printf and cout do nothing at the moment
*/

/* ERRORS
* The window that is being rendered is the second frame as when the rect is moved it only moves one of the amount
  so the window needs to be refreshed and also figure out how to render first frame as well as a nice to have
* Terminal broke lol
*/


//files for programmer to use
#include "vector.hpp"
#include "shapes.hpp"

//files for window handle and i/o
#include "window.h"
#include "iosensor.hpp"

//THINGS FOR SEPERATE THREADS:

//audio
#include <thread>
#include "audio.hpp"


//change static print values to non static functions

sensor_win::setup inline PreDef();
int inline SensorUpdate(HDC);


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void DrawPixels(HWND hwnd);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PWSTR lpCmdLine, int nCmdShow) {

    sensor_win::setup S = PreDef(); //settings for window

    AllocConsole(); //calls console
    freopen("conin$", "r", stdin); //handles stream in
    freopen("conout$", "w", stdout); //handles stream out
    freopen("conout$", "w", stderr); //handles stream exeptions
    SetConsoleTitle(S.CONSOLE_SETUP);

    MSG  msg;
    WNDCLASSW wc = { 0 };

    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpszClassName = S.WIN_TITLE;
    wc.hInstance = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc = WndProc;
    wc.hCursor = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, (LPCWSTR)S.WIN_TITLE,
        WS_OVERLAPPEDWINDOW | WS_VISIBLE | S.MAXIMIZE | WS_BORDER | WS_TILED,
        100, 100, S.SCREEN_WIDTH, S.SCREEN_HEIGHT, NULL, NULL, hInstance, NULL);

    while (GetMessage(&msg, NULL, 0, 0)) {

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam) {

    switch (msg) {

    case WM_PAINT:

        DrawPixels(hwnd);
        //RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
        KEY::RESET();
        break;

    case WM_KEYDOWN:
        if (wParam != 0x00)
            InvalidateRect(hwnd, NULL, TRUE);
        if (wParam == 0x57)
            KEY::W = true;
        else if (wParam == 0x41)
            KEY::A = true;
        else if (wParam == 0x53)
            KEY::S = true;
        else if (wParam == 0x44)
            KEY::D = true;
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void DrawPixels(HWND hwnd) {

    PAINTSTRUCT ps;

    HDC hdc = BeginPaint(hwnd, &ps);

    SensorUpdate(hdc);

    EndPaint(hwnd, &ps);
}