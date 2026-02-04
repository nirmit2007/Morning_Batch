#include <stdio.h>

#define SIZE 5

int main()
{
    int i, j;
    char temp;
    int swapped = 1;
    char a[SIZE];

    // Input characters
    for (i = 0; i < SIZE; i++)
    {
        printf("Enter a[%d]: ", i);
        scanf(" %c", &a[i]);
    }

    // Display unsorted array
    printf("\nUnsorted Array:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%c\t", a[i]);
    }

    // Bubble sort
    for (i = 0; i < SIZE && swapped == 1; i++)
    {
        swapped = 0;
        for (j = 0; j < SIZE - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
    }

    // Display sorted array
    printf("\n\nSorted Array:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%c\t", a[i]);
    }

    return 0;
}
