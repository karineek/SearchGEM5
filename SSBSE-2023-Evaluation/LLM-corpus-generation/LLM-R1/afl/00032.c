// Modification timestamp: 2023-08-03 18:00:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00032.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <val1> <val2> <val3> <val4>\n", argv[0]);
        return 1;
    }

    int arr[2];
    int *p;

    arr[0] = atoi(argv[1]);
    arr[1] = atoi(argv[2]);
    p = &arr[0];
    if (*(p++) != atoi(argv[3]))
        return 1;
    if (*(p++) != atoi(argv[4]))
        return 2;

    p = &arr[1];
    if (*(p--) != atoi(argv[3]))
        return 1;
    if (*(p--) != atoi(argv[2]))
        return 2;

    p = &arr[0];
    if (*(++p) != atoi(argv[4]))
        return 1;

    p = &arr[1];
    if (*(--p) != atoi(argv[2]))
        return 1;

    return 0;
}
