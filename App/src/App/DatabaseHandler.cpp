#include "DatabaseHandler.h"

DatabaseHandler::DatabaseHandler(const char* filePath)
	: dbManager(filePath)
{

}

void DatabaseHandler::CreateTable(const char* tableName, int flags)
{
	//if (HasFlag(flags, ALLOW_DUPLICATE))
	//{
	//	dbManager.Eval("CREATE TABLE {0}, {1}", tableName);
	//}
	//else
	//{
	//	dbManager.Eval("CREATE TABLE IF NOT EXISTS {0}, {1}", tableName);
	//}

	dbManager.Eval("CREATE TABLE IF NOT EXISTS {0}, {1}, {2}", "[TABLENAME]", "ARG1", "ARG2");

}

bool DatabaseHandler::HasFlag(int flags, Flags flag)
{
	return flags & flag;
}
