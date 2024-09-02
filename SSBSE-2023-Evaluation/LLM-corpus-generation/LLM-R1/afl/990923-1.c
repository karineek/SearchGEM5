// Modification timestamp: 2023-08-14 13:56:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990923-1.c

#include <stdio.h>
#include <stdlib.h>

#define mask 0xffff0000L
#define value 0xabcd0000L

long foo(long x) {
    if ((x & mask) == value)
        return x & 0xffffL;
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    long x = atol(argv[1]);
    if (foo(x) != 0 || foo(0) != 1)
        abort();

    exit(0);
}
