#pragma once
#include <string>
#include "SDL.h"

class Window
{
public:
	Window(float width, float height, std::string title = "");
	~Window();
	Window(const Window& other) = delete;
	Window(Window&& other) = default;
	Window operator=(const Window& other) = delete;
	Window operator=(Window&& other) = delete;

	SDL_Window* GetPointerHandler() { return m_pWindow; };
private:
	SDL_Window* m_pWindow;

	std::string m_Title;
	float m_Width;
	float m_Height;
};

