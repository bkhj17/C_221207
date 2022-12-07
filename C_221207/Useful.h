#pragma once
typedef unsigned uint;

template <typename T>
T Min(const T&, const T&);

template <typename T>
T Max(const T& a, const T& b);

template <typename T>
void Swap(T& a, T& b);

template <typename T>
void Swap(T* a, T* b);

uint MakeRandByRange(uint a, uint b);
void Shuffle(uint* arr, const uint& arr_length, const uint& n_shuffle);