#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float a, b, c, d, sum;

    if (argc != 5)
    {
        printf("Usage: %s num1 num2 num3 num4\n", argv[0]);
        return 1;
    }

    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);
    d = atof(argv[4]);

    sum = a + b + c + d;

    printf("Sum : %.2f\n", sum);

    return 0;
}
