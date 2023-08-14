// Modification timestamp: 2023-08-14 13:30:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921017-1.c

#include <stdio.h>
#include <stdlib.h>

int g(int i, int *a) {
    return a[i];
}

int f(int n, int *a) {
    a[1] = 4711;
    return g(1, a);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int *a = malloc(sizeof(int) * n);

    if (n < 2) {
        printf("Usage: %s <n> (n must be greater than or equal to 2)\n", argv[0]);
        return 1;
    }

    int result = f(n, a);
    
    if (result != 4711)
        abort();

    free(a);
    return 0;
}
