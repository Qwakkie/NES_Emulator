#include "pch.h"
#include "PixelProcessingUnit.h"
#include "Cartridge.h"

PixelProcessingUnit::PixelProcessingUnit()
	:m_NameTable{}
	, m_Palette{}
	, m_PaletteTable{}
{
	m_Screen.resize(m_ScreenSize);

	m_ColorPatternTables.push_back(Sprite(128, 128));
	m_ColorPatternTables.push_back(Sprite(128, 128));

	m_Nametable1.resize(256 * 240);
	m_Nametable2.resize(256 * 240);

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
		data = (status.reg & 0xE0) | (ppuDataBuffer & 0x1F0);
		status.verticalBlank = 0;
		addressLatch = 0;
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
		data = ppuDataBuffer;
		ppuDataBuffer = PpuRead(vRamAddress.reg);
		if (vRamAddress.reg > 0x3F00)
		{
			data = ppuDataBuffer;
		}
		vRamAddress.reg += (control.incrementMode ? 32 : 1);
		break;
	}

	return data;
}

void PixelProcessingUnit::CpuWrite(uint16_t address, uint8_t data)
{
	switch (address)
	{
	case 0x0000: //Control
		control.reg = data;
		tRamAddress.nametableX = control.nametableX;
		tRamAddress.nametableY = control.nametableY;
		break;
	case 0x0001: //Mask
		mask.reg = data;
		break;
	case 0x0002: //Status
		break;
	case 0x0003: //OAM Address
		break;
	case 0x0004: //OAM Data
		break;
	case 0x0005: //Scroll
		if (addressLatch == 0)
		{
			fineX = data & 0x07;
			tRamAddress.coarseX = data >> 3;
			addressLatch = 1;
		}
		else
		{
			tRamAddress.fineY = data & 0x07;
			tRamAddress.coarseY = data >> 3;
			addressLatch = 0;
		}
		break;
	case 0x0006: //PPU Address
		if (addressLatch == 0x00)
		{
			tRamAddress.reg = (uint16_t)((data & 0x3F) << 8) | (tRamAddress.reg & 0x00FF);
			addressLatch = 1;
		}
		else
		{
			tRamAddress.reg = (tRamAddress.reg & 0xFF00) | data;
			vRamAddress = tRamAddress;
			addressLatch = 0;
		}
		break;
	case 0x0007: //PPU Data
		PpuWrite(vRamAddress.reg, data);
		vRamAddress.reg += (control.incrementMode ? 32 : 1);
		break;
	}
}

uint8_t PixelProcessingUnit::PpuRead(uint16_t address, bool bReadOnly)
{
	(bReadOnly);
	uint8_t data{ 0x00 };
	address &= 0x3FFF;
	if (m_pCartridge->PpuRead(address, data))
	{

	}
	else if (address >= 0x000 && address <= 0x1FFF)
	{
		data = m_PatternTable[(address & 0x1000) >> 12][address & 0x0FFF];
	}
	else if (address >= 0x2000 && address <= 0x3EFF)
	{
		address &= 0x0FFF;
		if (m_pCartridge->mirror == Cartridge::MIRROR::VERTICAL)
		{
			if (address >= 0x000 && address <= 0x03FF)
			{
				data = m_NameTable[0][address & 0x03FF];
			}
			else if (address >= 0x0400 && address <= 0x07FF)
			{
				data = m_NameTable[1][address & 0x03FF];
			}
			else if (address >= 0x0800 && address <= 0x0BFF)
			{
				data = m_NameTable[0][address & 0x03FF];
			}
			else if (address >= 0x0C00 && address <= 0x0FFF)
			{
				data = m_NameTable[1][address & 0x03FF];
			}
		}
		else if (m_pCartridge->mirror == Cartridge::MIRROR::HORIZONTAL)
		{
			if (address >= 0x000 && address <= 0x03FF)
			{
				data = m_NameTable[0][address & 0x03FF];
			}
			else if (address >= 0x0400 && address <= 0x07FF)
			{
				data = m_NameTable[0][address & 0x03FF];
			}
			else if (address >= 0x0800 && address <= 0x0BFF)
			{
				data = m_NameTable[1][address & 0x03FF];
			}
			else if (address >= 0x0C00 && address <= 0x0FFF)
			{
				data = m_NameTable[1][address & 0x03FF];
			}
		}
	}
	else if (address >= 0x3F00 && address <= 0x3FFF)
	{
		address &= 0x001F;
		switch (address)
		{
		case 0x0010:
		case 0x0014:
		case 0x0018:
		case 0x001C:
			address &= 0x000F;
		}
		data = m_PaletteTable[address] & (mask.grayscale ? 0x30 : 0x3F);
	}

	return data;
}

