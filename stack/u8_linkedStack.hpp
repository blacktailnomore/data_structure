#pragma once

#include "stack.h"
#include "chainNode.h"

/*
ջ ������ʽ
*/
template<class T>
class LinkedStack :public Stack<T>
{
public:
	LinkedStack(int initialCapacity = 10);
	~LinkedStack();
public:
	bool empty()const { return stackSize == 0; }
	int size()const { return stackSize; }
	T& top();
	void pop();
	void push(const T& theElement);
protected:
	ChainNode<T>* stackTop;		//ջ��ָ��
	int stackSize;
};

template<class T>
void LinkedStack<T>::push(const T& theElement)
{
	stackTop = new ChainNode<T>(theElement, stackTop);
	stackSize++;
}

template<class T>
void LinkedStack<T>::pop()
{
	if (stackSize == 0)
	{
		//
		throw;
	}
	//����ͷ��ջ��
	auto* nextNode = stackTop->next;
	delete stackTop;
	stackTop = nextNode;
	stackSize--;
}

template<class T>
T& LinkedStack<T>::top()
{
	if (stackSize == 0)
	{
		//
		throw;
	}
	
	return stackTop->element;
}

template<class T>
LinkedStack<T>::LinkedStack(int initialCapacity /*= 10*/)
{
	stackTop = nullptr;
	stackSize = 0;
}

template<class T>
LinkedStack<T>::~LinkedStack()
{
	while (stackTop != nullptr)
	{
		auto* nextNode = stackTop->next;
		delete stackTop;
		stackTop = nextNode;
	}
}

