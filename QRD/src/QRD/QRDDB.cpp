#include "pch.h"
#include "QRDDB.h"


namespace QRD
{
    QRDDB::QRDDB(const std::string& dbFilePath)
    {
        QRDObject::SetFilePath(dbFilePath);
        Read();
    }

    Table&& QRDDB::AddTable(const std::string& tableName, const QRDFlags& flags)
    {
        return Table(tableName);
    }

    Table&& QRDDB::GetTable(const std::string& tableName)
    {
        return Table(tableName);
    }

    void QRDDB::Read()
    {

    }

    void QRDDB::Write()
    {

    }

    void QRDDB::ExitQRD()
    {

    }
}
