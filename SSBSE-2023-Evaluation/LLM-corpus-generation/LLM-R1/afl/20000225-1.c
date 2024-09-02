c
// Modification timestamp: 2023-08-10 16:16:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/Programs/SingleSource/Regression/C/20000225-1.c

#include <stdlib.h>

int main(int argc, char *argv[]) {
    int nResult;
    int b = 0;
    int i = -1;

    do {
        if (b != 0) {
            abort ();
            nResult = 1;
        } else {
            nResult = 0;
        }
        i++;
        b = (i + 2) * 4;
    } while (i < 0);

    exit(0);
}
