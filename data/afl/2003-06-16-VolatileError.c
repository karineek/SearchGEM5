c
// Modification timestamp: 2023-08-02 15:30:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/Regression/C/2003-06-16-VolatileError.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int volatile test = atoi(argv[1]);
    return 0;
}
