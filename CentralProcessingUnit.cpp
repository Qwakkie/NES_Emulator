#include "pch.h"
#include "CentralProcessingUnit.h"
#include "Bus.h"

CentralProcessingUnit::CentralProcessingUnit()
{
	using c = CentralProcessingUnit;
	m_Lookup =
	{
		{ "BRK", &c::BRK, &c::IMM, 7 },{ "ORA", &c::ORA, &c::IZX, 6 },{ "???", &c::XXX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 8 },{ "???", &c::NOP, &c::IMP, 3 },{ "ORA", &c::ORA, &c::ZP0, 3 },{ "ASL", &c::ASL, &c::ZP0, 5 },{ "???", &c::XXX, &c::IMP, 5 },{ "PHP", &c::PHP, &c::IMP, 3 },{ "ORA", &c::ORA, &c::IMM, 2 },{ "ASL", &c::ASL, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 2 },{ "???", &c::NOP, &c::IMP, 4 },{ "ORA", &c::ORA, &c::ABS, 4 },{ "ASL", &c::ASL, &c::ABS, 6 },{ "???", &c::XXX, &c::IMP, 6 },
		{ "BPL", &c::BPL, &c::REL, 2 },{ "ORA", &c::ORA, &c::IZY, 5 },{ "???", &c::XXX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 8 },{ "???", &c::NOP, &c::IMP, 4 },{ "ORA", &c::ORA, &c::ZPX, 4 },{ "ASL", &c::ASL, &c::ZPX, 6 },{ "???", &c::XXX, &c::IMP, 6 },{ "CLC", &c::CLC, &c::IMP, 2 },{ "ORA", &c::ORA, &c::ABY, 4 },{ "???", &c::NOP, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 7 },{ "???", &c::NOP, &c::IMP, 4 },{ "ORA", &c::ORA, &c::ABX, 4 },{ "ASL", &c::ASL, &c::ABX, 7 },{ "???", &c::XXX, &c::IMP, 7 },
		{ "JSR", &c::JSR, &c::ABS, 6 },{ "AND", &c::AND, &c::IZX, 6 },{ "???", &c::XXX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 8 },{ "BIT", &c::BIT, &c::ZP0, 3 },{ "AND", &c::AND, &c::ZP0, 3 },{ "ROL", &c::ROL, &c::ZP0, 5 },{ "???", &c::XXX, &c::IMP, 5 },{ "PLP", &c::PLP, &c::IMP, 4 },{ "AND", &c::AND, &c::IMM, 2 },{ "ROL", &c::ROL, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 2 },{ "BIT", &c::BIT, &c::ABS, 4 },{ "AND", &c::AND, &c::ABS, 4 },{ "ROL", &c::ROL, &c::ABS, 6 },{ "???", &c::XXX, &c::IMP, 6 },
		{ "BMI", &c::BMI, &c::REL, 2 },{ "AND", &c::AND, &c::IZY, 5 },{ "???", &c::XXX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 8 },{ "???", &c::NOP, &c::IMP, 4 },{ "AND", &c::AND, &c::ZPX, 4 },{ "ROL", &c::ROL, &c::ZPX, 6 },{ "???", &c::XXX, &c::IMP, 6 },{ "SEC", &c::SEC, &c::IMP, 2 },{ "AND", &c::AND, &c::ABY, 4 },{ "???", &c::NOP, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 7 },{ "???", &c::NOP, &c::IMP, 4 },{ "AND", &c::AND, &c::ABX, 4 },{ "ROL", &c::ROL, &c::ABX, 7 },{ "???", &c::XXX, &c::IMP, 7 },
		{ "RTI", &c::RTI, &c::IMP, 6 },{ "EOR", &c::EOR, &c::IZX, 6 },{ "???", &c::XXX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 8 },{ "???", &c::NOP, &c::IMP, 3 },{ "EOR", &c::EOR, &c::ZP0, 3 },{ "LSR", &c::LSR, &c::ZP0, 5 },{ "???", &c::XXX, &c::IMP, 5 },{ "PHA", &c::PHA, &c::IMP, 3 },{ "EOR", &c::EOR, &c::IMM, 2 },{ "LSR", &c::LSR, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 2 },{ "JMP", &c::JMP, &c::ABS, 3 },{ "EOR", &c::EOR, &c::ABS, 4 },{ "LSR", &c::LSR, &c::ABS, 6 },{ "???", &c::XXX, &c::IMP, 6 },
		{ "BVC", &c::BVC, &c::REL, 2 },{ "EOR", &c::EOR, &c::IZY, 5 },{ "???", &c::XXX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 8 },{ "???", &c::NOP, &c::IMP, 4 },{ "EOR", &c::EOR, &c::ZPX, 4 },{ "LSR", &c::LSR, &c::ZPX, 6 },{ "???", &c::XXX, &c::IMP, 6 },{ "CLI", &c::CLI, &c::IMP, 2 },{ "EOR", &c::EOR, &c::ABY, 4 },{ "???", &c::NOP, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 7 },{ "???", &c::NOP, &c::IMP, 4 },{ "EOR", &c::EOR, &c::ABX, 4 },{ "LSR", &c::LSR, &c::ABX, 7 },{ "???", &c::XXX, &c::IMP, 7 },
		{ "RTS", &c::RTS, &c::IMP, 6 },{ "ADC", &c::ADC, &c::IZX, 6 },{ "???", &c::XXX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 8 },{ "???", &c::NOP, &c::IMP, 3 },{ "ADC", &c::ADC, &c::ZP0, 3 },{ "ROR", &c::ROR, &c::ZP0, 5 },{ "???", &c::XXX, &c::IMP, 5 },{ "PLA", &c::PLA, &c::IMP, 4 },{ "ADC", &c::ADC, &c::IMM, 2 },{ "ROR", &c::ROR, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 2 },{ "JMP", &c::JMP, &c::IND, 5 },{ "ADC", &c::ADC, &c::ABS, 4 },{ "ROR", &c::ROR, &c::ABS, 6 },{ "???", &c::XXX, &c::IMP, 6 },
		{ "BVS", &c::BVS, &c::REL, 2 },{ "ADC", &c::ADC, &c::IZY, 5 },{ "???", &c::XXX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 8 },{ "???", &c::NOP, &c::IMP, 4 },{ "ADC", &c::ADC, &c::ZPX, 4 },{ "ROR", &c::ROR, &c::ZPX, 6 },{ "???", &c::XXX, &c::IMP, 6 },{ "SEI", &c::SEI, &c::IMP, 2 },{ "ADC", &c::ADC, &c::ABY, 4 },{ "???", &c::NOP, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 7 },{ "???", &c::NOP, &c::IMP, 4 },{ "ADC", &c::ADC, &c::ABX, 4 },{ "ROR", &c::ROR, &c::ABX, 7 },{ "???", &c::XXX, &c::IMP, 7 },
		{ "???", &c::NOP, &c::IMP, 2 },{ "STA", &c::STA, &c::IZX, 6 },{ "???", &c::NOP, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 6 },{ "STY", &c::STY, &c::ZP0, 3 },{ "STA", &c::STA, &c::ZP0, 3 },{ "STX", &c::STX, &c::ZP0, 3 },{ "???", &c::XXX, &c::IMP, 3 },{ "DEY", &c::DEY, &c::IMP, 2 },{ "???", &c::NOP, &c::IMP, 2 },{ "TXA", &c::TXA, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 2 },{ "STY", &c::STY, &c::ABS, 4 },{ "STA", &c::STA, &c::ABS, 4 },{ "STX", &c::STX, &c::ABS, 4 },{ "???", &c::XXX, &c::IMP, 4 },
		{ "BCC", &c::BCC, &c::REL, 2 },{ "STA", &c::STA, &c::IZY, 6 },{ "???", &c::XXX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 6 },{ "STY", &c::STY, &c::ZPX, 4 },{ "STA", &c::STA, &c::ZPX, 4 },{ "STX", &c::STX, &c::ZPY, 4 },{ "???", &c::XXX, &c::IMP, 4 },{ "TYA", &c::TYA, &c::IMP, 2 },{ "STA", &c::STA, &c::ABY, 5 },{ "TXS", &c::TXS, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 5 },{ "???", &c::NOP, &c::IMP, 5 },{ "STA", &c::STA, &c::ABX, 5 },{ "???", &c::XXX, &c::IMP, 5 },{ "???", &c::XXX, &c::IMP, 5 },
		{ "LDY", &c::LDY, &c::IMM, 2 },{ "LDA", &c::LDA, &c::IZX, 6 },{ "LDX", &c::LDX, &c::IMM, 2 },{ "???", &c::XXX, &c::IMP, 6 },{ "LDY", &c::LDY, &c::ZP0, 3 },{ "LDA", &c::LDA, &c::ZP0, 3 },{ "LDX", &c::LDX, &c::ZP0, 3 },{ "???", &c::XXX, &c::IMP, 3 },{ "TAY", &c::TAY, &c::IMP, 2 },{ "LDA", &c::LDA, &c::IMM, 2 },{ "TAX", &c::TAX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 2 },{ "LDY", &c::LDY, &c::ABS, 4 },{ "LDA", &c::LDA, &c::ABS, 4 },{ "LDX", &c::LDX, &c::ABS, 4 },{ "???", &c::XXX, &c::IMP, 4 },
		{ "BCS", &c::BCS, &c::REL, 2 },{ "LDA", &c::LDA, &c::IZY, 5 },{ "???", &c::XXX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 5 },{ "LDY", &c::LDY, &c::ZPX, 4 },{ "LDA", &c::LDA, &c::ZPX, 4 },{ "LDX", &c::LDX, &c::ZPY, 4 },{ "???", &c::XXX, &c::IMP, 4 },{ "CLV", &c::CLV, &c::IMP, 2 },{ "LDA", &c::LDA, &c::ABY, 4 },{ "TSX", &c::TSX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 4 },{ "LDY", &c::LDY, &c::ABX, 4 },{ "LDA", &c::LDA, &c::ABX, 4 },{ "LDX", &c::LDX, &c::ABY, 4 },{ "???", &c::XXX, &c::IMP, 4 },
		{ "CPY", &c::CPY, &c::IMM, 2 },{ "CMP", &c::CMP, &c::IZX, 6 },{ "???", &c::NOP, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 8 },{ "CPY", &c::CPY, &c::ZP0, 3 },{ "CMP", &c::CMP, &c::ZP0, 3 },{ "DEC", &c::DEC, &c::ZP0, 5 },{ "???", &c::XXX, &c::IMP, 5 },{ "INY", &c::INY, &c::IMP, 2 },{ "CMP", &c::CMP, &c::IMM, 2 },{ "DEX", &c::DEX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 2 },{ "CPY", &c::CPY, &c::ABS, 4 },{ "CMP", &c::CMP, &c::ABS, 4 },{ "DEC", &c::DEC, &c::ABS, 6 },{ "???", &c::XXX, &c::IMP, 6 },
		{ "BNE", &c::BNE, &c::REL, 2 },{ "CMP", &c::CMP, &c::IZY, 5 },{ "???", &c::XXX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 8 },{ "???", &c::NOP, &c::IMP, 4 },{ "CMP", &c::CMP, &c::ZPX, 4 },{ "DEC", &c::DEC, &c::ZPX, 6 },{ "???", &c::XXX, &c::IMP, 6 },{ "CLD", &c::CLD, &c::IMP, 2 },{ "CMP", &c::CMP, &c::ABY, 4 },{ "NOP", &c::NOP, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 7 },{ "???", &c::NOP, &c::IMP, 4 },{ "CMP", &c::CMP, &c::ABX, 4 },{ "DEC", &c::DEC, &c::ABX, 7 },{ "???", &c::XXX, &c::IMP, 7 },
		{ "CPX", &c::CPX, &c::IMM, 2 },{ "SBC", &c::SBC, &c::IZX, 6 },{ "???", &c::NOP, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 8 },{ "CPX", &c::CPX, &c::ZP0, 3 },{ "SBC", &c::SBC, &c::ZP0, 3 },{ "INC", &c::INC, &c::ZP0, 5 },{ "???", &c::XXX, &c::IMP, 5 },{ "INX", &c::INX, &c::IMP, 2 },{ "SBC", &c::SBC, &c::IMM, 2 },{ "NOP", &c::NOP, &c::IMP, 2 },{ "???", &c::SBC, &c::IMP, 2 },{ "CPX", &c::CPX, &c::ABS, 4 },{ "SBC", &c::SBC, &c::ABS, 4 },{ "INC", &c::INC, &c::ABS, 6 },{ "???", &c::XXX, &c::IMP, 6 },
		{ "BEQ", &c::BEQ, &c::REL, 2 },{ "SBC", &c::SBC, &c::IZY, 5 },{ "???", &c::XXX, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 8 },{ "???", &c::NOP, &c::IMP, 4 },{ "SBC", &c::SBC, &c::ZPX, 4 },{ "INC", &c::INC, &c::ZPX, 6 },{ "???", &c::XXX, &c::IMP, 6 },{ "SED", &c::SED, &c::IMP, 2 },{ "SBC", &c::SBC, &c::ABY, 4 },{ "NOP", &c::NOP, &c::IMP, 2 },{ "???", &c::XXX, &c::IMP, 7 },{ "???", &c::NOP, &c::IMP, 4 },{ "SBC", &c::SBC, &c::ABX, 4 },{ "INC", &c::INC, &c::ABX, 7 },{ "???", &c::XXX, &c::IMP, 7 },
	};
}

