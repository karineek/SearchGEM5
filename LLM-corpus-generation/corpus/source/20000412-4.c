
// Modification timestamp: 2023-08-10 16:30:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000412-4.c

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void f(int i, int j, int radius, int width, int N)
{
    const int diff = i - radius;
    const int lowk = (diff > 0 ? diff : 0);
    int k;

    for (k = lowk; k <= 2; k++) {
        int idx = ((k - i + radius) * width - j + radius);
        if (idx < 0)
            abort();
    }

    for (k = lowk; k <= 2; k++);
}


int main(int argc, char **argv)
{
    int exc_rad;
    int N;
    int i;

    if (argc != 3) {
        printf("Usage: %s <exc_rad> <N>\n", argv[0]);
        return 1;
    }

    exc_rad = atoi(argv[1]);
    N = atoi(argv[2]);

    for (i = 1; i < 4; i++)
        f(i, 1, exc_rad, 2 * exc_rad + 1, N);
    exit(0);
}
