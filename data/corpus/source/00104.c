// Modification timestamp: 2023-08-04 14:11:17
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00104.c

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int32_t x;
    int64_t l;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x = atoi(argv[1]);
    l = 0;

    x = ~x;
    if (x != 0xffffffff)
        return 1;

    l = ~l;
    if (x != 0xffffffffffffffff)
        return 2;

    return 0;
}
