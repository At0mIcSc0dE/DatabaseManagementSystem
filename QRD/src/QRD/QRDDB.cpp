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
        Table table = Table(tableName);

        return std::move(table);
    }

    Table&& QRDDB::GetTable(const std::string& tableName)
    {
        Table table = Table(tableName);
        return std::move(table);
    }

    void QRDDB::Read()
    {
        std::fstream reader(m_DBFilePath);

        std::string line;
        while (getline(reader, line))
        {

        }
    }

    void QRDDB::Write()
    {
        std::ofstream writer(m_DBFilePath);


    }

    void QRDDB::ExitQRD()
    {
        Write();
    }
}
