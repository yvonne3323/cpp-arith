//循环链表
#include<iostream>
using namespace std;

//存储结构
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//循环链表的初始化
//步骤：建立一个带头结点的单链表，头结点的指针域指向头结点本身
int InitList(LinkList &L)
{
    L = new LNode;
    if (!L)
        exit(-2);
    L->next = L;
    return 1;
}

//循环链表的插入
//步骤：判断插入位置是否合法，找到插入位置的前驱，插入，表长加一
int ListInsert(LinkList &L,int i,int e)
{
    if (i<1)
        return 0;
    LNode *p = L;
    int j = 0;
    while (p && j<i-1)
    {
        p = p->next;
        ++j;
    }
    if (!p)
        return 0;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}

//循环链表的删除
//步骤：判断删除位置是否合法，找到删除位置的前驱，删除，表长减一
int ListDelete(LinkList &L,int i,int &e)
{
    if (i<1)
        return 0;
    LNode *p = L;
    int j = 0;
    while (p->next && j<i-1)
    {
        p = p->next;
        ++j;
    }
    if (!(p->next))
        return 0;
    LNode *q = p->next;
    p->next = q->next;
    e = q->data;
    delete q;
    return 1;
}

//循环链表的遍历
//步骤：从头结点开始，依次输出每个结点的值
int ListTraverse(LinkList L)
{
    LNode *p = L->next;
    while (p!=L)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
    return 1;
}

int main()
{
    LinkList L;
    InitList(L);
    for (int i=0;i<10;i++)
    {
        ListInsert(L,i+1,i);
    }
    ListTraverse(L);
    int e;
    ListDelete(L,5,e);
    cout<<e<<endl;
    ListTraverse(L);
    return 0;
}
