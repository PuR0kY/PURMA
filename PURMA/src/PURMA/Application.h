#pragma once

#include "Core.h"

namespace PURMA {
	// Header soubory jsou interfacy kódu, ukazují jak mají třídy vypadat, ale jak fungují
	// __declspec (dllexport) Windows-specific compiler directive, která říka "Exportuj tuhle třídu z DLL", tzn. že tuhle třídu půjde z DLL používat
	class PUR_API Application
	{
	public:
		Application();
		virtual ~Application(); // Deconstruct, co se má dít při smazání, uvolnění

		void Run();
	};

	// To be defined in a CLIENT
	Application* CreateApplication();
}


