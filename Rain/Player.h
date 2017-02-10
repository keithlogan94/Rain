#pragma once
#include <vector>
#include <algorithm>
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"


class Player :
	public Entity
{
	bool left = false;
	int hits = 0;
	bool frameStop = false;
	SDL_Event event;
	const Uint8* keyBoardState{ nullptr };
	Uint32 mouseState = 0;
	int mouseX = 0, mouseY = 0;
	int msPerFrame{ 45 };
	int currentFrameIndex{ 0 };
	Uint32 prevTime = 0;
	struct Animations {
		std::vector<SDL_Texture*>* currentAnimation;
		std::vector<SDL_Texture*> attack1;
		std::vector<SDL_Texture*> attack2;
		std::vector<SDL_Texture*> noHealth;
		std::vector<SDL_Texture*> hit;
		std::vector<SDL_Texture*> idle1;
		std::vector<SDL_Texture*> idle2;
		std::vector<SDL_Texture*> jump;
		std::vector<SDL_Texture*> walk;
	} animations;
public:
	Player(EntityLoader loader);
	~Player();

	//inherited virtual pure
	void objectLeftClicked();
	void objectRightClicked();
	void objectHovered();
	void draw();
	void update();

private:
	void setAnimation();
	SDL_Texture* loadTexture(const char* imagePath);
	std::vector<std::string> constructPaths(const char *pathBegin, int lower, int upper, const char *ext = ".png");
};

