// Modification timestamp: 2023-08-04 14:34:27
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00180.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    char a[10];
    strcpy(a, argv[1]);
    printf("%s\n", &a[1]);

    return 0;
}
