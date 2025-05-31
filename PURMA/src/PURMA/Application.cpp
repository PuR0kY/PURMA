#include "purpch.h"
#include "Application.h"

#include "PURMA/Events/ApplicationEvent.h"
#include "PURMA/Log.h"

namespace PURMA {

	// NOTE:  Implementace Application třídy z Header souboru
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		PUR_TRACE(e.ToString());

		while (true)
		{

		}
	}
}