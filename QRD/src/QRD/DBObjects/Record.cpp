#include "pch.h"
#include "Record.h"


namespace QRD
{
    bool Record::operator==(const Record& other) const
    {
        return m_Data == other.GetRecordData() && m_RecordId == other.GetRecordId();
    }

    void Record::DeleteData(unsigned short fieldId)
    {
        m_Data.erase(m_Data.begin() + fieldId);
    }
}

