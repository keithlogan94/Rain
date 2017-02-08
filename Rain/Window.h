#pragma once
#include <SDL.h>
#include <string>
#include <stdexcept>
class Window
{
	SDL_Window *win{ nullptr };
	SDL_Renderer *ren{ nullptr };
	const Uint8*keyboardState;
	Uint32 mouseState;
	int mouseX;
	int mouseY;
	bool windowShouldClose();
	SDL_Event event;
	SDL_Surface *windowSurface;
public:
	Window();
	~Window();
	void loop();
private:
	void updateWindowState();
	void draw();
};

