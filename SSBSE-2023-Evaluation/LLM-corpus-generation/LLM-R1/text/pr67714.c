// Modification timestamp: 2023-08-14 15:45:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr67714.c
unsigned int b;
int c;

signed char
fn1 ()
{
  signed char d;
  for (int i = 0; i < 1; i++)
    d = -15;
  return d;
}

int
main (void)
{
  for (c = 0; c < 1; c++)
    b = 0;
  char e = fn1 ();
  signed char f = e ^ b;
  volatile int g = (int) f;

  if (g != -15)
    __builtin_abort ();

  return 0;
}
