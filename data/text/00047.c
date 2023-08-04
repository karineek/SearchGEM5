
// Modification timestamp: 2023-08-04 13:46:20
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00047.c

struct { int a; int b; int c; } s = {1, 2, 3};

int main() {
    if (s.a != 1)
        return 1;
    if (s.b != 2)
        return 2;
    if (s.c != 3)
        return 3;

    return 0;
}
