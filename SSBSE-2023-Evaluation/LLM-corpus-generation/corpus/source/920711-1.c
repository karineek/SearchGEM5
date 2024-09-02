// Modification timestamp: 2023-08-14 13:28:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920711-1.c
#include <stdio.h>

/* { dg-options "-fwrapv" } */

#include <stdlib.h>

extern void abort(void);
extern void exit(int);

int f(long a) {
    return (--a > 0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    long arg = atol(argv[1]);
    if (f(arg) == 0)
        abort();

    exit(0);
}
