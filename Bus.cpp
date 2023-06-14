#include "pch.h"
#include "Bus.h"

void Bus::Write(uint16_t address, uint8_t data)
{
	if (address >= 0x0000 && address <= 0xFFFF)
	{
		ram[address] = data;
	}
}

uint8_t Bus::Read(uint16_t address, bool bReadOnly)
{
	if (address >= 0x0000 && address <= 0xFFFF)
	{
		return ram[address];
	}
}

Bus::Bus()
{
	//Clear RAM contents
	for (auto& i : ram) i = 0x00;

	//Connect CPU
	Cpu.ConnectBus(this);
}
