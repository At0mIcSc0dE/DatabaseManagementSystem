#include "pch.h"
#include "Exception.h"



namespace QRD
{
    Exception::Exception(const char* file, const unsigned int line, const char* name, const char* message) noexcept
        : m_File(file), m_Line(line), m_Message(message), m_Name(name)
    {
    }

    const char* Exception::what() const noexcept
    {
        std::stringstream ss;
        ss << "[Exception] " << m_Name
            << "\n[File] " << m_File
            << "\n[Line] " << m_Line
            << "\n[Message] " << m_Message;

        return ss.str().c_str();
    }


    FileNotFoundException::FileNotFoundException(const char* file, const unsigned int line, const std::string& name, const std::string& message) noexcept
        : Exception(file, line, name.c_str(), message.c_str())
    {
    }

    ObjectNotFoundException::ObjectNotFoundException(const char* file, const unsigned int line, const std::string& name, const std::string& message) noexcept
        : Exception(file, line, name.c_str(), message.c_str())
    {
    }

    FileReadException::FileReadException(const char* file, const unsigned int line, const std::string& name, const std::string& message) noexcept
        : Exception(file, line, name.c_str(), message.c_str())
    {
    }

    InvalidCommandException::InvalidCommandException(const char* file, const unsigned int line, const std::string& name, const std::string& message) noexcept
        : Exception(file, line, name.c_str(), message.c_str())
    {
    }

    OutOfRangeException::OutOfRangeException(const char* file, const unsigned int line, const std::string& name, const std::string& message) noexcept
        : Exception(file, line, name.c_str(), message.c_str())
    {
    }
}


