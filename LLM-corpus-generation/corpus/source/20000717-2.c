
// Modification timestamp: 2023-08-10 16:39:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/Programs/SingleSource/UnitTests/20000717-2.c
#include <stdio.h>
#include <stdlib.h>

static void compare(long long foo) {
    if (foo < 4294967297LL) {
        abort();
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <foo>\n", argv[0]);
        return 1;
    }

    long long foo = atoll(argv[1]);
    compare(foo);
    exit(0);
}
