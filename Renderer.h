#pragma once
#include "SDL.h"

class Renderer
{
public:
	Renderer(SDL_Window* pWindow);
	~Renderer();
	Renderer(const Renderer& other) = delete;
	Renderer(const Renderer&& other) = delete;
	Renderer operator=(const Renderer& other) = delete;
	Renderer operator=(Renderer&& other) = delete;
private:
	SDL_Renderer* m_pRenderer;
};

