#pragma once

#include "pch.h"
#include "Core.h"

namespace DBMS
{
	class DBMS_API DBManager
	{
	public:
		/**
		* Constructor for DBManager class
		*
		* @param filePath is the path to the .dbs file
		* @returns a new DBManager object
		*/
		DBManager(
			_In_ const std::string& filePath
		);

		/**
		* Evaluates sql command
		* 
		* @param command is the sql command
		* @param args will replace any {0}, {1}... in string
		* @returns true if the command executed successfully else false
		*/
		template<typename... Args>
		bool Eval(
			_In_ std::string&& command, 
			_In_ Args&& ...args
		);

	private:
		template<typename T>
		void InsertArgsIntoString(std::string& command, int& runNr, const T& arg);

	private:
		const std::string& m_FilePath;
	};


	template<typename ...Args>
	inline bool DBManager::Eval(std::string&& command, Args&& ...args)
	{
		int amountOfArgs = 0;

		// C++17 fold expression (function executed for every argument in args)
		(InsertArgsIntoString(command, amountOfArgs, args), ...);
		
		printf(command.c_str());

		return false;
	}

	template<typename T>
	inline void DBManager::InsertArgsIntoString(std::string& command, int& runNr, const T& arg)
	{
		std::stringstream ss;
		ss << '{' << runNr << '}';
		size_t pos = command.find(ss.str());
	
		if(pos != std::string::npos)
			command.replace(pos, 3, arg);

		++runNr;
	}

}

