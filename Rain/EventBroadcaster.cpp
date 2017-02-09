#include "EventBroadcaster.h"
#include "EventObserver.h"
#include "Observer.h"


void EventBroadcaster::update()
{
	SDL_PollEvent(&event);
	for (int i = 0; i < observers.size(); i++) {
		dynamic_cast<EventObserver*>(observers.at(i))->sendEvent(event.type);
	}
}

EventBroadcaster::EventBroadcaster()
{
	SDL_PollEvent(&event);
}


EventBroadcaster::~EventBroadcaster()
{
}
