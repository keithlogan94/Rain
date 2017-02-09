#pragma once
#include "Broadcaster.h"
#include <SDL.h>
#include <vector>
#include <stdexcept>
#include <exception>
#include <memory>
class EventBroadcaster :
	public Broadcaster
{
	SDL_Event event;
public:
	EventBroadcaster();
	~EventBroadcaster();

	void update();
};

