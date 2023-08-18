// Modification timestamp: 2023-08-14 14:59:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr36093.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

typedef struct Bar {
    char c[129];
} Bar __attribute__((__aligned__(128)));

typedef struct Foo {
    Bar bar[4];
} Foo;

Foo foo[4];

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int i, j;
    Foo *foop = &foo[0];

    for (i = 0; i < 4; i++) {
        Bar *bar = &foop->bar[i];
        for (j = 0; j < 129; j++) {
            bar->c[j] = 'a' + i;
        }
    }

    if (foo[0].bar[3].c[atoi(argv[1])] != 'd')
        abort();
    return 0;
}

