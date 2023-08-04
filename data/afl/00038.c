
// Modification timestamp: 2023-08-04 13:39:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00038.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    int *p;

    if (sizeof(0) < 2)
        return x;
    if (sizeof 0 < 2)
        return x;
    if (sizeof(char) < 1)
        return x;
    if (sizeof(int) - 2 < 0)
        return x;
    if (sizeof(&x) != sizeof p)
        return x;
    return 0;
}
