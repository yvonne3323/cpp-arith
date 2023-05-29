#include <iostream>
#include <queue>
#include <stack>
#define MAXVEX 100
#define INFINITY 65535
using namespace std;

typedef char VertexType; // 顶点数据类型
typedef int EdgeType; // 边权值类型

// 图的邻接矩阵存储结构
typedef struct {
    VertexType vexs[MAXVEX]; // 顶点表
    EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵
    int numVertexes, numEdges; // 图的当前顶点数和边数
} MGraph;

// 深度优先遍历
void DFS(MGraph G, int i, bool visited[]) {
    visited[i] = true; // 标记当前顶点已访问
    cout << G.vexs[i] << " ";
    for (int j = 0; j < G.numVertexes; j++) {
        if (G.arc[i][j] != INFINITY && !visited[j]) { // 如果顶点j与顶点i有边且未被访问
            DFS(G, j, visited); // 递归访问顶点j
        }
    }
}

// 深度优先遍历（非递归）
void DFS2(MGraph G, int i, bool visited[]) {
    stack<int> S;
    S.push(i);
    visited[i] = true;
    cout << G.vexs[i] << " ";
    while (!S.empty()) {
        int k = S.top();
        bool flag = false;
        for (int j = 0; j < G.numVertexes; j++) {
            if (G.arc[k][j] != INFINITY && !visited[j]) {
                S.push(j);
                visited[j] = true;
                cout << G.vexs[j] << " ";
                flag = true;
                break;
            }
        }
        if (!flag) {
            S.pop();
        }
    }
}

// 广度优先遍历
void BFS(MGraph G, int i, bool visited[]) {
    queue<int> Q;
    visited[i] = true;
    cout << G.vexs[i] << " ";
    Q.push(i);
    while (!Q.empty()) {
        int k = Q.front();
        Q.pop();
        for (int j = 0; j < G.numVertexes; j++) {
            if (G.arc[k][j] != INFINITY && !visited[j]) {
                visited[j] = true;
                cout << G.vexs[j] << " ";
                Q.push(j);
            }
        }
    }
}

int main() {
    MGraph G;
    cout << "请输入顶点数和边数：" << endl;
    cin >> G.numVertexes >> G.numEdges;
    cout << "请输入顶点信息：" << endl;
    for (int i = 0; i < G.numVertexes; i++) {
        cin >> G.vexs[i];
    }
    for (int i = 0; i < G.numVertexes; i++) {
        for (int j = 0; j < G.numVertexes; j++) {
            G.arc[i][j] = INFINITY;
        }
    }
    cout << "请输入边信息：" << endl;
    for (int k = 0; k < G.numEdges; k++) {
        int i, j, w;
        cin >> i >> j >> w;
        G.arc[i][j] = w;
        G.arc[j][i] = w;
    }

    bool visited[MAXVEX] = {false}; // 标记顶点是否已访问
    cout << "深度优先遍历：";
    for (int i = 0; i < G.numVertexes; i++) {
        if (!visited[i]) {
            DFS(G, i, visited);
        }
    }
    cout << endl;

    bool visited2[MAXVEX] = {false};
    cout << "深度优先遍历（非递归）：";
    for (int i = 0; i < G.numVertexes; i++) {
        if (!visited2[i]) {
            DFS2(G, i, visited2);
        }
    }
    cout << endl;

    bool visited3[MAXVEX] = {false};
    cout << "广度优先遍历：";
    for (int i = 0; i < G.numVertexes; i++) {
        if (!visited3[i]) {
            BFS(G, i, visited3);
        }
    }
    cout << endl;

    return 0;
}
