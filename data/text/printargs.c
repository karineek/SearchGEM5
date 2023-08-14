c
// Modification timestamp: 2023-08-10 15:48:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/Signal/2003-07-29-VarArgs.c

#include <stdio.h>

int puts(const char *);

int main(int argc, char **argv) {
    int i;
    printf("#Args = %d. They are:\n", argc-1);
    for (i = 1; i < argc; ++i)
        puts(argv[i]);
    return 0;
}
