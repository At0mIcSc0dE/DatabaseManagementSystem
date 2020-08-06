#include "pch.h"
#include "Database.h"


namespace QRD
{
	Database::Database(const std::string& filePath)
		: m_DBFilePath(filePath), m_Data{}
	{

	}

	Table& Database::CreateTable(const std::string& tableName)
	{
		Table table(tableName, this);

		DbData* data = new DbData{std::move(table), {} };

		m_Data.emplace_back(data);
		return m_Data[m_Data.size() - 1]->table;
	}

	Table& Database::GetTable(const std::string& tableName)
	{
		for (auto& dbData : m_Data)
		{
			if (dbData->table.GetTableName() == tableName)
				return dbData->table;
		}
		
	}

	void Database::DeleteTable(const Table& table)
	{

	}

	void Database::DeleteTable(const std::string& tableName)
	{

	}

	void Database::ReadDb()
	{

	}

	void Database::WriteDb()
	{

	}

	void Database::ExitDb()
	{
		WriteDb();
	}

}


