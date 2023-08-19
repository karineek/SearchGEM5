// Modification timestamp: 2023-08-14 14:18:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/complex-5.c
float __complex__
p (float __complex__  a, float __complex__  b)
{
  return a + b;
}

float __complex__  x = 1.0 + 14.0 * (1.0fi);
float __complex__  y = 7.0 + 5.0 * (1.0fi);
float __complex__  w = 8.0 + 19.0 * (1.0fi);
float __complex__  z;

main ()
{

  z = p (x,y);
  y = p (x, 1.0f / z);
  if (z != w)
    abort ();
  exit (0);
}
