// Modification timestamp: 2023-08-14 13:17:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20090711-1.c

#include <stdio.h>
#include <stdlib.h>

long long div (long long val)
{
  return val / 32768;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  long long d1 = atoll(argv[1]);
  long long d2 = div(d1);
  long long expected = atoll(argv[2]);
  if (d2 != expected)
    abort ();

  return 0;
}
