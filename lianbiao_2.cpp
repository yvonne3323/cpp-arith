#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std;
typedef int ElemType;
typedef int Status;

//链表的结点定义如下：
struct Node
{ 
    int   data;
    Node *next;
};

void init(Node *&head)
{
    head=new Node;
    head->next=head;
}

void create(Node *&head)
{
 srand(time(0));
 Node *p,*rear=head;     
 int n=5;
 cout<<n<<endl;
    while(n--)
    {
        p=new Node;
        p->data=rand()%9+1;
        
        rear->next=p;
        rear=p; 
    }
    rear->next=head;

}

int show(Node *&head) 
{
    if (head->next == head)
        return 0;
    for(Node *p=head->next; p!=head ;p=p->next)
    {
        cout<<(p->data)<<"  ";
    }      
    cout<<endl;

}            


int MinLinklist(Node *&head)
{
 Node *p=head->next;
 int min=p->data;
 while(1){
   if(p->next->data<min) min=p->next->data;
    p=p->next;
   if(p->next==head) break; 
  }
  cout<<endl<<"min="<<min<<endl;
 return min;
}

void DeleteList(Node *&head){
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
 Node *p=head;
 int min;
 while(1)
 {
  
  if(head->next==head) 
    return;
  
  DeleteList(p);
  
  
 }
 cout<<"清空该链表";
 show(head);
}

int main()
{
 srand(time(0));
 Node *p;
 Node *rear,*head;
 init(head);
 create(head);
 cout<<endl;
 show(head);
 cout<<"-------------------------"<<endl;
 SearchDelete(head);
 return 0;
}