// Modification timestamp: 2023-08-14 12:36:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020911-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int main(int argc, char *argv[]) {
    unsigned short c = atoi(argv[1]);

    if ((c - 0x8000) < 0 || (c - 0x8000) > 0x7fff)
        abort();

    return 0;
}
