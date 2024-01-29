// Modification timestamp: 2023-08-14 11:52:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001013-1.c

#include <stdio.h>
#include <stdlib.h>

struct x {
    int a, b;
};

int foo(struct x *p, int y) {
    if ((y & 0xff) != y || -p->b >= p->a)
        return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    struct x z;
    z.a = atoi(argv[1]);
    z.b = atoi(argv[2]);

    if (foo(&z, atoi(argv[3])))
        abort();
    exit(0);
}
