#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include <iostream>

#include "FileSelector.h"
#include "Window.h"
#include "Renderer.h"
#include "App.h"

void Shutdown();

int main(int argc, char* argv[])
{
    FileSelector fileSelector{};
    //bool result = fileSelector.OpenFile();

	int windowWidth = 256;
	int windowHeight = 224;
	App app{};
	app.Run();
    return 0;
}

void Shutdown()
{
	SDL_Quit();
}