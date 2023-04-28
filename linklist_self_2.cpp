//单链表
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct 
{
    char no[20];
    char name[50];
    float price;
}Book;

//定义
//解析：同一结构体类型起了两个名称，LinkList 和 LNode*(提高程序的可读性)
typedef struct LNode
{
    int data;//int可以换成Book
    struct LNode *next;
}LNode,*LinkList;//存在两个名字：LinkList(定义单链表头指针) 和 LNode*(定义指向单链表中某个结点的指针)

//LNode *p, p为指向某结点的指针变量，表示结点地址， *p 对应的结点变量，表示该结点的名称
//首元结点：储存第一个数据元素的结点
//头结点：首元结点之前设的结点，指针域指向首元结点
//头指针：指向第一个结点的指针
//设置头结点好处：对第一个元素处理与其他元素一致；便于空表和非空表的统一处理

//初始化
//解析：生成新结点作为头结点，头指针指向头结点，头结点指针域置空
void InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
}

//取值
//解析：指针p指向首元结点，j做计数器，顺着next向下访问，循环(p指向下一个结点，j相应加一)，用参数e保存当前结点数据域
void GetElem(LinkList L,int i,int &e)
{
    LNode *p = L->next;
    int j = 1;
    while(p&&j<i)
    {
        p = p->next;
        ++j;
    }
    if (!p||j>i)
        return;
    e = p->data;
    return;
}

//查找
//步骤：指针p指向首元结点,顺next查找，不符合条件进入循环(p指向下一个结点)，p为结点的地址值
LNode *LocateElem(LinkList L,int e)
{
    LNode *p = L->next;
    while(p&& p->data!=e)
    {
        p= p->next;
    }
    return p;
}