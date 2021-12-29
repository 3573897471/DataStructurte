//
// Created by Levi on 2021/12/29.
//

#include "MinHeap.h"
#include <iostream>
using namespace std;
//构造函数
template<class E>
MinHeap<E>::MinHeap(int Size) {
    maxSize = (DefaultSize > Size) ? DefaultSize : Size;
    heap = new E[maxSize];
    currentSize = 0;
}
//构造函数：通过一个数组建立最小堆
template<class E>
MinHeap<E>::MinHeap(E *arr, int n) {
    maxSize = (DefaultSize > n) ? DefaultSize : n;
    heap = new E[maxSize];
    //复制arr数组，这里可以改成从键盘输入
    for (int i = 0; i < n; i++) heap[i] = arr[i];
    currentSize = n;
    //找最初的调整位置：最后的分支节点
    //最后的分支节点：最后一个含有左子树或者右子树的节点，在堆数组的中间位置
    int currentPos = (currentSize - 2) / 2;
    //自底向上逐步扩大形成堆
    while (currentPos >= 0) {
        //局部自上而下下滑调整
        SiftDown(currentPos, n - 1);
        //再向前更换一个分支节点
        currentPos--;
    }
}

//析构函数
template<class E>
MinHeap<E>::~MinHeap() {
    currentSize = 0;
    maxSize = 0;
    delete []heap;
}

//将val插入最小堆
template<class E>
bool MinHeap<E>::Insert(const E& val) {
    //如果堆满就返回false
    if (currentSize == maxSize) {
        cout << "MinHeap is Full\n";
        return false;
    }
    heap[currentSize] = val;
    //上滑维持最小堆性质
    SiftUp(currentSize);
    currentSize++;
    return true;
}

//删除堆顶上的最小元素
template<class E>
bool MinHeap<E>::RomoveMinNumber(E &val) {
    //如果堆为空则返回false
    if (! currentSize) {
        cout << "MinHeap is Empty\n";
        return false;
    }
    val = heap[0];
    //让最大的元素放到首位，然后下滑
    heap[0] = heap[currentSize - 1];
    currentSize--;
    //下滑维持最小堆性质
    SiftDown(0, currentSize - 1);
    return true;
}

//判定堆是否为空
template<class E>
bool MinHeap<E>::HeapIsEmpty() const {
    return ! currentSize;
}

//判定堆是否满了
template<class E>
bool MinHeap<E>::HeapIsFull() const {
    return currentSize == maxSize;
}

//置空堆
template<class E>
void MinHeap<E>::MakeEmpty() {
    currentSize = 0;
}

//下滑
template<class E>
void MinHeap<E>::SiftDown(int start, int m) {
    //i为父节点的下标
    int i = start;
    //j为i的左子树下标
    int j = 2 * i + 1;
    E temp = heap[i];
    //检查是否到最后位置
    while (j <= m) {
        //如果j没有到最后位置，则让j指向较小的一个（左右节点中的一个）
        if (j < m && heap[j] > heap[j + 1]) j++;
        //如果较小的一个大于temp，则说明已经满足了最小堆的性质，跳出
        if (temp <= heap[j]) break;
        //否则更新根节点为最小的值，然后往下继续维护最小堆性质
        else {
            heap[i] = heap[j];
            i = j;
            j = i * 2 + 1;
        }
    }
    //回放temp中的暂存的元素
    heap[i] = temp;
}

//上升
template<class E>
void MinHeap<E>::SiftUp(int start) {
    int j = start;
    int i = (j - 1) / 2;
    E temp = heap[j];
    //沿父节点路径向上直达根
    while (j > 0) {
        //父节点值小，不调整
        if (heap[i] <= temp) break;
        //父节点值大，调整，并且上滑
        else {
            heap[j] = heap[i];
            j = i;
            i = (i - 2) / 2;
        }
    }
    //回放temp中暂存的元素
    heap[i] = temp;
}

//