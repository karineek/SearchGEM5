// Modification timestamp: 2023-08-14 16:03:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr87290.c

#include <stdio.h>
#include <stdlib.h>

int c;

__attribute__((noipa)) void f0(void) {
    c++;
}

__attribute__((noipa)) int f1(int x) {
    return x % 16 == 13;
}

__attribute__((noipa)) int f2(int x) {
    return x % 16 == -13;
}

__attribute__((noipa)) void f3(int x) {
    if (x % 16 == 13)
        f0();
}

__attribute__((noipa)) void f4(int x) {
    if (x % 16 == -13)
        f0();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int i, j;
    int arg = atoi(argv[1]);

    for (i = -30; i < 30; i++) {
        if (f1(13 + i * 16 + arg) != (i >= arg) || f2(-13 + i * 16 + arg) != (i <= arg))
            __builtin_abort();
        f3(13 + i * 16 + arg);
        if (c != (i >= arg))
            __builtin_abort();
        f4(-13 + i * 16 + arg);
        if (c != 1 + (i == arg))
            __builtin_abort();
        for (j = 1; j < 16; j++) {
            if (f1(13 + i * 16 + j + arg) || f2(-13 + i * 16 + j + arg))
                __builtin_abort();
            f3(13 + i * 16 + j + arg);
            f4(-13 + i * 16 + j + arg);
        }
        if (c != 1 + (i == arg))
            __builtin_abort();
        c = 0;
    }

    return 0;
}
