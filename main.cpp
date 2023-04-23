#include <iostream>
#include <Windows.h>
#include <SDL.h>
#include "pch.h"
#include <iostream>

#include "FileSelector.h"
#include "Window.h"
#include "Renderer.h"
#include "App.h"

void Shutdown();

int main()
{
    FileSelector fileSelector{};
    //bool result = fileSelector.OpenFile();

	App::GetAppSettings() = AppSettings{224, 256};
	App app{};
	app.Run();
    return 0;
}

void Shutdown()
{
	SDL_Quit();
}