//
// Created by Levi on 2021/12/25.
//

#include "UnionFindSet.h"

//构造函数
UFSets::UFSets(int Size) {
    size = Size;
    parent = new int[size];
    //每个元素自成一个集合
    for (int i = 0; i < size; i++)
        parent[i] = -1;
}

//析构函数
UFSets::~UFSets() {
    size = -1;
    delete []parent;
}

//重载：集合赋值
UFSets& UFSets::operator=(UFSets &R) {
    this->size = R.size;
    this->parent = new int[size];
    for (int i = 0; i < size; i++)
        this->parent[i] = R.parent[i];
    return *this;
}

//基本合并：将root1接到root2下
void UFSets::Union(int Root1, int Root2) {
    //更新Root2的数量
    parent[Root2] += parent[Root1];
    //将Root1接到Root2下
    parent[Root1] = Root2;
    return;
}

//改进合并：加权合并
void UFSets::WeightedUnion(int Root1, int Root2) {
    //得到两个元素所在集合的元素个数，注意得到的都是负数
    int OneRootNodeCount = Find(Root1);
    int TwoRootNodeCount = Find(Root2);
    //如果两者所在的集合的元素数目相同，就可以直接基本合并
    //如果哪个元素所在集合的元素数目更多，就把少的那个放到多的那一个里面
    if (OneRootNodeCount == TwoRootNodeCount)
        Union(Root1, Root2);
    else if (OneRootNodeCount > TwoRootNodeCount)
        //1比2少，则1放到2里面
        Union(Root1, Root2);
    else
        //2比1少，则2放进1里面
        Union(Root2, Root1);
    return;
}

//基本搜寻
//迭代写法：
//int UFSets::Find(int x) {
//    while (parent[x] >= 0)
//        x = parent[x];
//    return x;
//}
//递归写法：
int UFSets::Find(int x) {
    if (parent[x] < 0) return x;
    return Find(parent[x]);
}

//改进搜寻：压缩路径
//搜寻的时候顺便将其他元素放到根节点下一层，减少其他操作时间
int UFSets::CollapsingFind(int x) {
    //如果x不在根结点下
    if (parent[x] != Find(x)) {
        parent[x] = Find(x);
    }
    return parent[x];
}