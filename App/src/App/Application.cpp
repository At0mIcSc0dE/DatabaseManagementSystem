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
	*/

	QRD::Table& tb1 = m_Database.GetTable("Table1");
	QRD::Table& tb2 = m_Database.GetTable("Table2");
	QRD::Table& tb3 = m_Database.GetTable("Table3");
	QRD::Table& tb4 = m_Database.GetTable("Table4");

	//for (unsigned int i = 0; i < 10000; ++i)
	//{
	//	tb1.AddRecord("Christa", 12.65, "NoInfo", i, i + 100, i + 1000);
	//	tb2.AddRecord("Christa", 12.65, "NoInfo", i, i + 100, i + 1000);
	//	tb3.AddRecord("Christa", 12.65, "NoInfo", i, i + 100, i + 1000);
	//	tb4.AddRecord("Christa", 12.65, "NoInfo", i, i + 100, i + 1000);
	//}

	const auto& recs = tb1.GetRecordsByValues("Price:12.64");

	std::cout << recs[0]->GetRecordData()[1] << '\n';

	m_Database.ExitDb();
	//QRD_LOG(totalAllocs);
}
