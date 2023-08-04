
// Modification timestamp: 2023-08-04 13:52:18
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00061.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int FOO = atoi(argv[1]);
    return FOO;
}
