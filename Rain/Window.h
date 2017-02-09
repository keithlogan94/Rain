#pragma once
#include <SDL.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include "ClickedBroadcaster.h"
#include "EventBroadcaster.h"
#include "HoverBroadcaster.h"
#include "ClickedObserver.h"
#include "EventObserver.h"
#include "HoverObserver.h"
#include "EntityLoader.h"
class Window : public ClickObserver, public HoverObserver, public EventObserver
{
	SDL_Window *win{ nullptr };
	SDL_Renderer *ren{ nullptr };
	bool windowShouldClose();
	SDL_Surface *windowSurface;
	bool windowClose = false;
	ClickBroadcaster *clicks;
	EventBroadcaster *events;
	HoverBroadcaster *hovering;
public:
	Window(Entity);
	~Window();
	void loop();

	void leftClick(const int x, const int y);
	void rightClick(const int x, const int y);
	void hover(const int mouseX, const int mouseY);
	void sendEvent(int sentEvent);

private:
	void updateWindowState();
	void draw();
};

