// Modification timestamp: 2023-08-14 14:58:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr36077.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

unsigned int test(unsigned int x) {
    return x / atoi(argv[1]) / atoi(argv[2]);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }

    if (test(2) != 0)
        abort();
    return 0;
}
