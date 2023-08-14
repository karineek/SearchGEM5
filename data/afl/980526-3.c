// Modification timestamp: 2023-08-14 13:49:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980526-3.c

#include <stdio.h>
#include <stdlib.h>

int compare(unsigned int x, unsigned int y) {
    if (x == y)
        return 0;
    else
        return 1;
}

int main(int argc, char *argv[]) {
    unsigned int i, j, k, l;
    if (argc != 5) {
        printf("Usage: %s <i> <j> <k> <l>\n", argv[0]);
        return 1;
    }
    i = atoi(argv[1]);
    j = atoi(argv[2]);
    k = atoi(argv[3]);
    l = atoi(argv[4]);

    if (compare(5 % (~(unsigned)2), i % ~j) || compare(0, k % ~l))
        abort();
    else
        exit(0);
}
