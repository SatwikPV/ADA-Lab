#include <stdio.h>
int n, c[10][10], src;
void dijkstras();

void main()
{
    int i, j;
    printf("\n Enter the no of vertices:\t");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }

    printf("\n Enter the source node:\t");
    scanf("%d", &src);
    dijkstras();
}

void dijkstras()
{
    int i, j, u, min = 0, count = 0;
    int dist[10], vis[10];

    for (i = 1; i <= n; i++)
        dist[j] = c[src][j];

    for (i = 1; i <= n; i++)
        vis[i] = 0;

    while (count != n)
    {
        min = 9999;

        for (i = 1; i <= n; i++)
        {
            if (dist[i] < min && vis[i] != 1)
            {
                min = dist[i];
                u = i;
            }
        }

        vis[u] = 1;
        count++;

        for (i = 1; i <= n; i++)
        {
            if (c[u][i] + min < dist[i] && vis[i] != 1)
            {
                dist[i] = c[u][i] + min;
            }
        }

        printf("Shortest Distance is:");
        for (i = 1; i <= n; i++)
        {
            printf("\n %d--------->%d=%d", src, i, dist[i]);
        }
    }
}