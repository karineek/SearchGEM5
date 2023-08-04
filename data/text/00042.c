c
// Modification timestamp: 2023-08-04 13:41:48
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00042.c

int main() {
    union { int a; int b; } u;
    u.a = 1;
    u.b = 3;

    if (u.a != 3 || u.b != 3)
        return 1;
    return 0;
}
