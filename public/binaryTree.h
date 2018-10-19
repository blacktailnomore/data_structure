#pragma once

#include "binaryTreeNode.h"

/*
二叉树基类
*/
template<class T>
class BinaryTree
{
public:
	virtual ~BinaryTree() {}
	virtual bool empty()const = 0;
	virtual bool size()const = 0;
	//前序遍历
	virtual void preOrder(BinaryTreeNode<T>* node) = 0;
	//中序遍历
	virtual void inOrder(BinaryTreeNode<T>* node) = 0;
	//后序遍历
	virtual void postOrder(BinaryTreeNode<T>* node) = 0;
	//层次遍历
	virtual void levelOrder(BinaryTreeNode<T>* node) = 0;
};