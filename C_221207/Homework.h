#pragma once
#include "Base.h"
#include "UsefulType.h"

class Homework : public Base
{
	enum class MENU_SELECTION;
	void MakeRandSet(uint *arr, uint arr_length, bool overlap = false);
	bool CheckInvalid(uint* arr, uint arr_length);
	bool CheckOverlap(uint* arr, uint arr_length);
	void GetInputSet(uint* arr, uint arr_length, bool overlap = false);
	void PrintArr(uint* arr, uint arr_length);
	void CompareArr(int& strike, int& ball, const uint* arr1, const uint* arr2);
	bool IsOut(const int& strike, const int& ball);
	bool isValid(uint a);
	bool PrintAttackResult(const int& strike, const int& ball);
	void PrintGameResult(int out);
	int Title();
	void Game(int chance, bool overlap = false);
public:
	// Base을(를) 통해 상속됨
	virtual void Run() override;
};

