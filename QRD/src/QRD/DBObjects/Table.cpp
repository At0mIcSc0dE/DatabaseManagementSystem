#include "pch.h"
#include "Table.h"


namespace QRD
{
    Table::Table(const std::string& tableName, std::vector<DbData*>& data)
        : m_TableName(tableName), m_Data(data), m_IndexInData(-1)
    {
    }

    void Table::DeleteField(const Field& field)
    {

    }

    void Table::DeleteField(const std::string& fieldName)
    {

    }

    std::tuple<Record> Table::GetRecordsByValues(const std::string& commandStr)
    {
        return std::tuple<Record>();
    }

    Record& Table::GetRecordById(const int id)
    {
        Record rec;
        return rec;
    }

    void Table::DeleteRecord(const Record& record)
    {

    }

    void Table::DeleteRecord(const std::string& commandStr)
    {

    }

}
