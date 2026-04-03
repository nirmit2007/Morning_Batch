#include <stdio.h>
#define SIZE 5

int main()
{
    int arr[SIZE], i, j, key, min_idx;

    printf("Enter %d elements: ", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < SIZE - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < SIZE; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            key = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = key;
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}