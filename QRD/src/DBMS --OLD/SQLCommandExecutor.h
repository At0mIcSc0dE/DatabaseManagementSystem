#pragma once

#include "pch.h"
#include "Core.h"


namespace DBMS
{

	/**
	* Class which receives SQL commands and dispatches them to their destination
	*/
	class DBMS_API SQLCommandExecutor
	{
	public:
		SQLCommandExecutor();

		bool Execute(const std::string& command);

	};

}



