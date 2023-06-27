#include "pch.h"
#include "Cartridge.h"
#include "FileSelector.h"
#include <fstream>
#include "Mapper_000.h"

Cartridge::Cartridge()
{
	struct Header
	{
		char name[4];
		uint8_t programRomSize;
		uint8_t characterRomSize;
		uint8_t mapper1;
		uint8_t mapper2;
		uint8_t programRamSize;
		uint8_t tvSystem1;
		uint8_t tvSystem2;
		char unused[5];
	}header;

	FileSelector selector{};
	selector.SelectFile();

	std::ifstream input;
	input.open(selector.GetFilePath(), std::ifstream::binary);
	if (input.is_open())
	{
		input.read((char*)&header, sizeof(Header));

		if (header.mapper1 & 0x04)
		{
			input.seekg(512, std::ios_base::cur);
		}

		m_MapperId = (header.mapper2 & 0xF0) | (header.mapper1 >> 4);
		mirror = (header.mapper1 & 0x01) ? VERTICAL : HORIZONTAL;

		uint8_t fileType = 1;

		if (fileType == 0)
		{

		}
		else if (fileType == 1)
		{
			m_ProgramBanks = header.programRomSize;
			m_ProgramMemory.resize((uint64_t)m_ProgramBanks * 16384);
			input.read((char*)m_ProgramMemory.data(), m_ProgramMemory.size());

			m_CharacterBanks = header.characterRomSize;
			m_CharacterMemory.resize((uint64_t)m_CharacterBanks * 8192);
			input.read((char*)m_CharacterMemory.data(), m_CharacterMemory.size());
		}
		else if (fileType == 2)
		{

		}

		switch (m_MapperId)
		{
		case 0:
			m_pMapper = std::make_shared<Mapper_000>(m_ProgramBanks, m_CharacterBanks);
			break;
		}

		input.close();

	}
}

bool Cartridge::CpuRead(uint16_t address, uint8_t& data)
{
	uint32_t mappedAddress{};
	if (m_pMapper->CpuMapRead(address, mappedAddress))
	{
		data = m_ProgramMemory[mappedAddress];
		return true;
	}
	return false;
}

bool Cartridge::CpuWrite(uint16_t address, uint8_t data)
{
	uint32_t mappedAddress{};
	if (m_pMapper->CpuMapWrite(address, mappedAddress))
	{
		m_ProgramMemory[mappedAddress] = data;
		return true;
	}
	return false;
}

bool Cartridge::PpuRead(uint16_t address, uint8_t& data)
{
	uint32_t mappedAddress{};
	if (m_pMapper->PpuMapRead(address, mappedAddress))
	{
		data = m_CharacterMemory[mappedAddress];
		return true;
	}
	return false;
}

bool Cartridge::PpuWrite(uint16_t address, uint8_t data)
{
	uint32_t mappedAddress{};
	if (m_pMapper->PpuMapWrite(address, mappedAddress))
	{
		m_CharacterMemory[mappedAddress] = data;
		return true;
	}
	return false;
}
