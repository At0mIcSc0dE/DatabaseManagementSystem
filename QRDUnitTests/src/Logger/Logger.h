#pragma once

#include <CppUnitTest.h>


class Logger
{
public:
	template<typename... Args>
	static void Log(std::string msg, const Args&... args);

private:
	template<typename T>
	static void FillOutputStr(std::string& msg, const T& arg);

	static unsigned int run;
};

unsigned int Logger::run = 0;

template<typename ...Args>
inline void Logger::Log(std::string msg, const Args& ...args)
{
	(FillOutputStr(msg, args), ...);
	Microsoft::VisualStudio::CppUnitTestFramework::Logger::WriteMessage((msg + '\n').c_str());
}

template<typename T>
inline void Logger::FillOutputStr(std::string& msg, const T& arg)
{
	auto idxOfNum = msg.find(std::to_string(run));

	//if (idxOfNum == std::string::npos)
	//	throw std::invalid_argument("Too many/few arguments to fill string");

	std::stringstream ss;
	ss << arg;
	msg.replace(idxOfNum - 1, idxOfNum + 1, ss.str());

}


#define QRDT_LOG(x, ...) Logger::Log(x, __VA_ARGS__)
