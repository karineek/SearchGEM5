
// Modification timestamp: 2023-08-10 16:35:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000605-3.c
#include <string.h>
#include <stdio.h>

#include <stdlib.h>

struct F { int x; int y; };

int main(int argc, char *argv[]) {
    int timeout = 0;
    int x = 0;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    while (1) {
        const struct F i = { x++, };
        if (i.x > 0)
            break;
        if (++timeout > 5)
            goto die;
    }
    return 0;

die:
    abort();
}
