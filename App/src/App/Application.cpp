#include "Application.h"
#include <iostream>

#include <Windows.h>

extern size_t totalAllocs;


Application::Application(const std::string& filePath)
	: m_Running(true), m_Database(filePath)
{
	
}

void Application::Run()
{
	
	//Create table Table1, alternatively get table Table1
	//QRD::Table& table = m_Database.AddTable("Table1");
	//QRD::Table table2 = m_Database.GetTable("Table1");

	//table.DeleteColumn(col);

	//table.AddField<QRD::INTEGER_TYPE>("HE");

	/******
	**NEW**
	******/

	QRD::Table table = m_Database.GetTable("table1");
	//QRD::Table table2 = m_Database.GetTable("fds");

	//table.AddField<QRD::INTEGER_TYPE>("field1");

	//table.GetRecordsByValues("field1:32,field2:Si");
	while (m_Running)
	{
		auto recs = table.GetRecordsByValues("f1:120", "f2:Simon"); //WORKING
		//auto recs = table.GetRecordsByValues("f1:120");
		//auto recs = table.GetRecords();
		//for (auto rec : recs)
		//{
		//	if (rec.GetData()[0] == "120" && rec.GetData()[2] == "30")
		//		std::cout << "Record found\n";
		//}

		// Add the age to the table
		//QRD::Record rec = table.AddRecord(age);

		//Skipping first, second and forth column from being searched
		//std::tuple<QRD::Record> recs = table.GetRecord(QRD_NULL, QRD_NULL, "Hello", QRD_NULL, 3);
		//std::tuple<QRD::Record> recs = table.GetRecordByName("col1:Hello,col2:3");
		//std::tuple<QRD::Record> recs = table.GetRecordById("col1:Hello,col2:3");

		//QRD::Column col = table.AddColumn<QRD::TEXT>("gd");
		//QRD::Column colI = table.InsertColumn<QRD::TEXT>("COLANE", 2);
		//m_Database.Write();

		/******
		**NEW**
		******/
		m_Database.WriteDb();		
		QRD_LOG(totalAllocs);

	}

	m_Database.ExitDb();
}
