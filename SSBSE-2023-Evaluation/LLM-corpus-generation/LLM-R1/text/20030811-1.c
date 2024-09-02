// Modification timestamp: 2023-08-14 12:47:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030811-1.c
/* Origin: PR target/11535 from H. J. Lu <hjl@lucon.org> */
/* { dg-require-effective-target return_address } */

void vararg (int i, ...)
{
  (void) i;
}

int i0[0], i1;

void test1 (void)
{
  int a = (int) (long long) __builtin_return_address (0);
  vararg (0, a);
}

void test2 (void)
{
  i0[0] = (int) (long long) __builtin_return_address (0);
}

void test3 (void)
{
  i1 = (int) (long long) __builtin_return_address (0);
}

void test4 (void)
{
  volatile long long a = (long long) __builtin_return_address (0);
  i0[0] = (int) a;
}

int main (void)
{
  return 0;
}
