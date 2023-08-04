
// Modification timestamp: 2023-08-04 13:57:20
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00073.c

#include <stdio.h>

int main() {
    int arr[2];
    int *p;

    p = &arr[1];
    p -= 1;
    *p = 123;

    if (arr[0] != 123)
        return 1;
    return 0;
}

