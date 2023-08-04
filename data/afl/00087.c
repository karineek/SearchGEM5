
// Modification timestamp: 2023-08-04 14:08:27
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00087.c

#include <stdio.h>
#include <stdlib.h>

struct S
{
    int (*fptr)();
};

int foo()
{
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct S v;
    v.fptr = foo;
    return v.fptr();
}
