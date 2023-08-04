
// Modification timestamp: 2023-08-04 13:57:20
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00073.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int arr[2];
    int *p;

    p = &arr[1];
    p -= 1;
    *p = atoi(argv[1]);

    if (arr[0] != atoi(argv[1]))
        return 1;
    return 0;
}
