#pragma once

#include "edge.h"

/*
ͼ����
*/

template<class T>
class Graph
{
public:
	virtual ~Graph() {}
	//����
	virtual int numberOfVertices()const = 0;
	//��
	virtual int numberOfEdges()const = 0;
	//�Ƿ��б�
	virtual  bool existsEdge(int, int)const = 0;
	//�����
	virtual insertEdge(Edge<T>*) = 0;
	//ɾ����
	virtual void eraseEdge(int, int) = 0;
	
	virtual int degree(int)const = 0;
	virtual int inDegree(int)const = 0;
	virtual int outDegree(int)const = 0;

	virtual bool directed()const = 0;
	virtual bool weighted()const = 0;
};
