// Modification timestamp: 2023-08-14 16:00:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr84748.c

#include <stdio.h>
#include <stdlib.h>

typedef unsigned __int128 u128;

int a, c, d;
u128 b;

unsigned long long g0, g1;

void store(unsigned long long a0, unsigned long long a1) {
    g0 = a0;
    g1 = a1;
}

void foo(void) {
    if (argc != 5) {
        printf("Usage: %s <value1> <value2> <value3> <value4>\n", argv[0]);
        return 1;
    }

    a = atoi(argv[1]);
    c = atoi(argv[2]);
    d = atoi(argv[3]);

    b += a;
    c = d != 84347;
    b /= c;
    u128 x = b;
    store(x >> 0, x >> 64);
}

int main(int argc, char *argv[]) {
    foo();
    if (g0 != 0 || g1 != 0)
        __builtin_abort();
    return 0;
}
