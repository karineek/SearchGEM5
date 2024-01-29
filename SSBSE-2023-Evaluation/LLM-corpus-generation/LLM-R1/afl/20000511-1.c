
// Modification timestamp: 2023-08-10 16:32:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/test/SingleSource/UnitTests/2000-05-11-1.c

#include <stdlib.h>

void f(int value, int expect) {
    if (value != expect)
        abort();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);
    int e = atoi(argv[5]);

    f(a || b % c, 1);
    f(a ? b % c : 0, 2);
    f(a = b % c, 2);
    f(a *= b % c, 4);
    f(a /= b % c, 2);
    f(a %= b % c, 0);
    f(a += b % c, 2);
    f(d || c && e, 1);
    f(d ? c && e : 0, 1);
    f(d = c && e, 1);
    f(d *= c && e, 1);
    f(d %= c && e, 0);
    f(d += c && e, 1);
    f(d -= c && e, 0);
    f(d || c || e, 1);
    f(d ? c || e : 0, 0);
    f(d = c || e, 1);
    f(d *= c || e, 1);
    f(d %= c || e, 0);
    f(d += c || e, 1);
    f(d -= c || e, 0);
    exit(0);
}
