// Modification timestamp: 2023-08-14 14:44:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr19606.c

#include <stdio.h>
#include <stdlib.h>

signed char a = -4;

int foo(int a) {
    return ((unsigned int) (signed int) a) / 2LL;
}

int bar(int a) {
    return ((unsigned int) (signed int) a) % 5LL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    signed char a = atoi(argv[1]);

    int r;

    r = foo(a);
    if (r != ((unsigned int) (signed int) (signed char) a) / 2LL)
        abort();

    r = bar(a);
    if (r != ((unsigned int) (signed int) (signed char) a) % 5LL)
        abort();

    exit(0);
}
