#pragma once
#include "Base.h"
class Pointer : public Base
{
	int TestPtr();
public:
	// Base을(를) 통해 상속됨
	virtual void Run() override;
};

