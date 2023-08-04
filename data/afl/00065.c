
// Modification timestamp: 2023-08-04 13:54:40
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00065.c

#include <stdio.h>
#include <stdlib.h>

#define ADD(X, Y) (X + Y)

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <arg1> <arg2> <arg3>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int z = atoi(argv[3]);

    return ADD(x, y) - z;
}
