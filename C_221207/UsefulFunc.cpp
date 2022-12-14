#include "UsefulFunc.h"
#include <stdlib.h>
#include <time.h>
template <typename T>
T Min(const T& a, const T& b) {
	return a < b ? a : b;
}

template <typename T>
T Max(const T& a, const T& b) {
	return a > b ? a : b;
}

template <typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
void Swap(T* a, T* b)	//?ּ? ????
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

uint MakeRandByRange(uint a, uint b)
{
	uint mn = Min(a, b), mx = Max(a, b);
	return rand() % (mx - mn + 1) + mn;
}

void Shuffle(uint* arr, const uint& arr_length, const uint& n_shuffle)
{
	for (uint i = 0; i < n_shuffle; i++) {
		uint a, b;
		a = MakeRandByRange(0, arr_length - 1);
		b = MakeRandByRange(0, arr_length - 1);
		Swap(arr[a], arr[b]);
	}
}

void GetRandomsNoOverlap(uint* arr, const uint& arr_length, const uint& num) {
	int pos = 0;
	for (uint cnt = 0; cnt < num; cnt++) {
		pos = MakeRandByRange(cnt, arr_length-1);
		Swap(arr[cnt], arr[pos]);
	}
}