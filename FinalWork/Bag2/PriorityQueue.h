//
// Created by Levi on 2021/12/19.
//

#ifndef HOMEWORK_PRIORITYQUEUE_H
#define HOMEWORK_PRIORITYQUEUE_H
#include "Bag.h"
//最小优先级队列
template<class T>
class PriorityQueue : public Bag<T> {
public:
    PriorityQueue(int Size = DaufaultSize);
    ~PriorityQueue();
    bool Get(T& val);
    bool Remove(T& val);
};
#endif //HOMEWORK_PRIORITYQUEUE_H
