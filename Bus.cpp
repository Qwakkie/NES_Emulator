#include "pch.h"
#include "Bus.h"

void Bus::CpuWrite(uint16_t address, uint8_t data)
{
	if (m_pCartridge->CpuWrite(address, data))
	{

	}
	else if (address >= 0x0000 && address <= 0x1FFF)
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
	(bReadOnly);
	uint8_t data{ 0x00 };
	if (m_pCartridge->CpuWrite(address, data))
	{

	}
	else if (address >= 0x0000 && address <= 0x1FFF)
	{
		data = m_CpuRam[address & 0x07FF];
	}
	else if (address >= 0x2000 && address <= 0x3FFF)
	{
		data = m_Ppu.CpuRead(address & 0x0007);
	}

	return data;
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
	m_Ppu.Clock();
	if (m_SystemClockCounter % 3 == 0)
	{
		m_Cpu.Clock();
	}
	++m_SystemClockCounter;
}

Bus::Bus()
	:m_CpuRam{}
{
	//Clear RAM contents
	for (auto& i : m_CpuRam) i = 0x00;

	//Connect CPU
	m_Cpu.ConnectBus(this);
}
