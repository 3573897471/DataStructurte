#include "Bag.h"

//构造函数
template<class T>
Bag<T>::Bag(int Size) {
    maxSize = Size;
    Elements = new T[maxSize];
    top = -1;
}
//析构函数
template<class T>
Bag<T>::~Bag() {
    delete Elements;
    top = -1;
    maxSize = 0;
}
//插入函数：尾部插入
template<class T>
bool Bag<T>::Add(const T val) {
    if (Full()) return false;
    else {
        Elements[++top] = val;
    }
    return true;
}
//删除函数：删除第一个元素
template<class T>
bool Bag<T>::Remove(T& val) {
    if (Empty()) return false;
    else {
        val = Elements[0];
        for (int i = 1; i <= top; i++)
            Elements[i - 1] = Elements[i];
        top--;
    }   
    return true;
}
//存取操作
template<class T>
bool Bag<T>::Get(T& val) {
    if (Empty()) return false;
    else val = Elements[0];
    return true;
}
template<class T>
bool Bag<T>::Put(const T val) {
    return this->Add(val);
}
//初始化操作
template<class T>
void Bag<T>::MakeEmpty() {
    delete []Elements;
    top = -1;
    maxSize = 0;
}
//判空操作
template<class T>
bool Bag<T>::Empty() {
    return top < 0;
}
//判满操作
template<class T>
bool Bag<T>::Full() {
    return top >= maxSize;
}
//长度操作
template<class T>
int Bag<T>::Length() {
    return top < 0 ? top : top + 1;
}