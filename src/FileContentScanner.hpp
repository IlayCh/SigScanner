#pragma once

class FileContentScanner final : public IFileScanner {
public:
    FileContentScanner(const std::string& signatureToScan);
    ~FileContentScanner() override = default;

    FileContentScanner(const FileContentScanner& other) = delete;
    FileContentScanner& operator=(const FileContentScanner& other) = delete;
    FileContentScanner(FileContentScanner&& other) noexcept = default;
    FileContentScanner& operator=(FileContentScanner&& other) noexcept = default;

    void scan(const fs::path& filePath) const override;

private:
    const std::string m_stringToScan;
};