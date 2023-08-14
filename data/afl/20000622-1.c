
// Modification timestamp: 2023-08-10 16:35:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/1998-07-20-Identify/20000622-1.c

#include <stdlib.h>

long foo(long a, long b, long c)
{
  if (a != 12 || b != 1 || c != 11)
    abort();
  return 0;
}
long bar (long a, long b)
{
  return b;
}
void baz (long a, long b, void *c)
{
  long d;
  d = (long)c;
  foo(d, bar (a, 1), b);
}
int main(int argc, char *argv[])
{
  if (argc != 4) {
    printf("Usage: %s <arg1> <arg2> <arg3>\n", argv[0]);
    return 1;
  }

  long arg1 = atol(argv[1]);
  long arg2 = atol(argv[2]);
  long arg3 = atol(argv[3]);

  baz(arg1, arg2, (void *)arg3);
  exit(0);
}
