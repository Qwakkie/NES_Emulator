#include "pch.h"
#include "Renderer.h"
#include "App.h"
#include "Sprite.h"
#include <iostream>

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

void Renderer::DrawFrame()const
{
    SDL_RenderCopy(m_pRenderer, m_pRenderTexture, NULL, NULL);
}

void Renderer::DrawSprite(const Sprite& sprite) const
{
    SDL_Color* pixelPointer = sprite.GetPixels();
    SDL_Color* destination;
    void* pixels;
    int pitch;
    SDL_Texture* pTexture{ SDL_CreateTexture(m_pRenderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, sprite.m_Width, sprite.m_Height) };

    if (SDL_LockTexture(pTexture, NULL, &pixels, &pitch) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't lock texture: %s\n", SDL_GetError());
    }

    for (int row{}; row < sprite.m_Width; ++row) {
#pragma warning (push)
#pragma warning (disable:26451)
        destination = (SDL_Color*)((Uint8*)pixels + row * pitch);
#pragma warning(pop)
        for (int col{}; col < sprite.m_Height; ++col) {
            *destination++ = *pixelPointer++;
        }
    }
    SDL_Rect destRect{sprite.m_X, sprite.m_Y, sprite.m_Width * sprite.m_Scale, sprite.m_Height * sprite.m_Scale};
    SDL_UnlockTexture(pTexture);
    SDL_RenderCopy(m_pRenderer, pTexture, NULL, &destRect);
    SDL_DestroyTexture(pTexture);
}

void Renderer::RenderPresent()
{
	SDL_RenderPresent(m_pRenderer);
}
