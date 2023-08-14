// Modification timestamp: 2023-08-14 13:40:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941025-1.c

#include <stdio.h>
#include <stdlib.h>

long f(long x, long y) {
    return (x > 1) ? y : (y & 1);
}

int main(int argc, char *argv[]) {
    if (f(atol(argv[1]), atol(argv[2])) != atol(argv[3])) {
        abort();
    }
    exit(0);
}
