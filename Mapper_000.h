#pragma once
#include "Mapper.h"
class Mapper_000 : public Mapper
{
public:
	Mapper_000(uint8_t programBanks, uint8_t characterBanks);
	// Inherited via Mapper
	virtual bool CpuMapRead(uint16_t address, uint32_t& mappedAddress) override;
	virtual bool CpuMapWrite(uint16_t address, uint32_t& mappedAddress) override;
	virtual bool PpuMapRead(uint16_t address, uint32_t& mappedAddress) override;
	virtual bool PpuMapWrite(uint16_t address, uint32_t& mappedAddress) override;
};

