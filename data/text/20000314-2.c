
// Modification timestamp: 2023-08-10 16:18:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/2000-03-14-2.c

typedef unsigned long long uint64;
const uint64 bigconst = 1ULL << 34;

int a = 1;

static uint64 getmask(void)
{
    if (a)
        return bigconst;
    else
        return 0;
}

int main()
{
    uint64 f = getmask();
    if (sizeof (long long) == 8 && f != bigconst)
        abort ();
    exit (0);
}
