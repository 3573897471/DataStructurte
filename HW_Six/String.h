//
// Created by 黎炜堂 on 2021/12/10.
//

#ifndef HOMEWORK_STRING_H
#define HOMEWORK_STRING_H

const int defaultSize = 128;
class String {
private:
    char *ch;
    int CurrentLength;
    int maxSize;
public:
    //构造函数
    String(int Size = defaultSize);
    String(const char * Words);
    String(const String& ob);
    //析构函数
    ~String();
    //返回String的实际长度
    int Length() const;
    //pos位置开始连续读取len个字符组成子串并返回
    String& operator() (int pos, int len);
    //判断串是否相等
    int operator== (String& ob) const;
    //判定串是否不相等
    int operator!= (String& ob) const;
    //判定串是否为空
    int operator! () const;
    //将ob串赋值给当前串
    String& operator= (String& ob);
    //将串链接在当前串后面
    String& operator+= (String& ob);
    //取第i个字符
    char& operator[] (int i);
    //在当前串中寻找子串
    int Find(String& ob) const;
};
#endif //HOMEWORK_STRING_H
