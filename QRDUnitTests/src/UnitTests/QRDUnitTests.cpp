#include "ToStringDefines.h"
#include "Logger/Logger.h"
#include <QRD/QRD.h>



namespace QRDUnitTests
{
	namespace MVCUF = Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(QRDUnitTests)
	{
	public:
		QRD::Database m_Db;

		QRDUnitTests() : m_Db("D:\\dev\\ProgramFiles\\DBMS\\DB.dbs") {}

		TEST_METHOD(CreateDatabase)
		{
			for (auto& table : m_Db.GetTables())
			{
				m_Db.DeleteTable(table);
			}
			m_Db.WriteDb();

			MVCUF::Assert::AreEqual({}, m_Db.GetTables(), L"Database::m_Tables should be empty");
		}

		TEST_METHOD(CreateTable)
		{
			if (m_Db.TableExists("Table1"))
			{
				QRDT_LOG("Table Table1 already exists");
				return;
			}

			size_t sizeofm_TablesBeforeAdding = m_Db.GetTables().size();
			QRDT_LOG("Size of m_Db.m_Tables before adding table: {0}", sizeofm_TablesBeforeAdding);

			QRD::Table& table1 = m_Db.CreateTable("Table1");
			QRDT_LOG("Name of new table: {0}", table1.GetTableName());
			MVCUF::Assert::AreEqual(std::string("Table1"), table1.GetTableName());
			
			MVCUF::Assert::AreEqual(sizeofm_TablesBeforeAdding + 1, m_Db.GetTables().size(), L"New table was not added to m_Db.m_Tables");
			MVCUF::Assert::AreEqual(table1, m_Db.GetTable("Table1"), L"Reference to new table does not match the found table by m_Db.GetTable(Table1)");
			MVCUF::Assert::AreEqual(table1, m_Db.GetTables()[m_Db.GetTables().size() - 1], L"Reference to new table is not the same as the last element in m_Db.m_Tables");
			m_Db.WriteDb();
		}

		TEST_METHOD(DeleteTable)
		{
			auto lastTableId = m_Db.GetTables()[m_Db.GetTables().size() - 1].GetTableId();
			auto lastm_TablesSize = m_Db.GetTables().size();

			QRD::Table& table1 = m_Db.GetTable("Table1");
			MVCUF::Assert::AreEqual(std::string("Table1"), table1.GetTableName());

			m_Db.DeleteTable(table1);
			MVCUF::Assert::AreEqual(lastm_TablesSize - 1, m_Db.GetTables().size(), L"Table was not removed from m_Tables");

		}

		TEST_METHOD(AddField)
		{
			QRD::Table& table1 = GetTestTable("Table1");

			table1.AddField<QRD::TEXT>("ExpName");
			table1.AddField<QRD::NUMBER>("ExpPrice");
			table1.AddField<QRD::TEXT>("ExpInfo");
			table1.AddField<QRD::NUMBER>("ExpDay");
			table1.AddField<QRD::NUMBER>("ExpMonth");
			table1.AddField<QRD::NUMBER>("ExpYear");
			table1.AddField<QRD::TEXT>("ExpCat");
			table1.AddField<QRD::TEXT>("ExpUser");

			MVCUF::Assert::AreEqual((size_t)8, table1.GetFields().size(), L"Some field was not added correctly");
			MVCUF::Assert::AreEqual(table1.GetFields()[0], table1.GetField("ExpName"), L"GetField did not find the correct field or GetFields()[0] did not return the correct one");
			MVCUF::Assert::AreEqual(table1.GetFields()[1], table1.GetField("ExpPrice"), L"GetField did not find the correct field or GetFields()[0] did not return the correct one");
			MVCUF::Assert::AreEqual(table1.GetFields()[2], table1.GetField("ExpInfo"), L"GetField did not find the correct field or GetFields()[0] did not return the correct one");
			MVCUF::Assert::AreEqual(table1.GetFields()[3], table1.GetField("ExpDay"), L"GetField did not find the correct field or GetFields()[0] did not return the correct one");
			MVCUF::Assert::AreEqual(table1.GetFields()[4], table1.GetField("ExpMonth"), L"GetField did not find the correct field or GetFields()[0] did not return the correct one");
			MVCUF::Assert::AreEqual(table1.GetFields()[5], table1.GetField("ExpYear"), L"GetField did not find the correct field or GetFields()[0] did not return the correct one");
			MVCUF::Assert::AreEqual(table1.GetFields()[6], table1.GetField("ExpCat"), L"GetField did not find the correct field or GetFields()[0] did not return the correct one");
			MVCUF::Assert::AreEqual(table1.GetFields()[7], table1.GetField("ExpUser"), L"GetField did not find the correct field or GetFields()[0] did not return the correct one");
		}

		TEST_METHOD(EditField)
		{

		}

		TEST_METHOD(DeleteField)
		{

		}

		TEST_METHOD(AddRecord)
		{
			QRD::Table& table1 = GetTestTable("Table1");

			QRD::Record& rec = table1.AddRecord("Christa", 14.43, "NoInfo", 8, 8, 2020, "GeneralCat", "Simon");

		}

		TEST_METHOD(EditRecord)
		{

		}

		TEST_METHOD(DeleteRecord)
		{

		}

		TEST_METHOD(GetFilePath)
		{
			MVCUF::Assert::AreEqual(std::string("D:\\dev\\ProgramFiles\\DBMS\\DB.dbs"), m_Db.GetFilePath());
			QRDT_LOG("File path: {0}", m_Db.GetFilePath());
		}

		QRD::Table& GetTestTable(const std::string& tableName)
		{
			QRD::Table& table1 = m_Db.GetTable("Table1");
			MVCUF::Assert::AreEqual(table1.GetTableId(), m_Db.GetTable("Table1").GetTableId(), L"Reference to table was not assigned correctly");
			MVCUF::Assert::AreEqual(table1.GetTableName(), m_Db.GetTable("Table1").GetTableName(), L"Reference to table was not assigned correctly");
			return table1;
		}

	};
}

