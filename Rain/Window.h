#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdexcept>
#include "Entity.h"
#include "EntityLoader.h"
class Window
{
	SDL_Window *win{ nullptr };
	SDL_Renderer *ren{ nullptr };
	const Uint8*keyboardState;
	Uint32 mouseState;
	int mouseX;
	int mouseY;
	int width, height;
	bool windowShouldClose();
	SDL_Event event;
	SDL_Surface *windowSurface;
	//test
	Entity *entity;

	struct Time {
		Uint32 prevTime = 0;
		float deltaTime = 0.0f;
	} time;
public:
	Window();
	~Window();
	void loop();
private:
	void updateWindowState();
	void draw();
	void handleInput();
};

