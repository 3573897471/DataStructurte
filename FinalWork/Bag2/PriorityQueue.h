//
// Created by 黎炜堂 on 2021/12/19.
//

#ifndef HOMEWORK_PRIORITYQUEUE_H
#define HOMEWORK_PRIORITYQUEUE_H
#include "Bag.h"
template<class T>
class PriorityQueue : public Bag<T> {
public:
    PriorityQueue(int Size = DaufaultSize);
    ~PriorityQueue();
    bool Get(T& val);
    bool Remove(T& val);

};
#endif //HOMEWORK_PRIORITYQUEUE_H
