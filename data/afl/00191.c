
// Modification timestamp: 2023-08-04 14:38:22
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00191.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a;

    for (a = 0; a < 2; a++) {
        int b = a;
    }

    printf("it's all good\n");

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    return 0;
}
