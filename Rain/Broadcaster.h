#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <SDL.h>

class Observer;

class Broadcaster
{
protected:
	std::vector<Observer*> observers;
public:
	Broadcaster();
	virtual ~Broadcaster();

	void addObserver(Observer* o);
	void stopObserving(int pos);
	virtual void update() {}
};

