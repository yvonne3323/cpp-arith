#include <iostream>
using namespace std;
typedef struct
{
    int *base;
    int *top;
    int stacksize;
} SqStack;

// 初始化
void InitStack(SqStack &S)
{
    S.base = new int[100];
    if (!S.base)
        exit(-2);
    S.top = S.base;
    S.stacksize = 100;
}

// 入栈
void Push(SqStack &S, int e)
{
    if (S.top - S.base >= S.stacksize)
    {
        int *newbase = new int[S.stacksize + 100];
        int *p = S.base;
        int *q = newbase;
        while (p != S.top)
        {
            *q++ = *p++;
        }
        delete S.base;
        S.base = newbase;
        S.top = q;
        S.stacksize += 100;
    }
    *S.top++ = e;
}

// 出栈
void Pop(SqStack &S, int &e)
{
    if (S.top == S.base)
        exit(-1);
    e = *--S.top;
}

// 取栈顶元素
int GetTop(SqStack S)
{
    if (S.top == S.base)
        exit(-1);
    return *(S.top - 1);
}

// 销毁栈
void DestroyStack(SqStack &S)
{
    delete S.base;
    S.stacksize = 0;
    S.base = S.top = NULL;
}

// 清空栈
void ClearStack(SqStack &S)
{
    S.top = S.base;
}

// 遍历栈
void TraverseStack(SqStack S)
{
    int *p = S.base;
    while (p != S.top)
    {
        cout << *p << " ";
        p++;
    }
    cout << endl;
}

int main()
{
    // 十进制转为其他进制
    SqStack S;
    InitStack(S);
    int m, n, i;
    cout << "请输入一个十进制数:" << endl;
    cin >> n;
    cout << "请输入要转换的进制:" << endl;
    cin >> m;
    while (n)
    {
        Push(S, n % m);
        n /= m;
    }
    cout << "转换后的数为:" << endl;
    while (S.top != S.base)
    {
        Pop(S, i);
        cout << i;
    }
    {
        Pop(S, i);
        cout << i;
    }
    cout << endl;

    return 0;
}
