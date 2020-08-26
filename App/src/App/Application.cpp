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
	/**
	* TODO:
	*	Invalidate Objects if they were deleted
	*	Decide whether the client should call RevalidateReferences or if QRD should detect vector resizing and call it itself
	*	Test deletion
	*/
	
	QRD::Table& tb1 = m_Database.CreateTable("Table1");
	QRD::Field& fName = tb1.AddField<QRD::TEXT>("Name");
	QRD::Field& fAge = tb1.AddField<QRD::NUMBER>("Age");

	QRD::Record& rSimon = tb1.AddRecord("Simon", 15);
	QRD::Record& rJonas = tb1.AddRecord("Jonas", 11);

	std::cout << m_Database.ToString() << '\n';

	//QRD_LOG(totalAllocs);
}
