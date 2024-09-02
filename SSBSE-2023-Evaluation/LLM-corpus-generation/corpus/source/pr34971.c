// Modification timestamp: 2023-08-14 14:57:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34971.c

#include <stdio.h>
#include <stdlib.h>

struct foo {
    unsigned long long b:40;
} x;

extern void abort(void);

void test1(unsigned long long res, unsigned long long x_b) {
    /* Build a rotate expression on a 40 bit argument.  */
    if ((x_b << 8) + (x_b >> 32) != res)
        abort();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    unsigned long long res = strtoull(argv[1], NULL, 0);

    x.b = 0x0100000001;
    test1(0x0000000101, x.b);
    x.b = 0x0100000000;
    test1(0x0000000001, x.b);
    return 0;
}
