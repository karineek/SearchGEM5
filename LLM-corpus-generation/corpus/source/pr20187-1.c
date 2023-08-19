// Modification timestamp: 2023-08-14 14:44:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr20187-1.c

#include <stdio.h>

int a;
int b;

int test(void) {
    return (((unsigned char) (unsigned long long) ((a ? a : 1) & (a * b))) ? 0 : 1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    return 1 - test();
}
