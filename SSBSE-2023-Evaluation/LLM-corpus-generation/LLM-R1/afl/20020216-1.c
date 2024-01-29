// Modification timestamp: 2023-08-14 12:10:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020216-1.c

#include <stdio.h>
#include <stdlib.h>

void abort() {
    printf("Aborted\n");
    exit(1);
}

void exit(int value) {
    printf("Exit with value: %d\n", value);
    exit(value);
}

int foo(signed char c) {
    return (unsigned short) c ^ (signed char) 0x99999999;
}

int main(int argc, char *argv[]) {
    if ((unsigned char) -1 != 0xff || sizeof (short) != 2 || sizeof (int) != 4) {
        exit(0);
    }

    signed char c = (signed char) 0xffffffff;
    int result = foo(c);

    if (result != (int) 0xffff0066) {
        abort();
    }

    exit(0);
}
