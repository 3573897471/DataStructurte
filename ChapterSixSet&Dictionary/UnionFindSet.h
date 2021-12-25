//
// Created by Levi on 2021/12/25.
//

#ifndef HOMEWORK_UNIONFINDSET_H
#define HOMEWORK_UNIONFINDSET_H
//并查集
const int DefaultSize = 100;
class UFSets {
public:
    //构造函数
    UFSets(int Size = DefaultSize);
    //析构函数
    ~UFSets();
    //重载：集合赋值
    UFSets& operator = (UFSets& R);
    //基本合并
    void Union(int Root1, int Root2);
    //改进合并：加权合并
    void WeightedUnion(int Root1, int Root2);
    //基本搜寻
    int Find(int x);
    //改进搜寻：压缩路径
    int CollapsingFind(int x);

private:
    //父节点数组
    int *parent;
    //数组大小
    int size;
};

#endif //HOMEWORK_UNIONFINDSET_H
