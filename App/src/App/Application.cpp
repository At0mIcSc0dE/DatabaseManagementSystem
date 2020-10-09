#include "Application.h"
#include <iostream>


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

	QRD::Table& tb1 = m_Database.GetTable("tb1");
	//tb1.AddRecord("Hello\nWorld", 3);

	std::cout << tb1.GetRecordById(2).GetRecordData()[0] << '\n';

	m_Database.ExitDb();
	//QRD_LOG(totalAllocs);
}
