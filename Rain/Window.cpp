#include "Window.h"



Window::Window()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::string errLog;
		errLog.append(SDL_GetError());
		errLog.append(" : error with initializing: SDL_Init() : in Main.cpp");
		throw std::runtime_error{ errLog.c_str() };
	}
	SDL_CreateWindowAndRenderer(1080, 680, SDL_WINDOW_FULLSCREEN, &win, &ren);
	SDL_SetWindowTitle(win, "ArcherZomb 3");
	if (!win || !ren) {
		if (win)SDL_DestroyWindow(win);
		else if (ren)SDL_DestroyRenderer(ren);
		SDL_Quit();
		throw std::runtime_error{ "error window or renderer was not created successfully : "
			"SDL_CreateWindowAndRenderer(...) : Window.cpp" };
	}
	SDL_ShowCursor(0);
	mouseX = 0;
	mouseY = 0;

	SDL_GetWindowSize(win, &width, &height);

	loader.drawPriority = 1;
	loader.entityName = "Player1";
	loader.width = 200;
	loader.height = 200;
	loader.ren = ren;
	loader.startingPositon.x = 200;
	loader.startingPositon.y = height - loader.height;

	p = new Player{ loader };
	background = loadTexture("_assets/jungle/jungle-sky.png");
}


Window::~Window()
{
	delete p;
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}


// window main loop
void Window::loop()
{
	do {
		updateWindowState();
		draw();
	} while (!windowShouldClose());
}


void Window::updateWindowState()
{
	mouseState = SDL_GetMouseState(&mouseX, &mouseY);
	keyboardState = SDL_GetKeyboardState(0);
	SDL_PollEvent(&event);
}


// draw here...
void Window::draw()
{
	if (!win || !ren)throw std::runtime_error{"error window or renderer is "
		"nullptr somthing went wrong in : draw() : Window.cpp"};
	//SDL_UpdateWindowSurface(win);
	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, background, NULL, NULL);
	p->draw();
	p->update();
	SDL_RenderPresent(ren);
}

SDL_Texture * Window::loadTexture(const char * imagePath)
{
	/* to load textures from image path */
	SDL_Surface *surface{ IMG_Load(imagePath) };
	if (!surface)return nullptr;
	SDL_Texture *texture{ SDL_CreateTextureFromSurface(ren, surface) };
	SDL_FreeSurface(surface);
	return texture;
}


bool Window::windowShouldClose()
{
	if (keyboardState == nullptr) throw std::runtime_error{ "error keyboardState is nullptr : "
		"windowShouldClose() : Window.cpp" };
	return keyboardState[SDL_SCANCODE_ESCAPE] || event.type == SDL_QUIT;
}
