// Modification timestamp: 2023-08-14 17:33:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//PR491.c

#include <stdio.h>
#include <stdlib.h>

static int assert_fail(const char* s, unsigned l)
{
    fprintf(stderr, "assertion failed in line %u: '%s'\n", l, s);
    return 0;
}
#define ASSERT(expr)    ((expr) ? 1 : assert_fail(#expr,__LINE__))

int test(int r, int argc, char* argv[]) {
#if !defined(__i386__) && !defined(__x86_64__)
  #if !defined(BYTE_ORDER) || !defined(LITTLE_ENDIAN)
     return r;
  #else
     if (BYTE_ORDER != LITTLE_ENDIAN) return r;
  #endif
#endif

    /* little endian */
    union { long l; unsigned char c[sizeof(long)]; } u;
    u.l = 0; u.c[0] = 0x80;
    r &= ASSERT(u.l == 128);
    u.l = 0; u.c[sizeof(long)-1] = 0x80;
    r &= ASSERT(u.l < 0);
    return r;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  return test(1, atoi(argv[1]), argv);
}

