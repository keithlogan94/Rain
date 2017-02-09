#pragma once
#include <SDL.h>
#include <glm.hpp>
#include <iostream>
#include <string>


struct EntityLoader {
	std::string entityName;
	SDL_Renderer * ren = nullptr;
	int width = 0, height = 0;
	int drawPriority = 1;
	glm::vec2 startingPositon;
};