//
// Created by Levi on 2021/12/19.
//

#include "PriorityQueue.h"
//最小优先级队列
template<class T>
PriorityQueue<T>::PriorityQueue(int Size) :Bag<T>(Size) {}

template<class T>
PriorityQueue<T>::~PriorityQueue<T>() {}

template<class T>
bool PriorityQueue<T>::Get(T &val) {
    if (this->Empty()) return false;
    else {
        T minNumber = this->Elements[0];
        for (int i = 1; i <= this->top ;i++) {
            minNumber = minNumber > this->Elements[i] ? this->Elements[i] : minNumber;
        }
        val = minNumber;
    }
    return true;
}

template<class T>
bool PriorityQueue<T>::Remove(T &val) {
    if (this->Empty()) return false;
    else {
        T minNumber = this->Elements[0];
        int minNumberIndex = 0;
        for (int i = 1; i <= this->top; i++) {
            if (minNumber > this->Elements[i]) {
                minNumber = this->Elements[i];
                minNumberIndex = i;
            }
        }
        if (minNumber != this->top)
            this->Elements[minNumberIndex] = this->Elements[this->top--];
    }
    return true;
}