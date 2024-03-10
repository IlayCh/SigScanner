#include "LinuxErrorCodeException.hpp"
#include <stdexcept>
#include <cstring>
#include <system_error>
#include <vector>

LinuxErrorCodeException::LinuxErrorCodeException(const std::string &errorMessage)
    : m_errorCode(errno), m_linuxErrorMessage(getLastErrorMessage()), m_errorMessage(errorMessage)
{}

const char *LinuxErrorCodeException::what() const noexcept
{
    return this->m_errorMessage.c_str();
}

int LinuxErrorCodeException::getErrorCode() const
{
    return this->m_errorCode;
}

std::string LinuxErrorCodeException::getErrorMessage() const
{
    return this->m_linuxErrorMessage;
}

std::string LinuxErrorCodeException::getLastErrorMessage() const
{
    if (m_errorCode == 0)
    {
        return "";
    }
    const int MESSAGE_SIZE = 512;
    std::vector<char> message(MESSAGE_SIZE);
    strerror_r(this->m_errorCode, message.data(), MESSAGE_SIZE);
    return std::string(message.data());
}