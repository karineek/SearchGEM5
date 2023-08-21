
// Modification timestamp: 2023-08-10 16:33:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000523-1.c
#include <string.h>
#include <stdio.h>

#include <stdlib.h>

int main(int argc, char *argv[]) {
    long long x;
    int n;

    if (sizeof(long long) < 8)
        exit(0);

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);
    x = (((long long)n) << 55) / 0xff;

    if (x == 0)
        abort();

    x = (((long long)9) << 55) / 0xff;

    if (x == 0)
        abort();

    exit(0);
}
