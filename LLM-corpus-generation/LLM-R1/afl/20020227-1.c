// Modification timestamp: 2023-08-14 12:11:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020227-1.c

#include <stdio.h>
#include <stdlib.h>

typedef __complex__ float cf;
struct x { char c; cf f; } __attribute__ ((__packed__));
extern void f2 (struct x*);
extern void f1 (void);
int main(int argc, char *argv[]) {
    f1();
    exit(0);
}

void f1 (void) {
    struct x s;
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        exit(1);
    }

    s.f = atof(argv[1]);
    s.c = atoi(argv[2]);
    f2(&s);
}

void f2 (struct x *y) {
    if (y->f != atof(argv[1]) || y->c != atoi(argv[2]))
        abort();
}
