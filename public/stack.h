#pragma once

/*
Õ»³éÏó»ùÀà
*/
template<class T>
class Stack
{
public:
	virtual ~Stack() {}
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual T& top() = 0;
	virtual void pop() = 0;
	virtual void push(const T& theElement) = 0;
};