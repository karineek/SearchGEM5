// Modification timestamp: 2023-08-14 15:35:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58640.c

#include <stdio.h>
#include <stdlib.h>

int a, b, c, d = 1, e;

static signed char foo() {
    int f, g = a;

    for (f = 1; f < 3; f++)
        for (; b < 1; b++) {
            if (d)
                for (c = 0; c < 4; c++)
                    for (f = 0; f < 3; f++) {
                        for (e = 0; e < 1; e++)
                            a = g;
                        if (f)
                            break;
                    }
            else if (f)
                continue;
            return 0;
        }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    int y = 0;
    int z = 0;
    a = x;
    b = y;
    c = z;

    foo();
    exit(0);
}
