#pragma once
#include <string>
extern const char* KEY_UP		=		"w"; //figure out how to implement arrow keys and fn keys
extern const char* KEY_LEFT		=		"a"; //might need just const char and do conversion
extern const char* KEY_DOWN		=		"s";
extern const char* KEY_RIGHT	=		"d";

extern const char* KEY_W		=		"w";
extern const char* KEY_A		=		"a";
extern const char* KEY_S		=		"s";
extern const char* KEY_D		=		"d"; //add more if you can be bothered

//let user change for custom key bindings
extern const char* BIND_UP		[2]	=	{ KEY_UP,	KEY_W				}; //implement bind checking later
extern const char* BIND_LEFT	[2]	=	{ KEY_LEFT, KEY_A				};
extern const char* BIND_DOWN	[2]	=	{ KEY_DOWN, KEY_S				};
extern const char* BIND_RIGHT	[2]	=	{ KEY_RIGHT,KEY_D				};