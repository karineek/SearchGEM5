
// Modification timestamp: 2023-08-04 14:25:48
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00152.c

#include <stdio.h>
#include <stdlib.h>

#undef  line
#define line 1000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int line = atoi(argv[1]);

    #line line
    if (1000 != __LINE__) {
        printf("  # line line not work as expected\n");
        return 2;
    }

    return 0;
}
