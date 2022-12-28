#include <iostream>
#include "Logger.h"
#include "Time.h"

int main()
{
	/*int a = 9;
	a++;
	for (size_t i = 0; i < 10; i++)
	{
		Log("1", INFO);
	}
	Log("hello world", INFO);*/

	Logger logger(Logger::file_and_terminal, Logger::debug, "result.log");
	logger.DEBUG("What happend?");
	logger.INFO("This is good.");
	logger.WARNING("Yes...");
	logger.ERROR("IO Error!");



	//std::cout << GetCurrentTime() << std::endl;
	std::cin.get();
	return 0;
}