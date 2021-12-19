#ifndef BAG_STACK_H
#define BAG_STACK_H
#include "Bag.h"
template<class T>
class BagStack:public Bag<T> {
public:
    BagStack(int Size = DaufaultSize);
    ~BagStack();
    bool Remove(T& val);
    bool Get(T& val);
};


#endif // BAG_ST