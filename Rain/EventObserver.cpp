#include "EventObserver.h"



EventObserver::EventObserver(Broadcaster *broadcaster)
	:Observer{ broadcaster }
{
}


EventObserver::~EventObserver()
{
}


