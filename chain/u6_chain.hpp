#pragma once

#include "linearlist.h"
#include "chainNode.h"




/*
 链表实现
*/
template<class T>
class Chain :public LinearList<T>
{
public:
	class iterator;
public:
	Chain(int initialCapacity = 10);
	Chain(const Chain<T>&);
	~Chain();

public:
	bool empty()const { return listSize == 0; }
	int size()const { return listSize; }
	T& get(int theIndex)const;
	int indexOf(const T& theElement)const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(std::ostream& out)const;

	void push_front(const T& theElement);
	void reverse();
	iterator begin() { return iterator(firstNode); }
	iterator end() { return iterator(nullptr); }
protected:
	void checkIndex(int theIndex)const;
	ChainNode<T>* firstNode;
	int listSize;
};

template<class T>
void Chain<T>::reverse()
{
	//逆序->其实就是把节点->next的指向一点点反过来
	ChainNode<T>* preNode = firstNode;
	ChainNode<T>* curNode = firstNode->next;
	ChainNode<T>* nextNode = nullptr;

	while (curNode != nullptr)
	{
		nextNode = curNode->next;
		curNode->next = preNode;
		preNode = curNode;
		curNode = nextNode;
	}
	//改一下头节点
	firstNode->next = nullptr;
	firstNode = preNode;
}

template<class T>
class Chain<T>::iterator
{
public:
	iterator(ChainNode<T>* theNode = nullptr) { node = nullptr; }

	T& operator*()const { return node->element; }
	T* operator->()const { return &node->element; }

	//前++
	iterator& operator++()
	{
		node = node->next;
		return *this;
	}
	//后++
	iterator& operator++(int)
	{
		iterator old = this;
		node = node->next;
		return old;
	}

	bool operator!=(const iterator right)const
	{
		return node != right.node;
	}
	bool operator==(const iterator right)const
	{
		return node == right.node;
	}
protected:
	ChainNode<T>* node;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& x)
{
	x.output(out);
	return out;
}

template<class T>
void Chain<T>::checkIndex(int theIndex) const
{
	if (theIndex<0 || theIndex>listSize)
	{
		//
		throw;
	}
}

template<class T>
Chain<T>::Chain(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		throw;
	}

	firstNode = nullptr;
	listSize = 0;
}

template<class T>
Chain<T>::Chain(const Chain<T>& theList)
{
	listSize = theList.listSize;

	if (listSize == 0)
	{
		firstNode = nullptr;
		return;
	}
	//首元素申请空间
	ChainNode<T>* sourceNode = theList.firstNode;
	firstNode = new ChainNode<T>(sourceNode->element);
	
	sourceNode = sourceNode->next;
	ChainNode<T>* targetNode = firstNode;

	while (sourceNode != nullptr)
	{
		targetNode->next = new ChainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = nullptr;
}

template<class T>
Chain<T>::~Chain()
{
	while (firstNode != nullptr)
	{
		ChainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}

template<class T>
T& Chain<T>::get(int theIndex) const
{
	//返回索引所在的元素
	checkIndex(theIndex);

	ChainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex; ++i)
		currentNode = currentNode->next;

	return currentNode->element;
}

template<class T>
int Chain<T>::indexOf(const T& theElement) const
{
	//返回元素首次出现的索引
	ChainNode<T>* currentNode = firstNode;
	int index = 0;
	while (currentNode != nullptr
		&&currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		index++;
	}

	return (currentNode != nullptr ? 
		index : -1);
}


template<class T>
void Chain<T>::erase(int theIndex)
{
	//删除索引所在元素
	checkIndex(theIndex);

	ChainNode<T>* deleteNode;
	if (theIndex == 0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		ChainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; ++i)
			p = p->next;

		deleteNode = p->next;
		p->next = p->next->next;
	}
	listSize--;
	delete deleteNode;
}


template<class T>
void Chain<T>::insert(int theIndex, const T& theElement)
{
	//在索引所在处插入元素
	checkIndex(theIndex);
	
	if (theIndex == 0)
	{
		firstNode = new ChainNode<T>(theElement, firstNode);
	}
	else
	{
		ChainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; ++i)
			p = p->next;

		p->next = new ChainNode<T>(theElement, p->next);
	}
	listSize++;
}


template<class T>
void Chain<T>::output(std::ostream& out) const
{
	ChainNode<T>* currentNode = firstNode;
	while (currentNode != nullptr)
	{
		out << currentNode->element << ' ';
		currentNode = currentNode->next;
	}
}


template<class T>
void Chain<T>::push_front(const T& theElement)
{
	auto* newNode = new ChainNode<T>(theElement, firstNode);
	firstNode = newNode;
}



