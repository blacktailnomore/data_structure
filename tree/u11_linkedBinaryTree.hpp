#pragma once

#include "binaryTree.h"

/*
������ ������ʽ
*/
template<class T>
class LinkedBinaryTree :public BinaryTree<T>
{
public:
	LinkedBinaryTree()
		:root(nullptr),treeSize(0)
	{}
	~LinkedBinaryTree() { clear(); }
public:
	bool empty()const { return treeSize == 0; }
	int size()const { return treeSize; }
	int height()const;
	void insert(const T& theElement);
	void preOrder()const;
	void inOrder()const;
	void postOrder()const;
	void levelOrder()const;
	void erase(const T& theElement);

	void clear();
protected:
	void insert(const T& theElement, BinaryTreeNode<T>* &node);
	void preOrder(BinaryTreeNode<T>* node)const;
	void inOrder(BinaryTreeNode<T>* node)const;
	void postOrder(BinaryTreeNode<T>* node)const;
	void levelOrder(BinaryTreeNode<T>* node)const;
private:
	BinaryTreeNode<T>* root;
	int treeSize;
};

template<class T>
void LinkedBinaryTree<T>::erase(const T& theElement)
{

}

template<class T>
void LinkedBinaryTree<T>::levelOrder() const
{
	if (root == nullptr)return;
	levelOrder(root);
}

template<class T>
void LinkedBinaryTree<T>::postOrder() const
{
	//����
	if (root == nullptr)return;
	postOrder(root);
}

template<class T>
void LinkedBinaryTree<T>::inOrder() const
{
	//����
	if (root == nullptr)return;
	inOrder(root);
}

template<class T>
void LinkedBinaryTree<T>::preOrder() const
{
	//ǰ��
	if (root == nullptr)return;
	preOrder(root);
}

template<class T>
void LinkedBinaryTree<T>::insert(const T& theElement, BinaryTreeNode<T>* &node)
{
	//������С�Ҵ�ݹ�
	if (node == nullptr)
	{
		node = new BinaryTreeNode<T>(theElement);
	}
	else if (theElement < (node->element))
	{
		insert(theElement, node->leftChild);
	}
	else if (theElement > (node->element))
	{
		insert(theElement, node->rightChild);
	}
}

template<class T>
int LinkedBinaryTree<T>::height() const
{
	if (root == nullptr)
		return 0;

}

template<class T>
void LinkedBinaryTree<T>::insert(const T& theElement)
{
	if (root == nullptr)
	{
		//�޸��ڵ�
		root = new BinaryTreeNode<T>(theElement);
	}
	else
	{
		//С�ڸ��ڵ�->������
		if (theElement < (root->element))
		{
			insert(theElement, root->leftChild);
		}
		//���ڸ��ڵ�->������
		else if (theElement > (root->element))
		{
			insert(theElement, root->rightChild);
		}
		else return;
	}
	treeSize++;
}

template<class T>
void LinkedBinaryTree<T>::preOrder(BinaryTreeNode<T>* node)const
{
	//ǰ��
	if (node != nullptr)
	{
		std::cout << (node->element) << " ";
		preOrder(node->leftChild);
		preOrder(node->rightChild);
	}
}


template<class T>
void LinkedBinaryTree<T>::inOrder(BinaryTreeNode<T>* node)const
{
	//����
	if (node != nullptr)
	{
		inOrder(node->leftChild);
		std::cout << (node->element) << " ";
		inOrder(node->rightChild);
	}
}


template<class T>
void LinkedBinaryTree<T>::postOrder(BinaryTreeNode<T>* node)const
{
	//����
	if (node != nullptr)
	{
		postOrder(node->leftChild);
		postOrder(node->rightChild);
		std::cout << (node->element) << " ";
	}
}


template<class T>
void LinkedBinaryTree<T>::levelOrder(BinaryTreeNode<T>* node)const
{
	//���
}


template<class T>
void LinkedBinaryTree<T>::clear()
{

}
