// Modification timestamp: 2023-08-04 14:09:40
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00093.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a[] = {1, 2, 3, 4};

    if (sizeof(a) != 4 * sizeof(int))
        return 1;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    return 0;
}
