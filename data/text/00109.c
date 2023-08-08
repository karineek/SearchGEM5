// Modification timestamp: 2023-08-04 14:12:04
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00109.c

int main() {
    int x = 0;
    int y = 1;
    if(x ? 1 : 0)
        return 1;
    if(y ? 0 : 1)
        return 2;
    return 0;
}
