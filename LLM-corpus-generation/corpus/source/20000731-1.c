//c
// Modification timestamp: 2023-08-10 16:41:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000731-1.c

#include <stdlib.h>

double foo(void) {
    return 0.0;
}

void do_sibcall(void) {
    (void)foo();
}

int main(int argc, char *argv[]) {
    double x;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    x = atof(argv[1]);

    for (x = 0; x < 20; x++)
        do_sibcall();
    if (!(x >= 10))
        abort();
    exit(0);
}
