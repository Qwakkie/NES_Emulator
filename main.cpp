#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include <iostream>

#include "FileSelector.h"
#include "Window.h"
#include "Renderer.h"

bool Init();

int main(int argc, char* argv[])
{
    FileSelector fileSelector{};
    //bool result = fileSelector.OpenFile();

	Init();

	float windowWidth = 256.f;
	float windowHeight = 224.f;
	Window window{ windowWidth, windowHeight };
	Renderer renderer{ window.GetPointerHandler() };

	if (Init() == false) { Shutdown(); }

	// Implement the main loop here

	Shutdown();

	std::cin.get();

    return 0;
}

bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		std::cout << "SDL initialization succeeded!";
	}


}

void Shutdown()
{
	SDL_Quit();
}