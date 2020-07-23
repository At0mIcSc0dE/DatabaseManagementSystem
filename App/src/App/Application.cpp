#include "Application.h"

Application::Application(const char* filePath)
	: m_Running(true), dbHandler(filePath)
{
}

void Application::Run()
{
	//while (m_Running)
	//{
		dbHandler.CreateTable("[TABLENAME]", ALLOW_DUPLICATE);
	//}
}
