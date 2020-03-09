#pragma once

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include <d3d11.h>
#include <directxmath.h>
using namespace DirectX;

class D3DClass
{
public:
	D3DClass() {};
	D3DClass(const D3DClass&) {};
	~D3DClass() {};

	bool Initialize(
		int screenWidth, int screenHeight,
		HWND hwnd,
		float screenDepth, float screenNear);
	void Shutdown();

	void BeginScene(float red, float green, float blue, float alpha);
	void EndScene();

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();

	void GetProjectionMatrix(XMMATRIX&);
	void GetWorldMatrix(XMMATRIX&);
	void GetOrthoMatrix(XMMATRIX&);

	

private:
	ID3D11Device* m_device {nullptr};
	ID3D11DeviceContext* m_deviceContext {nullptr};
	IDXGISwapChain* m_swapChain {nullptr};
	ID3D11RenderTargetView* m_renderTargetView {nullptr};

	ID3D11Texture2D* m_depthStencilBuffer {nullptr};
	ID3D11DepthStencilView* m_depthStencilView {nullptr};

	// Setup the projection matrix.
	float screenAspect{1};
	float fieldOfView = 3.141592654f / 4.0f;

	XMMATRIX m_projectionMatrix;
	XMMATRIX m_worldMatrix;
	XMMATRIX m_orthoMatrix;
};
