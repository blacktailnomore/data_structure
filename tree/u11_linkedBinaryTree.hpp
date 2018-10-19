#pragma once

/*
二叉树 链表形式
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
	void preOrder(BinaryTreeNode<T>* node);
	void inOrder(BinaryTreeNode<T>* node);
	void postOrder(BinaryTreeNode<T>* node);
	void levelOrder(BinaryTreeNode<T>* node);

	void clear();
private:
	BinaryTreeNode<T>* root;
	int treeSize;
};

template<class T>
int LinkedBinaryTree<T>::height() const
{
	if (root == nullptr)
		return 0;

}

template<class T>
void LinkedBinaryTree<T>::insert(const T& theElement)
{
	//二叉树有序
	if (treeSize == 0)
	{

	}
	else
	{

	}
}

template<class T>
void LinkedBinaryTree<T>::preOrder(BinaryTreeNode<T>* node)
{

}


template<class T>
void LinkedBinaryTree<T>::inOrder(BinaryTreeNode<T>* node)
{

}


template<class T>
void LinkedBinaryTree<T>::postOrder(BinaryTreeNode<T>* node)
{

}


template<class T>
void LinkedBinaryTree<T>::levelOrder(BinaryTreeNode<T>* node)
{

}


template<class T>
void LinkedBinaryTree<T>::clear()
{

}
