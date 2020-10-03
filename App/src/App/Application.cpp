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

	m_Database.Clear();
	m_Database.SetFilePath("D:\\dev\\ProgramFiles\\DBMS\\DB2.dbs");
	m_Database.ReadDb(m_Database.GetFieldAllocCount(), m_Database.GetRecordAllocCount());

	m_Database.ExitDb();
	//QRD_LOG(totalAllocs);
}
