c
// Modification timestamp: 2023-08-10 15:48:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/Signal/2003-07-29-VarArgs.c

#include <stdio.h>
#include <stdlib.h>

int puts(const char *);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int i = atoi(argv[1]);
    printf("#Args = %d. They are:\n", i);
    for (i = 1; i < argc; ++i)
        puts(argv[i]);
    return 0;
}
