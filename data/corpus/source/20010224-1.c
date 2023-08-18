// Modification timestamp: 2023-08-14 11:58:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010224-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

typedef signed short int16_t;
typedef unsigned short uint16_t;

int16_t logadd(int16_t *a, int16_t *b);
void ba_compute_psd(int16_t start);

int16_t masktab[6] = { 1, 2, 3, 4, 5 };
int16_t psd[6] = { 50, 40, 30, 20, 10 };
int16_t bndpsd[6] = { 1, 2, 3, 4, 5 };

void ba_compute_psd(int16_t start, int16_t *masktab, int16_t *psd, int16_t *bndpsd)
{
    int i, j, k;
    int16_t lastbin = 4;

    j = start;
    k = masktab[start];

    bndpsd[k] = psd[j];
    j++;

    for (i = j; i < lastbin; i++)
    {
        bndpsd[k] = logadd(&bndpsd[k], &psd[j]);
        j++;
    }
}

int16_t logadd(int16_t *a, int16_t *b)
{
    return *a + *b;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int16_t start = atoi(argv[1]);

    ba_compute_psd(start, masktab, psd, bndpsd);

    if (bndpsd[1] != 140)
        abort();
    return 0;
}
