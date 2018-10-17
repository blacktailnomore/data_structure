#pragma once

#include "utility.h"
#include "stack.h"

/*

*/

/*
ArrayStack
栈 数组实现
*/
template<class T>
class ArrayStack :public Stack<T>
{
public:
	ArrayStack(int initialCapacity = 10);
	~ArrayStack() { delete[] stack; }
public:
	bool empty()const { return stackTop == -1; }
	int size()const { return stackTop + 1; }
	T& top();
	void pop();

	void push(const T& theElement);
private:
	int stackTop;		//栈顶下标
	int arrayLength;	//栈长度
	T* stack;
};

template<class T>
ArrayStack<T>::ArrayStack(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		throw;
	}
	arrayLength = initialCapacity;
	stack = new T[arrayLength];
	stackTop = -1;
}


template<class T>
T& ArrayStack<T>::top()
{
	if (stackTop == -1)
	{
		//
		throw;
	}
	return stack[stackTop];
}


template<class T>
void ArrayStack<T>::pop()
{
	if (stackTop == -1)
	{
		//
		throw;
	}
	stack[stackTop--].~T();
}

template<class T>
void ArrayStack<T>::push(const T& theElement)
{
	if (stackTop == arrayLength - 1)
	{
		//容量不够
		changeLength1D(stack, arrayLength, 2 * arrayLength);
		arrayLength *= 2;
	}
	stack[++stackTop] = theElement;
}












