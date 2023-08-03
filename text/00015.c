// Modification timestamp: 2023-08-03 13:45:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00015.c

int main() {
    int arr[2];

    arr[0] = 1;
    arr[1] = 2;

    return arr[0] + arr[1] - 3;
}
