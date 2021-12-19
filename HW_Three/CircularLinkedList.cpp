//
// Created by Administrator on 2021/12/5.
//
//循环链表
#include"CircularLinkedList.h"
#include<iostream>
//构造函数
template<class T>
CircularLinkedList<T>::CircularLinkedList() {
    head = new CircularLinkedNode<T>;
    last = new CircularLinkedNode<T>;
    head = last;
}
template<class T>
CircularLinkedList<T>::CircularLinkedList(const T &val) {
    head = new CircularLinkedNode<T>(val);
    last = new CircularLinkedNode<T>;
    head = last;
}
template<class T>
CircularLinkedList<T>::CircularLinkedList(CircularLinkedList<T> &R) {
    if (R.CircularLinkedListIsEmpty()) {
        head = new CircularLinkedNode<T>;
        last = new CircularLinkedNode<T>;
        head = last;
    } else {
        CircularLinkedNode<T>* first = new CircularLinkedNode<T>(R.GetCircularLinkedListHead()->data,R.GetCircularLinkedListHead());
        CircularLinkedNode<T>* end = new CircularLinkedNode<T>(R.GetCircularLinkedListTail()->data,R.GetCircularLinkedListTail());
        CircularLinkedNode<T>* newHead = head;
        while (first !=end) {
            newHead->data = first->data;
            newHead->next = new CircularLinkedNode<T>;
            newHead = newHead->next;
            first = first->next;
        }
        newHead->next = new CircularLinkedNode<T>(first->data);
        last = newHead->next;
        last->next = new CircularLinkedNode<T>;
        last->next = head;
    }

}
//尾插法建立循环链表
template<class T>
bool CircularLinkedList<T>::AddToTail(const T &val) {
    if (head->next == nullptr) {
        head->next = new CircularLinkedNode<T>;
        head->data = val;
        last = head;
        return true;
    } else {
        last->next = nullptr;
        CircularLinkedNode<T>* node = new CircularLinkedNode<T>(val);
        last->next = node;
        last = node;
        last->next = head;
        return true;
    }
    return false;
}
//输出循环链表
template<class T>
void CircularLinkedList<T>::ShowCircularLinkedList() {
    CircularLinkedNode<T>* newHead = head;
    while (newHead != last) {
        cout << newHead->data << " " <<endl;
        newHead = newHead->next;
    }
    cout << newHead->data << endl;
}
//判断表是否为空
template<class T>
bool CircularLinkedList<T>::CircularLinkedListIsEmpty() {
    if (head == last) return true;
    else return false;
}
//求表长
template<class T>
int CircularLinkedList<T>::CircularLinkedListSize() {
    CircularLinkedNode<T>* first = head;
    int size = 0;
    while (first != last) {
        size++;
        first = first->next;
    }
    return size;
}
//输出表中的第i个节点
template<class T>
CircularLinkedNode<T>* CircularLinkedList<T>::ShowCircularLinkedNode(int index) {
    if (index > this->CircularLinkedListSize()) return nullptr;
    else {
        CircularLinkedNode<T>* first = head;
        for (int i = 0;i < index;i++) first = first->next;
        return first;
    }
    return nullptr;
}
//输出元素的位置
template<class T>
int CircularLinkedList<T>::IndexCircularLinkedNode(int value) {
    CircularLinkedNode<T>*first = head;
    for (int i = 0;first != last;i++) {
        if (first->data == value) return i;
        else first = first->next;
    }
    return -1;
}
//在第i个位置插入新节点
template<class T>
bool CircularLinkedList<T>::InsertCircularLinkedNode(int index, const T& val) {
    if (index > this->CircularLinkedListSize() && index < 1) return false;
    else {
        if (this->CircularLinkedListSize() == 1) {
            head->next = new CircularLinkedNode<T>(val);
            last = head->next;
            last->next = head;
        } else {
            CircularLinkedNode<T>* pre = head;
            CircularLinkedNode<T>* cur = head->next;
            for (int i = 0;i < index;i++) {
                pre = cur;
                cur = cur->next;
            }
            CircularLinkedNode<T>* node = new CircularLinkedNode<T>(val);
            node->next = cur;
            pre->next = node;
            if (index == this->CircularLinkedListSize()) node->next = head;
        }
    }
    return true;
}
//删除第i个节点
template<class T>
bool CircularLinkedList<T>::delCircularLinkedNode(int index) {
    if (index > this->CircularLinkedListSize()) return false;
    else {
        if (index == 1) {
            if (head->next) {
                CircularLinkedNode<T> *node = head;
                head = head->next;
                last->next = head;
                delete node;
            } else {
                head = new CircularLinkedNode<T>;
                last = head;
            }
        } else {
            CircularLinkedNode<T>* pre = head;
            CircularLinkedNode<T>* cur = head->next;
            for (int i = 0;i < index;i++) {
                pre = cur;
                cur =cur->next;
            }
            CircularLinkedNode<T>* node = cur;
            pre->next = cur->next;
            delete node;
            if (index == this->CircularLinkedListSize()) last = pre;
        }
        return true;
    }
    return false;
}
//得到头节点
template<class T>
CircularLinkedNode<T>* CircularLinkedList<T>::GetCircularLinkedListHead() {
    return this->head;
}
//得到尾节点
template<class T>
CircularLinkedNode<T>* CircularLinkedList<T>::GetCircularLinkedListTail() {
    return this->last;
}

void TestCircularLinkedList() {
    CircularLinkedList<int> c1;
    for (int i = 0;i < 20;i++) {
        c1.AddToTail(i);
    }

    if (c1.CircularLinkedListIsEmpty()) cout << "c1 is empty!" << endl;
    else cout << "c1 is not empty!" << endl;

    cout << "The Size of c1 is :" << c1.CircularLinkedListSize() << endl;

    cout << "The index node data is :" << c1.ShowCircularLinkedNode(3)->data << endl;

    cout << "3 is in:" << c1.IndexCircularLinkedNode(3) << endl;

    c1.InsertCircularLinkedNode(2, 2);

    c1.delCircularLinkedNode(2);



    c1.ShowCircularLinkedList();
    return;
}


//int main()
//{
//    TestCircularLinkedList();
//    return 0;
//}