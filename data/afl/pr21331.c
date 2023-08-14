// Modification timestamp: 2023-08-14 14:45:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr21331.c

#include <stdio.h>
#include <stdlib.h>

void abort(void);

int bar(void) {
    return -1;
}

unsigned long foo() {
    unsigned long retval;
    retval = bar();
    if (retval == -1)
        return 0;
    return 3;
}

int main(int argc, char *argv[]) {
    if (foo() != 0)
        abort();
    return 0;
}
