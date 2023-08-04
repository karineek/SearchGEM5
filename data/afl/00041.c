
// Modification timestamp: 2023-08-04 13:41:35
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00041.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n;
    int t;
    int c;
    int p;

    c = 0;
    n = atoi(argv[1]);
    while (n < 5000) {
        t = 2;
        p = 1;
        while (t*t <= n) {
            if (n % t == 0)
                p = 0;
            t++;
        }
        n++;
        if (p)
            c++;
    }
    if (c != 669)
        return 1;
    return 0;
}
