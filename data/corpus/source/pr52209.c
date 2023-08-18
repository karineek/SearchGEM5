// Modification timestamp: 2023-08-14 15:22:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr52209.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct S0 {
    int f2 : 1;
} c;

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int b = atoi(argv[1]) ^ c.f2;

    if (b != -1)
        abort();

    return 0;
}
