#include "pch.h"
#include "Field.h"


namespace QRD
{
    Field::Field(const std::string& fieldName, const DbTypes& dbType, const unsigned short fieldId)
        : m_FieldName(fieldName), m_FieldType(dbType), m_FieldId(fieldId)
    {
    }

    bool Field::operator==(const Field& other)
    {
        return m_FieldName == other.GetFieldName() && m_FieldType == other.GetFieldType() && m_FieldId == other.GetFieldId();
    }
}

