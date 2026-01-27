#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    int i, num;

    /* write */
    fp1 = fopen("odd.txt", "w");
    fp2 = fopen("even.txt", "w");

    i = 1;
    while (i <= 10)
    {
        if (i % 2 == 0)
            putw(i, fp2);
        else
            putw(i, fp1);
        i++;
    }

    fclose(fp1);
    fclose(fp2);

    /* read odd file */
    fp1 = fopen("odd.txt", "r");
    printf("Odd Numbers:\n");
    while ((num = getw(fp1)) != EOF)
    {
        printf("%d ", num);
    }
    fclose(fp1);

    /* read even file */
    fp2 = fopen("even.txt", "r");
    printf("\nEven Numbers:\n");
    while ((num = getw(fp2)) != EOF)
    {
        printf("%d ", num);
    }
    fclose(fp2);

    return 0;
}

