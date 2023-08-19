// Modification timestamp: 2023-08-04 14:26:28
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00155.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    sizeof((int) atoi(argv[1]));
    return 0;
}
