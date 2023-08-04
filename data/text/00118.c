
// Modification timestamp: 2023-08-04 14:13:21
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00118.c

int main() {
    struct { int x; } s = { 0 };
    return s.x;
}
