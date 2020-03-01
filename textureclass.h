#pragma once
#ifndef _TEXTURECLASS_H_
#define _TEXTURECLASS_H_


#include "DirectXTex.h"

#include <d3d11.h>
#include <stdio.h>

class TextureClass
{
public:
	TextureClass();
	TextureClass(const TextureClass&);
	~TextureClass();

	bool Initialize(ID3D11Device*, WCHAR*);
	void Shutdown();

	ID3D11ShaderResourceView* GetTexture();


private:
	ID3D11ShaderResourceView* m_texture;

};

#endif