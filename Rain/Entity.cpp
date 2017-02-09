#include "Entity.h"
#include "EntityLoader.h"


Entity::Entity(EntityLoader entity)
{
	position = entity.startingPositon;
	size.w = entity.width;
	size.h = entity.height;
	drawPriority = entity.drawPriority;
	ren = entity.ren;
}


Entity::~Entity()
{
}

void Entity::click(const int x, const int y, Uint32 mouseState)
{
	if ((mouseState & SDL_BUTTON(SDL_BUTTON_LEFT) || 
		mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT)) && 
		x >= position.x && x <= position.x + size.w &&
		y >= position.y && y <= position.y + size.h) {
		if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))
			objectLeftClicked();
		if (mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT))
			objectRightClicked();
	}
}

void Entity::hover(const int x, const int y)
{
	if (x >= position.x && x <= position.x + size.w &&
		y >= position.y && y <= position.y + size.h) {
		objectHovered();
	}
}
