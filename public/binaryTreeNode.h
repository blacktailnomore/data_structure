#pragma once

/*
¶þ²æÊ÷½Úµã
*/

template<class T>
struct BinaryTreeNode
{
	T element;
	BinaryTreeNode<T>* leftChild;
	BinaryTreeNode<T>* rightChild;

	BinaryTreeNode()
		:leftChild(nullptr),rightChild(nullptr)
	{}
	BinaryTreeNode(const T& theElement)
		:element(theElement),leftChild(nullptr),rightChild(nullptr)
	{}
	BinaryTreeNode(const T& theElement,BinaryTreeNode<T>* theLeftChild,BinaryTreeNode<T>* theRightChild)
		:element(theElement),leftChild(theLeftChild),rightChild(theRightChild)
	{}
};