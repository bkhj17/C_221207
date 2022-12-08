#include "Pointer.h"
#include "UsefulFunc.h"
#include <stdio.h>

int Pointer::TestPtr()
{
	int n = 10;
	int* pN;	//포인터 선언 : 초기값 nullptr
	pN = &n;
	//int * pN;
	//int *pN;
	//int*pN;
	//포인터 : 메모리에 저장된 변수의 주소를 저장하는 변수

	if (pN == nullptr)
		return 0;
	printf("n : %d\n", n);		//변수의 값을 출력
	printf("&n : %d\n", &n);	//변수의 주소를 출력
	printf("pN : %d\n", pN);	//주소를 출력
	printf("*pN : %d\n", *pN);	//주소에 기록된 변수를 참조

	*pN = 20;
	//	*pN++;						//연산자 우선순위 탓에 주소가 먼저 증가한다
	//	printf("pn : %d\n", pN);	//주소는 ++하면 다음변수 주소가 나온다
	(*pN)++;					//우선순위 헷갈리면 괄호 치자
	printf("n : %d\n", n);

	printf("pN size : %d\n", sizeof(pN));	//x86(32bit) : 4byte, x64(64bit) : 8byte
	//double : 둘 다 8byte

	int x = 10, y = 20;
	//Swap(x, y);
	printf("x : %d, y : %d\n", x, y);
	//Swap(&x, &y);
	printf("x : %d, y : %d\n", x, y);

	return 0;
}

void Pointer::Run()
{
	TestPtr();
}