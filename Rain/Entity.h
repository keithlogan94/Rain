#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <glm.hpp>
#include <memory>
#include <exception>
#include <stdexcept>

class EntityLoader;

class Entity
{
	glm::vec2 position;
	struct Size { int w = 0, h = 0; } size;
	short drawPriority = 1;
	SDL_Renderer *ren = nullptr;
public:
	Entity(EntityLoader entity);
	Entity(const EntityLoader& entity) = delete;
	Entity(const EntityLoader&& entity) = delete;
	Entity& operator=(const Entity& entity) = delete;
	Entity& operator=(Entity&& entity) = delete;
	virtual ~Entity();
	void click(const int x, const int y, Uint32 mouseState);
	void hover(const int x, const int y);
	//virtual pure
	virtual void objectLeftClicked() = 0;
	virtual void objectRightClicked() = 0;
	virtual void objectHovered() = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
};

