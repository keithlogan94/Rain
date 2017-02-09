#pragma once
#include "Broadcaster.h"
class HoverBroadcaster :
	public Broadcaster
{
	Uint32 mouseState = 0;
	int mouseX = 0, mouseY = 0 ;
public:
	HoverBroadcaster();
	~HoverBroadcaster();

	void update();
};

