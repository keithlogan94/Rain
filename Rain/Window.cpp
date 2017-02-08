#include "Window.h"



Window::Window()
{
	/* initialize sdl2 */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		//error not initialized
		std::string errLog;
		errLog.append(SDL_GetError());
		errLog.append(" : error with initializing: SDL_Init() : in Main.cpp");
		throw std::runtime_error{ errLog.c_str() };
	}
	/* initialize sdl2_image for png and jpg */
	constexpr int initFlags{ IMG_INIT_JPG | IMG_INIT_PNG };
	int inittedImageFlags = IMG_Init(initFlags);
	if ((initFlags & inittedImageFlags) != initFlags) {
		//error not initialized
		SDL_Quit();
		throw std::runtime_error{ "error sdl2_image did not initialize : "
			"IMG_Init() : Window.cpp" };
	}
	/* set up window and renderer */
	SDL_CreateWindowAndRenderer(1080, 680, SDL_WINDOW_RESIZABLE, &win, &ren);
	SDL_SetWindowTitle(win, "2D Game");
	if (!win || !ren) {
		//error window or renderer was not created
		if (win)SDL_DestroyWindow(win);
		else if (ren)SDL_DestroyRenderer(ren);
		IMG_Quit();
		SDL_Quit();
		throw std::runtime_error{ "error window or renderer was not created successfully : "
			"SDL_CreateWindowAndRenderer(...) : Window.cpp" };
	}
	windowSurface = SDL_GetWindowSurface(win);
	mouseX = 0;
	mouseY = 0;

	//object
	EntityLoader loader;
	loader.width = 100;
	loader.height = 100;
	loader.ren = ren;
	loader.startingLocX = 200;
	loader.startingLocY = 200;
	loader.imagePath = "_images/test.jpg";
	entity = new Entity(loader);
}


Window::~Window()
{
	/* clean up */
	delete entity;
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	IMG_Quit();
	SDL_Quit();
}


// window main loop
void Window::loop()
{
	/* we have to run a do while because 
		the while test needs access to variables that
		will be set in the while statement */
	do {
		updateWindowState();
		handleInput();
		draw();
	} while (!windowShouldClose());
}


void Window::updateWindowState()
{
	mouseState = SDL_GetMouseState(&mouseX, &mouseY);
	keyboardState = SDL_GetKeyboardState(0);
	SDL_PollEvent(&event);
	float currentTime = SDL_GetTicks();
	if (time.prevTime == 0)currentTime = 1;
	time.deltaTime = currentTime - time.prevTime;
	time.prevTime = currentTime;
	SDL_GetWindowSize(win, &width, &height);
}


// draw here...
void Window::draw()
{
	if (!win || !ren)throw std::runtime_error{"error window or renderer is "
		"nullptr somthing went wrong in : draw() : Window.cpp"};
	
	//draw objects
	SDL_RenderClear(ren);
	entity->draw();
	SDL_RenderPresent(ren);

}


bool Window::windowShouldClose()
{
	if (keyboardState == nullptr) throw std::runtime_error{ "error keyboardState is nullptr : "
		"windowShouldClose() : Window.cpp" };
	return keyboardState[SDL_SCANCODE_ESCAPE] || event.type == SDL_QUIT;
}


void Window::handleInput()
{
	if (keyboardState[SDL_SCANCODE_A]) {
		//move main character left
		entity->addMovementVector(glm::vec2(-1, 0), time.deltaTime);
	}
	if (keyboardState[SDL_SCANCODE_S]) {
		//move down...
		entity->addMovementVector(glm::vec2(0, 1), time.deltaTime);
	}
	if (keyboardState[SDL_SCANCODE_D]) {
		//move right...
		entity->addMovementVector(glm::vec2(1, 0), time.deltaTime);
	}
	if (keyboardState[SDL_SCANCODE_W]) {
		//move up
		entity->addMovementVector(glm::vec2(0, -1), time.deltaTime);
	}
	if (keyboardState[SDL_SCANCODE_J]) {
		//jump
		entity->addMovementVector(glm::vec2(0, -10), time.deltaTime);
	}
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		entity->addMovementVector(glm::vec2(mouseX - (width/2), mouseY - (height / 2)), .01);
	}
}
