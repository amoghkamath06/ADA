#include <stdio.h>

#define MAX 10

void topologicalSort(int adj[MAX][MAX], int n)
{
    int i, j;

    int indegree[MAX] = {0};

    int queue[MAX], front = 0, rear = -1;

    int topo[MAX], k = 0;

    // Calculate indegree
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(adj[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    // Insert vertices with indegree 0 into queue
    for(i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
        {
            queue[++rear] = i;
        }
    }

    // Source removal method
    while(front <= rear)
    {
        int v = queue[front++];

        topo[k++] = v;

        for(j = 0; j < n; j++)
        {
            if(adj[v][j] == 1)
            {
                indegree[j]--;

                if(indegree[j] == 0)
                {
                    queue[++rear] = j;
                }
            }
        }
    }

    // Check for cycle
    if(k != n)
    {
        printf("Graph has cycle, not possible.\n");
    }
    else
    {
        printf("Topological order : \n");

        for(i = 0; i < n; i++)
        {
            printf("%d ", topo[i]);
        }
    }
}

int main()
{
    int n, i, j;

    int adj[MAX][MAX];

    printf("Enter number of vertices : ");
    scanf("%d", &n);

    printf("Enter adjacency matrix : \n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(adj, n);

    return 0;
}