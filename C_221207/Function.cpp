#include "Function.h"
#include <stdio.h>

void Function::Run()
{
	int x = 10, y = 20;
	printf("x : %d, y : %d\n", x, y);
	Function::Add(x, y);		//���� �� ��� => �Լ� �ۿ� ����x
	printf("x : %d, y : %d\n", x, y);
	Function::Add2(x, y);		//������ �� ��� => �Լ� �ۿ����� ���Ѵ�
	printf("x : %d, y : %d\n", x, y);
	Function::Add3(&x, &y);		//�����Ͱ� �� ��쵵 �Լ� �ۿ����� ���Ѵ�
	printf("x : %d, y : %d\n", x, y);
	Function::Add4(x, y);		//const ������ �� �μ��� ���� �Ұ� : ���� �ѱ�°� ���� ȿ����
	printf("x : %d, y : %d\n", x, y);
	//Function::Add4(10, 20);	//�� �� ��� ���� ���� �μ��� �� �� ����
}
