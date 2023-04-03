#include<iostream>
using namespace std;
//完整顺序：顺序栈实现进制转换
//查找完整要求
typedef struct
{
    int *base;
    int *top;
    int stacksize;
}SqStack;

// 初始化
void InitStack(SqStack &S)
{
    S.base = new int[100];
    S.top = S.base;
    S.stacksize = 100;
}

//判断栈空
void StackEmpty(SqStack S)
{
    if(S.top==S.base)
        cout << "栈空" << endl;
}
// 入栈
void Push(SqStack &S, int e)
{
    //如果超过maxsize,分配新空间
    if(S.top-S.base>=S.stacksize)
    {
        int *newbase = new int[S.stacksize+100];
        int *p = S.base;
        int *q = newbase;
        while(p!=S.top)
        {
            *q++ = *p++;
        }
        delete []S.base;
        S.base = newbase;
        S.top = q;
        S.stacksize += 100;
    } //思考 
    *S.top++ = e;
}

// 出栈
void Pop(SqStack &S, int &e)
{
    StackEmpty(S);
    e = *--S.top;
}

// 取栈顶元素
void GetTop(SqStack S, int &e)
{
    StackEmpty(S);
    e = *(S.top-1);
}

// 销毁栈(有问题)
void DestroyStack(SqStack &S)
{
    delete []S.base;
    //如果不置空，会出现野指针
    S.base = NULL;
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
    while(p!=S.top)
    {
        cout << *p << " ";
        p++;
    }
    cout << endl;
}

int main()
{

}

