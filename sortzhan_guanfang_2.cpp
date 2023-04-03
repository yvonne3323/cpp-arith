//顺序栈实现进制转换
#include <iostream>
using namespace std;
typedef struct
{
    int *base;
    int *top;
    int stacksize;
} SqStack;
void InitStack(SqStack &S)
{
    S.base = new int[100];
    S.top = S.base;
    S.stacksize = 100;
}
void StackEmpty(SqStack S)
{
    if (S.top == S.base)
        cout << "栈空" << endl;
}

void Push(SqStack &S, int e)
{
    //如果超过maxsize,分配新空间
    if (S.top - S.base >= S.stacksize)
    {
        int *newbase = new int[S.stacksize + 100];
        int *p = S.base;
        int *q = newbase;
        while (p != S.top)
        {
            *q++ = *p++;
        }
        delete[] S.base;
        S.base = newbase;
        S.top = q;
        S.stacksize += 100;
    } //思考
    *S.top++ = e;
}
void Pop(SqStack &S, int &e)
{
    StackEmpty(S);
    e = *--S.top;
}
void GetTop(SqStack S, int &e)
{
    StackEmpty(S);
    e = *(S.top - 1);
}
void conversion(int N, int D)
{//进制转换关键步骤
    SqStack S;
    InitStack(S);
    int e;
    while (N)
    {
        Push(S, N % D);
        N = N / D;
    }
    while (S.top != S.base)
    {
        Pop(S, e);
        cout << e;
    }
    cout << endl;
}
int main()
{
    int N, D;
    cin >> N >> D;
    conversion(N, D);
    return 0;
}
