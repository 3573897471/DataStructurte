//
// Created by Levi on 2021/12/9.
//

#include "SeqList.h"

//构造函数
template <class T>
SeqList<T>::SeqList(int size) {
    maxSize = size;
    data = new T[maxSize];
    last = -1;
}
template <class T>
SeqList<T>::SeqList(SeqList<T>& L) {
    maxSize = L.SeqListMaxLength();
    last = L.SeqListLength();
    data = new T[maxSize];
    for (int i = 0;i <= last;i++) {
        data[i] = L.data[i];
    }
}
//析构函数
template <class T>
SeqList<T>::~SeqList() {
    last = -1;
    maxSize = 0;
    delete data;
}
//插入
template <class T>
bool SeqList<T>::InsertSeqList(int index, const T& val) {
    if (last == maxSize - 1) return false;
    if (index < 0 || index > last) return false;
    for (int i = index;i <= last + 1;i++) {
        data[i + 1] = data[i];
    }
    data[index] = val;
    last++;
    return true;
}
//删除:第i个节点
template <class T>
bool SeqList<T>::DelSeqListElement(int index) {
    if (last == -1) return false;
    if (index < 1 || index > last) return false;
    for (int i = index;i <= last;i++) {
        data[i - 1] = data [i];
    }
    return true;
}
//查找
template <class T>
int SeqList<T>::SearchSeqList(const T& val) {
    for (int i = 0;i <= last;i++)
        if (data[i] == val) return i;
    return -1;
}
//输出到屏幕上
template <class T>
void SeqList<T>::ShowSeqList() {
    if (last == -1) {
        cout << "This SeqList is empty" << endl;
        return;
    }
    for (int i = 0;i < last;i++)
        cout << data[i] << " ";
    cout<<endl;
}
//输出表长
template <class T>
int SeqList<T>::SeqListLength() {
    return last + 1;
}

//输出表最大长度
template<class T>
int SeqList<T>::SeqListMaxLength() {
    return maxSize;
}