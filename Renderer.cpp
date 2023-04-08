#include "Renderer.h"

Renderer::Renderer(SDL_Window* pWindow)
{
	m_pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(m_pRenderer);
}
