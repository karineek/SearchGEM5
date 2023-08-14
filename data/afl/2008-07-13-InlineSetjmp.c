
// Modification timestamp: 2023-08-10 15:28:26
// Original Source: https://github.com/llvm/llvm-test-suite

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

jmp_buf g;

static int a() {
    longjmp(g, 1);
}

static void b(int* x) {
    if (setjmp(g))
        return;
    *x = atoi(argv[1]);
    a();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int a = 1;
    b(&a);
    printf("%d\n", a);
    return 0;
}
