
// Modification timestamp: 2023-08-10 16:19:08
// Original Source: https://github.com/llvm/llvm-test-suite

#if ULLONG_MAX != 18446744073709551615ull && ULONG_MAX != 18446744073709551615ull
int main(void) { exit (0); }
#else
#if ULONG_MAX != 18446744073709551615ull
typedef unsigned long long ull;
#else
typedef unsigned long ull;
#endif

#include <stdio.h>
#include <stdlib.h>

void checkit(int);

main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    const ull a = 0x1400000000ULL;
    const ull b = 0x80000000ULL;
    const ull c = a/b;
    const ull d = 0x1400000000ULL / 0x80000000ULL;

    checkit ((int) c);
    checkit ((int) d);

    exit(0);
}

void checkit (int a)
{
  if (a != 40)
    abort();
}
#endif
