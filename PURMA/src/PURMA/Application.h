#pragma once

#include "Core.h"

namespace PURMA {
	// NOTE:  Header soubory jsou interfacy kódu, ukazují jak mají třídy vypadat, ale jak fungují
	// NOTE: __declspec (dllexport) Windows-specific compiler directive, která říka "Exportuj tuhle třídu z DLL", tzn. že tuhle třídu půjde z DLL používat
	class PUR_API Application
	{
	public:
		Application();

		// NOTE:  "~" = Deconstruct, co se má dít při smazání, uvolnění
		virtual ~Application();

		void Run();
	};

	// To be defined in a CLIENT
	Application* CreateApplication();
}


