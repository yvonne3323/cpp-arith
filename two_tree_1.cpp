//  使用二叉链表创建一棵二叉树，并完成如下操作：
// （1）	对这棵二叉树分别进行先序、中序、后序遍历；
// （2）	统计这棵二叉树的深度、叶子结点数、结点总数；
// （3）	销毁这棵二叉树。
#include <iostream>
using namespace std;
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void CreateBiTree(BiTree &T)//先序创建二叉树
{//ABC##DE#G##F###
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void PreOrderTraverse(BiTree T)//先序遍历
{
    if (T == NULL)
        return;
    cout << T->data;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)//中序遍历
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    cout << T->data;
    InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)//后序遍历
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    cout << T->data;
}

int Depth(BiTree T)//求树的深度
{
    int hl, hr, max;
    if (T == NULL)
        return 0;
    else
    {
        hl = Depth(T->lchild);
        hr = Depth(T->rchild);
        max = hl > hr ? hl : hr;
        return max + 1;
    }
}

int LeafCount(BiTree T)//求叶子结点数
{
    if (T == NULL)
        return 0;
    else if (T->lchild == NULL && T->rchild == NULL)
        return 1;
    else
        return LeafCount(T->lchild) + LeafCount(T->rchild);
}

int NodeCount(BiTree T)//求结点总数
{
    if (T == NULL)
        return 0;
    else
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

void Destroy(BiTree &T)//销毁二叉树
{
    if (T == NULL)
        return;
    Destroy(T->lchild);
    Destroy(T->rchild);
    delete T;
    T = NULL;
}

int main()
{
    BiTree T;
    CreateBiTree(T);
    cout << "先序遍历：";
    PreOrderTraverse(T);
    cout << endl;
    cout << "中序遍历：";
    InOrderTraverse(T);
    cout << endl;
    cout << "后序遍历：";
    PostOrderTraverse(T);
    cout << endl;
    cout << "树的深度：" << Depth(T) << endl;
    cout << "叶子结点数：" << LeafCount(T) << endl;
    cout << "结点总数：" << NodeCount(T) << endl;
    Destroy(T);
    return 0;
}




