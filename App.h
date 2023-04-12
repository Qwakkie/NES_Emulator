#pragma once
#include "Renderer.h"
#include "Window.h"
#include "AppSettings.h"

class App
{
public:
	App();
	App(AppSettings settings);
	~App();
	App(const App& other) = delete;
	App(App&& other) = delete;
	App operator=(const App& other) = delete;
	App operator=(App&& other) = delete;

	void Initialize();
	void Run();

	const AppSettings GetAppsettings() { return appSettings; };
	void SetAppSettings(AppSettings settings) { appSettings = settings; };
private:
	AppSettings appSettings;
	Window* m_pWindow;
	Renderer* m_pRenderer;
	bool m_bInitialized;
};

