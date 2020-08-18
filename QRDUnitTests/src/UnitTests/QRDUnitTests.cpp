#include "CppUnitTest.h"
#include "../Assert/Assert.h"
#include <QRD/QRD.h>
//#include "../ToStringImpl.h"


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
			QRDTest::Assert::AreEqual({}, m_Db.GetTables(), "Error");
		}

		TEST_METHOD(CreateTable)
		{
			QRD::Table& table = m_Db.CreateTable("Table1");
			//MVCUF::Assert::AreEqual({ table }, m_Db.GetTables());
			//MVCUF::Assert::AreEqual(table, m_Db.GetTable("Table1"));
			//MVCUF::Assert::AreEqual(table, m_Db.GetTables()[m_Db.GetTables().size() - 1]);

		}
	};
}

