#pragma once
#include <vector>
#include <memory>

class Mapper;

class Cartridge
{
public:
	Cartridge();
	~Cartridge() = default;

	enum MIRROR
	{
		HORIZONTAL,
		VERTICAL,
		ONESCREEN_LO,
		ONESCREEN_HI,
	} mirror = HORIZONTAL;

	bool CpuRead(uint16_t address, uint8_t& data);
	bool CpuWrite(uint16_t address, uint8_t data);

	//Communication with Ppu Bus
	bool PpuRead(uint16_t address, uint8_t& data);
	bool PpuWrite(uint16_t address, uint8_t data);

private:
	std::vector<uint8_t> m_ProgramMemory;
	std::vector<uint8_t> m_CharacterMemory;

	std::shared_ptr<Mapper> m_pMapper;

	uint8_t m_MapperId{};
	uint8_t m_ProgramBanks{};
	uint8_t m_CharacterBanks{};
};

