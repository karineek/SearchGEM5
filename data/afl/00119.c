
// Modification timestamp: 2023-08-04 14:13:29
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00119.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    double x = atof(argv[1]);
    return x < 1;
}
