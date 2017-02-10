#pragma once
#include "Entity.h"
#include "EntityLoader.h"
#include "SaveInterface.h"

class Scene : public Entity {
public:
	Scene(EntityLoader loader);
	~Scene();

};