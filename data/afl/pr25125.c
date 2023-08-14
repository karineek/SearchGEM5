// Modification timestamp: 2023-08-14 14:49:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr25125.c

#include <stdio.h>
#include <stdlib.h>

extern void exit(int);
extern void abort(void);
unsigned short f(short a) __attribute__((__noinline__));

unsigned short f(short a) {
    short b;

    if (a > 0)
        return 0;
    b = ((int)a) + - (int)32768;
    return b;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    if (sizeof(short) < 2 || sizeof(short) >= sizeof(int))
        exit(0);

    short arg = atoi(argv[1]);

    if (f(arg) != 1)
        abort();

    exit(0);
}
