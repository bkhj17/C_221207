#pragma once
#include "Base.h"

typedef unsigned int uint;	//����� ���� �ڷ���

class DrawDiamond :public Base
{
	uint GetDiamondSize();
	inline uint GetAbsolute(int value);
	void PrintChar(const uint& size, const char& word);
public:
	virtual void Run() override;
};

