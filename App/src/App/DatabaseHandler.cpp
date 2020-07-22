#include "DatabaseHandler.h"

void DatabaseHandler::CreateTable(const char* tableName, int flags)
{
	if (HasFlag(flags, ALLOW_DUPLICATE))
	{
		//DBMS.eval("CREATE TABLE {0}", tableName);
	}
	else
	{
		//DBMS.eval("CREATE TABLE IF NOT EXISTS {0}", tableName);
	}
}

bool DatabaseHandler::HasFlag(int flags, Flags flag)
{
	return flags & flag;
}
