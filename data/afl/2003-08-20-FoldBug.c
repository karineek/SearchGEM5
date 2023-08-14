c
// Modification timestamp: 2023-08-10 15:08:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/FreeBench/fourinarow/fourinarow.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int foo(int x) {
    if ((int)(x & 0x80ffffff) != (int)(0x8000fffe))
        abort();

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    foo(x);
    printf("All ok\n");
    return 0;
}
