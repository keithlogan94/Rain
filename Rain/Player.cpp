#include "Player.h"
#include "EntityLoader.h"


Player::Player(EntityLoader loader)
	:Entity{ loader }
{
	std::vector<std::string> attack1ImPaths
	{ constructPaths(
	"_assets/archers/archer1/FantasyArcher_01_Attack1_0",
		210,
		224) };
	for (auto path : attack1ImPaths) {
		animations.attack1.push_back(loadTexture(path.c_str()));
	}

	std::vector<std::string> attack2ImPaths
	{ constructPaths(
		"_assets/archers/archer1/FantasyArcher_01_Attack2_0",
		228,
		242) };
	for (auto path : attack2ImPaths) {
		animations.attack2.push_back(loadTexture(path.c_str()));
	}

	std::vector<std::string> noHealthImPaths
	{ constructPaths(
		"_assets/archers/archer1/FantasyArcher_01_Death_0",
		253,
		267) };
	for (auto path : noHealthImPaths) {
		animations.noHealth.push_back(loadTexture(path.c_str()));
	}

	std::vector<std::string> hitImPaths
	{ constructPaths(
		"_assets/archers/archer1/FantasyArcher_01_Hit_0",
		245,
		249) };
	for (auto path : hitImPaths) {
		animations.hit.push_back(loadTexture(path.c_str()));
	}

	std::vector<std::string> idle1ImPaths
	{ constructPaths(
		"_assets/archers/archer1/FantasyArcher_01_idle_0",
		125,
		139) };
	for (auto path : idle1ImPaths) {
		animations.idle1.push_back(loadTexture(path.c_str()));
	}

	std::vector<std::string> idle2ImPaths
	{ constructPaths(
		"_assets/archers/archer1/FantasyArcher_01_Idle2_0",
		143,
		172) };
	for (auto path : idle2ImPaths) {
		animations.idle2.push_back(loadTexture(path.c_str()));
	}

	std::vector<std::string> jumpImPaths
	{ constructPaths(
		"_assets/archers/archer1/FantasyArcher_01_Jump_0",
		270,
		282) };
	for (auto path : jumpImPaths) {
		animations.jump.push_back(loadTexture(path.c_str()));
	}

	std::vector<std::string> walkImPaths
	{ constructPaths(
		"_assets/archers/archer1/FantasyArcher_01_walk_",
		0,
		14) };
	for (auto path : walkImPaths) {
		animations.walk.push_back(loadTexture(path.c_str()));
	}
	animations.currentAnimation = &animations.idle1;
}


Player::~Player()
{
	std::for_each(animations.attack1.begin(), animations.attack1.end(),[](SDL_Texture *t) {SDL_DestroyTexture(t); });
	std::for_each(animations.attack2.begin(), animations.attack2.end(), [](SDL_Texture *t) {SDL_DestroyTexture(t); });
	std::for_each(animations.hit.begin(), animations.hit.end(), [](SDL_Texture *t) {SDL_DestroyTexture(t); });
	std::for_each(animations.idle1.begin(), animations.idle1.end(), [](SDL_Texture *t) {SDL_DestroyTexture(t); });
	std::for_each(animations.idle2.begin(), animations.idle2.end(), [](SDL_Texture *t) {SDL_DestroyTexture(t); });
	std::for_each(animations.jump.begin(), animations.jump.end(), [](SDL_Texture *t) {SDL_DestroyTexture(t); });
	std::for_each(animations.noHealth.begin(), animations.noHealth.end(), [](SDL_Texture *t) {SDL_DestroyTexture(t); });
	std::for_each(animations.walk.begin(), animations.walk.end(), [](SDL_Texture *t) {SDL_DestroyTexture(t); });
}

void Player::objectLeftClicked()
{
}

void Player::objectRightClicked()
{
}

void Player::objectHovered()
{
}

void Player::draw()
{
	SDL_Rect posRect{ position.x, position.y, size.w, size.h };
	SDL_RenderCopy(ren, animations.currentAnimation->at(currentFrameIndex), NULL, &posRect);
}

void Player::update()
{
	SDL_PollEvent(&event);
	keyBoardState = SDL_GetKeyboardState(0);
	mouseState = SDL_GetMouseState(&mouseX, &mouseY);
	setAnimation();
	Uint32 currentTime = SDL_GetTicks();
	if (currentTime - prevTime >= msPerFrame) {
		currentFrameIndex++;
		prevTime = currentTime;
	}
}

void Player::setAnimation()
{
	if (keyBoardState[SDL_SCANCODE_J] && 
		animations.currentAnimation != &animations.jump) {
		currentFrameIndex = 0;
		animations.currentAnimation = &animations.jump;
	}
	if (keyBoardState[SDL_SCANCODE_A] &&
		//animations.currentAnimation != )
	if (currentFrameIndex == animations.currentAnimation->size()) {
		currentFrameIndex = 0;
		animations.currentAnimation = &animations.idle1;
	}
}

SDL_Texture * Player::loadTexture(const char * imagePath)
{
	SDL_Surface *surface{ IMG_Load(imagePath) };
	if (!surface)return nullptr;
	SDL_Texture *texture{ SDL_CreateTextureFromSurface(ren, surface) };
	SDL_FreeSurface(surface);
	return texture;
}

std::vector<std::string> Player::constructPaths(const char * pathBegin, int lower, int upper, const char * ext)
{
	std::vector<std::string> imPaths;
	/* lower and upper end of path number*/
	for (int i = lower; i <= upper; i++) {
		std::string imPath{ pathBegin };
		imPath += std::to_string(i);
		imPath += ext;
		imPaths.push_back(imPath);
	}
	return imPaths;
}
