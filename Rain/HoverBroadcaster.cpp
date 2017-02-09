#include "HoverBroadcaster.h"
#include "HoverObserver.h"


HoverBroadcaster::HoverBroadcaster()
{
	mouseState = SDL_GetMouseState(&mouseX, &mouseY);
}


HoverBroadcaster::~HoverBroadcaster()
{
}

void HoverBroadcaster::update()
{
	mouseState = SDL_GetMouseState(&mouseX, &mouseY);
	for (int i = 0; i < observers.size(); i++) {
		dynamic_cast<HoverObserver*>(observers.at(i))->hover(mouseX, mouseY);
	}
}
