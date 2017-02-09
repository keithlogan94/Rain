#include "Broadcaster.h"
#include "Observer.h"


Broadcaster::Broadcaster()
{
}


Broadcaster::~Broadcaster()
{
}

void Broadcaster::addObserver(Observer *o)
{
	observers.push_back(o);
	o->setPosition(observers.size() - 1);
}


void Broadcaster::stopObserving(int pos)
{
	observers.erase(observers.begin() + pos);
}
