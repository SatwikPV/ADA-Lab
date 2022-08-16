#include <stdio.h>

int a[10][10], n;

void warshall();
void main()
{
    int i, j;

    printf("Enter the no of vertices\t");
    scanf("%d", &n);

    printf("Enter the cost matrix\t");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    warshall();
}

void warshall()
{
    int i, j, k;
    for (k = 1; i <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                a[i][j] = (a[i][j] || (a[i][k] && a[k][j]));
            }
        }
    }
    printf("\ntransitive closure is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", a[i][j]);
        }

        printf("\n\n");
    }
}
