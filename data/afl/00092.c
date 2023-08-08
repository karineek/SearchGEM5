// Modification timestamp: 2023-08-04 14:09:31
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00092.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a[] = {atoi(argv[1]), [2] = atoi(argv[2]), atoi(argv[3])};

    if (sizeof(a) != 4 * sizeof(int))
        return 1;

    if (a[0] != 5)
        return 2;
    if (a[1] != 0)
        return 3;
    if (a[2] != 2)
        return 4;
    if (a[3] != 3)
        return 5;

    return 0;
}
