#include "LogManager.hpp"
#include <iostream>

void LogInfo(const char* message)
{
	std::cout << "[INFO]: " << message << std::endl;
}

void LogWarning(const char* message)
{
	std::cout << "[WARNING]: " << message << std::endl;
}
