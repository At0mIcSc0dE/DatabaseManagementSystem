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
        while (reader.good())
        {
            std::getline(reader, line);
            if (line.find("TABLE ") != std::string::npos)
            {
                Table table(line.replace(0, 6, ""));

                // Get the next line (Columns)
                std::getline(reader, line);
                
                //Loop over every column separated by comma
                line = line.replace(0, 8, "");
                std::string colName = "";
                unsigned short colIndex = 0;
                
                for (unsigned short i = 0; i < std::count(line.begin(), line.end() + 2, ','); ++i)
                {
                    if (line[i] == ',')
                    {
                        table.AddColumn(colName);
                        colName = "";
                        continue;
                    }
                    colName += line[i];
                }

                // Get the next line (Fields)
                std::getline(reader, line);

                line = line.replace(0, 7, "");
                std::string fieldName = "";
                unsigned short colIndex = 0;
                QRDTypes type = QRD_NULLTYPE;

                for (unsigned short i = 0; i < std::count(line.begin(), line.end() + 2, ','); ++i)
                {
                    if (line[i] == ',')
                    {
                        table.AddField<type>(fieldName);
                        fieldName = "";
                        type = QRD_NULLTYPE;
                        continue;
                    }
                    else if (line[i] == ':')
                    {
                        if (line[i + 1] == 'I')
                        {
                            type = QRD_TEXT;
                            // Skip TEXT in line
                            i += 4;
                        }
                        else
                        {
                            type = QRD_INTEGER;
                            // Skip INTEGER in line
                            i += 7;
                        }
                    }
                    colName += line[i];
                }

                // Get amount of records

                m_Data.insert({ std::move(&table), {} });
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
