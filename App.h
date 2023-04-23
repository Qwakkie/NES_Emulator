#pragma once
#include "AppSettings.h"

class Renderer;
class Window;

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

	static AppSettings& GetAppSettings();
private:
	static AppSettings m_AppSettings;
	
	Window* m_pWindow;
	Renderer* m_pRenderer;
	bool m_bInitialized;
};

