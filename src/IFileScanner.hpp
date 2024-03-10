#pragma once

// Interface for Scanner
class IFileScanner {
public:
    virtual void scan(const fs::path& filePath) const = 0;
    virtual ~IFileScanner() = default;
};