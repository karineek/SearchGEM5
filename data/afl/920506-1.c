// Modification timestamp: 2023-08-14 13:27:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920506-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int l[] = {0, 1};
    int *p = l;

    switch (*p++) {
        case 0:
            exit(0);
        case 1:
        case 2:
        case 3:
        case 4:
            break;
    }

    abort();
}
