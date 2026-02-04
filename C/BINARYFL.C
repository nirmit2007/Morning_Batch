#include <stdio.h>

#define SIZE 5

int main()
{
    float a[SIZE], key;
    int i, low = 0, high = SIZE - 1, mid;
    int flag = -1;
    float temp;

    /* Input */
    for (i = 0; i < SIZE; i++)
    {
        printf("Enter a[%d] : ", i);
        scanf("%f", &a[i]);
    }

    /* Sorting (Bubble Sort) */
    for (i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nSorted Array:\n");
    for (i = 0; i < SIZE; i++)
        printf("%.2f  ", a[i]);

    /* Binary Search */
    printf("\n\nEnter Key : ");
    scanf("%f", &key);

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
        {
            flag = mid;
            break;
        }
        else if (key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (flag == -1)
        printf("\nKey Not Found\n");
    else
        printf("\n%.2f found at index %d\n", key, flag);

    return 0;
}
