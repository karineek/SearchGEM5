
// Modification timestamp: 2023-08-04 14:12:21
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00111.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <short_value> <long_value>\n", argv[0]);
        return 1;
    }

    short s = atoi(argv[1]);
    long l = atoi(argv[2]);

    s -= l;
    return s;
}
