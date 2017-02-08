#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>

int main(int argc, char ** argv) 
{
	try
	{
	//continue...


	}
	catch (const std::logic_error& e)
	{
		std::cerr << e.what() << "\n";
		system("pause");
		return 1;
	}
	return 0;
}

