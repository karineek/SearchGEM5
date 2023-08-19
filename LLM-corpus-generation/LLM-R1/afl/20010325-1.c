// Modification timestamp: 2023-08-14 11:58:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010325-1.c

#include <stdio.h>
#include <stdlib.h>

void exit(int);
void abort(void);

int main(int argc, char *argv[]) {
    if (L"a" "b"[1] != L'b')
        abort();
    exit(0);
}
