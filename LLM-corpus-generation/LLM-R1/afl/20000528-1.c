
// Modification timestamp: 2023-08-10 16:33:58
// Original Source: https://github.com/llvm/llvm-test-suite

#include <stdlib.h>

unsigned long l = (unsigned long)-2;
unsigned short s;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    long t = atoi(argv[1]);
    s = t;
    if (s != (unsigned short)-2)
        abort();
    exit(0);
}
