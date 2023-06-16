#pragma once
#include "AppSettings.h"
#include "Bus.h"

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
	
	std::shared_ptr<Cartridge> m_pCartridge;
	Bus m_Nes;
	Window* m_pWindow;
	Renderer* m_pRenderer;
	bool m_bInitialized;
};

