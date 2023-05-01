#include "pch.h"
#include "ProcessingUnit.h"

void ProcessingUnit::StepTo(unsigned int newCycle)
{
	while (m_CycleCount < newCycle)
	{
		ExecuteInstruction();
	}
}
