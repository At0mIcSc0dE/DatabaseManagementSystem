#include "Application.h"
#include <iostream>


Application::Application(const std::string& filePath)
	: m_Running(true), m_Database(filePath)
{
	
}

void Application::Run()
{
	int age;
	
	//Create table Table1, alternatively get table Table1
	//QRD::Table& table = m_Database.AddTable("Table1");
	//QRD::Table table2 = m_Database.GetTable("Table1");

	//table.DeleteColumn(col);

	//table.AddField<QRD::INTEGER_TYPE>("HE");

	/******
	**NEW**
	******/

	QRD::Table table = m_Database.CreateTable("Table1");
	//QRD::Table table2 = m_Database.GetTable("fds");

	//table.AddField<QRD::INTEGER_TYPE>("field1");

	//table.GetRecordsByValues("field1:32,field2:Si");
	while (m_Running)
	{
		std::cout << "Enter your age: \n";
		//std::cin >> age;
		age = 15;
		
		table.AddRecord("Hello", 3, "32");

		auto& data = m_Database.GetData();

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

	}

	m_Database.ExitDb();
}
