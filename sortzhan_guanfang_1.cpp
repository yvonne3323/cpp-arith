//顺序栈的基本操作
#include <iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;
Status InitStack(SqStack &S)
{
    S.base = new SElemType[MAXSIZE];
    if(!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
Status Push(SqStack &S, SElemType e)
{
    if(S.top-S.base>=S.stacksize)
        return ERROR;
    *S.top++ = e;
    return OK;
}
Status Pop(SqStack &S, SElemType &e)
{
    if(S.top==S.base)
        return ERROR;
    e = *--S.top;
    return OK;
}
Status GetTop(SqStack S, SElemType &e)
{
    if(S.top==S.base)
        return ERROR;
    e = *(S.top-1);
    return OK;
}
Status StackEmpty(SqStack S)
{
    if(S.top==S.base)
        return OK;
    else
        return ERROR;
}
void DestroyStack(SqStack &S)
{
    if(S.base)
        delete []S.base;
}
void ClearStack(SqStack &S)
{
    S.top = S.base;
}
int StackLength(SqStack S)
{
    return S.top-S.base;
}
void StackTraverse(SqStack S)
{
    SElemType *p;
    p = S.base;
    while(p<S.top)
        cout<<*p++<<" ";
    cout<<endl;
}