void CentralProcessingUnit::Write(uint16_t address, uint8_t data)
{
	m_pBus->Write(address, data);
}

uint8_t CentralProcessingUnit::Read(uint16_t address, bool bReadOnly)
{
	return m_pBus->Read(address, bReadOnly);
}

void CentralProcessingUnit::Clock()
{
	if (m_Cycles == 0)
	{
		opcode = Read(m_ProgramCounter++);

		m_Cycles = m_Lookup[opcode].cycles;

		uint8_t additionalCycle1{ (this->*m_Lookup[opcode].addressMode)() };
		uint8_t additionalCycle2{ (this->*m_Lookup[opcode].operate)() };

		m_Cycles += additionalCycle1 & additionalCycle2;
	}

	--m_Cycles;
}

void CentralProcessingUnit::Reset()
{
	m_Accumulator = 0;
	m_X = 0;
	m_Y = 0;
	m_StackPointer = 0xFD;
	m_StatusRegister = 0x00 | U;

	m_AddressAbsolute = 0xFFFC;
	uint16_t lowByte = Read(m_AddressAbsolute);
	uint16_t highByte = Read(m_AddressAbsolute + 1);

	m_ProgramCounter = (highByte << 8) | lowByte;

	m_AddressRelative = 0x0000;
	m_AddressAbsolute = 0x0000;
	m_Fetched = 0x00;

	m_Cycles = 8;
}

