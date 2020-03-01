#include "textureclass.h"
using namespace DirectX;

TextureClass::TextureClass()
{
	m_texture = nullptr;
}


TextureClass::TextureClass(const TextureClass& other)
{
}


TextureClass::~TextureClass()
{
}


bool TextureClass::Initialize(ID3D11Device* device, WCHAR* textureFilename)
{
	HRESULT hResult;
	HRESULT hr;
	//hResult = D3DX11CreateShaderResourceViewFromFile(device, filename, NULL, NULL, &m_texture, NULL);
	auto image = std::make_unique<ScratchImage>();

	hResult = LoadFromTGAFile(textureFilename, nullptr, *image);
	if (FAILED(hResult))
	{
		return false;
	}

	ID3D11Resource* pResource = nullptr;
	hr = CreateTexture(device, image->GetImages(), image->GetImageCount(), image->GetMetadata(), &pResource);
	if (FAILED(hr))
	{
		return false;
	}

	return true;
}


void TextureClass::Shutdown()
{

	// Release the texture.
	if (m_texture)
	{
		m_texture->Release();
		m_texture = nullptr;
	}


	return;
}


ID3D11ShaderResourceView* TextureClass::GetTexture()
{
	return m_texture;
}
