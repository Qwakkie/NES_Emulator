#include "pch.h"
#include "Sprite.h"

Sprite::Sprite(int w, int h, int x, int y)
	:m_Width{w}
	,m_Height{h}
	,m_pPixels{new SDL_Color[h*w]}
	,m_X{x}
	,m_Y{y}
{
}

Sprite::~Sprite()
{
}

SDL_Color* Sprite::GetPixels() const
{
	return m_pPixels;
}

void Sprite::SetPixel(int x, int y, SDL_Color value)
{
	if(x + y * m_Width < m_Width * m_Height)
		m_pPixels[x + y * m_Width] = value;
}
