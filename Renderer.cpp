#include "Renderer.h"

Renderer::Renderer(SDL_Window* pWindow)
	:m_ClearColor{}
{
	m_pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(m_pRenderer);
}

void Renderer::ClearScreen()
{
	SDL_SetRenderDrawColor(m_pRenderer, m_ClearColor.r, m_ClearColor.g, m_ClearColor.b, m_ClearColor.a);
	SDL_RenderClear(m_pRenderer);
}

void Renderer::SetClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	m_ClearColor = { r, g, b, a };
}

void Renderer::RenderPresent()
{
	SDL_RenderPresent(m_pRenderer);
}
