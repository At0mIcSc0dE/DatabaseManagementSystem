#include "pch.h"
#include "Database.h"


namespace QRD
{
	Database::Database(const std::string& filePath)
		: m_DBFilePath(filePath), m_Tables{}
	{
		ReadDb();
	}

	Table& Database::CreateTable(const std::string& tableName)
	{
		Table table(tableName, (const int)m_Tables.size());

		m_Tables.emplace_back(std::move(table));
		return m_Tables[m_Tables.size() - 1];
	}

	Table& Database::GetTable(const std::string& tableName)
	{
		for (auto& table : m_Tables)
		{
			if (table.GetTableName() == tableName)
				return table;
		}
		
	}

	void Database::DeleteTable(const Table& table)
	{
		for (const Table& tab : m_Tables)
		{
			if (tab == table)
				m_Tables.erase(m_Tables.begin() + tab.GetTableId());
		}
	}

	void Database::DeleteTable(const std::string& tableName)
	{
		for (const Table& tab : m_Tables)
		{
			if (tab.GetTableName() == tableName)
				m_Tables.erase(m_Tables.begin() + tab.GetTableId());
		}
	}

	void Database::ReadDb()
	{
		std::ifstream reader(m_DBFilePath);

		std::string line;
		std::getline(reader, line);
		unsigned short tableNr = std::stoi(line.replace(0, 8, ""));
		
		std::getline(reader, line);

		for (unsigned short i = 0; i < tableNr; ++i)
		{
			Table& table = this->CreateTable(line.replace(0, 7, ""));

			ReadFields(reader, line);
			ReadRecords(reader, line);
		}

	}

	void Database::WriteDb()
	{

	}

	void Database::ExitDb()
	{
		WriteDb();
	}

	void Database::ReadFields(std::ifstream& reader, std::string& line)
	{
		Table& table = m_Tables[m_Tables.size() - 1];

		std::getline(reader, line);
		std::getline(reader, line);
		std::getline(reader, line);

		while (line != "}")
		{
			unsigned char typeIdx = (unsigned char)line.find(':') + 1;

			if (line[typeIdx] == 'I')
				table.AddField<INTEGER_TYPE>(line.replace(line.size() - 8, line.size() - 1, "").replace(0, 4, ""));
			else if (line[typeIdx] == 'T')
				table.AddField<TEXT_TYPE>(line.replace(line.size() - 5, line.size() - 1, "").replace(0, 4, ""));

			std::getline(reader, line);
		}
	}

	void Database::ReadRecords(std::ifstream& reader, std::string& line)
	{
		Table& table = m_Tables[m_Tables.size() - 1];
		
		std::getline(reader, line);
		unsigned short recordNr = std::stoi(line.replace(0, 9, ""));

		std::getline(reader, line);
		std::getline(reader, line);
		std::getline(reader, line);

		for (unsigned short i = 0; i < recordNr; ++i)
		{
			Record& rec = table.AddRecord();
			while (line != "}")
			{
				rec.AddData(line.replace(0, 4, ""));
				std::getline(reader, line);
			}
			std::getline(reader, line);
			std::getline(reader, line);
			std::getline(reader, line);
		}
	}

}


