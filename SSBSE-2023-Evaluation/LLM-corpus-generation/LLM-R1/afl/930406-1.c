// Modification timestamp: 2023-08-14 13:33:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930406-1.c

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 0x2000

void f(int argc, char *argv[]) {
    int x = 1;
    char big[STACK_SIZE/2];

    ({
        __label__ mylabel;
        mylabel:
            x++;
            if (x != 3)
                goto mylabel;
    });
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    f(argc, argv);
    return 0;
}
