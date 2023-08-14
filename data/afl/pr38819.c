// Modification timestamp: 2023-08-14 15:03:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr38819.c

#include <stdio.h>
#include <stdlib.h>

extern void exit(int);
extern void abort(void);

volatile int a = 1;
volatile int b = 0;
volatile int x = 2;
volatile signed int r = 8;

void __attribute__((noinline))
foo(void)
{
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int si1 = atoi(argv[1]);
    int si2 = atoi(argv[2]);
    int i;

    for (i = 0; i < 100; ++i) {
        foo();
        if (x == 8)
            i++;
        r += i + si1 % si2;
    }
    abort();
}
