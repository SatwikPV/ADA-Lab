#include <stdio.h>

void kruskals();
int c[10][10], n;

void main()
{

    int i, j;
    printf("\n Enter the number of vertices\t");
    scanf("%d", &n);

    printf("\nEnter the cost matrix");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    kruskals();
}

void kruskals()
{
    int i, j, u, v, a, b, min = 0;
    int ne = 0, mincost = 0;
    int parent[10];

    for (i = 1; i <= n; i++)
    {
        parent[i] = 0;
    }

    while (ne != n - 1)
    {
        min = 9999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (c[i][j] < min)
                {
                    min = c[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }

        while (parent[u] != 0)
        {
            u = parent[u];
        }

        while (parent[v] != 0)
        {
            v = parent[v];
        }

        if (u != v)
        {
            parent[v] = u;
            ne++;
            mincost = mincost + min;
            printf("%d---->%d=%d", a, b, min);
        }

        c[a][b] = c[b][a] = 9999;
    }
    printf("%d", mincost);
}