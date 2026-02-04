/*
An integer N (8 ≤ N ≤ 20)

An integer array of size N

A pointer pointing to the first element of the array

Read N integers into the array using only a pointer and a for loop.

Reverse only the first half of the array in place using:
-> Pointer arithmetic
-> A for loop

If N is odd, exclude the middle element from reversing

Traverse the array using a pointer and a for loop.

For every element that satisfies both conditions:
-> Position is a multiple of 3 (0-based index)
-> Element value is negative

Replace the element with the sum of its immediate neighbors.

Skip the first and last elements to avoid invalid memory access.

Move the pointer to the last element of the array.

Traverse the array backwards using a for loop and pointers:

Replace each element with the difference between itself and the previous element

Display the final array using only pointers and a for loop.

Constraints :
-Only one array
-Only one pointer variable
-No extra arrays
-No while loops
-No array indexing ( arr[i] ) after declaration
-Do not modify N
*/
#include<stdio.h>

int main()
{
    int N;
    printf("\nEnter Value of N : ");
    scanf("%d",&N);

    int a[N];
    int *p = a;

    for(int i=0;i<N;i++) 
    {
        scanf("%d",p+i);  // read elements from user
    }
    
    int half = N/2;                          
    for(int i=0;i<half/2;i++)   // reverse first half of array                 
    {
        int temp = *(p+i);
        *(p + i) = *(p + (half - 1 - i));
        *(p + (half - 1 - i)) = temp;
    }

    for(int i=1;i<N-1;i++)  // replace negative elements at indexmultiple of 3
    {
        if(i%3 == 0 && *(p+i) < 0)
        {
            *(p + i) = *(p + i - 1) + *(p + i + 1);
        }
    }
    p = a + (N-1);  //  move pointer to last element

    /*
    Move through the array from right to left and replace each element 
    with the result of subtracting the previous element from it.
    (Traverse backward and modify)
    */
    for(int i = N -1 ; i > 0 ; i--) 
    {
        *p = *p - *(p - 1);
        p--;
    }
    p = a;
    for(int i=0;i<N;i++)  // display final array
    {
        printf("%d ",*(p+i));
    }
    return 0;
}