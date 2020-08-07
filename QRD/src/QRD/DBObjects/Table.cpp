#include "pch.h"
#include "Table.h"


namespace QRD
{
    Table::Table(const std::string& tableName, const int id)
        : m_TableName(tableName), m_Records{}, m_Fields{}, m_Id(id)
    {
    }

    Field& Table::GetField(const std::string_view fieldName)
    {
        for (auto& field : m_Fields)
        {
            if (field.GetFieldName() == fieldName)
                return field;
        }
    }

    void Table::DeleteField(const Field& field)
    {

    }

    void Table::DeleteField(const std::string& fieldName)
    {

    }

    Record& Table::GetRecordById(const int id)
    {
        return m_Records[id];
    }

    void Table::DeleteRecord(const Record& record)
    {

    }

    void Table::DeleteRecord(const std::string& commandStr)
    {

    }

    bool Table::operator==(const Table& other) const
    {
        if(m_Id == other.m_Id)
            return true;
        return false;
    }

}
