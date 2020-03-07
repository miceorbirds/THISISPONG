#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <memory> //for std::unique_ptr

#include "inputclass.h"
#include "graphicsclass.h"

class SystemClass
{
public:
	SystemClass(int width, int height, const wchar_t* name);
	SystemClass(const SystemClass&);
	~SystemClass();

	bool Initialize();
	void Shutdown();


	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitializeWindows();
	void ShutdownWindows();

private:
	const wchar_t* m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;
	int clientAreaWidth;
	int clientAreaHeight;
	InputClass* m_Input;
	GraphicsClass* m_Graphics;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static SystemClass* ApplicationHandle = nullptr;