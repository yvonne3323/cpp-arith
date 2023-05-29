//双向链表

#include <iostream>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *prior, *next;
} LNode, *LinkList;

// 初始化
void InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    L->prior = NULL;
}

// 创建
void CreateList(LinkList &L, int n)
{
    LNode *p, *q;
    int i;
    while (n < 0)
    {
        cout << "输入不合法，请重新输入" << endl;
        cin >> n;
    }
    cout << "请输入要创建的元素(请逆序输入)：";
    for (i = 0; i < n; i++)
    {
        p = new LNode;
        cin >> p->data;
        p->next = L->next;
        if (L->next != NULL)
            L->next->prior = p;
        L->next = p;
        p->prior = L;
    }
    cout << "创建成功" << endl;
}

// 遍历
void ListTraverse(LinkList L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 插入
int ListInsert(LinkList &L, int i, int e)
{//在第i个位置之前插入元素e
    LNode *p = L, *s;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i - 1)
    {
        cout << "插入位置不合法" << endl;
        return 0;
    }
    s = new LNode;
    s->data = e;
    s->prior = p->prior;
    
    cout << "插入成功" << endl;
    return 1;
}

// 删除
int ListDelete(LinkList &L, int i)
{
    LNode *p = L, *q;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i - 1)
    {
        cout << "删除位置不合法" << endl;
        return 0;
    }
    q = p->next;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    delete q;
    cout << "删除成功" << endl;
    return 1;
}

// 求表长
int ListLength(LinkList L)
{
    int n = 0;
    LNode *p = L->next;
    while (p != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}

// 按位查找
int GetElem(LinkList L, int i)
{
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i)
    {
        cout << "查找位置不合法" << endl;
        return 0;
    }
    return p->data;
}

// 按值查找
int LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    int i = 1;
    while (p != NULL && p->data != e)
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
    {
        cout << "查找失败" << endl;
        return 0;
    }
    return i;
}


// 清空
void ClearList(LinkList &L)
{
    LNode *p = L->next, *q;
    while (p != NULL)
    {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL;
    cout << "清空成功" << endl;
}

int main()
{

    return 0;
}
