#include<stdio.h>
#include<iostream>
#include<stack> 
#define mvnum 100
#define maxint 32767
#define mvnum 100
using namespace std;
typedef char vertextype;
typedef int arctype;
typedef struct{
    vertextype vexs[mvnum];
    arctype arcs[mvnum][mvnum];
    int vexnum,arcnum;
}amgraph;
int locatevex(amgraph &G,vertextype vex)
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==vex)
        {
            return i;
        }
    }
}
void creat(amgraph &G)
{
    printf("请输入总顶点数");
    scanf("%d",&G.vexnum);
    printf("请输入总边数");
    scanf("%d",&G.arcnum);
    getchar(); // 读取缓存区中的换行符
    for(int i=0;i<G.vexnum;i++)
    {
        printf("请输入第%d个顶点的信息\n",(i+1));
        scanf("%c",&G.vexs[i]);
        getchar(); // 读取缓存区中的换行符
    }
    for(int i=0;i<G.vexnum;i++)
    {
        for(int j=0;j<G.vexnum;j++)
        {
            G.arcs[i][j]=maxint;
        }
    }
    for(int k=0;k<G.arcnum;k++)
    {
        printf("请输入第%d条边的信息（边的顶点和权值）\n",(k+1));
        printf("请输入边的第一个顶点\n");
        vertextype v1;
        scanf("%c",&v1);
        getchar(); // 读取缓存区中的换行符
        printf("请输入边的第二个顶点\n");
        vertextype v2;
        scanf("%c",&v2);
        getchar(); // 读取缓存区中的换行符
        printf("请输入边的权重：\n");
        arctype weight;
        scanf("%d",&weight);
        int i=locatevex(G,v1);
        printf("v1在图中的位置：%d\n",i);
        int j=locatevex(G,v2);
        printf("v2在图中的位置：%d\n",j);
        G.arcs[i][j]=weight;
        G.arcs[j][i]=G.arcs[i][j];  
    }
}
void printam(amgraph &G)
{
    printf("\n输出图的邻接矩阵\n");
    for(int i=0;i<G.vexnum;i++)
    {
        for(int j=0;j<G.vexnum;j++)
        {
            if(G.arcs[i][j]==maxint)
            {
                G.arcs[i][j]=0;
                printf("%d",G.arcs[i][j]);
            }
            else{
                printf("%d",G.arcs[i][j]);
            }
        }
        printf("\n");
    }
}
int main()
{
    amgraph G;
    creat(G);
    printam(G);
    return 0;
}
