// Modification timestamp: 2023-08-14 13:37:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931004-3.c

#include <stdio.h>
#include <stdlib.h>

struct tiny
{
    short c;
};

void f(int n, struct tiny x, struct tiny y, struct tiny z, long l)
{
    if (x.c != 10)
        abort();

    if (y.c != 11)
        abort();

    if (z.c != 12)
        abort();

    if (l != 123)
        abort();
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct tiny x[3];
    x[0].c = atoi(argv[1]);
    x[1].c = atoi(argv[2]);
    x[2].c = atoi(argv[3]);
    f(3, x[0], x[1], x[2], (long)atoi(argv[4]));
    exit(0);
}
