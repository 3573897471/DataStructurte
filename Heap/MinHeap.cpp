//
// Created by Levi on 2021/12/29.
//

#include "MinHeap.h"

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

//将val插入最小堆

//删除堆顶上的最小元素

//判定堆是否为空

//判定堆是否满了

//置空堆

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
        //如果j没有到最后位置并且右子树大于父节点，则j到右节点处
        if (j < m && heap[i] > heap[j + 1]) j++;
        //如果
        if (temp <= heap[j]) break;
        else {
            heap[i] = heap[j];
            i = j;
            j = i * 2 + 1;
        }
    }
    heap[i] = temp;
}
//上升