#include "pch.h"
#include "Record.h"


namespace QRD
{
    bool Record::operator==(const Record& other) const
    {
        return m_RecordData == other.GetRecordData() && m_RecordId == other.GetRecordId();
    }

    void Record::DeleteData(unsigned short fieldId)
    {
        m_RecordData.erase(m_RecordData.begin() + fieldId);
    }
}

