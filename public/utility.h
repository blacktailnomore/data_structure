#pragma once



/*
一些公用函数
*/

#include <algorithm>

/*
改变一个一维数组长度
*/
template<typename T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
	if (newLength < 0)
		return;

	T* temp = new T[newLength];
	int number = std::min(oldLength, newLength);
	std::copy(a, a + number, temp);
	delete[] a;
	a = temp;
}


