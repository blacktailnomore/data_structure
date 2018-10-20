#pragma once

/*
Á´±í½Úµã
*/
template<class T>
struct ChainNode
{
	T element;
	ChainNode<T>* next;

	ChainNode() {}
	ChainNode(const T& element) { this->element = element; next = nullptr; }
	ChainNode(const T& element, ChainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
};