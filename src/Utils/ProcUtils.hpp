#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

class ProcUtils final
{
public:
	static bool isElfBinary(const fs::path& filePath);
};