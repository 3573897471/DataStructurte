//
// Created by Administrator on 2021/12/5.
//
//循环链表
#ifndef HOMEWORK_ANOTHERLINKEDLIST3_H
#define HOMEWORK_ANOTHERLINKEDLIST3_H
#include<iostream>
using namespace std;

//循环链表
template<class T>
struct CircularLinkedNode {
    T data;
    CircularLinkedNode<T>* next;
    CircularLinkedNode(T val = 0, CircularLinkedNode<T>* link = nullptr)
        :data(val), next(link) {}
};

template<class T>
class CircularLinkedList {
private:
    CircularLinkedNode<T>* head;
    CircularLinkedNode<T>* last;
public:
    //构造函数
    CircularLinkedList();
    CircularLinkedList(const T& val);
    CircularLinkedList(CircularLinkedList<T> &R);
    //尾插法建立循环链表
    bool AddToTail(const T& val);
    //输出循环链表
    void ShowCircularLinkedList();
    //判断表是否为空
    bool CircularLinkedListIsEmpty();
    //求表长
    int CircularLinkedListSize();
    //输出表中的第i个节点
    CircularLinkedNode<T>* ShowCircularLinkedNode(int index);
    //输出元素的位置
    int IndexCircularLinkedNode(int value);
    //在第i个位置插入新节点
    bool InsertCircularLinkedNode(int index, const T& val);
    //删除第i个节点
    bool delCircularLinkedNode(int index);
    //得到头节点
    CircularLinkedNode<T>* GetCircularLinkedListHead();
    //得到尾节点
    CircularLinkedNode<T>* GetCircularLinkedListTail();
};

#endif //HOMEWORK_ANOTHERLINKEDLIST3_H
