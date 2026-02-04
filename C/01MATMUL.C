#include <stdio.h>

#define ROW 10
#define COL 10

int main()
{
    int a[ROW][COL], b[ROW][COL], c[ROW][COL] = {0};
    int i, j, k;
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2)
    {
        printf("\nMatrix multiplication not possible\n");
        return 0;
    }

    printf("\nEnter elements of first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("\nEnter elements of second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    /* Matrix multiplication */
    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            for (k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];

    printf("\nResult:\n\n");

    for (i = 0; i < r1; i++)
    {
        /* First matrix */
        for (j = 0; j < c1; j++)
            printf("%4d", a[i][j]);

        if (i == r1 / 2)
            printf("  *  ");
        else
            printf("     ");

        /* Second matrix */
        for (j = 0; j < c2; j++)
            printf("%4d", b[i][j]);

        if (i == r1 / 2)
            printf("  =  ");
        else
            printf("     ");

        /* Result matrix */
        for (j = 0; j < c2; j++)
            printf("%4d", c[i][j]);

        printf("\n");
    }

    return 0;
}
