#include "Application.h"
#include <iostream>

#include <Windows.h>

extern size_t totalAllocs;


Application::Application(const std::string& filePath)
	: m_Running(true), m_Database(filePath, 0)
{
	
}

void Application::Run()
{
	/**
	* TODO:
	*	Invalidate Objects if they were deleted
	*	Decide whether the client should call RevalidateReferences or if QRD should detect vector resizing and call it itself
	*/

	QRD::Table& tb1 = m_Database.CreateTable("Table1");
	QRD::Table& tb2 = m_Database.CreateTable("Table2");

	m_Database.RevalidateReferences(tb1, tb2);

	std::cout << tb1.GetTableName() << '\n' << tb2.GetTableName() << '\n';

	m_Database.ExitDb();
	//QRD_LOG(totalAllocs);
}
