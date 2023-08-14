// Modification timestamp: 2023-08-14 14:29:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-10.c

#include <stdio.h>
#include <stdlib.h>

static int count = 0;

static void inc(void) {
    count++;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int iNbr = atoi(argv[1]);
    int test = 0;
    while (test == 0) {
        inc();
        if (iNbr == 0)
            break;
        else {
            inc();
            iNbr--;
        }
        test = 1;
    }
    if (count != 2)
        abort();
    return 0;
}
