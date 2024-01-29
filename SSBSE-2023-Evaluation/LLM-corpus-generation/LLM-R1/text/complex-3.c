// Modification timestamp: 2023-08-14 14:18:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/complex-3.c
struct complex
{
  float r;
  float i;
};

struct complex cmplx (float, float);

struct complex
f (float a, float b)
{
  struct complex c;
  c.r = a;
  c.i = b;
  return c;
}

main ()
{
  struct complex z = f (1.0, 0.0);

  if (z.r != 1.0 || z.i != 0.0)
    abort ();
  exit (0);
}
