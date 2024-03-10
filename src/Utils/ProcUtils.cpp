#include "ProcUtils.hpp"
#include "LinuxErrorCodeException.hpp"

bool ProcUtils::isElfBinary(const fs::path& filePath) {
    std::ifstream file(filePath, std::ios::binary);

    if (!file.is_open()) {
        throw LinuxErrorCodeException("Error opening file" + filePath.string());
        return false;
    }

    // Read the first few bytes (at least enough to cover the ELF header)
    std::vector<char> buffer(4);
    file.read(buffer.data(), buffer.size());

    // Check for ELF magic number "\x7FELF"
    return buffer[0] == 0x7F && buffer[1] == 'E' && buffer[2] == 'L' && buffer[3] == 'F';
}