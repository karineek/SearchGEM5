
// Modification timestamp: 2023-08-04 14:14:02
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00123.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double x;
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
    x = atof(argv[1]);
    return x < 1;
}
