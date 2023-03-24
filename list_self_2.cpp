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
    cout << "1.初始化" << endl;
    cout << "2.取值" << endl;
    cout << "3.查找" << endl;
    cout << "4.插入" << endl;
    cout << "5.删除" << endl;
    cout << "6.遍历" << endl;
    cout << "7.销毁" << endl;
    cout << "8.清空" << endl;
    cout << "9.退出" << endl;
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
/* 销毁 */
void DestroyList(Sqlist &L)
{
    free(L.elem);
    L.length = 0;
    cout << "销毁成功" << endl;
}

/* 取值 */

/* 查找 */

/* 插入 */
int Insert( Sqlist &L, int X, int i ) //L 表 X 元素 i 插入位置
{ 
    int j;
    if (L.length == 100) /* 顺序线性表已经满 */
    {//一开始忘记大括号了！！！
        cout << "顺序线性表已经满" << endl;
        return 0;
    }
    if (i < 1 || i > L.length+1) /* 当i小于1或者大于表长加1时 */
    {
        cout << "插入位置不合法" << endl;
        return 0;
    }
    if (i <= L.length) /* 若插入数据位置不在表尾 */
    {
        for (j = L.length-1; j >= i-1; j--)
            L.elem[j+1] = L.elem[j]; /* 将要插入位置后数据元素向后移动一位 */
    }
    L.elem[i-1] = X; /* 将新元素插入 */
    L.length++;
    return 1;
}

/* 删除 */

/* 遍历 */

/*销毁*/

/*清空*/

int main()
{
    int input = 0;
    do
    {
        Menu();
        cin >> input;
        switch (input)
        {
        case 1:
            /* 初始化 */
            //进行初始化考虑到的问题：1是否有必要把初始化放入循环中？2初始化两次会造成什么后果：比如第一次的初始化列表内容是否还可以找到，怎么找
            //如果要消除或销毁第一次初始化后再进行第二次初始化应该怎么做
            //现在可以确定下面的L是可以更改的
            //调试可知再次初始化后，第一次初始化的内容没有了,不确定是否被销毁
            Sqlist L;
            InitList(L);
            break;
        case 2:
            /* 取值 */
            break;
        case 3:
            /* 查找 */
            break;
        case 4:
            /* 插入 */
            printf ("请输入插入的元素和位置：");
            int X, i;
            scanf ("%d %d", &X, &i);            
            Insert(L, X, i);
            break;
        case 5:
            /* 删除 */
            break;
        case 6:
            /* 遍历 */
            break;
        case 7:
            /* 销毁 */
            break;
        case 8:
            /* 清空 */
            break;
        default:
            break;
        }
    } while (input != 9);
    return 0;
//问题：如果一开始想一次性输入一些数据怎么办，插入不能改，之后的小部分修改需要用到
//老师讲链表的时候讲了最开始的创建 - 已建立创建 - 问题解决
//一开始忘记大括号了！！！(python) lyt- try-except用法
//初始化问题(初始化程序已提取出)——即单个列表 void类型 
//错误：重新输入 while ,用if会直接退出
 //问题：销毁后，再次使用会出现问题，因为没有初始化
//既然单个列表，销毁后没必要再使用程序，即退出程序
}