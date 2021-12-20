//
// Created by Levi on 2021/12/20.
//

#include "AVLTree.h"

//构造函数
template<class T>
AVLTree<T>::AVLTree(AVLNode<T>* r, T val) {
    root = r;
    root->data = val;
}

//插入函数
template<class T>
bool Insert(AVLNode<T>*& ptr, T& val) {

}

//删除函数
template<class T>
bool Remove(AVLNode<T>*& ptr, T& val) {

}

//输入重载
template<class T>
istream& operator>>(istream& in, AVLNode<T>& Tree) {

}

//输出重载
template<class T>
ostream& operator<<(ostream& out, AVLNode<T>& Tree) {

}


//左旋
template<class T>
void AVLTree<T>::RotateL(AVLNode<T>*& ptr) {
    AVLNode<T>* subL = ptr;  // ptr为新根
    ptr = ptr->right;
    subL->right = ptr->left; // 接住ptr的左节点
    ptr->left = subL;        // 然后ptr再接住新的左节点，旋转完毕
    ptr->BalanceFactor = 0;
    subL->BalanceFactor = 0; // 此时平衡了，平衡因子全部为0
}

//右旋：左旋的镜像
template<class T>
void AVLTree<T>::RotateR(AVLNode<T>*& ptr) {
    AVLNode<T>* subR = ptr;
    ptr = ptr->left;
    subR->left = ptr->right;
    ptr->right = subR;
    ptr->BalanceFactor = 0;
    subR->BalanceFactor = 0;
}

//先左旋再右旋
template<class T>
void AVLTree<T>::RotateLR(AVLNode<T>*& ptr) {
    AVLNode<T>* subL = ptr->left;
    AVLNode<T>* subR = ptr;
    ptr = subL->right;

    //左旋
    subL->right = ptr->left;
    ptr->left = subL;
        //ptr无左节点就subL中没有右节点
    subL->BalanceFactor = ptr->BalanceFactor <= 0 ? 0 : -1;

    //右旋
    subR->left = ptr->right;
    ptr->right = subR;
        //ptr无右节点就subR中没有左节点
    subR->BalanceFactor = ptr->BalanceFactor >= 0 ? 0 : 1;

    ptr->BalanceFactor = 0;
}

//先右旋再左旋
template<class T>
void AVLTree<T>::RotateRL(AVLNode<T>*& ptr) {
    AVLNode<T>* subL = ptr;
    AVLNode<T>* subR = ptr->right;
    ptr = subR->left;

    //右旋
    subR->left = ptr->right;
    ptr->right = subR;
        //ptr无右节点就subR无左节点
    subR->BalanceFactor = ptr->BalanceFactor >= 0 ? 0 : 1;

    //左旋
    subL->right = ptr->left;
    ptr->left = subL;
        //ptr没有左节点时subL没有右节点
    subL->BalanceFactor = ptr->BalanceFactor <= 0 ? 0 : -1;

    ptr->BalanceFactor = 0;

}

//求某个节点的高度
template<class T>
int AVLTree<T>::Height(AVLNode<T>* ptr) const {
    if (! ptr) return 0;
    int LeftHeight = Height(ptr->left);
    int RightHeight = Height(ptr->right);
    return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
}