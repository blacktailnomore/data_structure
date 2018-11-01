#pragma once

#include "edge.h"

/*
图基类
*/

template<class T>
class Graph
{
public:
	virtual ~Graph() {}
	//顶点
	virtual int numberOfVertices()const = 0;
	//边
	virtual int numberOfEdges()const = 0;
	//是否有边
	virtual  bool existsEdge(int, int)const = 0;
	//插入边
	virtual insertEdge(Edge<T>*) = 0;
	//删除边
	virtual void eraseEdge(int, int) = 0;
	
	virtual int degree(int)const = 0;
	virtual int inDegree(int)const = 0;
	virtual int outDegree(int)const = 0;

	virtual bool directed()const = 0;
	virtual bool weighted()const = 0;
};
