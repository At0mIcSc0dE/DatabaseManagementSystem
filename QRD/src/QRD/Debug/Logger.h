#pragma once

#include "pch.h"
#include "Core.h"


namespace Calculator
{

	class QRD_API Logger
	{
	public:
		static void Init(const std::string& filepath);

		static void Log(const std::string& message, const std::string& filepath);
	};

}


#if QRD_LOG_ACTIVE
	#define CL_LOG(text) Calculator::Logger::Log(text, "D:\\dev\\Cpp\\Projects\\DatabaseManagementSystem\\log.txt")
	#define CL_CLEAR() Calculator::Logger::Init("D:\\dev\\Cpp\\Projects\\DatabaseManagementSystem\\log.txt")
#else
	#define CL_LOG(text)
	#define CL_CLEAR()
#endif