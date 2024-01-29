// Modification timestamp: 2023-08-03 15:00:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00016.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }

    int arr[2];
    int *p;

    arr[0] = atoi(argv[1]);
    arr[1] = atoi(argv[2]);
    p = &arr[1];
    *p = 0;
    return arr[1];
}
