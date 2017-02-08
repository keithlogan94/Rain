#include "Entity.h"



Entity::Entity(const EntityLoader& loader)
{
	ren = loader.ren;
	position.x = loader.startingLocX;
	position.y = loader.startingLocY;
	positionRect.w = loader.width;
	positionRect.h = loader.height;
	SDL_Surface *surface = IMG_Load(loader.imagePath);
	if (!surface) {
		throw std::runtime_error{ "error loading image : "
			"IMG_Load() : Entity.cpp" };
	}
	texture = SDL_CreateTextureFromSurface(loader.ren, surface);
	if (!texture) {
		throw std::runtime_error{ "error creating texture from surface"
			" : SDL_CreateTextureFromSurface() : Entity.cpp" };
	}
	SDL_FreeSurface(surface);
}


Entity::~Entity()
{
	SDL_DestroyTexture(texture);
}

void Entity::draw()
{
	/* to iliminate extra calls to be made I should implement the movement of 
	of this entity here... */
	//move...
	while (movementQueue.size()) {
		position += movementQueue.front();
		movementQueue.pop();
	}

	/* set the drawing rect position to the 'position' of
	this current entity */
	positionRect.x = position.x;
	positionRect.y = position.y;
	SDL_RenderCopy(ren, texture, NULL, &positionRect);
	/* in the future maybe call other drawing methods of  agragated objects
	that add to the looks of this entity */
}

void Entity::addMovementVector(const glm::vec2& movementVec2, float deltaTime)
{
	//magnitude == sqrt( square(movement.x) + square(movement.y) )
	//direction == normalize(vector)
	float magnitude = sqrt( pow(movementVec2.x, 2) + pow(movementVec2.y, 2) );
	glm::vec2 direction = glm::normalize(movementVec2);
	direction *= magnitude;
	const float slow = 0.30f;
	direction *= slow;
	direction *= deltaTime;
	movementQueue.push(direction);
}
