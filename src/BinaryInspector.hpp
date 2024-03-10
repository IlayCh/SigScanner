#pragma once
#include "IFileScanner.hpp"

class BinaryInspector {
public:
    BinaryInspector() = default;
    ~BinaryInspector() = default;

    BinaryInspector(const BinaryInspector &) = delete;
    BinaryInspector &operator=(const BinaryInspector &) = delete;
    BinaryInspector(BinaryInspector &&) = default;
    BinaryInspector &operator=(BinaryInspector &&) = default;

    void addScanner(std::unique_ptr<IFileScanner> scanner);
    void scanDirForELF(const fs::path& directory);

private:
    std::vector<std::unique_ptr<IFileScanner>> m_scanners = {};

    void notifyScanners(const fs::path& filePath);
};