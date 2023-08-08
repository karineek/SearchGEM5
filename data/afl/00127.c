// Modification timestamp: 2023-08-04 14:19:23
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00127.c

#include <stdio.h>
#include <stdlib.h>

int c;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    c = atoi(argv[1]);

    if (0) {
        return 1;
    } else if (0) {
    } else {
        if (1) {
            if (c)
                return 1;
            else
                return 0;
        } else {
            return 1;
        }
    }
    return 1;
}
