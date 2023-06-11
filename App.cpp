#include "pch.h"
#include "App.h"
#include <iostream>

#include "Renderer.h"
#include "Window.h"

#include "FileSelector.h"
#include "FileReader.h"

AppSettings App::m_AppSettings{};

App::App()
	: m_bInitialized{ false } 
{
	Initialize();
	m_pWindow = new Window{m_AppSettings.WindowWidth, m_AppSettings.WindowHeight };
	m_pRenderer = new Renderer{ m_pWindow->GetPointerHandler() };
}

App::~App()
{
	delete m_pWindow;
	delete m_pRenderer;
	SDL_Quit();
}

void App::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
		return;
	}
	std::cout << "SDL initialization succeeded!";
	m_bInitialized = true;
}

void App::Run()
{
	if (!m_bInitialized) return;
	SDL_Event event;
	bool running = true;

	while (running)
	{
		// Implement the sequence of tasks here.
		m_pRenderer->ClearScreen();

		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
			{
				running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;
				break;
			}
			case SDL_QUIT:
			{
				running = false;
				break;
			}
			default:
				break;
			}
		}
		const int bufferSize{ m_AppSettings.WindowWidth * m_AppSettings.WindowHeight };
		SDL_Color* pixelBuffer{ new SDL_Color[bufferSize]{} };

		m_pRenderer->DrawFrame(pixelBuffer);
		m_pRenderer->RenderPresent();
	}
}

AppSettings& App::GetAppSettings()
{
	return m_AppSettings;
}
