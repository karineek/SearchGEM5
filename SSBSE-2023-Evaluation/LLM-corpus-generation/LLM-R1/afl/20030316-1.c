// Modification timestamp: 2023-08-14 12:43:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030316-1.c

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    long j = atol(argv[1]);
    if ((unsigned int)(0x40000000 + j) < 0L)
        abort();

    return 0;
}
