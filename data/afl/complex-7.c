// Modification timestamp: 2023-08-14 14:19:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/complex-7.c

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

volatile float complex f1 = 1.1f + 2.2if;
volatile float complex f2 = 3.3f + 4.4if;
volatile float complex f3 = 5.5f + 6.6if;
volatile float complex f4 = 7.7f + 8.8if;
volatile float complex f5 = 9.9f + 10.1if;
volatile double complex d1 = 1.1 + 2.2i;
volatile double complex d2 = 3.3 + 4.4i;
volatile double complex d3 = 5.5 + 6.6i;
volatile double complex d4 = 7.7 + 8.8i;
volatile double complex d5 = 9.9 + 10.1i;
volatile long double complex ld1 = 1.1L + 2.2iL;
volatile long double complex ld2 = 3.3L + 4.4iL;
volatile long double complex ld3 = 5.5L + 6.6iL;
volatile long double complex ld4 = 7.7L + 8.8iL;
volatile long double complex ld5 = 9.9L + 10.1iL;

extern void abort(void);
extern void exit(int);

__attribute__((noinline)) void check_float(int a, float complex a1, float complex a2,
                                           float complex a3, float complex a4, float complex a5)
{
    if (a1 != f1 || a2 != f2 || a3 != f3 || a4 != f4 || a5 != f5)
        abort();
}

__attribute__((noinline)) void check_double(int a, double complex a1, double complex a2,
                                            double complex a3, double complex a4, double complex a5)
{
    if (a1 != d1 || a2 != d2 || a3 != d3 || a4 != d4 || a5 != d5)
        abort();
}

__attribute__((noinline)) void check_long_double(int a, long double complex a1, long double complex a2,
                                                 long double complex a3, long double complex a4,
                                                 long double complex a5)
{
    if (a1 != ld1 || a2 != ld2 || a3 != ld3 || a4 != ld4 || a5 != ld5)
        abort();
}

int main(void)
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    check_float(a, f1, f2, f3, f4, f5);
    check_double(a, d1, d2, d3, d4, d5);
    check_long_double(a, ld1, ld2, ld3, ld4, ld5);
    exit(0);
}

Note: In the modified code, I assumed that the command-line arguments are required and provided the necessary changes to include `argc` and `argv` in the `main` function.