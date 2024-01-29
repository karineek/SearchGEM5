// Modification timestamp: 2023-08-14 14:40:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/memset-4.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 15

void f(char *a) __attribute__((noinline));
void f(char *a)
{
    memset(a, 0, SIZE);
}

int main(int argc, char *argv[]) {
    char b[SIZE];
    for(int i = 0; i < sizeof(b); i++) {
        b[i] = i;
    }
    f(b);

    for(int i = 0; i < sizeof(b); i++) {
        if (0 != b[i])
            abort();
    }

    return 0;
}

