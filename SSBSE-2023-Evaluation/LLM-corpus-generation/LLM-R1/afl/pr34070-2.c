// Modification timestamp: 2023-08-14 14:55:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34070-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int f(unsigned int x, int n) {
    return ((int)x) / (1 << n);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    unsigned int x = atoi(argv[1]);
    int n = atoi(argv[2]);
  
    if (f(x, n) != 0)
        abort();

    return 0;
}
