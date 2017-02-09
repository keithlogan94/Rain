#pragma once
#include <memory>

class EventBroadcaster;
class ClickBroadcaster;
class HoverBroadcaster;

struct EntityLoader {
	HoverBroadcaster *hoverBroadcaster;
	EventBroadcaster *eventBroadcaster;
	ClickBroadcaster *clickedBroadcaster;
};