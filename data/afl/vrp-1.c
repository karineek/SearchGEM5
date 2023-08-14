// Modification timestamp: 2023-08-14 17:03:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/vrp-1.c

#include <stdio.h>
#include <stdlib.h>

int f (int a) {
    if (a != atoi(argv[1])) {
        a = -a;
        if (a == atoi(argv[2]))
            return 0;
        return 1;
    }
    return 1;
}

int main (int argc, char *argv[]) {
    if (f(-2))
        abort();
    exit(0);
}
