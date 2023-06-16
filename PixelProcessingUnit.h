#pragma once
#include <memory>
#include <vector>

class Cartridge;

class PixelProcessingUnit
{
public:
	PixelProcessingUnit();
	~PixelProcessingUnit() = default;

	//Communication with Main Bus
	uint8_t CpuRead(uint16_t address, bool bReadOnly = false);
	void CpuWrite(uint16_t address, uint8_t data);

	//Communication with Ppu Bus
	uint8_t PpuRead(uint16_t address, bool bReadOnly = false);
	void PpuWrite(uint16_t address, uint8_t data);

	void ConnectCartridge(const std::shared_ptr<Cartridge>& pCartridge);
	void Clock();

	std::vector<SDL_Color>& GetScreen();

	bool m_FrameComplete{ false };

private:
	std::shared_ptr<Cartridge> m_pCartridge;

	uint8_t m_NameTable[2][1024]{};
	uint8_t m_PaletteTable[32]{};

	SDL_Color m_Palette[0x40]{};
	
	const int m_ScreenWidth{ 256 };
	const int m_ScreenHeight{ 240 };
	const int m_ScreenSize{ m_ScreenWidth * m_ScreenHeight };
	std::vector<SDL_Color> m_Screen;

	uint16_t m_Scanline{};
	uint16_t m_Cycle{};

};

