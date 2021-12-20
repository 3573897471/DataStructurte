//
// Created by Levi on 2021/12/10.
//

#include "LinkedStack.h"

//构造函数
template<class T>
LinkedStack<T>::LinkedStack() {
    top = new LinkedStack<T>(nullptr);
}

//析构函数
template<class T>
LinkedStack<T>::~LinkedStack() {
    MakeEmpty();
}

//进栈
template<class T>
void LinkedStack<T>::Push(const T val) {
    top = new LinkedStack<T>(val, top);
}

//退栈
template<class T>
bool LinkedStack<T>::Pop(T& val) {
    if (StackIsEmpty()) {
        return false;
    } else {
        val = top->data;
        

        return true;
    }
}

//读取栈顶元素
template<class T>
bool LinkedStack<T>::Top(T& val) {

}

//判断栈是否为空
template<class T>
bool LinkedStack<T>::StackIsEmpty() const {

}

//求栈的个数
template<class T>
int LinkedStack<T>::GetSize() const {

}

//清空栈的内容
template<class T>
void LinkedStack<T>::MakeEmpty() {

}

//输出栈，重载左运算符
template<class T>
ostream& operator<<(ostream& out, LinkedStack<T>& LStack) {

}