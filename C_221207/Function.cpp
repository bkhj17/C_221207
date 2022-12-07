#include "Function.h"
#include <stdio.h>

void Function::Run()
{
	int x = 10, y = 20;
	printf("x : %d, y : %d\n", x, y);
	Function::Add(x, y);		//값이 들어간 경우 => 함수 밖에 영향x
	printf("x : %d, y : %d\n", x, y);
	Function::Add2(x, y);		//참조로 들어간 경우 => 함수 밖에서도 변한다
	printf("x : %d, y : %d\n", x, y);
	Function::Add3(&x, &y);		//포인터가 들어간 경우도 함수 밖에서도 변한다
	printf("x : %d, y : %d\n", x, y);
	Function::Add4(x, y);		//const 참조로 들어간 인수는 변경 불가 : 값을 넘기는거 보다 효율적
	printf("x : %d, y : %d\n", x, y);
	//Function::Add4(10, 20);	//단 이 경우 값을 직접 인수로 줄 수 없다
}
