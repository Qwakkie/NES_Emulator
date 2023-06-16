#include "pch.h"
#include "PixelProcessingUnit.h"
#include "Cartridge.h"

PixelProcessingUnit::PixelProcessingUnit()
	:m_NameTable{}
	, m_Palette{}
	, m_PaletteTable{}
{
	m_Screen.resize(m_ScreenSize);

#pragma region palette
	m_Palette[0x00] = SDL_Color{ 84, 84, 84 };
	m_Palette[0x01] = SDL_Color{ 0, 30, 116 };
	m_Palette[0x02] = SDL_Color{ 8, 16, 144 };
	m_Palette[0x03] = SDL_Color{ 48, 0, 136 };
	m_Palette[0x04] = SDL_Color{ 68, 0, 100 };
	m_Palette[0x05] = SDL_Color{ 92, 0, 48 };
	m_Palette[0x06] = SDL_Color{ 84, 4, 0 };
	m_Palette[0x07] = SDL_Color{ 60, 24, 0 };
	m_Palette[0x08] = SDL_Color{ 32, 42, 0 };
	m_Palette[0x09] = SDL_Color{ 8, 58, 0 };
	m_Palette[0x0A] = SDL_Color{ 0, 64, 0 };
	m_Palette[0x0B] = SDL_Color{ 0, 60, 0 };
	m_Palette[0x0C] = SDL_Color{ 0, 50, 60 };
	m_Palette[0x0D] = SDL_Color{ 0, 0, 0 };
	m_Palette[0x0E] = SDL_Color{ 0, 0, 0 };
	m_Palette[0x0F] = SDL_Color{ 0, 0, 0 };
					  
	m_Palette[0x10] = SDL_Color{ 152, 150, 152 };
	m_Palette[0x11] = SDL_Color{ 8, 76, 196 };
	m_Palette[0x12] = SDL_Color{ 48, 50, 236 };
	m_Palette[0x13] = SDL_Color{ 92, 30, 228 };
	m_Palette[0x14] = SDL_Color{ 136, 20, 176 };
	m_Palette[0x15] = SDL_Color{ 160, 20, 100 };
	m_Palette[0x16] = SDL_Color{ 152, 34, 32 };
	m_Palette[0x17] = SDL_Color{ 120, 60, 0 };
	m_Palette[0x18] = SDL_Color{ 84, 90, 0 };
	m_Palette[0x19] = SDL_Color{ 40, 114, 0 };
	m_Palette[0x1A] = SDL_Color{ 8, 124, 0 };
	m_Palette[0x1B] = SDL_Color{ 0, 118, 40 };
	m_Palette[0x1C] = SDL_Color{ 0, 102, 120 };
	m_Palette[0x1D] = SDL_Color{ 0, 0, 0 };
	m_Palette[0x1E] = SDL_Color{ 0, 0, 0 };
	m_Palette[0x1F] = SDL_Color{ 0, 0, 0 };
					  
	m_Palette[0x20] = SDL_Color{ 236, 238, 236 };
	m_Palette[0x21] = SDL_Color{ 76, 154, 236 };
	m_Palette[0x22] = SDL_Color{ 120, 124, 236 };
	m_Palette[0x23] = SDL_Color{ 176, 98, 236 };
	m_Palette[0x24] = SDL_Color{ 228, 84, 236 };
	m_Palette[0x25] = SDL_Color{ 236, 88, 180 };
	m_Palette[0x26] = SDL_Color{ 236, 106, 100 };
	m_Palette[0x27] = SDL_Color{ 212, 136, 32 };
	m_Palette[0x28] = SDL_Color{ 160, 170, 0 };
	m_Palette[0x29] = SDL_Color{ 116, 196, 0 };
	m_Palette[0x2A] = SDL_Color{ 76, 208, 32 };
	m_Palette[0x2B] = SDL_Color{ 56, 204, 108 };
	m_Palette[0x2C] = SDL_Color{ 56, 180, 204 };
	m_Palette[0x2D] = SDL_Color{ 60, 60, 60 };
	m_Palette[0x2E] = SDL_Color{ 0, 0, 0 };
	m_Palette[0x2F] = SDL_Color{ 0, 0, 0 };
					  
	m_Palette[0x30] = SDL_Color{ 236, 238, 236 };
	m_Palette[0x31] = SDL_Color{ 168, 204, 236 };
	m_Palette[0x32] = SDL_Color{ 188, 188, 236 };
	m_Palette[0x33] = SDL_Color{ 212, 178, 236 };
	m_Palette[0x34] = SDL_Color{ 236, 174, 236 };
	m_Palette[0x35] = SDL_Color{ 236, 174, 212 };
	m_Palette[0x36] = SDL_Color{ 236, 180, 176 };
	m_Palette[0x37] = SDL_Color{ 228, 196, 144 };
	m_Palette[0x38] = SDL_Color{ 204, 210, 120 };
	m_Palette[0x39] = SDL_Color{ 180, 222, 120 };
	m_Palette[0x3A] = SDL_Color{ 168, 226, 144 };
	m_Palette[0x3B] = SDL_Color{ 152, 226, 180 };
	m_Palette[0x3C] = SDL_Color{ 160, 214, 228 };
	m_Palette[0x3D] = SDL_Color{ 160, 162, 160 };
	m_Palette[0x3E] = SDL_Color{ 0, 0, 0 };
	m_Palette[0x3F] = SDL_Color{ 0, 0, 0 };
#pragma endregion
}

