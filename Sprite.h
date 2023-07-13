#pragma once
class Sprite
{
public:
	Sprite(int w, int h);
	SDL_Color* GetPixels()const;
	void SetPixel(int x, int y, SDL_Color value);

	int m_X;
	int m_Y;
	int m_Width;
	int m_Height;
private:
	SDL_Color* m_pPixels;
};

