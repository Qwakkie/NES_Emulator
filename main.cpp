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

	AppSettings settings{};
	settings.WindowHeight = 224;
	settings.WindowWidth = 256;
	App app{settings};
	app.Run();
    return 0;
}

void Shutdown()
{
	SDL_Quit();
}