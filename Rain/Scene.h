#pragma once
#include "Entity.h"
class Scene :
	public Entity
{
public:
	Scene(const EntityLoader& loader);
	~Scene();
};

