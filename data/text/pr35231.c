// Modification timestamp: 2023-08-14 14:57:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr35231.c
extern void abort(void);

int __attribute__((noinline))
foo(int bits_per_pixel, int depth)
{
  if ((bits_per_pixel | depth) == 1)
    abort ();
  return bits_per_pixel;
}

int main()
{
  if (foo(2, 0) != 2)
    abort ();
  return 0;
}
