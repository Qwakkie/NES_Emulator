#include "pch.h"
#include "Mapper.h"

Mapper::Mapper(uint8_t programBanks, uint8_t characterBanks)
	:m_ProgramBanks{ programBanks }
	,m_CharacterBanks{characterBanks}
{
}
