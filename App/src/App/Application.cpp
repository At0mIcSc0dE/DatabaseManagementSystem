#include "Application.h"
#include <iostream>


Application::Application(const char* filePath)
	: m_Running(true)
{
}

void Application::Run()
{
	int age;
	QRD::Table table = m_Database.AddTable("Table1", QRD::IfNotExist | QRD::IfNotExist);
	while (m_Running)
	{
		std::cout << "Enter your age: ";
		std::cin >> age;
		// Adds record to the end of the table
		table.AddRecord(1, 32, "Hefld", 3);
		//table.AddColumn<TEXT>("gd");
	}
}
