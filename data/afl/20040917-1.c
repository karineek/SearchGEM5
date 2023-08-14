// Modification timestamp: 2023-08-14 12:58:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040917-1.c

#include <stdio.h>
#include <stdlib.h>

static int test_var;

void not_inlinable() __attribute__((noinline));

static void inlinable() {
    test_var = -10;
}

void not_inlinable() {
    inlinable();
}

int main() {
    test_var = 10;
    not_inlinable();
    if (test_var == 10)
        abort ();
    return 0;
}

