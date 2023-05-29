#include<stdio.h>
#include<stdlib.h>
typedef char telemtype;
typedef struct tree
{
 telemtype data;
 struct tree *lchild;
 struct tree *rchild;
}bitree;
bitree *createtree()
{
 bitree *root;
 char ch;
 scanf("%c",&ch);
 if(ch=='#')
 {
  return NULL;
 }
 else{
  root=(bitree *)malloc(sizeof(bitree));
  if(root==NULL)
  {
   printf("创建失败");
   return NULL; 
  }
  root->data=ch;
  root->lchild=createtree();
  root->rchild=createtree();
  return root; 
 }
}
void xtraverse(bitree *root)
{
 if(root==NULL)
 {
  return;
 }
 printf("%c",root->data);
 xtraverse(root->lchild);
 xtraverse(root->rchild);
}
void ztraverse(bitree *root)
{
    
    if (root == NULL)
    {
        return;
    }
    ztraverse(root->lchild);
    printf("%c", root->data);
    ztraverse(root->rchild);
    
    
}
void htraverse(bitree *root)
{
 if(root==NULL)
 {
  return;
 }
 htraverse(root->lchild);
 htraverse(root->rchild);
 printf("%c",root->data);
}
int main()
{
 bitree *root;
 root=createtree();
 xtraverse(root);
 ztraverse(root);
 htraverse(root);
}