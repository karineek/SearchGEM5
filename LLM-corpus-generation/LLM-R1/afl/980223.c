// Modification timestamp: 2023-08-14 13:48:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980223.c

#include <stdio.h>
#include <stdlib.h>

typedef struct { char *addr; long type; } object;

object bar(object blah) {
    abort();
}

object foo(object x, object y) {
    object z = *(object*)(x.addr);
    if (z.type & 64) {
        y = *(object*)(z.addr + sizeof(object));
        z = *(object*)(z.addr);
        if (z.type & 64)
            y = bar(y);
    }
    return y;
}

int main(int argc, char *argv[]) {
    object x = {argv[1], 64};
    object y = {NULL, 0};
    object three = foo(x, y);
    return 0;
}
