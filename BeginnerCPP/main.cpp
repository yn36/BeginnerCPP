#include <iostream>
#include "Logger.h"
#include "Time.h"

int main()
{
	Logger logger(Logger::file_and_terminal, Logger::debug);

	logger.DEBUG("What happend?");
	logger.INFO("This is good.");
	logger.WARNING("Yes...");
	logger.ERROR("IO Error!");

	std::cin.get();
	return 0;
}
