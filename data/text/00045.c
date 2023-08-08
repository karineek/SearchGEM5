// Modification timestamp: 2023-08-04 13:45:27
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00045.c

int x = 5;
long y = 6;
int *p = &x;

int main() {
    if (x != 5)
        return 1;
    if (y != 6)
        return 2;
    if (*p != 5)
        return 3;
    return 0;
}
