#include "pch.h"
#include "PixelProcessingUnit.h"

uint8_t PixelProcessingUnit::CpuRead(uint16_t address, bool bReadOnly)
{
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
	uint8_t data{ 0x00 };
	address &= 0x3FFF;

	return data;
}

void PixelProcessingUnit::PpuWrite(uint16_t address, uint8_t data)
{
	address &= 0x3FFF;
}

void PixelProcessingUnit::ConnectCartridge(const std::shared_ptr<Cartridge>& pCartridge)
{
	m_pCartridge = pCartridge;
}
