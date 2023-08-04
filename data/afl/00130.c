
// Modification timestamp: 2023-08-04 14:20:34
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00130.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char arr[2][4], (*p)[4], *q;
    int v[4];

    p = arr;
    q = &arr[1][3];
    arr[1][3] = atoi(argv[1]);
    v[0] = atoi(argv[1]);

    if (arr[1][3] != atoi(argv[1]))
        return 1;
    if (p[1][3] != atoi(argv[1]))
        return 1;
    if (*q != atoi(argv[1]))
        return 1;
    if (*v != atoi(argv[1]))
        return 1;

    return 0;
}