void CentralProcessingUnit::Irq()
{
	if (!GetFlag(I))
	{
		Write(m_StackAddress + m_StackPointer--, (m_ProgramCounter >> 8) & 0x00FF);
		Write(m_StackAddress + m_StackPointer--, m_ProgramCounter & 0x00FF);

		SetFlag(B, 0);
		SetFlag(U, 1);
		SetFlag(I, 1);
		Write(m_StackAddress + m_StackPointer--, m_StatusRegister);

		m_AddressAbsolute = 0xFFFE;
		uint16_t lowByte = Read(m_AddressAbsolute);
		uint16_t highByte = Read(m_AddressAbsolute + 1);
		m_ProgramCounter = (highByte << 8) | lowByte;

		m_Cycles = 7;
	}
}

#pragma region addressingModes
uint8_t CentralProcessingUnit::IMP() //Implied
{
	m_Fetched = m_Accumulator;
	return 0;
}

uint8_t CentralProcessingUnit::IMM() //Immediate
{
	m_AddressAbsolute = m_ProgramCounter++;
	return 0;
}

uint8_t CentralProcessingUnit::ZP0() //Zero Page
{
	m_AddressAbsolute = Read(m_ProgramCounter++);
	m_AddressAbsolute &= 0x00FF;
	return 0;
}

