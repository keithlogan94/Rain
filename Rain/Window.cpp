#include "Window.h"



Window::Window()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::string errLog;
		errLog.append(SDL_GetError());
		errLog.append(" : error with initializing: SDL_Init() : in Main.cpp");
		throw std::runtime_error{ errLog.c_str() };
	}
	SDL_CreateWindowAndRenderer(1080, 680, SDL_WINDOW_RESIZABLE, &win, &ren);
	SDL_SetWindowTitle(win, "2D Game");
	if (!win || !ren) {
		if (win)SDL_DestroyWindow(win);
		else if (ren)SDL_DestroyRenderer(ren);
		SDL_Quit();
		throw std::runtime_error{ "error window or renderer was not created successfully : "
			"SDL_CreateWindowAndRenderer(...) : Window.cpp" };
	}
	windowSurface = SDL_GetWindowSurface(win);
	mouseX = 0;
	mouseY = 0;
}


Window::~Window()
{
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
	SDL_UpdateWindowSurface(win);

}


bool Window::windowShouldClose()
{
	if (keyboardState == nullptr) throw std::runtime_error{ "error keyboardState is nullptr : "
		"windowShouldClose() : Window.cpp" };
	return keyboardState[SDL_SCANCODE_ESCAPE] || event.type == SDL_QUIT;
}
