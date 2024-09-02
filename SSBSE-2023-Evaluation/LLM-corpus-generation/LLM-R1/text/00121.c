// Modification timestamp: 2023-08-04 14:13:47
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00121.c

int f(int a), g(int a), a;

int main() {
    return f(1) - g(1);
}

int f(int a) {
    return a;
}

int g(int a) {
    return a;
}
