// Modification timestamp: 2023-08-14 16:02:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr87053.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const union {
    struct {
        char x[4];
        char y[4];
    };
    struct {
        char z[8];
    };
} u;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    strcpy(u.x, argv[1]);
    strcpy(u.y, argv[2]);

    if (strlen(u.z) != 7) {
        abort();
    }

    return 0;
}
