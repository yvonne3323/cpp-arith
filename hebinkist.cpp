#include <iostream>
using namespace std;

//链表
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//顺序表
typedef struct
{
    int data[100];
    int length;
}SqList;

//初始化(链表)
void InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    cout << "初始化成功" << endl;
}
//初始化(顺序表)
void InitList2(SqList &L)
{
    L.length = 0;
    cout << "初始化成功" << endl;
}

//创建(链表)
void CreateList(LinkList &L,int n)
{
    LNode *p;
    int i;
    while (n < 0)
    {
        cout << "输入不合法，请重新输入" << endl;
        cin >> n;
    }
    cout << "请输入要创建的元素:";
    for(i=0;i<n;i++)
    {
        p = new LNode;
        cin>>p->data;
        p->next=L->next;
        L->next=p;
    }
    cout << "创建成功" << endl;
}
//创建(顺序表)
void CreateList2(SqList &L,int n)
{
    int i;
    while (n < 0)
    {
        cout << "输入不合法，请重新输入" << endl;
        cin >> n;
    }
    cout << "请输入要创建的元素:";
    for(i=0;i<n;i++)
    {
        cin>>L.data[i];
    }
    L.length = n;
    cout << "创建成功" << endl;
}

//合并(链表)
void AndList(LinkList &La,LinkList &Lb,LinkList &Lc)
{
    LNode *pa=La->next;
    LNode *pb=Lb->next;
    LNode *pc;
    Lc=pc=La;
    while(pa!=NULL&&pb!=NULL)
    {
        if(pa->data<=pb->data)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;
    delete Lb;
}
//合并(顺序表)
void AndList2(SqList &La,SqList &Lb,SqList &Lc)
{
    int i=0,j=0,k=0;
    while(i<La.length&&j<Lb.length)
    {
        if(La.data[i]<=Lb.data[j])
        {
            Lc.data[k++]=La.data[i++];
        }
        else
        {
            Lc.data[k++]=Lb.data[j++];
        }
    }
    while(i<La.length)
    {
        Lc.data[k++]=La.data[i++];
    }
    while(j<Lb.length)
    {
        Lc.data[k++]=Lb.data[j++];
    }
    Lc.length=k;
}

//遍历(链表)
void ListD(LinkList L)
{
    LNode *p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
//遍历(顺序表)
void ListD2(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        cout<<L.data[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    //链表
    LinkList La,Lb,Lc;
    int n1,n2;
    cout<<"链表：";
    cout<<"请输入La的长度:";
    cin>>n1;
    InitList(La);
    CreateList(La,n1);

    cout<<"请输入Lb的长度:";
    cin>>n2;
    InitList(Lb);
    CreateList(Lb,n2);

    cout<<"La的元素为:";
    ListD(La);
    cout<<"Lb的元素为:";
    ListD(Lb);
    AndList(La,Lb,Lc);
    cout<<"La与Lb合并:";
    ListD(Lc);

    //顺序表
    SqList Ld,Le,Lf;
    int n3,n4;
    cout<<"顺序表：";
    cout<<"请输入Ld的长度:";
    cin>>n3;
    InitList2(Ld);
    CreateList2(Ld,n3);

    cout<<"请输入Le的长度:";
    cin>>n4;
    InitList2(Le);
    CreateList2(Le,n4);

    cout<<"Ld的元素为:";
    ListD2(Ld);
    cout<<"Le的元素为:";
    ListD2(Le);

    AndList2(Ld,Le,Lf);
    cout<<"Ld与Le合并:";
    ListD2(Lf);

    return 0;
}