// Modification timestamp: 2023-08-14 15:42:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr65170.c
/* PR tree-optimization/65170 */

#ifdef __SIZEOF_INT128__
typedef unsigned __int128 V;
typedef unsigned long long int H;
#else
typedef unsigned long long int V;
typedef unsigned int H;
#endif

__attribute__((noinline, noclone)) void
foo (V b, V c)
{
  V a;
  b &= (H) -1;
  c &= (H) -1;
  a = b * c;
  if (a != 1)
    __builtin_abort ();
}

int
main ()
{
  foo (1, 1);
  return 0;
}
