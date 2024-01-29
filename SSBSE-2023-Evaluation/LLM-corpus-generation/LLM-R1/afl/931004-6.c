// Modification timestamp: 2023-08-14 13:38:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931004-6.c

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

struct tiny
{
    short c;
    short d;
};

void f(int n, ...)
{
    struct tiny x;
    int i;

    va_list ap;
    va_start(ap, n);
    for (i = 0; i < n; i++)
    {
        x = va_arg(ap, struct tiny);
        if (x.c != i + 10)
            abort();
        if (x.d != i + 20)
            abort();
    }
    {
        long x = va_arg(ap, long);
        if (x != 123)
            abort();
    }
    va_end(ap);
}

int main(int argc, char *argv[])
{
    struct tiny x[3];
    x[0].c = atoi(argv[1]);
    x[1].c = atoi(argv[2]);
    x[2].c = atoi(argv[3]);
    x[0].d = atoi(argv[4]);
    x[1].d = atoi(argv[5]);
    x[2].d = atoi(argv[6]);
    f(3, x[0], x[1], x[2], (long)123);
    exit(0);
}
