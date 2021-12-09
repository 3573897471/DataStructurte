//
// Created by 黎炜堂 on 2021/12/6.
//
//双向链表
#ifndef HOMEWORK_DOUBLELINKEDLIST_H
#define HOMEWORK_DOUBLELINKEDLIST_H
#include<iostream>
using namespace std;

//双向链表的节点结构
template<class T>
struct DoubleLinkedNode {
    T data;
    DoubleLinkedNode<T>* pre;
    DoubleLinkedNode<T>* next;
    DoubleLinkedNode<T>(T val = 0, DoubleLinkedNode<T>* node1 = nullptr, DoubleLinkedNode<T>* node2 = nullptr)
            : data(val), pre(node1), next(node2) {}
};

template<class T>
class DoubleLinkedList {
private:
    DoubleLinkedNode<T>* head;
public:
    //构造函数
    DoubleLinkedList();
    DoubleLinkedList(const T& val);
    DoubleLinkedList(DoubleLinkedList<T> &R);
    //尾插法建立双端链表
    void AddToTail(const T& val);
    //输出双端链表
    void ShowDoubleLinkedList();
    //判断表是否为空
    bool DoubleLinkedListIsEmpty();
    //求表长
    int DoubleLinkedListSize();
    //输出表的第index个节点
    DoubleLinkedNode<T>* IndexShowNode(int index);
    //输出元素的位置
    int NodeShowIndex(const T& val);
    //在第index个位置插入新节点
    bool InsertIndexNode(int index, const T& val);
    //删除第index个节点
    bool DelIndexNode(int index);
    //得到头节点
    DoubleLinkedNode<T>* GetHeadNode();
};


#endif //HOMEWORK_DOUBLELINKEDLIST_H
