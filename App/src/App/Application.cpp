#include "Application.h"

Application::Application()
	: m_Running(true)
{
}

void Application::Run()
{
	while (m_Running);
}
