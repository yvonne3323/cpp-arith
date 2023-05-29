#include <stdio.h>
#include<stdbool.h>
#define Maxlnt 100
typedef char VerTexType;
typedef int  ArcType;
typedef struct {
    VerTexType vexs[Maxlnt];
    ArcType arcs[Maxlnt][Maxlnt];
    int vexnum,arcnum;
}Graph;
bool visited[Maxlnt];
int LocateVex(Graph G, VerTexType v)
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v)
            return i;
        return -1;
    }
}
int FirstAdjvex(Graph G,int v)
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.arcs[v][i]==1&&visited[i]==false)
            return i;
    }
    return -1;
}
int NextAdjvex(Graph G,int v,int w)
{
    int i;
    for(i=w+1;w>0;w= NextAdjvex(G,v,w))
    {
        if(G.arcs[v][i]==1&&visited[i]==false)
            return i;
    }
    return -1;

}

void CreateUDN(Graph *G)
{  int i,j,k;
    printf("�������ĸ����ͱߵĸ���");
    scanf("%d %d",&G->vexnum,&G->arcnum);
    printf("\n");
    getchar();
    printf("������������");

    for( i=0;i<G->vexnum;i++)
        scanf("%c",&G->vexs[i]);
    printf("\n");
    for( i=0;i<G->vexnum;i++)
    {

        for( j=0;j<G->vexnum;j++)
        {
            G->arcs[i][j]=0;
        }
    }
    printf("����������Ķ���");
    for(k=0;k<G->arcnum;k++)
    {
        VerTexType v1,v2;
        printf("�������%d���������Ķ���",(k+1));
        scanf("%c %c",&v1,&v2);
        i= LocateVex(*G,v1);
        j= LocateVex(*G,v2);
        G->arcs[j][i]=G->arcs[i][j]=1;
    }


}
void DFS(Graph G,int v)
{

    int w;
    printf("%c", G.vexs[v]);
    visited[v] = true;
    for(w= FirstAdjvex(G,v);w>0;w= NextAdjvex(G,v,w))
        if(!visited[w])
            DFS(G,w);
}

int main()
{
    Graph  G;
    CreateUDN(&G);
    printf("����ͼG������ɣ�\n\n");
    printf("�������������ͼG����ʼ�㣺");
    VerTexType c;
    scanf("%c",&c);
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(c==G.vexs[i])
            break;
    }
    printf("\n");
    while (i >= G.vexnum) {
        printf("�õ㲻���ڣ����������룡\n");
        printf("�����������ͨͼ����ʼ�㣺");
        scanf(" %c", &c);
        for (i = 0; i < G.vexnum; ++i) {
            if (c == G.vexs[i])
                break;
        }
    }
    printf("�������������������ͼG�����\n");
    DFS(G,i);
    printf("\n");
    return 0;

}


