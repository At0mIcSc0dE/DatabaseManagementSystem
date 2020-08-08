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
	TIMER;
	QRD::Table& OneTimeExp = m_Database.GetTable("OneTimeExpenses");
	QRD::Table& MonthlyExp = m_Database.GetTable("MonthlyExpenses");
	QRD::Table& OneTimeTak = m_Database.GetTable("OneTimeTakings");
	QRD::Table& MonthlyTak = m_Database.GetTable("MonthlyTakings");
	
	QRD::Record& rec = OneTimeExp.GetRecordById(0);
	OneTimeExp.EditRecord(rec, "Christa2", 12, "No Info", 8, 8, 2020, "General", "Mom");

	m_Database.ExitDb();
	QRD_LOG(totalAllocs);
}
