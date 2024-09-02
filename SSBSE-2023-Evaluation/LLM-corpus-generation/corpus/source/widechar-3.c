// Modification timestamp: 2023-08-14 17:04:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/widechar-3.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void abort(void);
extern void exit(int);

static int f(char *x) {
    return strlen(x);
}

int foo() {
    return f((char*)&L"abcdef"[0]);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    if (foo() != 0)
        abort();
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    if (foo() != 1)
        abort();
#endif
    exit(0);
}
