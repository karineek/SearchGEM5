// Modification timestamp: 2023-08-04 14:12:12
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00110.c

#include <stdlib.h>
#include <stdio.h>

extern int x;
int x;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x = atoi(argv[1]);
    return x;
}
