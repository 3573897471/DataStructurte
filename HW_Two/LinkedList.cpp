//
// Created by 黎炜堂 on 2021/12/3.
//

#include"LinkedList.h"
#include <iostream>

using namespace std;

//插入
template<class T>
void SingleLinkedList<T>::addToHead(T value) {
    if (size == 0) {
        head->next = new ListNode<T>(value);
        size++;
    } else {
        ListNode<T> *temp = head->next;
        ListNode<T> *node = new ListNode<T>(value);
        head->next = node;
        node->next = temp;
        size++;
    }
}

template<class T>
void SingleLinkedList<T>::addToTail(T value) {
    if (size == 0) {
        head->next = new ListNode<T>(value);
        size++;
    } else {
        ListNode<T> *pre = head;
        ListNode<T> *cur = head->next;
        while (cur) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = new ListNode<T>(value);
        size++;
    }
}

//删除
template<class T>
bool SingleLinkedList<T>::delNode(T value) {
    //如果链表为空就返回false
    if (!head->next) return false;
    ListNode<T> *pre = head;
    ListNode<T> *cur = head->next;
    while (cur) {
        if (cur->data == value) {
            //如果删除的是尾节点
            if (!cur->next) {
                pre->next = nullptr;
                delete cur;
                return true;
            } else {
                pre->next = cur->next;
                delete cur;
                return true;
            }
        }
        pre = cur;
        cur = cur->next;
    }
    return false;
}

//查找
template<class T>
bool SingleLinkedList<T>::searchNode(T value) {
    //空表不用找返回false
    if (!head->next) return false;
    ListNode<T> *cur = head;
    while (cur) {
        if (cur->data == value) return true;
        else cur = cur->next;
    }
    return false;
}

//合并两个链表
template<class T>
ListNode<T> *SingleLinkedList<T>::mergeList(ListNode<T> *anotherHead) {
    if (!head->next) {
        head->next = new ListNode<T>;
        head->next = anotherHead;
        return head;
    } else {
        ListNode<T> *pre = head;
        ListNode<T> *cur = head->next;
        while (cur) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = anotherHead;
    }
    return this->head;
}

//获取头节点
template<class T>
ListNode<T> *SingleLinkedList<T>::getHead() {
    return this->head;
}

//输出集合中所有元素到屏幕上
template<class T>
void SingleLinkedList<T>::show() {
    if (!head->next) return;
    ListNode<T> *cur = head->next;
    while (cur) {
        cout << cur->data << " " << endl;
        cur = cur->next;
    }
    return;
}


//测试函数
void test() {
    SingleLinkedList<int> s1;
    for (int i = 0; i < 10; i++) {
        s1.addToTail(i);
    }
    s1.addToHead(1000);
    s1.addToTail(9999);
    if (s1.searchNode(3)) cout << "3 is in Set" << endl;
    s1.delNode(3);
    if (s1.searchNode(3)) cout << "3 is in Set" << endl;
    else cout << "3 is not in Set" << endl;
    SingleLinkedList<int> s2;
    for (int j = 10; j < 20; j += 2) {
        s2.addToTail(j);
    }
    s1.mergeList(s2.getHead());
    s1.show();
    cout << "Testing" << endl;
    return;
}

//int main() {
//    test();
//    return 0;
//}
