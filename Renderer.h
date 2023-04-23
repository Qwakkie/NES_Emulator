#pragma once

class Renderer
{
public:
	Renderer(SDL_Window* pWindow);
	~Renderer();
	Renderer(const Renderer& other) = delete;
	Renderer(const Renderer&& other) = delete;
	Renderer operator=(const Renderer& other) = delete;
	Renderer operator=(Renderer&& other) = delete;

	void ClearScreen();
	void SetClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = SDL_ALPHA_OPAQUE);
	void DrawFrame(SDL_Color* pixelArray)const;
	void RenderPresent();
private:
	SDL_Color m_ClearColor;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pRenderTexture;
};

