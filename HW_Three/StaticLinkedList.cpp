//
// Created by Levi on 2021/12/8.
//
#include "StaticLinkedList.h"
#include <iostream>
using namespace std;
//构造函数
template<class T>
StaticLinkedList<T>::StaticLinkedList() {
    elements[0].ElemIndex = -1;
    FirstIndex = 1;
    for (int i = 1;i < maxSize - 1;i++)
        elements[i].ElemIndex = i + 1;
    elements[maxSize - 1].ElemIndex = -1;
}
//template<class T>
//StaticLinkedList<T>::StaticLinkedList(const T& val) {
//    elements[0].ElemIndex = 1;
//    FirstIndex = 2;
//    elements[0].data = val;
//    for (int i = 2;i < maxSize - 1;i++)
//        elements[i].ElemIndex = i + 1;
//    elements[maxSize - 1].ElemIndex = -1;
//}
//尾插法建立链表
template<class T>
bool StaticLinkedList<T>::AddToTail(const T& val) {
    if (FirstIndex == -1) return false;
    //在链表的尾部新建一个节点
    int q = FirstIndex;
    FirstIndex = elements[FirstIndex].ElemIndex;
    //新建节点
    elements[q].data = val;
    elements[q].ElemIndex = -1;
    //找到链表的尾部
    int p = 0;
    while (elements[p].ElemIndex != -1)
        p = elements[p].ElemIndex;
    //将新节点和链表连接起来
    elements[p].ElemIndex = q;
    return true;

}
//输出链表到屏幕上
template<class T>
bool StaticLinkedList<T>::ShowStaticLinkedList() {
    int p = elements[0].ElemIndex;
    while (p != -1) {
        cout << elements[p].data << " ";
        p = elements[p].ElemIndex;
    }
    cout << endl;
}
//判断链表是否为空
template<class T>
bool StaticLinkedList<T>::StaticLinkedListIsEmpty() {
    if (elements[0].ElemIndex == 0) return true;
    else return false;
}
//求表长
template<class T>
int StaticLinkedList<T>::StaticLinkedListSize() {
    int size = 0;
    int p = elements[0].ElemIndex;
    while (p != -1) {
        size++;
        p = elements[p].ElemIndex;
    }
    return size;
}
//输出链表的第index个节点
template<class T>
StaticLinkedNode<T>* StaticLinkedList<T>::IndexShowNode(int index) {
    if (index < 0) return nullptr;
    if (index == 0) return &elements[0];
    int p = elements[0].ElemIndex;
    int i = 1;
    while (p != -1 && i < index) {
        i++;
        p = elements[p].ElemIndex;
    }
    return &elements[p];
}
//输出元素位置
template<class T>
int StaticLinkedList<T>::NodeShowIndex(const T& val) {

    int p =elements[0].ElemIndex;
    while (p != -1) {
        if (val = elements[p].data) return p;
        p = elements[p].ElemIndex;
    }
    return -1;
}
//在第index个位置插入新节点
template<class T>
bool StaticLinkedList<T>::InsertIndexNode(int index, const T& val) {
    if (index < 0) return false;
    int p = elements[index].ElemIndex;
    int i = 1;
    while (p != -1 && i < index) {
        i++;
        p = elements[p].ElemIndex;
    }
    //分配节点
    int q = FirstIndex;
    FirstIndex = elements[FirstIndex].ElemIndex;
    //新节点连接链表
    elements[q].data = val;
    elements[q].ElemIndex = elements[p].ElemIndex;
    elements[p].ElemIndex = q;
    return true;
}
//删除第index个节点
template<class T>
bool StaticLinkedList<T>::DelIndexNode(int index) {
    if (index < 0) return false;
    int p = elements[0].ElemIndex;
    int i = 1;
    while (p != -1 && i < index - 1) {
        p = elements[p].ElemIndex;
        i++;
    }
    //q是第index个节点
    int q = elements[p].ElemIndex;
    elements[p].ElemIndex = elements[q].ElemIndex;
    //释放
    elements[q].ElemIndex = FirstIndex;
    FirstIndex = q;
    return true;
}

void TestStaticLinkedList() {
    return;
}

//int main() {
//    TestStaticLinkedList();
//    return 0;
//}
