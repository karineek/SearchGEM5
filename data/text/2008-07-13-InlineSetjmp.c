
// Modification timestamp: 2023-08-10 15:28:26
// Original Source: https://github.com/llvm/llvm-test-suite

#include <setjmp.h>
#include <stdio.h>

jmp_buf g;

static int a() {
    longjmp(g, 1);
}

static void b(int* x) {
    if (setjmp(g))
        return;
    *x = 10;
    a();
}

int main() {
    int a = 1;
    b(&a);
    printf("%d\n", a);
    return 0;
}
