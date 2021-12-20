//
// Created by Levi on 2021/12/20.
//

#include<iostream>
#include<string.h>
#include <fstream>
#include <string>
#include"stdlib.h"
using namespace std;

struct Node{

    int num;
    char name[20];
    float Score;
    Node *next;
};
class StudList
{
private:
    Node *head;
public:
    StudList();
    void CreateList();//创建链表
    void Display(); //显示链表
    int Getlen() ; //获取链表长度
    Node *GetHead();
    void pushBack(); //尾部添加一个学生 信息
    void Insert(); //在指定位置插入一个学生
    int Delete(); //删除一个个学生
    int Update(); //修改一个个学生 的信息
    void Sort();//按成绩排序
    void FindByNum();	// 按学号查找
    void FindByName();  //按姓名查找
};

void menu(StudList *list);
//int main(){
//    StudList list;
//    list.CreateList();
//    menu(&list);
//    return 0;
//}

StudList::StudList()  //::是作用域操作符，表示你引用的变量限定在该作用域内。
{
    head=new Node();
    head->next=NULL;
}

//建立一个空表
void StudList::CreateList()
{
    head->num=0;
}

Node *StudList::GetHead(){
    return head;
}

void StudList::Display(){
    Node *cur=head;
    int len = Getlen();
    cout<<" 人数:"<<len<<endl;
    while(len--){
        cout<<"  学号："<<cur->num;
        cout<<"  姓名："<<cur->name;
        cout<<"  成绩："<<cur->Score;
        cout<<endl;
        cur=cur->next;
    }
}


//在单链表末尾加上一个学生的信息
void StudList::pushBack(){
    Node *cur,*p,*t;
    if(!head){
        head = new Node();
    }
    cur=head;
    p=new Node();
    t= head;

    while(cur->next){
        cur=cur->next;
    }
    cout<<" 输入学号："<<endl;
    cin>>p->num;
    while(t){
        if(t->num==p->num){
            cout<<" 已存在该学号！"<<endl;
            return;
        }
        t=t->next;
    }
    cout<<" 输入姓名："<<endl;
    cin>>p->name;
    cout<<" 输入成绩："<<endl;
    cin>>p->Score;

    if(head->num==0){
        head = p;
        return;
    }
    cur->next = p;
    p->next=NULL;
}
//获取单链表长度 （=学生总数）
int StudList::Getlen(){
    int n=0;
    Node *cur;
    cur=head;
    while( cur ){
        n++;
        cur=cur->next;
    }
    return n;
}

//在指定位置插入一个结点
void StudList::Insert(){
    int i,len;
    cout<<" 输入要插入学生的位置：";
    cin>>i;
    len=Getlen();

    Node *cur,*t,*pr,*newNode;
    if(head==NULL||head->num==0){
        cout<<" 当前表为空！"<<endl;
        StudList();
        return;
    }
    cur=head;
    pr = head;
    i-=1;
    while(cur&&i--){
        pr=cur;
        cur=cur->next;
    }
    newNode = new Node();
    t=head;
    cout<<" 输入插入学生的学号："<<endl;
    cin>>newNode->num;
    while(t){		//判断是否是已存在学号
        if(t->num==newNode->num){
            cout<<" 已存在该学号!"<<endl;
            return;
        }
        t=t->next;
    }
    cout<<" 输入姓名："<<endl;
    cin>>newNode->name;
    cout<<" 输入成绩："<<endl;
    cin>>newNode->Score;

    pr->next=newNode;
    newNode->next=cur;

}

//删除
int StudList::Delete() {//n表示学号
    int n;
    Node *cur,*pr;
    cur=head;
    pr=head;
    cout<<" 输入要删除学生的学号：";
    cin>>n;
    while(cur){
        if(cur->num==n){
            if(cur==head){//如果删除的是头节点，直接令头结点为头结点的下一结点
                head=head->next;
                return 1;
            }
            pr->next=cur->next;
            return 1; //若删除的是最后一个结点则不能使用 cur->next->next,前边已经 cur = cur->next;不许操作
        }
        pr=cur;
        cur=cur->next;
    }
    cout<<" 没有查到要删除的学号"<<endl;
    return -1;
}

