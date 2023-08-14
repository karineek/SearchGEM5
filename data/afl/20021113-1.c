// Modification timestamp: 2023-08-14 12:37:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021113-1.c

#include <stdio.h>
#include <stdlib.h>

void foo(int *p) {
    *p = 10;
}

int main(int argc, char *argv[]) {
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 5;
    foo(ptr);
    if (*ptr == 5)
        abort();
    free(ptr);
    exit(0);
}
