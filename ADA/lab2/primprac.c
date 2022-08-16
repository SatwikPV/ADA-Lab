#include <stdio.h>
int n, c[10][10];
void prim();

void main()
{
    int i, j;
    printf("enter no of variables");
    scanf("%d", &n);

    printf("Enter the cost matrix");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }

    prim();
}

void prim()
{
    int i, j, elec[10], min = 0, minpath = 0, u, v, ne = 0;

    for (i = 1; i <= n; i++)
    {
        elec[i] = 0;
    }

    elec[1] = 1;
    while (ne != n - 1)
        min = 9999;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (elec[i] == 1)
            {
                if (c[i][j] < min)
                {
                    min = c[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (elec[v] != 1)
        {
            printf("%d => %d = %d", u, v, min);
            minpath = minpath + min;
            elec[v] = 1;
            ne++;
        }

        c[u][v] = c[v][u] = 9999;
    }
    printf("\n mincost=%d", minpath);
}