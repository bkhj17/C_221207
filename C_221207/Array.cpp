#include "Array.h"

void Array::Run()
{
	int arr[] = {1, 2, 3, 4};
	int arrLength = sizeof(arr) / sizeof(int);
	printf("arr size : %d\n", arrLength);	//�迭 ������ = �迭 ���� * �ڷ��� ũ��
	//�迭�� �Ű������� �ѱ涧 �����ּҰ� ���� ������ ���� �Լ� �������� �ҿ����
	//=> �迭�� �Ű������� �ѱ涧 ���̵� ���� ��������

	for (int i = 0; i < arrLength; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
		printf("&arr[%d] = %d\n", i, &arr[i]);
	}

	printf("arr : %d\n", arr);	//�迭 �����ּ� == arr[0]

	int* p = arr;	//�迭 ���� �ּҸ� ����
	printf("arr : %d\n", p[3]);
}
