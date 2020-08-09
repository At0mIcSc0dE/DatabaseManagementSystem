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
	
	OneTimeExp.AddRecord("Christa", 32, "", 3, 3, 3333, "c", "c");

	m_Database.ExitDb();
	QRD_LOG(totalAllocs);
}
