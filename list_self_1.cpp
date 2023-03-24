#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct
{
    int *elem;
    int length;
}Sqlist;

/* 菜单 */
void Menu()
{
    cout << "**********菜单**********" << endl;
    cout << "1.取值 " << endl;
    cout << "2.查找" << endl;
    cout << "3.插入" << endl;
    cout << "4.删除" << endl;
    cout << "5.遍历" << endl;
    cout << "6.清空" << endl;
    cout << "7.退出" << endl;
    cout << "************************" << endl;
}

/* 初始化 */
void InitList(Sqlist &L)
{
    L.elem = (int *)malloc(100 * sizeof(int));
    if (!L.elem)
        exit(-2);
    L.length = 0;
    cout << "初始化成功" << endl;
}

/* 创建 */
void CreateList(Sqlist &L, int n)
{
    while (n < 0 || n > 100)
    {
        cout << "输入不合法，请重新输入" << endl;
        cin >> n;
    }
    if (n != 0)
    {
        printf("请输入要创建的元素：");
        for (int i = 0; i < n; i++)
            cin >> L.elem[i];
    }
    L.length = n;
    cout << "创建成功" << endl;
}

/* 取值 */
void GetValue(Sqlist &L, int i)
{
    if (i < 1 || i > L.length)
    {
        cout << "位置不合法" << endl;
        return;
    }
    cout << "第" << i << "个元素为：" << L.elem[i-1] << endl;
}

/* 查找 */
void FindValue(Sqlist &L, int X)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.elem[i] == X)
        {
            cout << "元素" << X << "在第" << i+1 << "个位置" << endl;
            return;
        }
    }
    cout << "元素" << X << "不存在" << endl;
}

/* 插入 */
void Insert( Sqlist &L, int X, int i )
{
    int j;
    if (L.length == 100) /* 顺序线性表已经满 */
    {
        cout << "顺序线性表已经满" << endl;
        return;
    }
    if (i < 1 || i > L.length+1) /* 当i小于1或者大于表长加1时 */
    {
        cout << "插入位置不合法" << endl;
        return;
    }
    if (i <= L.length)
    {
        for (j = L.length-1; j >= i-1; j--)
            L.elem[j+1] = L.elem[j]; /* 将要插入位置后数据元素向后移动一位 */
    }
    L.elem[i-1] = X; /* 将新元素插入 */
    L.length++;
    cout << "插入成功" << endl;
}

/* 删除 */
void Delete(Sqlist &L, int i)
{
    int j;
    if (i < 1 || i > L.length)
    {
        cout << "删除位置不合法" << endl;
        return;
    }
    if (i < L.length)
    {
        for (j = i; j < L.length; j++)
            L.elem[j-1] = L.elem[j];
    }
    L.length--;
    cout << "删除成功" << endl;
}

/* 遍历 */
void Traverse(Sqlist &L)
{
    int i;
    for (i = 0; i < L.length; i++)
        cout << L.elem[i] << " ";
    cout << endl;
}

/* 销毁 */
void Destroy(Sqlist &L)
{
    free(L.elem);
    L.length = 0;
}

/* 清空 */
void Clear(Sqlist &L)
{
    L.length = 0;
    cout << "清空成功" << endl;
}

int main()
{
    int input = 0;
    Sqlist L;
    InitList(L);

    /* 创建 */
    printf("请输入要创建的元素个数：");
    int B;
    scanf("%d", &B);
    CreateList(L, B);
    
    do
    {
        Menu();
        cin >> input;
        switch (input)
        {
        case 1:
            /* 取值 */
            printf("请输入要取值的位置：");
            int k;
            cin >> k;
            GetValue(L, k);
            break;
        case 2:
            /* 查找 */
            printf("请输入要查找的元素：");
            int F;
            cin >> F;
            FindValue(L, F);
            break;
        case 3:
            /* 插入 */
            printf("请输入要插入的元素和位置：");
            int X, i;
            cin >> X >> i;
            Insert(L, X, i);
            break;
        case 4:
            /* 删除 */
            printf("请输入要删除的位置：");
            int D;
            cin >> D;
            Delete(L, D);
            break;
        case 5:
            /* 遍历 */
            Traverse(L);
            break;
        case 6:
            /* 清空 */
            Clear(L);
            break;
        case 7: 
            /* 退出 */
            cout << "退出" << endl;
            /* 销毁 */
            Destroy(L);
            break;
        default:
            cout << "输入错误" << endl;
            break;
        }
    } while (input != 7);
    return 0;
}