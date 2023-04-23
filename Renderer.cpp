#include "pch.h"
#include "Renderer.h"
#include "App.h"
#include <iostream>
#include <string>

Renderer::Renderer(SDL_Window* pWindow)
	:m_ClearColor{}
{
	m_pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	m_pRenderTexture = SDL_CreateTexture(m_pRenderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, App::GetAppSettings().WindowWidth, App::GetAppSettings().WindowHeight);
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

void Renderer::DrawFrame(SDL_Color* pixelArray)
{
    SDL_Color* pixelPointer = pixelArray;
    SDL_Color* destination;
    int row, col;
    void* pixels;
    int pitch;

    if (SDL_LockTexture(m_pRenderTexture, NULL, &pixels, &pitch) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't lock texture: %s\n", SDL_GetError());
    }
    for (row = 0; row < App::GetAppSettings().WindowHeight; ++row) {
        destination = (SDL_Color*)((Uint8*)pixels + (Uint8)(row) * pitch);
        for (col = 0; col < App::GetAppSettings().WindowWidth; ++col) {
            *destination++ = *pixelPointer++;
        }
    }
    SDL_UnlockTexture(m_pRenderTexture);
    SDL_RenderCopy(m_pRenderer, m_pRenderTexture, NULL, NULL);
}

void Renderer::RenderPresent()
{
	SDL_RenderPresent(m_pRenderer);
}
