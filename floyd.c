#include <stdio.h>

#define INF 99999

void floydWarshall(int graph[][10], int dist[][10], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void printMatrix(int dist[][10], int n)
{
    printf("\nShortest distance matrix : \n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dist[i][j] == INF)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ", dist[i][j]);
            }
        }

        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter number of vertices : ");

    scanf("%d", &n);

    int graph[10][10], dist[10][10];

    printf("Enter the adjacency matrix : \n");

    printf("Enter %d for INF if no direct edge exists\n", INF);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, dist, n);

    printMatrix(dist, n);

    return 0;
}