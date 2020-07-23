#pragma once

#include "pch.h"


enum class CommandType
{
	NONE = 0,
	CreateTable,
	EditTable,
	RemoveTable,
	AddRecord,
	EditRecord,
	RemoveRecord,
};


#define DECL_CMD_TYPE(type)		static CommandType GetStaticCommandType() { return CommandType::##type; }\
								CommandType GetCommandType() const { return CommandType::##type; }\


class Command
{
public:
	virtual CommandType GetCommandType() const = 0;
	virtual bool ExecuteCommand() = 0;

	virtual std::string ToString() const
	{
		return "Command";
	}

	virtual ~Command() { };
};
