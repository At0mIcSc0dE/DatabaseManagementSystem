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

	auto recs = tb1.GetRecordsByValues("s:5");


	//QRD_LOG(totalAllocs);
}