uint8_t CentralProcessingUnit::ZPX() //Zero Page X
{
	m_AddressAbsolute = Read(m_ProgramCounter++) + m_X;
	m_AddressAbsolute &= 0x00FF;
	return 0;
}

uint8_t CentralProcessingUnit::ZPY() //Zero Page Y
{
	m_AddressAbsolute = Read(m_ProgramCounter++) + m_Y;
	m_AddressAbsolute &= 0x00FF;
	return 0;
}

uint8_t CentralProcessingUnit::REL() //Relative
{
	m_AddressRelative = Read(m_ProgramCounter++);
	
	if (m_AddressRelative & 0x80)
	{
		m_AddressRelative |= 0xFF00;
	}

	return 0;
}

uint8_t CentralProcessingUnit::ABS() //Absolute
{
	uint16_t lowByte{ Read(m_ProgramCounter++) };
	uint16_t highByte{ Read(m_ProgramCounter++) };

	m_AddressAbsolute = (highByte << 8) | lowByte;
	return 0;
}

uint8_t CentralProcessingUnit::ABX() //Absolute X
{
	uint16_t lowByte{ Read(m_ProgramCounter++) };
	uint16_t highByte{ Read(m_ProgramCounter++) };

	m_AddressAbsolute = (highByte << 8) | lowByte;
	m_AddressAbsolute += m_X;

	if ((m_AddressAbsolute & 0xFF00) != (highByte << 8)) //If we change page we may need another cycle
	{
		return 1;
	}
	return 0;
}

uint8_t CentralProcessingUnit::ABY() //Absolute Y
{
	uint16_t lowByte{ Read(m_ProgramCounter++) };
	uint16_t highByte{ Read(m_ProgramCounter++) };

	m_AddressAbsolute = (highByte << 8) | lowByte;
	m_AddressAbsolute += m_Y;

	if ((m_AddressAbsolute & 0xFF00) != (highByte << 8)) //If we change page we may need another cycle
	{
		return 1;
	}
	return 0;
}

uint8_t CentralProcessingUnit::IND() //Indirect
{
	uint16_t pointerLow{ Read(m_ProgramCounter++) };
	uint16_t pointerHigh{ Read(m_ProgramCounter++) };

	uint16_t pointer{ (pointerHigh << 8) | pointerLow };

	if (pointerLow == 0x00FF) //Page boundary hardware bug
	{
		m_AddressAbsolute = (Read(pointer & 0xFF00) << 8) | Read(pointer);
	}
	else
	{
		m_AddressAbsolute = (Read(pointer + 1) << 8) | Read(pointer);
	}

	return 0;
}

