#include "systemclass.h"
#include <iostream>

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR pScmdline,
	int iCmdshow)
{

	HRESULT hr = CoInitializeEx(nullptr, COINITBASE_MULTITHREADED);
	if (FAILED(hr))
		// error
	{
		std::cout << "Hello" << std::endl;
	}

	// I. создаём объект окна и инициализируем его в 0
	SystemClass* System = nullptr;
	bool result;
	// Create the window class (like lil system).
	System = new SystemClass;
	if (!System)
	{
		return 0;
	}


	// II. Запускаем процесс создания окна с шириной и высотой
	result = System->Initialize(800,800);
	if (result)
	{
		// III. if everything is OK, show begin
		System->Run();
	}


	// IV. Shutdown and release the window
	System->Shutdown();
	delete System;
	System = nullptr;

	return 0;
}