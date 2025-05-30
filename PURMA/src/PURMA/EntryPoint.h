#pragma once

#ifdef PUR_PLATFORM_WINDOWS

/*
* returns application that is defined somewhere else
* "extern" znamená "Nedefinuj tuto proměnnou, je již deklarovaná někde jinde (třeba v jiném souboru)
*/
extern PURMA::Application* PURMA::CreateApplication();

/// <summary>
/// 
/// </summary>
/// <param name="argc">Argument Count</param>
/// <param name="argv">Argument Values</param> // Pointer-to-Pointer to char, ekvivalent char* argv[]
/// <returns></returns>
int main(int argc, char** argv)
{
	printf("Welcome to PURMA!");
	/* "auto" nechává compiler rozhodnout datový typ */
	auto app = PURMA::CreateApplication();
	app->Run();
	delete app;
}
#endif

// NOTE: Existují také smart-pointery, kdy lze zapsat takto:
	/*
	* std::unique_ptr<Sandbox> sandbox = std::make_unique<Sandbox>(); <- je automaticky deletnutý pokud se dostane "out of scope"
	* - nelze je zkopírovat, pouze přemístit:
	* std::unique_ptr<Sandbox> other = std::move(app);  // now `sandbox` is empty
	*
	* NEBO:
	* lze používat tyto shared pointery, kdy používá tzv. reference counting => objekt je zničen jakmile poslendní shared_ptr je zničen
	*
	* std::shared_ptr<Sandbox> app = std::make_shared<Sandbox>();
	* std::shared_ptr<Sandbox> second = app; // both share ownership
	*
	* Useful pro:
	* - GUI trees
	* - Game object references
	* - Plugin Systems
	*/
// "->" = equivalent to (*app).Run() sandbox je pointer na objekt typu Sandbox, pokud chceme hodnotu pointeru musíme použít *app nebo -> a rovnou volat funkci tohoto objektu