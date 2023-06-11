#include "pch.h"
#include "Emulator.h"

void Emulator::EmulateCycles(int amount)
{
	m_CycleCount += amount;
	m_CPU.StepTo(m_CycleCount);
	m_PPU.StepTo(m_CycleCount);
}
