#include "Player.h"
#include "EntityLoader.h"


Player::Player(EntityLoader loader)
	:Entity{ loader }
{
	/* in the following we create lists of paths to each image asset
	and we load up vectors of textures from each image according to there 
	animation in sequential order */
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
	/* default is idle */
	animations.currentAnimation = &animations.idle1;
}


Player::~Player()
{
	/* destroy our textures and release memory */
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
	/* render all animations facing right */
	if (!left)
		SDL_RenderCopy(ren, animations.currentAnimation->at(currentFrameIndex), NULL, &posRect);
	/* render all animations facing left */
	else
		SDL_RenderCopyEx(ren, animations.currentAnimation->at(currentFrameIndex), NULL, &posRect,
			NULL, NULL, SDL_FLIP_HORIZONTAL);
}

void Player::update()
{
	/* let this class manage its own events mouse and keys so 
	we don't have to pass around pointers */
	SDL_PollEvent(&event);
	keyBoardState = SDL_GetKeyboardState(0);
	mouseState = SDL_GetMouseState(&mouseX, &mouseY);
	/* decides what animation to set */
	setAnimation();
	/* change frame every miliseconds... frames still get rendered
	though in between */
	Uint32 currentTime = SDL_GetTicks();
	if (currentTime - prevTime >= msPerFrame) {
		if (!frameStop)
			currentFrameIndex++;
		prevTime = currentTime;
	}
}

void Player::setAnimation()
{
	/* if player clicks to the left of character then face character left 
	and the other way */
	if (mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT) ||
		mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		if (mouseX < position.x) {
			left = true;
		}
		else {
			left = false;
		}
	}
	/* test hit */
	if (keyBoardState[SDL_SCANCODE_H] && 
		animations.currentAnimation != &animations.hit &&
		animations.currentAnimation != &animations.noHealth) {
		currentFrameIndex = 0;
		animations.currentAnimation = &animations.hit;
		msPerFrame = 80;
		hits++;
	}
	if (hits >= 10 && animations.currentAnimation != &animations.noHealth) {
		currentFrameIndex = 0;
		animations.currentAnimation = &animations.noHealth;
	}
	/* shoot arrow on right click */
	if (mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT) &&
		animations.currentAnimation != &animations.attack1 &&
		animations.currentAnimation != &animations.attack2 &&
		animations.currentAnimation != &animations.noHealth) {
		currentFrameIndex = 0;
		animations.currentAnimation = &animations.attack2;
		msPerFrame = 40;
	}
	/* shoot arrow on left click */
	if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT) &&
		animations.currentAnimation != &animations.attack1 &&
		animations.currentAnimation != &animations.attack2 &&
		animations.currentAnimation != &animations.noHealth) {
			currentFrameIndex = 0;
			animations.currentAnimation = &animations.attack1;
	}
	/* jump on J... switch to 'space' */
	if (keyBoardState[SDL_SCANCODE_SPACE] && 
		animations.currentAnimation != &animations.jump && 
		animations.currentAnimation != &animations.noHealth) {
		currentFrameIndex = 0;
		animations.currentAnimation = &animations.jump;
		msPerFrame = 65;
	}
	if (animations.currentAnimation == &animations.jump) {
		Uint32 currentTime = SDL_GetTicks();
		if (currentTime - prevTime >= msPerFrame && left) {
			position.x -= 3;
		} else if (currentTime - prevTime >= msPerFrame && !left) {
			position.x += 3;
		}
	}
	/* walk left with 'A' */
	if (keyBoardState[SDL_SCANCODE_A] &&
		animations.currentAnimation != &animations.jump &&
		animations.currentAnimation != &animations.hit &&
		animations.currentAnimation != &animations.noHealth &&
		animations.currentAnimation != &animations.attack1 &&
		animations.currentAnimation != &animations.attack2 &&
		animations.currentAnimation != &animations.walk) {
		currentFrameIndex = 0;
		animations.currentAnimation = &animations.walk;
		left = true;
	}
	if (keyBoardState[SDL_SCANCODE_A] &&
		animations.currentAnimation != &animations.jump &&
		animations.currentAnimation != &animations.hit &&
		animations.currentAnimation != &animations.noHealth &&
		animations.currentAnimation != &animations.attack1 &&
		animations.currentAnimation != &animations.attack2) {
		Uint32 currentTime = SDL_GetTicks();
		if (currentTime - prevTime >= msPerFrame && left) {
			position.x -= 7;
		}
	}
	/* walk right with 'D' */
	if (keyBoardState[SDL_SCANCODE_D] &&
		animations.currentAnimation != &animations.jump &&
		animations.currentAnimation != &animations.hit &&
		animations.currentAnimation != &animations.noHealth &&
		animations.currentAnimation != &animations.attack1 &&
		animations.currentAnimation != &animations.attack2 &&
		animations.currentAnimation != &animations.walk) {
		currentFrameIndex = 0;
		animations.currentAnimation = &animations.walk;
		left = false;
	}
	if (animations.currentAnimation == &animations.walk &&
		!keyBoardState[SDL_SCANCODE_A] && !keyBoardState[SDL_SCANCODE_D]) {
		animations.currentAnimation = &animations.idle1;
		currentFrameIndex = 0;
	}
	if (keyBoardState[SDL_SCANCODE_D] &&
		animations.currentAnimation != &animations.jump &&
		animations.currentAnimation != &animations.hit &&
		animations.currentAnimation != &animations.noHealth &&
		animations.currentAnimation != &animations.attack1 &&
		animations.currentAnimation != &animations.attack2) {
		Uint32 currentTime = SDL_GetTicks();
		if (currentTime - prevTime >= msPerFrame && !left) {
			position.x += 7;
		}
	}
	/* there are only a certain number of frames for each animation. When
	we reach the size of the vector that holds the frames for the current
	animation we set the animation to its default and rest the frameIndex to
	0 */
	if (currentFrameIndex == animations.currentAnimation->size()-1) {
		if (animations.currentAnimation == &animations.noHealth) {
			frameStop = true;
			return;
		}
		currentFrameIndex = 0;
		animations.currentAnimation = &animations.idle1;
		msPerFrame = 45;
	}
}

SDL_Texture * Player::loadTexture(const char * imagePath)
{
	/* to load textures from image path */
	SDL_Surface *surface{ IMG_Load(imagePath) };
	if (!surface)return nullptr;
	SDL_Texture *texture{ SDL_CreateTextureFromSurface(ren, surface) };
	SDL_FreeSurface(surface);
	return texture;
}

std::vector<std::string> Player::constructPaths(const char * pathBegin, int lower, int upper, const char * ext)
{
	/* to create list of images paths to each image asset */
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
