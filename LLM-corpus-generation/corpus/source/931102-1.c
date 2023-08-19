// Modification timestamp: 2023-08-14 13:39:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931102-1.c

#include <stdio.h>
#include <stdlib.h>

typedef union {
    struct {
        char h, l;
    } b;
} T;

int f(int x) {
    int num = 0;
    T reg;

    reg.b.l = x;
    while ((reg.b.l & 1) == 0) {
        num++;
        reg.b.l >>= 1;
    }
    return num;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    if (f(x) != 1) {
        abort();
    }
    exit(0);
}
