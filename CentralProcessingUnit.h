#pragma once
#include "ProcessingUnit.h"
#include <vector>

class Bus;

class CentralProcessingUnit : public ProcessingUnit
{
public:
	CentralProcessingUnit();
	~CentralProcessingUnit() = default;

	void ConnectBus(Bus* bus) { m_pBus = bus; };

	enum Flags
	{
		C = (1<<0),	//Carry bit
		Z = (1<<1),	//Zero
		I = (1<<2),	//Disable Interrupts
		D = (1<<3),	//Decimal Mode
		B = (1<<4),	//Break
		U = (1<<5),	//Unused
		V = (1<<6),	//Overflow
		N = (1<<7),	//Negative
	};

	//REGISTERS
	uint8_t m_Accumulator{ 0x00 };
	uint8_t m_X{ 0x00 };
	uint8_t m_Y{ 0x00 };
	uint8_t m_StackPointer{ 0x00 };
	uint16_t m_ProgramCounter{ 0x0000 };
	uint8_t m_StatusRegister{ 0x00 };

	//Stack starts here
	const uint16_t m_StackAddress{ 0x0100 };


private:

#pragma region addressing
	//Addressing modes
	uint8_t IMP();	uint8_t IMM();	uint8_t ZP0();
	uint8_t ZPX();	uint8_t ZPY();	uint8_t REL();
	uint8_t ABS();	uint8_t ABX();	uint8_t ABY();
	uint8_t IND();	uint8_t IZX();	uint8_t IZY();
#pragma endregion

#pragma region opcodes
	//Opcodes
	uint8_t ADC();	uint8_t AND();	uint8_t ASL();	uint8_t BCC();
	uint8_t BCS();	uint8_t BEQ();	uint8_t BIT();	uint8_t BMI();
	uint8_t BNE();	uint8_t BPL();	uint8_t BRK();	uint8_t BVC();
	uint8_t BVS();	uint8_t CLC();	uint8_t CLD();	uint8_t CLI();
	uint8_t CLV();	uint8_t CMP();	uint8_t CPX();	uint8_t CPY();
	uint8_t DEC();	uint8_t DEX();	uint8_t DEY();	uint8_t EOR();
	uint8_t INC();	uint8_t INX();	uint8_t INY();	uint8_t JMP();
	uint8_t JSR();	uint8_t LDA();	uint8_t LDX();	uint8_t LDY();
	uint8_t LSR();	uint8_t NOP();	uint8_t ORA();	uint8_t PHA();
	uint8_t PHP();	uint8_t PLA();	uint8_t PLP();	uint8_t ROL();
	uint8_t ROR();	uint8_t RTI();	uint8_t RTS();	uint8_t SBC();
	uint8_t SEC();	uint8_t SED();	uint8_t SEI();	uint8_t STA();
	uint8_t STX();	uint8_t STY();	uint8_t TAX();	uint8_t TAY();
	uint8_t TSX();	uint8_t TXA();	uint8_t TXS();	uint8_t TYA();

	uint8_t XXX(); //Illegal opcodes
#pragma endregion

	void Clock();
	void Reset();
	void Irq(); //Interrupt request
	void Nmi(); //Non-maskable interrupt request

	uint8_t GetFlag(Flags f);
	void    SetFlag(Flags f, bool v);

	uint8_t Fetch();
	uint8_t m_Fetched{0x00};

	uint16_t m_AddressAbsolute{0x0000};
	uint16_t m_AddressRelative{ 0x00 };
	uint8_t opcode{ 0x00 };
	uint8_t m_Cycles{ 0 };

	void Write(uint16_t address, uint8_t data);
	uint8_t Read(uint16_t address, bool bReadOnly = false);

	Bus* m_pBus = nullptr;

	struct Instruction
	{
		std::string name;
		uint8_t(CentralProcessingUnit::* operate)(void) { nullptr };
		uint8_t(CentralProcessingUnit::* addressMode)(void) { nullptr };
		uint8_t cycles{ 0 };
	};

	std::vector<Instruction> m_Lookup{};
};

