// Modification timestamp: 2023-08-14 15:18:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr49279.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct S {
    int a;
    int *__restrict p;
};

__attribute__((noinline, noclone))
struct S *bar(struct S *p) {
    struct S *r;
    asm volatile("" : "=r" (r) : "0" (p) : "memory");
    return r;
}

__attribute__((noinline, noclone))
int foo(int *p, int *q) {
    struct S s, *t;
    s.a = atoi(argv[1]);
    s.p = p;
    t = bar(&s);
    t->p = q;
    s.p[0] = 0;
    t->p[0] = atoi(argv[2]);
    return s.p[0];
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    if (foo(&a, &b) != 1)
        abort();
    return 0;
}

