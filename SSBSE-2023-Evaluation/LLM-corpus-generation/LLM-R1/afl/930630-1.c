// Modification timestamp: 2023-08-14 13:35:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930630-1.c

#include <stdio.h>
#include <stdlib.h>

#if __INT_MAX__ < 2147483647
int main(void) {
    exit(0);
}
#else
void f(int x) {
    if (x != 7)
        abort();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct {
        signed int bf0:17;
        signed int bf1:7;
    } bf;

    bf.bf1 = atoi(argv[1]);
    f(bf.bf1);
    exit(0);
}
#endif
