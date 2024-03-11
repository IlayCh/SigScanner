#include "pch.hpp"
#include "IFileScanner.hpp"
#include "FileContentScanner.hpp"
#include "Utils/ConsoleLogger.hpp"
#include "Utils/LinuxErrorCodeException.hpp"

FileContentScanner::FileContentScanner(const std::string& signatureToScan) : m_stringToScan(signatureToScan) {} 

void FileContentScanner::scan(const fs::path &filePath) const
{
    std::ifstream fileStream(filePath, std::ios::binary);
    if (!fileStream.is_open()) {
        throw LinuxErrorCodeException("Error opening file: " + filePath.string());
    }

    std::string lineToRead;
    while (std::getline(fileStream, lineToRead)) {
        if (lineToRead.find(m_stringToScan) != std::string::npos) {
            std::stringstream log;
            log << "File " << filePath << " is infected!";
            ConsoleLogger::getInstance().Log(log.str());
            return;
        }
    }
}