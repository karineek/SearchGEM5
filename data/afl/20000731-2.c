
// Modification timestamp: 2023-08-10 16:41:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/MultiSource/Applications/oggenc/20000731-2.c

#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i = 1;
    int j = 0;

    while (i != 1024 || j <= 0) {
        i *= 2;
        ++ j;
    }

    if (j != 10)
        abort();

    exit(0);
}
