
// Modification timestamp: 2023-08-04 13:56:52
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00072.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int arr[2];
    int *p;

    p = &arr[0];
    p += 1;
    *p = atoi(argv[1]);

    if (arr[1] != atoi(argv[1]))
        return 1;
    return 0;
}
