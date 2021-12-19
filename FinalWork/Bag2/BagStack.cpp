#include "BagStack.h"
#include "Bag.h"
template<class T>
BagStack<T>::BagStack(int Size): Bag<T>(Size) {}

template<class T>
BagStack<T>::~BagStack(){
    ~Bag<T>();
}
template<class T>
bool BagStack<T>::Remove(T& val) {
    if (this->Empty()) return false;
    else val = this->Elements[this->top--];
    return true;
}

template<class T>
bool BagStack<T>::Get(T& val) {
    if (this->Empty()) return false;
    else val = this->Elements[this->top];
    return true;
}


