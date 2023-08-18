// Modification timestamp: 2023-08-14 12:35:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020720-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);
extern double fabs (double);
extern void link_error (void);

void foo(double x) {
    double p, q;
    
    p = fabs(x);
    q = atof(argv[1]);
    if (p < q)
        link_error();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
    
    foo(atof(argv[1]));
    return 0;
}

#ifndef __OPTIMIZE__
void link_error() {
    abort();
}
#endif
