// Modification timestamp: 2023-08-14 14:05:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bf-pack-1.c

#include <stdio.h>
#include <stdlib.h>

struct foo
{
    unsigned half:16;
    unsigned long whole:32 __attribute__ ((packed));
};

void f(struct foo *q)
{
    if (q->half != 0x1234)
        abort();
    if (q->whole != 0x56789abcL)
        abort();
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct foo bar;
    bar.half = atoi(argv[1]);
    bar.whole = atoi(argv[2]); // Use a suitable conversion for the value

    f(&bar);
    exit(0);
}
