// Modification timestamp: 2023-08-14 14:09:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/builtin-bitops-1.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

int my_ffs(unsigned x) {
    int i;
    if (x == 0)
        return 0;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned); i++)
        if (x & ((unsigned)1 << i))
            break;
    return i + 1;
}

int my_ctz(unsigned x) {
    int i;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned); i++)
        if (x & ((unsigned)1 << i))
            break;
    return i;
}

int my_clz(unsigned x) {
    int i;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned); i++)
        if (x & ((unsigned)1 << ((CHAR_BIT * sizeof(unsigned)) - i - 1)))
            break;
    return i;
}

int my_clrsb(unsigned x) {
    int i;
    int leading = (x >> CHAR_BIT * sizeof(unsigned) - 1) & 1;
    for (i = 1; i < CHAR_BIT * sizeof(unsigned); i++)
        if (((x >> ((CHAR_BIT * sizeof(unsigned)) - i - 1)) & 1)
            != leading)
            break;
    return i - 1;
}

int my_popcount(unsigned x) {
    int i;
    int count = 0;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned); i++)
        if (x & ((unsigned)1 << i))
            count++;
    return count;
}

int my_parity(unsigned x) {
    int i;
    int count = 0;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned); i++)
        if (x & ((unsigned)1 << i))
            count++;
    return count & 1;
}

int my_ffsl(unsigned long x) {
    int i;
    if (x == 0)
        return 0;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned long); i++)
        if (x & ((unsigned long)1 << i))
            break;
    return i + 1;
}

int my_clzl(unsigned long x) {
    int i;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned long); i++)
        if (x & ((unsigned long)1 << i))
            break;
    return i;
}

int my_ctzl(unsigned long x) {
    int i;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned long); i++)
        if (x & ((unsigned long)1 << i))
            break;
    return i;
}

int my_clrsbl(unsigned long x) {
    int i;
    int leading = (x >> CHAR_BIT * sizeof(unsigned long) - 1) & 1;
    for (i = 1; i < CHAR_BIT * sizeof(unsigned long); i++)
        if (((x >> ((CHAR_BIT * sizeof(unsigned long)) - i - 1)) & 1)
            != leading)
            break;
    return i - 1;
}

int my_popcountl(unsigned long x) {
    int i;
    int count = 0;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned long); i++)
        if (x & ((unsigned long)1 << i))
            count++;
    return count;
}

int my_parityl(unsigned long x) {
    int i;
    int count = 0;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned long); i++)
        if (x & ((unsigned long)1 << i))
            count++;
    return count & 1;
}

int my_ffsll(unsigned long long x) {
    int i;
    if (x == 0)
        return 0;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned long long); i++)
        if (x & ((unsigned long long)1 << i))
            break;
    return i + 1;
}

int my_clzll(unsigned long long x) {
    int i;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned long long); i++)
        if (x & ((unsigned long long)1 << i))
            break;
    return i;
}

int my_ctzll(unsigned long long x) {
    int i;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned long long); i++)
        if (x & ((unsigned long long)1 << i))
            break;
    return i;
}

int my_clrsbll(unsigned long long x) {
    int i;
    int leading = (x >> CHAR_BIT * sizeof(unsigned long long) - 1) & 1;
    for (i = 1; i < CHAR_BIT * sizeof(unsigned long long); i++)
        if (((x >> ((CHAR_BIT * sizeof(unsigned long long)) - i - 1)) & 1)
            != leading)
            break;
    return i - 1;
}

int my_popcountll(unsigned long long x) {
    int i;
    int count = 0;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned long long); i++)
        if (x & ((unsigned long long)1 << i))
            count++;
    return count;
}

int my_parityll(unsigned long long x) {
    int i;
    int count = 0;
    for (i = 0; i < CHAR_BIT * sizeof(unsigned long long); i++)
        if (x & ((unsigned long long)1 << i))
            count++;
    return count & 1;
}

extern void abort(void);
extern void exit(int);

#define NUMS16                 \
  {                      \
    0x0000U,                 \
    0x0001U,                 \
    0x8000U,                 \
    0x0002U,                 \
    0x4000U,                 \
    0x0100U,                 \
    0x0080U,                 \
    0xa5a5U,                 \
    0x5a5aU,                 \
    0xcafeU,                 \
    0xffffU                 \
  }

#define NUMS32                 \
  {                      \
    0x00000000UL,                \
    0x00000001UL,                \
    0x80000000UL,                \
    0x00000002UL,                \
    0x40000000UL,                \
    0x00010000UL,                \
    0x00008000UL,                \
    0xa5a5a5a5UL,                \
    0x5a5a5a5aUL,                \
    0xcafe0000UL,                \
    0x00cafe00UL,                \
    0x0000cafeUL,                \
    0xffffffffUL                \
  }

