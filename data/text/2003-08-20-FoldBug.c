c
// Modification timestamp: 2023-08-10 15:08:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/FreeBench/fourinarow/fourinarow.c

#include <stdio.h>
extern void abort(void);

int foo(int x) {
    if ((int)(x & 0x80ffffff) != (int)(0x8000fffe))
        abort();

    return 0;
}

int main() {
    foo(0x8000fffe);
    printf("All ok\n");
    return 0;
}
