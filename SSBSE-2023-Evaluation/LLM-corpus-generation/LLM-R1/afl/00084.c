// Modification timestamp: 2023-08-04 14:02:50
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00084.c

#include <stdio.h>
#include <stdlib.h>

#define ARGS(...) __VA_ARGS__

int none()
{
    return 0;
}

int one(int a)
{
    if (a != 1)
        return 1;

    return 0;
}

int two(int a, int b)
{
    if (a != 1)
        return 1;
    if (b != 2)
        return 1;

    return 0;
}

int three(int a, int b, int c)
{
    if (a != 1)
        return 1;
    if (b != 2)
        return 1;
    if (c != 3)
        return 1;

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 5) {
        printf("Usage: %s <none> <one> <two> <three>\n", argv[0]);
        return 1;
    }
    int arg_none = atoi(argv[1]);
    int arg_one = atoi(argv[2]);
    int arg_two = atoi(argv[3]);
    int arg_three = atoi(argv[4]);

    if (none())
        return arg_none;
    if (one(arg_one))
        return arg_one;
    if (two(arg_one, arg_two))
        return arg_two;
    if (three(arg_one, arg_two, arg_three))
        return arg_three;
    return 0;
}
