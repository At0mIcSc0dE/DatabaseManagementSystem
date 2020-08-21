#include "Application.h"
#include <iostream>

#include <Windows.h>

extern size_t totalAllocs;


Application::Application(const std::string& filePath)
	: m_Running(true), m_Database(filePath, 4, 6, 10000)
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

	QRD::Table tb1 = m_Database.GetTable("Table1");
	QRD::Table tb2 = m_Database.GetTable("Table1");
	QRD::Table tb3 = m_Database.GetTable("Table1");
	QRD::Table tb4 = m_Database.GetTable("Table1");

	m_Database.ExitDb();
	//QRD_LOG(totalAllocs);
}
