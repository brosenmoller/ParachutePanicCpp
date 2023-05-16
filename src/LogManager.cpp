#include "LogManager.hpp"
#include <iostream>

const char* LOG_INFO = "[INFO]: ";
const char* LOG_WARNING = "[WARNING]: ";

void LogInfo(const char* message)
{
	std::cout << LOG_INFO << message << std::endl;
}

void LogWarning(const char* message)
{
	std::cout << LOG_WARNING << message << std::endl;
}
