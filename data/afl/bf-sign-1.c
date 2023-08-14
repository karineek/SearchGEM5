// Modification timestamp: 2023-08-14 14:05:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bf-sign-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct {
        signed int s:3;
        unsigned int u:3;
        int i:3;
    } x = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3])};

    if (x.u != 7)
        abort();
    if (x.s != -1)
        abort();

    if (x.i != -1 && x.i != 7)
        abort();

    exit(0);
}

Note: You need to provide command-line arguments for `argv[1]`, `argv[2]`, and `argv[3]` when running the program.