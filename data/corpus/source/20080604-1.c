// Modification timestamp: 2023-08-14 13:14:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20080604-1.c

#include <stdio.h>
#include <stdlib.h>

struct barstruct { char const* some_string; } x;

void abort(void) {
    printf("Aborted\n");
    exit(1);
}

void __attribute__((noinline)) foo(void) {
    if (!x.some_string)
        abort();
}

void baz(int b) {
    struct barstruct bar;
    struct barstruct* barptr;

    if (b)
        barptr = &bar;
    else {
        barptr = &x + 1;
        barptr = barptr - 1;
    }

    barptr->some_string = argv[1];
    foo();
    barptr->some_string = argv[2];
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    x.some_string = NULL;
    baz(0);

    if (!x.some_string)
        abort();

    return 0;
}

//Note: This code assumes that the command line arguments `argv[1]` and `argv[2]` are to be used as the values for `barptr->some_string` in the `baz` function.