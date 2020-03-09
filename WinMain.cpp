#include "systemclass.h"

//------------------------------------------------------------------------------------
// Точка входа в программу. Инициализация всех объектов и вход в цикл сообщений.
// Свободное время используется для отрисовки сцены.
//------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int iCmdshow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(pCmdLine);
	bool result;

	auto app = std::make_unique<SystemClass>(800, 800, L"Solar System");
	if (!app)
	{
		return 0;
	}

	// Initialize and run the system object.
	result = app->Initialize();
	if (result)
	{
		// if everything ok, show must begin
		app->Run();
	}

	// Shutdown and release the system object.
	app->Shutdown();

	return 0;
}