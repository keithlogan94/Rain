#include "ClickedBroadcaster.h" 
#include "ClickedObserver.h"


ClickBroadcaster::ClickBroadcaster()
{
	mouseState = SDL_GetMouseState(&mouseX, &mouseY);
}


ClickBroadcaster::~ClickBroadcaster()
{
}


void ClickBroadcaster::update()
{
	mouseState = SDL_GetMouseState(&mouseX, &mouseY);
	if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		//send left mouse click to observers
		//observer.leftClick();
		for (int i = 0; i < observers.size(); i++) {
			dynamic_cast<ClickObserver*>(observers.at(i))->leftClick(mouseX, mouseY);
		}
	}
	if (mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
		//send right mouse click to observers
		for (int i = 0; i < observers.size(); i++) {
			dynamic_cast<ClickObserver*>(observers.at(i))->rightClick(mouseX, mouseY);
		}
	}
}
