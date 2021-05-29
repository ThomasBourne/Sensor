#pragma once
#include "shapes.hpp"
#include <windows.h> //includes for the winod to open as well
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <fstream>
namespace sensor_win {
	struct setup {
		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;

		const wchar_t* CONSOLE_SETUP;

		const wchar_t* WIN_TITLE;

		long MAXIMIZE = 0x00000000L;

		setup(int SCREEN_WIDTH, int SCREEN_HEIGHT, const wchar_t* WIN_TITLE = L"SENSOR Project", bool maximaise = false, const wchar_t* CONSOLE_SETUP = L"Terminal required : DO NOT TERMINATE") {
			this->SCREEN_WIDTH = SCREEN_WIDTH;
			this->SCREEN_HEIGHT = SCREEN_HEIGHT;
			this->CONSOLE_SETUP = CONSOLE_SETUP;
			this->WIN_TITLE = WIN_TITLE;
			if (maximaise)
				this->MAXIMIZE = 0x01000000L;
		}
		//add other perams
	};
}
namespace sensor {
	struct rgb {
		BYTE RGB[3]; //no need to specify unsigned char as there is a typedef for it (BYTE)
		rgb(int red = 0, int green = 0, int blue = 0) {
			this->RGB[0]	= red;
			this->RGB[1]	= green;
			this->RGB[2]	= blue;
		}
		static COLORREF convert(rgb obj) {
			return ((COLORREF)(((BYTE)(obj.RGB[0]) | ((WORD)((BYTE)(obj.RGB[1])) << 8)) | (((DWORD)(BYTE)(obj.RGB[2])) << 16)));
		}
	};

	//basic struct for premade colours colours
	struct colours {
		const rgb
			black = rgb(0, 0, 0),
			red = rgb(255, 0, 0),
			green = rgb(0, 255, 0),
			blue = rgb(0, 0, 255),
			purple = rgb(128, 0, 128),
			pink = rgb(255, 192, 203),
			magenta = rgb(255, 0, 255),
			turquoise = rgb(64, 244, 208),
			grey = rgb(128, 128, 128),
			orange = rgb(255, 69, 0),
			yellow = rgb(255, 255, 0),
			indigo = rgb(75, 0, 130),
			white = rgb(255, 255, 255);
	}Colour;
}