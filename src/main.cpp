#include "pch.hpp"
#include "BinaryInspector.hpp"
#include "FileContentScanner.hpp"
#include "Utils/FileUtils.hpp"
#include "Utils/LinuxErrorCodeException.hpp"

int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            std::cerr << "Usage: " << argv[0] << " <path_to_directory> <signature_file>" << std::endl;
            return 1;
        }

        BinaryInspector binaryInspector;
        std::unique_ptr<IFileScanner> virusSignatureScanner = std::make_unique<FileContentScanner>(FileUtils::getRawDataOfFile(argv[2]));

        // Attach the scanner to the binary inspector
        binaryInspector.addScanner(std::move(virusSignatureScanner));

        // Scan the specified directory for ELF
        binaryInspector.scanDirForELF(argv[1]);

    } catch (const LinuxErrorCodeException& exception) {
        std::cerr << "Error: " << exception.what() << "\nLinux error code: " << exception.getErrorCode()
                  << "\nLinux error message: " << exception.getErrorMessage() << std::endl;
        return 1;  
    } catch (const std::exception& exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;  
    }

}