#pragma once
#include "d3dclass.h"
#include "cameraclass.h"
#include "modelclass.h"
#include "colorshaderclass.h"

const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();

private:
	bool Render(float);


	D3DClass* m_Direct3D{ nullptr };
	CameraClass* m_Camera{ nullptr };
	ModelClass* m_Model{ nullptr };
	ColorShaderClass* m_ColorShader{ nullptr };
};

