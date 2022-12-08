#include "Pointer.h"
#include "UsefulFunc.h"
#include <stdio.h>

int Pointer::TestPtr()
{
	int n = 10;
	int* pN;	//������ ���� : �ʱⰪ nullptr
	pN = &n;
	//int * pN;
	//int *pN;
	//int*pN;
	//������ : �޸𸮿� ����� ������ �ּҸ� �����ϴ� ����

	if (pN == nullptr)
		return 0;
	printf("n : %d\n", n);		//������ ���� ���
	printf("&n : %d\n", &n);	//������ �ּҸ� ���
	printf("pN : %d\n", pN);	//�ּҸ� ���
	printf("*pN : %d\n", *pN);	//�ּҿ� ��ϵ� ������ ����

	*pN = 20;
	//	*pN++;						//������ �켱���� ſ�� �ּҰ� ���� �����Ѵ�
	//	printf("pn : %d\n", pN);	//�ּҴ� ++�ϸ� �������� �ּҰ� ���´�
	(*pN)++;					//�켱���� �򰥸��� ��ȣ ġ��
	printf("n : %d\n", n);

	printf("pN size : %d\n", sizeof(pN));	//x86(32bit) : 4byte, x64(64bit) : 8byte
	//double : �� �� 8byte

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