#pragma once
#include <SDL.h>
#include "EntityLoader.h"
class Entity
{
	/* maybe I have a class of movement that is owned by this class
	and then I have a classes run walk attack1 attack2 lose hit idle idle2 jump walk
	*/
protected:
	SDL_Rect rect;
public:
	Entity(const EntityLoader& loader);

	virtual ~Entity();
	virtual void update() = 0;
	virtual void draw() = 0;
	const SDL_Rect& getRect() const { return rect; }
};

