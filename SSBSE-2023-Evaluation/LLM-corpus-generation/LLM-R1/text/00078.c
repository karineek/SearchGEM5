// Modification timestamp: 2023-08-04 14:00:33
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00078.c

int f1(char *p) {
    return *p+1;
}

int main() {
    char s = 1;
    int v[1000];
    int f1(char *);

    if (f1(&s) != 2)
        return 1;
    return 0;
}
