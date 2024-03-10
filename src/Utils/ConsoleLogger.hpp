#pragma once
#include "ILogger.hpp"
#include <mutex>

class ConsoleLogger : public ILogger
{
public:
    // Function to access the singleton instance
    static ConsoleLogger& getInstance() {
        static ConsoleLogger instance; // This instance is created only once
        return instance;
    }

	ConsoleLogger(const ConsoleLogger&) = delete;
	ConsoleLogger& operator=(const ConsoleLogger&) = delete;
	ConsoleLogger(ConsoleLogger&&) = delete;
	ConsoleLogger& operator=(ConsoleLogger&&) = delete;

	void Log(const std::string& message) override;

private:

	ConsoleLogger() = default;
	~ConsoleLogger() = default;

	std::mutex m_mutex;
};