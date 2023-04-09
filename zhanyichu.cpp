#include<iostream>
using namespace std;
typedef struct
{
    int *base;
    int *top;
    int stacksize;
}SqStack;//文件操作,这里主要是数制转换，没有多个数需要存入，比较有必要的是前面写的，
//如果要实施可以写个链栈，前面还有个题目没写
//查一下C++的文件操作，看和C的区别，C的文件操作应该在画图的文件里
// 初始化
void InitStack(SqStack &S)
{
    S.base = new int[5];
    S.top = S.base;
    S.stacksize = 5;
}
void Push(SqStack &S, int e)
{
    if(S.top-S.base>=S.stacksize)
    {
        int *newbase = new int[S.stacksize+5];//申请新空间
        int *p = S.base;//将原栈中的元素复制到新栈中
        int *q = newbase;//q指向新栈的栈顶
        while(p!=S.top)//仔细判别p,q的区别
        {
            *q++ = *p++;
        }
        delete []S.base;//释放原栈空间？
        //这里的[]的意思是什么
        S.base = newbase;//将新栈的栈底指针赋值给S.base
        S.top = q;//将新栈的栈顶指针赋值给S.top
        S.stacksize += 5;//栈的大小增加5
    }
    *S.top++ = e;
}

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
    SqStack S;
    InitStack(S);
    int e;
    for(int i=0; i<10; i++)
    {
        Push(S, i);
        TraverseStack(S);
    }
    return 0;
}