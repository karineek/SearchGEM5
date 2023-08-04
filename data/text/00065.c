
// Modification timestamp: 2023-08-04 13:54:40
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00065.c

#define ADD(X, Y) (X + Y)

int main() {
    return ADD(1, 2) - 3;
}
