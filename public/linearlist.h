#pragma once


/*
一个线性表的抽象类
*/
template<class T>
class LinearList
{
public:
	virtual ~LinearList() {}
	//检查是否为空
	virtual bool empty()const = 0;
	//元素个数
	virtual int size()const = 0;
	//根据索引返回元素
	virtual T& get(int theIndex)const = 0;
	//返回元素第一次出现的索引
	virtual int indexOf(const T& theElement)const = 0;
	//根据索引删除元素
	virtual void erase(int theIndex) = 0;
	//指定索引插入元素
	virtual void insert(int theIndex, const T& theElement) = 0;
	//输出
	virtual void output(std::ostream& out)const = 0;
};