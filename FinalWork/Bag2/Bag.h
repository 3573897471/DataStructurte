#ifndef BAG_H
#define BAG_H

#define DaufaultSize 100

#include<iostream>

template<class T>
class Bag {
public:
    //构造函数
    Bag(int Size = DaufaultSize);
    //析构函数
    ~Bag();
    //插入函数
    virtual bool Add(const T val);
    //删除函数
    virtual bool Remove(T& val);
    //存取操作
    virtual bool Get(T& val);
    virtual bool Put(const T val);
    //初始化操作
    virtual void MakeEmpty();
    //判空操作
    virtual bool Empty();
    //判满操作
    virtual bool Full();
    //计数操作
    virtual int Length();
protected:
    //元素数组
    T* Elements;
    //数组最大尺寸
    int maxSize;
    //数组当前元素个数
    int top;
};



#endif