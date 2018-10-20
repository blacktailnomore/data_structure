#pragma once

#include "queue.h"
#include "chainNode.h"

/*
队列 链表形式
*/
template<class T>
class LinkedQueue :public Queue<T>
{
public:
	LinkedQueue(int initialCapacity = 10);
	LinkedQueue(const LinkedQueue<T>&);
	~LinkedQueue();
private:
	bool empty()const { return queueFront == nullptr; }
	bool size()const { return queueSize; }
	T& front() { return queueFront->element; }
	T& back() { return queueBack->element; }
	void pop();
	void push(const T& theElement);
private:
	ChainNode<T>* queueFront;
	ChainNode<T>* queueBack;
	int queueSize;
};

template<class T>
LinkedQueue<T>::LinkedQueue(int initialCapacity /*= 10*/)
	:queueFront(nullptr), queueBack(nullptr), queueSize(0)
{

}

template<class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& theQueue)
{
	queueSize = theQueue.queueSize;

	if (queueSize == 0)
	{
		queueFront = queueBack = nullptr;
		return;
	}

	ChainNode<T>* sourceNode = theQueue.queueFront;
	queueFront = new ChainNode<T>(sourceNode->element);

	sourceNode = sourceNode->next;
	ChainNode<T>* targetNode = queueFront;

	while (sourceNode != nullptr)
	{
		targetNode->next = new ChainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	queueBack = targetNode;
	queueBack->next = nullptr;
}


template<class T>
LinkedQueue<T>::~LinkedQueue()
{
	while (queueFront != nullptr)
	{
		ChainNode<T>* nextNode = queueFront->next;
		delete queueFront;
		queueFront = nextNode;
	}
}


template<class T>
void LinkedQueue<T>::pop()
{
	if (queueFront == nullptr)
	{
		//
		throw;
	}
	ChainNode<T>* nextNode = queueFront->next;
	delete queueFront;
	queueFront = nextNode;
	queueSize--;
}


template<class T>
void LinkedQueue<T>::push(const T& theElement)
{
	ChainNode<T>* newNode = new ChainNode<T>(theElement, nullptr);

	if (queueSize == 0)
		queueFront = newNode;
	else
		queueBack->next = newNode;
	
	queueBack = newNode;
	queueSize++;
}
