#pragma once
class Mapper
{
public:
	Mapper(uint8_t programBanks, uint8_t characterBanks);

	virtual bool CpuMapRead(uint16_t address, uint32_t& mappedAddress) = 0;
	virtual bool CpuMapWrite(uint16_t address, uint32_t& mappedAddress) = 0;
	virtual bool PpuMapRead(uint16_t address, uint32_t& mappedAddress) = 0;
	virtual bool PpuMapWrite(uint16_t address, uint32_t& mappedAddress) = 0;
protected:
	uint8_t m_ProgramBanks{};
	uint8_t m_CharacterBanks{};
};