uint8_t PixelProcessingUnit::CpuRead(uint16_t address, bool bReadOnly)
{
	(bReadOnly);
	uint8_t data{ 0x00 };

	switch (address)
	{
	case 0x0000: //Control
		break;
	case 0x0001: //Mask
		break;
	case 0x0002: //Status
		break;
	case 0x0003: //OAM Address
		break;
	case 0x0004: //OAM Data
		break;
	case 0x0005: //Scroll
		break;
	case 0x0006: //PPU Address
		break;
	case 0x0007: //PPU Data
		break;
	}

	return data;
}

void PixelProcessingUnit::CpuWrite(uint16_t address, uint8_t data)
{
	switch (address)
	{
	case 0x0000: //Control
		break;
	case 0x0001: //Mask
		break;
	case 0x0002: //Status
		break;
	case 0x0003: //OAM Address
		break;
	case 0x0004: //OAM Data
		break;
	case 0x0005: //Scroll
		break;
	case 0x0006: //PPU Address
		break;
	case 0x0007: //PPU Data
		break;
	}
}

uint8_t PixelProcessingUnit::PpuRead(uint16_t address, bool bReadOnly)
{
	(bReadOnly);
	uint8_t data{ 0x00 };
	address &= 0x3FFF;
	if (m_pCartridge->CpuWrite(address, data))
	{

	}

	return data;
}

void PixelProcessingUnit::PpuWrite(uint16_t address, uint8_t data)
{
	address &= 0x3FFF;

	if (m_pCartridge->CpuWrite(address, data))
	{

	}
}

void PixelProcessingUnit::ConnectCartridge(const std::shared_ptr<Cartridge>& pCartridge)
{
	m_pCartridge = pCartridge;
}

void PixelProcessingUnit::Clock()
{
	m_Screen[(uint64_t)m_Cycle % m_ScreenWidth + (uint64_t)m_Scanline % m_ScreenHeight * m_ScreenWidth] = m_Palette[(rand() % 2) ? 0x3F : 0x30];

	++m_Cycle;
	if (m_Cycle >= 341)
	{
		m_Cycle = 0;
		++m_Scanline;
		if (m_Scanline >= 261)
		{
			m_Scanline = (uint16_t)-1;
			m_FrameComplete = true;
		}
	}
}

std::vector<SDL_Color>& PixelProcessingUnit::GetScreen()
{
	return m_Screen;
}
