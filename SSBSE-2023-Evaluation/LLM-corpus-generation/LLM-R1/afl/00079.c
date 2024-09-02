// Modification timestamp: 2023-08-04 14:00:46
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00079.c

#include <stdio.h>
#include <stdlib.h>

#define x(y) ((y) + 1)

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = x(atoi(argv[1]));

    if (x != 1)
        return 1;

    return 0;
}
