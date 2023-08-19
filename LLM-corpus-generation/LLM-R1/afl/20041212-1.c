// Modification timestamp: 2023-08-14 13:00:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041212-1.c

#include <stdio.h>
#include <stdlib.h>

void *f(void) __attribute__((__noinline__));
void *f(void) {
    return f;
}

int main(void) {
    if (f() != f) {
        abort();
    }
    exit(0);
}
