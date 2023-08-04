// Modification timestamp: 2023-08-03 10:15:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00011.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x;
    int y;

    if (argc != 3) {
        printf("Usage: %s <x_value> <y_value>\n", argv[0]);
        return 1;
    }

    x = atoi(argv[1]);
    y = atoi(argv[2]);

    x = y = 0;

    return x;
}
