// Modification timestamp: 2023-08-04 14:12:04
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00109.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <x> <y>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    if(x ? 1 : 0)
        return 1;
    if(y ? 0 : 1)
        return 2;
    return 0;
}
