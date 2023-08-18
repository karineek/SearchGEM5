
// Modification timestamp: 2023-08-10 16:31:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Applications/oggenc/20000419-1.c

#include <stdlib.h>

struct foo { int a, b, c; };

void brother(int a, int b, int c) {
    if (a)
        abort();
}

void sister(struct foo f, int b, int c) {
    brother((f.b == b), b, c);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
        return 1;
    }

    struct foo f = { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]) };
    sister(f, atoi(argv[1]), atoi(argv[2]));
    exit(0);
}
