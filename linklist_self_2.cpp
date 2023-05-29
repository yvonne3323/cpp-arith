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
//解析：指针p指向首元结点，j做计数器，顺着next向下访问
//只要p非空并且没有达到序号为i的结点(p指向下一个结点，j相应加一)，用参数e保存当前结点数据域
//退出循环时，如果p为空或者j>i,说明第i个结点不存在
int GetElem(LinkList L,int i,int &e)
{
    LNode *p = L->next;
    int j = 1;
    while(p&&j<i)
    {
        p = p->next;
        ++j;
    }
    if (!p||j>i)
        return 0;
    e = p->data;
    return 1;
}

//查找
//步骤：指针p指向首元结点,顺next查找，
//只要当p不为空，并且p所指的数据域不等于e,则循环(p指向下一个结点)
//p为结点的地址值//NULL
LNode *LocateElem(LinkList L,int e)
{
    LNode *p = L->next;
    while(p&& p->data!=e)
    {
        p= p->next;
    }
    return p;
}

//插入(将e插入第i个结点位置)
//步骤：查找a(i-1),p指向该结点
//生成新结点，数据域置为e
//新结点指针域指向ai
//结点*p指针域指向新结点
int ListInsert(LinkList &L,int i,int e)
{
    int j = 0;
    LNode *p = L, *s;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return 0;
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

//删除
//步骤：查找ai-1,p指向该结点
//临时保存ai的地址在q
//*p指针域指向ai的直接后继
//释放ai空间
int ListDelete(LinkList &L,int i)
{
    int j = 0;
    LNode *p = L, *q;
    while (p ->next && j < i - 1)//p为空不足以判断，因为p指向的是ai-1
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1)
        return 0;
    q = p->next;
    p->next = q->next;
    //e = q->data; 若想保存删除的数据，可以用e保存
    delete q;
    return 1;
}

//创建单链表
//头插法
//步骤：初始化头结点
//循环：生成新结点，元素赋给数据域，新结点插到头结点之后
//顺序是反的
void CreateListF(LinkList &L,int n)
{//逆序输入
    LNode *p;
    int i;
    L = new LNode;//初始化
    L->next = NULL;
    for (i = 0; i < n; i++)
    {
        p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}
//尾插法
//步骤：创建空链表
//尾指针r初始化，指向头结点
//循环：生成新结点，元素赋给数据域，新结点插到尾结点之后，尾指针r指向新结点
int CreateListR(LinkList &L,int n)
{//顺序输入
    LNode *p,*r;
    int i;
    L = new LNode;
    L->next = NULL;
    r = L;//r指向头结点
    for (i = 0; i < n; i++)
    {
        p = new LNode;
        cin >> p->data;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return 1;
}

//遍历
//步骤：指针p指向首元结点，顺next向下访问
//只要p非空，输出p所指结点的数据域，p指向下一个结点
void ListTraverse(LinkList L)
{
    LNode *p = L->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//清空单链表
//步骤：指针p指向首元结点，顺next向下访问
//只要p非空，释放p所指结点，p指向下一个结点
void ClearList(LinkList &L)
{
    LNode *p = L->next, *q;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL;
}

//动态增长内存
//在原有的基础上增加len个结点
void IncreaseSize(LinkList &L,int len)
{
    
}

//计算单链表长度
//步骤：指针p指向首元结点，顺next向下访问
//只要p非空，计数器加一，p指向下一个结点
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L->next;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}


int main()
{
    LinkList L;
    int n;
    cin >> n;
    CreateListR(L, n);
    ListTraverse(L);
    ClearList(L);
    ListTraverse(L);
    return 0;
}