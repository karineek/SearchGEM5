// Modification timestamp: 2023-08-03 16:15:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00020.c

int main() {
    int x, *p, **pp;

    x = 0;
    p = &x;
    pp = &p;
    return **pp;
}
