#include <stdio.h>

int main()
{
    FILE *fp;
    char fileName[50];
    char str[100];

    printf("Enter the file name: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "w+");

    if (fp == NULL)
    {
        printf("File could not be created.\n");
        return 1;
    }

    printf("Enter the content: ");
    scanf(" %[^\n]", str);

    fprintf(fp, "%s", str);
    fclose(fp);

    printf("File created successfully.\n");

    return 0;
}
