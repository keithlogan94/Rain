#pragma once
#include <SDL.h>
#include <string>
#include <stdexcept>
class Window
{
	SDL_Window *win{ nullptr };
	SDL_Renderer *ren{ nullptr };
public:
	Window();
	~Window();
};

