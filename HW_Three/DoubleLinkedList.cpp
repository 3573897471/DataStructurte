//
// Created by Levi on 2021/12/6.
//
//双向链表

#include"DoubleLinkedList.h"
//构造函数
template<class T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = new DoubleLinkedNode<T>;
    head->next = head;
    head->pre = head;
}
template<class T>
DoubleLinkedList<T>::DoubleLinkedList(const T& val) {
    head = new DoubleLinkedNode<T>;
    head->next = new DoubleLinkedNode<T>(val);
    head->next->pre = head;
    head->next->next = head->next;
}
template<class T>
DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList<T> &R) {
    DoubleLinkedNode<T>* RHead = R.GetHeadNode();
    DoubleLinkedNode<T>* NewHead = head;
    while (RHead) {
        NewHead = new DoubleLinkedNode(RHead->data);
        NewHead->next->pre = NewHead;
        NewHead = NewHead->next;
        RHead = RHead->next;
    }
}
//尾插法建立双端链表
template<class T>
void DoubleLinkedList<T>::AddToTail(const T& val) {
    DoubleLinkedNode<T>* last = head;
    while (last != last->next) last = last->next;
    last->next = new DoubleLinkedNode<T>(val);
    last->next->pre = last;
    last->next->next = last->next;
}
//输出双端链表
template<class T>
void DoubleLinkedList<T>::ShowDoubleLinkedList() {
    DoubleLinkedNode<T>* node = head->next;
    while (node != node->next) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
//判断表是否为空
template<class T>
bool DoubleLinkedList<T>::DoubleLinkedListIsEmpty() {
    if (head == head->next) return true;
    else return false;
}
//求表长
template<class T>
int DoubleLinkedList<T>::DoubleLinkedListSize() {
    int size = 0;
    DoubleLinkedNode<T>* node = head;
    while (node != node->next) {
        size++;
        node = node->next;
    }
    return size - 1;
}
//输出表的第index个节点
template<class T>
DoubleLinkedNode<T>* DoubleLinkedList<T>::IndexShowNode(int index) {
    DoubleLinkedNode<T>* node = head;
    if(index > this->DoubleLinkedListSize() || index < 0) return nullptr;
    else {
        for (int i = 0;i < index;i++) {
            node = node->next;
        }
        return node;
    }
    return nullptr;
}
//输出元素的位置
template<class T>
int DoubleLinkedList<T>::NodeShowIndex(const T& val) {
    DoubleLinkedNode<T>* node = head;
    for (int i = 0;node != node->next;i++) {
        if (node->data == val) return i;
        node = node->next;
    }
    return -1;
}
//在第index个位置插入新节点
template<class T>
bool DoubleLinkedList<T>::InsertIndexNode(int index, const T& val) {
    DoubleLinkedNode<T>* node = head;
    if (index > this->DoubleLinkedListSize() || index < 0) return false;
    else {
        for (int i = 0;i < index;i++) node = node->next;
        DoubleLinkedNode<T>* temp = new DoubleLinkedNode<T>(val, node->pre, node);
        node->pre->next = temp;
        node->pre = temp;
        return true;
    }
    return false;
}
//删除第index个节点
template<class T>
bool DoubleLinkedList<T>::DelIndexNode(int index) {
    DoubleLinkedNode<T>* node = head;
    if (index > this->DoubleLinkedListSize()) return false;
    else {
        for (int i = 0;i < index;i++) node = node->next;
        DoubleLinkedNode<T>* temp = node->pre;
        temp->next = node->next;
        node->next->pre = temp;
        delete node;
        return true;
    }
}
//获取头节点
template<class T>
DoubleLinkedNode<T>* DoubleLinkedList<T>::GetHeadNode() {
    return this->head;
}

void TestDoubleLinkedList() {
    DoubleLinkedList<int> d1;
    for (int i = 0;i < 10;i++) {
        d1.AddToTail(i);
    }
    d1.ShowDoubleLinkedList();
    if (! d1.DoubleLinkedListIsEmpty())
        cout << d1.DoubleLinkedListSize() << endl;
    else cout << "d1 is empty()" <<endl;

    DoubleLinkedNode<int>* node = d1.IndexShowNode(20);
    if (node) cout << "node data is:" << node->data << endl;
    else cout << "node is nullptr" <<endl;
    cout << d1.NodeShowIndex(4) << " " << d1.NodeShowIndex(10) << endl;
    d1.DelIndexNode(4);
    d1.ShowDoubleLinkedList();
    return;
}


//int main() {
//    TestDoubleLinkedList();
//    return 0;
//}
