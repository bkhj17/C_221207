#include "Homework.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef TEST
//#define TEST
#endif // !TEST

const uint MIN_NUM = 1;
const uint MAX_NUM = 9;
const uint GAME_OVER = 3;
const uint SHUFFLE_TIME = 100;
const uint ARR_SIZE = 3;

void Homework::MakeRandSet(uint* arr, uint arr_length, bool overlap)
{
	if (!overlap) {
		uint numbers[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		//셔플
		Shuffle(numbers, MAX_NUM, SHUFFLE_TIME);

		for (uint i = 0; i < arr_length; i++)
			arr[i] = numbers[i];
	}
	else {
		for (uint i = 0; i < arr_length; i++) {
			uint a = MakeRandByRange(MIN_NUM, MAX_NUM);
			arr[i] = a;
		}
	}
}

void Homework::GetInputSet(uint* arr, uint arr_length, bool overlap)
{
	bool did[9] = { false };
	for (int i = 0; i < arr_length; i++)
		arr[i] = 0;
		
	printf("%d개의 숫자를 입력하시오(%d~%d)", ARR_SIZE, MIN_NUM, MAX_NUM);
	printf((overlap ? "(중복 가능)\n" : "(중복 없음)\n"));
	for (int i = 0; i < arr_length; i++) {
		printf("\n%d번째 숫자를 입력하시오 -> ", i+1);
		scanf_s("%d", arr+i);

		if (!isValid(arr[i])) {
			printf("그 숫자는 범위 밖입니다. 다시 입력하시오\n");
			i--;
			continue;
		}
		else if (!overlap && did[arr[i]]) {
			printf("이전에 입력한 숫자와 중복됩니다. 다시 입력하시오\n");
			arr[i] = 0;
			i--;
			continue;
		}
		did[arr[i]] = true;
	}
	printf("입력한 숫자 : ");
	PrintArr(arr, arr_length);
	printf("\n");
}

void Homework::PrintArr(uint* arr, uint arr_length)
{
	for (int i = 0; i < arr_length; i++) {
		printf((arr[i] == 0 ? "_ " : "%d "), arr[i]);
	}
}

void Homework::CompareArr(int& strike, int& ball, const uint* arr_target, const uint* arr_input)
{
	bool isIn[9] = {};

	strike = 0;
	ball = 0;

	for (int i = 0; i < ARR_SIZE; i++)
		isIn[arr_target[i]] = true;
	
	for (int i = 0; i < ARR_SIZE; i++) {
		if (arr_target[i] == arr_input[i])
			strike++;
		else if (isIn[arr_input[i]])
			ball++;
	}
}

bool Homework::IsOut(const int& strike, const int& ball)
{
	return strike == 0 && ball == 0;
}

bool Homework::isValid(uint a)
{
	return a >= MIN_NUM && a <= MAX_NUM;
}

bool Homework::PrintAttackResult(const int& strike, const int& ball, int &out)
{
	if (strike == 3) {
		printf("3 스트라이크!\n");
		return true;
	}
	else if (IsOut(strike, ball)) {
		printf("%d아웃!\n", ++out);
	}
	else {
		if (strike > 0)
			printf("%d 스트라이크", strike);
		if (ball > 0)
			printf("%d 볼", ball);
		printf("\n");
	}
	return false;
}

void Homework::PrintGameResult(int out)
{
	if (out == GAME_OVER)
		//패배
		printf("3 아웃. 게임 오버....\n");
	
	else
		//승리
		printf("You Win!\n");
}

int Homework::Title()
{
	int s = 0;
	printf("[숫자야구 게임]\n");
	printf("%d개의 숫자를 맞춰라! 기회는 단 %d번!\n", ARR_SIZE, GAME_OVER);
	printf("1. 중복없음\n2. 중복있음\n그 외.종료\n-> ");
	scanf_s("%d", &s);

	return s;
}

void Homework::Game(bool overlap)
{
	uint arr_rand[3] = {}, arr_input[3] = {};
	int out = 0;

	srand((uint)time(NULL));
	MakeRandSet(arr_rand, ARR_SIZE, overlap);
#ifdef TEST
	printf("Test : ");
	PrintArr(arr_rand, ARR_SIZE);
	printf("\n");
#endif // TEST
	printf("[게임 시작]\n");

	int strike = 0, ball = 0;
	while (out != GAME_OVER) {
		GetInputSet(arr_input, ARR_SIZE, overlap);

		PrintArr(arr_input, ARR_SIZE);
		printf(" : ");
		CompareArr(strike, ball, arr_rand, arr_input);
		if (PrintAttackResult(strike, ball, out))
			break;
	}
	PrintGameResult(out);
}

void Homework::Run()
{
	/*
	과제: 숫자야구
	1~9 랜덤 숫자 3개 생성(중복 불가/가능)
	while
		1~9 숫자 입력받기
		비교 => 자릿수==숫자 => 스트라이크, 숫자는 있고 자리는 다르면 볼, 0s0b는 아웃
		3아웃은 게임오버
	*/
	do {
		int select = Title();
		switch (select) {
		case 1:
			Game(false);
			break;
		case 2:
			Game(true);
			break;
		default:
			printf("게임을 종료합니다.");
			return;
		}
		printf("\n");
	} while (true);
}