uint8_t CentralProcessingUnit::IZX() //Indirect Zero Page X
{
	uint16_t t{ Read(m_ProgramCounter++) };

	uint16_t lowByte{ Read((uint16_t)(t + (uint16_t)m_X) & 0x00FF) };
	uint16_t highByte{ Read((uint16_t)(t + (uint16_t)m_X + 1) & 0x00FF) };

	m_AddressAbsolute = (highByte << 8) | lowByte;

	return 0;
}

uint8_t CentralProcessingUnit::IZY() //Indirect Zero Page Y
{
	uint16_t t{ Read(m_ProgramCounter++) };

	uint16_t lowByte{ Read(t & 0x00FF) };
	uint16_t highByte{ Read((t + 1) & 0x00FF) };

	m_AddressAbsolute = (highByte << 8) | lowByte;
	m_AddressAbsolute += m_Y;

	if ((m_AddressAbsolute & 0xFF00) != (highByte << 8))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
#pragma endregion

uint8_t CentralProcessingUnit::GetFlag(Flags f)
{
	return ((m_StatusRegister & f) > 0) ? 1 : 0;
}
void CentralProcessingUnit::SetFlag(Flags f, bool v)
{
	if (v)
		m_StatusRegister |= f;
	else
		m_StatusRegister &= ~f;
}

#pragma region instructions
uint8_t CentralProcessingUnit::Fetch()
{
	if (!(m_Lookup[opcode].addressMode == &IMP))
	{
		m_Fetched = Read(m_AddressAbsolute);
	}
	return m_Fetched;
}

uint8_t CentralProcessingUnit::ADC() //Addition
{
	Fetch();
	uint16_t temp{ (uint16_t)m_Accumulator + (uint16_t)m_Fetched + (uint16_t)GetFlag(C) };
	SetFlag(C, temp > 255);
	SetFlag(Z, (temp & 0x00FF) == 0);
	SetFlag(N, temp & 0x80);
	SetFlag(V, (((uint16_t)m_Accumulator ^ (uint16_t)m_Fetched) & ((uint16_t)m_Accumulator ^ (uint16_t)temp)) & 0x0080);
	m_Accumulator = temp & 0x00FF;
	return 1;
}

uint8_t CentralProcessingUnit::AND() //Bitwise AND
{
	Fetch();
	m_Accumulator &= m_Fetched;
	SetFlag(Z, m_Accumulator == 0x00);
	SetFlag(N, m_Accumulator == 0x80);
	return 1;
}

uint8_t CentralProcessingUnit::ASL() //Arithmetic Shift Left one bit
{
	Fetch();
	uint16_t temp = (uint16_t)m_Fetched << 1;
	SetFlag(C, (temp & 0xFF00) > 0);
	SetFlag(Z, (temp & 0xFF00) == 0x00);
	SetFlag(N, temp & 0x80);
	if (m_Lookup[opcode].addressMode == &IMP)
	{
		m_Accumulator = temp & 0x00FF;
	}
	else
	{
		Write(m_AddressAbsolute, temp & 0x00FF);
	}
	return 0;
}

uint8_t CentralProcessingUnit::BCS() //Branch if clear
{
	if (GetFlag(C))
	{
		m_Cycles++;
		m_AddressAbsolute = m_ProgramCounter + m_AddressRelative;

		if ((m_AddressAbsolute & 0xFF00) != (m_ProgramCounter & 0xFF00))
		{
			m_Cycles++;
		}

		m_ProgramCounter = m_AddressAbsolute;
	}
	return 0;
}

uint8_t CentralProcessingUnit::BCC() //Branch if not clear
{
	if (!GetFlag(C))
	{
		m_Cycles++;
		m_AddressAbsolute = m_ProgramCounter + m_AddressRelative;

		if ((m_AddressAbsolute & 0xFF00) != (m_ProgramCounter & 0xFF00))
		{
			m_Cycles++;
		}

		m_ProgramCounter = m_AddressAbsolute;
	}
	return 0;
}

uint8_t CentralProcessingUnit::BEQ() //Branch if equal
{
	if (GetFlag(Z))
	{
		m_Cycles++;
		m_AddressAbsolute = m_ProgramCounter + m_AddressRelative;

		if ((m_AddressAbsolute & 0xFF00) != (m_ProgramCounter & 0xFF00))
		{
			m_Cycles++;
		}

		m_ProgramCounter = m_AddressAbsolute;
	}
	return 0;
}

uint8_t CentralProcessingUnit::BIT() //Test bits in memory with accumulator
{
	Fetch();
	uint16_t temp = m_Accumulator & m_Fetched;
	SetFlag(Z, !(temp & 0x00FF));
	SetFlag(N, temp & (1 << 7));
	SetFlag(V, temp & (1 << 6));
	return 0;
}

uint8_t CentralProcessingUnit::BMI() //Branch if negative
{
	if (GetFlag(N))
	{
		m_Cycles++;
		m_AddressAbsolute = m_ProgramCounter + m_AddressRelative;

		if ((m_AddressAbsolute & 0xFF00) != (m_ProgramCounter & 0xFF00))
		{
			m_Cycles++;
		}

		m_ProgramCounter = m_AddressAbsolute;
	}
	return 0;
}

uint8_t CentralProcessingUnit::BNE() //Branch if not equal
{
	if (!GetFlag(Z))
	{
		m_Cycles++;
		m_AddressAbsolute = m_ProgramCounter + m_AddressRelative;

		if ((m_AddressAbsolute & 0xFF00) != (m_ProgramCounter & 0xFF00))
		{
			m_Cycles++;
		}

		m_ProgramCounter = m_AddressAbsolute;
	}
	return 0;
}

uint8_t CentralProcessingUnit::BPL() //Branch if positive
{
	if (!GetFlag(N))
	{
		m_Cycles++;
		m_AddressAbsolute = m_ProgramCounter + m_AddressRelative;

		if ((m_AddressAbsolute & 0xFF00) != (m_ProgramCounter & 0xFF00))
		{
			m_Cycles++;
		}

		m_ProgramCounter = m_AddressAbsolute;
	}
	return 0;
}

uint8_t CentralProcessingUnit::BRK() //Force an interrupt
{
	SetFlag(I, 1);
	Write(m_StackAddress + m_StackPointer--, (++m_ProgramCounter >> 8) & 0x00FF);
	Write(m_StackAddress + m_StackPointer--, m_ProgramCounter & 0x00FF);

	SetFlag(B, 1);
	Write(m_StackAddress + m_StackPointer--, m_StatusRegister);
	SetFlag(B, 0);

	m_ProgramCounter = (uint16_t)Read(0xFFFE) | ((uint16_t)Read(0xFFFF) << 8);
	return 0;
}

uint8_t CentralProcessingUnit::BVC() //Branch if overflow
{
	if (GetFlag(V))
	{
		m_Cycles++;
		m_AddressAbsolute = m_ProgramCounter + m_AddressRelative;

		if ((m_AddressAbsolute & 0xFF00) != (m_ProgramCounter & 0xFF00))
		{
			m_Cycles++;
		}

		m_ProgramCounter = m_AddressAbsolute;
	}
	return 0;
}

uint8_t CentralProcessingUnit::BVS() //Branch if no overflow
{
	if (!GetFlag(V))
	{
		m_Cycles++;
		m_AddressAbsolute = m_ProgramCounter + m_AddressRelative;

		if ((m_AddressAbsolute & 0xFF00) != (m_ProgramCounter & 0xFF00))
		{
			m_Cycles++;
		}

		m_ProgramCounter = m_AddressAbsolute;
	}
	return 0;
}

uint8_t CentralProcessingUnit::CLC() //Clear C flag
{
	SetFlag(C, false);
	return 0;
}

uint8_t CentralProcessingUnit::CLD() //Clear D flag
{
	SetFlag(D, false);
	return 0;
}

uint8_t CentralProcessingUnit::CLI() //Clear I flag
{
	SetFlag(I, false);
	return 0;
}

uint8_t CentralProcessingUnit::CLV() //Clear V flag
{
	SetFlag(V, false);
	return 0;
}

uint8_t CentralProcessingUnit::CMP() //Compare memory and accumulator
{
	Fetch();
	uint16_t temp{ (uint16_t)m_Accumulator - (uint16_t)m_Fetched };
	SetFlag(N, temp & 0x0080);
	SetFlag(Z, !(temp & 0x00FF));
	SetFlag(C, m_Accumulator >= m_Fetched);
	return 1;
}

uint8_t CentralProcessingUnit::CPX() //Compare memory and X
{
	Fetch();
	uint16_t temp{ (uint16_t)m_X - (uint16_t)m_Fetched };
	SetFlag(N, temp & 0x0080);
	SetFlag(Z, !(temp & 0x00FF));
	SetFlag(C, m_X >= m_Fetched);
	return 1;
}

uint8_t CentralProcessingUnit::CPY() //Compare memory and Y
{
	Fetch();
	uint16_t temp{ (uint16_t)m_Y - (uint16_t)m_Fetched };
	SetFlag(N, temp & 0x0080);
	SetFlag(Z, !(temp & 0x00FF));
	SetFlag(C, m_Y >= m_Fetched);
	return 1;
}

uint8_t CentralProcessingUnit::DEC() //Decrement memory at location
{
	Fetch();
	uint16_t temp{ m_Fetched - 1 };
	Write(m_AddressAbsolute, temp & 0x00FF);
	SetFlag(N, temp & 0x0080);
	SetFlag(Z, !(temp & 0x00FF));
	return 0;
}

uint8_t CentralProcessingUnit::DEX() //Decrement X
{
	--m_X;
	SetFlag(N, m_X & 0x80);
	SetFlag(Z, !m_X);
	return 0;
}

uint8_t CentralProcessingUnit::DEY() //Decrement Y
{
	--m_Y;
	SetFlag(N, m_Y & 0x80);
	SetFlag(Z, !m_Y);
	return 0;
}

uint8_t CentralProcessingUnit::EOR() //XOR Memory with accumulator
{
	Fetch();
	m_Accumulator = m_Fetched ^ m_Accumulator;
	SetFlag(N, m_Accumulator & 0x80);
	SetFlag(Z, !m_Accumulator);
	return uint8_t();
}

uint8_t CentralProcessingUnit::INC() //Increment memory
{
	Fetch();
	uint16_t temp{ m_Fetched + 1 };
	Write(m_AddressAbsolute, temp & 0x00FF);
	SetFlag(N, temp & 0x0080);
	SetFlag(Z, !(temp & 0x00FF));
	return 0;
}

uint8_t CentralProcessingUnit::INX() //Increment X
{
	++m_X;
	SetFlag(N, m_X & 0x80);
	SetFlag(Z, !m_X);
	return 0;
}

uint8_t CentralProcessingUnit::INY() //Increment Y
{
	++m_Y;
	SetFlag(N, m_Y & 0x80);
	SetFlag(Z, !m_Y);
	return 0;
}

uint8_t CentralProcessingUnit::JMP() //Jump
{
	m_ProgramCounter = m_AddressAbsolute;
	return 0;
}

uint8_t CentralProcessingUnit::JSR() //Jump to subroutine
{
	Write(m_StackAddress + m_StackPointer--, (--m_ProgramCounter >> 8) & 0x00FF);
	Write(m_StackAddress + m_StackPointer--, m_ProgramCounter & 0x00FF);

	m_ProgramCounter = m_AddressAbsolute;
	return 0;
}

uint8_t CentralProcessingUnit::LDA() //Load memory into A
{
	Fetch();
	m_Accumulator = m_Fetched;
	SetFlag(N, m_Accumulator & 0x80);
	SetFlag(Z, !m_Accumulator);
	return 0;
}

uint8_t CentralProcessingUnit::LDX() //Load memory into X
{
	Fetch();
	m_X = m_Fetched;
	SetFlag(N, m_X & 0x80);
	SetFlag(Z, !m_X);
	return 0;
}

uint8_t CentralProcessingUnit::LDY() //Load memory into Y
{
	Fetch();
	m_Y = m_Fetched;
	SetFlag(N, m_Y & 0x80);
	SetFlag(Z, !m_Y);
	return 0;
}


uint8_t CentralProcessingUnit::LSR() //Logical shift right
{
	Fetch();
	SetFlag(C, m_Fetched & 0x01);
	uint16_t temp{ m_Fetched >> 1 };
	SetFlag(N, temp & 0x0080);
	SetFlag(Z, !(temp & 0x00FF));

	if (m_Lookup[opcode].addressMode == &IMP)
		m_Accumulator = temp & 0x00FF;
	else
		Write(m_AddressAbsolute, temp & 0x00FF);
	return 0;
}

uint8_t CentralProcessingUnit::ROR() //Rotate right one bit
{
	Fetch();
	uint16_t temp{(uint16_t)(GetFlag(C) << 7 ) | m_Fetched >> 1 };
	SetFlag(C, m_Fetched & 0x01);
	SetFlag(Z, !(temp & 0x00FF));
	SetFlag(N, temp & 0x0080);

	if (m_Lookup[opcode].addressMode == &IMP)
		m_Accumulator = temp & 0x00FF;
	else
		Write(m_AddressAbsolute, temp & 0x00FF);
	return 0;
}

uint8_t CentralProcessingUnit::RTI() //Return from interrupt
{
	m_StatusRegister = Read(m_StackAddress + ++m_StackPointer);
	m_StatusRegister &= ~B;
	m_StatusRegister &= ~U;

	m_ProgramCounter = (uint16_t)Read(m_StackAddress + ++m_StackPointer);
	m_ProgramCounter |= (uint16_t)Read(m_StackAddress + ++m_StackPointer) << 8;
	return 0;
}

uint8_t CentralProcessingUnit::RTS() //Return from subroutine
{
	m_ProgramCounter = (uint16_t)Read(m_StackAddress + ++m_StackPointer);
	m_ProgramCounter |= (uint16_t)Read(m_StackAddress + ++m_StackPointer) << 8;
	++m_ProgramCounter;
	return 0;
}

uint8_t CentralProcessingUnit::SBC() //Subtract
{
	Fetch();

	uint16_t value{ ((uint16_t)m_Fetched ^ 0x00FF) };

	uint16_t temp{ (uint16_t)m_Accumulator + value + (uint16_t)GetFlag(C) };
	SetFlag(C, temp > 255);
	SetFlag(Z, (temp & 0x00FF) == 0);
	SetFlag(N, temp & 0x80);
	SetFlag(V, (((uint16_t)m_Accumulator ^ (uint16_t)value) & ((uint16_t)m_Accumulator ^ (uint16_t)temp)) & 0x0080);
	m_Accumulator = temp & 0x00FF;
	return 1;
}

uint8_t CentralProcessingUnit::SEC() //Set C flag
{
	SetFlag(C, true);
	return 0;
}

uint8_t CentralProcessingUnit::SED() //Set D flag
{
	SetFlag(D, true);
	return 0;
}

uint8_t CentralProcessingUnit::SEI() //Set I flag
{
	SetFlag(I, true);
	return 0;
}

uint8_t CentralProcessingUnit::STA() //Store A in memory
{
	Write(m_AddressAbsolute, m_Accumulator);
	return 0;
}

uint8_t CentralProcessingUnit::STX() //Store X in memory
{
	Write(m_AddressAbsolute, m_X);
	return 0;
}

uint8_t CentralProcessingUnit::STY() //Store Y in memory
{
	Write(m_AddressAbsolute, m_Y);
	return 0;
}

uint8_t CentralProcessingUnit::TAX() //Transfer A to X
{
	m_X = m_Accumulator;
	SetFlag(Z, !m_X);
	SetFlag(N, m_X & 0x80);
	return 0;
}

uint8_t CentralProcessingUnit::TAY() //Transfer A to Y
{
	m_Y = m_Accumulator;
	SetFlag(Z, !m_Y);
	SetFlag(N, m_Y & 0x80);
	return 0;
}

uint8_t CentralProcessingUnit::TSX() //Transfer stack pointer to X
{
	m_X = m_StackPointer;
	SetFlag(Z, !m_X);
	SetFlag(N, m_X & 0x80);
	return 0;
}

uint8_t CentralProcessingUnit::TXA() //Transfer X to A
{
	m_Accumulator = m_X;
	SetFlag(Z, !m_Accumulator);
	SetFlag(N, m_Accumulator & 0x80);
	return 0;
}

uint8_t CentralProcessingUnit::TXS() //Transfer X to stack pointer
{
	m_StackPointer = m_X;
	return 0;
}

uint8_t CentralProcessingUnit::TYA() //Transfer Y to A
{
	m_Accumulator = m_Y;
	SetFlag(Z, !m_Accumulator);
	SetFlag(N, m_Accumulator & 0x80);
	return 0;
}

uint8_t CentralProcessingUnit::XXX() //illegal opcodes
{
	return 0;
}

uint8_t CentralProcessingUnit::NOP() //No operation (apparently not all NOPs are equal)
{
	switch (opcode) {
	case 0x1C:
	case 0x3C:
	case 0x5C:
	case 0x7C:
	case 0xDC:
	case 0xFC:
		return 1;
		break;
	}
	return 0;
}

uint8_t CentralProcessingUnit::ORA() //OR memory with A
{
	Fetch();
	m_Accumulator |= m_Fetched;
	SetFlag(N, m_Accumulator & 0x80);
	SetFlag(Z, !m_Accumulator);
	return 1;
}

uint8_t CentralProcessingUnit::PHA() //Put A on stack
{
	Write(m_StackAddress + m_StackPointer--, m_Accumulator);
	return 0;
}

uint8_t CentralProcessingUnit::PHP() //Push Status on stack (B flag is set before)
{
	Write(m_StackAddress + m_StackPointer--, m_StatusRegister | B | U);
	SetFlag(B, 0);
	SetFlag(U, 0);
	return 0;
}

uint8_t CentralProcessingUnit::PLA() //Take A off stack
{
	m_Accumulator = Read(m_StackAddress + ++m_StackPointer);
	SetFlag(Z, m_Accumulator == 0x00);
	SetFlag(N, m_Accumulator & 0x80);
	return 0;
}
uint8_t CentralProcessingUnit::PLP() //Pull Status from stack
{
	m_StatusRegister = Read(m_StackAddress + ++m_StackPointer);
	SetFlag(U, 1);
	return 0;	
}
uint8_t CentralProcessingUnit::ROL() //Rotate left
{
	Fetch();
	uint16_t temp{ (uint16_t)(m_Fetched << 1) | GetFlag(C) };
	SetFlag(C, m_Fetched & 0x80);
	SetFlag(Z, !(temp & 0x00FF));
	SetFlag(N, temp & 0x0080);

	if (m_Lookup[opcode].addressMode == &IMP)
		m_Accumulator = temp & 0x00FF;
	else
		Write(m_AddressAbsolute, temp & 0x00FF);
	return 0;
}
#pragma endregion