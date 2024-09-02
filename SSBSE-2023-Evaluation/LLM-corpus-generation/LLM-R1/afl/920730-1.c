// Modification timestamp: 2023-08-14 13:29:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920730-1.c

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int f1(int b) {
    return b >= INT_MIN;
}

int f2(int b) {
    return b >= (unsigned)(INT_MAX + 2);
}

int f3(int b) {
    return b >= INT_MAX;
}

int f4(int b) {
    return b >= UINT_MAX;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <b1> <b2> <b3> <b4>\n", argv[0]);
        return 1;
    }

    int b1 = atoi(argv[1]);
    int b2 = atoi(argv[2]);
    int b3 = atoi(argv[3]);
    int b4 = atoi(argv[4]);

    if ((f1(b1) & f2(b2) & f3(b3) & f4(b4)) != 1) {
        abort();
    }

    exit(0);
}

Note: This assumes that the function calls `f1()`, `f2()`, `f3()`, and `f4()` in the original code were supposed to have arguments. If not, please let me know, and I can modify the code accordingly.