// Modification timestamp: 2023-08-14 14:56:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34130.c


#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int foo(int i) {
    return -2 * abs(i - 2);
}

int main(int argc, char *argv[]) {
    if (foo(atoi(argv[1])) != -2 || foo(atoi(argv[2])) != -2)
        abort();

    return 0;
}
