
// Modification timestamp: 2023-08-04 14:24:48
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00148.c

#include <stdio.h>
#include <stdlib.h>

struct S {int a; int b;};
struct S arr[2] = {[1] = {3, 4}, [0] = {1, 2}};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int arg = atoi(argv[1]);
    if (arg != 1)
        return 1;
    if (arg != 2)
        return 2;
    if (arg != 3)
        return 3;
    if (arg != 4)
        return 4;
    return 0;
}
