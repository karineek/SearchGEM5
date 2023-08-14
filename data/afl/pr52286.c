// Modification timestamp: 2023-08-14 15:22:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr52286.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    #if __SIZEOF_INT__ > 2
        int a, b;
        asm("" : "=r"(a) : "0"(0));
        b = (~a | 1) & atoi(argv[1]);
    #else
        long a, b;
        asm("" : "=r"(a) : "0"(0));
        b = (~a | 1) & atol(argv[1]);
    #endif

    if (b >= 0)
        abort();
    return 0;
}

Note: The original code uses `__SIZEOF_INT__` to determine the size of the integer type. In the converted code, the value is replaced with `atoi(argv[1])` or `atol(argv[1])` depending on the size.