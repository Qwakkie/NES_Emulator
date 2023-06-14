#pragma once
#include <cstdint>
#include <array>
#include "CentralProcessingUnit.h"

class Bus
{
public:
	void Write(uint16_t address, uint8_t data);
	uint8_t Read(uint16_t address, bool bReadOnly = false);

	Bus();
	~Bus();

	CentralProcessingUnit Cpu;

	//Fake RAM for testing purposes
	std::array<uint8_t, 64 * 1024> ram;
};

