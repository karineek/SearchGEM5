
// Modification timestamp: 2023-08-04 14:20:34
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00130.c

int main() {
    char arr[2][4], (*p)[4], *q;
    int v[4];

    p = arr;
    q = &arr[1][3];
    arr[1][3] = 2;
    v[0] = 2;

    if (arr[1][3] != 2)
        return 1;
    if (p[1][3] != 2)
        return 1;
    if (*q != 2)
        return 1;
    if (*v != 2)
        return 1;

    return 0;
}
