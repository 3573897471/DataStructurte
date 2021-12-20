#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Student {
public:
    Student(string name = string(), long long number = 0, int result = -1) :
        Name(name), Number(number), Result(result) {}
private:
    string Name;
    long long Number;
    int Result;
};

#define maxSize 100
class List {
public:
    List() {
        Elements = new Student[maxSize];
    }
private:
    Student * Elements;
};

void test() {
    Student s1("Levi", 1, 0);
    Student s2("Yu",2, 1);

}