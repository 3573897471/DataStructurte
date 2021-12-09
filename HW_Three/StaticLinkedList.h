//
// Created by 黎炜堂 on 2021/12/8.
//

#ifndef HOMEWORK_STATICLINKEDLIST_H
#define HOMEWORK_STATICLINKEDLIST_H
//静态链表最大尺寸
const int maxSize = 100;
template <class T>
struct StaticLinkedNode {
    T data;
    //
    int ElemIndex;
};

template<class T>
class StaticLinkedList {
private:
    //链表数组
    StaticLinkedNode<T> elements[maxSize];
    //当前可分配的首地址
    int FirstIndex;
public:
    //构造函数
    StaticLinkedList();
//    StaticLinkedList(const T& val);
    //尾插法建立链表
    bool AddToTail(const T& val);
    //输出链表到屏幕上
    bool ShowStaticLinkedList();
    //判断链表是否为空
    bool StaticLinkedListIsEmpty();
    //求表长
    int StaticLinkedListSize();
    //输出链表的第index个节点
    StaticLinkedNode<T>* IndexShowNode(int index);
    //输出元素位置
    int NodeShowIndex(const T& val);
    //在第index个位置插入新节点
    bool InsertIndexNode(int index, const T& val);
    //删除第index个节点
    bool DelIndexNode(int index);

};
#endif //HOMEWORK_STATICLINKEDLIST_H
