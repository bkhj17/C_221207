#pragma once
#include "Base.h"
class Function : public Base
{
	inline static void Add(int a, int b) { a += b; }
	inline static void Add2(int& a, int& b) { a += b; }
	inline static void Add3(int* a, int* b) { *a += *b; }
	inline static void Add4(int& a, const int& b) { a += b; }
public:
	// Base��(��) ���� ��ӵ�
	virtual void Run() override;
};