void PixelProcessingUnit::PpuWrite(uint16_t address, uint8_t data)
{
	address &= 0x3FFF;

	if (m_pCartridge->PpuWrite(address, data))
	{

	}
	else if (address >= 0x0000 && address <= 0x1FFF)
	{
		m_PatternTable[(address & 0x1000) >> 12][address & 0x0FFF] = data;
	}
	else if (address >= 0x2000 && address <= 0x3EFF)
	{
		address &= 0x0FFF;
		if (m_pCartridge->mirror == Cartridge::MIRROR::VERTICAL)
		{
			if (address >= 0x000 && address <= 0x03FF)
			{
				m_NameTable[0][address & 0x03FF] = data;
			}
			else if (address >= 0x0400 && address <= 0x07FF)
			{
				m_NameTable[1][address & 0x03FF] = data;
			}
			else if (address >= 0x0800 && address <= 0x0BFF)
			{
				m_NameTable[0][address & 0x03FF] = data;
			}
			else if (address >= 0x0C00 && address <= 0x0FFF)
			{
				m_NameTable[1][address & 0x03FF] = data;
			}
		}
		else if (m_pCartridge->mirror == Cartridge::MIRROR::HORIZONTAL)
		{
			if (address >= 0x000 && address <= 0x03FF)
			{
				m_NameTable[0][address & 0x03FF] = data;
			}
			else if (address >= 0x0400 && address <= 0x07FF)
			{
				m_NameTable[0][address & 0x03FF] = data;
			}
			else if (address >= 0x0800 && address <= 0x0BFF)
			{
				m_NameTable[1][address & 0x03FF] = data;
			}
			else if (address >= 0x0C00 && address <= 0x0FFF)
			{
				m_NameTable[1][address & 0x03FF] = data;
			}
		}
	}
	else if (address >= 0x3F00 && address <= 0x3FFF)
	{
		address &= 0x001F;
		switch (address)
		{
		case 0x0010:
		case 0x0014:
		case 0x0018:
		case 0x001C:
			address &= 0x000F;
		}
		m_PaletteTable[address] = data;
	}
}

void PixelProcessingUnit::ConnectCartridge(const std::shared_ptr<Cartridge>& pCartridge)
{
	m_pCartridge = pCartridge;
}

