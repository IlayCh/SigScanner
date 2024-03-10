#include "pch.hpp"
#include "BinaryInspector.hpp"
#include "IFileScanner.hpp"
#include "Utils/ConsoleLogger.hpp"
#include "Utils/ProcUtils.hpp"

void BinaryInspector::addScanner(std::unique_ptr<IFileScanner> scanner) {
    m_scanners.push_back(std::move(scanner));
}

void BinaryInspector::scanDirForELF(const fs::path& directory) {
    ConsoleLogger::getInstance().Log("Scanning started...");

    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (ProcUtils::isElfBinary(entry.path())) {
            notifyScanners(entry.path());
        }
    }
}

void BinaryInspector::notifyScanners(const fs::path& filePath) {
    for (const auto& scanner : m_scanners) {
        scanner->scan(filePath);
    }
}