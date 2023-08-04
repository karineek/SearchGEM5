
// Modification timestamp: 2023-08-04 14:14:33
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00126.c

int main() {
    int x;

    x = 3;
    x = !x;
    x = !x;
    x = ~x;
    x = -x;
    if(x != 2)
        return 1;
    return 0;
}
