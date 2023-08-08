// Modification timestamp: 2023-08-04 14:11:43
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00107.c

#include <stdio.h>
#include <stdlib.h>

typedef int myint;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    myint x = (myint)atoi(argv[1]);
    return x - 1;
}
