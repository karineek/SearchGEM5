c
// Modification timestamp: 2023-08-10 16:32:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/Benchmarks/BitBench/pstack.c

unsigned long sub (int a)
{
  return ((0 > a - 2) ? 0 : a - 2) * sizeof (long);
}

int main ()
{
  if (sub (0) != 0)
    abort ();

  exit (0);
}
