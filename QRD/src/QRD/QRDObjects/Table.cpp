#include "pch.h"
#include "Table.h"


namespace QRD
{
	Table::Table(const std::string& tableName)
	{

	}

	//void Table::EditTable(const std::string& oldName, const std::string& newName)

	Column&& Table::AddColumn(const std::string& columnName)
	{
		Column col = Column(columnName);
		m_Columns.emplace_back(col);
		return std::move(col);
	}

	Column&& Table::InsertColumn(const std::string& columnName, const unsigned short index)
	{
		Column col = Column(columnName);
		m_Columns.emplace_back(col);
		return std::move(col);
	}

	void Table::DeleteTable()
	{

	}
}
