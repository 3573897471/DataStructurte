//
// Created by Levi on 2021/12/29.
//

#ifndef HOMEWORK_MINHEAP_H
#define HOMEWORK_MINHEAP_H
#define DefaultSize 100
template<class E>
class MinHeap {
public:
    //构造函数
    MinHeap(int Size = DefaultSize);
    //构造函数：通过一个数组构建最小堆
    MinHeap(E arr[], int n);
    //析构函数
    ~MinHeap();
    //将val插入最小堆
    bool Insert(const E& val);
    //删除堆顶上的最小元素
    bool RomoveMinNumber(E& val);
    //判定堆是否为空
    bool HeapIsEmpty() const;
    //判定堆是否满
    bool HeapIsFull() const;
    //置空堆
    void MakeEmpty();
private:
    //堆数组
    E *heap;
    //堆的当前尺寸
    int currentSize;
    //堆的最大尺寸
    int maxSize;
    //从start开始下滑到m位置
    void SiftDown(int start, int m);
    //从start开始上升到根节点
    void SiftUp(int start);
};

#endif //HOMEWORK_MINHEAP_H
