// Modification timestamp: 2023-08-14 15:26:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr56051.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void abort(void) {
  printf("Abort called\n");
  exit(1);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned char x1[1] = { 0 };
  unsigned int s1 = CHAR_BIT;
  int a1 = x1[0] < (unsigned char) (1 << s1);
  unsigned char y1 = (unsigned char) (1 << s1);
  int b1 = x1[0] < y1;
  if (a1 != b1)
    abort();

#if __SIZEOF_LONG_LONG__ > __SIZEOF_INT__
  unsigned long long x2[1] = { 2ULL << (sizeof(int) * CHAR_BIT) };
  unsigned int s2 = sizeof(int) * CHAR_BIT - 1;
  int a2 = x2[0] >= (unsigned long long) (1 << s2);
  unsigned long long y2 = 1 << s2;
  int b2 = x2[0] >= y2;
  if (a2 != b2)
    abort();

  unsigned long long x3[1] = { 2ULL << (sizeof(int) * CHAR_BIT) };
  unsigned int s3 = sizeof(int) * CHAR_BIT - 1;
  int a3 = x3[0] >= (unsigned long long) (1U << s3);
  unsigned long long y3 = 1U << s3;
  int b3 = x3[0] >= y3;
  if (a3 != b3)
    abort();
#endif

  return 0;
}
