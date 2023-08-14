// Modification timestamp: 2023-08-14 15:36:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr59014.c

#include <stdio.h>
#include <stdlib.h>

int a, b, c, d;

int foo(int a, int b, int c, int d)
{
    for (;; c++)
    {
        if ((b > 0) | (a & 1))
        {
            // do nothing
        }
        else
        {
            d = a;
            return 0;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]);
    d = atoi(argv[4]);

    foo(a, b, c, d);

    if (d != 2)
    {
        __builtin_abort();
    }

    return 0;
}
