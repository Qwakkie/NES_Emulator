#pragma once
#include "CentralProcessingUnit.h"
#include "PixelProcessingUnit.h"

class Emulator
{
public:
	void EmulateCycles(int amount);
	void LoadRom(const char* data, int dataSize);
private:
	void ProcessHeader(const char* header);

	CentralProcessingUnit m_CPU;
	PixelProcessingUnit m_PPU;
	unsigned int m_CycleCount;

	//----------------------------------------------------------------------+
	//MEMORY LAYOUT															|
	//----------------------------------------------------------------------+
	//$0000-$07FF: 2KB internal RAM											|
	//$0800-$0FFF															|
	//$1000-$17FF: Mirrors of $0000-$07FF									|
	//$1800-$1FFF															|
	//$2000-$2007:NES PPU registers											|
	//$2008-$3FFF: Mirrors of $2000-$2007 (repeating)						|
	//$4000-$4017: NES APU and I/O registers								|
	//$4018-$401F: APU and I/O functionality that is normally disabled		|
	//$4020-$FFFF: Cartridge space: PRG ROM, PRG RAM and mapper registers	|
	//$6000–$7FFF: Battery-backed save or work RAM							|
	//$8000–$FFFF: ROM and mapper registers									|
	//----------------------------------------------------------------------+
	static const int m_MemorySize{ 0xffff };
	//REGISTERS
	unsigned char m_Accumulator;
	unsigned char m_IndexX;
	unsigned char m_IndexY;
	unsigned char m_StackPointer;
	unsigned char m_StatusRegister;

	unsigned short m_ProgramCounter;
};

