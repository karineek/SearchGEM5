// Modification timestamp: 2023-08-04 14:02:13
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00083.c

#include <stdio.h>
#include <stdlib.h>

#define CALL(FUN, ...) FUN(__VA_ARGS__)

int
one(int a)
{
    if (a != 1)
        return 1;

    return 0;
}

int
two(int a, int b)
{
    if (a != 1)
        return 1;
    if (b != 2)
        return 1;

    return 0;
}

int
three(int a, int b, int c)
{
    if (a != 1)
        return 1;
    if (b != 2)
        return 1;
    if (c != 3)
        return 1;

    return 0;
}

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    if (CALL(one, atoi(argv[1])))
        return 2;
    if (CALL(two, atoi(argv[1]), 2))
        return 3;
    if (CALL(three, atoi(argv[1]), 2, 3))
        return 4;

    return 0;
}
