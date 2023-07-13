#include "pch.h"
#include "Sprite.h"

Sprite::Sprite(int w, int h)
	:m_Width{w}
	,m_Height{h}
	,m_pPixels{new SDL_Color[h*w]}
{
}

SDL_Color* Sprite::GetPixels() const
{
	return m_pPixels;
}

void Sprite::SetPixel(int x, int y, SDL_Color value)
{
	m_pPixels[x + y * m_Width] = value;
}
