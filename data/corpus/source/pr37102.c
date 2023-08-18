// Modification timestamp: 2023-08-14 14:59:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr37102.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

unsigned int a, b = 1, c;

void __attribute__ ((noinline)) foo (int x) {
    if (x != 5)
        abort ();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    unsigned int d, e;
    for (d = atoi(argv[1]); d < 5; d++) {
        if (c) {
            a = b;
        }
    }
    a = b;
    e = a << 1;
    if (e) {
        e = (e << 1) ^ 1;
    }
    foo(e);
    return 0;
}

//In this code, I have replaced the constant `5` with `atoi(argv[1])` to assign the command-line argument to `d`.