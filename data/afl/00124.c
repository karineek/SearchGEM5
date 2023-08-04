
// Modification timestamp: 2023-08-04 14:14:18
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00124.c

#include <stdio.h>
#include <stdlib.h>

int
f2(int c, int b)
{
    return c - b;
}

int (*
f1(int a, int b))(int c, int b)
{
    if (a != b)
        return f2;
    return 0;
}

int
main(int argc, char *argv[])
{
    int (* (*p)(int a, int b))(int c, int d) = f1;

    if (argc != 3) {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }

    int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);

    return (*(*p)(arg1, arg2))(arg2, arg2);
}
