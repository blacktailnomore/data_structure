#pragma once

#include "binaryTreeNode.h"

/*
����������
*/
template<class T>
class BinaryTree
{
public:
	virtual ~BinaryTree() {}
	virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual void insert(const T& theElement) = 0;
	//ǰ�����
	virtual void preOrder(BinaryTreeNode<T>* node)const = 0;
	//�������
	virtual void inOrder(BinaryTreeNode<T>* node)const = 0;
	//�������
	virtual void postOrder(BinaryTreeNode<T>* node)const = 0;
	//��α���
	virtual void levelOrder(BinaryTreeNode<T>* node)const = 0;
};