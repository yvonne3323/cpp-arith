//使用邻接矩阵创建一个图，并对这个图进行深度优先遍历和广度优先遍历。

#include <iostream>
using namespace std;

#define MVNum 100
#define MaxInt 32767

typedef char VertexType;
typedef int ArcType;

typedef struct
{
    VertexType vexs[MVNum];
    ArcType arc[MVNum][MVNum];
    int vexnum, arcnum;
} AMGraph;

void CreatUDN(AMGraph *G)
{
    int i, j, k, w;
    cout << "输入顶点数和边数：";
    cin >> G->vexnum >> G->arcnum;
    cout << "输入顶点信息：";
    for (i = 0; i < G->vexnum; i++)
        cin >> G->vexs[i];
    for (i = 0; i < G->vexnum; i++)
        for (j = 0; j < G->vexnum; j++)
            G->arc[i][j] = MaxInt;
    for (k = 0; k < G->arcnum; k++)
    {
        cout << "输入边(vi,vj)上的下标i，下标j和权w：";
        cin >> i >> j >> w;
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}

bool visited[MVNum];
void DFS(AMGraph G, int i)
{
    int j;
    visited[i] = true;
    cout << G.vexs[i] << " ";
    for (j = 0; j < G.vexnum; j++)
        if (G.arc[i][j] == 1 && !visited[j])
            DFS(G, j);
}

void DFSTraverse(AMGraph G)
{
    int i;
    for (i = 0; i < G.vexnum; i++)
        visited[i] = false;
    for (i = 0; i < G.vexnum; i++)
        if (!visited[i])
            DFS(G, i);
}

void BFS(AMGraph G,int i)
{
    int j;
    int queue[MVNum], front = 0, rear = 0;
    cout << G.vexs[i] << " ";
    visited[i] = true;
    rear = (rear + 1) % MVNum;
    queue[rear] = i;
    while (front != rear)
    {
        front = (front + 1) % MVNum;
        j = queue[front];
        for (int k = 0; k < G.vexnum; k++)
        {
            if (G.arc[j][k] == 1 && !visited[k])
            {
                cout << G.vexs[k] << " ";
                visited[k] = true;
                rear = (rear + 1) % MVNum;
                queue[rear] = k;
            }
        }
    }
}


void BFSTraverse(AMGraph G)
{
    int i;
    for (i = 0; i < G.vexnum; i++)
        visited[i] = false;
    for (i = 0; i < G.vexnum; i++)
        if (!visited[i])
            BFS(G, i);
}

int main()
{
    AMGraph G;
    CreatUDN(&G);
    cout << "深度优先遍历序列：";
    DFSTraverse(G);
    cout << endl;
    cout << "广度优先遍历序列：";
    BFSTraverse(G);
    cout << endl;

    return 0;
}
