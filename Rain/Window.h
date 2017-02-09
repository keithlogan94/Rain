#pragma once
#include <SDL.h>
#include <string>
#include <stdexcept>
#include <memory>
class Window
{
	SDL_Window *win;
	SDL_Renderer *ren;
	const Uint8* keyboardState;
	Uint32 mouseState;
	int mouseX;
	int mouseY;
	bool windowShouldClose();
	SDL_Event event;
	SDL_Surface *winSurface;
public:
	Window();
	~Window();
	void loop();
private:
	void updateWindowState();
	void draw();
};

