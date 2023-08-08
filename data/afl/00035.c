// Modification timestamp: 2023-08-04 13:37:46
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00035.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    if (!x != 0)
        return 1;
    if (!!x != 1)
        return 1;
    if (-x != 0 - 4)
        return 1;
    return 0;
}
