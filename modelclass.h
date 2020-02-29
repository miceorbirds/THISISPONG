#ifndef _MODELCLASS_H_
#define _MODELCLASS_H_



#include <d3d11.h>
#include <directxmath.h>
using namespace DirectX;

#include "textureclass.h"


class ModelClass
{
private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

public:
	ModelClass();
	ModelClass(const ModelClass&);
	~ModelClass();

	bool Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, char* textureFilename);

	void Shutdown();
	void Render(ID3D11DeviceContext*);

	void SetVertexCount(int x);
	void SetIndexCount(int x);
	ID3D11ShaderResourceView* GetTexture();

	int GetIndexCount();


private:
	bool InitializeBuffers(ID3D11Device*) ;
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);
	bool LoadTexture(ID3D11Device*, ID3D11DeviceContext*, char*);
	void ReleaseTexture();

private:
	ID3D11Buffer* m_vertexBuffer, * m_indexBuffer;
	int m_vertexCount, m_indexCount;
	VertexType* m_vertices;
	TextureClass* m_Texture;
};

#endif