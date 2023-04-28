// 线性表链式储存结构
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 菜单
void Menu()
{
    cout << "**********菜单**********" << endl;
    cout << "1.取值 " << endl;
    cout << "2.查找" << endl;
    cout << "3.插入" << endl;
    cout << "4.删除" << endl;
    cout << "5.遍历" << endl;
    cout << "6.表长" << endl;
    cout << "7.清空" << endl;
    cout << "8.退出" << endl;
    cout << "************************" << endl;
}
// 初始化
void InitList(LinkList &L)
{
    L = new LNode;  // 创建头结点
    L->next = NULL; // 头结点指针域为空
    cout << "初始化成功" << endl;
}

// 创建
void CreateList(LinkList &L, int n)
{
    LNode *p;
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
        L->next = p;
    }
    cout << "创建成功" << endl;
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

// 遍历
void DispList(LinkList L)
{
    LNode *p = L->next;
    cout << "链表：";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 插入
bool ListInsert(LinkList &L, int i, int e)
{
    int j = 0;
    LNode *p = L, *s;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 删除
void ListDelete(LinkList &L, int i, int &e)
{
    int j = 0;
    LNode *p = L, *q;

    while (p->next != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p->next == NULL)
    {
        cout << "删除位置不合法" << endl;
        return;
    }
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    cout << "删除的元素为" << e << endl;
}

// 查找
int LocateElem(LinkList L, int e)
{
    int i = 0;
    LNode *p = L->next;
    while (p != NULL)
    {
        i++;
        if (p->data == e)
            return i;
        p = p->next;
    }
    return 0;
}
// 取值
bool GetElem(LinkList L, int i, int &e)//第i个元素的值为e
{
    int j = 0;
    LNode *p = L->next;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    e = p->data;
    return true;
}

// 清空
void ClearList(LinkList &L)
{
    LNode *p = L->next, *q;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

int main()
{
    LinkList L;

    /* 初始化 */
    InitList(L);

    /* 创建 */
    int n;
    cout << "请输入要创建的元素个数：";
    while (n < 0)
    {
        cout << "输入不合法，请重新输入" << endl;
        cin >> n;
    }
    cin >> n;
    CreateList(L, n);

    /* 遍历 */
    DispList(L);

    do
    {
        Menu();
        int choice;
        cout << "请输入你的选择：";
        cin >> choice;
        switch (choice)
        {
        /* 取值 */
        case 1:
        {
            int i, e;
            cout << "请输入要取值的位置：";
            cin >> i;
            if (GetElem(L, i, e))
                cout << "第" << i << "个元素的值为：" << e << endl;
            else
                cout << "输入不合法" << endl;
            break;
        }
        /* 查找 */
        case 2:
        {
            int e;
            cout << "请输入要查找的元素：";
            cin >> e;
            int i = LocateElem(L, e);
            if (i)
                cout << "元素" << e << "的位置为：" << i << endl;
            else
                cout << "元素" << e << "不存在" << endl;
            break;
        }
        /* 插入 */
        case 3:
        {
            int i, e;
            cout << "请输入要插入的位置：";
            cin >> i;
            cout << "请输入要插入的元素：";
            cin >> e;
            if (ListInsert(L, i, e))
                cout << "插入成功" << endl;
            else
                cout << "插入失败" << endl;
            break;
        }
        /* 删除 */
        case 4:
        {
            int i, e;
            cout << "请输入要删除的位置：";
            cin >> i;
            ListDelete(L, i, e);
            break;
        }
        /* 遍历 */
        case 5:
        {
            DispList(L);
            break;
        }
        /* 求表长 */
        case 6:
        {
            cout << "表长为：" << ListLength(L) << endl;
            break;
        }
        /* 清空 */
        case 7:
        {
            ClearList(L);
            cout << "清空成功" << endl;
            break;
        }
        /* 退出 */
        case 8:
        {
            exit(0);
        }
        default:
        {
            cout << "输入不合法" << endl;
            break;
        }
        }
    } while (1);
    return 0;
}
