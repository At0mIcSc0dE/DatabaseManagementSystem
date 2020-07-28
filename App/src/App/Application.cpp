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
	QRD::Table table = m_Database.AddTable("Table1", QRD::IfNotExist);
	//QRD::Table table2 = m_Database.GetTable("Table1");

	//Add column Age to the table
	table.AddColumn<QRD::TEXT>("Age");
	
	while (m_Running)
	{
		std::cout << "Enter your age: ";
		std::cin >> age;
		
		// Add the age to the table
		QRD::Record rec = table.AddRecord(age);


		//QRD::Column col = table.AddColumn<QRD::TEXT>("gd");
		//QRD::Column colI = table.InsertColumn<QRD::TEXT>("COLANE", 2);
		m_Database.Write();
	}

	m_Database.ExitQRD();
}
