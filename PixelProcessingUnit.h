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
	//std::vector<SDL_Color>& GetPatternTable(uint8_t i, uint8_t palette);

	bool m_FrameComplete{ false };

private:
	SDL_Color GetColourFromPaletteRam(uint8_t palette, uint8_t pixel);

	std::shared_ptr<Cartridge> m_pCartridge;

	uint8_t m_NameTable[2][1024]{};
	uint8_t m_PatternTable[2][4096];
	uint8_t m_PaletteTable[32]{};	

	SDL_Color m_Palette[0x40]{};
	
	const int m_ScreenWidth{ 256 };
	const int m_ScreenHeight{ 240 };
	const int m_ScreenSize{ m_ScreenWidth * m_ScreenHeight };
	std::vector<SDL_Color> m_Screen;
	std::vector<std::vector<SDL_Color>> m_ColorPatternTables;

	uint16_t m_Scanline{};
	uint16_t m_Cycle{};

	union
	{
		struct
		{
			uint8_t unused : 5;
			uint8_t spriteOverflow : 1;
			uint8_t spriteZeroHit : 1;
			uint8_t verticalBlank : 1;
		};
		uint8_t reg;
	}status;

};

