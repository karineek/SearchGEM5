// Modification timestamp: 2023-08-14 16:52:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/struct-cpy-1.c

#include <stdio.h>
#include <stdlib.h>

struct termios
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned char pad[28];
};

struct tty_driver
{
    unsigned char pad1[38];
    struct termios t __attribute__ ((aligned (8)));
};

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct termios zero_t;
    struct tty_driver pty;

    pty.t = zero_t;
    pty.t.a = atoi(argv[1]);
    pty.t.b = atoi(argv[2]);
    pty.t.c = atoi(argv[3]);
    pty.t.d = atoi(argv[4]);

    if (pty.t.a != atoi(argv[1])
        || pty.t.b != atoi(argv[2])
        || pty.t.c != atoi(argv[3])
        || pty.t.d != atoi(argv[4])) {
        abort();
    }

    return 0;
}
