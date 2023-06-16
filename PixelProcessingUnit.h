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

private:
	std::shared_ptr<Cartridge> m_pCartridge;

	uint8_t m_NameTable[2][1024]{};
	uint8_t m_PaletteTable[32]{};

	SDL_Color m_Palette[0x40]{};
	static const int m_ScreenSize{ 256 * 240 };
	std::vector<SDL_Color> m_Screen;

	uint16_t m_Scanline{};
	uint16_t m_Cycle{};

	bool m_FrameComplete{ false };
};

