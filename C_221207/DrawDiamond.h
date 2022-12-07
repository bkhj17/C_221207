#pragma once
#include "Base.h"

typedef unsigned int uint;	//사용자 지정 자료형

class DrawDiamond :public Base
{
	uint GetDiamondSize();
	inline uint GetAbsolute(int value);
	void PrintChar(const uint& size, const char& word);
public:
	virtual void Run() override;
};

