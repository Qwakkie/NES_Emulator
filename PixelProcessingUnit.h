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
	std::vector<SDL_Color>& GetNameTable(uint8_t i);
	std::vector<SDL_Color>& GetPatternTable(uint8_t i, uint8_t palette);

	bool m_FrameComplete{ false };
	bool m_Nmi{ false };

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
	std::vector<SDL_Color> m_Nametable1;
	std::vector<SDL_Color> m_Nametable2;
	std::vector<std::vector<SDL_Color>> m_ColorPatternTables;

	uint16_t m_Scanline{};
	uint16_t m_Cycle{};

#pragma warning (push)
#pragma warning (disable:4201)
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

	union
	{
		struct
		{
			uint8_t grayscale : 1;
			uint8_t renderBackgroundLeft : 1;
			uint8_t renderSpritesLeft : 1;
			uint8_t renderBackground : 1;
			uint8_t renderSprites : 1;
			uint8_t enhanceRed : 1;
			uint8_t enhanceGreen : 1;
			uint8_t enhanceBlue : 1;
		};
		uint8_t reg;
	}mask;

	union PpuControl
	{
		struct
		{
			uint8_t nametableX : 1;
			uint8_t nametableY : 1;
			uint8_t incrementMode : 1;
			uint8_t patternSprite : 1;
			uint8_t patternBackground : 1;
			uint8_t spriteSize : 1;
			uint8_t slaveMode : 1; //unused
			uint8_t enableNmi : 1;
		};
		uint8_t reg;
	}control;
#pragma warning (pop)

	uint8_t addressLatch{ 0x00 };
	uint8_t ppuDataBuffer{ 0x00 };
	
	union LoopyRegister
	{
		struct
		{
			uint16_t coarseX : 5;
			uint16_t coarseY : 5;
			uint16_t nametableX : 1;
			uint16_t nametableY : 1;
			uint16_t fineY : 3;
			uint16_t unused : 1;
		};

		uint16_t reg{ 0x0000 };
	};

	LoopyRegister vRamAddress;
	LoopyRegister tRamAddress;

	uint8_t fineX{ 0x00 };

	uint8_t bgNextTileId{};
	uint8_t bgNextTileAttribute{};
	uint8_t bgNextTileLsb{};
	uint8_t bgNextTileMsb{};

	uint16_t bgShifterPatternLow{};
	uint16_t bgShifterPatternHigh{};
	uint16_t bgShifterAttributeLow{};
	uint16_t bgShifterAttributeHigh{};
};

