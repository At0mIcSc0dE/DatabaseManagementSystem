#include "pch.h"
#include "Logger.h"

#include <fstream>
#include <ctime>


namespace Calculator
{
	void Logger::Init(const std::string& filepath)
	{
		std::ofstream ofs;
		ofs.open(filepath, std::ofstream::out | std::ofstream::trunc);
		ofs.close();
	}

	void Logger::Log(const std::string& message, const std::string& filepath)
	{
		std::ofstream stream(filepath, std::ios_base::app);
		std::time_t t = std::time(0);
		std::tm* now = std::localtime(&t);		

		stream << '[' << now->tm_hour << ':' << now->tm_min << ':' << round(now->tm_sec) << "]: " << message << '\n';
		
		stream.close();

	}

}

