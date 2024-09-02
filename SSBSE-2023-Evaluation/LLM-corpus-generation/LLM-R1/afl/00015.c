// Modification timestamp: 2023-08-03 13:45:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00015.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }

    int arr[2];

    arr[0] = atoi(argv[1]);
    arr[1] = atoi(argv[2]);

    return arr[0] + arr[1] - 3;
}
