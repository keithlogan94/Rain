#pragma once
#include <SDL.h>
#include <SDL_image.h>
class Entity
{
	SDL_Surface *mainSurface;
public:
	Entity();
	virtual ~Entity();
};

