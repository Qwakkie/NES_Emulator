#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include <iostream>

#include "FileSelector.h"
#include "Window.h"
#include "Renderer.h"

bool Init();
void Shutdown();

int main(int argc, char* argv[])
{
    FileSelector fileSelector{};
    //bool result = fileSelector.OpenFile();

	Init();

	int windowWidth = 256;
	int windowHeight = 224;
	Window window{ windowWidth, windowHeight };
	Renderer renderer{ window.GetPointerHandler() };

	if (Init() == false) { Shutdown(); }

	SDL_Event event;
	bool running = true;

	while (running)
	{
		// Implement the sequence of tasks here.
		renderer.ClearScreen();

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

		renderer.RenderPresent();
	}

	Shutdown();
    return 0;
}

bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
		return false;
	}
	std::cout << "SDL initialization succeeded!";
	return true;
}

void Shutdown()
{
	SDL_Quit();
}