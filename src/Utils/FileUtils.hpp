#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

class FileUtils final
{
public:
	static const std::string getRawDataOfFile(const fs::path& filePath);
};