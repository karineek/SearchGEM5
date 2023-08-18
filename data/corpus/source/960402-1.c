// Modification timestamp: 2023-08-14 13:45:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960402-1.c

#include <stdio.h>
#include <stdlib.h>

int f(signed long long int x) {
    return x > 0xFFFFFFFFLL || x < -0x80000000LL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    signed long long int x = atoll(argv[1]);
    int result = f(x);

    if (result != 0)
        abort();

    exit(0);
}
