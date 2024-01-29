// Modification timestamp: 2023-08-14 17:30:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/printargs.c

#include <stdio.h>

int puts(const char *);

int main(int argc, char **argv) {
    printf("#Args = %d. They are:\n", argc - 1);
    for (int i = 1; i < argc; ++i)
        puts(argv[i]);
    return 0;
}
