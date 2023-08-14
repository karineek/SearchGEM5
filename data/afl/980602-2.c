// Modification timestamp: 2023-08-14 13:49:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980602-2.c

#include <stdio.h>
#include <stdlib.h>

#if __INT_MAX__ < 2147483647
int main(void) {
    exit(0);
}
#else
struct {
    unsigned bit : 30;
} t;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);

    if (!(t.bit++)) {
        exit(0);
    } else {
        abort();
    }
}
#endif
