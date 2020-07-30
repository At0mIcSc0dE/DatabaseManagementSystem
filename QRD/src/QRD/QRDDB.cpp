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
        std::getline(reader, line);
        if (line.find("TABLE ") != std::string::npos)
        {
            Table* table = new Table(line.replace(0, 6, ""));

            // Get the next lines (COLUMS, {, 1stCol)
            std::getline(reader, line);
            std::getline(reader, line);
            std::getline(reader, line);
            
            // Loop over every column and add them to table
            while (line != "}")
            {
                table->AddColumn(line);
                std::getline(reader, line);
            }

            // Get the next lines (FIELDS, {, 1stField)
            std::getline(reader, line);
            std::getline(reader, line);
            std::getline(reader, line);

            // Loop over every field and add them to table
            while (line != "}")
            {
                // If line after : is a I (Integer)
                if (line[line.size() - 7] == 'I')
                {
                    table->AddField<QRD_INTEGER>(line.replace(line.size() - 8, line.size() - 1, ""));
                }
                else
                {
                    table->AddField<QRD_TEXT>(line.replace(line.size() - 4, line.size() - 1, ""));
                }

                std::getline(reader, line);
            }

            // Insert the table into m_Data
            m_Data.insert({ table, {} });

            // Get amount of records
            std::getline(reader, line);
            unsigned int amntOfRecs = std::stoi(line.replace(0, 8, ""));

            // Get the lines (RECORD, {, 1stRec)
            std::getline(reader, line);
            std::getline(reader, line);
            std::getline(reader, line);

            for (unsigned int recNum = 0; recNum < amntOfRecs; ++recNum)
            {
                m_Data[table].emplace_back(&Record());
                while (line != "}")
                {
                    m_Data[table][recNum]->AddData(line.replace(0, 4, ""));
                    std::getline(reader, line);
                }
                std::getline(reader, line);
                std::getline(reader, line);
                std::getline(reader, line);
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
