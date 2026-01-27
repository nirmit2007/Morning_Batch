#include <stdio.h>

int main()
{
    FILE *findia, *fusa;

    // Open files in w+ mode
    findia = fopen("india.txt", "w+");
    fusa   = fopen("usa.txt", "w+");

    if (findia == NULL || fusa == NULL)
    {
        printf("Error creating files.\n");
        return 1;
    }

    // Write data into files
    fputs("INDIA", findia);
    fputs("USA", fusa);

    fclose(findia);
    fclose(fusa);

    printf("Files created and data written successfully.\n");

    return 0;
}
