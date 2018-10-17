#pragma once

#include "utility.h"
#include "linearlist.h"

#include <iterator>
#include <sstream>
#include <cstddef>

//���Ա� �������� ��������

/*
��arrayList
*/
template<class T>
class ArrayList :public LinearList<T>
{
public:
	class iterator;
public:
	ArrayList(int initialCapacity = 10);
	ArrayList(const ArrayList<T>& theList)
	{
		arrayLength = theList.arrayLength;
		listSize = theList.listSize;
		element = new T[arrayLength];
		std::copy(theList.element, theList.element + listSize, element);
	}

	~ArrayList() { delete[] element; }


	T& operator[](int theIndex)const;
	bool operator==(const ArrayList<T>& other)const;
	bool operator!=(const ArrayList<T>& other)const;
	bool operator<(const ArrayList<T>& other)const;
public:
	bool empty()const { return listSize == 0; }
	int size()const { return listSize; }
	T& get(int theIndex)const
	{
		checkIndex(theIndex);
		return element[theIndex];
	}
	int indexOf(const T& theElement)const
	{
		int theIndex = (int)(std::find(element, element + listSize, theElement) - element);

		return (theIndex == listSize ? 
			-1 : theIndex);
	}
	void erase(int theIndex)
	{
		//std::vector��ɾ��һ��Ԫ��ʱ��ֻ�ǰ�Ԫ������λ�ú��������Ԫ����λ����ռ���ڴ�ռ䲢û�м�С
		checkIndex(theIndex);

		std::copy(element + theIndex + 1, element + listSize, element + theIndex);
		element[--listSize].~T();
	}
	void erase(int theIndex, bool isReduce);

	void insert(int theIndex,const T& theElement)
	{
		if (theIndex<0 || theIndex>listSize)
		{
			std::ostringstream s;
			s << "index= " << theIndex << " size= " << listSize;
			throw;
		}

		//������������������·���ռ�
		if (listSize == arrayLength)
		{
			changeLength1D(element, arrayLength, 2 * arrayLength);
			arrayLength *= 2;
		}

		std::copy_backward(element + theIndex, element + listSize, element + listSize + 1);
		element[theIndex] = theElement;
		listSize++;
	}
	void output(std::ostream& out)const
	{
		std::copy(element, element + listSize, std::ostream_iterator<T>(out, " "));
	}
	int capacity()const { return arrayLength; }

	T* data()const { return element; }

	void trimToSize();
	void setSize(int theSize,int theCapacity);
	ArrayList<T>& push_back(const T& theElement);
	ArrayList<T>& pop_back();
	void swap(ArrayList<T>& theList);
	void reserve(int theCapacity);
	T set(int theIndex, const T& theElement);
	void clear();
	void leftShift(int theIndex);
	void removeRange(int theBegin, int theEnd);
	int lastIndexOf(const T& theElement)const;
	void reverse();
	void half();
	iterator begin() { return iterator(element); }
	iterator end() { return iterator(element + listSize); }
protected:
	void checkIndex(int theIndex)const
	{
		if (theIndex < 0 || theIndex >= listSize)
		{
			std::ostringstream s;
			s << "index= " << theIndex << " size= " << listSize;
			throw;
		}
	}

	T* element;
	int arrayLength;
	int listSize;
};


template<class T>
class ArrayList<T>::iterator
{
public:
	using iterrrator_catefoty = std::bidirectional_iterator_tag;
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using pointer = T * ;
	using reference = T & ;
public:
	iterator(T* thePosition = 0) { position = thePosition; }

	//�����ò�����
	T& operator*()const { return *position; }
	T* operator->()const { return position; }
	//��������
	///ǰ
	iterator& operator++() { ++position; return *this; }
	///��
	iterator operator++(int)
	{
		iterator old = *this;
		++position;
		return old;
	}
	//��������
	///ǰ
	iterator& operator--() { --position; return *this; }
	///��
	iterator operator--(int)
	{
		iterator old = *this;
		--position;
		return old;
	}

	bool operator!=(const iterator right)const
	{
		return position != right.position;
	}
	bool operator==(const iterator right)const
	{
		return position == right.position;
	}
protected:
	T* position;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const ArrayList<T>& x)
{
	x.output(out);
	return out;
}

/*
��ϰ3
*/
template<typename T>
void changeLength2D(T** a, int oldRowLength,int newRowLength,int oldColumnLength,int newColumnLength)
{
	if (newRowLength < 0 || newColumnLength < 0)
	{
		return;
	}

	//������ռ�
	T** temp = new T*[newRowLength];
	for (int i = 0; i < newRowLength; ++i)
	{
		temp[i] = new T[newColumnLength];
	}

	//�������� ȡ�н�С��ֵ���� ���������л���û��ԭ���Ĵ�ͻ�����ڴ����
	int rowLength = std::min(oldRowLength, newRowLength);
	int columnLength = std::min(oldColumnLength, newColumnLength);
	for (int i = 0; i < rowLength; ++i)
	{
		std::copy(a[i], a[i] + columnLength, temp[i]);
	}

	for (int i = 0; i < oldRowLength; ++i)
	{
		delete[] a[i];
	}
	delete[] a;
	a = temp;
}

/*
��ϰ4
*/
template<class T>
ArrayList<T>::ArrayList(int initialCapacity)
{
	if (initialCapacity < 0)
	{
		//�쳣����
		throw;
	}
	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;
}

