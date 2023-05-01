#pragma once
class ProcessingUnit
{
public:
	void StepTo(unsigned int cycle);
protected:
	virtual void ExecuteInstruction() = 0;

	unsigned int m_CycleCount;
};

