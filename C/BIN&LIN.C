#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int a[SIZE];

void linearSearch(void);
void binarySearch(void);
void sortArray(void);

int main()
{
    int i, choice;

    while (1)
    {
        printf("\nEnter %d elements:\n", SIZE);
        for (i = 0; i < SIZE; i++)
        {
            printf("a[%d] : ", i);
            scanf("%d", &a[i]);
        }

        printf("\n1. Linear Search");
        printf("\n2. Binary Search");
        printf("\n3. Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                linearSearch();
                break;

            case 2:
                sortArray();
                binarySearch();
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid Choice\n");
        }
    }

    return 0;
}

/* LINEAR SEARCH */
void linearSearch(void)
{
    int key, i, index = -1;

    printf("\nEnter Key : ");
    scanf("%d", &key);

    for (i = 0; i < SIZE; i++)
    {
        if (a[i] == key)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
        printf("Key %d found at index %d\n", key, index);
    else
        printf("Key not found\n");
}

/* SORT ARRAY FOR BINARY SEARCH */
void sortArray(void)
{
    int i, j, temp;

    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = i + 1; j < SIZE; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

/* BINARY SEARCH */
void binarySearch(void)
{
    int key, low = 0, high = SIZE - 1, mid, index = -1, i;

    printf("\nSorted Array : ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", a[i]);

    printf("\nEnter Key : ");
    scanf("%d", &key);

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
        {
            index = mid;
            break;
        }
        else if (key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (index == -1)
        printf("Key not found\n");
    else
        printf("Key %d found at index %d\n", key, index);
}
