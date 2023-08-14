
// Modification timestamp: 2023-08-10 16:13:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/Benchmarks/BenchmarksC/uint64_to_float.c

#include <stdio.h>
#include <stdint.h>
#include <fenv.h>
#include <float.h>

typedef union
{
    uint32_t u;
    float f;
} float_bits;


float floatundisf(uint64_t a)
{
    if (a == 0)
        return 0.0F;
    const unsigned N = sizeof(uint64_t) * 8;
    int sd = N - __builtin_clzll(a);  /* number of significant digits */
    int e = sd - 1;             /* 8 exponent */
    if (sd > FLT_MANT_DIG)
    {
        switch (sd)
        {
        case FLT_MANT_DIG + 1:
            a <<= 1;
            break;
        case FLT_MANT_DIG + 2:
            break;
        default:
            a = (a >> (sd - (FLT_MANT_DIG+2))) |
                ((a & ((uint64_t)(-1) >> ((N + FLT_MANT_DIG+2) - sd))) != 0);
        };
        a |= (a & 4) != 0;
        ++a;
        a >>= 2;
        if (a & ((uint64_t)1 << FLT_MANT_DIG))
        {
            a >>= 1;
            ++e;
        }
    }
    else
    {
        a <<= (FLT_MANT_DIG - sd);
    }
    float_bits fb;
    fb.u = ((e + 127) << 23)       |
           ((int32_t)a & 0x007FFFFF);
    return fb.f;
}

void test(uint64_t x) {
    const float_bits expected = { .f = floatundisf(x) };
    const float_bits observed = { .f = x };

    if (expected.u != observed.u) {
        printf("Error detected @ 0x%016llx\n", x);
        printf("\tExpected result: %a (0x%08x)\n", expected.f, expected.u);
        printf("\tObserved result: %a (0x%08x)\n", observed.f, observed.u);
    }
}

int main(int argc, char *argv[]) {
    int i, j, k, l, m;
    const uint64_t one = 1;
    const uint64_t mone = -1;
    const int roundingModes[4] = { FE_TONEAREST };
    const char *modeNames[4] = {"to nearest", "down", "up", "towards zero"};

    for ( m=0; m<4; ++m) {
        fesetround(roundingModes[0]);
        printf("Testing uint64_t --> float conversions in round %s...\n",
               modeNames[m]);

        test(0);
        for ( i=0; i<64; ++i) {
            test( one << i);
            test(mone << i);
            for ( j=0; j<i; ++j) {
                test(( one << i) + ( one << j));
                test(( one << i) + (mone << j));
                test((mone << i) + ( one << j));
                test((mone << i) + (mone << j));
                for ( k=0; k<j; ++k) {
                    test(( one << i) + ( one << j) + ( one << k));
                    test(( one << i) + ( one << j) + (mone << k));
                    test(( one << i) + (mone << j) + ( one << k));
                    test(( one << i) + (mone << j) + (mone << k));
                    test((mone << i) + ( one << j) + ( one << k));
                    test((mone << i) + ( one << j) + (mone << k));
                    test((mone << i) + (mone << j) + ( one << k));
                    test((mone << i) + (mone << j) + (mone << k));
                    for ( l=0; l<k; ++l) {
                        test(( one << i) + ( one << j) + ( one << k) + ( one << l));
                        test(( one << i) + ( one << j) + ( one << k) + (mone << l));
                        test(( one << i) + ( one << j) + (mone << k) + ( one << l));
                        test(( one << i) + ( one << j) + (mone << k) + (mone << l));
                        test(( one << i) + (mone << j) + ( one << k) + ( one << l));
                        test(( one << i) + (mone << j) + ( one << k) + (mone << l));
                        test(( one << i) + (mone << j) + (mone << k) + ( one << l));
                        test(( one << i) + (mone << j) + (mone << k) + (mone << l));
                        test((mone << i) + ( one << j) + ( one << k) + ( one << l));
                        test((mone << i) + ( one << j) + ( one << k) + (mone << l));
                        test((mone << i) + ( one << j) + (mone << k) + ( one << l));
                        test((mone << i) + ( one << j) + (mone << k) + (mone << l));
                        test((mone << i) + (mone << j) + ( one << k) + ( one << l));
                        test((mone << i) + (mone << j) + ( one << k) + (mone << l));
                        test((mone << i) + (mone << j) + (mone << k) + ( one << l));
                        test((mone << i) + (mone << j) + (mone << k) + (mone << l));
                    }
                }
            }
        }
    }
    printf("Finished Testing.\n");
    return 0;
}
