#include <SDL.h>
#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char ** argv) 
{
	try
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::string errLog;
			errLog.append(SDL_GetError());
			errLog.append(" : error with initializing: SDL_Init() : in Main.cpp");
			throw std::logic_error{errLog.c_str()};
		}
		//continue...



	}
	catch (const std::logic_error& e)
	{
		std::cerr << e.what() << "\n";
		system("pause");
		return 1;
	}
	SDL_Quit();
	return 0;
}

