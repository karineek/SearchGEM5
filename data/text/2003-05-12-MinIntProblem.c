
// Modification timestamp: 2023-08-10 14:46:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Benchmarks/Misc/2003-05-12-MinIntProblem.c

#include <stdio.h>

void foo(int X) {
    if (X + 1 < 0)
        printf("success\n");
}

int main() {
    foo(-2147483648);
    return 0;
}
