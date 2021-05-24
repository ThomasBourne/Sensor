#pragma once
#include "shapes.hpp"
//#include <fcntl.h>
namespace sensor_win {
	struct setup {
		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;

		const wchar_t* CONSOLE_SETUP;

		setup(int SCREEN_WIDTH, int SCREEN_HEIGHT, const wchar_t* CONSOLE_SETUP = L"Terminal required : DO NOT TERMINATE") {
			this->SCREEN_WIDTH = SCREEN_WIDTH;
			this->SCREEN_HEIGHT = SCREEN_HEIGHT;
			this->CONSOLE_SETUP = CONSOLE_SETUP;
		}
		//add other perams
	};
}
namespace sensor {
	struct rgb { //optimise so there is an array[3] not sperate variables
		unsigned int red;
		unsigned int green;
		unsigned int blue;
		rgb(int red = 0, int green = 0, int blue = 0) {
			if (red <= 255 && green <= 255 && blue <= 255) {
				this->red	= red;
				this->green = green;
				this->blue	= blue;
			}
			else {
				this->red	= 0;
				this->green = 0;
				this->blue	= 0;
			}
		}
	};
}