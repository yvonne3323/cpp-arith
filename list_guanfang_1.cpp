#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h> //exit() malloc() free()
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 3
#define ElementType int
typedef int Status;//Status是函数返回值的类型，其值是函数结果状态代码
typedef struct 
{
    ElementType *elem;
    int length;
}Sqlist;

/* 初始化 */
Status InitList(Sqlist &L)
{
    L.elem = (ElementType *)malloc(MAXSIZE * sizeof(ElementType));
    // L.elem = new ElementType[MAXSIZE]; //指针变量 = new 类型[数组长度]
    //释放内存：delete 指针变量;
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    cout << "初始化成功" << endl;
    return OK;
}

/* 查找 */
int LocateElem( Sqlist L, ElementType X )
{ /* 在顺序线性表L中查找值为X的元素，如果找到，返回其在表中序号表示成功；否则返回0表示失败 */
    int i;
    for (i = 0; i < L.length; i++)
        if (L.elem[i] == X)
            return i+1;
    return 0;
}//O(n)

/*取值*/ 
Status GetElem( Sqlist L, int i, ElementType &e )
{ /* 在顺序线性表L中查找序号为i的元素，如果找到，返回其值；否则返回0表示失败 */
    if (i < 1 || i > L.length)
        return ERROR;
    e = L.elem[i-1];
    return OK;
}//O(1)  //取到了怎么显示：cout << e << endl;


/* 插入 */
Status Insert( Sqlist &L, ElementType X, int i )
{ /* 在L的指定位置i前插入新元素X */
    int j;
    if (L.length == MAXSIZE) /* 顺序线性表已经满 */
        return ERROR;
    if (i < 1 || i > L.length+1) /* 当i小于1或者大于表长加1时 */
        return ERROR;
    if (i <= L.length) /* 若插入数据位置不在表尾 */
    {
        for (j = L.length-1; j >= i-1; j--)
            L.elem[j+1] = L.elem[j]; /* 将要插入位置后数据元素向后移动一位 */
    }
    L.elem[i-1] = X; /* 将新元素插入 */
    ++L.length; /* 表长增1 */ //用L.length++有影响吗？——有，
    return OK;
}

/* 删除 */
Status ListDelete (Sqlist &L, int i)
{
    int j;
    if (i<1 || i>L.length)
        return ERROR;
    for (j=i;j<L.length;j++)//如果刚好是表尾，那么就不用移动了，直接减少长度就行
        L.elem[j-1]=L.elem[j];
    L.length--;//--L.length;
    return OK;
}//O(n)

/* 遍历 */
Status ListTraverse( Sqlist L )
{ /* 依次输出顺序线性表L中的每个元素 */
    int i;
    for (i = 0; i < L.length; i++)
        cout << L.elem[i] << " ";
    cout << endl;//换行
    return OK;
}


int main()
{
    Sqlist L;
    InitList(L);
    Insert(L, 1, 1);
    Insert(L, 2, 2);
    Insert(L, 3, 3);
    ListDelete(L, 3);
    ListTraverse(L);

}