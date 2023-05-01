#include "pch.h"
#include "Emulator.h"

void Emulator::EmulateCycle()
{
	++m_CycleCount;
	m_CPU.StepTo(m_CycleCount);
	m_PPU.StepTo(m_CycleCount);
}
