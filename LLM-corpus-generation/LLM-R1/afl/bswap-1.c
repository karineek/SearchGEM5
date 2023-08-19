// Modification timestamp: 2023-08-14 14:07:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bswap-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned long long g(unsigned long long a) __attribute__((noinline));
unsigned long long g(unsigned long long a)
{
  return __builtin_bswap64(a);
}

unsigned long long f(unsigned long long c)
{
  union {
    unsigned long long a;
    unsigned char b[8];
  } a, b;
  a.a = c;
  b.b[0] = a.b[7];
  b.b[1] = a.b[6];
  b.b[2] = a.b[5];
  b.b[3] = a.b[4];
  b.b[4] = a.b[3];
  b.b[5] = a.b[2];
  b.b[6] = a.b[1];
  b.b[7] = a.b[0];
  return b.a;
}

int main(int argc, char *argv[]) {
  unsigned long long i;
  /* The rest of the testcase assumes 8 byte long long. */
  if (sizeof(i) != sizeof(char)*8)
    return 0;
  if (f(atoi(argv[1])) != g(atoi(argv[1])))
    __builtin_abort();
  if (f(atoi(argv[2])) != g(atoi(argv[2])))
    __builtin_abort();
  if (f(atoi(argv[3])) != g(atoi(argv[3])))
    __builtin_abort();
  if (f(atoi(argv[4])) != g(atoi(argv[4])))
    __builtin_abort();
  if (f(atoi(argv[5])) != g(atoi(argv[5])))
    __builtin_abort();
  if (f(atoi(argv[6])) != g(atoi(argv[6])))
    __builtin_abort();
  if (f(atoi(argv[7])) != g(atoi(argv[7])))
    __builtin_abort();
  if (f(atoi(argv[8])) != g(atoi(argv[8])))
    __builtin_abort();
  return 0;
}