/*
��ϰ5
*/
template<class T>
void ArrayList<T>::trimToSize()
{
	if (listSize == arrayLength)
		return;

	T* temp = new T[listSize];
	std::copy(element, element + listSize, temp);
	delete[] element;
	element = temp;
	arrayLength = listSize;
}

/*
��ϰ6
*/
template<class T>
void ArrayList<T>::setSize(int theSize, int theCapacity)
{
	if (theSize < 0 || theCapacity < 0 || theSize > theCapacity)
	{
		//�쳣����
		return;
	}

	if (theSize >= listSize)
		return;

	T* temp = new T[theCapacity];
	std::copy(element, element + theSize, temp);
	delete[] element;
	element = temp;
	listSize = theSize;
	arrayLength = theCapacity;
}

/*
��ϰ7
*/
template<class T>
T& ArrayList<T>::operator[](int theIndex)const
{
	checkIndex(theIndex);

	return element[theIndex];
}

/*
��ϰ8
*/
template<class T>
bool ArrayList<T>::operator==(const ArrayList<T>& other)const
{
	int theSize = std::min(listSize, other.listSize);

	int i;
	for (i = 0; i < theSize && element[i] == other.element[i]; ++i);

	return (i == theSize);
}

/*
��ϰ9
*/
template<class T>
bool ArrayList<T>::operator!=(const ArrayList<T>& other)const
{
	return !(*this == other);
}

/*
��ϰ10
*/
template<class T>
bool ArrayList<T>::operator<(const ArrayList<T>& other)const
{
	int theSize = std::min(listSize, other.listSize);

	int i;
	for (i = 0; i < theSize && element[i] < other.element[i]; ++i);

	return (i == theSize);
}

/*
��ϰ11
*/
template<class T>
ArrayList<T>& ArrayList<T>::push_back(const T& theElement)
{
	if (listSize == arrayLength)
	{
		changeLength1D(element, arrayLength, arrayLength * 2);
		arrayLength *= 2;
	}

	element[listSize++] = theElement;

	return *this;
}

/*
��ϰ12
*/
template<class T>
ArrayList<T>& ArrayList<T>::pop_back()
{
	element[--listSize].~T();

	return *this;
}

/*
��ϰ13
size��capacityҲҪ����
*/
template<class T>
void ArrayList<T>::swap(ArrayList<T>& theList)
{
	int theSize = theList.size();
	int theCapacity = theList.capacity();

	

}

/*
��ϰ14
*/
template<class T>
void ArrayList<T>::reserve(int theCapacity)
{
	arrayLength = std::max(theCapacity, arrayLength);

	T* temp = new T[arrayLength];

	std::copy(element, element + listSize, temp);
	delete[] element;
	element = temp;
}

/*
��ϰ15
*/
template<class T>
T ArrayList<T>::set(int theIndex, const T& theElement)
{
	checkIndex(theIndex);

	T tmp = element[theIndex];
	element[theIndex] = theElement;
	
	return tmp;
}

/*
��ϰ16
*/
template<class T>
void ArrayList<T>::clear()
{
	delete[] element;
}

/*
��ϰ17
���ҿ�
*/
template<class T>
void ArrayList<T>::removeRange(int theBegin, int theEnd)
{
	//ֱ��ʹ���Լ�ʵ�ֵ�eraseһ����ɾ��Ч��̫�ͣ�ɾ��һ����Ҫȫ��Ų��һ��
	checkIndex(theBegin);
	checkIndex(theEnd);

	T* temp = new T[arrayLength];
	std::copy(element, element + theBegin, temp);
	std::copy(element + theEnd - 1, element + listSize, temp + theBegin);
	delete[] element;
	element = temp;
	listSize -= theEnd - theBegin - 1;
}

/*
��ϰ18
*/
template<class T>
int ArrayList<T>::lastIndexOf(const T& theElement)const
{
	int i;
	for (i = listSize - 1; i >= 0 && element[i] != theElement; --i);

	return (i > -1 ? 
		i : -1);
}

/*
��ϰ20
*/
template<class T>
void ArrayList<T>::erase(int theIndex, bool isReduce)
{
	if (listSize - 1 < arrayLength / 4)
	{

	}
}

/*
��ϰ22 1)
*/
template<class T>
void ArrayList<T>::reverse()
{
	if (empty()) return;
	//int i = 0;
	//int j = listSize - 1;
	//while (i != j)
	//{
	//	element[i] += element[j];
	//	element[j] = element[i] - element[j];
	//	element[i] -= element[j];
	//	i++;
	//	j--;
	//}
	iterator first = begin();
	iterator last = end();
	while ((first != last) && (first != --last))
	{
		std::iter_swap(first++, last);
	}
}

/*
��ϰ23
*/

template<class T>
void ArrayList<T>::leftShift(int theIndex)
{

}

/*
��ϰ24	����ʹ�ó�Ա����
*/
template<class T>
void ArrayList<T>::half()
{
	//
	T* tmp = new T[arrayLength];
	int index = 0;
	int size = listSize;
	for (int i = 0; i < size; ++i)
	{
		if (i % 2 == 0)
		{
			tmp[index++] = element[i];
		}
		else listSize--;
	}
	delete[] element;
	element = tmp;
}

//ʣ��...






