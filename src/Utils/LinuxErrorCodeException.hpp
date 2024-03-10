#pragma once
#include <stdexcept>
#include <cstring>
#include <system_error>
#include <vector>

class LinuxErrorCodeException : public std::exception
{
public:
    explicit LinuxErrorCodeException(const std::string &message);
    virtual ~LinuxErrorCodeException() = default;

    const char *what() const noexcept override;

    LinuxErrorCodeException(const LinuxErrorCodeException &) = delete;
    LinuxErrorCodeException &operator=(const LinuxErrorCodeException &) = delete;
    LinuxErrorCodeException(LinuxErrorCodeException &&) = default;
    LinuxErrorCodeException &operator=(LinuxErrorCodeException &&) = default;

    /* Get Linux last error code. */
    int getErrorCode() const;

    /* Get Linux message corresponding to the last error that occurred. */
    std::string getErrorMessage() const;

protected:
    std::string getLastErrorMessage() const;

    int m_errorCode;
    std::string m_linuxErrorMessage;
    std::string m_errorMessage;
};