// Modification timestamp: 2023-08-02 15:30:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00036.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x = atoi(argv[1]);
    x += 2;
    x += 2;
    if (x != 4)
        return 1;
    x -= 1;
    if (x != 3)
        return 2;
    x *= 2;
    if (x != 6)
        return 3;

    return 0;
}
