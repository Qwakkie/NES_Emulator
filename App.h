#pragma once
#include "Renderer.h"
#include "Window.h"

class App
{
public:
	App();
	~App();
	App(const App& other) = delete;
	App(App&& other) = delete;
	App operator=(const App& other) = delete;
	App operator=(App&& other) = delete;

	void Initialize();
	void Run();
private:
	Window* m_pWindow;
	Renderer* m_pRenderer;
	bool m_bInitialized;
};

