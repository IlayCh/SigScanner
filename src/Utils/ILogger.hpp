#pragma once
#include <string>

class ILogger
{
public:
	virtual void Log(const std::string& message) = 0;
	virtual ~ILogger() = default;
};

