#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "EntityLoader.h"
#include <exception>
#include <stdexcept>
#include <vec2.hpp>
#include <queue>
#include <math.h>
#include <glm.hpp>
#include <vector>
class Entity
{
	SDL_Texture *texture;
	SDL_Renderer *ren;
	SDL_Rect positionRect;
	glm::vec2 position;
	std::queue<glm::vec2> movementQueue;
	Uint32 prevTime = 0;
public:
	Entity(const EntityLoader& loader);
	virtual ~Entity();
	virtual void draw();
	void addMovementVector(const glm::vec2& movementVec2, float deltaTime);
};

