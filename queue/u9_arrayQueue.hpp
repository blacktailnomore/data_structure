#pragma once

#include "queue.h"


/*
环形结构的队列
*/

template<class T>
class ArrayQueue :public Queue<T>
{
public:
	ArrayQueue(int initialCapacity=10);
	ArrayQueue(const ArrayQueue<T>&);
	~ArrayQueue() { delete[] queue; }
public:
	bool empty()const { return queueFront == queueBack; }//数组最大元素数=queuesize-1
	int size()const { return queueSize - 1; }
	T& front() { return queue[queueFront]; }
	T& back() { return queue[queueBack-1]; }
	void pop();
	void push(const T& theElement);

	void output(std::ostream& out)const;
protected:
	T * queue;
	int queueFront;		//队首位置并不一定代表下标0
	int queueBack;		//队尾
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
	//删除一个元素 FIFO
	queueFront = (queueFront + 1) % queueSize;
	queue[queueFront].~T();
}


template<class T>
void ArrayQueue<T>::push(const T& theElement)
{
	//快满了
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

		//设置新的首和尾
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