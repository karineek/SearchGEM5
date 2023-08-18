// Modification timestamp: 2023-08-04 13:51:12
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00057.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char a[16], b[16];

    if (argc != 3) {
        printf("Usage: %s <size1> <size2>\n", argv[0]);
        return 1;
    }

    int size1 = atoi(argv[1]);
    int size2 = atoi(argv[2]);

    if (size1 != size2)
        return 1;
    
    return 0;
}
