
// Modification timestamp: 2023-08-10 16:39:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/Programs/SingleSource/UnitTests/20000717-2.c
#include <stdlib.h>

static void compare(long long foo) {
    if (foo < 4294967297LL) {
        abort();
    }
}

int main(void) {
    compare(8589934591LL);
    exit(0);
}
