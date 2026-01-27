#include <stdio.h>

int main()
{
    int a[3][3], b[3][3], c[3][3];
    int i, j;

    printf("Enter Matrix A (3x3):\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);

    printf("\nEnter Matrix B (3x3):\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &b[i][j]);

    /* Matrix Addition */
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            c[i][j] = a[i][j] + b[i][j];

    printf("\nMatrix A       Matrix B       Sum (A+B)\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%4d", a[i][j]);

        printf("     ");

        for (j = 0; j < 3; j++)
            printf("%4d", b[i][j]);

        printf("     ");

        for (j = 0; j < 3; j++)
            printf("%4d", c[i][j]);

        printf("\n");
    }

    return 0;
}

