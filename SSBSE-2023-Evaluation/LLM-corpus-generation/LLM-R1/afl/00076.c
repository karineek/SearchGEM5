// Modification timestamp: 2023-08-04 13:59:38
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00076.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    if (atoi(argv[1]) ? 1 : 0)
        return 1;
    if (atoi(argv[1]) ? 0 : 1)
        return 2;
    return 0;
}
