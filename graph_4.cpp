#include <stdio.h>
#define MAX_VERTICES 6
void dfs(int adj_matrix[][MAX_VERTICES],int start,int visited[]) {
    int i;
    visited[start]=1;
    printf("%d ",start);
    for (i=0;i<MAX_VERTICES;i++)
	{
        if(adj_matrix[start][i] && !visited[i])
		{
            dfs(adj_matrix, i, visited);
        }
    }
}
void bfs(int adj_matrix[][MAX_VERTICES], int start, int visited[]) {
    int i;
    int queue[MAX_VERTICES];
    int front=0, rear=0;
    visited[start]=1;
    printf("%d ",start);
    queue[rear++]=start;
    while (front!=rear)
	{
        int v=queue[front++];
        for (i=0;i<MAX_VERTICES;i++)
		{
            if (adj_matrix[v][i]&&!visited[i])
			{
                visited[i]=1;
                printf("%d ",i);
                queue[rear++]=i;
            }
        }
    }
}
int main() 
{
    int adj_matrix[MAX_VERTICES][MAX_VERTICES]=
	{
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };
    int visited[MAX_VERTICES]={0};
    dfs(adj_matrix,0,visited);
    printf("\n");
    for (int i=0;i<MAX_VERTICES;i++) 
	{
        visited[i]=0;
    }
    bfs(adj_matrix,0,visited);
    printf("\n");
    return 0;
}
