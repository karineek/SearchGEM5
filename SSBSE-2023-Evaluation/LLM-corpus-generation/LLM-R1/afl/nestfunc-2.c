// Modification timestamp: 2023-08-14 14:41:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/nestfunc-2.c

#include <stdio.h>
#include <stdlib.h>

int z;

int nested(int a, int b, int c, int d, int e, int f, int g);
int foo(int a, int b, int (*fp)(int, int, int, int, int, int, int));

int main(void)
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
  
    int sum = 0;
    int i;

    int nested(int a, int b, int c, int d, int e, int f, int g)
    {
        z = c + d + e + f + g;

        if (a > 2 * b)
            return a - b;
        else
            return b - a;
    }

    for (i = 0; i < 10; ++i)
    {
        int j;

        for (j = 0; j < 10; ++j)
        {
            int k;

            for (k = 0; k < 10; ++k)
                sum += foo(i, j > k ? j - k : k - j, nested);
        }
    }

    if (sum != atoi(argv[1]))
        abort();

    if (z != 0x1b)
        abort();

    exit(0);
}

int foo(int a, int b, int (*fp)(int, int, int, int, int, int, int))
{
    return fp(a, b, a, b, a, b, a);
}
