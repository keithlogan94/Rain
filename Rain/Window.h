#pragma once
#include <SDL.h>
#include <string>
#include <stdexcept>
#include <memory>
#include "Player.h"
#include "EntityLoader.h"
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
	Player * p;
	EntityLoader loader;
	SDL_Texture *background;
	int height, width;
public:
	Window();
	~Window();
	void loop();
private:
	void updateWindowState();
	void draw();
	SDL_Texture* loadTexture(const char *imagePath);
};

