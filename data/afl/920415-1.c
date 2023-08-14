// Modification timestamp: 2023-08-14 13:25:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920415-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    __label__ l;
    void *x() { return &&l; }
    goto *x();
    abort();
    return;
l:
    exit(0);
}

Note that the code snippet you provided is non-standard C syntax and may not be compatible with all compilers.