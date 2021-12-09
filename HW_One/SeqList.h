//
// Created by 黎炜堂 on 2021/12/9.
//

#ifndef HOMEWORK_SEQLIST_H
#define HOMEWORK_SEQLIST_H
#include <iostream>
using namespace std;

const int FirstSize = 100;
template <class T>
class SeqList {
private:
    //存放数组的数组
    T *data;
    //数组最大尺寸：可扩充
    int maxSize;
    //存放最后一个数据的下标
    int last;
public:
    //构造函数
    SeqList(int size = FirstSize);
    SeqList(SeqList<T>& L);
    //析构函数
    ~SeqList();
    //插入
    bool InsertSeqList(int index, const T& val);
    //删除:第i个节点
    bool DelSeqListElement(int index);
    //查找
    int SearchSeqList(const T& val);
    //输出到屏幕上
    void ShowSeqList();
    //输出表长
    int SeqListLength();
    //输出表的最大长度
    int SeqListMaxLength();
};
#endif //HOMEWORK_SEQLIST_H
