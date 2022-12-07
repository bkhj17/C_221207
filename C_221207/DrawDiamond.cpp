#include "DrawDiamond.h"
#include <stdio.h>
#include <stdlib.h>

uint DrawDiamond::GetDiamondSize() {
	int size = 0;
	do {
		printf("다이아몬드 크기 입력(홀수만) -> ");
		scanf_s("%d", &size);

		if (size <= 0 || size % 2 != 1)
			printf("잘못된 입력입니다. 다시 입력하십시오.\n");

	} while (size <= 0 || size % 2 != 1);
	return static_cast<uint>(size);
}

uint DrawDiamond::GetAbsolute(int value)
{
	return value < 0 ? -value : value;
}

void DrawDiamond::PrintChar(const uint& size, const char& word)
{
	for (uint j = 0; j < size; j++)
		printf("%c", word);
}

void DrawDiamond::Run()
{
	uint diamondSize = 0;
	uint halfSize = 0;

	diamondSize = GetDiamondSize();
	halfSize = diamondSize >> 1;

	for (int i = 0; i < diamondSize; i++) {
		uint spaceSize = GetAbsolute(halfSize - i);
		uint starSize = diamondSize - spaceSize * 2;
		PrintChar(spaceSize, ' ');
		PrintChar(starSize, '*');
		printf("\n");
	}
}

