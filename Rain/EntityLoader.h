#pragma once
#include <SDL.h>
struct EntityLoader {
	const char* imagePath = nullptr;
	SDL_Renderer *ren = nullptr;
	int startingLocX = 0;
	int startingLocY = 0;
	int width = 0;
	int height = 0;
};