#include <stdio.h>

#define MAX 10
#define INF 99999

void dijkstra(int G[MAX][MAX], int n, int s)
{
    int dist[MAX], visited[MAX];

    int u, min;

    for(int i = 0; i < n; i++)
    {
        dist[i] = INF;

        visited[i] = 0;
    }

    dist[s] = 0;

    for(int i = 0; i < n; i++)
    {
        min = INF;

        for(int j = 0; j < n; j++)
        {
            if(visited[j] == 0 && dist[j] < min)
            {
                min = dist[j];

                u = j;
            }
        }

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(visited[v] == 0 &&
               G[u][v] != INF &&
               dist[u] + G[u][v] < dist[v])
            {
                dist[v] = dist[u] + G[u][v];
            }
        }
    }

    printf("Shortest distances:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d -> %d = %d\n", s, i, dist[i]);
    }
}

int main()
{
    int n, s;

    int G[MAX][MAX];

    printf("Enter number of vertices: ");

    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    printf("Enter source vertex: ");

    scanf("%d", &s);

    dijkstra(G, n, s);

    return 0;
}