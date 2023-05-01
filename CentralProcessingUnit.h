#pragma once
#include "ProcessingUnit.h"
class CentralProcessingUnit : public ProcessingUnit
{
private:
	void ExecuteInstruction() override;
};

