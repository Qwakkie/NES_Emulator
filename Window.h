#pragma once
#include <string>
#include "SDL.h"

class Window
{
public:
	Window(int width, int height, std::string title = "");
	~Window();
	Window(const Window& other) = delete;
	Window(Window&& other) = default;
	Window operator=(const Window& other) = delete;
	Window operator=(Window&& other) = delete;

	SDL_Window* GetPointerHandler() { return m_pWindow; };
private:
	SDL_Window* m_pWindow;

	std::string m_Title;
	int m_Width;
	int m_Height;
};

