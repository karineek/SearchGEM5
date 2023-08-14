// Modification timestamp: 2023-08-14 15:36:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr59229.c

#include <stdio.h>
#include <string.h>

int i;

__attribute__((noinline, noclone)) void bar(char *p) {
    if (i < 1 || i > 6)
        abort();
    if (memcmp(p, "abcdefg", i + 1) != 0)
        abort();
    memset(p, ' ', 7);
}

__attribute__((noinline, noclone)) void foo(char *p, unsigned long l) {
    if (l < 1 || l > 6)
        return;
    char buf[7];
    memcpy(buf, p, l + 1);
    bar(buf);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    for (i = 0; i < 16; i++)
        foo(argv[1], i);
    return 0;
}
