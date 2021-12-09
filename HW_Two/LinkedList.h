//
// Created by 黎炜堂 on 2021/12/3.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include<iostream>

using namespace std;

//单链表节点
template<class T>
struct ListNode {
    T data;
    ListNode<T> *next;

    ListNode() : next(nullptr) {}

    ListNode(T value, ListNode<T> *node = nullptr) : data(value), next(node) {}
};

//单链表
template<class T>
class SingleLinkedList {
private:
    ListNode<T> *head;
    int size;

public:
    //默认构造函数
    SingleLinkedList() {
        size = 0;
        head = new ListNode<T>();
    }

    SingleLinkedList(T val) {
        addToTail(val);
    }

    //插入
    void addToHead(T value);

    void addToTail(T value);

    //删除
    bool delNode(T value);

    //查找
    bool searchNode(T value);

    //合并两个链表
    ListNode<T> *mergeList(ListNode<T> *anotherHead);

    //获取头节点
    ListNode<T> *getHead();

    //输出链表中所有元素到屏幕上
    void show();
};

#endif //LINKEDLIST_LINKEDLIST_H
