#include "Window.h"



Window::Window()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::string errLog;
		errLog.append(SDL_GetError());
		errLog.append(" : error with initializing: SDL_Init() : in Main.cpp");
		throw std::logic_error{ errLog.c_str() };
	}
	SDL_CreateWindowAndRenderer(1080, 680, SDL_WINDOW_RESIZABLE, &win, &ren);
	SDL_SetWindowTitle(win, "2D Game");
	if (!win && !ren) {
		throw std::logic_error{ "error window or renderer was not created successfully : " 
			"SDL_CreateWindowAndRenderer(...) : Window.cpp"};
	}
}


Window::~Window()
{
	SDL_Quit();
}
