//链式存储结构
#include<stdio.h>
#include<iostream>
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
 while((p->next)&&(j<i-1))
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
 LNode *p=p->next;
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
 LNode *p;
 p=L->next;
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
 LNode *p;
 LinkList L; 
 InitList(L);
 printf("请输入值的个数n=");
 scanf("%d",&n);
 printf("请输入数组元素");  
 for(int i;i<n;i++)
 {
  p=new LNode;
  scanf("%d",&p->data);
  p->next=L->next;
  L->next=p;
 }
 Traverse(L);
 
}