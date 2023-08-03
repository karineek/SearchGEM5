// Modification timestamp: 2023-08-03 17:17:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00030.c

int f() {
    return 100;
}

int main() {
    if (f() > 1000)
        return 1;
    if (f() >= 1000)
        return 1;
    if (1000 < f())
        return 1;
    if (1000 <= f())
        return 1;
    if (1000 == f())
        return 1;
    if (100 != f())
        return 1;
    return 0;
}
