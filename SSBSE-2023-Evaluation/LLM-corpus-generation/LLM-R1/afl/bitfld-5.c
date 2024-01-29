// Modification timestamp: 2023-08-14 14:06:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bitfld-5.c

#include <stdio.h>
#include <stdlib.h>

void abort(void) {
    printf("Abort called\n");
    exit(1);
}

struct s {
    unsigned long long a:2;
    unsigned long long b:40;
    unsigned long long c:22;
};

void g(unsigned long long a, unsigned long long b) {
    asm ("");
    if (a != b)
        abort();
}

void f(struct s s, unsigned long long b) {
    asm ("");
    g(((unsigned long long)(s.b - 8)) + 8, b);
}

int main(int argc, char *argv[]) {
    struct s s = {1, 10, 3};
    struct s t = {1, 2, 3};
    f(s, 10);
    f(t, 0x10000000002);
    return 0;
}
