
// Modification timestamp: 2023-08-04 14:13:07
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00116.c

#include <stdio.h>
#include <stdlib.h>

int f(int f) {
    return f;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int f = atoi(argv[1]);
    return f;
}
