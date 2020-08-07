#include "pch.h"
#include "Record.h"


namespace QRD
{
    bool Record::operator==(const Record& other) const
    {
        return m_Data == other.GetData();
    }
}

