// Modification timestamp: 2023-08-14 12:50:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031211-1.c

#include <stdio.h>
#include <stdlib.h>

struct a {
    unsigned int bitfield : 1;
};

unsigned int x;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct a a = {0};
    x = atoi(argv[1]);
    a.bitfield |= x;
    if (a.bitfield != 1)
        abort ();
    exit (0);
}
