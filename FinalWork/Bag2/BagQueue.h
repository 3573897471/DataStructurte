//
// Created by Levi on 2021/12/19.
//

#ifndef HOMEWORK_BAGQUEUE_H
#define HOMEWORK_BAGQUEUE_H
#include "Bag.h"

template<class T>
class BagQueue :public Bag<T> {
public:
    BagQueue(int Size = DaufaultSize);
    ~BagQueue();
};
#endif //HOMEWORK_BAGQUEUE_H
