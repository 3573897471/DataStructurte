//
// Created by Levi on 2021/12/20.
//

#ifndef HOMEWORK_AVLTREE_H
#define HOMEWORK_AVLTREE_H

#include <iostream>
using namespace std;
//AVL树的节点
template<class T>
struct AVLNode {
    //AVL树的平衡因子
    int BalanceFactor;
    T data;
    AVLNode* left;
    AVLNode* right;
    AVLNode(AVLNode* l = nullptr, AVLNode* r = nullptr, T val = 0) :
        left(l), right(r), data(val), BalanceFactor(0) {}
};

template<class T>
class AVLTree {
public:
    //构造函数
    AVLTree(AVLNode<T>* r = new AVLNode<T>(), T val = 0);
    //插入函数
    bool Insert(AVLNode<T>*& ptr, T& val);
    //删除函数
    bool Remove(AVLNode<T>*& ptr, T& val);
    //输入重载
    friend istream& operator>>(istream& in, AVLNode<T>& Tree);
    //输出重载
    friend ostream& operator<<(ostream& out, AVLNode<T>& Tree);
private:
    AVLNode<T>* root;
    //左旋
    void RotateL(AVLNode<T>*& ptr);
    //右旋
    void RotateR(AVLNode<T>*& ptr);
    //先左旋再右旋
    void RotateLR(AVLNode<T>*& ptr);
    //先右旋再左旋
    void RotateRL(AVLNode<T>*& ptr);
    //求某个节点的高度
    int Height(AVLNode<T>* ptr) const;
};


#endif //HOMEWORK_AVLTREE_H
