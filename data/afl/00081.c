
// Modification timestamp: 2023-08-04 14:01:23
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00081.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    long long x = atoi(argv[1]);
    x = x + 1;
    if (x != 1)
        return 1;
    return 0;
}
