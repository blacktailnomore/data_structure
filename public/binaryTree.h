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
	virtual bool size()const = 0;
	//ǰ�����
	virtual void preOrder(BinaryTreeNode<T>* node) = 0;
	//�������
	virtual void inOrder(BinaryTreeNode<T>* node) = 0;
	//�������
	virtual void postOrder(BinaryTreeNode<T>* node) = 0;
	//��α���
	virtual void levelOrder(BinaryTreeNode<T>* node) = 0;
};