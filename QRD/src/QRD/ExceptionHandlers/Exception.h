#pragma once

#include <exception>


namespace QRD
{
	class Exception : public std::exception
	{
	public:
		/**
		* Overridden what function from std::exception
		* 
		* @returns More information about the exception
		*/
		virtual const char* what() const noexcept override;

	protected:
		/**
		* Exception constructor
		* 
		* @param file is the path to the file where the error occured
		* @prarm line is the line where the error was thrown
		* @param name is the name of the error (FileNotFoundException, ...)
		* @param message is a message for more information about the error
		* 
		* @see QRD::Exception::what() to get a string of information about the error
		*/
		Exception(const char* file, const unsigned int line, const char* name, const char* message) noexcept;

	private:
		const char* m_File;
		const char* m_Message;
		const char* m_Name;
		const unsigned int m_Line;
	};

	class FileNotFoundException : public Exception
	{
	public:
		/**
		* FileNotFoundException constructor
		*/
		FileNotFoundException(const char* file, const unsigned int line, const std::string& name, const std::string& message) noexcept;
	};

	class ObjectNotFoundException : public Exception
	{
	public:
		/**
		* ObjectNotFoundException constructor
		*/
		ObjectNotFoundException(const char* file, const unsigned int line, const std::string& name, const std::string& message) noexcept;
	};

	class FileReadException : public Exception
	{
	public:
		/**
		* ObjectNotFoundException constructor
		*/
		FileReadException(const char* file, const unsigned int line, const std::string& name, const std::string& message) noexcept;
	};

	class InvalidCommandException : public Exception
	{
	public:
		/**
		* InvalidCommandException constructor
		*/
		InvalidCommandException(const char* file, const unsigned int line, const std::string& name, const std::string& message) noexcept;
	};

	class OutOfRangeException : public Exception
	{
	public:
		/**
		* InvalidCommandException constructor
		*/
		OutOfRangeException(const char* file, const unsigned int line, const std::string& name, const std::string& message) noexcept;
	};

}


#define QRD_THROW(name, message)	throw QRD::##name(__FILE__, __LINE__, #name, message)
