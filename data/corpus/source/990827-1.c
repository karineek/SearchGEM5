// Modification timestamp: 2023-08-14 13:56:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990827-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned test(unsigned one, unsigned bit) {
    unsigned val = bit & 1;
    unsigned zero = one >> 1;

    val++;
    return zero + (val >> 1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <one> <bit>\n", argv[0]);
        return 1;
    }

    unsigned one = atoi(argv[1]);
    unsigned bit = atoi(argv[2]);

    if (test(one, bit) != 0) {
        abort();
    }
    if (test(one, bit) != 1) {
        abort();
    }
    if (test(one, bit) != 1) {
        abort();
    }

    exit(0);
}