//修改指定学号学生的信息
int StudList::Update(){//n为学号
    int a,n;
    Node *cur;
    cur=head;
    cout<<" 输入要修改学生的学号：";
    cin>>n;
    while(cur){
        if(cur->num==n){
            cout<<" 1.修改姓名"<<endl;
            cout<<" 2.修改成绩"<<endl;

            cout<<" 请输入要修改的项目(输入其它不做修改)：";
            cin>>a ;
            switch(a){
                case 1:
                    cout<<" 请输入修改姓名：";
                    cin>>cur->name;
                    return 1;
                case 2:
                    cout<<" 请输入修改的成绩：";
                    cin>>cur->Score;
                    return 1;

                default:
                    cout<<" 退出修改"<<endl;
                    return 1;
            }
        }
        cur=cur->next;
    }
    return -1;
}

//交换两结点的信息
void swapNode(Node *a,Node *b){
    int temp;
    char c;
    float ft;

    temp=a->num;
    a->num=b->num;
    b->num=temp;

//姓名交换
    for(int i=0;i<20;i++){
        c=a->name[i];
        a->name[i]=b->name[i];
        b->name[i]=c;
    }
//成绩交换
    ft=a->Score;
    a->Score=b->Score;
    b->Score=ft;

}

//按成绩排序
void StudList::Sort(){
    int len,inlen;
    Node *cur;
    len =Getlen();
    while(--len){
        inlen = len;
        cur = head;
        while(inlen--){
            if(cur->Score<cur->next->Score){
                swapNode(cur,cur->next);
            }
            cur=cur->next;
        }
    }
}

//按学号查找某一学生的信息
void StudList::FindByNum(){
    int n;
    int flag=0;
    Node *cur;
    cur=head;
    cout<<" 输入要查询的学生的学号：";
    cin>>n;
    while(cur!=NULL){
        if(cur->num==n){
            flag=1;
            cout<<" 下面是查找结果："<<endl;
            cout<<" 学号："<<cur->num<<" ";
            cout<<" 姓名："<<cur->name<<" ";
            cout<<" 成绩："<<cur->Score<<" ";
            cout<<endl;
        }
        cur=cur->next;
        if(flag==0){
            cout<<" 不存在该学号！"<<endl;
        }
    }

}

//按姓名查找某一学生的信息
void StudList::FindByName(){
    string name;
    int flag=0;
    Node *cur;
    cur=head;
    cout<<" 输入要查询的学生的姓名：";
    cin>>name;
    while(cur!=NULL){
        if(cur->name==name){
            flag=1;
            cout<<" 下面是查找结果："<<endl;
            cout<<" 学号："<<cur->num<<" ";
            cout<<" 姓名："<<cur->name<<" ";
            cout<<" 成绩："<<cur->Score<<" ";
            cout<<endl;
        }
        cur=cur->next;
    }
    if(flag==0){
        cout<<" 不存在该学生！"<<endl;
    }

}


//菜单
void menu(StudList *list){
    int a;
    while(1){
        //system("pause");
        system("cls");
        cout<<"**********************************"<<endl;
        cout<<"**  欢迎使用学生成绩表管理系统  **"<<endl;
        cout<<"**********************************"<<endl;
        cout<<"********************************"<<endl;
        cout<<"*   1.添加一个学生成绩。        *"<<endl;
        cout<<"*   2.删除一个学生成绩。        *"<<endl;
        cout<<"*   3.修改一个学生成绩。        *"<<endl;
        cout<<"*   4.插入一个学生成绩。        *"<<endl;
        cout<<"*   5.显示学生成绩表。          *"<<endl;
        cout<<"*   6.按成绩排序。              *"<<endl;
        cout<<"*   7.计算学生的总数。          *"<<endl;
        cout<<"*   8.按学号查找学生。          *"<<endl;
        cout<<"*   9.按姓名查找学生。          *"<<endl;
        cout<<"********************************"<<endl;
        cin>>a;
        switch(a){
            case 1:
                list->pushBack();
                break;

            case 2:
                list->Display();
                list->Delete();
                list->Display();
                break;

            case 3:
                list->Display();
                list->Update();
                list->Display();
                break;

            case 4:
                list->Display();
                list->Insert();
                list->Display();
                break;
            case 5:
                list->Display();
                break;

            case 6:
                list->Sort();
                list->Display();
                break;

            case 7:
                list->Getlen();
                list->Display();
                break;

            case 8:
                list->FindByNum();
                break;

            case 9:
                list->FindByName();
                break;
        }
    }
}

