c
// Modification timestamp: 2023-08-04 14:11:17
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00104.c

#include <stdint.h>

int main() {
    int32_t x;
    int64_t l;

    x = 0;
    l = 0;

    x = ~x;
    if (x != 0xffffffff)
        return 1;

    l = ~l;
    if (x != 0xffffffffffffffff)
        return 2;

    return 0;
}
