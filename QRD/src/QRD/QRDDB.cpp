#include "pch.h"
#include "QRDDB.h"


namespace QRD
{
    QRDDB::QRDDB(const std::string& dbFilePath)
        : m_DBFilePath(dbFilePath), m_Data{}
    {
        Read();
    }

    Table& QRDDB::AddTable(const std::string& tableName, const GlobalFlags& flags)
    {
        Table* table = new Table(tableName);
        m_Data.insert({table, {}});
        return *table;
    }

    Table&& QRDDB::GetTable(const std::string& tableName)
    {
        return Table(tableName);
    }

    void QRDDB::Read()
    {
        std::fstream reader(m_DBFilePath);

        std::string line;
        std::getline(reader, line);
        if (line.find("TABLE: ") != std::string::npos)
        {
            Table& table = this->AddTable(line.replace(0, 7, ""));

            std::getline(reader, line);
            std::getline(reader, line);
            std::getline(reader, line);

            while (line != "}")
            {
                unsigned char datatypeIndex = (unsigned char)line.find(":") + 1;
                if (line[datatypeIndex] == 'I')
                    table.AddField<INTEGER_TYPE>(line);
                else if (line[datatypeIndex] == 'T')
                    table.AddField<TEXT_TYPE>(line);

                std::getline(reader, line);
            }
            
            std::getline(reader, line);
            unsigned int numOfRecs = std::stoi(line.replace(0, 9, ""));
            for (unsigned int i = 0; i < numOfRecs; ++i)
            {
                Record rec = table.AddRecord();
                std::getline(reader, line);
                std::getline(reader, line);
                std::getline(reader, line);

                while (line != "}")
                {
                    unsigned char datatypeIndex = (unsigned char)line.find(":") + 1;
                    if (line[datatypeIndex] == 'I')
                    {
                        rec.AddData(std::stoi(line));
                    }
                    else if (line[datatypeIndex] == 'T')
                    {
                        rec.AddData(line);
                    }
                    std::getline(reader, line);
                }
            }
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
