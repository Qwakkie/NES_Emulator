#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <iostream>

#include "FileSelector.h"
#include "Window.h"
#include "Renderer.h"
#include "App.h"

void Shutdown();

#pragma warning (push)
#pragma warning (disable: 4100)
int main(int argc, char* argv[])
#pragma warning (pop)
{
    FileSelector fileSelector{};
    //bool result = fileSelector.OpenFile();

	App::GetAppSettings() = AppSettings{768, 640};
	App app{};
	app.Run();
    return 0;
}

void Shutdown()
{
	SDL_Quit();
}