#include "systemclass.h"

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR pScmdline,
	int iCmdshow)
{
	SystemClass* System = nullptr;
	bool result;

	// Create the window class (like lil system).
	System = new SystemClass;
	if (!System)
	{
		return 0;
	}

	// Initialize and run the window
	result = System->Initialize(800,800);
	if (result)
	{
		// if everything is OK, show begin
		System->Run();
	}

	// Shutdown and release the window
	System->Shutdown();
	delete System;
	System = nullptr;

	return 0;
}