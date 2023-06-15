#pragma once
#include <cstdint>
#include <array>
#include <memory>
#include "CentralProcessingUnit.h"
#include "PixelProcessingUnit.h"
#include "Cartridge.h"


class Bus
{
public:
	void CpuWrite(uint16_t address, uint8_t data);
	uint8_t CpuRead(uint16_t address, bool bReadOnly = false);

	void InsertCartride(const std::shared_ptr<Cartridge>& pCartridge);
	void Reset();
	void Clock();

	Bus();
	~Bus() = default;

	CentralProcessingUnit m_Cpu;
	PixelProcessingUnit m_Ppu;
	std::shared_ptr<Cartridge> m_pCartridge;

	//Fake RAM for testing purposes
	std::array<uint8_t, 2048> m_CpuRam;

private:
	uint32_t m_SystemClockCounter{};
};

