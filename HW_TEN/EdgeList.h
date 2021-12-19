#ifndef HOMEWORK_EDGELIST_H
#define HOMEWORK_EDGELIST_H

#include<iostream>
#include "Graph.h"

template<class T, class E>
struct Edge
{
    int dest;
    E cost;
    Edge<T, E>* link;
    //构造函数
    Edge() {}
    Edge(int num, E weight) : dest(num), cost(weight), link(nullptr) {}
    //判断边不等否
    bool operator!= (Edge<T, E>& R) const {
        return (dest != R.dest) ? true : false;
    }
};

//顶点
template<class T, class E>
struct Vertex {
    //顶点名称
    T data;
    //边链表的头指针
    Edge<T, E>* adj;
};

template<class T, class E>
class Graphlnk {
public:
    //构造函数
    Graphlnk(int sz = DefaultVertices);
    //析构函数
    ~Graphlnk();
    //取位置为i的顶点中的值
    T getValue(int i);
    //返回边（v1，v2）上的权值
    E getWeight(int v1, int v2);
    //在图中插入一个顶点vertex
    bool insertVertex(const T& vertex);
    //在图中删除一个顶点v
    bool removeVertex(int v);
    //在图中插入一条边（v1，v2）
    bool insertEdge(int v1, int v2, E weight);
    //在图中删除一条边（v1，v2）
    bool removeEdge(int v1, int v2);
    //取顶点v的第一个邻接顶点
    int getFirstNeighbor(int v);
    //取v的邻接顶点w的下一邻接顶点
    int getNextNeighbor(int v, int w);

    
private:
    Vertex<T, E> *NodeTable;
    int maxVertices;
    int numEdges;
    int numVertices;
    int getVertexPos(const T vertex) {
        for (int i = 0; i < numVertices;i++) {
            if (NodeTable[i].data == vertex) return i;
        }
        return -1;
    }
};

#endif