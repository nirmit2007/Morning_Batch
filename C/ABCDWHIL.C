#include <stdio.h>

int main()
{
    int i = 0, j = 1;
    char ch1 = 'A';
    char ch2 = 'a';

    while (j < 80)
    {
        i = 0;   /* reset i for each line */

        while (i < 25)
        {
            if (i % 2 == 0)
            {
                printf("\n%c", ch1 + i);
            }
            else
            {
                printf("\n%c", ch2 + i);
            }
            i++;
        }
        j++;
    }

    return 0;
}
