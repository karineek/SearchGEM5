//c
// Modification timestamp: 2023-08-10 16:41:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/817c1f7f9439fe4e2e238c3aeb1e2e8607a1819b/SingleSource/UnitTests/2001-07-31-ManyArgs.c

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
