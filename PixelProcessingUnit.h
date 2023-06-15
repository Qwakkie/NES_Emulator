#pragma once
#include <memory>

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

private:
	uint8_t m_NameTable[2][1024];
	uint8_t m_PaletteTable[32];

	std::shared_ptr<Cartridge> m_pCartridge;
};