#define NUMS64                 \
  {                      \
    0x0000000000000000ULL,          \
    0x0000000000000001ULL,          \
    0x8000000000000000ULL,          \
    0x0000000000000002ULL,          \
    0x4000000000000000ULL,          \
    0x0000000100000000ULL,          \
    0x0000000080000000ULL,          \
    0xa5a5a5a5a5a5a5a5ULL,          \
    0x5a5a5a5a5a5a5a5aULL,          \
    0xcafecafe00000000ULL,          \
    0x0000cafecafe0000ULL,          \
    0x00000000cafecafeULL,          \
    0xffffffffffffffffULL          \
  }

unsigned int ints[] =
#if BITSIZEOF_INT == 64
NUMS64;
#elif BITSIZEOF_INT == 32
NUMS32;
#else
NUMS16;
#endif

unsigned long longs[] =
#if BITSIZEOF_LONG == 64
NUMS64;
#else
NUMS32;
#endif

unsigned long long longlongs[] =
#if BITSIZEOF_LONG_LONG == 64
NUMS64;
#else
NUMS32;
#endif

#define N(table) (sizeof (table) / sizeof (table[0]))

int main(void)
{
    int i;

    for (i = 0; i < N(ints); i++)
    {
        if (__builtin_ffs(ints[i]) != my_ffs(ints[i]))
            abort();
        if (ints[i] != 0
            && __builtin_clz(ints[i]) != my_clz(ints[i]))
            abort();
        if (ints[i] != 0
            && __builtin_ctz(ints[i]) != my_ctz(ints[i]))
            abort();
        if (__builtin_clrsb(ints[i]) != my_clrsb(ints[i]))
            abort();
        if (__builtin_popcount(ints[i]) != my_popcount(ints[i]))
            abort();
        if (__builtin_parity(ints[i]) != my_parity(ints[i]))
            abort();
    }

    for (i = 0; i < N(longs); i++)
    {
        if (__builtin_ffsl(longs[i]) != my_ffsl(longs[i]))
            abort();
        if (longs[i] != 0
            && __builtin_clzl(longs[i]) != my_clzl(longs[i]))
            abort();
        if (longs[i] != 0
            && __builtin_ctzl(longs[i]) != my_ctzl(longs[i]))
            abort();
        if (__builtin_clrsbl(longs[i]) != my_clrsbl(longs[i]))
            abort();
        if (__builtin_popcountl(longs[i]) != my_popcountl(longs[i]))
            abort();
        if (__builtin_parityl(longs[i]) != my_parityl(longs[i]))
            abort();
    }

    for (i = 0; i < N(longlongs); i++)
    {
        if (__builtin_ffsll(longlongs[i]) != my_ffsll(longlongs[i]))
            abort();
        if (longlongs[i] != 0
            && __builtin_clzll(longlongs[i]) != my_clzll(longlongs[i]))
            abort();
        if (longlongs[i] != 0
            && __builtin_ctzll(longlongs[i]) != my_ctzll(longlongs[i]))
            abort();
        if (__builtin_clrsbll(longlongs[i]) != my_clrsbll(longlongs[i]))
            abort();
        if (__builtin_popcountll(longlongs[i]) != my_popcountll(longlongs[i]))
            abort();
        if (__builtin_parityll(longlongs[i]) != my_parityll(longlongs[i]))
            abort();
    }

    /* Test constant folding.  */
    TEST(0x00000000UL,);
    TEST(0x00000001UL,);
    TEST(0x80000000UL,);
    TEST(0x40000000UL,);
    TEST(0x00010000UL,);
    TEST(0x00008000UL,);
    TEST(0xa5a5a5a5UL,);
    TEST(0x5a5a5a5aUL,);
    TEST(0xcafe0000UL,);
    TEST(0x00cafe00UL,);
    TEST(0x0000cafeUL,);
    TEST(0xffffffffUL,);

    TEST(0x0000000000000000ULL, ll);
    TEST(0x0000000000000001ULL, ll);
    TEST(0x8000000000000000ULL, ll);
    TEST(0x0000000000000002ULL, ll);
    TEST(0x4000000000000000ULL, ll);
    TEST(0x0000000100000000ULL, ll);
    TEST(0x0000000080000000ULL, ll);
    TEST(0xa5a5a5a5a5a5a5a5ULL, ll);
    TEST(0x5a5a5a5a5a5a5a5aULL, ll);
    TEST(0xcafecafe00000000ULL, ll);
    TEST(0x0000cafecafe0000ULL, ll);
    TEST(0x00000000cafecafeULL, ll);
    TEST(0xffffffffffffffffULL, ll);

    exit(0);
}
