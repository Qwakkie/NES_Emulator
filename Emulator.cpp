#include "pch.h"
#include "Emulator.h"

void Emulator::EmulateCycles(int amount)
{
	m_CycleCount += amount;
	m_CPU.StepTo(m_CycleCount);
	m_PPU.StepTo(m_CycleCount);
}

void Emulator::LoadRom(const char* data, int dataSize)
{
	ProcessHeader(data);
}

void Emulator::ProcessHeader(const char* header)
{
	int headerPointer{};
	//Bytes 0-3 should be 'NES' followed by MS-DOS end-of-file
	if (!(header[headerPointer++] == 'N' && header[headerPointer++] == 'E' && header[headerPointer++] == 'S' && header[headerPointer++] == 0x1a))
	{
		throw std::exception{ "The file is not compatible for NES" };
	}

	int PrgRomSize{ int(header[headerPointer++]) }; //in 16KB units
	int ChrRomSize{ int(header[headerPointer++]) }; //in 8KB units
	char flags6{ int(header[headerPointer++]) };
	//  76543210
	//	||||||||
	//	|||||||+-Mirroring: 0 : horizontal(vertical arrangement) (CIRAM A10 = PPU A11)
	//	|||||||              1 : vertical(horizontal arrangement) (CIRAM A10 = PPU A10)
	//	||||||+-- 1 : Cartridge contains battery - backed PRG RAM($6000 - 7FFF) or other persistent memory
	//	|||||+-- - 1 : 512 - byte trainer at $7000 - $71FF(stored before PRG data)
	//	||||+---- 1 : Ignore mirroring control or above mirroring bit; instead provide four - screen VRAM
	//	++++---- - Lower nybble of mapper number

	char flags7{ int(header[headerPointer++]) };
	//  76543210
	//	||||||||
	//	|||||||+-VS Unisystem
	//	||||||+--PlayChoice - 10 (8 KB of Hint Screen data stored after CHR data)
	//	||||++-- - If equal to 2, flags 8 - 15 are in NES 2.0 format
	//	++++---- - Upper nybble of mapper number
	char lowerNibble{ (flags6 & 0xf0) >> 4};
	char higherNibble{ flags7 & 0xf0 };
	char mapperNumber{ lowerNibble | (higherNibble) };

	char flags8{ int(header[headerPointer++]) }; //PRG RAM size in 8KB units
	char flags9{ int(header[headerPointer++]) };
	//  76543210
	//	||||||||
	//	|||||||+-TV system(0: NTSC; 1: PAL)
	//	++++++ + --Reserved, set to zero

	char flags10{ int(header[headerPointer++]) };
	//  76543210
	//	||  ||
	//	||  ++ - TV system(0: NTSC; 2: PAL; 1 / 3: dual compatible)
	//	| +---- - PRG RAM($6000 - $7FFF) (0: present; 1: not present)
	//	+ ------ 0: Board has no bus conflicts; 1: Board has bus conflicts

}
