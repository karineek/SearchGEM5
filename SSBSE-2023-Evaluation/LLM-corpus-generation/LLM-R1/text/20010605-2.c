// Modification timestamp: 2023-08-14 11:59:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010605-2.c
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  __real__ x = 1.0;
  __imag__ x = 2.0;
  foo (x);
  __real__ y = 3.0f;
  __imag__ y = 4.0f;
  bar (y);
  __real__ z = 5.0L;
  __imag__ z = 6.0L;
  baz (z);
  exit (0);
}

void foo (__complex__ double x)
{
  if (__real__ x != 1.0 || __imag__ x != 2.0)
    abort ();
}

void bar (__complex__ float x)
{
  if (__real__ x != 3.0f || __imag__ x != 4.0f)
    abort ();
}

void baz (__complex__ long double x)
{
  if (__real__ x != 5.0L || __imag__ x != 6.0L)
    abort ();
}
