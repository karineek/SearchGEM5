
// Modification timestamp: 2023-08-10 16:35:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/1998-07-20-Identify/20000622-1.c

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
int main()
{
  baz (10, 11, (void *)12);
  exit(0);
}
