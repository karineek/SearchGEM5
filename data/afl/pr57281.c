// Modification timestamp: 2023-08-14 15:27:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57281.c

#include <stdio.h>

int a, b, d, *e = &d;
long long c, *g = &c;
volatile long long f;

int foo(int h, int *g, int *e)
{
    int j = *g = b;
    return h == 0 ? j : 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    a = atoi(argv[1]);
    int h = a;
    for (; b != -20; b--)
    {
        (int)f;
        *e = 0;
        *e = foo(h, (int *)g, e);
    }
    return 0;
}
