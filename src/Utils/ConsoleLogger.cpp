#include "ConsoleLogger.hpp"
#include <iostream>

void ConsoleLogger::Log(const std::string &message) {
    std::lock_guard<std::mutex> lock(m_mutex);
	std::cout << "[Console] " << message << std::endl;
}