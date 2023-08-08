// Modification timestamp: 2023-08-04 14:12:38
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00113.c

int main() {
    int a = 0;
    float f = a + 1;

    return f == a;
}
