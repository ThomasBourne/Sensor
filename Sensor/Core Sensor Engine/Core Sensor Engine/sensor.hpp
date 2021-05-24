#pragma once
/* TODO
* fix the enum for default colours thowing error for [not being able to convert to const] see more below
* switch from console app to win32 and open a terminal win still
* acc build it now lol gd luck
*/
//files for programmer to use
#include "vector.hpp"
#include "shapes.hpp"

//files for window handle and i/o
#include "window.h"
#include "iosensor.hpp"

//THINGS FOR SEPERATE THREADS:

//audio
#include "audio.hpp"

//basic enum for colours
/*namespace sensor {
    enum class stdColour {
	    black		=		rgb	(0,		0,		0	),
	    red			=		rgb	(255,	0,		0	),
	    green		=		rgb	(0,		255,	0	),
	    blue		=		rgb	(0,		0,		255	),
	    purple		=		rgb	(128,	0,		128	),
	    pink		=		rgb	(255,	192,	203	),
	    magenta		=		rgb	(255,	0,		255	),
	    turquoise	=		rgb	(64,	244,	208	),
	    grey		=		rgb	(128,	128,	128	),
	    orange		=		rgb	(255,	69,		0	),
	    yellow		=		rgb	(255,	255,	0	),
	    indigo		=		rgb	(75,	0,		130	),
	    white		=		rgb	(255,	255,	255	)
    };
}*/

//add non static print func for vec2, line, tri, rect

sensor_win::setup inline PreDef();
int SensorMain(sensor::vec2i);

int main() {
    sensor_win::setup S = PreDef();
    sensor::vec2i RES = sensor::vec2i(S.SCREEN_WIDTH, S.SCREEN_HEIGHT);

    SetConsoleTitle(S.CONSOLE_SETUP);
    return SensorMain(RES);
}
/*

	AllocConsole();
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);
	freopen("conout$", "w", stderr);

	sensor_win::setup S = PreDef();
	sensor::vec2i RES = sensor::vec2i(S.SCREEN_WIDTH, S.SCREEN_HEIGHT);

	SetConsoleTitle(S.CONSOLE_SETUP);
	//std::thread game(SensorMain, RES);
	//std::thread audio(Audio);

	//game.join();
	//audio.join();
	//std::thread audio;
	//audio(Audio/*, 42000, L"track1", 1);
	//audio.join();
	SensorMain(RES);
*/

/*LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    sensor_win::setup S = PreDef();
    sensor::vec2i RES = sensor::vec2i(S.SCREEN_WIDTH, S.SCREEN_HEIGHT);

    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        S.CONSOLE_SETUP,                // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);



        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}*/