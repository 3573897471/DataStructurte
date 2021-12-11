//
// Created by 黎炜堂 on 2021/12/10.
//

#ifndef HOMEWORK_LINKEDSTACK_H
#define HOMEWORK_LINKEDSTACK_H

#include<iostream>
using namespace std;
template<class T>
struct LinkedStackNode {
    T data;
    LinkedStackNode<T>* next;
    LinkedStackNode(T val = 0, LinkedStackNode<T>* next = nullptr):
        data(val), next(next) {}
};

template<class T>
class LinkedStack {
private:
    LinkedStackNode<T>* top;
public:
    //构造函数
    LinkedStack();
    //析构函数
    ~LinkedStack();
    //进栈
    void Push(const T val);
    //退栈
    bool Pop(T& val);
    //读取栈顶元素
    bool Top(T& val);
    //判断栈是否为空
    bool StackIsEmpty() const;
    //求栈的个数
    int GetSize() const;
    //清空栈的内容
    void MakeEmpty();
    //输出栈，重载左运算符
    friend ostream& operator<<(ostream& out, LinkedStack<T>& LStack);
};
#endif //HOMEWORK_LINKEDSTACK_H