void PixelProcessingUnit::Clock()	
{
	auto IncrementScrollX = [&]()
	{
		if (mask.renderBackground || mask.renderSprites)
		{
			if (vRamAddress.coarseX == 31)
			{
				vRamAddress.coarseX = 0;
				vRamAddress.nametableX = ~vRamAddress.nametableX;
			}
			else
			{
				++(vRamAddress.coarseX);
			}
		}
	};

	auto IncrementScrollY = [&]()
	{
		if (mask.renderBackground || mask.renderSprites)
		{
			if (vRamAddress.fineY < 7)
			{
				++(vRamAddress.fineY);
			}
			else
			{
				vRamAddress.fineY = 0;
				if (vRamAddress.coarseY == 29)
				{
					vRamAddress.coarseY = 0;
					vRamAddress.nametableY = ~vRamAddress.nametableY;
				}
				else if (vRamAddress.coarseY == 31)
				{
					vRamAddress.coarseY = 0;
				}
				else
				{
					++(vRamAddress.coarseY);
				}
			}
		}
	};

	auto TransferAddressX = [&]()
	{
		if (mask.renderBackground || mask.renderSprites)
		{
			vRamAddress.nametableX = tRamAddress.nametableX;
			vRamAddress.coarseX = tRamAddress.coarseX;
		}
	};

	auto TransferAddressY = [&]()
	{
		if (mask.renderBackground || mask.renderSprites)
		{
			vRamAddress.fineY = tRamAddress.fineY;
			vRamAddress.nametableY = tRamAddress.nametableY;
			vRamAddress.coarseY = tRamAddress.coarseY;
		}
	};

	auto LoadBackgroundShifters = [&]()
	{
		bgShifterPatternLow = (bgShifterPatternLow & 0xFF00) | bgNextTileLsb;
		bgShifterPatternHigh = (bgShifterPatternHigh & 0xFF00) | bgNextTileMsb;
		bgShifterAttributeLow = (bgShifterAttributeLow & 0xFF00) | ((bgNextTileAttribute & 0b01) ? 0xFF : 0x00);
		bgShifterAttributeHigh = (bgShifterAttributeHigh & 0xFF00) | ((bgNextTileAttribute & 0b10) ? 0xFF : 0x00);
	};

	auto UpdateShifters = [&]()
	{
		if (mask.renderBackground)
		{
			bgShifterPatternLow <<= 1;
			bgShifterPatternHigh <<= 1;
			bgShifterAttributeLow <<= 1;
			bgShifterAttributeHigh <<= 1;
		}
	};

	if (m_Scanline >= -1 && m_Scanline < 240)
	{
		if (m_Scanline == 0 && m_Cycle == 0)
		{
			// "Odd Frame" cycle skip
			m_Cycle = 1;
		}
		if (m_Scanline == -1 && m_Cycle == 1)
		{
			status.verticalBlank = 0;
		}

		if ((m_Cycle >= 2 && m_Cycle < 258) || (m_Cycle >= 321 && m_Cycle < 338))
		{
			UpdateShifters();
			switch ((m_Cycle - 1) % 8)
			{
			case 0:
				LoadBackgroundShifters();
				bgNextTileId = PpuRead(0x2000 | (vRamAddress.reg & 0x0FFF));
				break;
			case 2:
				bgNextTileAttribute = PpuRead(0x23C0 | (vRamAddress.nametableY << 11)
					| (vRamAddress.nametableX << 10)
					| ((vRamAddress.coarseY >> 2) << 3)
					| (vRamAddress.coarseX >> 2));
				if (vRamAddress.coarseY & 0x02)
				{
					bgNextTileAttribute >>= 4;
				}
				if (vRamAddress.coarseX & 0x02)
				{
					bgNextTileAttribute >>= 2;
				}
				bgNextTileAttribute &= 0x03;
				break;
			case 4:
				bgNextTileLsb = PpuRead((control.patternBackground << 12) + ((uint16_t)bgNextTileId << 4) + vRamAddress.fineY);
			case 6:
				bgNextTileLsb = PpuRead((control.patternBackground << 12) + ((uint16_t)bgNextTileId << 4) + vRamAddress.fineY + 8);
			case 7:
				IncrementScrollX();
				break;
			}
		}
		if (m_Cycle == 256)
		{
			IncrementScrollY();
		}

		if (m_Cycle == 257)
		{
			LoadBackgroundShifters();
			TransferAddressX();
		}

		if (m_Cycle == 338 || m_Cycle == 340)
		{
			bgNextTileId = PpuRead(0x2000 | (vRamAddress.reg & 0x0FFF));
		}

		if (m_Scanline == -1 && m_Cycle >= 280 && m_Cycle < 305)
		{
			TransferAddressY();
		}
	}

	//At scanline 240 nothing happens

	if (m_Scanline == 241 && m_Cycle == 1)
	{
		status.verticalBlank = 1;
		if (control.enableNmi)
		{
			m_Nmi = true;
		}
	}

	uint8_t bgPixel{};
	uint8_t bgPalette{};

	if (mask.renderBackground)
	{
		uint16_t bitMask{ (uint16_t)(0x8000 >> fineX) };

		uint8_t p0Pixel{ (bgShifterPatternLow & bitMask) > 0 };
		uint8_t p1Pixel{ (bgShifterPatternHigh & bitMask) > 0 };
		bgPixel = (p1Pixel << 1) | p0Pixel;

		uint8_t p0Palette{ (bgShifterAttributeLow & bitMask) > 0 };
		uint8_t p1Palette{ (bgShifterAttributeHigh & bitMask) > 0 };
		bgPalette = (p1Palette << 1) | p0Palette;
	}
	unsigned int pixelIndex{ (unsigned int)((m_Cycle - 1) + m_Scanline * 128) };
	if (m_Screen.size() > pixelIndex)
	{
		m_Screen[pixelIndex] = GetColourFromPaletteRam(bgPalette, bgPixel);
	}

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

std::vector<SDL_Color>& PixelProcessingUnit::GetNameTable(uint8_t i)
{
	return m_Nametable1;
}

const Sprite& PixelProcessingUnit::GetPatternTable(uint8_t i, uint8_t palette)
{
	int maxIndex{};
	for (uint16_t tileY{}; tileY < 16; ++tileY)
	{
		for (uint16_t tileX{}; tileX < 16; ++tileX)
		{
			uint16_t offset{ static_cast<uint16_t>(tileY * 256 + tileX * 16) };
			for (uint16_t row{}; row < 8; ++row)
			{
				uint8_t tileLowerBit{ PpuRead(i * 0x1000 + offset + row) };
				uint8_t tileHigherBit{ PpuRead(i * 0x1000 + offset + row + 8) };

				for (uint16_t column{}; column < 8; ++column)
				{
					uint8_t pixel = { static_cast<uint8_t>((tileLowerBit & 0x01) + (tileHigherBit & 0x01)) };
					tileLowerBit >>= 1;
					tileHigherBit >>= 1;
					SDL_Color colour = GetColourFromPaletteRam(palette, pixel);
					int tableX{ tileX * 8 + (7 - column) };
					int tableY{ tileY * 8 + row };
					int index{ tableX + tableY * 128 };
					m_ColorPatternTables[i].SetPixel(tableX, tableY, colour);
					if (index > maxIndex)
					{
						maxIndex = index;
					}
				}
			}
		}
	}
	return m_ColorPatternTables[i];
}

SDL_Color PixelProcessingUnit::GetColourFromPaletteRam(uint8_t palette, uint8_t pixel)
{
	return m_Palette[PpuRead(0x3F00 + (palette << 2) + pixel)];
}
