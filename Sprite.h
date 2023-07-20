#pragma once
class SDL_Surface;

class Sprite
{
public:
	Sprite(int w, int h, int x = 0, int y = 0);
	~Sprite();

	SDL_Color* GetPixels()const;
	void SetPixel(int x, int y, SDL_Color value);

	int m_X;
	int m_Y;
	int m_Width;
	int m_Height;
	float m_Scale{ 1 };
private:
	SDL_Color* m_pPixels;
};

