//在非主函数的函数里尽量不要出现输出，因为这是主函数的事情
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//存储结构
typedef struct
{
    int *elem;
    int length;
}SqList;

//初始化
//步骤：为顺序表L动态分配一个预定义大小的数组空间，使elem指向这段空间的基地址，表的当前长度设为0
int IniitList (SqList &L)//引用：改变L;
{
    L.elem = new int[100];//分配一个数组空间
    if (!L.elem)
        exit(-2);//这个x是返回给操作系统（包括UNIX,Linux,和MS DOS）的，以供其他程序使用。
        //0是正常退出，其他均是异常，overflow(-2)
    L.length = 0;
    return 1;
}

//取值
//步骤：判断位置是否合理，合理将第i个数据元素L.elem[i-1]赋给参数e,通过e返回第i个元素的传值
int GetElem(SqList L,int i,int &e)
{
    if(i<1 || i>L.length)
        return 0;
    e = L.elem[i-1];
    return 1;
}

//查找
//步骤：从第一个元素起，和e比较，找到相同元素，返回序号，查找失败返回0
int LocateElem(SqList L,int e)
{
    for(int i=0;i<=L.length;i++)
    {
        if (L.elem[i]==e)
            return i+1;
    }
    return 0;
}

//插入
//步骤：判断插入位置是否合法，存储空间是否已满，元素后移，空出第i个位置，插入，表长加一
int ListInsert(SqList &L,int i,int e)
{
    if (i<1||i>L.length+1)
        return 0;
    if(L.length==100)//还可以改，加内存
        return 0;
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.elem[j+1]=L.elem[j];//注意循环主语
    }
    L.elem[i-1]==e;
    ++L.length;
    return 1;
}

//删除
//步骤：判断是否合法，向前移动，表长减1
int ListDelete(SqList &L,int i)
{
    if(i<1||i>L.length)
        return 0;
    //for(int j=L.length-1;j>=1;j--)
    for (int j=i;j<=L.length-1;j++)//加也可以
        L.elem[j-1]=L.elem[j];
    --L.length;
    return 1;
}

//遍历
//步骤：从第一个元素开始，依次输出
int ListTraverse(SqList L)
{
    for(int i=0;i<L.length;i++)
        cout<<L.elem[i]<<endl;
    return 1;
}

int main()
{
    SqList L;
    int e;
    int i;

    //初始化
    IniitList(L);

    //赋值
    for(int i=0;i<10;i++)
        L.elem[i]=i+1;

    //遍历
    ListTraverse(L);

    //查找
    cout<<"请输入要查找的元素："<<endl;
    cin>>e;
    i=LocateElem(L,e);
    if(i)
        cout<<"该元素的位置是："<<i<<endl;
    else
        cout<<"查找失败"<<endl;

    //删除
    cout<<"请输入要删除的元素的位置："<<endl;
    cin>>i;
    ListDelete(L,i);
    ListTraverse(L);

    //插入：空列表插不了
    cout<<"请输入要插入的元素的位置："<<endl;
    cin>>i;
    cout<<"请输入要插入的元素："<<endl;
    cin>>e;
    ListInsert(L,i,e);
    ListTraverse(L);

    //取值
    cout<<"请输入要取值的元素的位置："<<endl;
    cin>>i;
    GetElem(L,i,e);
    cout<<"该元素的值是："<<e<<endl;

    return 0;
}