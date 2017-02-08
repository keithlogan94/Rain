#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include "Window.h"

int main(int argc, char ** argv) 
{
	try
	{
	//continue...
		Window win;
		win.loop();
	}
	catch (const std::logic_error& e)
	{
		std::cerr << "exception logic_error : " << e.what() << "\n";
		system("pause");
		return 1;
	}
	catch (const std::runtime_error& e) {
		std::cerr << "exception runtime_error : " << e.what() << "\n";
		system("pause");
		return 1;
	}
	catch (const std::exception& e) {
		std::cerr << "exception unknown exception : " << e.what() << "\n";
		system("pause");
		return 1;
	}
	return 0;
}

