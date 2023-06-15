#include "pch.h"
#include "Bus.h"

void Bus::CpuWrite(uint16_t address, uint8_t data)
{
	if (address >= 0x0000 && address <= 0x1FFF)
	{
		m_CpuRam[address & 0x07FF] = data;
	}
	else if (address >= 0x2000 && address <= 0x3FFF)
	{
		m_Ppu.CpuWrite(address & 0x0007, data);
	}
}

uint8_t Bus::CpuRead(uint16_t address, bool bReadOnly)
{
	uint8_t data{ 0x00 };
	if (address >= 0x0000 && address <= 0x1FFF)
	{
		data = m_CpuRam[address & 0x07FF];
	}
	else if (address >= 0x2000 && address <= 0x3FFF)
	{
		data = m_Ppu.CpuRead(address & 0x0007);
	}

	return data;
}

void Bus::InsertCartride(const Cartridge* cartridge)
{
}

void Bus::InsertCartride(const std::shared_ptr<Cartridge>& pCartridge)
{
	m_pCartridge = pCartridge;
	m_Ppu.ConnectCartridge(pCartridge);
}

void Bus::Reset()
{
	m_Cpu.Reset();
	m_SystemClockCounter = 0;
}

void Bus::Clock()
{
}

Bus::Bus()
{
	//Clear RAM contents
	for (auto& i : m_CpuRam) i = 0x00;

	//Connect CPU
	m_Cpu.ConnectBus(this);
}
