// Modification timestamp: 2023-08-14 14:26:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/ffs-1.c

#include <stdio.h>
#include <stdlib.h>

__volatile int a = 0;

extern void abort(void);
extern void exit(int);

int main(int argc, char *argv[]) {
    if (__builtin_ffs(atoi(argv[1])) != 0)
        abort();
    exit(0);
}

Note: I assume that the value of `a` is passed as a command-line argument.