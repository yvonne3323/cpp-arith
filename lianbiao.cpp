//设计算法，反复查找并删除循环单链表的最小值结点，直至链表为空
// Created by Administrator on 2019/10/29.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef int ElemType;
typedef int Status;

//链表的结点定义如下：
struct Node
{
    int data;
    Node *next;
};

void init(Node *&head)
{
    head = new Node;
    head->next = head;
}

void create(Node *&head)
{
    srand(time(0));
    Node *p, *rear = head;
    int n = 5;
    cout << n << endl;
    while (n--)
    {
        p = new Node;
        p->data = rand() % 9 + 1;

        rear->next = p;
        rear = p;
    }
    rear->next = head;
}

void show(Node *&head)
{
    for (Node *p = head->next; p != head; p = p->next)
    {
        cout << (p->data) << "  ";
    }
    cout << endl;
}

int MinLinklist(Node *&head)
{
    Node *p = head->next;
    int min = p->data;
    while (1)
    {
        if (p->next->data < min)
            min = p->next->data;
        p = p->next;
        if (p->next == head)
            break;
    }
    cout << endl
         << "min=" << min << endl;
    return min;
}

void DeleteMin(Node *&head)
{
    if(head->next==head) return; 
 cout<<"原链表："; 
 show(head);
 Node *p=head;
 int i=MinLinklist(head);
 while(1){
  if(p->next==head) break;
  if(p->next->data==i)
  {
   Node *q=new Node;
   q=p->next;
         p->next=q->next;
         delete q;
         
  }
  else p=p->next;
 }
 cout<<"链表为："; 
 show(head);
 cout<<"-----------"<<endl;


}

void SearchDelete(Node *&head)
{
    while (head->next != head)
    {
        DeleteMin(head);
        cout << "删除最小值后的链表：";
        show(head);

    }
}

int main()
{
    Node *head;
    init(head);
    create(head);
    show(head);
    SearchDelete(head);
    return 0;
}

