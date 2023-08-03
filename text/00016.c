// Modification timestamp: 2023-08-03 15:00:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00016.c

int main() {
    int arr[2];
    int *p;

    p = &arr[1];
    *p = 0;
    return arr[1];
}
