// Modification timestamp: 2023-08-14 12:38:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021127-1.c
/* { dg-options "-std=c99" } */

long long a = -1;
long long llabs (long long);
void abort (void);
int
main()
{
  if (llabs (a) != 1)
    abort ();
  return 0;
}
long long llabs (long long b)
{
	abort ();
}
