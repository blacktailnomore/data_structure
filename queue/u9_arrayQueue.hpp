#pragma once

#include "queue.h"


/*
���νṹ�Ķ���
*/

template<class T>
class ArrayQueue :public Queue<T>
{
public:
	ArrayQueue(int initialCapacity=10);
	ArrayQueue(const ArrayQueue<T>&);
	~ArrayQueue() { delete[] queue; }
public:
	bool empty()const { return queueFront == queueBack; }//�������Ԫ����=queuesize-1
	int size()const { return queueSize - 1; }
	T& front() { return queue[queueFront]; }
	T& back() { return queue[queueBack-1]; }
	void pop();
	void push(const T& theElement);

	void output(std::ostream& out)const;
protected:
	T * queue;
	int queueFront;		//����λ�ò���һ�������±�0
	int queueBack;		//��β
	int queueSize;		
};


template<class T>
ArrayQueue<T>::ArrayQueue(int initialCapacity)
	:queueFront(0),queueBack(0),queueSize(initialCapacity)
{
	if (queueSize < 0)throw;

	queue = new T[queueSize];
}

template<class T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& theQueue)
{
 	queueSize = theQueue.queueSize;
 	queueFront = theQueue.queueFront;
 	queueBack = theQueue.queueBack;
 	queue = new T[queueSize];
 	std::copy(theQueue.queue, theQueue.queue + queueSize, queue);
}


template<class T>
void ArrayQueue<T>::pop()
{
	if (empty())
	{
		//
		throw;
	}
	//ɾ��һ��Ԫ�� FIFO
	queueFront = (queueFront + 1) % queueSize;
	queue[queueFront].~T();
}


template<class T>
void ArrayQueue<T>::push(const T& theElement)
{
	//������
	if ((queueBack + 1) % queueSize == queueFront)
	{
		T* newQueue = new T[2 * queueSize];

		int start = (queueFront + 1) % queueSize;
		if (start < 2)
			std::copy(queue + start, queue + queueSize, newQueue);
		else
		{
			std::copy(queue + start, queue + queueSize, newQueue);
			std::copy(queue, queue + queueBack + 1, newQueue + queueSize - start);
		}

		//�����µ��׺�β
		queueFront = 2 * queueSize - 1;
		queueBack = queueSize - 2;
		queueSize *= 2;
		
		delete[] queue;
		queue = newQueue;
	}
	
}


template<class T>
void ArrayQueue<T>::output(std::ostream& out) const
{
	auto index = queueFront;
	for (; index < queueBack; ++index)
	{
		out << queue[index] << ' ';
	}
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const ArrayQueue<T>& x)
{
	x.output(out);
	return out;
}