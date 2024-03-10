#include "FileUtils.hpp"
#include "LinuxErrorCodeException.hpp"
#include <algorithm>

namespace fs = std::filesystem;

const std::string FileUtils::getRawDataOfFile(const fs::path& filePath){
    std::ifstream fileStream(filePath, std::ios::binary);

    if (!fileStream.is_open()) {
        throw LinuxErrorCodeException("Error opening file" + filePath.string());
        return "";
    }

    std::string rawDataStr((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
    // Remove newline characters from the string
    rawDataStr.erase(std::find_if_not(rawDataStr.rbegin(), rawDataStr.rend(),
                    [](char c) { return c == '\n'; }).base(), rawDataStr.end());

    return rawDataStr;
}