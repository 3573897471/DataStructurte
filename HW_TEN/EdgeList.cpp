#include "EdgeList.h"

//构造函数
template<class T, class E>
Graphlnk<T, E>::Graphlnk(int sz) {
    maxVertices = sz;
    numVertices = 0;
    numEdges = 0;
    NodeTable = new Vertex<T, E>[maxVertices];
    for (int i = 0;i < maxVertices;i++)
        NodeTable[i].adj = nullptr;
}
//析构函数
template<class T, class E>
Graphlnk<T, E>::~Graphlnk() {
    for (int i = 0;i < numVertices;i++) {
        Edge<T, E>* p = NodeTable[i].adj;
        while (p != nullptr) {
            NodeTable[i].adj = p->link;
            delete p;
            p = NodeTable[i].adj;
        }
    }
    delete []NodeTable;
}
//取位置为i的顶点中的值
template<class T, class E>
T Graphlnk<T, E>::getValue(int i) {

}
//返回边（v1，v2）上的权值
template<class T, class E>
E Graphlnk<T, E>::getWeight(int v1, int v2) {
    if (v1 != -1 && v2 != -1) {
        Edge<T, E>* p = NodeTable[v1].adj;
        while (p != nullptr && p->dest != v2)
            p = p->link;
        if (p != nullptr) return p->cost;
    }
    return 0;
}
//在图中插入一个顶点vertex
template<class T, class E>
bool Graphlnk<T, E>::insertVertex(const T& vertex) {
    if (numVertices == maxVertices) return false;
    NodeTable[numVertices].data = vertex;
    numVertices++;
    return true;
}
//在图中删除一个顶点v
template<class T, class E>
bool Graphlnk<T, E>::removeVertex(int v) {
    if (numVertices == 1 || v < 0 || v >= numVertices) return false;

    Edge<T, E>*p ,*s, *t;
    int i, k;
    while (NodeTable[v].adj) {
        p = NodeTable[v].adj;
        k = p->dest;
        s = NodeTable[k].adj;
        t =nullptr;
        while (s !=nullptr && s->dest != v) {
            t = s;
            s = s->link;
        }
        if (s !=nullptr) {
            if (t == nullptr)
                NodeTable[k].adj = s->link;
                else t->link = s->link;
                delete s;
        }
    }
    numVertices--;
    NodeTable[v].data = NodeTable[numVertices].data;
    p = NodeTable[p->dest].adj;
    while (p !=nullptr) {
        s = NodeTable[p->dest].adj;
        while (s != nullptr) {
            if (s->dest == numVertices) {
                s->dest = v;
                break;
            }
        }
    }
    return true;
}

//在图中插入一条边（v1，v2）
template<class T, class E>
bool Graphlnk<T, E>::insertEdge(int v1, int v2, E weight) {
    if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
        Edge<T, E>*q;
        Edge<T, E>*p = NodeTable[v1].adj;
        while (p != nullptr && p->dest != v2)
            p = p->link;
        if (p != nullptr) return false;
        p = new Edge<T, E>();
        q = new Edge<T, E>();
        p->dest = v2;
        p->cost = weight;
        p->link = NodeTable[v1].adj;
        NodeTable[v1].adj = p;
        q->dest = v1;
        q->cost = weight;
        q->link = NodeTable[v2].adj;
        NodeTable[v2].adj = q;
        numEdges++;
        return true;
    }
    return 0;
}

//在图中删除一条边（v1，v2）
template<class T, class E>
bool Graphlnk<T, E>::removeEdge(int v1, int v2) {
    if (v1 != -1 && v2 != -1) {
        Edge<T ,E>*p = NodeTable[v1].adj;
        Edge<T ,E>*q = nullptr;
        Edge<T ,E>*s = p;
        while (p != nullptr && p->dest != v2) {
            q = p;
            p = p->link;
        }
        if (p != nullptr) {
            if (p == s) NodeTable[v1].adj = p->link;
            else q->link = p->link;
            delete p;
        } else
            return false;
        p = NodeTable[v2].adj;
        q = nullptr;
        s = p;
        while (p->dest != v1) {
            q = p;
            p = p->link;
        }
        if (p == s) NodeTable[v2].adj = p->link;
        else q->link = p->link;
        delete p;
        return true;
    }
    return false;
}
//取顶点v的第一个邻接顶点
template<class T, class E>
int Graphlnk<T, E>::getFirstNeighbor(int v) {
    if (v != -1) {
        Edge<T, E>* p =NodeTable[v].adj;
        if (p != nullptr)
            return p->dest;
    }
    return -1;
}
//取v的邻接顶点w的下一邻接顶点
template<class T, class E>
int Graphlnk<T, E>::getNextNeighbor(int v, int w) {
    if (v != -1) {
        Edge<T, E>* p = NodeTable[v].adj;
        while (p != nullptr && p->dest != w)
            p = p->link;
        if (p !=nullptr && p->link != nullptr)
            return p->link->dest;
    }
    return -1;
}


void TestGraphList() {
    Graphlnk<int ,int> g1;
}
// int main() {
//     TestGraphList();
//     return 0;
// }
