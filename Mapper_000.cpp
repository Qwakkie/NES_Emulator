#include "pch.h"
#include "Mapper_000.h"

Mapper_000::Mapper_000(uint8_t programBanks, uint8_t characterBanks)
    :Mapper(programBanks, characterBanks)
{
}


bool Mapper_000::CpuMapRead(uint16_t address, uint32_t& mappedAddress)
{
    if (address >= 0x8000 && address <= 0xFFFF)
    {
        mappedAddress = address & (m_ProgramBanks > 1 ? 0x7FFF : 0x3FFF);
        return true;
    }
    return false;
}

bool Mapper_000::CpuMapWrite(uint16_t address, uint32_t& mappedAddress)
{
    if (address >= 0x8000 && address <= 0xFFFF)
    {
        mappedAddress = address & (m_ProgramBanks > 1 ? 0x7FFF : 0x3FFF);
        return true;
    }
    return false;
}

bool Mapper_000::PpuMapRead(uint16_t address, uint32_t& mappedAddress)
{
    if (address >= 0x0000 && address <= 0x1FFF)
    {
        mappedAddress = address;
        return true;
    }
    return false;
}

bool Mapper_000::PpuMapWrite(uint16_t address, uint32_t& mappedAddress)
{
    if (address >= 0x0000 && address <= 0x1FFF)
    {
        if (m_CharacterBanks == 0)
        {
            // Treat as RAM
            mappedAddress = address;
            return true;
        }
    }

    return false;
}
