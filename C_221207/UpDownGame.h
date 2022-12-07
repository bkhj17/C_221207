#pragma once
#include "Base.h"


class UpDownGame :
    public Base
{
    enum class GameResult
    {
        NONE, CLEAR, OVER
    };

    const int MIN_RANGE = 10;
    const int MAX_RANGE = 100;
    const int MAX_ATTEMP_NUM = 10;
private:
    bool Game(int stage);
    int GetRandomRange(const int&, const int&);
    int GetPlayerInputNum(const int&, const int&);
    GameResult GetGameResult(const int&, const int&, int&);
    bool isAnswer(const int&, const int&);
    void PrintGameResult(const GameResult&);
public:
    // Base��(��) ���� ��ӵ�
    virtual void Run() override;
};
