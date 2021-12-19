//
// Created by 黎炜堂 on 2021/12/10.
//

#include "String.h"
#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//构造函数
String::String(int Size) {
    maxSize = Size;
    ch = new char[maxSize + 1]; 
    CurrentLength = 0;
    ch[0] = '\0';
    
}
String::String(const char * Words) {
    int len = strlen(Words);
    maxSize = (defaultSize > len) ? defaultSize : len;
    ch = new char[maxSize + 1];
    CurrentLength = len;
    for (int i = 0; i < len; i++) {
        ch[i] = Words[i];
    }
}
String::String(const String& ob) {
    maxSize = ob.maxSize;
    CurrentLength = ob.CurrentLength;
    ch = new char[maxSize];
    for (int i = 0;i < CurrentLength;i++) {
        ch[i] = ob.ch[i];
    }
}
//析构函数
String::~String() {
    maxSize = 0;
    CurrentLength = 0;
    delete ch;
}
//返回String的实际长度
int String::Length() const {
    return CurrentLength;
}
//pos位置开始连续读取len个字符组成子串并返回
String& String::operator() (int pos, int len) {
    String temp;
    if (pos < 0 || pos + len > CurrentLength || len < 0) {
        temp.CurrentLength = 0;
        temp.ch[0] = '\0';
    } else {
        int j = 0;
        temp.CurrentLength = len;
        temp.maxSize = len + 1;
        for (int i = pos;i <= len;i++ && j++) {
            temp.ch[j] = ch[i];
        }
        temp.ch[len] = '\0';
    }
    return temp;
}
//判断串是否相等
int String::operator== (String& ob) const {
    if (CurrentLength != ob.CurrentLength) return 0;
    for (int i = 0;i < CurrentLength;i++) {
        if (ch[i] != ob.ch[i]) return 0;
    }
    return 1;
}
//判定串是否不相等
int String::operator!= (String& ob) const {
    return ~(*this == ob);
}
//判定串是否为空
int String::operator! () const {
    if (CurrentLength == 0) return 1;
    else return 0;
}
//将ob串赋值给当前串
String& String::operator= (String& ob) {
    delete ch;
    maxSize = ob.maxSize;
    CurrentLength = ob.CurrentLength;
    ch = new char[maxSize];
    for (int i = 0;i < CurrentLength;i++) {
        ch[i] = ob.ch[i];
    }
}
//将串链接在当前串后面
String& String::operator+= (String& ob) {
    if ((ob.CurrentLength + this->CurrentLength) <= this->maxSize) {
        int i = CurrentLength - 1;
        this->CurrentLength += ob.CurrentLength;
        this->maxSize += ob.maxSize;
        for (int j = 0;i < CurrentLength;i++ && j++) {
            ch[i] = ob.ch[j];
        }
    } else {
        this->maxSize += ob.maxSize;
        //记录下原先的ch
        char *cpy = new char[CurrentLength];
        for (int i = 0;i < CurrentLength;i++) {
            cpy[i] = ch[i];
        }
        //重新分配ch的长度
        delete ch;
        ch = new char[maxSize];
        //重置了ch之后，复制原来的内容到新的ch中
        for (int i = 0;i < CurrentLength;i++) {
            ch[i] = cpy[i];
        }
        //复制ob到ch尾部
        int i = CurrentLength - 1;
        CurrentLength += ob.CurrentLength;
        for (int j = 0;i < CurrentLength;i++ && j++) {
            ch[i] = ob.ch[j];
        }
    }
    return *this;
}
//取第i个字符
char& String::operator[] (int i) {
    char c = ' ';
    if (i < 0 || i >CurrentLength) return c;
    else c = ch[i];
    return c;
}
//在当前串中寻找子串
int String::Find(String& ob) const {
    
}

void TestString() {

}

//int main() {
//    TestString();
//    return 0;
//}

