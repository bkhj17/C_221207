#include "UpDownGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define TEST

void UpDownGame::Run()
{ 
	srand((unsigned int)time(NULL));
	for(int i = 1; i <= 5; i++)
		if (!Game(i))
			break;
}

bool UpDownGame::Game(int stage)
{
	const int MIN_RANGE = stage == 1 ? 10 : 1;
	const int MAX_RANGE = 100 * stage;
	const int MAX_ATTEMP_NUM = 10 - stage;

	printf("Up&DownGame Start!\n");

	int randomNum = GetRandomRange(MIN_RANGE, MAX_RANGE);
#ifdef TEST
	printf("RandomNum : %d\n", randomNum);
#endif // TEST
	int playerNum;
	int attemp_num = MAX_ATTEMP_NUM;
	GameResult result = GameResult::NONE;

	while (true) {
		playerNum = GetPlayerInputNum(MIN_RANGE, MAX_RANGE);
		printf("InputNum : %d\n", playerNum);
		result = GetGameResult(playerNum, randomNum, attemp_num);
	}

	PrintGameResult(result);
	return result == GameResult::CLEAR;
}

int UpDownGame::GetRandomRange(const int& minRange, const int& maxRange) {
	return rand() % (maxRange - minRange + 1) + minRange;
}

int UpDownGame::GetPlayerInputNum(const int& minRange, const int& maxRange)
{
	int input_num = 0;
	while (true) {
		printf("%d부터 %d까지의 숫자을 입력하시오 ->", minRange, maxRange);
		scanf_s("%d", &input_num);

		if (minRange <= input_num && input_num <= maxRange)
			return input_num;
		else
			printf("입력한 숫자가 범위 밖입니다.\n");
	}
	return input_num;
}

UpDownGame::GameResult UpDownGame::GetGameResult(const int& playerNum, const int& randomNum, int& attemp_num)
{
	if (isAnswer(playerNum, randomNum))
		return GameResult::CLEAR;
	else {
		attemp_num++;
		printf("남은 횟수 : %d\n", attemp_num);
	}

	if (attemp_num == 0)
		return GameResult::OVER;
	
	return GameResult::NONE;
}

bool UpDownGame::isAnswer(const int& inputNum, const int& randomNum)
{
	if (inputNum == randomNum)
		return true;
	else if (inputNum > randomNum)
		printf("정답보다 큼\n");
	else
		printf("정답보다 작음\n");

	return false;
}

void UpDownGame::PrintGameResult(const GameResult& result) {
	switch (result)
	{
	case UpDownGame::GameResult::NONE:
		break;
	case UpDownGame::GameResult::CLEAR:
		printf("Game Clear!\n");
		break;
	case UpDownGame::GameResult::OVER:
		printf("Game Over...\n");
		break;
	default:
		break;
	}
}