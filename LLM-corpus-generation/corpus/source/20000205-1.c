
// Modification timestamp: 2023-08-10 16:15:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000205-1.c
#include <string.h>
#include <stdio.h>

#include <stdlib.h>

static int f(int a) {
    if (a == 0)
        return 0;
    do
        if (a & 128)
            return 1;
    while (f(0));
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int arg_value = atoi(argv[1]);
    if (f(~128))
        abort();
    exit(0);
}
