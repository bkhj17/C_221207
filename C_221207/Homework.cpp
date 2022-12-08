#include "Homework.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "UsefulFunc.h"

#ifndef TEST
//#define TEST
#endif // !TEST

const uint MIN_NUM = 1;
const uint MAX_NUM = 9;
const uint GAME_OVER = 10;
const uint SHUFFLE_TIME = 1000;
const uint ARR_SIZE = 3;

void Homework::MakeRandSet(uint* arr, uint arr_length, bool overlap)
{
	if (!overlap) {
		uint numbers[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		//����
		Shuffle(numbers, 9, SHUFFLE_TIME);
		//
		GetRandomsNoOverlap(numbers, sizeof(numbers) / sizeof(uint), ARR_SIZE);

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

bool Homework::CheckInvalid(uint* arr, uint arr_length)
{
	for (uint i = 0; i < arr_length; i++) {
		if (arr[i] < MIN_NUM || arr[i] > MAX_NUM)
			return true;
	}

	return false;
}

bool Homework::CheckOverlap(uint* arr, uint arr_length)
{
	bool did[MAX_NUM] = { false };

	for (uint i = 0; i < arr_length; i++) {
		if (did[arr[i]-1])
			return true;	//�ߺ� ����
		did[arr[i]-1] = true;
	}
	return false;
}


void Homework::GetInputSet(uint* arr, uint arr_length, bool overlap)
{
	for (int i = 0; i < arr_length; i++)
		arr[i] = 0;

	while (1) {
		printf("%d���� ���ڸ� �Է��Ͻÿ�(%d~%d)", ARR_SIZE, MIN_NUM, MAX_NUM);
		printf((overlap ? "(�ߺ� ����)\n" : "(�ߺ� ����)\n"));
		printf("-> ");
		for (int i = 0; i < arr_length; i++)
			scanf_s("%d", arr + i);
		

		if (CheckInvalid(arr, arr_length)) {
			printf("���� ���� ���ڰ� �ֽ��ϴ�. �ٽ� �Է��Ͻÿ�\n");
			continue;
		}

		if (!overlap && CheckOverlap(arr, arr_length)) {
			printf("�ߺ��� ���ڰ� �ֽ��ϴ�. �ٽ� �Է��Ͻÿ�\n");
			continue;
		}

		break;
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
	bool isIn[9] = {false};

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

bool Homework::PrintAttackResult(const int& strike, const int& ball)
{
	if (strike == 3) {
		printf("3 ��Ʈ����ũ!\n");
		return true;
	}

	if (IsOut(strike, ball))
		printf("�ƿ�!");
	else {
		if (strike > 0)
			printf("%d ��Ʈ����ũ ", strike);
		if (ball > 0)
			printf("%d ��", ball);
	}
	printf("\n");
	return false;
}

void Homework::PrintGameResult(int out)
{
	if (out == GAME_OVER)
		//�й�
		printf("���� ����....\n");
	
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

void Homework::Game(int chance, bool overlap)
{
	uint arr_rand[3] = {}, arr_input[3] = {};
	MakeRandSet(arr_rand, ARR_SIZE, overlap);
#ifdef TEST
	printf("Test : ");
	PrintArr(arr_rand, ARR_SIZE);
	printf("\n");
#endif // TEST
	printf("[���� ����]\n");

	int strike = 0, ball = 0;
	int cntAnswer = 0;
	while (cntAnswer != GAME_OVER) {
		printf("���� ��ȸ : %d��\n", GAME_OVER - cntAnswer);
		GetInputSet(arr_input, ARR_SIZE, overlap);
		printf("%d�� �õ� : ", ++cntAnswer);
		PrintArr(arr_input, ARR_SIZE);
		printf(" => ");
		CompareArr(strike, ball, arr_rand, arr_input);
		if (PrintAttackResult(strike, ball))
			break;
	}
	PrintGameResult(cntAnswer);
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
	srand((uint)time(NULL));
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
