#include "Window.h"
#include <iostream>

Window::Window(int width, int height, std::string title)
	:m_Title{ title }
	, m_Width{ width }
	, m_Height{height}
{
	m_pWindow = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_OPENGL
	);

	if (m_pWindow == nullptr) {
		std::cout << "Unable to create the main window. Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		//return EXIT_FAILURE;
	}
}

Window::~Window()
{
	SDL_DestroyWindow(m_pWindow);
}
