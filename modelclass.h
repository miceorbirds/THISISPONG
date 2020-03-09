#pragma once

#include <d3d11.h>
#include <directxmath.h>
using namespace DirectX;
#include <fstream>
using namespace std;

class ModelClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT4 color;
	};

	struct ModelType
	{
		float x, y, z;
		float r, g, b, a;
	};

	struct ConstantBufferType
	{
		XMMATRIX transform;
	};

public:
	ModelClass();
	ModelClass(const ModelClass&);
	~ModelClass();

	bool Initialize(ID3D11Device*, ID3D11DeviceContext* context, wchar_t*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();

private:
	bool InitializeBuffers(ID3D11Device*, ID3D11DeviceContext*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	bool LoadModel(wchar_t*);
	bool SetModel();
	void ReleaseModel();

private:
	ID3D11Buffer* m_vertexBuffer, * m_indexBuffer, *m_constantBuffer;
	int m_vertexCount, m_indexCount;
	ModelType* m_model;
};