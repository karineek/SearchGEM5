// Modification timestamp: 2023-08-03 16:16:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00021.c

int foo(int a, int b) {
    return 2 + a - b;
}

int main() {
    return foo(1, 3);
}
