#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
#define ElementType char
typedef int Status;
typedef struct 
{
    ElementType *elem;
    int length;
}SqList;

/* 初始化 */
Status InitList(SqList &L)
{
    L.elem = new ElementType[MAXSIZE];
    //l.elem = (char *)malloc(100*sizeof(char));
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return OK;
}

/* 取值 */
ElementType GetElem(SqList L, int i,ElementType &e)
{
    if(i<1 || i>L.length) 
        return ERROR;
    e = L.elem[i-1];
    return OK;
}
/*销毁*/
void DestroyList(SqList &L)
{
    if(L.elem)
        delete []L.elem;
}
/*清空*/
void ClearList(SqList &L)
{
    L.length = 0;
}
/* 查找 */
int LocateElem(SqList L, ElementType e)
{
    int i;
    for(i=0;i<L.length;i++)
        if(L.elem[i]==e)
            return i+1;
    return 0;
}

/* 插入 */
Status ListInsert(SqList &L, int i, ElementType e)
{
    int j;
    if(i<1 || i>L.length+1)
        return ERROR;
    if(L.length>=MAXSIZE)
        return ERROR;
    for(j=L.length-1;j>=i-1;j--)
        L.elem[j+1] = L.elem[j];
    L.elem[i-1] = e;
    L.length++;
    return OK;
}

/* 删除 */
Status ListDelete(SqList &L, int i, ElementType &e)
{
    int j;
    if(i<1 || i>L.length)
        return ERROR;
    e = L.elem[i-1];
    for(j=i;j<L.length;j++)
        L.elem[j-1] = L.elem[j];
    L.length--;
    return OK;
}

/* 遍历 */
void ListTraverse(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
        printf("%c ",L.elem[i]);
    printf("\r");
}

int main()
{
    
    return 0;
}