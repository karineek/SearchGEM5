// Modification timestamp: 2023-08-14 13:32:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921215-1.c

#include <stdio.h>
#include <stdlib.h>

void p(void ((*f) (void ())))
{
    void r()
    {
        foo ();
    }

    f(r);
}

void q(void ((*f)()))
{
    f();
}

void foo() {}

int main(int argc, char *argv[]) {
    p(q);

    exit(0);
}
