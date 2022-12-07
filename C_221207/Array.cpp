#include "Array.h"

void Array::Run()
{
	int arr[] = {1, 2, 3, 4};
	int arrLength = sizeof(arr) / sizeof(int);
	printf("arr size : %d\n", arrLength);	//배열 사이즈 = 배열 개수 * 자료형 크기
	//배열은 매개변수로 넘길때 시작주소가 들어가기 때문에 따로 함수 만들어봐야 소용없다
	//=> 배열을 매개변수로 넘길때 길이도 같이 보내주자

	for (int i = 0; i < arrLength; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
		printf("&arr[%d] = %d\n", i, &arr[i]);
	}

	printf("arr : %d\n", arr);	//배열 시작주소 == arr[0]

	int* p = arr;	//배열 시작 주소를 참조
	printf("arr : %d\n", p[3]);
}
