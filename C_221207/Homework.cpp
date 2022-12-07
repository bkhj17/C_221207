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
		//����
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
		
	printf("%d���� ���ڸ� �Է��Ͻÿ�(%d~%d)", ARR_SIZE, MIN_NUM, MAX_NUM);
	printf((overlap ? "(�ߺ� ����)\n" : "(�ߺ� ����)\n"));
	for (int i = 0; i < arr_length; i++) {
		printf("\n%d��° ���ڸ� �Է��Ͻÿ� -> ", i+1);
		scanf_s("%d", arr+i);

		if (!isValid(arr[i])) {
			printf("�� ���ڴ� ���� ���Դϴ�. �ٽ� �Է��Ͻÿ�\n");
			i--;
			continue;
		}
		else if (!overlap && did[arr[i]]) {
			printf("������ �Է��� ���ڿ� �ߺ��˴ϴ�. �ٽ� �Է��Ͻÿ�\n");
			arr[i] = 0;
			i--;
			continue;
		}
		did[arr[i]] = true;
	}
	printf("�Է��� ���� : ");
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
		printf("3 ��Ʈ����ũ!\n");
		return true;
	}
	else if (IsOut(strike, ball)) {
		printf("%d�ƿ�!\n", ++out);
	}
	else {
		if (strike > 0)
			printf("%d ��Ʈ����ũ", strike);
		if (ball > 0)
			printf("%d ��", ball);
		printf("\n");
	}
	return false;
}

void Homework::PrintGameResult(int out)
{
	if (out == GAME_OVER)
		//�й�
		printf("3 �ƿ�. ���� ����....\n");
	
	else
		//�¸�
		printf("You Win!\n");
}

int Homework::Title()
{
	int s = 0;
	printf("[���ھ߱� ����]\n");
	printf("%d���� ���ڸ� �����! ��ȸ�� �� %d��!\n", ARR_SIZE, GAME_OVER);
	printf("1. �ߺ�����\n2. �ߺ�����\n�� ��.����\n-> ");
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
	printf("[���� ����]\n");

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
	����: ���ھ߱�
	1~9 ���� ���� 3�� ����(�ߺ� �Ұ�/����)
	while
		1~9 ���� �Է¹ޱ�
		�� => �ڸ���==���� => ��Ʈ����ũ, ���ڴ� �ְ� �ڸ��� �ٸ��� ��, 0s0b�� �ƿ�
		3�ƿ��� ���ӿ���
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
			printf("������ �����մϴ�.");
			return;
		}
		printf("\n");
	} while (true);
}
