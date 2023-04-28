//链式存储结构
#include<stdio.h>
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<math.h>
#include <malloc.h>
#define Status int
#define OK 1
#define Maxsize 100
#define ERROR 0
typedef struct LNode
{
 int data;
 int length;
 struct LNode *next;
}LNode,*LinkList;
//初始化
Status InitList(LinkList &L)
{
 L=new LNode;
 L->next=NULL;
 return OK; 
// L.elem=new ElemType[Maxsize];
// if(!L.elem) exit(OVERFLOW)
// L.length=0;
// return OK;
}
//插入
Status ListInsert(LinkList &L,int i,int e)
{
 LNode *p=L,*s;
 int j=0;
 while(p &&(j<i-1))
  {p=p->next;++j;}
 if(!p||j>i-1) return ERROR;
 s=new LNode;
 s->data=e;
 s->next=p->next;
 p->next=s;
 return OK;
 }
//删除
Status ListDelete(LinkList &L,int i)
{
 LNode *p=L,*q;
 int j=0;
 while((p->next!= NULL)&&(j<i-1))
 {
  p=p->next;
  ++j;
 }
 if(!(p->next)||(j>i-1)) return ERROR;
 q=p->next;
 delete q;
 return OK;
}
//查找 
LNode *LocateElem(LinkList L,int e)
{
 LNode *p=L->next;
 while(p && p->data!=e)
  p=p->next;
 return p;
}
//取值 
Status GetElem(LinkList L,int &e)
{
 int j,i;
 LNode *p = L ->next;
 j=1;
 while(p&&j<i)
 {
  p=p->next;
  ++j;
 }
 if(p||j>i) return ERROR;
 e=p->data;
 return OK;
}
//遍历
void Traverse(LinkList L)
{
    LNode *p=L->next;
    while(p)
    {
    printf("%d ",p->data);
    p=p->next;
    }
    printf("\n");
}
int main()
{
 int n,a,b,i,d,e;
 LinkList L; 
 InitList(L);
 //输入数据(不用插入直接写入)
 LNode *p;
    printf("请输入数据个数：\n");
    scanf("%d",&n);
    printf("请输入数据：\n");
    for(int i=0;i<n;i++)
    {
        p = new LNode;
        scanf("%d",&p->data);
        p->next = L->next;
        L->next = p;
    }
    Traverse(L);
    printf("输入情况\n");
    printf("1.插入,2.删除,3.查找,4.取值,5.遍历,6.退出\n");
    while(1)
    {
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                printf("请输入插入位置和数据：\n");
                scanf("%d%d",&b,&d);
                ListInsert(L,b,d);
                Traverse(L);
                break;
            case 2:
                printf("请输入删除位置：\n");
                scanf("%d",&b);
                ListDelete(L,b);
                Traverse(L);
                break;
            case 3:
                printf("请输入查找数据：\n");
                scanf("%d",&b);
                p=LocateElem(L,b);
                if(p)
                printf("查找成功\n");
                else
                printf("查找失败\n");
                break;
            case 4:
                printf("请输入取值位置：\n");
                scanf("%d",&b);
                GetElem(L,b);
                printf("取值成功\n");
                break;
            case 5:
                Traverse(L);
                break;
            case 6:
                return 0;
        }
    }
    return 0;
}