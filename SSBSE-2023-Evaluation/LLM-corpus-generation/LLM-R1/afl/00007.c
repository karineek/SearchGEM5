// Modification timestamp: 2023-08-03 10:15:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00007.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x;

    x = 1;
    for (x = 10; x; x = x - 1)
        ;
    if (x)
        return 1;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x = atoi(argv[1]);
    for (; x;)
        x = x - 1;

    return x;
}
