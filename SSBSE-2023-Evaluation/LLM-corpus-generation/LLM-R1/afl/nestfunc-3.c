// Modification timestamp: 2023-08-14 14:41:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/nestfunc-3.c

#include <stdio.h>
#include <stdlib.h>

extern long foo(long, long, long (*)(long, long));
extern long use(long (*)(long, long), long, long);

long nested_0(long a, long b) {
  if (a > 2 * b)
    return a - b;
  else
    return b - a;
}

long nested_1(long a, long b, long sum) {
  return use(nested_0, b, a) + sum;
}

long nested_2(long a, long b, long sum) {
  return nested_1(b, a, sum);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long sum = 0;
  long i;

  for (i = 0; i < atoi(argv[1]); ++i) {
    long j;

    for (j = 0; j < atoi(argv[1]); ++j) {
      long k;

      for (k = 0; k < atoi(argv[1]); ++k)
        sum += foo(i, j > k ? j - k : k - j, nested_2);
    }
  }

  if ((sum & 0xffffffff) != 0xbecfcbf5)
    abort();

  return 0;
}

long use(long (*func)(long, long), long a, long b) {
  return func(b, a);
}

long foo(long a, long b, long (*func)(long, long)) {
  return func(a, b);
}
