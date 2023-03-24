#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h> //exit() malloc() free()
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
#define ElementType int
typedef int Status;
typedef struct 
{
    ElementType *elem;
    int length;
}Sqlist;

/* 初始化 */
Status InitList(Sqlist &L)
{
    L.elem = (ElementType *)malloc(MAXSIZE * sizeof(ElementType));
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    cout << "初始化成功" << endl;
    return OK;
}

/* 查找 */
// #define ERROR -1

// Position Find( List L, ElementType X )
// {
//     Position i = 0;

//     while( i <= L->Last && L->Data[i]!= X )
//         i++;
//     if ( i > L->Last )  return ERROR; /* 如果没找到，返回错误信息 */
//     else  return i;  /* 找到后返回的是存储位置 */
// }

/* 插入 */
/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
/*bool*/
Status Insert( Sqlist &L, ElementType X, int i )
{ /* 在L的指定位置P前插入新元素X */
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
    L.length++;
    return OK;
}

/* 删除 */
/*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
// void Delete( List L, Position P )
// { /* 从L中删除指定位置P的元素 */
//     Position i;

//     if( P<0 || P>L->Last ) { /* 检查空表及删除位置的合法性 */
//         printf("位置%d不存在元素", P ); 
//         return; 
//     }
//     for( i=P+1; i<=L->Last; i++ )
//         L->Data[i-1] = L->Data[i]; /* 将位置P+1及以后的元素顺序向前移动 */
//     L->Last--; /* Last仍指向最后元素 */
//     return;   
// }

int main()
{
    Sqlist L;
    InitList(L);
    Insert(L, 'a', 0);
    Insert(L, 'b', 1);
    int X,i;
    scanf("%c %d",&X,&i);
    Insert(L, X, i);

}